// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

// This is called from the Tank_BP event graph.
void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	this->Barrel_SM = BarrelToSet;
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

void UTankAimingComponent::AimAt(FVector target, float launchSpeed) const
{
	//UE_LOG(LogTemp, Warning, TEXT("%s is targeting:\t%s"), *this->GetName(), *target.ToString());
	UE_LOG(LogTemp, Warning, TEXT("projectile speed:\t%f"), launchSpeed);
}

