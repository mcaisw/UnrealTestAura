// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
 #include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"

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

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();
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

void AAuraCharacter::InitAbilityActorInfo()
{
	//Init ability actor info for the server
	AAuraPlayerState* AuraPlayerState=GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState,this);

	AbilitySystemComponent=AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet=AuraPlayerState->GetAttributeSet();

	if (AAuraPlayerController* AuraPlayerController=Cast<AAuraPlayerController>(GetController()))
	{
		if (AAuraHUD* AuraHUD=Cast<AAuraHUD>(AuraPlayerController->GetHUD()))
		{
			AuraHUD->InitOverlay(AuraPlayerController,AuraPlayerState,AbilitySystemComponent,AttributeSet);
		}
	}
}
