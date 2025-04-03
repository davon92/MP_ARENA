// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PowerUpSpawnerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MP_ARENA_API UPowerUpSpawnerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	static UPowerUpSpawnerSubsystem* Get(const UObject* WorldContext);

	/** Called when a destructible tile is destroyed */
	void MaybeSpawnPowerUpAt(const FVector& Location);

	/** Types of power-ups to randomly choose from */
	UPROPERTY(EditDefaultsOnly, Category = "PowerUps")
	TArray<TSubclassOf<AActor>> PowerUpClasses;

	/** Spawn chance between 0 and 1 (e.g., 0.25 = 25%) */
	UPROPERTY(EditDefaultsOnly, Category = "PowerUps")
	float PowerUpSpawnChance = 0.25f;
};
