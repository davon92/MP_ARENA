// Fill out your copyright notice in the Description page of Project Settings.


#include "DevToolsSubsystem.h"

#include "GridManagerSubsystem.h"
#include "Engine/Engine.h"

void UDevToolsSubsystem::ToggleGridDebug()
{
	bShowGridOverlay = !bShowGridOverlay;
	if (bShowGridOverlay)
	{
		if (UGridManagerSubsystem* Grid = UGridManagerSubsystem::Get(this))
		{
			if (Grid->GetGridMap().Num() == 0)
			{
				Grid->GenerateGrid(10, 10, 100.f); // Size = 10x10, each tile = 100 units
				UE_LOG(LogTemp, Warning, TEXT("Grid generated from DevTools toggle"));
			}
		}
	}

	UE_LOG(LogTemp,Warning,TEXT("Grid Debug Overlay: %s"), bShowGridOverlay? TEXT("ON"): TEXT("OFF"));
}

void UDevToolsSubsystem::ToggleGodMode()
{
	bGodMode=!bGodMode;
	UE_LOG(LogTemp,Warning,TEXT("God Mode: %s"), bGodMode? TEXT("ENABLED") : TEXT("DISABLED"));
}

void UDevToolsSubsystem::ToggleTileIndices()
{
	bShowTileIndices = !bShowTileIndices;
	UE_LOG(LogTemp, Warning, TEXT("Tile Index Overlay: %s"), bShowTileIndices ? TEXT("ON") : TEXT("OFF"));
}

void UDevToolsSubsystem::ToggleAllCheats()
{
	ToggleGridDebug();
	ToggleGodMode();
	ToggleTileIndices();
}

UDevToolsSubsystem* UDevToolsSubsystem::Get(const UObject* WorldContext)
{
	if (!WorldContext) return nullptr;
	if (const UGameInstance* GI = WorldContext->GetWorld()->GetGameInstance())
	{
		return GI->GetSubsystem<UDevToolsSubsystem>();
	}
	return nullptr;
}

void UDevToolsSubsystem::DrawGridDebug(const UWorld* World)
{
	if (!bShowGridOverlay || !World) return;

	if (UGridManagerSubsystem* Grid = UGridManagerSubsystem::Get(this))
	{
		for (const TPair<FIntPoint, FGridTileData>& Pair : Grid->GetGridMap())
		{
			const FIntPoint& Coord = Pair.Key;
			const FGridTileData& Tile = Pair.Value;
			const FVector& Location = Tile.WorldLocation;

			FColor BoxColor = Tile.bOccupied ? FColor::Red : FColor::Green;

			if (Tile.bOccupied)
			{
				BoxColor = FColor::Red;
			}
			else if (Tile.bDestructible)
			{
				BoxColor = FColor::Yellow;
			}
			// Future: else if (Tile.bIndestructible) BoxColor = FColor::Gray;
			
			DrawDebugBox(World, Location, FVector(50.f, 50.f, 10.f), BoxColor, false, -1.f, 0, 2.f);

			if (bShowTileIndices)
			{
				const FString Label = FString::Printf(TEXT("(%d,%d)"), Coord.X, Coord.Y);
				DrawDebugString(World, Location + FVector(0, 0, 60), Label, nullptr, FColor::White, 0.f, true);
			}
		}
	}
}

