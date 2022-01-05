// Fill out your copyright notice in the Description page of Project Settings.

#include "FTProject/Public/EnemyCharacter.h"

#include "HPBarWidget.h"
#include "Components/ProgressBar.h"
#include "Components/WidgetComponent.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxHealth = 2.f;
	CurrentHealth = MaxHealth;
	MovementSpeed = 270.f;

	HPBarComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HP Bar"));
	if (HPBarComponent)
	{
		HPBarComponent->SetWidgetClass(HPBarWidgetClass);
		HPBarComponent->SetupAttachment(GetMesh());
	}
}

void AEnemyCharacter::Die()
{
	Destroy();
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (HPBarComponent)
	{
		HPBarComponent->InitWidget();
		UHPBarWidget* HPBarWidget = Cast< UHPBarWidget>(HPBarComponent->GetUserWidgetObject());
		if(!HPBarWidget)
			return;
		HPBarWidget->GetHPBar()->PercentDelegate.BindUFunction(this, FName("GetHPPercentage"));
	}
}

float AEnemyCharacter::GetHPPercentage() const
{
	if (MaxHealth <= 0)
		return 0;
	return  CurrentHealth / MaxHealth;
}

float AEnemyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	CurrentHealth -= DamageAmount;
	if (CurrentHealth <= 0)
		Die();
	return Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

