// Copyright Epic Games, Inc. All Rights Reserved.

#include "MP_ARENAGameMode.h"
#include "MP_ARENACharacter.h"
#include "CollectibleActor.h"
#include "Kismet/GameplayStatics.h"
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

void AMP_ARENAGameMode::StartPlay()
{
	Super::StartPlay();

	TArray<AActor*> Collectibles;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACollectibleActor::StaticClass(), Collectibles);

	for (AActor* Actor : Collectibles)
	{
		if (ACollectibleActor* Collectible = Cast<ACollectibleActor>(Actor))
		{
			Collectible->OnPlatformTriggered.AddDynamic(this,&AMP_ARENAGameMode::ScorePoint);;
		}
	}
}

void AMP_ARENAGameMode::ScorePoint()
{
	Score++;
	UE_LOG(LogTemp, Warning, TEXT("Player Has Scored A Point"));
}
