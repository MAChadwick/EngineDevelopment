// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task_FindPoint.h"
#include "AI/CodeAIController.h"
#include "NavigationSystem.h"

EBTNodeResult::Type UTask_FindPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACodeAIController* Controller = Cast<ACodeAIController>(OwnerComp.GetAIOwner());

	FVector ActorLocation = Controller->GetPawn()->GetActorLocation();

	const UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());

	FNavLocation RandomLocation;
	bool FoundLocation = NavSystem->GetRandomReachablePointInRadius(ActorLocation, Radius, RandomLocation);



	return EBTNodeResult::Succeeded;
}