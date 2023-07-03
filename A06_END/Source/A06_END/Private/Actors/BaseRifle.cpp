// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseRifle.h"
#include "Engine/SkeletalMesh.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Pawn.h"
#include "../../A06_END.h"
#include "Actors/BaseBullet.h"

// Sets default values
ABaseRifle::ABaseRifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));

	ConstructorHelpers::FObjectFinder<USkeletalMesh>MeshAsset(TEXT("SkeletalMesh'/Game/END_Starter/Guns/Rifle/SK_Rifle.SK_Rifle'"));
	USkeletalMesh* Asset = MeshAsset.Object;

	SkeletalMesh->SetSkeletalMesh(Asset);
}

// Called when the game starts or when spawned
void ABaseRifle::BeginPlay()
{
	Super::BeginPlay();
	
	APawn* Pawn = Cast<APawn>(GetParentActor());

	// Get rifle's parent and cast to a pawn
	if (nullptr != Pawn)
	{
		ParentPawn = Pawn;
		UE_LOG(Game, Warning, TEXT("Set ParentPawn"));
	}
	else
	{
		UE_LOG(Game, Error, TEXT("Could not cast to pawn | BaseRifle, BeginPlay(), %s"), GetParentActor());
	}
}

// Called every frame
void ABaseRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseRifle::Attack()
{
	if (!Animate)
	{
		Animate = true;
		FVector SpawnLocation = SkeletalMesh->GetSocketLocation(FName("MuzzleFlashSocket"));
		FRotator AimRotation = ParentPawn->GetBaseAimRotation();
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.Owner = ParentPawn->GetController();
		SpawnInfo.Instigator = ParentPawn;

		GetWorld()->SpawnActor<ABaseBullet>(SpawnLocation, AimRotation, SpawnInfo);

		OnShot.Broadcast();
	}
}

void ABaseRifle::AnimationEnded()
{
	UE_LOG(Game, Warning, TEXT("Animation Ended *** NEEDS TO BE FIXED ***"));
	Animate = false;
}