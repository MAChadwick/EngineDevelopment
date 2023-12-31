// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"


#include "BaseRifle.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShotVariable);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmmoChanged, float, Current, float, Max);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReloadStart);

UCLASS()
class A06_END_API ABaseRifle : public AActor
{
	GENERATED_BODY()

private:
	APawn* ParentPawn;

public:	
	// Sets default values for this actor's properties
	ABaseRifle();

	bool IsDead;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class ABaseBullet* Bullet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool Animate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float CurrentAmmo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float MaxAmmo;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Delegate variable
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Variable | Dispatcher")
		FOnShotVariable OnShot;

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Variable | Dispatcher")
		FOnAmmoChanged OnAmmoChanged;

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Variable | Dispatcher")
		FOnReloadStart OnReloadStart;

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Variable | Dispatcher")
		FOnMontageEndedMCDelegate OnAnimationEnded;

	// Bullet class declaration
	UPROPERTY(VisibleAnywhere, BlueprintreadOnly)
		class ABaseBullet* BulletClass;

	// Function for OnShot delegate
	UFUNCTION()
		void Attack();

	// Function for OnAnimationEnded delegate
	UFUNCTION()
		void AnimationEnded();

	UFUNCTION()
		void OwnerDied();

	UFUNCTION()
		FVector GetFirePoint();

	UFUNCTION()
		void Reload();

	UFUNCTION()
		void RequestReload();

	UFUNCTION()
		void UseAmmo();
};
