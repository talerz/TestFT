// Copyright Epic Games, Inc. All Rights Reserved.

#include "FTProjectGameMode.h"

#include "FTGameInstance.h"
#include "Spawner.h"
#include "Engine/TargetPoint.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AFTProjectGameMode::AFTProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/Characters/PlayerCharacter/BP_ThirdPersonCharacter_Weapon"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
	MainSpawner = nullptr;
}

void AFTProjectGameMode::Start()
{
	UWorld* World = GetWorld();
	if (!World)
		return; 

	if(AActor* FoundActor = UGameplayStatics::GetActorOfClass(World, ATargetPoint::StaticClass()))
	{
		if(FoundActor && MainSpawnerClass)
		{
			if (GetGameInstance())
			{
				UFTGameInstance* FTGameInstance = Cast<UFTGameInstance>(GetGameInstance());
				if (FTGameInstance)
					FTGameInstance->SetPlayerStartLocation(FoundActor->GetActorLocation());
			}
			MainSpawner = World->SpawnActor<ASpawner>(MainSpawnerClass, FoundActor->GetActorLocation(), FRotator::ZeroRotator);
			
		}
	}
}

void AFTProjectGameMode::StartPlay()
{
	Super::StartPlay();
	Start();
}