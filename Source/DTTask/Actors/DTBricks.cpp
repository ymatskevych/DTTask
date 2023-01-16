// Fill out your copyright notice in the Description page of Project Settings.


#include "DTBricks.h"

#include "DTTask/Player/DTPlayerController.h"

void ADTBricks::DealDamage()
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
