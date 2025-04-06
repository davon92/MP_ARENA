// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpEffectComponent.h"
#include "GameEventSubsystem.h"
#include "BlasterPlayerCharacter.h"
#include "FPowerUpEffectData.h"


// Sets default values for this component's properties
UPowerUpEffectComponent::UPowerUpEffectComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPowerUpEffectComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<ABlasterPlayerCharacter>(GetOwner());
	if (!OwnerCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("PowerUpEffectComponent: Could not cast owner to ABlasterPlayerCharacter"));
	}
	// ...
	
}


// Called every frame
void UPowerUpEffectComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPowerUpEffectComponent::ApplyEffect(const FPowerUpEffectData& Data)
{
	int32* CurrentStack = CurrentStacks.Find(Data.EffectType);
	int32 NewStack = (CurrentStack ? *CurrentStack : 0) + 1;

	if (NewStack > Data.MaxStacks)
	{
		NewStack = Data.MaxStacks;
	}

	CurrentStacks.Add(Data.EffectType, NewStack); // Set the new value
	
	// Apply gameplay effect
	switch (Data.EffectType)
	{
	case EPowerUpType::SpeedBoost:
		OwnerCharacter->SetMoveSpeed(Data.Value * NewStack);
		break;

	case EPowerUpType::BombRadius:
		OwnerCharacter->SetBombRadius(NewStack);
		break;

	case EPowerUpType::BombCount:
		OwnerCharacter->SetMaxBombs(NewStack);
		break;

	default:
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("Applied effect %s (Stacks: %d)"),
		*UEnum::GetValueAsString(Data.EffectType),
		NewStack);
	
}

void UPowerUpEffectComponent::ApplyEffectByRow(FName RowID)
{
	if (FPowerUpEffectData* Row = PowerUpTable->FindRow<FPowerUpEffectData>(RowID, TEXT("PowerUpLookup")))
	{
		ApplyEffect(*Row); // Now you apply the whole effect
	}
}

int32 UPowerUpEffectComponent::GetStackFor(EPowerUpType Type) const
{
	const int32* Found = CurrentStacks.Find(Type);
	return Found ? *Found : 0;
}

