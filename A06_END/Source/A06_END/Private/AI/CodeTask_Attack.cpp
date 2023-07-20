// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/CodeTask_Attack.h"
#include "Actors/BaseCharacter_AI.h"
#include "AI/CodeAIController.h"
#include "EnemyInterface.h"
#include "../../A06_END.h"

EBTNodeResult::Type UCodeTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AActor* Actor = OwnerComp.GetAIOwner()->GetPawn();
	IEnemyInterface* Interface = Cast<IEnemyInterface>(Actor);

	if (nullptr != Interface)
	{
		Interface->AIAttack();

		return EBTNodeResult::Succeeded;
	}
	else
		UE_LOG(Game, Log, TEXT("Interface Null"));

	return EBTNodeResult::Failed;
}


