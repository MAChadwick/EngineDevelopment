// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/PickupBase.h"
#include "PickupsInterface.h"
#include "Components/BoxComponent.h"
#include "../../A06_END.h"

// Sets default values
APickupBase::APickupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &APickupBase::HandleOverlap);
	SetRootComponent(BoxCollider);
}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APickupBase::CanPickup(AActor* OtherActor) const
{
	return true;
}

bool APickupBase::ShouldPickup(AActor* OtherActor) const
{
	return true;
}

void APickupBase::HandlePostPickup()
{
	Destroy();
}

void APickupBase::HandleOverlap(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
	if (CanPickup(OtherActor) && ShouldPickup(OtherActor))
	{
		HandlePickup(OtherActor, SweepResult);
		HandlePostPickup();
	}
	else
		HandleNoPickup();
}

void APickupBase::HandleNoPickup()
{
	return;
}

void APickupBase::HandlePickup(AActor* OtherActor, const FHitResult& hitResult)
{
	return;
}
