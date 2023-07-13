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
	
private:
	void SetColor(FLinearColor newColor);
	void ChangeCrosshair();
	


protected:
	virtual void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UMaterialInstanceDynamic* DynamicMaterial;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FName ColorName = "Color";

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor DangerColor = FLinearColor(0.7f, 0, 0, 1);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FLinearColor SafeColor = FLinearColor(0.25f, 0.75f, 0.75f, 1);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector EndPoint;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
		class UProgressBar* HealthBar;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* Crosshair;

public:
	UHUGBase(const FObjectInitializer& ObjectInitializer);
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;
	bool Initialize() override;

	UFUNCTION(BlueprintCallable)
		void SetPlayerHealth(float percent);

	UFUNCTION(BlueprintCallable)
		FVector GetEndPoint();
};
