// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PowerUpEffectComponent.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStatsWidget.generated.h"
class UTextBlock;

/**
 * 
 */

UENUM(BlueprintType)
enum class EStatsWidgetOrientation : uint8
{
	TopLeft,
	TopRight,
	BottomLeft,
	BottomRight
};

UCLASS()
class MP_ARENA_API UPlayerStatsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/** Call to set the player data this widget will observe */
	UFUNCTION(BlueprintCallable)
	void BindToPlayer(APawn* Player);
	
	UFUNCTION(BlueprintCallable)
	void SetOrientation(EStatsWidgetOrientation Orientation);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOrientationChanged(EStatsWidgetOrientation NewOrientation);

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* BombCountText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* RadiusText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* SpeedText;

private:
	UPROPERTY()
	UPowerUpEffectComponent* ObservedEffectComponent;
};
