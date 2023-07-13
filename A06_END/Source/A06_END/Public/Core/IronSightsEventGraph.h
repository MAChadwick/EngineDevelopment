// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "IronSightsEventGraph.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAttackAnimationEnded);

UCLASS()
class A06_END_API UIronSightsEventGraph : public UAnimInstance
{
	GENERATED_BODY()

private:
	FTimerHandle AttackTimerHandle;

public:
	void NativeUpdateAnimation(float deltaSeconds) override;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FTimerHandle AnimateTimerHandle;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Speed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Direction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		class UAnimSequence* AttackAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		class UAnimSequence* HurtAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TArray<class UAnimSequence*> DeathAnims;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UAnimSequence* CurrentDeath;

public:
	UPROPERTY(VisibleAnywhere, BlueprintAssignable)
		FOnAttackAnimationEnded OnAttackAnimationEnded;

	UFUNCTION(BlueprintCallable)
		void PlayAttackAnim();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void PlayHurtAnim(float Percent);
	virtual void PlayHurtAnim_Implementation(float Percent);

	UFUNCTION(BlueprintCallable)
		void PlayDeathAnim(float Percent);

	UFUNCTION()
		void AttackAnimationEnded();
};
