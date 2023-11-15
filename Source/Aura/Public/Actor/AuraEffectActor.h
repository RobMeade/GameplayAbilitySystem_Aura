// Copyright Rob Meade.  All rights reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "ActiveGameplayEffectHandle.h"
#include "CoreMinimal.h"

#include "AbilitySystem/AuraGameplayEffect.h"

#include "AuraEffectActor.generated.h"


// Forward Declarations
class UAbilitySystemComponent;
class UGameplayEffect;


UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()


public:	

	AAuraEffectActor();


protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, FAuraGameplayEffect& Effect);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	bool bDestroyOnEffectRemoval = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TArray<FAuraGameplayEffect> Effects;

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;


private:

};
