// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacterBase.h"
#include "AbilitySystemComponent.h"

// Sets default values
AAuraCharacterBase::AAuraCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Weapon=CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAuraCharacterBase::InitializePrimaryAttributes() const
{
	check(IsValid(AbilitySystemComponent));
	check(IsValid(DefaultPrimaryAttributes));
	// 获取角色的能力系统组件（AbilitySystemComponent）
	// 检查能力系统组件和默认主属性（DefaultPrimaryAttributes）是否都有效
	// 创建一个 GameplayEffectContextHandle，用于描述效果的上下文（如来源对象等）
	FGameplayEffectContextHandle EffectContextHandle = AbilitySystemComponent->MakeEffectContext();
	// 基于默认主属性和上下文，生成一个 GameplayEffectSpecHandle，1 表示效果等级
	FGameplayEffectSpecHandle EffectSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultPrimaryAttributes, 1, EffectContextHandle);
	// 获取实际的 GameplayEffectSpec 指针
	FGameplayEffectSpec* EffectSpec = EffectSpecHandle.Data.Get();
	// 将该效果应用到自己身上，实现主属性的初始化
	AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*EffectSpec,AbilitySystemComponent);
}

void AAuraCharacterBase::InitAbilityActorInfo()
{
	
}


