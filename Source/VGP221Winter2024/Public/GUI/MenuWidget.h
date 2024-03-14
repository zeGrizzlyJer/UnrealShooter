// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "GUI/Buttonwidget.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2024_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TitleText;

	UPROPERTY(meta = (BindWidget))
	UButtonWidget* StartButton;

	UPROPERTY(meta = (BindWidget))
	UButtonWidget* QuitButton;

	UFUNCTION()
	void SetTitleText(const FText& text);

	UFUNCTION()
	void SetButtonText(const FText& text, UButtonWidget* button);

	UFUNCTION(BlueprintCallable)
	void SetMainMenu();

	UFUNCTION(BlueprintCallable)
	void SetWinScreen();

protected:
	UFUNCTION()
	void ClickStart();
	UFUNCTION()
	void ClickQuit();
};
