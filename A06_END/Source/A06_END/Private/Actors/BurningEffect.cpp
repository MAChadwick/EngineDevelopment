// Fill out your copyright notice in the Description page of Project Settings.


#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../../A06_END.h"
#include "Actors/BurningEffect.h"

// Sets default values
ABurningEffect::ABurningEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	DamagePerSecond = 0.25f;
}

// Called when the game starts or when spawned
void ABurningEffect::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(Game, Log, TEXT("I{M ALIVE"));
}

// Called every frame
void ABurningEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float DamageWithTime = DamagePerSecond * DeltaTime;

	UGameplayStatics::ApplyDamage(GetAttachParentActor(), DamageWithTime, GetInstigatorController(), GetOwner(), UDamageType::StaticClass());
}

