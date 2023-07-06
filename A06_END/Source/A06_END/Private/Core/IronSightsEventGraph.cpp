// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/IronSightsEventGraph.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimSequence.h"
#include "../../A06_END.h"
#include "GameFramework/Pawn.h"

UIronSightsEventGraph::UIronSightsEventGraph()
{
	ConstructorHelpers::FObjectFinder<UAnimSequence>Sequence(TEXT("AnimSequence'/Game/END_Starter/Mannequin/A_Fire_Ironsights.A_Fire_Ironsights'"));

	AnimSequence = Sequence.Object;
}
void UIronSightsEventGraph::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn* Owner = TryGetPawnOwner();

	if (nullptr == Owner)
	{
		UE_LOG(Game, Error, TEXT("Didn't get owner pawn | IronSightsAnimation.cpp, NativeUpdateAnimation"));
	}
	else
	{
		FVector Velocity = Owner->GetVelocity();
		FRotator Rotation = Owner->GetActorRotation();
		float VelocityLength = Velocity.Size();

		float VelocityDirection = CalculateDirection(Velocity, Rotation);

		Speed = VelocityLength;
		Direction = VelocityDirection;
		
	}
}

void UIronSightsEventGraph::PlayAttackAnim_Implementation()
{
	PlaySlotAnimationAsDynamicMontage(AnimSequence, FName("Action"), 0.25f, 0.25f, 1.0f, 1);
}
