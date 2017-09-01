// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;

	// Move the barrel to mouse target
	void MoveBarrel();

	// Get raycast location
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditAnywhere, Category = "CrosshairLocation")
		float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere, Category = "CrosshairLocation")
		float CrossHairYLocation = 0.333333;

	UPROPERTY(EditAnywhere, Category = "LineTrace")
		float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector lookDirection, FVector& HitLocation) const;
};
