﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "DTCameraActor.generated.h"

UCLASS()
class DTTASK_API ADTCameraActor : public ACameraActor
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
};
