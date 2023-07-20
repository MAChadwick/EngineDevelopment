// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "EnemyInterface.h"
#include "BaseCharacter_AI.generated.h"

/**
 * 
 */
UCLASS()
class A06_END_API ABaseCharacter_AI : public ABaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:	
	// Sets default values for this character's properties
	ABaseCharacter_AI();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Begin EnemyInterface
	virtual void AIAttack() override;
	// End EnemyInterface
};
