// Fill out your copyright notice in the Description page of Project Settings.


#include "HUGBase.h"
#include "../A06_END.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/ProgressBar.h"

UHUGBase::UHUGBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	if (nullptr == HealthBar)
		UE_LOG(Game, Error, TEXT("No HealthBar Set | HUGBASE.cpp, Constructor"));
}

bool UHUGBase::Initialize()
{
	bool value = Super::Initialize();

	UCanvasPanelSlot* MySlot = Cast<UCanvasPanelSlot>(HealthBar->Slot);

	if (nullptr == MySlot)
		UE_LOG(Game, Error, TEXT("Could not cast to UCanvasPanelSlot | HUGBase.cpp, Initialize"));

	HealthBar->SetPercent(1.0f);

	return value;
}

void UHUGBase::NativeConstruct()
{
	Super::NativeConstruct();

	FAnchors anchors;
	anchors.Minimum = FVector2D(0.5f, 0.0f);
	anchors.Maximum = FVector2D(0.5f, 0.0f);
}

void UHUGBase::SetPlayerHealth(float percent)
{
	HealthBar->SetPercent(percent);
}