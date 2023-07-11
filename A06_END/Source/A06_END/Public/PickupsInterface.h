// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PickupsInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI , meta = (CannotImplementInterfaceInBlueprint))
class UPickupsInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class A06_END_API IPickupsInterface
{
	GENERATED_BODY()
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable)
		virtual bool CanPickupHealth() = 0;

	UFUNCTION(BlueprintCallable)
		virtual bool ShouldPickupHealth() = 0;
};
