// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAbilitySystemComponent.h"


void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                                const FGameplayEffectSpec& GameplayEffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{

	FGameplayTagContainer OutContainer;
	GameplayEffectSpec.GetAllAssetTags(OutContainer);
	for (const FGameplayTag& T:OutContainer)
	{
		const auto msg=T.ToString();
		GEngine->AddOnScreenDebugMessage(1,8.f,FColor::Blue,msg);
	}
}
