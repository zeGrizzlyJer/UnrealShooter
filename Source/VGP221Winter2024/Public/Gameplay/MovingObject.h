// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gameplay/AC_MoveBetweenTargets.h"
#include "MovingObject.generated.h"

UCLASS()
class VGP221WINTER2024_API AMovingObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingObject();

	UPROPERTY(EditAnywhere)
	UAC_MoveBetweenTargets* PatrolComponent;
	UPROPERTY(EditAnywhere)
	USceneComponent* TargetA;
	UPROPERTY(EditAnywhere)
	USceneComponent* TargetB;
	UPROPERTY(EditAnywhere)
	USceneComponent* MovingObject;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
