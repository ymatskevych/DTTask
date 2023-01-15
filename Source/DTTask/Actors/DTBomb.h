// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DTBomb.generated.h"

UCLASS(Abstract)
class DTTASK_API ADTBomb : public AActor
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

private:

	void CorrectStartLocation();
	
	UFUNCTION()
	void Detonate();

	void MakeDamage();

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AActor>> DamagableActorClasses;
	
	FTimerHandle DetonateTimerHandle;

	UPROPERTY(EditDefaultsOnly)
	float DetonationTime = 3.f;

	float GridCellSize = 64.f;
	float TraceLenght = 32.f;
	float DetonationRate = 1.f;
};
