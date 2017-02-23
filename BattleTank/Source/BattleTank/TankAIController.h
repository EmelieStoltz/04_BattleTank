// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaTime) override;
	
private:

	virtual void BeginPlay() override;

	//How close can the AI tank get to the player
	float AcceptanceRadius = 3000;

	UTankAimingComponent* AimingComponent = nullptr;
};
