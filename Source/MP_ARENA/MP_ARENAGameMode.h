// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MP_ARENAGameMode.generated.h"
class ADestructibleTile;
class UGridManagerSubsystem;
class ACollectibleActor;
UCLASS(minimalapi)
class AMP_ARENAGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMP_ARENAGameMode();
	virtual void StartPlay() override;
	
	UFUNCTION()
	virtual void ScorePoint();

	UFUNCTION(BlueprintCallable, Category="Subsystems")
	UGridManagerSubsystem* GetGridManager() const;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Grid")
    TSubclassOf<ADestructibleTile> DestructibleTileClass;
	
protected:
	int32 Score;
};



