// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RunnerCharacter.generated.h"

UCLASS()
class ENDLESSRUNNERGAME3D_API ARunnerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARunnerCharacter();

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* FixedCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraSpeed")
	float CameraSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void MoveRight(float Value);

public:
	FORCEINLINE UCameraComponent* GetFixedCamera() const { return FixedCamera; }

	void RestartLevel();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:

	float zPosition;
	float xPosition;
	float yPosition;
	
	FVector TempPos; // = FVector();

	bool bCanMove;

};
