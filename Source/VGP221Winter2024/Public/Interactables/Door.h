// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables/Interactable.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2024_API ADoor : public AInteractable
{
	GENERATED_BODY()
	
public:
	ADoor();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float MoveDuration;
	UPROPERTY(EditAnywhere)
	USceneComponent* Target;
	UPROPERTY(EditAnywhere)
	USceneComponent* MovingObject;
	
	void Interact_Implementation(AActor* OtherActor) override;

protected:
	bool IsActivated;
	float MoveTime;
	FVector InitialPos, EndPos;
};
