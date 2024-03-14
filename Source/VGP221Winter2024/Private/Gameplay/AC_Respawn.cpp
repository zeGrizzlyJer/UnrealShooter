// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/AC_Respawn.h"

// Sets default values for this component's properties
UAC_Respawn::UAC_Respawn()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


}


// Called when the game starts
void UAC_Respawn::BeginPlay()
{
	Super::BeginPlay();

	SetCheckpoint(GetOwner()->GetActorTransform());
}

void UAC_Respawn::SetCheckpoint(FTransform transform)
{
	AActor* owner = GetOwner();
	UFPSGameInstance* instance = Cast<UFPSGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (!instance)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid Instance Type"));
		return;
	}
	instance->RespawnsMap.Add(owner, transform);
}

void UAC_Respawn::Respawn()
{
	AActor* owner = GetOwner();
	UFPSGameInstance* instance = Cast<UFPSGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (!instance)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid Instance Type"));
		return;
	}
	if (const FTransform* respawnSpot = instance->RespawnsMap.Find(owner))
	{
		FVector location = respawnSpot->GetLocation();
		FQuat rotation = respawnSpot->GetRotation();

		owner->SetActorLocationAndRotation(location, rotation);
	}
}


