// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUGBase.generated.h"

// I accidentally misnamed this class and I haven't bothered to go back and fix it
// Its a little too late now to be honest
/**
 * 
 */
UCLASS()
class A06_END_API UHUGBase : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
		class UProgressBar* HealthBar;

public:
	UHUGBase(const FObjectInitializer& ObjectInitializer);
	bool Initialize() override;

	UFUNCTION()
		void SetPlayerHealth(float percent);
};
