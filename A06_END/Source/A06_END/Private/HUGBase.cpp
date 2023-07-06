// Fill out your copyright notice in the Description page of Project Settings.


#include "HUGBase.h"
#include "Components/ProgressBar.h"

void UHUGBase::NativeConstruct()
{
	Super::NativeConstruct();

	FAnchors anchors;
	anchors.Minimum = FVector2D(0.5f, 0.0f);
	anchors.Maximum = FVector2D(0.5f, 0.0f);

	HealthBar->SetPercent(1.0f);
}

void UHUGBase::SetPlayerHealth(float percent)
{
	HealthBar->SetPercent(percent);
}