// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FTGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class FTPROJECT_API UFTGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	void SetPlayerStartLocation(FVector NewPlayerStartLocation) { PlayerStartLocation = NewPlayerStartLocation; }

	float GetPCMoveSpeed() const { return PCMoveSpeed; }
	float GetEnemyMoveSpeed() const { return EnemyMoveSpeed; }
	int32 GetEnemyNumber() const { return EnemyNumber; }
	float GetShootDist() const { return ShootDist; }
	float GetDMG() const { return DMG; }
	float GetEnemyHP() const { return EnemyHP; }
	FVector GetPlayerStartLocation() const { return PlayerStartLocation; }

protected:
	UFUNCTION(BlueprintCallable)
	void SetSettings(float NewPCMoveSpeed, float NewEnemyMoveSpeed, int NewEnemyNumber, float NewShootDist, float NewDMG, float NewEnemyHP);

private:
	float PCMoveSpeed;
	float EnemyMoveSpeed;
	int32 EnemyNumber;
	float ShootDist;
	float DMG;
	float EnemyHP;
	FVector PlayerStartLocation;
};
