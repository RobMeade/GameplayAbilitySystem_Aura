// Copyright Rob Meade.  All rights reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "AuraUserWidget.generated.h"


UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()


public:

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;


protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();


private:

	
};
