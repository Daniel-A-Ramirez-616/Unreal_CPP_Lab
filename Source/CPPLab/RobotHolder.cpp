// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "RobotHolder.h"

// Sets default values
ARobotHolder::ARobotHolder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARobotHolder::BeginPlay()
{
	Super::BeginPlay();
	

    AController* pc = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (pc == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("HOLDER:: No Controller Found"));
        return;
    }
    RobotSpawned = pc->GetPawn();
}

// Called every frame
void ARobotHolder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

