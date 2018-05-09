// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_Testing_Grounds.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	auto aiController = OwnerComp.GetAIOwner();
	auto blackBoardComp = OwnerComp.GetBlackboardComponent();
	auto controlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto patrolRoute = controlledPawn->FindComponentByClass<UPatrolRoute>();

	if (!ensure(patrolRoute))
	{
		return EBTNodeResult::Failed;
	}

	auto patrolPoints = patrolRoute->getPatrolPoints();

	if (patrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor has no patrol points"));
		return EBTNodeResult::Failed;
	}

	auto index = blackBoardComp->GetValueAsInt(indexKey.SelectedKeyName);
	blackBoardComp->SetValueAsObject(nextWaypointKey.SelectedKeyName, patrolPoints[index]);

	auto nextIndex = (index + 1) % patrolPoints.Num();
	blackBoardComp->SetValueAsInt(indexKey.SelectedKeyName, nextIndex);


	return EBTNodeResult::Succeeded;
}


