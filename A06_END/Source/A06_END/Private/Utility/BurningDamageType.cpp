// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/EffectComponent.h"
#include "Utility/Enums.h"
#include "../../A06_END.h"
#include "Utility/BurningDamageType.h"

void UBurningDamageType::StartEffect(AActor* DamagedActor, AActor* DamageCauser)
{
	UE_LOG(Game, Error, TEXT("Line 11 BurningDamageType.cpp"));
	UActorComponent* ActorEffectComponent = DamagedActor->GetComponentByClass(EffectComponentClass);
	UEffectComponent* EffectComponent = Cast<UEffectComponent>(ActorEffectComponent);

	if (nullptr != EffectComponent)
	{
		UE_LOG(Game, Error, TEXT("Line 17 BurningDamageType.cpp"));
		EffectComponent->StartEffect(EEffects::EFFECTS_BURNING, DamageCauser);
	}
}