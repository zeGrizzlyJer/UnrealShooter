// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/DamageType.h"
#include "Characters/FPSCharacter.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2024_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
public:
	AEnemyAIController();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UPawnSensingComponent* PawnSensing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBehaviorTree* BehaviourTree;

	UFUNCTION()
	void OnSeePawn(APawn* PlayerPawn);

	UFUNCTION()
	void SetCanSeePlayer(bool SeePlayer, UObject* Player);


	AFPSCharacter* player;
	FTimerHandle RetriggerablTimerHandle;
	FTimerDelegate FunctionDelegate;
	void RunTriggerableTimer();
};
