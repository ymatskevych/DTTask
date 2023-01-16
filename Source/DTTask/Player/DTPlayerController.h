﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DTPlayerController.generated.h"

class UDTMainWidget;

UCLASS()
class DTTASK_API ADTPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDTMainWidget> MainWidgetClass;

	UPROPERTY(EditDefaultsOnly)
	int32 LevelTimeInSeconds = 220;
};
