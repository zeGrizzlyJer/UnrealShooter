// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible/Checkpoint.h"

ACheckpoint::ACheckpoint()
{
	PrimaryActorTick.bCanEverTick = true;

	if (!CheckpointMesh)
	{
		CheckpointMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CheckpointMesh"));
		CheckpointMesh->SetupAttachment(CollisionComponent);
	}
	RespawnLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Respawn Location"));
	RespawnLocation->SetupAttachment(CollisionComponent);
}

void ACheckpoint::BeginPlay()
{
	Super::BeginPlay();

	CheckpointMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ACheckpoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckpointMesh->AddLocalRotation(FRotator(0, RotationRate * DeltaTime, 0));
}

void ACheckpoint::OnCollect(AActor* OtherActor)
{
	Super::OnCollect(OtherActor);

	UE_LOG(LogTemp, Warning, TEXT("Checkpoint OnCollect Called"));

	AFPSCharacter* character = Cast<AFPSCharacter>(OtherActor);

	if (!character)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid Character Type"));
		CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		return;
	}

	UFPSGameInstance* instance = Cast<UFPSGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (!instance)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid Instance Type"));
		CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		return;
	}

	if (UAC_Respawn* respawn = character->FindComponentByClass<UAC_Respawn>()) respawn->SetCheckpoint(RespawnLocation->GetComponentTransform());
	instance->UpdateCheckpoint(this);
}

