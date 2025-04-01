// Fill out your copyright notice in the Description page of Project Settings.

#include "BombActor.h"

#include "BombComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABombActor::ABombActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	BombMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BombMesh"));
	BombMesh->SetupAttachment(Root);

	BombComponent = CreateDefaultSubobject<UBombComponent>(TEXT("BombComponent"));
}

void ABombActor::InitBombAt(FIntPoint TileCoord)
{
	if (BombComponent)
	{
		BombComponent->StartCountdown(TileCoord);
	}
}

// Called when the game starts or when spawned
void ABombActor::BeginPlay()
{
	Super::BeginPlay();
	if (BombDropSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, BombDropSound, GetActorLocation());
	}
}

// Called every frame
void ABombActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

