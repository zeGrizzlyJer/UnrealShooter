// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Gameplay/AC_Respawn.h"
#include "Gameplay/IDie.h"
#include "Gameplay/AC_HealthComponent.h"
#include "Projectiles/FPSProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "GameMode/FPSGameMode.h"
#include "FPSCharacter.generated.h"

UCLASS()
class VGP221WINTER2024_API AFPSCharacter : public ACharacter, public IIDie
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Projectile class to spawn
	UPROPERTY(EditAnywhere, Category = Projectile)
	TSubclassOf<class AFPSProjectile> ProjectileClass;
	UPROPERTY(EditAnywhere, Category = Projectile)
	float pitchSkew = 10.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Handles input for moving forward/backward
	UFUNCTION()
	void MoveForward(float Value);

	// Handles input for moving right/left
	UFUNCTION()
	void MoveRight(float Value);

	// Sets jump flag when key is pressed
	UFUNCTION()
	void StartJump();

	// Clears jump flag when key is released
	UFUNCTION()
	void StopJump();

	// Function that handles firing projectiles
	UFUNCTION()
	void Fire();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	// FPS Camera
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPSCameraComponent;

	// First-person mesh (arms), visible only to the owning player
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* FPSMesh;

	UPROPERTY(EditAnywhere, Category = Health)
	UAC_HealthComponent* HealthComponent;

	// Gun muzzle offset from the camera location
	UPROPERTY(EditAnywhere, blueprintReadWrite, Category = Projectile)
	FVector MuzzleOffset;

protected:
	// Params for debug log to screen
	float displayTime = 5.0f;
	FColor textColor = FColor::Cyan;

public:
	void Die_Implementation();
};
