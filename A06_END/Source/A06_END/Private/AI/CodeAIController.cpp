// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/CodeAIController.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionTypes.h"
#include "../../A06_END.h"

ACodeAIController::ACodeAIController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("UAISenseConfig_Sight"));
	SightComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));

	FAISenseAffiliationFilter filter;
	filter.bDetectNeutrals = true;

	SightConfig->SightRadius = 1000.0f;
	SightConfig->LoseSightRadius = 1500.0f;
	SightConfig->PeripheralVisionAngleDegrees = 35.0f;
	SightConfig->DetectionByAffiliation = filter;

	SightComponent->ConfigureSense(*SightConfig);

	SightComponent->Activate();
}

void ACodeAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	bool didRun = RunBehaviorTree(BehaviorTree);

	SightComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ACodeAIController::ProcessPerceptionUpdate);
}

void ACodeAIController::ProcessPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus)
{

	FVector Pos = Stimulus.StimulusLocation;

	if (Stimulus.WasSuccessfullySensed())
		Blackboard->SetValueAsObject(PlayerKey, Actor);
	else
		Blackboard->ClearValue(PlayerKey);
}