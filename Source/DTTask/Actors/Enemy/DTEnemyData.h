// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DTEnemyData.generated.h"

UENUM()
enum class EEnemyDirection : uint8 
{
	None = 0,
	Up,
	Right,
	Down,
	Left
};
