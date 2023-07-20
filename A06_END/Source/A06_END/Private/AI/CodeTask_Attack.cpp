// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/CodeTask_Attack.h"
#include "Actors/BaseCharacter_AI.h"
#include "AI/CodeAIController.h"
#include "EnemyInterface.h"
#include "../../A06_END.h"

EBTNodeResult::Type UCodeTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACodeAIController* Controller = Cast<ACodeAIController>(OwnerComp.GetAIOwner());
	ABaseCharacter_AI* Actor = Cast<ABaseCharacter_AI>(OwnerComp.GetOwner());
	IEnemyInterface* Interface = Cast<IEnemyInterface>(Actor);

	if (nullptr == Actor) UE_LOG(Game, Log, TEXT("ACtor Null"));

	if (nullptr != Interface)
	{
		Interface->AIAttack();

		return EBTNodeResult::Succeeded;
		UE_LOG(Game, Log, TEXT("Cast Complete"));
	}
	else
		UE_LOG(Game, Log, TEXT("Interface Null"));

	return EBTNodeResult::Failed;
}


