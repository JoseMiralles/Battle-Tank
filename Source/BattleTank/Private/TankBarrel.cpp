// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

UTankBarrel::UTankBarrel()
{}

void UTankBarrel::Elevate(ElevationDirection Direction)
{
	BP.Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("Elevating by:\t%f"), BP.Time);
}
