#include "PlayerStatsOverlayWidget.h"
#include "PlayerStatsWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

void UPlayerStatsOverlayWidget::InitializeForPlayers(const TArray<APawn*>& PlayerPawns)
{
	if (!PlayerStatsWidgetClass || !RootCanvas) return;

	const TArray<FVector2D> CornerPositions = {
		{ 20, 20 },          // Top Left
		{ 1600, 20 },        // Top Right
		{ 20, 800 },         // Bottom Left
		{ 1600, 800 }        // Bottom Right
	};

	for (int32 i = 0; i < PlayerPawns.Num() && i < CornerPositions.Num(); ++i)
	{
		UPlayerStatsWidget* Widget = CreateWidget<UPlayerStatsWidget>(GetWorld(), PlayerStatsWidgetClass);
		if (!Widget) continue;

		Widget->BindToPlayer(PlayerPawns[i]);
		UCanvasPanelSlot* CanvasSlot  = RootCanvas->AddChildToCanvas(Widget);
		if (CanvasSlot )
		{
			CanvasSlot ->SetAutoSize(true);
			CanvasSlot ->SetPosition(CornerPositions[i]);
		}

		ActiveWidgets.Add(Widget);
	}
}
