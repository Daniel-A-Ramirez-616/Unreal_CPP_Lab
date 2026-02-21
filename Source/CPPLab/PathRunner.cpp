// Fill out your copyright notice in the Description page of Project Settings.


#include "PathRunner.h"

// Sets default values
APathRunner::APathRunner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APathRunner::BeginPlay()
{
	Super::BeginPlay();
	PathListIndex = 0;
	Currentpoint = PathList[PathListIndex];
	SetMoveDirection();
}

// Called every frame
void APathRunner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsActive) { return; }

	if (HasDynamicDirection) { SetMoveDirection(); }

	FVector location = GetActorLocation();


	location += (MoveDirection * moveSpeed * DeltaTime);
	SetActorLocation(location);


	if (IsCloseToTarget())
	{
		SetNextPathPoint();
		SetMoveDirection();
	}

}


void APathRunner::SetNextPathPoint()
{
	PathListIndex++;
	if (PathListIndex >= PathList.Num())
	{
		PathListIndex = 0;
	}
	Currentpoint = PathList[PathListIndex];
}

void APathRunner::SetMoveDirection()
{
	FVector OurLocation = GetActorLocation();
	FVector PointLocation = Currentpoint->GetActorLocation();
	FVector direction = PointLocation - OurLocation;


	direction.Normalize();
	MoveDirection = direction;

	direction.Z = 0;
	SetActorRotation(FRotator::MakeFromEuler(direction));

}

bool APathRunner::IsCloseToTarget()
{
	FVector OurLocation = GetActorLocation();
	FVector PointLocation = Currentpoint->GetActorLocation();
	FVector direction = PointLocation - OurLocation;

	return (direction.Length() < PointWithinRange);
}

