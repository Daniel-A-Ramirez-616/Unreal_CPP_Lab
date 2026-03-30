// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InteractablePawn.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "CPP_InteractableObject.h"

void ACPP_InteractablePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


		// Set up action bindings
		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

			// Jumping
			EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ACPP_InteractablePawn::PerformWorldTrace);
		}
		else
		{
			UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
		}
}

void ACPP_InteractablePawn::PerformWorldTrace()
{
	UE_LOG(LogTemplateCharacter, Warning, TEXT("PerformWorldTrace"));

	  float LengthOfTrace = 300.f;
	
  FVector StartLocation;
  FVector EndLocation;
  
  StartLocation = FirstPersonCameraComponent->GetComponentLocation();
  
  EndLocation = StartLocation + 
    (FirstPersonCameraComponent->GetForwardVector() * LengthOfTrace);
	
  FHitResult OutHitResult;
  FCollisionQueryParams LineTraceParams;  
   
  bool bHitSomething = GetWorld()->LineTraceSingleByChannel(OutHitResult, 
                       StartLocation, EndLocation, ECC_Visibility, LineTraceParams);


  if (bHitSomething)
  {

	  CPP_InteractableObject* CPP_InteractableObjectInstance = Cast<CPP_InteractableObject>(OutHitResult.GetActor());

	  if (CPP_InteractableObjectInstance)
	  {
		  CPP_InteractableObjectInstance->OnUse();
	  }
  }
}