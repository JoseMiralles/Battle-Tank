// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

UTankTurret::UTankTurret(){}

void UTankTurret::Rotate(float relativeSpeed)
{
	TP.RelativeSpeed = FMath::Clamp<float>(relativeSpeed, -1, 1);
	TP.rotationChange = TP.RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	TP.RawNewRotation = this->RelativeRotation.Yaw + TP.rotationChange;

	this->SetRelativeRotation(FRotator(0,TP.RawNewRotation, 0));
}
