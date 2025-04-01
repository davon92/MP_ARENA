// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestructibleTile.generated.h"

UCLASS()
class MP_ARENA_API ADestructibleTile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADestructibleTile();
	
	/** World location of the tile center */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	/** Grid coordinate this tile occupies */
	UPROPERTY(BlueprintReadOnly, Category="Grid")
	FIntPoint TileCoord;

	/** Destroys the tile (can be called from bomb or explosion) */
	UFUNCTION(BlueprintCallable, Category="Tile")
	void Explode();

	/** Optional: Explosion effects */
	void PlayDestructionEffects();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
