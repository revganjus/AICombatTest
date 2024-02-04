// Copyright Epic Games, Inc. All Rights Reserved.

#include "AICombatTestGameMode.h"
#include "AICombatTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAICombatTestGameMode::AAICombatTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
