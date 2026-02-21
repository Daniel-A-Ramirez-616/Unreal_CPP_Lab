// Fill out your copyright notice in the Description page of Project Settings.


#include "Lab04Pawn.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Kismet/GameplayStatics.h"


void ALab04Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	holder = (ARobotHolder*)UGameplayStatics::GetActorOfClass(GetWorld(), ARobotHolder::StaticClass());



	ACPPLabCharacter::SetupPlayerInputComponent(PlayerInputComponent);
	
	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		EnhancedInputComponent->BindAction(SelectPawn1Action, ETriggerEvent::Started, this, &ALab04Pawn::SelectPawn1);
		EnhancedInputComponent->BindAction(SelectPawn2Action, ETriggerEvent::Started, this, &ALab04Pawn::SelectPawn2);
		EnhancedInputComponent->BindAction(SelectPawn3Action, ETriggerEvent::Started, this, &ALab04Pawn::SelectPawn3);
		EnhancedInputComponent->BindAction(SelectPawnSpawnedAction, ETriggerEvent::Started, this, &ALab04Pawn::SelectSpawnedPawn);
		
		
		/*
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACPPLabCharacter::Move);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &ACPPLabCharacter::Look);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPPLabCharacter::Look);
		*/
	}
	
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void ALab04Pawn::SelectPawn1()
{
	UE_LOG(LogTemp, Warning, TEXT("Select Pawn 1"));

	AController* pc = this->GetController();
	if (pc == nullptr)
	{
		return;
	}
	pc->Possess(holder->Robot1);

}


void ALab04Pawn::SelectPawn2()
{
	UE_LOG(LogTemp, Warning, TEXT("Select Pawn 2"));

	AController* pc = this->GetController();
	if (pc == nullptr)
	{
		return;
	}
	pc->Possess(holder->Robot2);

}


void ALab04Pawn::SelectPawn3()
{
	AController* pc = this->GetController();
	if (pc == nullptr)
	{
		return;
	}
	pc->Possess(holder->Robot3);

}


void ALab04Pawn::SelectSpawnedPawn()
{


	AController* pc = this->GetController();
	if (pc == nullptr)
	{
		return;
	}

	if(holder->RobotSpawned != nullptr)
	{ 
	pc->Possess(holder->RobotSpawned);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing "));
	}
}