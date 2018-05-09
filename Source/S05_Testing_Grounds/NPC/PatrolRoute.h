// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S05_TESTING_GROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	
	TArray<AActor*> getPatrolPoints() const;

private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol")
		TArray<AActor*> patrolPoints;
	
};
