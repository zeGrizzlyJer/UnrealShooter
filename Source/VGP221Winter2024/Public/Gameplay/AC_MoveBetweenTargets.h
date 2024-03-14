// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_MoveBetweenTargets.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VGP221WINTER2024_API UAC_MoveBetweenTargets : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_MoveBetweenTargets();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	float MoveSpeed;
	UPROPERTY(EditAnywhere)
	float DelayPeriod;

	UFUNCTION()
	void SetTargets(USceneComponent* targetA, USceneComponent* targetB, USceneComponent* patrolObject);

private:
	USceneComponent* TargetA;
	USceneComponent *TargetB;
	USceneComponent *MovingObject;

	bool IsMoving, Direction;
	FVector CurrentTarget;
	float CurrentDelay;
};
