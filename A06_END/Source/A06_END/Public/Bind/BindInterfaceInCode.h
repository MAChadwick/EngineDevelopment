// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BindInterfaceInCode.generated.h"

// This class does not need to be modified.
// Blueprint subsection
// "U" represents "UObject", AKA, the garbage collector
// If you mispell a meta command, it just won't work and will not throw an error
UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UBindInterfaceInCode : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
// Code subsection
// "I" represents "Interface"
class A06_END_API IBindInterfaceInCode
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	// Using BlueprintCallable either requires that you include meta = CannotImplmentInterfaceInBlueprint in the above class
	// Or you make it able to be implemented in code using the "UObject" subsection
public:
	UFUNCTION(BlueprintCallable)
		virtual void BlueprintCallable() = 0; // Initalize to 0 for a pure virtual function
};
