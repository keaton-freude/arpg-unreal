// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "arpgGameMode.h"
#include "arpgPlayerController.h"
#include "arpgCharacter.h"
#include "UObject/ConstructorHelpers.h"

AarpgGameMode::AarpgGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AarpgPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}