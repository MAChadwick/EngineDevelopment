// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "EffectsInterface.h"
#include "BurningDamageType.generated.h"

/**
 * 
 */
UCLASS()
class A06_END_API UBurningDamageType : public UDamageType, public IEffectsInterface
{
	GENERATED_BODY()
	
public:
	// Forward declares
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Variable|Class Ref")
		TSubclassOf<class UEffectComponent> EffectComponentClass;

	// Start IEffectsInterface
	virtual void StartEffect(AActor* DamagedActor, AActor* DamageCauser) override;
	// End IEffectsInterface
};
