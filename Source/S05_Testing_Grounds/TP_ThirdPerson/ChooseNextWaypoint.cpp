// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_Testing_Grounds.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto blackBoardComp = OwnerComp.GetBlackboardComponent();
	auto index = blackBoardComp->GetValueAsInt(indexKey.SelectedKeyName);

	UE_LOG(LogTemp, Warning, TEXT("Waypoint index: %i"), index);


	return EBTNodeResult::Succeeded;
}


