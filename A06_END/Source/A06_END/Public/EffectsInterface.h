// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EffectsInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UEffectsInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class A06_END_API IEffectsInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		virtual void StartEffect(AActor* DamagedActor, AActor* DamageCauser) const = 0 ;
};
