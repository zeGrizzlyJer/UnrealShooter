// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/Door.h"

ADoor::ADoor()
{
	SelfActivating = false;
	IsActivated = false;
	MoveTime = 0.0f;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Self"));
	}

	Target = CreateDefaultSubobject<USceneComponent>(TEXT("Target"));
	Target->SetupAttachment(RootComponent);

	MovingObject = CreateDefaultSubobject<USceneComponent>(TEXT("MovingObject"));
	MovingObject->SetupAttachment(RootComponent);
}

void ADoor::Tick(float DeltaTime)
{
	if (IsActivated)
	{
		MoveTime += DeltaTime;

		float alpha = FMath::Clamp(MoveTime / MoveDuration, 0.0f, 1.0f);

		FVector NewPosition = FMath::Lerp(InitialPos, EndPos, alpha);
		MovingObject->SetWorldLocation(NewPosition);

		if (MoveTime >= MoveDuration) SetActorTickEnabled(false);
	}
}

void ADoor::Interact_Implementation(AActor* OtherActor)
{
	Super::Interact_Implementation(OtherActor);

	InitialPos = MovingObject->GetComponentLocation();
	EndPos = Target->GetComponentLocation();
	IsActivated = true;
}