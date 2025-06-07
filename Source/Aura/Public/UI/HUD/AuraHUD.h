// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

/**
 * 
 */

class UAbilitySystemComponent;
class UAttributeSet;
class UOverlayWidgetController;
class UAuraUserWidget;

UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;
	UOverlayWidgetController* GetOverlayWidgetController(APlayerController* PC, APlayerState* PS,
	UAbilitySystemComponent* ASC, UAttributeSet* AS);

	void InitOverlay(APlayerController* PC, APlayerState* PS,
	UAbilitySystemComponent* ASC, UAttributeSet* AS);


private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
};
