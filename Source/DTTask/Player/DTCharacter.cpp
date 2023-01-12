// Fill out your copyright notice in the Description page of Project Settings.


#include "DTCharacter.h"

void ADTCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Forward", this, &ADTCharacter::OnMoveForward);
	InputComponent->BindAxis("Backward", this, &ADTCharacter::OnMoveBackward);
	InputComponent->BindAxis("Left", this, &ADTCharacter::OnMoveLeft);
	InputComponent->BindAxis("Right", this, &ADTCharacter::OnMoveRight);
}

void ADTCharacter::OnMoveForward(float InAxisValue)
{
	AddMovementInput(FVector(1.f, 0.f, 0.f), fSpeed * InAxisValue);
}

void ADTCharacter::OnMoveBackward(float InAxisValue)
{
	AddMovementInput(FVector(-1.f, 0.f, 0.f), fSpeed * InAxisValue);
}

void ADTCharacter::OnMoveLeft(float InAxisValue)
{
	AddMovementInput(FVector(0.f, -1.f, 0.f), fSpeed * InAxisValue);
}

void ADTCharacter::OnMoveRight(float InAxisValue)
{
	AddMovementInput(FVector(0.f, 1.f, 0.f), fSpeed * InAxisValue);
}


