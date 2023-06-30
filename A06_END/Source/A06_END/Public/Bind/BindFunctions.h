// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BindFunctions.generated.h"

UCLASS()
class A06_END_API ABindFunctions : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABindFunctions();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void BlueprintCallable();

	// BlueprintImplementbleEvent allows you to declare the function here and implement it in a blueprint
	// Since you are implementing it in a BP, you cannot also define it in the .cpp file. You will get errors
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void BlueprintImplementableEvent();

	// Native functions automatically declare an additional function with _Implementation appended to the end
	// So you will need to define the _Implememntation function in the .cpp file and not define the 
	// regular function. 
	// BlueprintNativeEvent is a function type that is meant to be overridden, which is why the _Implementation exists.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void BlueprintNativeEvent();
	virtual void BlueprintNativeEvent_Implementation();

	// Pure function
	UFUNCTION(BlueprintCallable)
		bool PureFunction() const;
};
