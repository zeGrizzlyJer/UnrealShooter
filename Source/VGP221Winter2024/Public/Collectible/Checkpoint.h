// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/FPSCharacter.h"
#include "Collectible/Collectible.h"
#include "Gameplay/AC_Respawn.h"
#include "Instance/FPSGameInstance.h"
#include "Checkpoint.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2024_API ACheckpoint : public ACollectible
{
	GENERATED_BODY()
	
public:
	ACheckpoint();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;

	virtual void OnCollect(AActor* OtherActor) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CheckpointMesh;

	UPROPERTY(EditAnywhere)
	USceneComponent* RespawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationRate = 100;
};
