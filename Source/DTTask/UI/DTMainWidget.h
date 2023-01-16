// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/Object.h"
#include "DTMainWidget.generated.h"

class UTextBlock;

UCLASS(Abstract)
class DTTASK_API UDTMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	void SetTimeLeft(int32 InSecondsLeft);
	
private:

	UFUNCTION()
	void OnSecondGone();

	void UpdateTimeText();
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TimeText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* HealthCountText;

	FTimerHandle SecondsTimerHandle;
	int32 SecondsLeft = 0;
};
