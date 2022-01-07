// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class FTPROJECT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();
	void SetupPlayer(float NewMovementSpeed, float NewShootingDistance);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Fire();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY()
	float MovementSpeed;
	UPROPERTY(BlueprintReadOnly)
	float ShootingDistance;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
