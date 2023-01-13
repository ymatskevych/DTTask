// Fill out your copyright notice in the Description page of Project Settings.


#include "DTBomb.h"

void ADTBomb::BeginPlay()
{
	Super::BeginPlay();

	FVector CorrectedLocation = GetActorLocation();
	CorrectedLocation.X = FMath::RoundToFloat(CorrectedLocation.X / 64.f) * 64.f;
	CorrectedLocation.Y = FMath::RoundToFloat(CorrectedLocation.Y / 64.f) * 64.f;

	SetActorLocation(CorrectedLocation);
}
