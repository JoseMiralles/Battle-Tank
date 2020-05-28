// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
    UTankTurret();

    /// Rotates the turret in the given speed and direction. -1 left, 1 right
    void Rotate(float relativeSpeed);

private:
    /// The speed of rotation of the turret in degrees per second.
    UPROPERTY(EditAnywhere, Category = Setup)
        float MaxDegreesPerSecond = 20;

    /// Used for recycling purposes.
    struct TurretParams
    {
        float Time;
        float rotationChange;
        float RawNewRotation;
        float RelativeSpeed;
    };
    TurretParams TP;
};
