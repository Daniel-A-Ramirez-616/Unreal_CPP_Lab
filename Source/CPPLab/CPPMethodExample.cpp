// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPMethodExample.h"

// Sets default values
ACPPMethodExample::ACPPMethodExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPMethodExample::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPMethodExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ACPPMethodExample::AddOne(int value)
{
	return (value++);
}

int ACPPMethodExample::TimesTwo(int value)
{
	return (value * 2);
}

int ACPPMethodExample::TimesThreePure(int value)
{
	return(value * 3);
}


