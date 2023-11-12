// Copyright Rob Meade.  All rights reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "CoreMinimal.h"

#include "AuraEffectActor.generated.h"


// Forward Declarations
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
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;


private:


};
