// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CppPlayerController.generated.h"

UCLASS()
class SPACERANCHER_API ACppPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACppPlayerController(const FObjectInitializer& ObjectInitializer);

	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
	class AMyCharacter* PlayerCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMainGameInstance* GameInstance;

	UFUNCTION(Exec)
	void SetTime(int Hour, int Minute = 0) const;
};
