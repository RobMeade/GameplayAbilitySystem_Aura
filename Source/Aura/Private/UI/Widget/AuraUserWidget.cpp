// Copyright Rob Meade.  All rights reserved.

#include "UI/Widget/AuraUserWidget.h"


void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
