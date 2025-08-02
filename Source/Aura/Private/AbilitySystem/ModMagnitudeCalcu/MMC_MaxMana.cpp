// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ModMagnitudeCalcu/MMC_MaxMana.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Interactive/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	IntelligenceDefinition.AttributeToCapture=UAuraAttributeSet::GetIntelligenceAttribute();
	IntelligenceDefinition.AttributeSource=EGameplayEffectAttributeCaptureSource::Target;
	IntelligenceDefinition.bSnapshot=false;
	RelevantAttributesToCapture.Add(IntelligenceDefinition);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	// 获取 Source 和 Target 的 Tag
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = SourceTags;
	EvaluateParameters.TargetTags = TargetTags;

	float intelligence=0.f;
	GetCapturedAttributeMagnitude(IntelligenceDefinition, Spec, EvaluateParameters, intelligence);
	intelligence=FMath::Max(intelligence,0.f);

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface ? CombatInterface->GetPlayerLevel() : 1;

	float result=80+intelligence* 2.5f +10*PlayerLevel;
	//show result on screen
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("MaxMana: %.2f"), result));
	}

	// Log the result for debugging
	UE_LOG(LogTemp, Log, TEXT("MaxMana: %.2f"), result);
	return result;
}
