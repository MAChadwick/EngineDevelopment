// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageVariable, float, percent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeathVariable, float, percent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealVariable, float, percent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class A06_END_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	float maxHealth;
	float currentHealth;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
		void HandleDamage(AActor* damagedActor, float damage, const UDamageType* damageType, AController* instigator, AActor* damageCauser);

	UFUNCTION()
		bool IsFullHealth();

	// Delegate Variables
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Variable | Dispatcher")
		FOnDamageVariable OnDamage;

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Variable | Dispatcher")
		FOnDeathVariable OnDeath;

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Variable | Dispatcher")
		FOnHealVariable OnHeal;
};
