// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter_Player.h"
#include "GameFramework/SpringArmcomponent.h"
#include "Camera/CameraComponent.h"
#include "HUGBase.h"
#include <Kismet/KismetMathLibrary.h>
#include "Actors/BaseRifle.h"
#include "../../A06_END.h"

ABaseCharacter_Player::ABaseCharacter_Player() {
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->TargetArmLength = 300.0f;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	SpringArmComponent->SetRelativeLocation(FVector(0.0f, 80.f, 90.f));
}

void ABaseCharacter_Player::BeginPlay()
{
	Super::BeginPlay();

	SetupHud();

	CurrentWeapon->OnAmmoChanged.AddDynamic(HudWidget, &UHUGBase::SetAmmo);

	CurrentWeapon->Reload();
}

void ABaseCharacter_Player::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Call parent class' functions using Super:: namespace
	// You don't have to call the parent's function if you don't need it
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("LookLeftRight"), this, &ABaseCharacter_Player::AddControllerYawInput);
	PlayerInputComponent->BindAxis(FName("LookUpDown"), this, &ABaseCharacter_Player::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(FName("MoveForwardBackward"), this, &ABaseCharacter_Player::MoveForwardBackward);
	PlayerInputComponent->BindAxis(FName("MoveLeftRight"), this, &ABaseCharacter_Player::MoveLeftRight);
	PlayerInputComponent->BindAction(FName("StandardAttack"), EInputEvent::IE_Pressed, this, &ABaseCharacter::CharacterAttack);
	PlayerInputComponent->BindAction(FName("Reload"), EInputEvent::IE_Pressed, this, &ABaseCharacter::WeaponReload);
}

void ABaseCharacter_Player::MoveForwardBackward(float AxisValue)
{
	FRotator MakeRotator(0.0f, GetControlRotation().Yaw, 0.0f);
	AddMovementInput(UKismetMathLibrary::GetForwardVector(MakeRotator), AxisValue);
}

void ABaseCharacter_Player::MoveLeftRight(float AxisValue)
{
	FRotator MakeRotator(0.0f, GetControlRotation().Yaw, 0.0f);
	AddMovementInput(UKismetMathLibrary::GetRightVector(MakeRotator), AxisValue);
}

void ABaseCharacter_Player::SetupHud()
{
	APlayerController* playerController = Cast<APlayerController>(GetController());

	if (nullptr != playerController)
	{
		HudWidget->SetOwningPlayer(playerController);
		HudWidget->AddToViewport();

		Health->OnDamage.AddDynamic(HudWidget, &UHUGBase::SetPlayerHealth);
		Health->OnDeath.AddDynamic(HudWidget, &UHUGBase::SetPlayerHealth);
		Health->OnHeal.AddDynamic(HudWidget, &UHUGBase::SetPlayerHealth);
	}
	else
		UE_LOG(Game, Error, TEXT("Could not cast to APlayer Controller | BaseChaaracter.cpp, SetupHud"));

}
void ABaseCharacter_Player::CharacterDeath(float Percent)
{
	Super::CharacterDeath(0);

	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	if (nullptr != PlayerController) DisableInput(PlayerController);

	SetActorEnableCollision(false);

	HudWidget->RemoveFromParent();
}

bool ABaseCharacter_Player::CanPickupHealth()
{
	return true;
}

bool ABaseCharacter_Player::ShouldPickupHealth()
{
	return !(Health->IsFullHealth());
}

FRotator ABaseCharacter_Player::GetBaseAimRotation() const
{
	return UKismetMathLibrary::MakeRotFromX(HudWidget->GetEndPoint() - CurrentWeapon->GetFirePoint());
}