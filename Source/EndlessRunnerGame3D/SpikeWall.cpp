// Fill out your copyright notice in the Description page of Project Settings.


#include "SpikeWall.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine.h"

ASpikeWall::ASpikeWall()
{
	PrimaryActorTick.bCanEverTick = true;

	WallComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallComponent"));
	RootComponent = WallComponent;
	WallTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("WallTrigger"));
	WallTrigger->SetupAttachment(GetRootComponent());

	WallSpeed = 300.f;

}

void ASpikeWall::BeginPlay()
{

	Super::BeginPlay();

}

void ASpikeWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + FVector(0.f, WallSpeed * DeltaTime, 0.f), true);
}