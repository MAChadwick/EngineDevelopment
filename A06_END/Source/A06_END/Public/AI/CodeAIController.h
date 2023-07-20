// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CodeAIController.generated.h"

/**
 * 
 */
UCLASS()
class A06_END_API ACodeAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ACodeAIController(const FObjectInitializer & ObjectInitializer);

	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		FName PlayerKey;

protected:
	UPROPERTY()
		UAIPerceptionComponent* SightComponent;

	UPROPERTY()
		class UAISenseConfig_Sight* SightConfig;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UBehaviorTree* BehaviorTree;

private:
	UFUNCTION()
		void ProcessPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus);
};
