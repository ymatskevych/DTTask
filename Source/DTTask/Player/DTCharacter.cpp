// Fill out your copyright notice in the Description page of Project Settings.


#include "DTCharacter.h"

#include "DTTask/Actors/DTBomb.h"

void ADTCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Forward", this, &ADTCharacter::OnMoveForward);
	InputComponent->BindAxis("Backward", this, &ADTCharacter::OnMoveBackward);
	InputComponent->BindAxis("Left", this, &ADTCharacter::OnMoveLeft);
	InputComponent->BindAxis("Right", this, &ADTCharacter::OnMoveRight);

	InputComponent->BindAction("PlaceBomb", IE_Pressed, this, &ADTCharacter::OnPlaceBomb);
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

void ADTCharacter::OnPlaceBomb()
{
	if (!bCanPlaceBomb)
	{
		return;
	}
	if (!ensureMsgf(IsValid(BombClass), TEXT("[ADTCharacter]: BombClass is not assigned")))
	{
		return;
	}
	
	FActorSpawnParameters ActorSpawnParameters;
	ActorSpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	ADTBomb* Bomb = GetWorld()->SpawnActor<ADTBomb>(BombClass, GetActorLocation(),
		FRotator::ZeroRotator, ActorSpawnParameters);
	Bomb->SetUp(BombDetonationTime);

	GetWorldTimerManager().SetTimer(BombPlaceTimerHandle, this, &ADTCharacter::OnBombDelay, DetonationRate,
		false, BombDetonationTime);
	bCanPlaceBomb = false;
}

void ADTCharacter::OnBombDelay()
{
	GetWorldTimerManager().ClearTimer(BombPlaceTimerHandle);
	bCanPlaceBomb = true;
}


