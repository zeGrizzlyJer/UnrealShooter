// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/MovingObject.h"

// Sets default values
AMovingObject::AMovingObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Self"));
	}

	PatrolComponent = CreateDefaultSubobject<UAC_MoveBetweenTargets>(TEXT("PatrolComponent"));

	TargetA = CreateDefaultSubobject<USceneComponent>(TEXT("TargetA"));
	TargetA->SetupAttachment(RootComponent);
	TargetB = CreateDefaultSubobject<USceneComponent>(TEXT("TargetB"));
	TargetB->SetupAttachment(RootComponent);
	MovingObject = CreateDefaultSubobject<USceneComponent>(TEXT("MovingObject"));
	MovingObject->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMovingObject::BeginPlay()
{
	Super::BeginPlay();
	
	if (PatrolComponent)
	{
		PatrolComponent->SetTargets(TargetA, TargetB, MovingObject);
	}
}

// Called every frame
void AMovingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

