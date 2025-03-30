// Fill out your copyright notice in the Description page of Project Settings.


#include "GameEventSubsystem.h"

void UGameEventSubsystem::BroadcastPlayerDied()
{
	OnPlayerDied.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Broadcasting: OnPlayerDied"));
}

void UGameEventSubsystem::BroadcastPowerupCollected(FName PowerupID)
{
	OnPowerupCollected.Broadcast(PowerupID);
}

UGameEventSubsystem* UGameEventSubsystem::Get(const UObject* WorldContext)
{
	if (!WorldContext) return nullptr;

	if (const UGameInstance* GI = WorldContext->GetWorld()->GetGameInstance())
	{
		return GI->GetSubsystem<UGameEventSubsystem>();
	}

	return nullptr;
}