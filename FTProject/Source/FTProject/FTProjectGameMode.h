// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FTProjectGameMode.generated.h"

class ASpawner;
UCLASS(minimalapi)
class AFTProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFTProjectGameMode();

	void Start();
	virtual void StartPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpawner> MainSpawnerClass;
	UPROPERTY()
	class ASpawner* MainSpawner;
};



