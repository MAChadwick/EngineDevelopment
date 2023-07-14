// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter.h"
#include "Components/ChildActorComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Actors/BaseRifle.h"
#include "Core/IronSightsEventGraph.h"
#include "GameFramework/PlayerController.h"
#include "Components/HealthComponent.h"
#include "../../A06_END.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WeaponChildActorComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("WeaponChildActorComponent"));

	USkeletalMeshComponent* SkeleMesh = GetMesh();

	// Gets the mesh of the the character and sets the location relative to the parent class (World in this case)
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));

	Health = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
	Effect = CreateDefaultSubobject<UEffectComponent>(TEXT("Effect"));

	WeaponChildActorComponent->SetupAttachment(SkeleMesh);
	Effect->SetupAttachment(SkeleMesh);
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();	

	SetupCharacter();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABaseCharacter::CharacterAttack() 
{
	CurrentWeapon->Attack();
}

void ABaseCharacter::SetupCharacter()
{
	// Get the skeleton mesh from pawn
	USkeletalMeshComponent* SkeleMesh = GetMesh();

	// Set the child actor class
	WeaponChildActorComponent->SetChildActorClass(ABaseRifle::StaticClass());
	WeaponChildActorComponent->AttachToComponent(SkeleMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("WeaponPlacement"));

	// Cast to BaseRifle
	AActor* ChildActor = WeaponChildActorComponent->GetChildActor();
	ABaseRifle* Weapon = Cast<ABaseRifle>(ChildActor);

	// Check if cast was successful
	if (nullptr != ChildActor)
	{
		CurrentWeapon = Weapon;

		UAnimInstance* AnimInstance = SkeleMesh->GetAnimInstance();

		Animation = Cast<UIronSightsEventGraph>(AnimInstance);

		// Check if cast was successful
		if (nullptr != Animation)
		{
			// Bind Play Animation function to OnShot from weapon
			CurrentWeapon->OnShot.AddDynamic(Animation, &UIronSightsEventGraph::PlayAttackAnim);
			Animation->OnAttackAnimationEnded.AddDynamic(CurrentWeapon, &ABaseRifle::AnimationEnded);

			Health->OnDamage.AddDynamic(Animation, &UIronSightsEventGraph::PlayHurtAnim);
			Health->OnDeath.AddDynamic(this, &ABaseCharacter::CharacterDeath);
		}
		else
			UE_LOG(Game, Error, TEXT("Could not cast to UIronSightsAnimation | BaseCharacter, BeginPlay()"));
	}
	else
		UE_LOG(Game, Error, TEXT("Could not cast to ABaseRifle | BaseCharacter, BeginPlay()"));
}

void ABaseCharacter::CharacterDeath(float Percent)
{
	CurrentWeapon->OwnerDied();

	Animation->PlayDeathAnim(0);

	GetController()->StopMovement();
}

bool ABaseCharacter::CanPickupHealth()
{
	return false;
}

bool ABaseCharacter::ShouldPickupHealth()
{
	return false;
}