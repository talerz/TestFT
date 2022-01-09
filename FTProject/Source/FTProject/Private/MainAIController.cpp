// Fill out your copyright notice in the Description page of Project Settings.


#include "FTProject/Public/MainAIController.h"

#include "FTProject/Public/PlayerCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "FTProject/FTProjectGameMode.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

AMainAIController::AMainAIController()
{
	AIBehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	AIBlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoardComp"));

	CachedCharacter = nullptr;
}

void AMainAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	CachedCharacter = Cast<ACharacter>(InPawn);

	if (!AIBehaviorTreeComponent || !AIBlackboardComponent || !AIBehaviorTree)
		return;

	AIBlackboardComponent->InitializeBlackboard(*AIBehaviorTree->BlackboardAsset);
	AIBehaviorTreeComponent->StartTree(*AIBehaviorTree);

	UWorld* World = GetWorld();
	class AFTProjectGameMode* FTGameMode = nullptr;
	if (World && UGameplayStatics::GetGameMode(World))
		FTGameMode = Cast<AFTProjectGameMode>(UGameplayStatics::GetGameMode(World));

	AIBlackboardComponent->ClearValue("Target");
	AIBlackboardComponent->ClearValue("ShootingRadius");

	if (FTGameMode)
		AIBlackboardComponent->SetValueAsObject("Target", FTGameMode->FindRandomEnemy());

	if (CachedCharacter)
	{
		class APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(CachedCharacter);
		if (PlayerCharacter)
			AIBlackboardComponent->SetValueAsFloat("ShootingRadius", PlayerCharacter->GetShootingDist());
	}
	
}