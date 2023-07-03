// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter.h"
#include "Components/ChildActorComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Actors/BaseRifle.h"
#include "Core/IronSightsEventGraph.h"
#include "../../A06_END.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Gets the mesh of the the character and sets the location relative to the parent class (World in this case)
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));

	WeaponChildActorComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("WeaponChildActorComponent"));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();	

	// Get the skeleton mesh from pawn
	USkeletalMeshComponent* SkeleMesh = GetMesh();

	// Set the child actor class
	WeaponChildActorComponent->SetChildActorClass(ABaseRifle::StaticClass());
	WeaponChildActorComponent->AttachTo(SkeleMesh, FName("WeaponPlacement"));

	// Cast to BaseRifle
	AActor* ChildActor = WeaponChildActorComponent->GetChildActor();
	ABaseRifle* Weapon = Cast<ABaseRifle>(ChildActor);

	// Check if cast was successful
	if (nullptr != ChildActor)
	{
		CurrentWeapon = Weapon;

		UAnimInstance* AnimInstance = SkeleMesh->GetAnimInstance();

		UIronSightsEventGraph* Animation = Cast<UIronSightsEventGraph>(AnimInstance);

		// Check if cast was successful
		if (nullptr != Animation)
		{
			// Bind Play Animation function to OnShot from weapon
			CurrentWeapon->OnShot.AddDynamic(Animation, &UIronSightsEventGraph::PlayAttackAnim);
			Animation->OnAnimationEnded.AddDynamic(CurrentWeapon, &ABaseRifle::AnimationEnded);
		}
		else
			UE_LOG(Game, Error, TEXT("Could not cast to UIronSightsAnimation | BaseCharacter, BeginPlay()"));
	}
	else
		UE_LOG(Game, Error, TEXT("Could not cast to ABaseRifle | BaseCharacter, BeginPlay()"));
	
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

