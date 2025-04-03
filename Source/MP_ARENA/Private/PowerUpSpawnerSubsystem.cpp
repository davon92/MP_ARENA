// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpSpawnerSubsystem.h"

UPowerUpSpawnerSubsystem* UPowerUpSpawnerSubsystem::Get(const UObject* WorldContext)
{
	if (const UGameInstance* GI = WorldContext->GetWorld()->GetGameInstance())
	{
		return GI->GetSubsystem<UPowerUpSpawnerSubsystem>();
	}
	return nullptr;
}

void UPowerUpSpawnerSubsystem::MaybeSpawnPowerUpAt(const FVector& Location)
{
	if (PowerUpClasses.Num() == 0 || FMath::FRand() > PowerUpSpawnChance)
		return;

	int32 Index = FMath::RandRange(0, PowerUpClasses.Num() - 1);
	TSubclassOf<AActor> ChosenClass = PowerUpClasses[Index];

	GetWorld()->SpawnActor<AActor>(ChosenClass, Location, FRotator::ZeroRotator);
}