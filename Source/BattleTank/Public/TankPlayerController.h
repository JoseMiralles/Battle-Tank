// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h"

/// Forward Declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATankPlayerController();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	/// Gets a reference to the ATank instance being controlled by this controller.
	ATank* GetControlledTank() const;

private:
	/// Tank Pawn being controlled.
	ATank* ControlledTank;

		/// Actor Hit Calculation
	/// Tells the tank to rotate the turret and barrel so that shots get aligned to the crosshair.
	void AimTowardsCrossHair();
	/// Gets the location of where the cursor is.
	bool GetSightRayHitLocation
	(FVector& OutHitLocation, FVector& OutCameraWorldLocation, FHitResult& OutObjectHit) const;
	/// The location of where the ray hits.
	FVector RayHitLocation;
	/// The location of the camera. Declared for recycling purposes.
	FVector CameraWorldLocation;
	/// The object being hit by the ray.
	FHitResult objectHit;
	/// The total range of the ray trace in meters. Make it longer if the map is much bigger.
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;

		///Crosshair Location is calculated and stored on BeginPlay();
	/// X-Location of Crosshair as a percentage of the screen, from left to right.
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 50.f;
	/// Y-Location of Crosshair as a percentage of the screen, from top to bottom.
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 33.33333f;
	/// Calculate Crosshair screen location
	void CalculateCrossHairScreenLocation(FVector2D& OutScreenLocation) const;
	/// Stores the location of the Crosshair in pixels as a 2D vector.
	FVector2D CrosshairScreenLocation;
};
