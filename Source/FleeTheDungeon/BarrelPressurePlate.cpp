// Fill out your copyright notice in the Description page of Project Settings.


#include "BarrelPressurePlate.h"


// Sets default values
ABarrelPressurePlate::ABarrelPressurePlate()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABarrelPressurePlate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABarrelPressurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ABarrelPressurePlate::SetIsKeyPlaced(bool bIsKeyPlaced)
{
	Super::SetIsKeyPlaced(bIsKeyPlaced);
	TriggerComp->SetIsPressurePlate(!bIsKeyPlaced);
	if (bIsKeyPlaced)
	{
		
	}
}