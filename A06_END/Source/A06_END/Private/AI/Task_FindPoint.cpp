// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task_FindPoint.h"
#include "AI/CodeAIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "../../A06_END.h"

EBTNodeResult::Type UTask_FindPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	FVector ActorLocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();

	const UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());

	FNavLocation RandomLocation;
	bool FoundLocation = NavSystem->GetRandomReachablePointInRadius(ActorLocation, Radius, RandomLocation);

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("Destination"), RandomLocation.Location);

	return (FoundLocation ? EBTNodeResult::Succeeded : EBTNodeResult::Failed);
}