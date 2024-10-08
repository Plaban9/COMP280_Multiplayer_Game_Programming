// Copyright Epic Games, Inc. All Rights Reserved.

#include "Test_PBGameMode.h"
#include "Test_PBPlayerController.h"
#include "Test_PBCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATest_PBGameMode::ATest_PBGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATest_PBPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}