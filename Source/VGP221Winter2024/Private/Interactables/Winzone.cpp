// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/Winzone.h"

void AWinzone::Interact_Implementation(AActor* OtherActor)
{
	Super::Interact_Implementation(OtherActor);

	if (AFPSGameMode* Gamemode = Cast<AFPSGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		int currentScore = Gamemode->CurrentWidget->GetScore();

		FString text = (currentScore >= 12) ? "You Win" : "Find More Coins";

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, text);
		}
	}
}
