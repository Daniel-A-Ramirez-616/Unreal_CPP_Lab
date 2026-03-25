// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPLabCharacter.h"
#include "CPP_InteractablePawn.generated.h"

/**
 * 
 */
UCLASS()
class CPPLAB_API ACPP_InteractablePawn : public ACPPLabCharacter
{
	GENERATED_BODY()
	

public:

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* InteractAction;

	void PerformWorldTrace();
protected:
	/** Initialize input action bindings */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
