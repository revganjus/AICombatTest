#pragma once

#include "CoreMinimal.h"
#include "AICombatTestTypes.generated.h"

class UCharacterAnimDataAsset;

UENUM(BlueprintType)
enum class ECardinalDirectionType : uint8
{
	Forward,
	Backward,
	Left,
	Right
};

USTRUCT(BlueprintType, Blueprintable)
struct FCardinalDirectionsAnimationData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UAnimSequenceBase* Forward = nullptr;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UAnimSequenceBase* Backward = nullptr;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UAnimSequenceBase* Left = nullptr;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UAnimSequenceBase* Right = nullptr;
};


USTRUCT(BlueprintType)
struct FCharacterAnimationData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly)
	FCardinalDirectionsAnimationData StartAnimations;

	UPROPERTY(EditDefaultsOnly)
	FCardinalDirectionsAnimationData JogAnimations;

	UPROPERTY(EditDefaultsOnly)
	FCardinalDirectionsAnimationData StopAnimations;

	UPROPERTY(EditDefaultsOnly)
	UAnimSequenceBase* IdleAnimation = nullptr;
};

USTRUCT(BlueprintType)
struct FCharacterData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animation")
	UCharacterAnimDataAsset* CharacterAnimDataAsset = nullptr;
};