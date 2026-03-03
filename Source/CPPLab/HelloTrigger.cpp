// Fill out your copyright notice in the Description page of Project Settings.


#include "HelloTrigger.h"

// Sets default values
AHelloTrigger::AHelloTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHelloTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHelloTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AHelloTrigger::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("Begin Overlap"));
	OnBeginOverlapCPPCODE(OtherActor);
}

void AHelloTrigger::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("End Overlap"));
	OnEndOverlapCPPCODE(OtherActor);
}

void AHelloTrigger::OnEndOverlapCPPCODE_Implementation(AActor* otherActor)
{
	
}
