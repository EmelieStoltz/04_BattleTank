// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"



void UTankBarrel::Elevate(float RelativeSpeed)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT(" %f: Barrel elevate called at speed %f"), Time, RelativeSpeed);
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds; //keep it framerate independent
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto NewElevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(NewElevation, 0, 0));
}
