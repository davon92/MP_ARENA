#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStatsOverlayWidget.generated.h"

class UPlayerStatsWidget;
class UCanvasPanel;

UCLASS()
class MP_ARENA_API UPlayerStatsOverlayWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void InitializeForPlayers(const TArray<APawn*>& PlayerPawns);

protected:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* RootCanvas;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UPlayerStatsWidget> PlayerStatsWidgetClass;

	// Optionally store references
	UPROPERTY()
	TArray<UPlayerStatsWidget*> ActiveWidgets;
};
