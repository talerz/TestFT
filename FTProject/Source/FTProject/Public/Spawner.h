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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	int32 EnemyToSpawnCounter;
	UPROPERTY()
	int32 CurrentEnemyCounter;
	UPROPERTY(EditDefaultsOnly)
	float SpawnRadius;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ACharacter> EnemyClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ACharacter> PlayerCharClass;
	UPROPERTY(EditAnywhere)
	class ATargetPoint* PlayerStart;

	UFUNCTION()
	void Spawn();

private:
	void GetSpawnLocations(const FVector& Origin, float const MaxRadius, int32 const EnemiesNumber, TArray<FVector>& Locations) const;
	bool SpawnCharacter(TSubclassOf<ACharacter> CharacterClass, FVector const SpawnLocation) const;
};

