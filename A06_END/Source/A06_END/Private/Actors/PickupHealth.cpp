// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/PickupHealth.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "Particles/ParticleSystemComponent.h"
#include "Sound/SoundBase.h"
#include "../../A06_END.h"
#include "PickupsInterface.h"

APickupHealth::APickupHealth()
{
	
	ParticleSystem->SetRelativeLocation(FVector(0, 0, -40.0f));
	ParticleSystem->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.7f));

}

void APickupHealth::BeginPlay()
{
	// I set this here because it wasn't wanting to set in the constructor for some reason
	BaseDamage = -2.0f;
}

void APickupHealth::HandlePostPickup()
{
	Destroy();
}

void APickupHealth::HandleNoPickup()
{
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), FullHealthSound, GetActorLocation());
}

bool APickupHealth::CanPickup(AActor* OtherActor) const
{
	bool returnVal = false;

	IPickupsInterface* Interface = Cast<IPickupsInterface>(OtherActor);

	if (nullptr != Interface)
	{
		// Function call
		returnVal = Interface->CanPickupHealth();
	}

	return returnVal;
}

bool APickupHealth::ShouldPickup(AActor* OtherActor) const
{
	bool returnVal = false;

	IPickupsInterface* Interface = Cast<IPickupsInterface>(OtherActor);

	if (nullptr != Interface)
	{
		// Function call
		returnVal = Interface->ShouldPickupHealth();
	}

	return returnVal;
}