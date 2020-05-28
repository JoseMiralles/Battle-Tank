// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"

#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"

#define OUT

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

// This is called from the Tank_BP event graph.
void UTankAimingComponent::SetComponentReferences
(UTankBarrel* BarrelToSet, UStaticMeshComponent* TurretToSet)
{
	this->Barrel = BarrelToSet;
	this->Turret = TurretToSet;
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector target, float launchSpeed)
{
	if (!this->Barrel) return;

	AimP.LaunchVelocity = FVector(0);
	AimP.StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OUT AimP.LaunchVelocity,
		AimP.StartLocation,
		target,
		launchSpeed,
		isHighArcFiringEnabled,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		AimP.AimDirection = AimP.LaunchVelocity.GetSafeNormal();
		MoveBarrelTowardsAimDirection();
		Barrel->Elevate(5.f);
	}
}

void UTankAimingComponent::MoveBarrelTowardsAimDirection()
{
	/// Start rotation.
	AimP.BarrelRotator = Barrel->GetForwardVector().Rotation();
	/// End/Target rotation.
	AimP.AimAsRotator = AimP.AimDirection.Rotation();
	/// Difference.
	AimP.DeltaRotator = AimP.AimAsRotator - AimP.BarrelRotator;
}

