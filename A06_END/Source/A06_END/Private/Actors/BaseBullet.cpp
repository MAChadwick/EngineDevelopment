// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseBullet.h"
#include "Components/SphereComponent.h"
#include "components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementcomponent.h"

// Sets default values
ABaseBullet::ABaseBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->OnComponentHit.AddDynamic(this, &ABaseBullet::HandleHit);

	SetRootComponent(Collision);

	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(Collision);
	Sphere->SetCollisionProfileName(TEXT("NoCollision"));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
}

// Called when the game starts or when spawned
void ABaseBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Function used for handling delegates
void ABaseBullet::HandleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
							UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

}

