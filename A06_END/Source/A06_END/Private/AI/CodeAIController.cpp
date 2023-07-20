// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/CodeAIController.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionTypes.h"

ACodeAIController::ACodeAIController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("UAISenseConfig_Sight"));
	SightComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
}

void ACodeAIController::OnPossess(APawn* InPawn)
{
	RunBehaviorTree(BehaviorTree);

	SightComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ACodeAIController::ProcessPerceptionUpdate);
}

void ACodeAIController::ProcessPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.SensingSucceeded)
		Blackboard->SetValueAsObject(PlayerKey, Actor);
	else
		Blackboard->ClearValue(PlayerKey);
}