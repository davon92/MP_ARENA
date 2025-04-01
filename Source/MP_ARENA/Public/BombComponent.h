// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BombComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MP_ARENA_API UBombComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBombComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	/** The tile this bomb was placed on */
	FIntPoint CachedTileCoord;
	/** Timer handle for delayed explosion */
	FTimerHandle ExplosionTimerHandle;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,FActorComponentTickFunction* ThisTickFunction) override;
	void StartCountdown(FIntPoint TileCoord);
	void TriggerExplosion();
	void ExplodeAtTile(const FIntPoint& CenterTile);
	TArray<FIntPoint>GetExplosionTiles(FIntPoint Center);
	
};
