// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelSpawner.h"
#include "Engine.h"
#include "Components/BoxComponent.h"
#include "BaseLevel.h"

// Sets default values
ALevelSpawner::ALevelSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnLevel(true);
	SpawnLevel(false);
	SpawnLevel(false);
	SpawnLevel(false);

}

// Called every frame
void ALevelSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelSpawner::SpawnLevel(bool IsFirst)
{
	SpawnLoc = FVector(0.f, 1000.f, 0.f);
	SpawnRotation = FRotator(0, 90, 0);

	if (!IsFirst)
	{
		ABaseLevel* LastLevel = LevelList.Last();
		SpawnLoc = LastLevel->GetSpawnLoc()->GetComponentTransform().GetTranslation();
	}

	RandomLvl = FMath::RandRange(1, 12);
	ABaseLevel* NewLevel = nullptr;

	switch (RandomLvl)
	{
	case 1:
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level1, SpawnLoc, SpawnRotation, SpawnInfo);
		break;
	case 2:
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level2, SpawnLoc, SpawnRotation, SpawnInfo);
		break;
	case 3:
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level3, SpawnLoc, SpawnRotation, SpawnInfo);
		break;
	case 4:
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level4, SpawnLoc, SpawnRotation, SpawnInfo);
		break;
	case 5:
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level5, SpawnLoc, SpawnRotation, SpawnInfo);
		break;
	case 6:
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level6, SpawnLoc, SpawnRotation, SpawnInfo);
		break;
	case 7:
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level7, SpawnLoc, SpawnRotation, SpawnInfo);
		break;
	case 8:
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level8, SpawnLoc, SpawnRotation, SpawnInfo);
		break;
	case 9:
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level9, SpawnLoc, SpawnRotation, SpawnInfo);
		break;
	case 10:
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level10, SpawnLoc, SpawnRotation, SpawnInfo);
		break;
	case 11:
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level11, SpawnLoc, SpawnRotation, SpawnInfo);
		break;
	case 12:
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(Level12, SpawnLoc, SpawnRotation, SpawnInfo);
		break;
	default:
		break;
	}

	if (NewLevel)
	{
		if (NewLevel->GetTrigger())
		{
			
			NewLevel->GetTrigger()->OnComponentBeginOverlap.AddDynamic(this, &ALevelSpawner::OnOverlapBegin);
		
		}
	}

	LevelList.Add(NewLevel);
	if (LevelList.Num() >= 6)
	{
		LevelList.RemoveAt(0);
	}
}

void ALevelSpawner::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	SpawnLevel(false);
}

