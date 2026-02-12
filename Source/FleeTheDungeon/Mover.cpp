// Fill out your copyright notice in the Description page of Project Settings.

// Fill out your copyright notice in the Description page of Project Settings.

#include "Mover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...


}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetOwner()->GetActorLocation();

	TargetLocation = StartLocation + MoveOffset;
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Move(DeltaTime);
}

bool UMover::GetShouldMove()
{
	return ShouldMove;
}

void UMover::SetShouldMove(bool bVal)
{
	ShouldMove = bVal;
}

void UMover::Move(float DeltaTime) {
	if (ShouldMove) {
		TargetLocation = StartLocation + MoveOffset;
	}
	else {
		TargetLocation = StartLocation;
	}
	FVector CurrLocation = GetOwner()->GetActorLocation();

	if (TargetLocation.Equals(CurrLocation)) return;

	float MoveSpeed = MoveOffset.Length() / MoveTime;
	FVector NewLocation = FMath::VInterpConstantTo(CurrLocation, TargetLocation, DeltaTime, MoveSpeed);
	GetOwner()->SetActorLocation(NewLocation);
}