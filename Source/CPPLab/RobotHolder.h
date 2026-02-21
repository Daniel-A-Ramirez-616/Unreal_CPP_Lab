// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RobotHolder.generated.h"

UCLASS()
class CPPLAB_API ARobotHolder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARobotHolder();

	//Robot 1 in world
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	APawn* Robot1;

	//Robot 2 in world
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	APawn* Robot2;

	//Robot 3 in world
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	APawn* Robot3;
	
	// Robot Spawned in world -- will be grabbed on begin play
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	APawn* RobotSpawned;





protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
