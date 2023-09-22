// Copyright Rob Meade.  All rights reserved.

#pragma once

#include "UObject/Interface.h"
#include "CoreMinimal.h"

#include "EnemyInterface.generated.h"


UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

class AURA_API IEnemyInterface
{
	GENERATED_BODY()


public:

	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;

};
