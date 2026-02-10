// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorRotator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FLEETHEDUNGEON_API UDoorRotator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorRotator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	FRotator StartRotation;
	FRotator TargetRotation;

	UPROPERTY(EditAnywhere)
	FRotator MoveOffset;

	UPROPERTY(EditAnywhere)
	float MoveTime = 4.0f;

	UPROPERTY(EditAnywhere)
	bool ShouldMove = false;

	void RotateDoor(float DeltaTime);
		
};
