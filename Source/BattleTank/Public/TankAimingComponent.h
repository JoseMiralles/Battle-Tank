// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"

#include "TankAimingComponent.generated.h"

class UTankBarrel;

/// Holds barrel's properties and elevate method.
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Sets references to components of the tank.
	void SetComponentReferences (UTankBarrel* BarrelToSet, UStaticMeshComponent* Turret);

	bool isHighArcFiringEnabled = false; /// TODO: Make BP editable.

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector target, float LaunchSpeed);

private:
	UTankBarrel* Barrel = nullptr;
	UStaticMeshComponent* Turret = nullptr;

	/// Used to recycle tick variables.
	struct AimParams
	{
		FVector LaunchVelocity;
		FVector StartLocation;
		FVector AimDirection;

		FRotator BarrelRotator;
		FRotator AimAsRotator;
		FRotator DeltaRotator;
	};
	AimParams AimP;

	/// Moves the Barrel towards PP.AimDirection.
	void MoveBarrelTowardsAimDirection();
};
