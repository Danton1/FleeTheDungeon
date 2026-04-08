// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Lock.h"
#include "BarrelPressurePlate.generated.h"

UCLASS()
class FLEETHEDUNGEON_API ABarrelPressurePlate : public ALock
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABarrelPressurePlate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void SetIsKeyPlaced(bool bIsKeyPlaced) override;
};
