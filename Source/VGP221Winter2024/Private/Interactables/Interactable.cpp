// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/Interactable.h"

// Sets default values
AInteractable::AInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractableComponent = CreateDefaultSubobject<UAC_Interactable>(TEXT("InteractableComponent"));
	InteractableComponent->Interactable.SetObject(this);
	InteractableComponent->Interactable.SetInterface(this);

	SelfActivating = true;
}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
	if (!SelfActivating)
	{
		if (InteractableComponent)
		{
			if (UBoxComponent* box = InteractableComponent->CollisionBox)
			{
				box->SetCollisionEnabled(ECollisionEnabled::NoCollision);
				UE_LOG(LogTemp, Warning, TEXT("Collision unset for non self activating interactable: %s"), *GetName());
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Collision NOT unset for non self activating interactable!! Be afraid: %s"), *GetName());
			}
		}
	}
}

void AInteractable::Interact_Implementation(AActor* OtherActor)
{

}

