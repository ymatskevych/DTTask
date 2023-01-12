// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DTCharacter.generated.h"

UCLASS()
class DTTASK_API ADTCharacter : public ACharacter
{
	GENERATED_BODY()
	
protected:
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
private:

	UFUNCTION()
	void OnMoveForward(float InAxisValue);

	UFUNCTION()
	void OnMoveBackward(float InAxisValue);

	UFUNCTION()
	void OnMoveLeft(float InAxisValue);

	UFUNCTION()
	void OnMoveRight(float InAxisValue);

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float fSpeed = 10.f;
};
