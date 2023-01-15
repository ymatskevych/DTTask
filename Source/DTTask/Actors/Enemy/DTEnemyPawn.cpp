// Fill out your copyright notice in the Description page of Project Settings.


#include "DTEnemyPawn.h"

void ADTEnemyPawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AddMovementInput(Destination);
}

void ADTEnemyPawn::BeginPlay()
{
	Super::BeginPlay();

	InitializeProperties();
	
	OnActorHit.AddDynamic(this, &ADTEnemyPawn::OnEnemyPawnWallHit);
}

void ADTEnemyPawn::OnEnemyPawnWallHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
	const FHitResult& Hit)
{
	RotatePawn();
}

void ADTEnemyPawn::InitializeProperties()
{
	if (Direction == EEnemyDirection::None)
	{
		ensureMsgf(false, TEXT("[ADTEnemyPawn]: Direction of an enemy has not been selected"));
		return;
	}
	
	switch (Direction)
	{
	case EEnemyDirection::Up:
		{
			Destination = FVector::XAxisVector;
			break;
		}
	case EEnemyDirection::Right:
		{
			Destination = FVector::RightVector;
			break;
		}
	case EEnemyDirection::Down:
		{
			Destination = FVector::YAxisVector;
			break;
		}
	case EEnemyDirection::Left:
		{
			Destination = FVector::LeftVector;
			break;
		}
	default: return;
	}
	Destination *= Speed;
}

void ADTEnemyPawn::RotatePawn()
{
	Destination *= -1.f;
}
