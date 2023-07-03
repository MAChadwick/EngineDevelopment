// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter_AI.h"

ABaseCharacter_AI::ABaseCharacter_AI()
{
	PrimaryActorTick.bCanEverTick = true;
}

	// Called every frame
void ABaseCharacter_AI::Tick(float DeltaTime)
{
	CharacterAttack();
}