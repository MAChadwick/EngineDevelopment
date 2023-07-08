// Fill out your copyright notice in the Description page of Project Settings.

// You cannot forward declare an interface, so you have to include the interface
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bind/BindInterfaceInCode.h"
#include "ACtorWithInterfaces.generated.h"

UCLASS()
class A06_END_API AACtorWithInterfaces : public AActor, public IBindInterfaceInCode		// Derive the class from this interface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AACtorWithInterfaces();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Coding convention for organizing code
	// Start IBindInterfaceInCode code
	virtual void BlueprintCallable() override;	// If you don't override the pure abstract interface function, it will not compile
	// End IBindInterfaceInCode code
};
