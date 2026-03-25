// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/TimerHandle.h"
#include "AI_CPP.generated.h"

UCLASS()
class CPPLAB_API AAI_CPP : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveToPlayer();

	void MoveToPlayerAgain();

	void WaitToMoveAgain();

	AActor* player;

	FTimerHandle delayTimer;


	float DelayBeforMoving = 5.0f;


	float WithinRangeToPlayer = 150.0f;
};
