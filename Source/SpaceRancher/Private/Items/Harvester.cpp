// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Harvester.h"
#include "Interactables/HarvesterAffectable.h"
#include "Characters/Main Character/CppPlayerController.h"
#include "Characters/Main Character/MyCharacter.h"
#include "Particles/ParticleSystemComponent.h"

AHarvester::AHarvester()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	SetRootComponent(StaticMesh);
	
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

	SetActorTickEnabled(false);
}

void AHarvester::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bLaserActive && !bCollectDeactivated)
	{
		UpdateAimDirection();
		if (HitActor && HitActor == LastAffectedActor)
		{
			if (HitActor->GetClass()->ImplementsInterface(UHarvesterAffectable::StaticClass()))
			{
				IHarvesterAffectable::Execute_PrimaryAffect(HitActor, this, DeltaTime);
			}
		}
		else if (LastAffectedActor)
		{
			IHarvesterAffectable::Execute_EndPrimaryAffect(LastAffectedActor, this);
		}
	}

	LastAffectedActor = GetHitActor() ? HitActor : LastAffectedActor;
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
	SetActorTickEnabled(true);
	LaserBeam->Activate();
	LaserBeam->SetVariableVec3(FName("BeamEnd"), BeamTarget);
	return true;
}

bool AHarvester::DeactivateLaser()
{
	if (bLaserActive)
	{
		LaserBeam->Deactivate();
		SetActorTickEnabled(false);
		bLaserActive = false;
		SetCollectDeactivated(false);
		if (LastAffectedActor)
		{
			IHarvesterAffectable::Execute_EndPrimaryAffect(LastAffectedActor, this);
		}
		return true;
	}
	return false;
}

void AHarvester::UpdateAimDirection()
{
	LaserStart = LaserHolder->GetComponentLocation();
	
	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = false;
	ECollisionChannel Channel = ECC_Visibility;
	FHitResult OutHit(ForceInit);

	LaserTarget = PC->GetPlayerCharacter()->GetViewPoint();

	if (FVector::Distance(LaserStart, LaserTarget) > LaserRange)
	{
		LaserTarget = PC->GetPlayerCharacter()->GetViewForwardVector() * LaserRange + LaserStart;
	}

	GetWorld()->LineTraceSingleByChannel(OutHit, LaserStart, LaserTarget, Channel, TraceParams);
	
	BeamTarget = OutHit.TraceEnd;

	HitActor = PC->GetPlayerCharacter()->LineTraceFromView(LaserRange).GetActor();
	if (HitActor)
	{
		HitActor = HitActor->Implements<UHarvesterAffectable>() ? HitActor : nullptr;
	}
	
	LaserBeam->SetVariableVec3(FName("BeamEnd"), BeamTarget);
	LaserBeam->SetVariableVec3(FName("BeamStart"), LaserStart);
}
