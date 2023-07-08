// Fill out your copyright notice in the Description page of Project Settings.


#include "Bind/ACtorWithInterfaces.h"
#include "../../A06_END.h"

// Sets default values
AACtorWithInterfaces::AACtorWithInterfaces()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AACtorWithInterfaces::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AACtorWithInterfaces::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AACtorWithInterfaces::BlueprintCallable()
{
	UE_LOG(Game, Warning, TEXT("Inside Blueprint Callable in ActorWithInterfaces.cpp"))
}

