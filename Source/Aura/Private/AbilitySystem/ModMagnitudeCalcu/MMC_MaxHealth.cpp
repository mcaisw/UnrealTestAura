// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ModMagnitudeCalcu/MMC_MaxHealth.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Interactive/CombatInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	VigorDefinition.AttributeToCapture=UAuraAttributeSet::GetVigorAttribute();
	VigorDefinition.AttributeSource=EGameplayEffectAttributeCaptureSource::Target;
	VigorDefinition.bSnapshot=false;
	RelevantAttributesToCapture.Add(VigorDefinition);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	// 获取 Source 和 Target 的 Tag
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = SourceTags;
	EvaluateParameters.TargetTags = TargetTags;

	float vigor=0.f;
	GetCapturedAttributeMagnitude(VigorDefinition, Spec, EvaluateParameters, vigor);
	vigor=FMath::Max(vigor,0.f);

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface ? CombatInterface->GetPlayerLevel() : 1;

	float result=80+vigor* 2.5f +10*PlayerLevel;
	//show result on screen
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("MaxHealth: %.2f"), result));
	}

	// Log the result for debugging
	UE_LOG(LogTemp, Log, TEXT("MaxHealth: %.2f"), result);
	return result;
}
