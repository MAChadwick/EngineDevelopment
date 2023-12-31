// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseRifle.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Pawn.h"
#include "../../A06_END.h"
#include "Actors/BaseBullet.h"

// Sets default values
ABaseRifle::ABaseRifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));

	ConstructorHelpers::FObjectFinder<USkeletalMesh>MeshAsset(TEXT("SkeletalMesh'/Game/END_Starter/Guns/Rifle/SK_Rifle.SK_Rifle'"));
	USkeletalMesh* Asset = MeshAsset.Object;

	SkeletalMesh->SetSkeletalMesh(Asset);

	IsDead = false;
}

// Called when the game starts or when spawned
void ABaseRifle::BeginPlay()
{
	Super::BeginPlay();
	
	MaxAmmo = 5;
	CurrentAmmo = MaxAmmo;

	APawn* Pawn = Cast<APawn>(GetParentActor());

	// Get rifle's parent and cast to a pawn
	if (nullptr != Pawn)
	{
		ParentPawn = Pawn;
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
	if (!Animate && !IsDead && CurrentAmmo > 0)
	{
		Animate = true;
		FVector SpawnLocation = GetFirePoint();
		FRotator AimRotation = ParentPawn->GetBaseAimRotation();
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.Owner = ParentPawn->GetController();
		SpawnInfo.Instigator = ParentPawn;

		GetWorld()->SpawnActor<ABaseBullet>(SpawnLocation, AimRotation, SpawnInfo);

		OnShot.Broadcast();

		UseAmmo();
	}
}

void ABaseRifle::AnimationEnded()
{
	Animate = false;
}

void ABaseRifle::OwnerDied()
{
	IsDead = true;
}

FVector ABaseRifle::GetFirePoint()
{
	return SkeletalMesh->GetSocketLocation(FName("MuzzleFlashSocket"));
}


void ABaseRifle::Reload()
{
	CurrentAmmo = MaxAmmo;
	OnAmmoChanged.Broadcast(CurrentAmmo, MaxAmmo);
	AnimationEnded();
}


void ABaseRifle::RequestReload()
{
	if (!Animate)
	{
		Animate = true;
		OnReloadStart.Broadcast();
	}
}

void ABaseRifle::UseAmmo()
{
	CurrentAmmo--;

	CurrentAmmo = FMath::Max(CurrentAmmo, 0.0f);
	
	OnAmmoChanged.Broadcast(CurrentAmmo, MaxAmmo);
}
