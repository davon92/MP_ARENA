// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BlasterPlayerController.generated.h"
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
/**
 * 
 */
UCLASS()
class MP_ARENA_API ABlasterPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	// Sets default values for this character's properties
	ABlasterPlayerController();
protected:
	// Input Mapping to apply to this player's input subsystem
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	// Priority value for applying the context (lower = higher priority)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	int32 MappingPriority = 0;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(Exec)
	void ToggleAllCheats();
	void SetupInputComponent();
	void HandleToggleGodMode();
	void HandleToggleGridDebug();

	UPROPERTY(EditDefaultsOnly, Category="DevTools|Input")
	UInputAction* ToggleGodModeAction;

	UPROPERTY(EditDefaultsOnly, Category="DevTools|Input")
	UInputAction* ToggleGridDebugAction;
};
