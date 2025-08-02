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

void AAuraCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes,1);
	ApplyEffectToSelf(DefaultSecondaryAttributes,1);
}

void AAuraCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> Effect, int level) const
{
	// 验证能力系统组件和效果类是否有效
	check(IsValid(AbilitySystemComponent));
	check(IsValid(Effect));
	
	// 1. 创建效果上下文（记录效果来源信息）
	FGameplayEffectContextHandle EffectContextHandle = AbilitySystemComponent->MakeEffectContext();
	// 设置效果来源为当前角色
	EffectContextHandle.AddSourceObject(this); 
	
	// 2. 根据效果类、等级和上下文创建具体的效果规格
	FGameplayEffectSpecHandle EffectSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(Effect, level, EffectContextHandle);
	// 获取效果规格的原始指针
	FGameplayEffectSpec* EffectSpec = EffectSpecHandle.Data.Get();
	
	// 3. 将配置好的效果应用到自己身上
	AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*EffectSpec,AbilitySystemComponent);
}

void AAuraCharacterBase::InitAbilityActorInfo()
{
	
}

