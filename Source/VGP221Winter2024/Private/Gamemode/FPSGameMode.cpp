// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamemode/FPSGameMode.h"

void AFPSGameMode::StartPlay()
{
	Super::StartPlay();

	UE_LOG(LogTemp, Warning, TEXT("Starting FPS Map"));

	ChangeMenuWidget(UserWidgetPrefab);
}

void AFPSGameMode::ChangeMenuWidget(TSubclassOf<UFPSUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromParent();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UFPSUserWidget>(GetWorld(), NewWidgetClass);
		CurrentWidget->AddToViewport();

		if (APawn* PlayerPawn = Cast<APawn>(GetWorld()->GetFirstPlayerController()->GetPawn()))
		{
			if (PlayerPawn)
			{
				UAC_HealthComponent* HealthComponent = PlayerPawn->FindComponentByClass<UAC_HealthComponent>();
				if (HealthComponent)
				{
					FScriptDelegate HealthChangedDelegate;
					HealthChangedDelegate.BindUFunction(CurrentWidget, FName("SetHealthBar"));

					HealthComponent->OnHealthChanged.Add(HealthChangedDelegate);
				}
			}
		}
	}
}
