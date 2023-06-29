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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent* SpringArmComponent;

public:
	ABaseCharacter_Player();
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForwardBackward(float AxisValue);
};