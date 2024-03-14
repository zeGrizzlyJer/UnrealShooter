// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible/Collectible.h"

// Sets default values
ACollectible::ACollectible()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (!CollisionComponent)
	{
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
		CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ACollectible::BeginOverlap);
		CollisionComponent->InitSphereRadius(50.0f);
		CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Collectible"));
		RootComponent = CollisionComponent;
	}

}

// Called when the game starts or when spawned
void ACollectible::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollectible::BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OnCollect(OtherActor);
}

void ACollectible::OnCollect(AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Collectible OnCollect Called"));

	// Set collision presets to NoCollision
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	UGameplayStatics::PlaySound2D(this, Sound);

	if (Interactable)
	{
		if (UAC_Interactable* AC_Component = Interactable->FindComponentByClass<UAC_Interactable>()) AC_Component->ActivateInteractable(this);
	}
}