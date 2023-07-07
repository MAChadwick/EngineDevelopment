// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "BaseCharacter_Player.generated.h"

/**
 * 
 */

UCLASS()
class A06_END_API ABaseCharacter_Player : public ABaseCharacter
{
	GENERATED_BODY()
	
protected:

	void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCameraComponent* CameraComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		class UHUGBase* HudWidget;

public:
	ABaseCharacter_Player();
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	virtual void CharacterDeath(float Percent) override;

private:
	void MoveForwardBackward(float AxisValue);
	void MoveLeftRight(float AxisValue);

	void SetupHud();
};
