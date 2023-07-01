// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUGBase.generated.h"

/**
 * 
 */
UCLASS()
class A06_END_API UHUGBase : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	class UPRogressBar* HealthBar;
};
