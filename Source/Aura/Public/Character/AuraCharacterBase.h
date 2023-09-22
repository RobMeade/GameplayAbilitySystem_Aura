// Copyright Rob Meade.  All rights reserved.

#pragma once

#include "GameFramework/Character.h"
#include "CoreMinimal.h"

#include "AuraCharacterBase.generated.h"


UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()


public:

	AAuraCharacterBase();


protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;


private:


};
