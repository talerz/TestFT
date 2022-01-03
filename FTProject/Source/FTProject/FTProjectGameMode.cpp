// Copyright Epic Games, Inc. All Rights Reserved.

#include "FTProjectGameMode.h"
#include "FTProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFTProjectGameMode::AFTProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
