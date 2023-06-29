// Fill out your copyright notice in the Description page of Project Settings.


#include "Bind/BindVariables.h"
#include "../../A06_END.h"

// Sets default values
ABindVariables::ABindVariables()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABindVariables::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(Game, Error, TEXT("Actor's name is %s"), *GetName());
	UE_LOG(Game, Display, TEXT("int %d float %f"), VisibleInstanceOnlyOdd, EditAnywhere);
	UE_LOG(Game, Warning, TEXT("Actor's velocity is %s"), *GetVelocity().ToString());
}

// Called every frame
void ABindVariables::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

