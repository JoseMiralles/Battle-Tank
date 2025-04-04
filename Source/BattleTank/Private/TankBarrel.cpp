// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

UTankBarrel::UTankBarrel()
{}

void UTankBarrel::Elevate(float Direction)
{
	BP.RelativeSpeed = FMath::Clamp<float>(Direction, -1, 1);
	BP.ElevationChange = BP.RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	BP.RawNewElevation = this->RelativeRotation.Pitch + BP.ElevationChange;
	BP.RawNewElevation = FMath::Clamp<float>(BP.RawNewElevation, MinElevation, MaxElevation);

	this->SetRelativeRotation(FRotator(BP.RawNewElevation, 0, 0));
}
