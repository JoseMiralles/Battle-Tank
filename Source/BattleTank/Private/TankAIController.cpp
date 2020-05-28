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

	this->TankControlled = Cast<ATank>(GetPawn());
	this->PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
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
		this->TankControlled->FireCannon();
	}
}
