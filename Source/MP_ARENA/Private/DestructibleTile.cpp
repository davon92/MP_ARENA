// Fill out your copyright notice in the Description page of Project Settings.


#include "DestructibleTile.h"

#include "GridManagerSubsystem.h"
#include "PowerUpSpawnerSubsystem.h"

// Sets default values
ADestructibleTile::ADestructibleTile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void ADestructibleTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestructibleTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADestructibleTile::Explode()
{
	PlayDestructionEffects();

	// Notify grid to mark this tile as unoccupied
	if (UGridManagerSubsystem* Grid = UGridManagerSubsystem::Get(this))
	{
		Grid->SetTileOccupied(TileCoord, false);
	}

	if (UPowerUpSpawnerSubsystem* PowerUpSpawner = UPowerUpSpawnerSubsystem::Get(this))
	{
		PowerUpSpawner->MaybeSpawnPowerUpAt(GetActorLocation());
	}
	// Destroy self
	Destroy();
}

void ADestructibleTile::PlayDestructionEffects()
{
	// TODO: Add VFX, SFX, particles, camera shake etc
	UE_LOG(LogTemp, Warning, TEXT("Tile at (%d, %d) destroyed!"), TileCoord.X, TileCoord.Y);
}

