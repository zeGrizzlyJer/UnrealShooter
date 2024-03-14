// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/Winzone.h"

void AWinzone::Interact_Implementation(AActor* OtherActor)
{
	Super::Interact_Implementation(OtherActor);

	if (AFPSGameMode* Gamemode = Cast<AFPSGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		int currentScore = Gamemode->CurrentWidget->GetScore();
		FString text = "Find More Coins";

		if (currentScore < 12)
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, text);
			}
		}
		else
		{
			Gamemode->CurrentWidget->RemoveFromViewport();
			UMenuWidget* CurrentWidget = CreateWidget<UMenuWidget>(GetWorld(), UserWidgetPrefab);
			if (CurrentWidget)
			{
				CurrentWidget->SetWinScreen();
				CurrentWidget->AddToViewport();
				APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

				FInputModeUIOnly InputMode;
				PlayerController->SetInputMode(InputMode);
				PlayerController->bShowMouseCursor = true;
			}
		}
	}
}
