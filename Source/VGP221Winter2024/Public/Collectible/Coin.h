// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectible/Collectible.h"
#include "Kismet/GameplayStatics.h"
#include "Gamemode/FPSGameMode.h"
#include "Coin.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2024_API ACoin : public ACollectible
{
	GENERATED_BODY()
	
public:
	ACoin();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;

	virtual void OnCollect() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CoinMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Points = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationRate = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CollectRotationRate = 1500;

	FTimerHandle DeathTimerHandle;
	void DeathTimerComplete();

};
