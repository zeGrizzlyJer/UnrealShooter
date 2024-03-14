// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/Task_Shoot.h"

EBTNodeResult::Type UTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Attempt to fire
	if (!ProjectileClass) return EBTNodeResult::Failed;

	UE_LOG(LogTemp, Warning, TEXT("Shooting Player"));

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp) return EBTNodeResult::Failed;

	USceneComponent* ShootSpot = Cast<USceneComponent>(BlackboardComp->GetValueAsObject("Shoot Spot"));
	if (!ShootSpot) return EBTNodeResult::Failed;

	FTransform ShootSpotTransform = ShootSpot->GetComponentTransform();

	// Transform MuzzleOffset from camera space to world space
	FVector MuzzleLocation = ShootSpotTransform.GetLocation();

	// Skew the aim to be slightly upwards
	FRotator MuzzleRotation = ShootSpotTransform.Rotator();

	UWorld* World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = Cast<AAIController>(OwnerComp.GetAIOwner())->GetPawn();
		SpawnParams.Instigator = Cast<AAIController>(OwnerComp.GetAIOwner())->GetInstigator();

		// Spawn the projectile at the muzzle
		AFPSProjectile* Projectile = World->SpawnActor<AFPSProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
		if (Projectile)
		{
			// Set the projectile's initial trajectory
			FVector LaunchDirection = MuzzleRotation.Vector();
			Projectile->FireInDirection(LaunchDirection);
		}
	}

	return EBTNodeResult::Succeeded;
}
