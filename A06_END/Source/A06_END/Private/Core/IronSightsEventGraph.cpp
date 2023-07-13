// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/IronSightsEventGraph.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimSequence.h"
#include "../../A06_END.h"
#include "GameFramework/Pawn.h"


void UIronSightsEventGraph::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn* Owner = TryGetPawnOwner();

	if (nullptr == Owner)
	{
		//UE_LOG(Game, Error, TEXT("Didn't get owner pawn | IronSightsAnimation.cpp, NativeUpdateAnimation"));
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

void UIronSightsEventGraph::PlayAttackAnim()
{
	PlaySlotAnimationAsDynamicMontage(AttackAnim, FName("Action"), 0.25f, 0.25f, 1.0f, 1);

	GetWorld()->GetTimerManager().SetTimer(AttackTimerHandle, this, &UIronSightsEventGraph::AttackAnimationEnded, AttackAnim->GetPlayLength());
}

void UIronSightsEventGraph::PlayHurtAnim_Implementation(float Percent)
{
	PlaySlotAnimationAsDynamicMontage(HurtAnim, FName("Action"), 0.25f, 0.25f, 1.0f, 1);
}

void UIronSightsEventGraph::PlayDeathAnim(float Percent)
{
	CurrentDeath = DeathAnims[FMath::RandRange(0, DeathAnims.Num() - 1)];
	PlaySlotAnimationAsDynamicMontage(CurrentDeath, FName("Action"), 0.25f, 0.25f, 1.0f, 1);
}

void UIronSightsEventGraph::AttackAnimationEnded()
{
	OnAttackAnimationEnded.Broadcast();
}
