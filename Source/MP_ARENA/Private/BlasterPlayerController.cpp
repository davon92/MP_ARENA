﻿// Fill out your copyright notice in the Description page of Project Settings.

#include "BlasterPlayerController.h"

#include "DevToolsSubsystem.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
ABlasterPlayerController::ABlasterPlayerController()
{
}

void ABlasterPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
            LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (DefaultMappingContext)
            {
                InputSubsystem->AddMappingContext(DefaultMappingContext, MappingPriority);
            }
        }
    }
}

void ABlasterPlayerController::ToggleAllCheats()
{
    if (UDevToolsSubsystem* DevTools = UDevToolsSubsystem::Get(this))
    {
        DevTools->ToggleAllCheats();
    }
}

void ABlasterPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
    {
        // God Mode Toggle
        if (ToggleGodModeAction)
        {
            EnhancedInput->BindAction(ToggleGodModeAction, ETriggerEvent::Triggered, this, &ABlasterPlayerController::HandleToggleGodMode);
        }

        // Grid Overlay Toggle
        if (ToggleGridDebugAction)
        {
            EnhancedInput->BindAction(ToggleGridDebugAction, ETriggerEvent::Triggered, this, &ABlasterPlayerController::HandleToggleGridDebug);
        }
    }
}