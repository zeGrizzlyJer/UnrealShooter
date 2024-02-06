// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamemode/FPSGameMode.h"

void AFPSGameMode::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);
	// Display a debug message for 5 seconds.
	// The -1 "Key" value argument prevents the msg from being updated/refreshed.
	GEngine->AddOnScreenDebugMessage(-1, displayTime, textColor, FString::Printf(TEXT("Starting FPS Map")));

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
	}
}
