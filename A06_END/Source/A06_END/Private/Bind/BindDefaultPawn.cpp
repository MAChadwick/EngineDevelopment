// Fill out your copyright notice in the Description page of Project Settings.


#include "Bind/BindDefaultPawn.h"
#include "EngineUtils.h"
#include "Bind/ACtorWithInterfaces.h"
#include "../../A06_END.h"

// Sets default values
ABindDefaultPawn::ABindDefaultPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABindDefaultPawn::BeginPlay()
{
	Super::BeginPlay();
	
	// Basically says "Get All Actors Of Class. Includes actual class and child classes
	for (TActorIterator<AACtorWithInterfaces>itr(GetWorld()); itr; ++itr)
	{
		// We don't want to communicate directly, so we communicate through the interface
		// Example with both methods
		UBindInterfaceInCode* U = Cast<UBindInterfaceInCode>(*itr);

		if (nullptr != U)
		{
			// Function call
			//U->
			UE_LOG(Game, Error, TEXT("In UObject portion of BindDefaultPawn.cpp"));
		}
		IBindInterfaceInCode* I = Cast<IBindInterfaceInCode>(*itr);

		if (nullptr != I)
		{
			// Function call
			I->BlueprintCallable();

			UE_LOG(Game, Error, TEXT("In Interface portion of BindDefaultPawn.cpp"))
		}
	}
}

// Called every frame
void ABindDefaultPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABindDefaultPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

