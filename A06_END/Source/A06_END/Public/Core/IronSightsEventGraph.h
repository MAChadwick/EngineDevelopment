// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "IronSightsEventGraph.generated.h"

/**
 * 
 */
UCLASS()
class A06_END_API UIronSightsEventGraph : public UAnimInstance
{
	GENERATED_BODY()
public:
	UIronSightsEventGraph();
	void NativeUpdateAnimation(float deltaSeconds) override;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Speed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Direction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UAnimSequence* AnimSequence;

public:
	UFUNCTION()
		void PlayAttackAnim();
};
