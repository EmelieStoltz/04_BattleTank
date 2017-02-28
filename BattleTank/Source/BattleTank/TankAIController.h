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

protected:
	//How close can the AI tank get to the player
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000;
	
private:

	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	UTankAimingComponent* AimingComponent = nullptr;

	UFUNCTION()
	void OnTankDeath();
};
