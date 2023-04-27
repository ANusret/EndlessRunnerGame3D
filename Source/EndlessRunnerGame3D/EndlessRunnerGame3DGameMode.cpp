// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessRunnerGame3DGameMode.h"
#include "EndlessRunnerGame3DCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEndlessRunnerGame3DGameMode::AEndlessRunnerGame3DGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
