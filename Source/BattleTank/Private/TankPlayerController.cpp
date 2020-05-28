// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"

#define OUT

ATankPlayerController::ATankPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	/// Get a reference to controlled tank at the start of the game.
	this->ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController.cpp:\t NO TANK POSSESED!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesed:\t%s"), *ControlledTank->GetName());
	}

	/* Calculate the location of the crosshair on the screen.
	** This is later used to ray trace on the Tick() method.*/
	CalculateCrossHairScreenLocation(OUT this->CrosshairScreenLocation);
	UE_LOG(LogTemp, Warning, TEXT("Crosshair Location:\t%fpx * %fpx"),
		this->CrosshairScreenLocation.X, this->CrosshairScreenLocation.Y);
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/// Calculate the location of where we are aiming, and tell the tank to aim there.
	AimTowardsCrossHair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!this->ControlledTank) return;

	/// Trace a line trought the crosshair, and get the object at that location.
	if (GetSightRayHitLocation(OUT this->RayHitLocation, OUT this->CameraWorldLocation, OUT this->objectHit))
	{
		/// Tell the tank toa im at that object.
		this->ControlledTank->AimAt(this->objectHit.Location);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation, FVector& OutCameraWorldLocation, FHitResult& OutObjectHit) const
{
	/// De-project the the screen position of the crosshair to a world direction.
	if ( this->DeprojectScreenPositionToWorld(
			CrosshairScreenLocation.X,
			CrosshairScreenLocation.Y,
			OUT OutCameraWorldLocation,
			OUT OutHitLocation) )
	{
		/// Raytrace to HitLocation, and see what is hit.
		return GetWorld()->LineTraceSingleByChannel(
			OUT OutObjectHit,
			this->CameraWorldLocation,
			CameraWorldLocation + (OutHitLocation * this->LineTraceRange),
			ECollisionChannel::ECC_Visibility);
	}
	return false;
}

void ATankPlayerController::CalculateCrossHairScreenLocation(FVector2D& OutScreenLocation) const
{
	// Find Crosshair position.
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(OUT ViewPortSizeX, OUT ViewPortSizeY);
	ViewPortSizeX = ViewPortSizeX * (this->CrossHairXLocation / 100);
	ViewPortSizeY = ViewPortSizeY * (this->CrossHairYLocation / 100);
	
	OutScreenLocation = FVector2D(ViewPortSizeX, ViewPortSizeY);
}
