// Fill out your copyright notice in the Description page of Project Settings.
#include "Projectile.h"

#include "EnemyCharacter.h"
#include "FTGameInstance.h"
#include "Components/CapsuleComponent.h"
#include "FTProject/FTProjectGameMode.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectile::AProjectile()
{
	CollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
	CollisionComp->InitCapsuleSize(5.0f, 5.f);

	CollisionComp->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	RootComponent = CollisionComp;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	InitialLifeSpan = 5.f;
	Damage = 1.f;
}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (!OtherActor || OtherActor == this)
		return;

	AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(OtherActor);
	if (Enemy)
		UGameplayStatics::ApplyDamage(Enemy, Damage, GetInstigatorController(), this, UDamageType::StaticClass());

	Destroy();
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	if(GetGameInstance())
	{
		UFTGameInstance* FTGameInstance = Cast<UFTGameInstance>(GetGameInstance());
		if (FTGameInstance)
			Damage = FTGameInstance->GetDMG() <= 0.f ? 1.f : FTGameInstance->GetDMG();
	}
	Super::BeginPlay();
}