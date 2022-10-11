// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"


ATank::ATank() //Default Constructor for initializing pre processing stuff
{

SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("springArm");
SpringArmComp->SetupAttachment(RootComponent);

CameraComp =  CreateDefaultSubobject<UCameraComponent>("UCameraCompo");
CameraComp->SetupAttachment(SpringArmComp);
}
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
Super::SetupPlayerInputComponent(PlayerInputComponent);
PlayerInputComponent->BindAxis(TEXT("MoveForward"),this, &ATank::Move);
PlayerInputComponent->BindAxis(TEXT("Turn"),this, &ATank::Turn);
}
void ATank::Move(float value)
{
float deltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
FVector deltaLocation(0.f);
deltaLocation.X = value*tankSpeed;
AddActorLocalOffset(deltaLocation*deltaTime,true);
}
void ATank::Turn(float value)
{
    float deltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
    FRotator deltaRotation = FRotator::ZeroRotator;
    deltaRotation.Yaw = value*turnRate*deltaTime;
    AddActorLocalRotation(deltaRotation,true);
}

