// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/EnemyAICharacter.h"

// Sets default values
AEnemyAICharacter::AEnemyAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<UAC_HealthComponent>(TEXT("HealthComponent"));
}

// Called when the game starts or when spawned
void AEnemyAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AEnemyAICharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float FinalDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	if (HealthComponent) HealthComponent->TakeDamage(DamageAmount);
	if (GEngine)
	{
		FString text = "Enemy taking Damage";
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, text);
	}

	return FinalDamage;
}

void AEnemyAICharacter::Die_Implementation()
{
	Destroy();
}

