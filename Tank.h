// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 *
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	ATank();
virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TankMovementProperties", meta = (AllowPrivateAccess = "true"))
    float tankSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TankMovementProperties", meta = (AllowPrivateAccess = "true"))
    float turnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TankComponents", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TankComponents", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComp;
	void Move(float value);
	void Turn (float value);
};
