// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Harvester.h"
#include "Interactables/HarvesterAffectable.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "Characters/Main Character/MyCharacter.h"
#include "Particles/ParticleSystemComponent.h"
#include "Items/HarvesterAttachmentBase.h"

AHarvester::AHarvester()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	AddOwnedComponent(StaticMesh);

	LaserHolder = CreateDefaultSubobject<USceneComponent>(TEXT("LaserHolder"));
	LaserHolder->SetupAttachment(StaticMesh);
	
	LaserBeam = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Laser Beam"));
	LaserBeam->SetupAttachment(LaserHolder);

	AttachmentHolder = CreateDefaultSubobject<USceneComponent>(TEXT("AttachmentHolder"));
	AttachmentHolder->SetupAttachment(StaticMesh);

	Attachment = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Attachment"));
	Attachment->SetupAttachment(AttachmentHolder);
}

void AHarvester::BeginPlay()
{
	Super::BeginPlay();
	LaserBeam->Activate();
}

void AHarvester::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bLaserActive)
	{
		UpdateAimDirection();
		AActor* AffectedActor = GetHitActor();
		if (AffectedActor)
		{
			if (AffectedActor->GetClass()->ImplementsInterface(UHarvesterAffectable::StaticClass()))
			{
				IHarvesterAffectable::Execute_PrimaryAffect(AffectedActor, ActiveAttachment, DeltaTime);
			}
		}
	}
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

AActor* AHarvester::GetHitActor()
{
	return HitActor;
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
	return false;
}

bool AHarvester::DeactivateLaser()
{
	if (bLaserActive)
	{
		LaserBeam->Deactivate();
		bLaserActive = false;
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

	HitActor = OutHit.GetActor();
	
	LaserBeam->SetVariableVec3(FName("BeamEnd"), BeamTarget);
	LaserBeam->SetVariableVec3(FName("BeamStart"), Start);
}
