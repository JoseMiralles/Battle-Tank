// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->ProjectileMovement
		= CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	this->ProjectileMovement->bAutoActivate = false; //Prevent it from moving until it is fired.
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile(const float& speed)
{
	this->ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * speed);
	this->ProjectileMovement->Activate();
}

