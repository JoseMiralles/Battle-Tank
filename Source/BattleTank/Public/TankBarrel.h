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
	/// Dictates the directions in which the turret should move.
	enum ElevationDirection
	{
		Up = 1,
		Down = -1,
		none = 0
	};

public:
	UTankBarrel();
	
	/// Elevates the barrel in the given direction. 1 = up, -1 = down
	void Elevate(ElevationDirection Direction);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = -15.f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 90.f;

	/// Used for recycling purposes.
	struct BarrelParams
	{
		float Time;
	};
	BarrelParams BP;
};
