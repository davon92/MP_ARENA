// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameEventSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDied);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPowerupCollected, FName, PowerupID);

UCLASS()
class MP_ARENA_API UGameEventSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	static UGameEventSubsystem* Get(const UObject* WorldContext);
	
	/** Example: When a player dies */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnPlayerDied OnPlayerDied;

	/** Example: When a power-up is collected */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnPowerupCollected OnPowerupCollected;

	/** Example function to broadcast death */
	UFUNCTION(BlueprintCallable, Category="Events")
	void BroadcastPlayerDied();

	UFUNCTION(BlueprintCallable, Category="Events")
	void BroadcastPowerupCollected(FName PowerupID);
};
