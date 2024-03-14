// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactables/ICanInteract.h"
#include "Interactables/AC_Interactable.h"
#include "Interactable.generated.h"

UCLASS()
class VGP221WINTER2024_API AInteractable : public AActor, public IICanInteract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void Interact_Implementation(AActor* OtherActor);

	UPROPERTY(EditAnywhere)
	bool SelfActivating;

	UPROPERTY(EditInstanceOnly)
	UAC_Interactable* InteractableComponent;
};
