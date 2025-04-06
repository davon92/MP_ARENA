// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DevOverlayWidget.h"
#include "PlayerStatsWidget.h"
#include "GameFramework/HUD.h"
#include "BlasterHUD.generated.h"

/**
 * 
 */
UCLASS()
class MP_ARENA_API ABlasterHUD : public AHUD
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly,Category = "HUD")
	TSubclassOf<UDevOverlayWidget> DevOverlayClass;

	UPROPERTY()
	UDevOverlayWidget* DevOverlayWidget;

	UPROPERTY(EditDefaultsOnly,Category = "HUD")
	TSubclassOf<UPlayerStatsWidget> PlayerStatsWidgetClass;

	UPROPERTY()
	UPlayerStatsWidget* PlayerStatsWidget;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
