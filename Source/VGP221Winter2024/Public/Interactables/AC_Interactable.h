// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"
#include "Interactables/ICanInteract.h"
#include "AC_Interactable.generated.h"


UCLASS(meta=(BlueprintSpawnableComponent))
class VGP221WINTER2024_API UAC_Interactable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_Interactable();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components)
	UBoxComponent* CollisionBox;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USceneComponent* RootSceneComponent;*/

	UFUNCTION()
	void OnBoxOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
						   int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category = Interactable)
	void ActivateInteractable(AActor* OtherActor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Interactable)
	TScriptInterface<IICanInteract> Interactable;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
