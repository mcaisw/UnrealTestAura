// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "Widget/AuraUserWidget.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(APlayerController* PC, APlayerState* PS,
	UAbilitySystemComponent* ASC,UAttributeSet* AS)
{
	if (OverlayWidgetController==nullptr)
	{
		OverlayWidgetController=NewObject<UOverlayWidgetController>(this,OverlayWidgetControllerClass);
		OverlayWidgetController->SetupAbilitySystemComponents(PC,PS,ASC,AS);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	UUserWidget* Widget=CreateWidget<UUserWidget>(GetWorld(),OverlayWidgetClass);
	OverlayWidget=Cast<UAuraUserWidget>(Widget);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(PC,PS,ASC,AS);
	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	Widget->AddToViewport();
}

