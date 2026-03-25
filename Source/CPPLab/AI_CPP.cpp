// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_CPP.h"
#include "AIController.h"
#include "NavigationSystem.h" 
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAI_CPP::AAI_CPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI_CPP::BeginPlay()
{
	Super::BeginPlay();
	MoveToPlayer();
}

// Called every frame
void AAI_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (player != nullptr)
	{
		FVector playerLocation = player->GetActorLocation();
		FVector botLocation = this->GetActorLocation();
		FVector distanceVector = botLocation - playerLocation;

			if (distanceVector.Length() <= WithinRangeToPlayer)
			{
				WaitToMoveAgain();
			}
	}
}

// Called to bind functionality to input
void AAI_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAI_CPP::MoveToPlayer()
{
	AController* AIController = GetController();
	player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	UAIBlueprintHelperLibrary::SimpleMoveToActor(AIController, player);
}

void AAI_CPP::MoveToPlayerAgain()
{
	MoveToPlayer();
}

void AAI_CPP::WaitToMoveAgain()
{
	player = nullptr;
	GetWorldTimerManager().SetTimer(delayTimer, this, &AAI_CPP::MoveToPlayerAgain, DelayBeforMoving, false, 2.0f);
}

