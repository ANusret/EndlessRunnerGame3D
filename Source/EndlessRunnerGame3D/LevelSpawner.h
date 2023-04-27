// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelSpawner.generated.h"

UCLASS()
class ENDLESSRUNNERGAME3D_API ALevelSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public: 
	UFUNCTION()
	void SpawnLevel(bool IsFirst);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:

	APawn* Player;

	UPROPERTY(EditAnywhere)//, BlueprintReadWrite, Category = "Level")
	TSubclassOf<class ABaseLevel> Level1;

	UPROPERTY(EditAnywhere)//, BlueprintReadWrite, Category = "Level")
	TSubclassOf<ABaseLevel> Level2;

	UPROPERTY(EditAnywhere)//, BlueprintReadWrite, Category = "Level")
	TSubclassOf<ABaseLevel> Level3;

	UPROPERTY(EditAnywhere)//, BlueprintReadWrite, Category = "Level")
	TSubclassOf<ABaseLevel> Level4;

	UPROPERTY(EditAnywhere)//, BlueprintReadWrite, Category = "Level")
	TSubclassOf<ABaseLevel> Level5;

	UPROPERTY(EditAnywhere)//, BlueprintReadWrite, Category = "Level")
	TSubclassOf<ABaseLevel> Level6;

	UPROPERTY(EditAnywhere)//, BlueprintReadWrite, Category = "Level")
	TSubclassOf<ABaseLevel> Level7;

	UPROPERTY(EditAnywhere)//, BlueprintReadWrite, Category = "Level")
	TSubclassOf<ABaseLevel> Level8;

	UPROPERTY(EditAnywhere)//, BlueprintReadWrite, Category = "Level")
	TSubclassOf<ABaseLevel> Level9;

	UPROPERTY(EditAnywhere)//, BlueprintReadWrite, Category = "Level")
	TSubclassOf<ABaseLevel> Level10;

	UPROPERTY(EditAnywhere)//, BlueprintReadWrite, Category = "Level")
	TSubclassOf<ABaseLevel> Level11;

	UPROPERTY(EditAnywhere)//, BlueprintReadWrite, Category = "Level")
	TSubclassOf<ABaseLevel> Level12;

	TArray<ABaseLevel*> LevelList;

public:
	int RandomLvl;

	FVector SpawnLoc = FVector();
	FRotator SpawnRotation = FRotator();
	FActorSpawnParameters SpawnInfo = FActorSpawnParameters();

};
