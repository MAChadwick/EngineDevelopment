// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/PickupDamage.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "../../A06_END.h"


APickupDamage::APickupDamage()
{
	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));

	ParticleSystem->SetupAttachment(BoxCollider);

	ParticleSystem->SetRelativeLocation(FVector(0, 0, -30.0f));
	ParticleSystem->SetRelativeScale3D(FVector(0.4f, 0.4f, 0.25f));

	BoxCollider->SetRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));

	BaseDamage = 2.0f;
}

void APickupDamage::HandlePostPickup()
{
	return;
}

void APickupDamage::HandlePickup(AActor* OtherActor, const FHitResult& SweepResult)
{
	UGameplayStatics::ApplyDamage(OtherActor, BaseDamage, this->GetInstigatorController(), this, DamageTypeClass);
}