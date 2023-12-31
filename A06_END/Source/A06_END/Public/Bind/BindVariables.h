// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"


#include "BindVariables.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateVariable, AActor*, Object);

// Allows it to be used in a blueprint
UENUM(BlueprintType)
enum class EBindEnum : uint8
{
	BIND_EARTH		UMETA(DisplayName = "Earth"),
	BIND_WIND		UMETA(DisplayName = "WIND"),
	BIND_FIRE		UMETA(DisplayName = "FIRE")
};

UCLASS()
class A06_END_API ABindVariables : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABindVariables();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Readable anywhere (Instance, BP, defaults, etc) type boolean
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Variable|ReadOnly")
		bool VisibleAnywhere;

	// Readable only in class defaults and in BP type byte
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Variable|ReadOnly")
		uint8 VisibleDefaultsOnlyOdd;

	// Readable ONLY in class defaults Type int64
	UPROPERTY(VisibleDefaultsOnly, Category = "Variable|ReadOnly")
		int64 VisibleDefaultsOnly;

	// Readable Only in instance and BP Type int32
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Variable|ReadOnly")
		int32 VisibleInstanceOnlyOdd;

	// Readable ONLY in Instance 
	UPROPERTY(VisibleInstanceOnly, Category = "Variable|ReadOnly")
		int32 VisibleInstanceOnly;

	// Read Write	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|ReadWrite")
		float EditAnywhere;
	
	// Read write in defaults only Type Name
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Variable|ReadWrite")
		FName EditDefaultsOnlyOdd;

	// Read write in defaults only, read in BP only. Type: string
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Variable|ReadWrite")
		FString EditDefaultsOnly;

	// Read write in instance only, read in BP only. Type: Text
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Variable|ReadWrite")
		FText EditInstanceOnlyOdd;

	// Read write in instance only, read in BP only. Type: string
	UPROPERTY(EditInstanceOnly, Category = "Variable|ReadWrite")
		FVector EditInstanceOnly;

	void K2_DestroyActor() override;

	// Class reference
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|Class Ref")
		TSubclassOf<class ACharacter>ClassType;

	// Delegate. Must have both options for it to work right.
	// Regular Delegate: One person can bind to it
	// Multicast delegate: Many things can bind to it
	// Dynamic delegate: A blueprint can bind to it
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Variable | Dispatcher")
		FDelegateVariable OnTest;
	
	// Function for the delegate
	UFUNCTION()
		void HandleTest(AActor* Object);

	// Array
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable | Array")
		TArray<int32> ValueArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable | Array")
		TArray<UObject*> ObjectArray;
	
	// Enum
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|Enum")
		EBindEnum EnumValue;
};
