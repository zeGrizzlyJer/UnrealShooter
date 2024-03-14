// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gameplay/IDie.h"
#include "AC_HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedDelegate, float, CurrentHealth, float, MaxHealth);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VGP221WINTER2024_API UAC_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_HealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Health")
	float MaxHealth = 100.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Health")
	float CurrentHealth;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnHealthChangedDelegate OnHealthChanged;
	
	UFUNCTION(BlueprintCallable, Category = "Health")
	void TakeDamage(float damage);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetHealth(float value);

};
