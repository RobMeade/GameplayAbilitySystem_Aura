// Copyright Rob Meade.  All rights reserved.

#include "UI/WidgetController/AuraWidgetController.h"


void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams)
{
	PlayerController = WidgetControllerParams.PlayerController;
	PlayerState = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystemComponent;
	AttributeSet = WidgetControllerParams.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValues()
{
	// Note: Deliberately left empty for base class, derived classes will override it
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
	// Note: Deliberately left empty for base class, derived classes will override it
}
