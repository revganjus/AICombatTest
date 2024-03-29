// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AICombatTest/AICombatTestTypes.h"
#include "CharacterAnimDataAsset.generated.h"

UCLASS()
class AICOMBATTEST_API UCharacterAnimDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly)
	FCharacterAnimationData CharacterAnimationData;
};
