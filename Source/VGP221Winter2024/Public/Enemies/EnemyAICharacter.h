// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Gameplay/AC_HealthComponent.h"
#include "Gameplay/IDie.h"
#include "GameFramework/Character.h"
#include "EnemyAICharacter.generated.h"

UCLASS()
class VGP221WINTER2024_API AEnemyAICharacter : public ACharacter, public IIDie
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyAICharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Health)
	UAC_HealthComponent* HealthComponent;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	void Die_Implementation();
};
