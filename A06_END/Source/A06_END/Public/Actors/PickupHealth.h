// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/PickupDamage.h"
#include "PickupHealth.generated.h"

/**
 * 
 */
UCLASS()
class A06_END_API APickupHealth : public APickupDamage
{
	GENERATED_BODY()

public:
	APickupHealth();

protected:
	virtual void BeginPlay() override;

	virtual void HandlePickup(AActor* OtherActor, const FHitResult& SweepResult) override;
	virtual void HandlePostPickup() override;
	virtual void HandleNoPickup() override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		USoundBase* FullHealthSound;

	virtual bool CanPickup(AActor* OtherActor) const override;

	virtual bool ShouldPickup(AActor* OtherActor) const override;
};
