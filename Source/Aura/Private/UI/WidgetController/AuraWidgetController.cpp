// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::SetupAbilitySystemComponents(APlayerController* PC, APlayerState* PS,
	UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	PlayerController=PC;
	PlayerState=PS;
	AbilitySystemComponent=ASC;
	AttributeSet=AS;
}

void UAuraWidgetController::BroadcastInitialValues()
{
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
}
