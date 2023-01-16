// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DTTask/Interfaces/DTDamagable.h"
#include "DTBricks.generated.h"

UCLASS()
class DTTASK_API ADTBricks : public AActor, public IDTDamagable
{
	GENERATED_BODY()

public:

	virtual void DealDamage() override;

private:

	UPROPERTY(EditDefaultsOnly)
	int32 ScoreValue = 100;
};
