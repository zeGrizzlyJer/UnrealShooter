// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/ButtonWidget.h"

void UButtonWidget::SetText(int value)
{
	if (!Button || !ButtonText) return;

	num = value;
	ButtonText->SetText(FText::FromString("Button: " + FString::FromInt(num)));
}

void UButtonWidget::OnButtonClick()
{
	UE_LOG(LogTemp, Warning, TEXT("Button Clicked: %s"), FString("Button Activated"));
}

void UButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (!Button)
	{
		Button = Cast<UButton>(GetWidgetFromName(TEXT("Button")));
		if (Button)
		{
			Button->OnClicked.AddDynamic(this, &UButtonWidget::OnButtonClick);
		}
	}
}
