// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DTPlayerController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDTUpdateScore, int32, InScoreValue);

class UDTMainWidget;

UCLASS()
class DTTASK_API ADTPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	FDTUpdateScore UpdateScore;
	
protected:
	
	virtual void BeginPlay() override;

private:

	UFUNCTION()
	void OnUpdateScore(int32 InScoreValue);
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDTMainWidget> MainWidgetClass;

	UPROPERTY()
	UDTMainWidget* MainWidget;

	UPROPERTY(EditDefaultsOnly)
	int32 LevelTimeInSeconds = 220;

	int32 TotalScore = 0; // TODO: Move to GameState
};
