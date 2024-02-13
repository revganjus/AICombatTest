// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AICombatTest/AICombatTestTypes.h"
#include "Engine/DataAsset.h"
#include "CharacterDataAsset.generated.h"

UCLASS()
class AICOMBATTEST_API UCharacterDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	FCharacterData CharacterData;
};
