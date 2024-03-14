// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/MenuWidget.h"

void UMenuWidget::NativeConstruct()
{
}

void UMenuWidget::SetTitleText(const FText& text)
{
	if (TitleText)
	{
		TitleText->SetText(text);
	}
}

void UMenuWidget::SetButtonText(const FText& text, UButtonWidget* button)
{
	button->ButtonText->SetText(text);
}

void UMenuWidget::SetMainMenu()
{
	FText text1 = FText::FromString(FString("Test Lab 002"));
	SetTitleText(text1);

	FText text2 = FText::FromString(FString("Start Game"));
	SetButtonText(text2, StartButton);
	StartButton->Button->OnClicked.AddDynamic(this, &UMenuWidget::ClickStart);

	FText text3 = FText::FromString(FString("Quit Game"));
	SetButtonText(text3, QuitButton);
	QuitButton->Button->OnClicked.AddDynamic(this, &UMenuWidget::ClickQuit);
}

void UMenuWidget::SetWinScreen()
{
	FText text1 = FText::FromString(FString("You Win"));
	SetTitleText(text1);

	FText text2 = FText::FromString(FString("Restart Game"));
	SetButtonText(text2, StartButton);
	StartButton->Button->OnClicked.AddDynamic(this, &UMenuWidget::ClickStart);

	FText text3 = FText::FromString(FString("Quit Game"));
	SetButtonText(text3, QuitButton);
	QuitButton->Button->OnClicked.AddDynamic(this, &UMenuWidget::ClickQuit);
}

void UMenuWidget::ClickStart()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("START"));
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	FInputModeGameOnly InputMode;
	PlayerController->SetInputMode(InputMode);
	PlayerController->bShowMouseCursor = false;

	FString LevelName = "FPSMap";
	UGameplayStatics::OpenLevel(GetWorld(), FName(*LevelName));
}

void UMenuWidget::ClickQuit()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	PlayerController->ConsoleCommand("quit");
}
