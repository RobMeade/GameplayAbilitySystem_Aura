// Copyright Rob Meade.  All rights reserved.

#pragma once

#include "GameFramework/HUD.h"
#include "CoreMinimal.h"

#include "AuraHUD.generated.h"


// Forward Declarations
class UAuraUserWidget;


UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()


public:

	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;


protected:

	virtual void BeginPlay() override;


private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

};
