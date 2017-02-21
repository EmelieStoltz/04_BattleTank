// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::RotateAround(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds; //keep it framerate independent
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}

