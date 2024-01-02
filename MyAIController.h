// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLE_SHOOTER_API AMyAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;
	bool IsDead() const;

protected:
	virtual void BeginPlay() override;

private:
	APawn* Player;
	// float AcceptanceRadius = 200;
	UPROPERTY(EditAnywhere)
	UBehaviorTree* AIBehavior;
};