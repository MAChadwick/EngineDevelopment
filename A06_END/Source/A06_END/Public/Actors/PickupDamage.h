// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/PickupBase.h"
#include "Utility/BurningDamageType.h"
#include "PickupDamage.generated.h"

/**
 * 
 */
UCLASS()
class A06_END_API APickupDamage : public APickupBase
{
	GENERATED_BODY()

public:
	APickupDamage();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float BaseDamage;

	virtual void HandlePickup(AActor* OtherActor, const FHitResult& SweepResult) override;
	virtual void HandlePostPickup() override;
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UParticleSystemComponent* ParticleSystem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TSubclassOf<class UBurningDamageType> DamageTypeClass;
};
