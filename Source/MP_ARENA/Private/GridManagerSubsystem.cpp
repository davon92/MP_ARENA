// Fill out your copyright notice in the Description page of Project Settings.


#include "GridManagerSubsystem.h"

#include "DestructibleTile.h"
#include "Engine/World.h"

UGridManagerSubsystem* UGridManagerSubsystem::Get(const UObject* WorldContext)
{
	if (!WorldContext) return nullptr;
	if (const UGameInstance* GI = WorldContext->GetWorld()->GetGameInstance())
	{
		return GI->GetSubsystem<UGridManagerSubsystem>();
	}
	return nullptr;
}

void UGridManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	// Optional: Auto-generate a default grid here for testing
}

void UGridManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();
	GridMap.Empty();
}

void UGridManagerSubsystem::GenerateGrid(int32 Rows, int32 Columns, float TileSize)
{
	GridRows = Rows;
	GridCols = Columns;
	GridTileSize = TileSize;
	GridMap.Empty();

	UWorld* World = GetWorld();
	if (!World || !DestructibleTileClass) return;

	const FVector Start = GridOrigin;

	for (int32 Row = 0; Row < Rows; ++Row)
	{
		for (int32 Col = 0; Col < Columns; ++Col)
		{
			FIntPoint Coord(Col, Row);
			FVector Location = GridOrigin + FVector(Col * TileSize, Row * TileSize, 0.f);


			// Store grid data
			FGridTileData TileData;
			TileData.WorldLocation = Location;
			TileData.bOccupied = true; // Will be occupied by tile
			TileData.bDestructible = true;

			GridMap.Add(Coord, TileData);

			// Spawn the tile
			FActorSpawnParameters Params;
			Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			ADestructibleTile* Tile = World->SpawnActor<ADestructibleTile>(DestructibleTileClass, Location, FRotator::ZeroRotator, Params);

			if (Tile)
			{
				Tile->TileCoord = Coord;
			}
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Grid with destructible tiles generated."));
}

FIntPoint UGridManagerSubsystem::GetTileIndexFromWorld(const FVector& WorldLocation) const
{
	const int32 X = FMath::RoundToInt((WorldLocation.X - GridOrigin.X) / GridTileSize);
	const int32 Y = FMath::RoundToInt((WorldLocation.Y - GridOrigin.Y) / GridTileSize);
	return FIntPoint(X, Y);
}

FVector UGridManagerSubsystem::GetTileWorldLocation(const FIntPoint& Coord) const
{
	if (const FGridTileData* Tile = GridMap.Find(Coord))
	{
		return Tile->WorldLocation;
	}

	// Fallback: calculate manually if needed
	return GridOrigin + FVector(Coord.X * GridTileSize, Coord.Y * GridTileSize, 0.f);
}

const FGridTileData* UGridManagerSubsystem::GetTileData(FIntPoint TileCoord) const
{
	return GridMap.Find(TileCoord);
}

void UGridManagerSubsystem::SetTileOccupied(FIntPoint TileCoord, bool bOccupied)
{
	if (FGridTileData* Tile = GridMap.Find(TileCoord))
	{
		Tile->bOccupied = bOccupied;
	}
}

const TMap<FIntPoint, FGridTileData>& UGridManagerSubsystem::GetGridMap() const
{
	return GridMap;
}
