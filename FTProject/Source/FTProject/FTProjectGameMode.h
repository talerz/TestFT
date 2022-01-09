// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FTProjectGameMode.generated.h"

class ASpawner;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnemiesKilled, bool, bAllKilled);
UCLASS(minimalapi)
class AFTProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFTProjectGameMode();

	void Start();
	virtual void StartPlay() override;
	float GetCurrentEnemyCounter() const { return CurrentEnemyCounter; }

	void SetCurrentEnemyCounter(int32 NewCurrentEnemyCounter) { CurrentEnemyCounter = NewCurrentEnemyCounter; }
	void ClearSpawnedEnemies();
	void AddSpawnedEnemies(class ACharacter* NewEnemy);
	void RemoveKilledEnemy(class ACharacter* KilledEnemy);
	UFUNCTION(BlueprintCallable)
	class ACharacter* FindRandomEnemy();

	UPROPERTY(BlueprintAssignable)
	FEnemiesKilled OnEnemiesKilled;

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpawner> MainSpawnerClass;
	UPROPERTY()
	class ASpawner* MainSpawner;
	UPROPERTY()
	TArray<class ACharacter*> SpawnedEnemies;
private:
	int32 CurrentEnemyCounter;
};



