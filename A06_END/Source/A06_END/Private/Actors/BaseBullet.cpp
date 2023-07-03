// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseBullet.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../../A06_END.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABaseBullet::ABaseBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));

	// Set parent of static mesh
	SetRootComponent(Collision);

	// Configure Static Mesh
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(Collision);
	Sphere->SetCollisionProfileName(TEXT("NoCollision"));
	Sphere->SetRelativeScale3D(FVector(0.6f, 0.6f, 0.6f));
	Sphere->SetEnableGravity(false);

	ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	UStaticMesh* Asset = MeshAsset.Object;

	Sphere->SetStaticMesh(Asset);

	// Configure collider
	Collision->SetGenerateOverlapEvents(true);
	Collision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	Collision->SetEnableGravity(false);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = 1800.0f;
	ProjectileMovement->MaxSpeed = 2000.0f;
	ProjectileMovement->ProjectileGravityScale = 0.0f;

	// Set Bullet Damage
	Damage = 1.0f;
}

// Called when the game starts or when spawned
void ABaseBullet::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &ABaseBullet::K2_DestroyActor, 3.0f);

	// Setup collision event
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ABaseBullet::HandleHit);
}

// Called every frame
void ABaseBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Function used for handling delegates
void ABaseBullet::HandleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
							UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
	UE_LOG(Game, Warning, TEXT("Hit"));
	UGameplayStatics::ApplyDamage(OtherActor, Damage, this->GetInstigatorController(), this, UDamageType::StaticClass());
	K2_DestroyActor();
}

