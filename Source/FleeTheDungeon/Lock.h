// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "TriggerComponent.h"
#include "Components/StaticMeshComponent.h"


#include "Lock.generated.h"

UCLASS()
class FLEETHEDUNGEON_API ALock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	bool GetIsKeyPlaced();

	void SetIsKeyPlaced(bool bIsKeyPlaced);

	FString GetKeyItemName();

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* RootComp;

	UPROPERTY(VisibleAnywhere)
	UTriggerComponent* TriggerComp;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* KeyItemMesh;

	UPROPERTY(EditAnywhere)
	FString KeyItemName;

	UPROPERTY(VisibleAnywhere)
	bool IsKeyPlaced = false;
};
