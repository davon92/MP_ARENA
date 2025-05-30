﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "BlasterPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class MP_ARENA_API ABlasterPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	/** Place Bomb Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PlaceBombAction;

	UPROPERTY(EditDefaultsOnly, Category = "Bombs")
	TSubclassOf<class ABombActor> BombActorClass;

	

public:
	// Sets default values for this character's properties
	ABlasterPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void PlaceBomb(const FInputActionValue& Value);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Gameplay Stats
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay")
	int32 MaxBombs = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay")
	int32 BombRadius = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay")
	float BaseSpeed = 600.f;

	// Setters
	void SetMaxBombs(int32 NewMax) { MaxBombs = NewMax; }
	void SetBombRadius(int32 NewRadius) { BombRadius = NewRadius; }
	void SetMoveSpeed(float Speed);
	
};
