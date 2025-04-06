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
	void SpawnPowerUpFromRow(FName RowID, const FVector& Location);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* PowerUpTable;
};
