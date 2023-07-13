// Fill out your copyright notice in the Description page of Project Settings.


#include "HUGBase.h"
#include "../A06_END.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"
#include "Blueprint/SlateBlueprintLibrary.h"
#include "Engine/EngineTypes.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "DrawDebugHelpers.h"
#include <Kismet/KismetSystemLibrary.h>

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

	MySlot = Cast<UCanvasPanelSlot>(Crosshair->Slot);

	if (nullptr == MySlot)
		UE_LOG(Game, Error, TEXT("Could not cast to UImage | HUGBase.cpp, Initialize"));

	HealthBar->SetPercent(1.0f);

	return value;
}

// Called every frame
void UHUGBase::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	ChangeCrosshair();
}

void UHUGBase::NativeConstruct()
{
	Super::NativeConstruct();

	DynamicMaterial = Crosshair->GetDynamicMaterial();

	FAnchors anchors;
	anchors.Minimum = FVector2D(0.5f, 0.0f);
	anchors.Maximum = FVector2D(0.5f, 0.0f);
}

void UHUGBase::SetPlayerHealth(float percent)
{
	HealthBar->SetPercent(percent);
}

void UHUGBase::ChangeCrosshair()
{
	FGeometry CachedGeometry = Crosshair->GetCachedGeometry();
	FVector2D PixelPosition;
	FVector2D ViewportPosition;
	FVector2D AbsoluteSize = CachedGeometry.GetAbsoluteSize() / 2;
	FVector WorldPosition;
	FVector WorldDirection;
	APlayerController* Controller = GetOwningPlayer();
	TArray<AActor*> Actors = { GetOwningPlayerPawn() };
	const TArray<TEnumAsByte<EObjectTypeQuery>> Objects = { UEngineTypes::ConvertToObjectType(ECC_WorldStatic), UEngineTypes::ConvertToObjectType(ECC_Pawn) };

	USlateBlueprintLibrary::LocalToViewport(GetWorld(), CachedGeometry, FVector2D(0, 0), PixelPosition, ViewportPosition);

	AbsoluteSize += PixelPosition;

	bool result = Controller->DeprojectScreenPositionToWorld(AbsoluteSize.X, AbsoluteSize.Y, WorldPosition, WorldDirection);

	WorldDirection *= 100000.0f;

	FVector EndPos = WorldPosition + WorldDirection;

	FHitResult OutHit;

	if (UKismetSystemLibrary::LineTraceSingleForObjects(GetWorld(), WorldPosition, EndPos, Objects, false, Actors, EDrawDebugTrace::None, OutHit, true))
	{
		EndPoint = OutHit.Location;

		APawn* HitPawn = Cast<APawn>(OutHit.Actor);

		// If the thing we hit was a pawn
		if (nullptr != HitPawn)
		{
			SetColor(DangerColor);
		}
		else
			SetColor(SafeColor);
	}
	else
	{
		EndPoint = WorldDirection;
		SetColor(SafeColor);
	}
}

void UHUGBase::SetColor(FLinearColor newColor)
{
	DynamicMaterial->SetVectorParameterValue(ColorName, newColor);
}