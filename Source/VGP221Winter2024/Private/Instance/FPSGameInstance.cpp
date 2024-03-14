// Fill out your copyright notice in the Description page of Project Settings.


#include "Instance/FPSGameInstance.h"

UFPSGameInstance::UFPSGameInstance()
{
}

void UFPSGameInstance::UpdateCheckpoint(ACollectible* Checkpoint)
{
	if (CurrentCheckpoint)
	{
		CurrentCheckpoint->SetActorHiddenInGame(false);

		CurrentCheckpoint->CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
	CurrentCheckpoint = Checkpoint;

	CurrentCheckpoint->SetActorHiddenInGame(true);
}
