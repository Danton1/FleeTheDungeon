// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Display, TEXT("Hi!"));

	if (MoverActor) {
		Mover = MoverActor->FindComponentByClass<UMover>();
		Rotator = MoverActor->FindComponentByClass<UDoorRotator>();
		if (Mover) {
			UE_LOG(LogTemp, Display, TEXT("Succesfully found Mover Component"));
		}
		else {
			UE_LOG(LogTemp, Display, TEXT("Failed to find Mover Component"));
		}
	}
	else {
		UE_LOG(LogTemp, Display, TEXT("MoverActor is nullpptr"));
	}

	if (IsPressurePlate) {
		OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapBegin);
		OnComponentEndOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapEnd);
	}
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Mover) {
		Mover->SetShouldMove(true);
		UE_LOG(LogTemp, Display, TEXT("Should move is now true"));
	}
	else if (Rotator) {
		Rotator->SetShouldMove(true);
		UE_LOG(LogTemp, Display, TEXT("Should move is now true"));
	}
	else {
		UE_LOG(LogTemp, Display, TEXT("Should move was not set to true"));
	}
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Mover) {
		Mover->SetShouldMove(false);
		UE_LOG(LogTemp, Display, TEXT("Should move is now false"));
	}
	else if (Rotator) {
		Rotator->SetShouldMove(false);
		UE_LOG(LogTemp, Display, TEXT("Should move is now true"));
	}
	else {
		UE_LOG(LogTemp, Display, TEXT("Should move was not set to false"));
	}
}
