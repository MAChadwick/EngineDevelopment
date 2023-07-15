// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Core/IronSightsEventGraph.h"
#include "Components/HealthComponent.h"
#include "Components/EffectComponent.h"
#include "PickupsInterface.h"
#include "BaseCharacter.generated.h"

UCLASS(Abstract)
class A06_END_API ABaseCharacter : public ACharacter, public IPickupsInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Child component for rifle
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UChildActorComponent* WeaponChildActorComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class ABaseRifle* CurrentWeapon;

	UPROPERTY()
		UIronSightsEventGraph* Animation;

	UPROPERTY()
		UHealthComponent* Health;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UEffectComponent* Effect;

private:
	// Helper functions for initializing values
	void SetupCharacter();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Begin IPickupsInterface
	virtual bool CanPickupHealth() override;
	virtual bool ShouldPickupHealth() override;
	// End IPickupsInterface

	UFUNCTION()
		void CharacterAttack();

	UFUNCTION()
		virtual void CharacterDeath(float Percent);
};
