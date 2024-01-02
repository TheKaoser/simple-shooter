// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTService_PlayerLocationIfSeen.h"
#include "Kismet/GameplayStatics.h"
#include "MyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UMyBTService_PlayerLocationIfSeen::UMyBTService_PlayerLocationIfSeen()
{
    this->NodeName = "Set Player Location if Seen";
}

void UMyBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn == nullptr)
    {
        return;
    }

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return;
    }

    if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }

}