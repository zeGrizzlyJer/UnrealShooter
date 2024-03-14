// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/FPSUserWidget.h"

void UFPSUserWidget::NativeConstruct()
{
	SetHealthBar(100.0f, 100.0f);
	SetScore(0);

	if (ButtonWidgetPrefab)
	{
		for (int i = 0; i < 4; i++)
		{
			UUserWidget* widget = CreateWidget(this, ButtonWidgetPrefab);
			ButtonContainer->AddChildToVerticalBox(widget);

			UButtonWidget* button = Cast<UButtonWidget>(widget);
			button->SetText(i);
		}
	}
}

void UFPSUserWidget::SetHealthBar(float CurrentHealth, float MaxHealth)
{
	if (!HealthBar) return;

	HealthBar->SetPercent(CurrentHealth / MaxHealth);
}

void UFPSUserWidget::SetScore(int newScore)
{
	if (!ScoreText) return;

	UIScore += newScore;
	ScoreText->SetText(FText::FromString("Score: " + FString::FromInt(UIScore)));
}

int UFPSUserWidget::GetScore()
{
	return UIScore;
}
