// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Spawner.generated.h"

class APlayerCharacter;
class AEnemyCharacter;
UCLASS()
class FTPROJECT_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	void SetupSpawner(int32 NewEnemyToSpawnNumber) { EnemyToSpawnNumber = NewEnemyToSpawnNumber <= 0 ? 5 : NewEnemyToSpawnNumber; }
	void SetupPlayerLocation(FVector NewPlayerStart) { PlayerStartLocation = NewPlayerStart; }

	void Spawn();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	float SpawnRadius;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ACharacter> EnemyClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ACharacter> PlayerCharClass;

private:
	int32 EnemyToSpawnNumber;
	int32 CurrentEnemyCounter;
	FVector PlayerStartLocation;

	void GetSpawnLocations(const FVector& Origin, float const MaxRadius, int32 const EnemiesNumber, TArray<FVector>& Locations) const;
	bool SpawnCharacter(TSubclassOf<ACharacter> CharacterClass, FVector const SpawnLocation) const;
};

