// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatsWidget.h"
#include "Components/TextBlock.h"
#include "PowerUpEffectComponent.h"
#include "BlasterPlayerCharacter.h"

void UPlayerStatsWidget::BindToPlayer(APawn* Player)
{
	if (Player)
	{
		ObservedEffectComponent = Player->FindComponentByClass<UPowerUpEffectComponent>();
	}
}

void UPlayerStatsWidget::SetOrientation(EStatsWidgetOrientation Orientation)
{
}

void UPlayerStatsWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!ObservedEffectComponent) return;

	const int32 Bombs = ObservedEffectComponent->GetStackFor(EPowerUpType::BombCount);
	const int32 Radius = ObservedEffectComponent->GetStackFor(EPowerUpType::BombRadius);
	const int32 SpeedStacks = ObservedEffectComponent->GetStackFor(EPowerUpType::SpeedBoost);
	const float Speed = 600.f + SpeedStacks * 100.f; // Example scaling

	if (BombCountText) BombCountText->SetText(FText::AsNumber(Bombs));
	if (RadiusText) RadiusText->SetText(FText::AsNumber(Radius));
	if (SpeedText) SpeedText->SetText(FText::AsNumber(FMath::RoundToInt(Speed)));
}
