// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BombActor.generated.h"

UCLASS()
class MP_ARENA_API ABombActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABombActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* BombMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBombComponent* BombComponent;

	/** Initializes bomb logic (tile location, delay, etc.) */
	void InitBombAt(FIntPoint TileCoord);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
