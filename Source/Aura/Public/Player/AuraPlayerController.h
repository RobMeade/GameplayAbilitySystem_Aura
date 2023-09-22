// Copyright Rob Meade.  All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "AuraPlayerController.generated.h"


// Forward Declarations
class IEnemyInterface;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;


UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()


public:

	AAuraPlayerController();

	virtual void PlayerTick(float DeltaTime) override;


protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;


private:

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);
	void CursorTrace();

	IEnemyInterface* LastActor = nullptr;
	IEnemyInterface* CurrentActor = nullptr;
};
