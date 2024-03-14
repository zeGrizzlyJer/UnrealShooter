// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gamemode/FPSGameMode.h"
#include "GUI/MenuWidget.h"
#include "Interactables/Interactable.h"
#include "Winzone.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2024_API AWinzone : public AInteractable
{
	GENERATED_BODY()

public:
	void Interact_Implementation(AActor* OtherActor) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GUI")
	TSubclassOf<UMenuWidget> UserWidgetPrefab;

};
