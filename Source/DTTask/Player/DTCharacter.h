// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DTCharacter.generated.h"

class ADTBomb;
UCLASS()
class DTTASK_API ADTCharacter : public ACharacter
{
	GENERATED_BODY()
	
protected:
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
private:

	// Movement
	UFUNCTION()
	void OnMoveForward(float InAxisValue);

	UFUNCTION()
	void OnMoveBackward(float InAxisValue);

	UFUNCTION()
	void OnMoveLeft(float InAxisValue);

	UFUNCTION()
	void OnMoveRight(float InAxisValue);
	// *******

	UFUNCTION()
	void OnPlaceBomb();

	UFUNCTION()
	void OnBombDelay();

	UPROPERTY(EditDefaultsOnly)
	float BombDetonationTime = 3.f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float fSpeed = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = "Bomb")
	TSubclassOf<ADTBomb> BombClass;

	FTimerHandle BombPlaceTimerHandle;
	bool bCanPlaceBomb = true;
	float DetonationRate = 1.f;
};
