// Copyright Rob Meade.  All rights reserved.

#include "UI/HUD/AuraHUD.h"

#include "Blueprint/UserWidget.h"

#include "UI/Widget/AuraUserWidget.h"


void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
