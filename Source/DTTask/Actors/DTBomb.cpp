// Fill out your copyright notice in the Description page of Project Settings.


#include "DTBomb.h"

#include "Kismet/KismetSystemLibrary.h"

void ADTBomb::BeginPlay()
{
	Super::BeginPlay();

	CorrectStartLocation();

	GetWorldTimerManager().SetTimer(DetonateTimerHandle, this, &ADTBomb::Detonate, DetonationRate, false,
		DetonationTime);
}

void ADTBomb::CorrectStartLocation()
{
	FVector CorrectedLocation = GetActorLocation();
	CorrectedLocation.X = FMath::RoundToFloat(CorrectedLocation.X / GridCellSize) * GridCellSize;
	CorrectedLocation.Y = FMath::RoundToFloat(CorrectedLocation.Y / GridCellSize) * GridCellSize;
	CorrectedLocation.Z = TraceLenght;

	SetActorLocation(CorrectedLocation);
}

void ADTBomb::Detonate()
{
	MakeDamage();
	
	Destroy();
	GetWorldTimerManager().ClearTimer(DetonateTimerHandle);
}

void ADTBomb::MakeDamage()
{
	const FVector Start = GetActorLocation();

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);

	TArray<AActor*> OutActors;
	TArray<FHitResult> OutHits;
	UKismetSystemLibrary::SphereTraceMulti(GetWorld(), Start, Start, TraceLenght, TraceTypeQuery1,
		false, ActorsToIgnore, EDrawDebugTrace::ForOneFrame, OutHits, true,
		FLinearColor::Red, FLinearColor::Green, 1.f);

	for (const TSubclassOf<AActor>& DamagableActorClass : DamagableActorClasses)
	{
		for (const FHitResult HitResult : OutHits)
		{
			AActor* HitActor = HitResult.GetActor();
			if (HitActor && HitActor->GetClass() == DamagableActorClass)
			{
				HitActor->Destroy(); // TODO: add interface IDamagable
			}
		}	
	}
}
