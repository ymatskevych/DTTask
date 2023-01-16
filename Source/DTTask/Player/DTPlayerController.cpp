// Fill out your copyright notice in the Description page of Project Settings.


#include "DTPlayerController.h"

#include "DTTask/UI/DTMainWidget.h"

void ADTPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!ensureMsgf(IsValid(MainWidgetClass), TEXT("[ADTPlayerController]: MainWidgetClass is not assigned")))
	{
		return;
	}
	MainWidget = CreateWidget<UDTMainWidget>(this, MainWidgetClass);
	MainWidget->SetTimeLeft(LevelTimeInSeconds);
	MainWidget->AddToViewport();

	UpdateScore.AddDynamic(this, &ADTPlayerController::OnUpdateScore);
}

void ADTPlayerController::OnUpdateScore(int32 InScoreValue)
{
	TotalScore += InScoreValue;
	MainWidget->UpdateScore(TotalScore);
}
