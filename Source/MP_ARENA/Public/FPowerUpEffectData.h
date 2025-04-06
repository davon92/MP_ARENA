#pragma once

#include "CoreMinimal.h"
#include "FPowerUpEffectData.generated.h"

UENUM(BlueprintType)
enum class ERarity : uint8
{
	Common		UMETA(DisplayName = "Common"),
	Rare		UMETA(DisplayName = "Rare"),
	Epic		UMETA(DisplayName = "Epic"),
	Legendary	UMETA(DisplayName = "Legendary")
};

UENUM(BlueprintType)
enum class EPowerUpType : uint8
{
	None        UMETA(DisplayName = "None"),
	SpeedBoost  UMETA(DisplayName = "Speed Boost"),
	BombRadius  UMETA(DisplayName = "Bomb Radius"),
	BombCount   UMETA(DisplayName = "Bomb Count")
};

USTRUCT(BlueprintType)
struct FPowerUpEffectData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EPowerUpType EffectType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Value = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SpawnChance = 1.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> PowerUpClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxStacks = 3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName VFXTag;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ERarity Rarity = ERarity::Common;
};