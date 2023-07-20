// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter_AI.h"
#include "Actors/BaseRifle.h"
#include "../../A06_END.h"

ABaseCharacter_AI::ABaseCharacter_AI()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABaseCharacter_AI::BeginPlay()
{
	Super::BeginPlay();
	CurrentWeapon->Reload();
}

	// Called every frame
void ABaseCharacter_AI::Tick(float DeltaTime)
{
	CharacterAttack();
}

void ABaseCharacter_AI::AIAttack()
{
	CharacterAttack();
}