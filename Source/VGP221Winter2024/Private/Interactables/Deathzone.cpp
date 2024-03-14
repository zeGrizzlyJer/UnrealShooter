// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/Deathzone.h"

void ADeathzone::Interact_Implementation(AActor* OtherActor)
{
	Super::Interact_Implementation(OtherActor);

	if (UFPSGameInstance* instance = Cast<UFPSGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		if (UAC_Respawn* respawn = OtherActor->FindComponentByClass<UAC_Respawn>()) respawn->Respawn();
	}
}
