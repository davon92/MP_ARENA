// Copyright Epic Games, Inc. All Rights Reserved.

#include "MP_ARENAGameMode.h"
#include "MP_ARENACharacter.h"
#include "UObject/ConstructorHelpers.h"

AMP_ARENAGameMode::AMP_ARENAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
