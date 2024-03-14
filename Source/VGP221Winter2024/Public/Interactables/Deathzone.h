// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables/Interactable.h"
#include "Kismet/GameplayStatics.h"
#include "Gameplay/AC_Respawn.h"
#include "Instance/FPSGameInstance.h"
#include "Deathzone.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2024_API ADeathzone : public AInteractable
{
	GENERATED_BODY()
	
public:
	void Interact_Implementation(AActor* OtherActor) override;
};
