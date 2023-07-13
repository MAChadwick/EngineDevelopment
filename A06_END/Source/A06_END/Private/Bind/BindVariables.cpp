// Fill out your copyright notice in the Description page of Project Settings.


#include "Bind/BindVariables.h"
#include "../../A06_END.h"
#include "GameFramework/Character.h"
#include "Blueprint/UserWidget.h"
#include "HUGBase.h"

// Sets default values
ABindVariables::ABindVariables()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Add to an array
	ValueArray.Add(3);

	// Set enum value to something
	EnumValue = EBindEnum::BIND_EARTH;
}

// Called when the game starts or when spawned
void ABindVariables::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(Game, Error, TEXT("Actor's name is %s"), *GetName());
	UE_LOG(Game, Display, TEXT("int %d float %f"), VisibleInstanceOnlyOdd, EditAnywhere);
	UE_LOG(Game, Warning, TEXT("Actor's velocity is %s"), *GetVelocity().ToString());
	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle, this, &ABindVariables::K2_DestroyActor, 2.0f);

	OnTest.AddDynamic(this, &ABindVariables::HandleTest);

	// Dont do this. Passing in the static class will not let it bind
	//UUserWidget *test = CreateWidget<UUserWidget>(nullptr, UHUGBase::StaticClass())
}

// Called every frame
void ABindVariables::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABindVariables::K2_DestroyActor()
{
	// Call for delegate
	OnTest.Broadcast(this);
	FActorSpawnParameters params;
	params.Owner = this;
	params.Instigator = nullptr;

	AActor *Actor = GetWorld()->SpawnActor<AActor>(ClassType, FVector(0, 0, 500.0f), FRotator(), params);

	if (nullptr == Actor) 
	{
		UE_LOG(Game, Error, TEXT("Nothing"));
	}

	// Casting to different classes
	ACharacter* Char = Cast<ACharacter>(Actor);

	if (nullptr == Char)
	{
		UE_LOG(Game, Error, TEXT("Cast Failed"));
	}

	Super::K2_DestroyActor();
}

void ABindVariables::HandleTest(AActor* Object)
{
	UE_LOG(Game, Warning, TEXT("In HandleTest"));
}

