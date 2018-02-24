// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_Testing_Grounds.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("This is a test"));
	return EBTNodeResult::Succeeded;
}


