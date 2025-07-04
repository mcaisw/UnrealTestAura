// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"


class UInputAction;
class UInputMappingContext;
class IEnemyInterface;
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AAuraPlayerController();
	void CursorTrace();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaTime) override;

	private:
	UPROPERTY(EditAnywhere,Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;
	
	UPROPERTY(EditAnywhere,Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const struct FInputActionValue& InputActionValue);

	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;

};
