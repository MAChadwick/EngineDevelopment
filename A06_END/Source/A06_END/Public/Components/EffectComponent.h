// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utility/Enums.h"
#include "Components/SceneComponent.h"
#include "Actors/BurningEffect.h"
#include "EffectComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class A06_END_API UEffectComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEffectComponent();

private:
	UFUNCTION()
		void StartBurning(AActor* DamageCauser);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Class reference
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		class ABurningEffect* BurningEffect;

	UFUNCTION()
		void StartEffect(EEffects effect, AActor* DamageCauser);
};
