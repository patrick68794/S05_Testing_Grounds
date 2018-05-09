// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_Testing_Grounds.h"
#include "PatrolRoute.h"

TArray<AActor*> UPatrolRoute::getPatrolPoints() const
{
	return patrolPoints;
}