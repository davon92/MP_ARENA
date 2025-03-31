// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UGridManagerSubsystem.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FGridTileData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector WorldLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bOccupied = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDestructible = false;
};

UCLASS()
class MP_ARENA_API UUGridManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

protected:
	void GetTileFromWorldLocation();

	void GetTileOccupant(FIntPoint);

	void MarkTileOccupied();
};
