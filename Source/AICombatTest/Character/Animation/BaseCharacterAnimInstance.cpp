// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacterAnimInstance.h"

#include "AICombatTest/Character/AICombatTestCharacter.h"
#include "AICombatTest/AICombatTestTypes.h"
#include "AICombatTest/DataAssets/CharacterAnimDataAsset.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBaseCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<AAICombatTestCharacter>(TryGetPawnOwner());
	MovementComponent = IsValid(Character)
							? Cast<UCharacterMovementComponent>(Character->GetMovementComponent())
							: nullptr;
}

void UBaseCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!IsValid(Character) || !IsValid(MovementComponent))
	{
		return;
	}

	bIsFalling = MovementComponent->IsFalling();
	
	MaxWalkSpeed = MovementComponent->MaxWalkSpeed;
	Velocity = MovementComponent->Velocity;
	Acceleration = MovementComponent->GetCurrentAcceleration();
	Speed = Velocity.Size2D();
	Rotation = Character->GetActorRotation();
}

FCardinalDirectionsAnimationData UBaseCharacterAnimInstance::GetStartAnimations() const
{
	if (const UCharacterAnimDataAsset* AnimDataAsset = GetCharacterAnimDataAsset())
	{
		return AnimDataAsset->CharacterAnimationData.StartAnimations;
	}

	return FCardinalDirectionsAnimationData();
}

FCardinalDirectionsAnimationData UBaseCharacterAnimInstance::GetMoveAnimations() const
{
	if (const UCharacterAnimDataAsset* AnimDataAsset = GetCharacterAnimDataAsset())
	{
		return AnimDataAsset->CharacterAnimationData.JogAnimations;
	}

	return FCardinalDirectionsAnimationData();
}

FCardinalDirectionsAnimationData UBaseCharacterAnimInstance::GetStopAnimations() const
{
	if (const UCharacterAnimDataAsset* AnimDataAsset = GetCharacterAnimDataAsset())
	{
		return AnimDataAsset->CharacterAnimationData.StopAnimations;
	}

	return FCardinalDirectionsAnimationData();
}

UAnimSequenceBase* UBaseCharacterAnimInstance::GetIdleAnimation() const
{
	if (const UCharacterAnimDataAsset* AnimDataAsset = GetCharacterAnimDataAsset())
	{
		return AnimDataAsset->CharacterAnimationData.IdleAnimation;
	}

	return nullptr;
}

UCharacterAnimDataAsset* UBaseCharacterAnimInstance::GetCharacterAnimDataAsset() const
{
	if (IsValid(Character))
	{
		return Character->GetCharacterAnimDataAsset();
	}

	return DefaultCharacterAnimDataAsset;
}
