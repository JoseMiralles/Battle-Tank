// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

#include "TankAimingComponent.h"
#include "TankBarrel.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	this->TankAimingComponent
		= CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::AimAt(FVector HitLocation)
{
	this->TankAimingComponent->AimAt(HitLocation, this->LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet, UStaticMeshComponent* TurretToSet)
{
	this->TankAimingComponent->SetComponentReferences(BarrelToSet, TurretToSet);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}