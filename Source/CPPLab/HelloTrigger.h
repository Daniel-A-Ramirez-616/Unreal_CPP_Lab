// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HelloTrigger.generated.h"

UCLASS(Blueprintable, BlueprintType)
class CPPLAB_API AHelloTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHelloTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;


	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginOverlapCPPCODE(AActor* otherActor);

	UFUNCTION(BlueprintNativeEvent)
	void OnEndOverlapCPPCODE(AActor* otherActor);

};
