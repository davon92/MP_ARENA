// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MP_ARENAGameMode.generated.h"
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
	
protected:
	int32 Score;
};



