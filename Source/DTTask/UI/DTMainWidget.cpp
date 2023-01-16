// Fill out your copyright notice in the Description page of Project Settings.


#include "DTMainWidget.h"

#include "Components/TextBlock.h"

void UDTMainWidget::SetTimeLeft(int32 InSecondsLeft)
{
	const UWorld* World = GetWorld();
	if (!ensureMsgf(IsValid(World), TEXT("[UDTMainWidget]: World is invalid")))
	{
		return;
	}
	
	World->GetTimerManager().SetTimer(SecondsTimerHandle, this, &UDTMainWidget::OnSecondGone, 1.f,
		true, 0.f);

	SecondsLeft = InSecondsLeft;
}

void UDTMainWidget::UpdateScore(int32 InScoreValue)
{
	ScoreText->SetText(FText::FromString(FString::Printf(TEXT("SCORE: %d"), InScoreValue)));
}

void UDTMainWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UpdateScore(0);
}

void UDTMainWidget::OnSecondGone()
{
	if (SecondsLeft <= 0)
	{
		const UWorld* World = GetWorld();
		if (!ensureMsgf(IsValid(World), TEXT("[UDTMainWidget]: World is invalid")))
		{
			return;
		}
	
		World->GetTimerManager().ClearTimer(SecondsTimerHandle);
	}
	
	SecondsLeft--;
	UpdateTimeText();
}

void UDTMainWidget::UpdateTimeText()
{
	const int32 MinutesLeft = SecondsLeft / 60;
	const int32 SecondsAfterMinutes = SecondsLeft - MinutesLeft * 60;
	TimeText->SetText(FText::FromString(FString::Printf(TEXT("TIME: %d:%d"), MinutesLeft, SecondsAfterMinutes)));
}
