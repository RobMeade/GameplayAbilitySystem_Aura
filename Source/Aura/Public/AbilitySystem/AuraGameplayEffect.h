// Copyright Rob Meade.  All rights reserved.

#pragma once

#include "AbilitySystem/AuraGameplayEffectPolicies.h"
#include "GameplayEffect.h"

#include "AuraGameplayEffect.generated.h"


// Forward Declarations
class UGameplayEffect;


USTRUCT(BlueprintType)
struct AURA_API FAuraGameplayEffect
{
	GENERATED_BODY()


public:

	FAuraGameplayEffect();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
	EGameplayEffectDurationType DurationPolicy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
	TSubclassOf<UGameplayEffect> GameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects");
	EEffectApplicationPolicy ApplicationPolicy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects");
	EEffectRemovalPolicy RemovalPolicy;

	UPROPERTY()
	TArray<FActiveGameplayEffectHandle> RemovableEffectHandles;
};
