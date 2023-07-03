// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter_Player.h"
#include "GameFramework/SpringArmcomponent.h"
#include "Camera/CameraComponent.h"
#include <Kismet/KismetMathLibrary.h>

ABaseCharacter_Player::ABaseCharacter_Player() {
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camer"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	SpringArmComponent->SetRelativeLocation(FVector(0.0f, 80.f, 90.f));
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