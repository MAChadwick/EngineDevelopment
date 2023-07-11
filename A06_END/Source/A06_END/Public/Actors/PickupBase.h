// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupsInterface.h"
#include "Components/BoxComponent.h"
#include "PickupBase.generated.h"

UCLASS()
class A06_END_API APickupBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void HandleOverlap(UPrimitiveComponent* HitComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UBoxComponent* BoxCollider;

	UFUNCTION(BlueprintCallable)
		virtual bool CanPickup(AActor* OtherActor) const;

	UFUNCTION(BlueprintCallable)
		virtual bool ShouldPickup(AActor* OtherActor) const;

	UFUNCTION()
		virtual void HandlePickup(AActor* OtherActor, const FHitResult& hitResult);
	
	UFUNCTION()
		virtual void HandlePostPickup();

	UFUNCTION()
		virtual void HandleNoPickup();

};
