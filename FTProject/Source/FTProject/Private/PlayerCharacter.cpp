// Fill out your copyright notice in the Description page of Project Settings.


#include "FTProject/Public/PlayerCharacter.h"

#include "Projectile.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	if (Weapon && GetMesh())
		Weapon->SetupAttachment(GetMesh(), FName("Weapon"));

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawn"));
	if (ProjectileSpawnPoint && Weapon)
		ProjectileSpawnPoint->SetupAttachment(Weapon, FName("Projectile"));

	ProjectileClass = AProjectile::StaticClass();

	MovementSpeed = 270.f;
	ShootingDistance = 500.f;
}

void APlayerCharacter::SetupPlayer(float NewMovementSpeed, float NewShootingDistance)
{
	GetCharacterMovement()->MaxWalkSpeed = NewMovementSpeed;
	ShootingDistance = NewShootingDistance;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::Fire()
{
	UE_LOG(LogTemp, Error, L"FIREE")
		UWorld* World = GetWorld();
	if (World && ProjectileClass && ProjectileSpawnPoint)
		World->SpawnActor<AProjectile>(ProjectileClass, ProjectileSpawnPoint->GetComponentTransform());
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
