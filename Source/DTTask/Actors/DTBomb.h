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
};
