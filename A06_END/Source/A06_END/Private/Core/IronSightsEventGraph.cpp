// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/IronSightsEventGraph.h"

void UIronSightsEventGraph::NativeUpdateAnimation(float deltaSeconds)
{
	Super::NativeUpdateAnimation(deltaSeconds);
	APawn *Pawn = TryGetPawnOwner();
	if (nullptr != Pawn)
	{
		Speed = Pawn->GetVelocity().Size();
	}
	else 
	{

	}

}
