// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FTProjectGameMode.generated.h"

UCLASS(minimalapi)
class AFTProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFTProjectGameMode();

protected:
	UFUNCTION(BlueprintCallable)
	void SetSettings(float PCMoveSpeed, float EnemyMoveSpeed, int EnemyNumber, float ShootDist, float DMG, float EnemyHP);
};



