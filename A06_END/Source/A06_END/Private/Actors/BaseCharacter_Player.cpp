// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter_Player.h"
#include "GameFramework/SpringArmcomponent.h"

ABaseCharacter_Player::ABaseCharacter_Player() {
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;
}

void ABaseCharacter_Player::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Call parent class' functions using Super:: namespace
	// You don't have to call the parent's function if you don't need it
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("LookLeftRight"), this, &ABaseCharacter_Player::AddControllerYawInput);
	PlayerInputComponent->BindAxis(FName("MoveForwardBackward"), this, &ABaseCharacter_Player::MoveForwardBackward);
}

void ABaseCharacter_Player::MoveForwardBackward(float AxisValue)
{
	FRotator MakeRotator(0.0f, GetControlRotation().Yaw, 0.0f);
	AddMovementInput(MakeRotator.Vector(), AxisValue);
}