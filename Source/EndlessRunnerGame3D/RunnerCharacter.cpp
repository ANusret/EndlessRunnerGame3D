// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ARunnerCharacter::ARunnerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Overlap);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
	FixedCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FixedCamera"));
	FixedCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 720.f, 0.f);
	GetCharacterMovement()->GravityScale = 1.8f;
	GetCharacterMovement()->AirControl = 0.8f;
	GetCharacterMovement()->JumpZVelocity = 800.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	/*
	TempPos = GetActorLocation();
	zPosition = TempPos.Z + 200.f;
	*/
	
	TempPos = GetActorLocation();
	zPosition = TempPos.Z + 200;
	xPosition = TempPos.X - 900;
	yPosition = TempPos.Y;
	
	CameraSpeed = 300.f;

}

// Called when the game starts or when spawned
void ARunnerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//GetCapsuleComponent()->

	bCanMove = true;

}

// Called every frame
void ARunnerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*
	TempPos = GetActorLocation();
	TempPos.X -= 700.f;
	TempPos.Z = zPosition;
	FixedCamera->SetWorldLocation(TempPos);
	*/
	
	yPosition += CameraSpeed * DeltaTime;
	TempPos.X = xPosition;
	TempPos.Z = zPosition;
	TempPos.Y = yPosition;
	FixedCamera->SetWorldLocation(TempPos);
	
}

// Called to bind functionality to input
void ARunnerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveRight", this, &ARunnerCharacter::MoveRight);

}

void ARunnerCharacter::MoveRight(float Value)
{
	if (bCanMove)
	{
		AddMovementInput(FVector(0.f, 1.f, 0.f), Value);
	}
}

void ARunnerCharacter::RestartLevel()
{
}

void ARunnerCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

