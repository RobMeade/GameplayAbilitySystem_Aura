// Copyright Rob Meade.  All rights reserved.

#include "Actor/AuraEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

#include "AbilitySystem/AuraGameplayEffectPolicies.h"


AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, FAuraGameplayEffect& Effect)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) { return; }

	check(Effect.GameplayEffectClass);

	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(Effect.GameplayEffectClass, 1.f, EffectContextHandle);
	const FActiveGameplayEffectHandle ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	if (Effect.DurationPolicy == EGameplayEffectDurationType::Infinite && Effect.RemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		Effect.RemovableEffectHandles.Add(ActiveEffectHandle);		
	}
}

void AAuraEffectActor::OnOverlap(AActor* TargetActor)
{
	for (FAuraGameplayEffect& Effect : Effects)
	{
		if (Effect.ApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
		{
			ApplyEffectToTarget(TargetActor, Effect);
		}
	}
}

void AAuraEffectActor::OnEndOverlap(AActor* TargetActor)
{
	for (FAuraGameplayEffect& Effect : Effects)
	{
		if (Effect.ApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
		{
			ApplyEffectToTarget(TargetActor, Effect);
		}

		if (Effect.DurationPolicy == EGameplayEffectDurationType::Infinite && Effect.RemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
		{
			UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
			if (TargetASC == nullptr) { return; }

			for (int32 HandleIndex = Effect.RemovableEffectHandles.Num() - 1; HandleIndex >= 0; --HandleIndex)
			{
				if (Effect.RemovableEffectHandles[HandleIndex].GetOwningAbilitySystemComponent() == TargetASC)
				{
					TargetASC->RemoveActiveGameplayEffect(Effect.RemovableEffectHandles[HandleIndex], 1);
					Effect.RemovableEffectHandles.RemoveAt(HandleIndex);
				}
			}
		}
	}
}
