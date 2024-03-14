// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Gameplay/AC_HealthComponent.h"
#include "GUI/FPSUserWidget.h"
#include "FPSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2024_API AFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void StartPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GUI")
	TSubclassOf<UFPSUserWidget> UserWidgetPrefab;

	UFUNCTION(BlueprintCallable, Category = "GUI")
	void ChangeMenuWidget(TSubclassOf<UFPSUserWidget> NewWidgetClass);

	UPROPERTY()
	UFPSUserWidget* CurrentWidget;

private:
	float displayTime = 5.0f;
	FColor textColor = FColor::Red;
};
