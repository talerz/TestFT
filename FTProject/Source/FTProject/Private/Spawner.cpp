// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

#include "NavigationSystem.h"
#include "GameFramework/Character.h"
#include "Engine/TargetPoint.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	EnemyToSpawnCounter = 5;
	CurrentEnemyCounter = 0;
	SpawnRadius = 5000.f;
	PlayerStart = nullptr;
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	Spawn();
	
}
 void ASpawner::Spawn()
{
	if(EnemyClass)
	{
		TArray<FVector> SpawnLocations;
		GetSpawnLocations(GetActorLocation(), SpawnRadius, EnemyToSpawnCounter, SpawnLocations);
		for (int32 i = 0; i < EnemyToSpawnCounter; i++)
		{
			if (SpawnCharacter(EnemyClass, SpawnLocations[i]))
				CurrentEnemyCounter++;
		}
	}
	if (PlayerCharClass && PlayerStart)
		SpawnCharacter(PlayerCharClass, PlayerStart->GetActorLocation());

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

