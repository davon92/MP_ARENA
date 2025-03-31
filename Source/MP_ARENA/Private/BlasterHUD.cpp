// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterHUD.h"

#include "Blueprint/UserWidget.h"

void ABlasterHUD::BeginPlay()
{
	Super::BeginPlay();

	if (WBP_DevOverlayClass)
	{
		UUserWidget* DevOverlay = CreateWidget<UUserWidget>(GetWorld(), WBP_DevOverlayClass);
		if (DevOverlay)
		{
			DevOverlay->AddToViewport();
		}
	}
}
