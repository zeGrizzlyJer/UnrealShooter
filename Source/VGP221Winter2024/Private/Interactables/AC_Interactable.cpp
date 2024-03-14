// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactables/AC_Interactable.h"

// Sets default values for this component's properties
UAC_Interactable::UAC_Interactable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &UAC_Interactable::OnBoxOverlapBegin);
	CollisionBox->BodyInstance.SetCollisionProfileName(TEXT("Interactable"));
}

// Called when the game starts
void UAC_Interactable::BeginPlay()
{
	Super::BeginPlay();
}


void UAC_Interactable::OnBoxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ActivateInteractable(OtherActor);
}

void UAC_Interactable::ActivateInteractable(AActor* OtherActor)
{
	AActor* Owner = GetOwner();

	if (Owner && Owner->Implements<UICanInteract>() && OtherActor != Owner) IICanInteract::Execute_Interact(Owner, OtherActor);
}

