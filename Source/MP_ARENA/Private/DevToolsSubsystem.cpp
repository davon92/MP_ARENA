// Fill out your copyright notice in the Description page of Project Settings.


#include "DevToolsSubsystem.h"
#include "Engine/Engine.h"

void UDevToolsSubsystem::ToggleGridDebug()
{
	bShowGridOverlay = !bShowGridOverlay;
	UE_LOG(LogTemp,Warning,TEXT("Grid Debug Overlay: %s"), bShowGridOverlay? TEXT("ON"): TEXT("OFF"));
}

void UDevToolsSubsystem::ToggleGodMode()
{
	bGodMode=!bGodMode;
	UE_LOG(LogTemp,Warning,TEXT("God Mode: %s"), bGodMode? TEXT("ENABLED") : TEXT("DISABLED"));
}

void UDevToolsSubsystem::ToggleAllCheats()
{
	ToggleGridDebug();
	ToggleGodMode();
}

UDevToolsSubsystem* UDevToolsSubsystem::Get(const UObject* WorldContext)
{
	if (!WorldContext) return nullptr;
	if (const UGameInstance* GI = WorldContext->GetWorld()->GetGameInstance())
	{
		return GI->GetSubsystem<UDevToolsSubsystem>();
	}
	return nullptr;
}
