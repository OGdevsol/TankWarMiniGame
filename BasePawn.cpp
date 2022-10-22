// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComp);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	BulletSpawnPoint=CreateDefaultSubobject<USceneComponent>(TEXT("Bullet Spawn Point"));
	BulletSpawnPoint->SetupAttachment(TurretMesh);

}

void ABasePawn::RotateTurret(FVector lookAtTarget)
{
  FVector toTarget = lookAtTarget - TurretMesh->GetComponentLocation();
  FRotator lookAtRotation = FRotator(0.f,toTarget.Rotation().Yaw,0.f);
  TurretMesh->SetWorldRotation(FMath::RInterpTo(TurretMesh->GetComponentRotation(),lookAtRotation,UGameplayStatics::GetWorldDeltaSeconds(this),10.f));
}
void ABasePawn::Fire()
{
  FVector ProjectileSpawnPointLocation = BulletSpawnPoint->GetComponentLocation();
  DrawDebugSphere(
  GetWorld(),
  ProjectileSpawnPointLocation,
  25.f,
  12,
  FColor::Red,
  false,
  3.f);
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

