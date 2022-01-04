// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MainAIController.generated.h"

/**
 * 
 */
UCLASS()
class FTPROJECT_API AMainAIController : public AAIController
{
	GENERATED_BODY()
public:
	AMainAIController();

	virtual void OnPossess(APawn* InPawn) override;
protected:
	UPROPERTY()
	class UBehaviorTreeComponent* AIBehaviorTreeComponent;
	UPROPERTY(BlueprintReadOnly)
	class UBlackboardComponent* AIBlackboardComponent;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	class UBehaviorTree* AIBehaviorTree;
	UPROPERTY(BlueprintReadOnly)
	class ACharacter* CachedCharacter;
};
