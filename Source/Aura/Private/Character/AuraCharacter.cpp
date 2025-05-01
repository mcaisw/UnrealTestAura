// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
	UE_LOG(LogTemp, Warning, TEXT("AAuraCharacter::AAuraCharacter()"));
	
	// 确保获取到 CharacterMovement 组件
	UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	if (MovementComponent)
	{
		MovementComponent->bOrientRotationToMovement = true;
		MovementComponent->RotationRate = FRotator(0.f, 400.0f, 0.f);
		MovementComponent->bConstrainToPlane = true;
		MovementComponent->bSnapToPlaneAtStart = true;
		MovementComponent->bUseControllerDesiredRotation = false;
	}

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	UE_LOG(LogTemp, Warning, TEXT("######AAuraCharacter::AAuraCharacter()"));
}

void AAuraCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// 在 BeginPlay 中再次确保设置正确
	UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	if (MovementComponent)
	{
		MovementComponent->bOrientRotationToMovement = true;
		MovementComponent->RotationRate = FRotator(0.f, 400.0f, 0.f);
		MovementComponent->bUseControllerDesiredRotation = false;
		MovementComponent->bConstrainToPlane = true;
		MovementComponent->bSnapToPlaneAtStart = true;
	}
}
