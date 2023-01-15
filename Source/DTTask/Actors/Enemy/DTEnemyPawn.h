// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DTEnemyData.h"
#include "DTEnemyPawn.generated.h"

UCLASS()
class DTTASK_API ADTEnemyPawn : public APawn
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaSeconds) override;
	
protected:

	virtual void BeginPlay() override;	
	
private:

	UFUNCTION()
	void OnEnemyPawnWallHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
		const FHitResult& Hit);

	void InitializeProperties();
	
	void RotatePawn();

	UPROPERTY(EditDefaultsOnly, Category = "Overridables")
	float Speed = 0.3f;

	UPROPERTY(EditAnywhere, Category = "Overridables")
	EEnemyDirection Direction = EEnemyDirection::None;
	
	FVector Destination = FVector(1.f, 0.f, 0.f);

	bool bIsEvenRotation = false;
};
