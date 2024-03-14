// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/Task_Attack.h"

EBTNodeResult::Type UTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("Attacking Player"));

	AAIController* AIController = Cast<AAIController>(OwnerComp.GetOwner());

	if (APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	{
		PlayerPawn->TakeDamage(10.0f, FDamageEvent(), AIController, AIController);
	}


	return EBTNodeResult::Succeeded;
}
