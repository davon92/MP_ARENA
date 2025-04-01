// Fill out your copyright notice in the Description page of Project Settings.


#include "DevOverlayWidget.h"
#include "Components/TextBlock.h"
#include "DevToolsSubsystem.h"

void UDevOverlayWidget::NativeConstruct()
{
	Super::NativeConstruct();
	// Optional: Set initial values
	if (Text_GodMode) Text_GodMode->SetText(FText::FromString(TEXT("God Mode: ?")));
	if (Text_GridDebug) Text_GridDebug->SetText(FText::FromString(TEXT("Grid Debug: ?")));
}

void UDevOverlayWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (UDevToolsSubsystem* DevTools = UDevToolsSubsystem::Get(this))
	{
		if (Text_GodMode)
		{
			const FString GodModeStatus = DevTools->bGodMode ? TEXT("ON") : TEXT("OFF");
			Text_GodMode->SetText(FText::FromString(FString::Printf(TEXT("God Mode: %s"), *GodModeStatus)));
		}

		if (DevTools->bShowGridOverlay)
		{
			DevTools->DrawGridDebug(GetWorld());
		}

		if (Text_GridDebug)
		{
			const FString GridStatus = DevTools->bShowGridOverlay ? TEXT("ON") : TEXT("OFF");
			
			Text_GridDebug->SetText(FText::FromString(FString::Printf(TEXT("Grid Debug: %s"), *GridStatus)));
		}

		// Get raw frame delta and calculate instantaneous FPS
		const float InstantFPS = 1.0f / InDeltaTime;

		// Smooth the FPS using a simple lerp for EMA-like smoothing
		SmoothedFPS = FMath::Lerp(SmoothedFPS, InstantFPS, 0.1f); // Tweak 0.1f for faster/slower smoothing

		if (Text_FPS)
		{
			FString FPSText = FString::Printf(TEXT("FPS: %.1f"), SmoothedFPS);
			Text_FPS->SetText(FText::FromString(FPSText));

			FSlateColor TextColor;
			if (SmoothedFPS >= 60.f)
			{
				TextColor = FSlateColor(FLinearColor::Green);
			}
			else if (SmoothedFPS >= 30.f)
			{
				TextColor = FSlateColor(FLinearColor::Yellow);
			}
			else
			{
				TextColor = FSlateColor(FLinearColor::Red);
			}

			Text_FPS->SetColorAndOpacity(TextColor);
		}
	}
}