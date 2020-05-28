// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UTankBarrel();
	
	/// Elevates the barrel in the given direction. 1 = up, -1 = down
	void Elevate(float direction);

private:
	/// The speed of elevation for the barrel in degrees per second.
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 10;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = -5.f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 45.f;

	/// Used for recycling purposes.
	struct BarrelParams
	{
		float Time;
		float ElevationChange;
		float RawNewElevation;
		float RelativeSpeed;
	};
	BarrelParams BP;
};
