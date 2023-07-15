// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/EffectComponent.h"
#include "Utility/Enums.h"
#include "Actors/BurningEffect.h"
#include "../../A06_END.h"

// Sets default values for this component's properties
UEffectComponent::UEffectComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UEffectComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEffectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEffectComponent::StartEffect(EEffects effect, AActor* DamageCauser)
{
	switch (effect)
	{
	case EEffects::EFFECTS_BURNING:
		StartBurning(DamageCauser);
		break;
	default:
		UE_LOG(Game, Error, TEXT("Invalid effect sent in | EffectComponent.cpp, StartEffect"));
		break;
	}
}

void UEffectComponent::StartBurning(AActor* DamageCauser)
{
	FActorSpawnParameters params;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::Undefined;
	params.Owner = DamageCauser;

	AActor* BurningEffectActor = GetWorld()->SpawnActor<ABurningEffect>(GetComponentLocation(), GetComponentRotation(), params);

	if (nullptr != BurningEffectActor)
	{
		FAttachmentTransformRules rules = { EAttachmentRule::KeepWorld, true };

		BurningEffectActor->AttachToActor(GetOwner(), rules);
	}
	else
		UE_LOG(Game, Error, TEXT("Could not spawn BurningEffect actor"));
}
