// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"
#include "../../A06_END.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	maxHealth = 5;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// Set current health to max health
	currentHealth = maxHealth;

	// Bind damage event to fucntion
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleDamage);
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UHealthComponent::IsFullHealth()
{
	return (currentHealth / maxHealth) > 0.99f;
}

void UHealthComponent::HandleDamage(AActor* damagedActor, float damage, const UDamageType* damageType, AController* instigator, AActor* damageCauser)
{
	currentHealth -= damage;
	currentHealth = FMath::Clamp(currentHealth, 0.0f, maxHealth);

	if (currentHealth > 0)
	{
		if (damage > 0)
			OnDamage.Broadcast(currentHealth / maxHealth);
		else
			OnHeal.Broadcast(currentHealth / maxHealth);
	}
	else
	{
		GetOwner()->OnTakeAnyDamage.RemoveDynamic(this, &UHealthComponent::HandleDamage);
		OnDeath.Broadcast(0);
	}

}

