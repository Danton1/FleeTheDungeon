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
		if (Mover) {
			UE_LOG(LogTemp, Display, TEXT("Succesfully found Mover Component"));
			Mover->SetShouldMove(true);
		}
		else {
			UE_LOG(LogTemp, Display, TEXT("Failed to find Mover Component"));
		}
	}
	else {
		UE_LOG(LogTemp, Display, TEXT("MoverActor is nullpptr"));
	}
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}
