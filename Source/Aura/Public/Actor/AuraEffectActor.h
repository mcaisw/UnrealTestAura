// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAuraEffectActor();
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGamePlayEffectClass;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	void ApplyEffectToTarget(AActor* Target,TSubclassOf<UGameplayEffect> GamePlayEffectClass);
	
};
