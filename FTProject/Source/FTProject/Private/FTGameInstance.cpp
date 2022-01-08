// Fill out your copyright notice in the Description page of Project Settings.


#include "FTGameInstance.h"

void UFTGameInstance::SetSettings(float NewPCMoveSpeed, float NewEnemyMoveSpeed, int NewEnemyNumber, float NewShootDist,
	float NewDMG, float NewEnemyHP)
{
	PCMoveSpeed = NewPCMoveSpeed;
	EnemyMoveSpeed = NewEnemyMoveSpeed;
	EnemyNumber = NewEnemyNumber;
	ShootDist = NewShootDist;
	DMG = NewDMG;
	EnemyHP = NewEnemyHP;
}
