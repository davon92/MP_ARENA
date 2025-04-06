// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPowerUpEffectData.h"
#include "Components/ActorComponent.h"
#include "PowerUpEffectComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MP_ARENA_API UPowerUpEffectComponent : public UActorComponent
{
	GENERATED_BODY()
	

public:
	// Sets default values for this component's properties
	UPowerUpEffectComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* PowerUpTable;

	UPROPERTY()
	TMap<EPowerUpType, int32> CurrentStacks;

	UPROPERTY()
	class ABlasterPlayerCharacter* OwnerCharacter;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	void ApplyEffect(const FPowerUpEffectData& Data);
	void ApplyEffectByRow(FName RowID);
	int32 GetStackFor(EPowerUpType Type) const;
};
