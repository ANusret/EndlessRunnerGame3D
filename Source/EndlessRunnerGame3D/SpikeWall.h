// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spikes.h"
#include "SpikeWall.generated.h"

/**
 * 
 */
UCLASS()
class ENDLESSRUNNERGAME3D_API ASpikeWall : public ASpikes
{
	GENERATED_BODY()
	
public:

	ASpikeWall();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	class UStaticMeshComponent* WallComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	class UBoxComponent* WallTrigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WallSpeed")
	float WallSpeed;

protected:
	
	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

};
