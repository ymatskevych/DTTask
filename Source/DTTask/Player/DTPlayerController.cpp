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
	UDTMainWidget* MainWidget = CreateWidget<UDTMainWidget>(this, MainWidgetClass);
	MainWidget->AddToViewport();
}
