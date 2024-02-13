// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BaseCharacterAnimInstance.generated.h"

class AAICombatTestCharacter;
class UCharacterAnimDataAsset;
class UCharacterMovementComponent;

UCLASS()
class AICOMBATTEST_API UBaseCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	FCardinalDirectionsAnimationData GetStartAnimations() const;

	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	FCardinalDirectionsAnimationData GetMoveAnimations() const;
	
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	FCardinalDirectionsAnimationData GetStopAnimations() const;

	UFUNCTION(BlueprintCallable)
	UAnimSequenceBase* GetIdleAnimation() const;

private:
	UCharacterAnimDataAsset* GetCharacterAnimDataAsset() const;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animation")
	UCharacterAnimDataAsset* DefaultCharacterAnimDataAsset;

	UPROPERTY(BlueprintReadOnly, Category = "Character")
	AAICombatTestCharacter* Character;
	
	UPROPERTY(BlueprintReadOnly, Category = "Character")
	UCharacterMovementComponent* MovementComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Movement")
	bool bIsFalling;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animations|Movement")
	float MaxWalkSpeed;

	/** 2D speed.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animations|Movement")
	float Speed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animations|Movement")
	FVector Velocity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animations|Movement")
	FVector Acceleration;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Animations|Movement")
	FRotator Rotation;
};
