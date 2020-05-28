// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"

#include "TankAIController.generated.h"

/// Foward reference.
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	//Constructor
	ATankAIController();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	ATank* TankControlled; /// Tank controlled by this AI controller.
	ATank* PlayerTank; /// Tank controlled by the player.
};
