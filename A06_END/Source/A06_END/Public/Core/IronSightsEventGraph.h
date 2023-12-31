// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "IronSightsEventGraph.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttackAnimationEnded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReloadEnded);

UCLASS()
class A06_END_API UIronSightsEventGraph : public UAnimInstance
{
	GENERATED_BODY()

public:
	void NativeUpdateAnimation(float deltaSeconds) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FTimerHandle AttackTimerHandle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FTimerHandle ReloadAnimHandle;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Speed;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Direction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		class UAnimSequence* AttackAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		class UAnimSequence* HurtAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		class UAnimSequence* ReloadAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TArray<class UAnimSequence*> DeathAnims;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UAnimSequence* CurrentDeath;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FName SlotName;

public:
	UPROPERTY(VisibleAnywhere, BlueprintAssignable)
		FOnAttackAnimationEnded OnAttackAnimationEnded;

	UPROPERTY(VisibleAnywhere, BlueprintAssignable)
		FOnReloadEnded OnReloadAnimationEnded;

	UFUNCTION(BlueprintCallable)
		void PlayAttackAnim();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void PlayHurtAnim(float Percent);
	virtual void PlayHurtAnim_Implementation(float Percent);

	UFUNCTION(BlueprintCallable)
		void PlayDeathAnim(float Percent);

	UFUNCTION(BlueprintCallable)
		void PlayReloadAnim();

	UFUNCTION()
		void AttackAnimationEnded();

	UFUNCTION()
		void ReloadAnimationEnded();
};
