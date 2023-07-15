// Fill out your copyright notice in the Description page of Project Settings.

#include "Utility/BurningDamageType.h"
#include "Components/EffectComponent.h"
#include "Utility/Enums.h"
#include "../../A06_END.h"

void UBurningDamageType::StartEffect(AActor* DamagedActor, AActor* DamageCauser) const
{
	UEffectComponent* ActorEffectComponent = DamagedActor->FindComponentByClass<UEffectComponent>();

	if (nullptr != ActorEffectComponent)
	{
		ActorEffectComponent->StartEffect(EEffects::EFFECTS_BURNING, DamageCauser);
	}
}