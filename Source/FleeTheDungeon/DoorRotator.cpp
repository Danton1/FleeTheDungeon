// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorRotator.h"

// Sets default values for this component's properties
UDoorRotator::UDoorRotator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorRotator::BeginPlay()
{
	Super::BeginPlay();

	StartRotation = GetOwner()->GetActorRotation();
	
	TargetRotation = StartRotation + MoveOffset;
	
}


// Called every frame
void UDoorRotator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	RotateDoor(DeltaTime);
	
}

void UDoorRotator::RotateDoor(float DeltaTime) {
	if (!ShouldMove) {
		TargetRotation = StartRotation;
	}

	FVector CurrLocation = GetOwner()->GetActorLocation();
	FRotator CurrRotation = GetOwner()->GetActorRotation();

	if (TargetRotation.Equals(CurrRotation)) return;

	float MoveSpeed = MoveOffset.Yaw / MoveTime;
	FRotator NewRotation = FMath::RInterpConstantTo(CurrRotation, TargetRotation, DeltaTime, MoveSpeed);
	GetOwner()->SetActorRotation(NewRotation);
}