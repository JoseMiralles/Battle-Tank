// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"

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
(UStaticMeshComponent* BarrelToSet, UStaticMeshComponent* Turret)
{
	this->Barrel = BarrelToSet;
	this->Turret = Turret;
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
	}
}

void UTankAimingComponent::MoveBarrelTowardsAimDirection()
{

}

