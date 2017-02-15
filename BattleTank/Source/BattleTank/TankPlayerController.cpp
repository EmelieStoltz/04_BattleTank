// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* Tank = GetControlledTank();
	if (!Tank) {
		UE_LOG(LogTemp, Warning, TEXT("No tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player tank: %s"), *(Tank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}