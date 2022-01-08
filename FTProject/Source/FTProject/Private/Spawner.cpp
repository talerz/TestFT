// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "FTGameInstance.h"
#include "NavigationSystem.h"
#include "GameFramework/Character.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	EnemyToSpawnNumber = 5;
	CurrentEnemyCounter = 0;
	SpawnRadius = 5000.f;
	PlayerStartLocation = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	if(GetGameInstance())
	{
		UFTGameInstance* FTGameInstance = Cast<UFTGameInstance>(GetGameInstance());
		if (FTGameInstance)
		{
			SetupSpawner(FTGameInstance->GetEnemyNumber());
			SetupPlayerLocation(FTGameInstance->GetPlayerStartLocation());
		}
	}
	Super::BeginPlay();
	Spawn();
}

 void ASpawner::Spawn()
{

	if(EnemyClass)
	{
		TArray<FVector> SpawnLocations;
		GetSpawnLocations(GetActorLocation(), SpawnRadius, EnemyToSpawnNumber, SpawnLocations);
		for (int32 i = 0; i < EnemyToSpawnNumber; i++)
		{
			if (SpawnCharacter(EnemyClass, SpawnLocations[i]))
				CurrentEnemyCounter++;
		}
	}
	if (PlayerCharClass)
		SpawnCharacter(PlayerCharClass, PlayerStartLocation);
}

bool ASpawner::SpawnCharacter(TSubclassOf<ACharacter> CharacterClass, FVector const SpawnLocation) const
{
	UWorld* World = GetWorld();

	auto SpawnedCharacter = World->SpawnActor<ACharacter>(CharacterClass, SpawnLocation, FRotator::ZeroRotator);
	if (SpawnedCharacter)
		return true;
	return false;
}

void ASpawner::GetSpawnLocations(const FVector& Origin, float const MaxRadius, int32 const EnemiesNumber, TArray<FVector>& Locations) const
{
	UWorld* World = GetWorld();
	if (!World)
		return;

	UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(World);
	if (!NavigationSystem)
		return;

	for(int32 i = 0 ; i < EnemiesNumber; i++)
	{
		FNavLocation NavLocation;
		if (!NavigationSystem->GetRandomReachablePointInRadius(Origin, MaxRadius, NavLocation))
			continue;
	
		Locations.Add(NavLocation.Location);
	}
}

