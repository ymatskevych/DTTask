// Fill out your copyright notice in the Description page of Project Settings.


#include "DTCameraActor.h"

#include "Kismet/GameplayStatics.h"

void ADTCameraActor::BeginPlay()
{
	Super::BeginPlay();

	const UWorld* World = GetWorld();
	if (!ensureMsgf(IsValid(World), TEXT("[ADTCameraActor]: World is invalid")))
	{
		return;
	}
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(World, 0);
	if (!ensureMsgf(IsValid(PlayerController), TEXT("[ADTCameraActor]: PlayerController is invalid")))
	{
		return;
	}
	PlayerController->SetViewTarget(this);
}
