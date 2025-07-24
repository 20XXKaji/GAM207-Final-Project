// Copyright Epic Games, Inc. All Rights Reserved.

#include "Final_Project_PartIGameMode.h"
#include "Final_Project_PartICharacter.h"
#include "UObject/ConstructorHelpers.h"

AFinal_Project_PartIGameMode::AFinal_Project_PartIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
