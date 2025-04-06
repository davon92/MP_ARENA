// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpSpawnerSubsystem.h"

#include "FPowerUpEffectData.h"

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
	if (!PowerUpTable) return;

	TArray<FName> RowNames = PowerUpTable->GetRowNames();

	for (const FName& RowName : RowNames)
	{
		const FPowerUpEffectData* Data = PowerUpTable->FindRow<FPowerUpEffectData>(RowName, TEXT("MaybeSpawnPowerUpAt"));
		if (!Data) continue;

		if (FMath::FRand() <= Data->SpawnChance)
		{
			SpawnPowerUpFromRow(RowName, Location);
			break;
		}
	}
}

void UPowerUpSpawnerSubsystem::SpawnPowerUpFromRow(FName RowID, const FVector& Location)
{
	if (!PowerUpTable) return;

	if (const FPowerUpEffectData* Row = PowerUpTable->FindRow<FPowerUpEffectData>(RowID, TEXT("Spawning")))
	{
		if (Row->PowerUpClass)
		{
			FActorSpawnParameters Params;
			Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			GetWorld()->SpawnActor<AActor>(Row->PowerUpClass, Location, FRotator::ZeroRotator, Params);
		}
	}
}