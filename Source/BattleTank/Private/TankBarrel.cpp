// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

UTankBarrel::UTankBarrel()
{}

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("Elevating by:\t%f"), DegreesPerSecond);
}
