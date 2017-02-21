// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* Tank = GetPlayerTank();
	if (!Tank) {
		UE_LOG(LogTemp, Warning, TEXT("No player tank found"));
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("A player tank found! %s"), *(Tank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		// TODO move towards the player

		//Aim at player
		ATank* PlayerTank = GetPlayerTank();
		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());

		// fire if ready
	}
	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) {return nullptr;}
	else {
		return Cast<ATank>(PlayerTank);
	}
}
