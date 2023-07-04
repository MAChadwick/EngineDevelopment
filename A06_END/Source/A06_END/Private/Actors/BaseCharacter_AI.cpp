// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter_AI.h"
#include "Components/SkeletalMeshComponent.h"

ABaseCharacter_AI::ABaseCharacter_AI()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseCharacter_AI::BeginPlay()
{
	Super::BeginPlay();
}

	// Called every frame
void ABaseCharacter_AI::Tick(float DeltaTime)
{
	CharacterAttack();
}