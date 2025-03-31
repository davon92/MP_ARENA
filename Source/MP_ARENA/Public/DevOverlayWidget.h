// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DevOverlayWidget.generated.h"
class UTextBlock;
/**
 * 
 */
UCLASS()
class MP_ARENA_API UDevOverlayWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* Text_GodMode;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* Text_GridDebug;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* Text_FPS;

    float SmoothedFPS = 0.f;
};
