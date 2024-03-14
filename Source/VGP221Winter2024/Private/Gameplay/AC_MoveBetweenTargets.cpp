// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/AC_MoveBetweenTargets.h"

// Sets default values for this component's properties
UAC_MoveBetweenTargets::UAC_MoveBetweenTargets()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	IsMoving = Direction = true;
	CurrentDelay = 0.0f;
	MoveSpeed = 150.0f;
	DelayPeriod = 1.0f;
}


// Called when the game starts
void UAC_MoveBetweenTargets::BeginPlay()
{
	Super::BeginPlay();

	IsMoving = true;
	Direction = true;
}


// Called every frame
void UAC_MoveBetweenTargets::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsMoving)
	{
		FVector NewLocation = FMath::VInterpConstantTo
		(
			MovingObject->GetComponentLocation(),
			CurrentTarget, 
			DeltaTime, 
			MoveSpeed
		);
		MovingObject->SetWorldLocation(NewLocation);

		if (FVector::DistSquared(MovingObject->GetComponentLocation(), CurrentTarget) < 1.0f)
		{
			IsMoving = false;
			CurrentDelay = 0.0f;
			Direction = !Direction;
			CurrentTarget = (Direction) ? TargetB->GetComponentLocation() : TargetA->GetComponentLocation();
		}
	}
	else
	{
		CurrentDelay += DeltaTime;
		IsMoving = CurrentDelay >= DelayPeriod;
	}
}

void UAC_MoveBetweenTargets::SetTargets(USceneComponent* targetA, USceneComponent* targetB, USceneComponent* patrolObject)
{
	TargetA = targetA;
	TargetB = targetB;
	MovingObject = patrolObject;
	CurrentTarget = TargetB->GetComponentLocation();
}

