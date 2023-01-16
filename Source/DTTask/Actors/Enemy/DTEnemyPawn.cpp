// Fill out your copyright notice in the Description page of Project Settings.


#include "DTEnemyPawn.h"

#include "DTTask/Player/DTPlayerController.h"

void ADTEnemyPawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AddMovementInput(Destination);
}

void ADTEnemyPawn::DealDamage()
{
	// TODO: Move UpdateScore into separate subsystem
	const UWorld* World = GetWorld();
	if (!ensureMsgf(IsValid(World), TEXT("[ADTBricks]: World is invalid")))
	{
		return;
	}
	const auto* PlayerController = Cast<ADTPlayerController>(World->GetFirstPlayerController());
	if (!ensureMsgf(IsValid(PlayerController), TEXT("[ADTBricks]: PlayerController is invalid")))
	{
		return;
	}
	PlayerController->UpdateScore.Broadcast(ScoreValue);
	
	Destroy();
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
