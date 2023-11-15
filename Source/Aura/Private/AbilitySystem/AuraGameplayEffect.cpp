// Copyright Rob Meade.  All rights reserved.

#include "AbilitySystem/AuraGameplayEffect.h"


FAuraGameplayEffect::FAuraGameplayEffect()
{
	DurationPolicy = EGameplayEffectDurationType::Instant;
	GameplayEffectClass = nullptr;
	ApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	RemovalPolicy = EEffectRemovalPolicy::DoNotRemove;
}
