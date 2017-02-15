// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* Tank = GetPlayerTank();
	if (!Tank) {
		UE_LOG(LogTemp, Warning, TEXT("No player tank found"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("A player tank found!"));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) {
		return;
	}
	else {
		return Cast<ATank>(PlayerTank);
	}
}
