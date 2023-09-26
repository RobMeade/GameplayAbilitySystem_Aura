// Copyright Rob Meade.  All rights reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "CoreMinimal.h"

#include "AuraEffectActor.generated.h"


// Forward Declarations
class USphereComponent;
class UStaticMeshComponent;


UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()


public:	

	AAuraEffectActor();

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


protected:

	virtual void BeginPlay() override;


private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;
};
