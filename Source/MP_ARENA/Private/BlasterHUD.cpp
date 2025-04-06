// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterHUD.h"

#include "Blueprint/UserWidget.h"

void ABlasterHUD::BeginPlay()
{
	Super::BeginPlay();

	DevOverlayWidget = CreateWidget<UDevOverlayWidget>(GetWorld(), DevOverlayClass);
	if (DevOverlayWidget)
	{
		DevOverlayWidget->AddToViewport();
	}

	PlayerStatsWidget = CreateWidget<UPlayerStatsWidget>(GetWorld(), PlayerStatsWidgetClass);
	if (PlayerStatsWidget)
	{
		PlayerStatsWidget->AddToViewport();
		PlayerStatsWidget->BindToPlayer(GetOwningPawn());
	}
}
