 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPMethodExample.generated.h"

UCLASS()
class CPPLAB_API ACPPMethodExample : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPMethodExample();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	int AddOne(int value);

	UFUNCTION(BlueprintCallable)
	int TimesTwo(int value);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int TimesThreePure(int value);


};
