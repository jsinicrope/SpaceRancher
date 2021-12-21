// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Harvester.h"

#include "Characters/Main Character/CppPlayerController.h"
#include "Characters/Main Character/MyCharacter.h"
#include "Particles/ParticleSystemComponent.h"

AHarvester::AHarvester()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	AddOwnedComponent(StaticMesh);

	LaserHolder = CreateDefaultSubobject<USceneComponent>(TEXT("LaserHolder"));
	LaserHolder->SetupAttachment(StaticMesh);
	
	LaserBeam = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Laser Beam"));
	LaserBeam->SetupAttachment(LaserHolder);
}

void AHarvester::BeginPlay()
{
	Super::BeginPlay();
	LaserBeam->Activate();
	SetActorTickEnabled(false);
}

void AHarvester::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateAimDirection();
}

void AHarvester::Selected_Implementation()
{
	
}

void AHarvester::Activated_Implementation()
{
	ToggleLaser();
}

void AHarvester::Deactivated_Implementation()
{
	DeactivateLaser();
}

bool AHarvester::ToggleLaser()
{
	if (bLaserActive)
	{
		return DeactivateLaser();
	}
	return ActivateLaser();
}

bool AHarvester::ActivateLaser()
{
	bLaserActive = true;
	LaserBeam->Activate();
	LaserBeam->SetVariableVec3(FName("BeamEnd"), BeamTarget);
	SetActorTickEnabled(true);
	return false;
}

bool AHarvester::DeactivateLaser()
{
	if (bLaserActive)
	{
		LaserBeam->Deactivate();
		bLaserActive = false;
		SetActorTickEnabled(false);
		return true;
	}
	return false;
}

void AHarvester::UpdateAimDirection()
{
	const FVector Start = LaserHolder->GetComponentLocation();
	
	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = false;
	ECollisionChannel Channel = ECC_Visibility;
	FHitResult OutHit(ForceInit);

	FVector TargetViewPoint = PC->GetPlayerCharacter()->GetViewPoint();

	if (FVector::Distance(Start, TargetViewPoint) > LaserRange)
	{
		TargetViewPoint = PC->GetPlayerCharacter()->GetViewForwardVector() * LaserRange + Start;
	}

	GetWorld()->LineTraceSingleByChannel(OutHit, Start, TargetViewPoint, Channel, TraceParams);
	
	BeamTarget = OutHit.TraceEnd;
	
	LaserBeam->SetVariableVec3(FName("BeamEnd"), BeamTarget);
	LaserBeam->SetVariableVec3(FName("BeamStart"), Start);
}
