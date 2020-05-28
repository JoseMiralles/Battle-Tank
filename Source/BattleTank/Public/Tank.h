// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshSocket.h"
#include "GameFramework/Pawn.h"

#include "Tank.generated.h" /// Put new includes above this one.

/// Forward declaration.
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/// Aims the tank at the location of the FHitResult provided.
	void AimAt(FVector HitLocation);

	/// Passes a reference of the Barrel SM to the tank's TankAimingComponent.
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet); // Should be called from the Tank_BP event graph.

	/// Fires the main cannon at launch speed.
	UFUNCTION(BlueprintCallable)
	void FireCannon();

	/// Used to aim the tank.
	UTankAimingComponent* TankAimingComponent = nullptr;


private:
	/// Launch speed of the projectile.
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000;

	/// The BP to spawn as a projectile when firing.
	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	/// reference to the tank barrel for firing.
	UTankBarrel* Barrel = nullptr;

	/// For recycling purposes.
	struct FiringParams
	{
		FTransform STransform;
		const UStaticMeshSocket* FSocket;
	};
	FiringParams FP;
};