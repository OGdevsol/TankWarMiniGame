// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
//#include "Tank.generated.h"


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
PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATank::Fire );
}

void ATank:: BeginPlay()
{

    Super::BeginPlay();
    PlayerControllerRef= Cast<APlayerController>(GetController());
    
}
void ATank::Tick(float DeltaTime)
{
   Super::Tick(DeltaTime);
   if (PlayerControllerRef)
   {
    FHitResult HitResult;
     PlayerControllerRef->GetHitResultUnderCursor(
        ECollisionChannel::ECC_Visibility,
        false,
        HitResult);

        RotateTurret(HitResult.ImpactPoint);

     DrawDebugSphere(GetWorld(),
     HitResult.ImpactPoint,
     20.f,
     5,
     FColor::Blue,
     false,
     -1.f);
   }
   
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

