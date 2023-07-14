// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "Enums.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EEffects : uint8
{
	EFFECTS_BURNING			UMETA(DisplayName = "Burning"),
	EFFECTS_NUMEFFECT		UMETA(DisplayName = "NumEffects")
};

UCLASS()
class A06_END_API UEnums : public UUserDefinedEnum
{
	GENERATED_BODY()
	
};
