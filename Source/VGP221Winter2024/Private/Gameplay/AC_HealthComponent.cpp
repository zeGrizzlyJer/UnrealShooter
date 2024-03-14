// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/AC_HealthComponent.h"

// Sets default values for this component's properties
UAC_HealthComponent::UAC_HealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UAC_HealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
}

void UAC_HealthComponent::TakeDamage(float damage)
{
	if (damage <= 0.0f) return;
	CurrentHealth = FMath::Clamp(CurrentHealth - damage, 0.0f, MaxHealth);
	OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
	if (CurrentHealth <= 0.0f)
	{
		AActor* Owner = GetOwner();

		if (Owner && Owner->Implements<UIDie>()) IIDie::Execute_Die(Owner);
	}
}

void UAC_HealthComponent::SetHealth(float value)
{
	if (value <= 0.0f) return;
	CurrentHealth = FMath::Clamp(CurrentHealth + value, 0.0f, MaxHealth);
	OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
}


