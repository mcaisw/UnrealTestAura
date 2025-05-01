#pragma once


#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"   // 其他头文件放前面
#include "UAuraAnimInstance.generated.h"  // ✅ 必须是最后一个 include

class UCharacterMovementComponent;
class AAuraCharacter;

UCLASS()
class AURA_API UAuraAnimInstance : public UAnimInstance
{
    GENERATED_BODY()

public:
    virtual void NativeInitializeAnimation() override;
    virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
    UPROPERTY(BlueprintReadOnly, Category = "Movement")
    float GroundSpeed;

    UPROPERTY(BlueprintReadOnly, Category = "Movement")
    bool bIsInAir;

private:
    UPROPERTY()
    AAuraCharacter* CachedAuraCharacter;
    
    UCharacterMovementComponent* AuraMovementComponent;
};

