// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"

ATankAIController::ATankAIController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	this->TankControlled = GetControlledTank();
	this->PlayerTank = GetPlayerControlledTank();

	if (this->TankControlled)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possesed:\t%s"), *TankControlled->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController couldn't posses a Tank!"));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	if (this->PlayerTank)
	{
		/// Move towards the player.

		/// Aim towards the player.
		this->TankControlled->AimAt(
			PlayerTank->GetActorLocation());

		/// Fire if ready.
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerControlledTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
