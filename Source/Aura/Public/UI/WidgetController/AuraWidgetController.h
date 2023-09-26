// Copyright Rob Meade.  All rights reserved.

#pragma once

#include "UObject/NoExportTypes.h"
#include "CoreMinimal.h"

#include "AuraWidgetController.generated.h"


// Forward Declarations
class UAbilitySystemComponent;
class UAttributeSet;


UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()


public:


protected:

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;


private:


};
