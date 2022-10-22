// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
void AEnemy::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (Tank)
    {
         float distance = FVector::Dist(GetActorLocation(),Tank->GetActorLocation());
         if(distance<=fireRange)
         {
            RotateTurret(Tank->GetActorLocation());
         }
    }   
}
    
   
void AEnemy::BeginPlay()
{
    Super::BeginPlay();
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
}

