// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_Testing_Grounds.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto aiController = OwnerComp.GetAIOwner();
	auto blackBoardComp = OwnerComp.GetBlackboardComponent();
	auto index = blackBoardComp->GetValueAsInt(indexKey.SelectedKeyName);
	auto controlledPawn = OwnerComp.GetAIOwner()->GetPawn();

	//
	auto patrollingGuard = Cast<APatrollingGuard>(controlledPawn);
	auto patrolPoints = patrollingGuard->getPatrolPoints();
	blackBoardComp->SetValueAsObject(nextWaypointKey.SelectedKeyName, patrolPoints[index]);

	//UE_LOG(LogTemp, Warning, TEXT("Waypoint index: %i"), index);
	auto nextIndex = (index + 1) % patrolPoints.Num();
	blackBoardComp->SetValueAsInt(indexKey.SelectedKeyName, nextIndex);


	return EBTNodeResult::Succeeded;
}


