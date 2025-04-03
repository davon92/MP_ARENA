// Fill out your copyright notice in the Description page of Project Settings.


#include "BombComponent.h"

#include "BombActor.h"
#include "DestructibleTile.h"
#include "GridManagerSubsystem.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UBombComponent::UBombComponent(): CachedTileCoord()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBombComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBombComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBombComponent::StartCountdown(FIntPoint TileCoord)
{
	CachedTileCoord = TileCoord;

	GetWorld()->GetTimerManager().SetTimer(ExplosionTimerHandle, this, &UBombComponent::TriggerExplosion, 2.0f, false);
}

void UBombComponent::TriggerExplosion()
{
	ExplodeAtTile(CachedTileCoord);

	if (AActor* Owner = GetOwner())
	{
		if (ABombActor* Bomb = Cast<ABombActor>(Owner))
		{
			if (Bomb->ExplosionSound)
			{
				UGameplayStatics::PlaySoundAtLocation(Bomb, Bomb->ExplosionSound, Bomb->GetActorLocation());
			}

			if (Bomb->ExplosionVFX)
			{
				GetWorld()->SpawnActor<AActor>(Bomb->ExplosionVFX,
					Bomb->GetActorLocation(),
					FRotator::ZeroRotator);
			}
		}

		Owner->Destroy();
	}
}

TArray<FIntPoint> UBombComponent::GetExplosionTiles(FIntPoint Center)
{
	TArray<FIntPoint> OutTiles;

	const int32 Radius = 3; // Customize this later

	// Always include center
	OutTiles.Add(Center);

	// Add cardinal directions
	for (int32 Offset = 1; Offset <= Radius; ++Offset)
	{
		OutTiles.Add(Center + FIntPoint(Offset, 0));  // Right
		OutTiles.Add(Center + FIntPoint(-Offset, 0)); // Left
		OutTiles.Add(Center + FIntPoint(0, Offset));  // Up
		OutTiles.Add(Center + FIntPoint(0, -Offset)); // Down
	}

	return OutTiles;
}

void UBombComponent::ExplodeAtTile(const FIntPoint& CenterTile)
{
	UWorld* World = GetWorld();
	if (!World) return;

	UGridManagerSubsystem* Grid = UGridManagerSubsystem::Get(this);
	if (!Grid) return;

	const TArray<FIntPoint> ExplosionTiles = GetExplosionTiles(CenterTile);

	for (const FIntPoint& Coord : ExplosionTiles)
	{
		// Optional: Spawn visual FX at this tile
		if (const FGridTileData* TileData = Grid->GetTileData(Coord))
		{
			FVector Location = TileData->WorldLocation;

			TArray<FHitResult> HitResults;

			if (World->SweepMultiByChannel(
					HitResults,
					Location, Location,
					FQuat::Identity,
					ECC_WorldDynamic,
					FCollisionShape::MakeSphere(50.f)))
			{
				for (const FHitResult& Hit : HitResults)
				{
					if (AActor* HitActor = Hit.GetActor())
					{
						// Example: destructible tile
						if (ADestructibleTile* Tile = Cast<ADestructibleTile>(HitActor))
						{
							Tile->Explode();
						}
					}
				}
			}
		}
	}
}

