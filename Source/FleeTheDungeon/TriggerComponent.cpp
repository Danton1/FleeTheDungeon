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
		} else if (Rotator) {
			UE_LOG(LogTemp, Display, TEXT("Succesfully found Rotator Component"));
		}
		else {
			UE_LOG(LogTemp, Display, TEXT("Failed to find Mover or Rotator Component"));
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
	if(!IsTriggered) {
		Trigger(true, OtherActor);
	}
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (IsTriggered) {
		Trigger(false, OtherActor);
	}
}

void UTriggerComponent::Trigger(bool NewTriggerValue, AActor* OtherActor)
{
	if (OtherActor && OtherActor->ActorHasTag("PressurePlateActivator")) {
		Trigger(NewTriggerValue);
	}
}

void UTriggerComponent::Trigger(bool NewTriggerValue)
{
		if (Mover) {
			Mover->SetShouldMove(NewTriggerValue);
		}
		else if (Rotator) {
			Rotator->SetShouldMove(NewTriggerValue);
		}
		else {
			UE_LOG(LogTemp, Display, TEXT("%s doesn't have a mover to trigger!"), *GetOwner()->GetActorNameOrLabel());
		}
		IsTriggered = NewTriggerValue;
}