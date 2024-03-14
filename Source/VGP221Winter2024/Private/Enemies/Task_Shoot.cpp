// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/Task_Shoot.h"

EBTNodeResult::Type UTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("Shooting Player"));

	AActor* Target = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("Player Target"));
	UStaticMeshComponent* Rotator = Cast<UStaticMeshComponent>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("Rotator"));

	FVector Direction = Target->GetActorLocation() - Rotator->GetComponentLocation();

	return EBTNodeResult::Succeeded;
}
