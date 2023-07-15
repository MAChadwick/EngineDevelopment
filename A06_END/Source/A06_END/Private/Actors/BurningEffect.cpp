// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BurningEffect.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../../A06_END.h"

// Sets default values
ABurningEffect::ABurningEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	DamagePerSecond = 0.25f;

	InitialLifeSpan = 2.0f;
}

// Called when the game starts or when spawned
void ABurningEffect::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABurningEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float DamageWithTime = DamagePerSecond * DeltaTime;

	UGameplayStatics::ApplyDamage(GetAttachParentActor(), DamageWithTime, GetInstigatorController(), GetOwner(), UDamageType::StaticClass());
}

