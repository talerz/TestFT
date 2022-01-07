// Copyright Epic Games, Inc. All Rights Reserved.

#include "FTProjectGameMode.h"
#include "FTProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFTProjectGameMode::AFTProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/Characters/PlayerCharacter/BP_ThirdPersonCharacter_Weapon"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AFTProjectGameMode::SetSettings(float PCMoveSpeed, float EnemyMoveSpeed, int EnemyNumber, float ShootDist, float DMG, float EnemyHP)
{
}
