// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "US_Interactable.generated.h"
UINTERFACE(MinimalAPI, Blueprintable)
class UUS_Interactable : public UInterface
{
	GENERATED_BODY()
};

class US_LOTL_PB_API IUS_Interactable
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction", meta = (DisplayName = "Interact"))
	void Interact(class AUS_Character* CharacterInstigator);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction", meta = (DisplayName = "CanInteract"))
	bool CanInteract(AUS_Character* CharacterInstigator) const;
};