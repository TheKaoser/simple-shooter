// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "MyBTService_PlayerLocationIfSeen.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLE_SHOOTER_API UMyBTService_PlayerLocationIfSeen : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:
	UMyBTService_PlayerLocationIfSeen();
};
