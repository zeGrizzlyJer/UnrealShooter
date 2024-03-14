// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Collectible/Collectible.h"
#include "FPSGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2024_API UFPSGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UFPSGameInstance();
	ACollectible* CurrentCheckpoint;
	TMap<AActor*, FTransform> RespawnsMap;

	void UpdateCheckpoint(ACollectible* Checkpoint);
};
