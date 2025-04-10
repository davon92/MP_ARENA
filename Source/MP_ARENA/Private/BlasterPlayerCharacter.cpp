﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterPlayerCharacter.h"

#include "BombActor.h"
#include "EnhancedInputComponent.h"
#include "GameEventSubsystem.h"
#include "GridManagerSubsystem.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ABlasterPlayerCharacter::ABlasterPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}

// Called when the game starts or when spawned
void ABlasterPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlasterPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABlasterPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABlasterPlayerCharacter::Move);
		EnhancedInput->BindAction(PlaceBombAction, ETriggerEvent::Triggered, this, &ABlasterPlayerCharacter::PlaceBomb);
	}
}

void ABlasterPlayerCharacter::SetMoveSpeed(float Speed)
{
	GetCharacterMovement()->MaxWalkSpeed = BaseSpeed*Speed;
}

void ABlasterPlayerCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D InputVector = Value.Get<FVector2D>();
	if (Controller && InputVector.SizeSquared() > 0.f)
	{
		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);

		const FVector Forward = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector Right = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Forward, InputVector.Y);
		AddMovementInput(Right, InputVector.X);
	}
}

void ABlasterPlayerCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ABlasterPlayerCharacter::PlaceBomb(const FInputActionValue& Value)
{
	if (Controller != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlaceBomb Triggered"));
		if (UGridManagerSubsystem* Grid = UGridManagerSubsystem::Get(this))
		{
			if (BombActorClass)
			{
				FIntPoint Coord = Grid->GetTileIndexFromWorld(GetActorLocation());
				FVector WorldPos = Grid->GetTileWorldLocation(Coord);

				FActorSpawnParameters Params;
				Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

				ABombActor* Bomb = GetWorld()->SpawnActor<ABombActor>(BombActorClass, WorldPos, FRotator::ZeroRotator, Params);
				if (Bomb)
				{
					Bomb->InitBombAt(Coord);
				}
			}
		}
	}
}

