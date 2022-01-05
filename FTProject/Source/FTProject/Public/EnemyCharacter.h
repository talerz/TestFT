// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class FTPROJECT_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	UPROPERTY()
	float MaxHealth;
	UPROPERTY()
	float CurrentHealth;
	UPROPERTY()
	float MovementSpeed;
	UPROPERTY(VisibleAnywhere)
	class UWidgetComponent* HPBarComponent;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> HPBarWidgetClass;

	//Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	float GetHPPercentage() const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
private:
	void Die();
};


