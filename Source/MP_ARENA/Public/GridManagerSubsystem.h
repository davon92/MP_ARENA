// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GridManagerSubsystem.generated.h"

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
class MP_ARENA_API UGridManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/** Static accessor for ease of use */
	static UGridManagerSubsystem* Get(const UObject* WorldContext);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Initializes the grid */
	UFUNCTION(BlueprintCallable, Category="Grid")
	void GenerateGrid(int32 Rows, int32 Columns, float TileSize);

	/** Converts world position to tile index */
	UFUNCTION(BlueprintCallable, Category="Grid")
	FIntPoint GetTileIndexFromWorld(const FVector& WorldLocation) const;

	/** Returns tile data */
	const FGridTileData* GetTileData(FIntPoint TileCoord) const;

	/** Set tile occupancy */
	void SetTileOccupied(FIntPoint TileCoord, bool bOccupied);

	const TMap<FIntPoint, FGridTileData>& GetGridMap() const;

	UPROPERTY(EditDefaultsOnly, Category = "Grid")
	TSubclassOf<class ADestructibleTile> DestructibleTileClass;

	UFUNCTION(BlueprintCallable, Category="Grid")
	FVector GetTileWorldLocation(const FIntPoint& Coord) const;

protected:
	TMap<FIntPoint, FGridTileData> GridMap;

	int32 GridRows = 0;
	int32 GridCols = 0;
	float GridTileSize = 100.f;

	FVector GridOrigin = FVector::ZeroVector; // Bottom-left origin
};
