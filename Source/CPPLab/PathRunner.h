// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PathRunner.generated.h"

UCLASS()
class CPPLAB_API APathRunner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APathRunner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	AActor* Currentpoint;
	FVector MoveDirection;

public:

	/* Is Path Runner Active*/
	UPROPERTY(BlueprintReadWrite,EditInstanceOnly, Category = "Path Runner Values")
	bool IsActive = true;

	/* List of actors to path */
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Path Runner Values")
	TArray<AActor*> PathList;

	/* Does the pathrunner update Direction every tick */
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Path Runner Values")
	bool HasDynamicDirection = true;

	/* How close is close enough */
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Path Runner Values")
	float PointWithinRange = 50;

	/* Movement Speed */
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Path Runner Values")
	float moveSpeed = 500;

	/* Index in the path array */
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Path Runner Values")
	int32 PathListIndex = 0;

	void SetNextPathPoint();

	void SetMoveDirection();

	bool IsCloseToTarget();

};
