// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DevToolsSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MP_ARENA_API UDevToolsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category= "DevTools")
	void ToggleGridDebug();
	
	UFUNCTION(BlueprintCallable,Category= "DevTools")
	void ToggleGodMode();

	UFUNCTION(Exec)
	void ToggleAllCheats();
	

	UFUNCTION(BlueprintCallable, Category = "DevTools")
	void ToggleTileIndices();

	UFUNCTION(Exec)
	void DrawGridDebug(const UWorld* World);

	UPROPERTY(BlueprintReadOnly, Category = "DevTools")
	bool bShowGridOverlay = false;

	UPROPERTY(BlueprintReadOnly, Category = "DevTools")
	bool bGodMode = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "DevTools")
	bool bShowTileIndices = false;

	static UDevToolsSubsystem* Get(const UObject* WorldContext);
};
