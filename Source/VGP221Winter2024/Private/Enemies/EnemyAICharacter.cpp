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

	TArray<UStaticMeshComponent*> MeshComponents;
	GetComponents<UStaticMeshComponent>(MeshComponents);

	for (UStaticMeshComponent* mesh : MeshComponents)
	{
		if (mesh->GetName() == "TurretHead")
		{
			TurretHead = mesh;

			TArray<USceneComponent*> SceneComponents;
			GetComponents<USceneComponent>(SceneComponents);

			for (USceneComponent* scene : SceneComponents)
			{
				if (scene->GetName() == "ShootSpot")
				{
					if (AAIController* MyController = Cast<AAIController>(GetController()))
					{
						if (UBlackboardComponent* Blackboard = MyController->GetBlackboardComponent())
						{
							Blackboard->SetValueAsObject("Shoot Spot", scene);
						}
					}
				}
			}
			break;
		}
	}
}

// Called every frame
void AEnemyAICharacter::Tick(float DeltaTime)
{
	if (!TurretHead) return;

	if (AAIController* MyController = Cast<AAIController>(GetController()))
	{
		if (UBlackboardComponent* Blackboard = MyController->GetBlackboardComponent())
		{
			if (bool SeePlayer = !Blackboard->GetValueAsBool("Can See Player"))
			{
				float TargetRotation = MaxRotationAngle * (GoingRight ? 1 : -1);
				RotationAngle = FMath::FInterpTo(RotationAngle, TargetRotation, DeltaTime, RotationSpeed);

				TurretHead->SetRelativeRotation(FRotator(0.0f, RotationAngle, 0.0f));
				if (FMath::IsNearlyEqual(RotationAngle, TargetRotation, 0.1f)) GoingRight = !GoingRight;
			}
			else
			{
				if (AActor* Target = Cast<AActor>(Blackboard->GetValueAsObject("Player Target")))
				{
					FVector Direction = (Target->GetActorLocation() - TurretHead->GetComponentLocation()).GetSafeNormal();
						
					FRotator TargetRotation = FRotationMatrix::MakeFromX(Direction).Rotator();

					TurretHead->SetWorldRotation(TargetRotation);
				}
			}
		}
	}
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

