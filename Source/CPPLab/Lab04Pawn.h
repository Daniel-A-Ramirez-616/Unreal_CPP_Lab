// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPLabCharacter.h"
#include "Lab04Pawn.generated.h"

/**
 * 
 */
UCLASS()
class CPPLAB_API ALab04Pawn : public ACPPLabCharacter
{
	GENERATED_BODY()


protected:

	/** Initialize input action bindings */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	/** SelectPawn1 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* SelectPawn1Action;


	/** SelectPawn2 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* SelectPawn2Action;


	/** SelectPawn3 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* SelectPawn3Action;


	/** SelectSpawnedPawn */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* SelectPawnSpawnedAction;


public:

	/** Function to select pawn1 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	 void SelectPawn1();

	/** Function to select pawn2 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	 void SelectPawn2();

	/** Function to select pawn3 */
	UFUNCTION(BlueprintCallable, Category = "Input")
	 void SelectPawn3();

	/** Function to select pawn spawned */
	UFUNCTION(BlueprintCallable, Category = "Input")
	 void SelectSpawnedPawn();

};
