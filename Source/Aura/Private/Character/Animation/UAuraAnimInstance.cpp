#include "Character/Animation/UAuraAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Character/AuraCharacter.h"  // 你自定义的角色类
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

void UAuraAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    // 这里你可以缓存角色指针（可选）
    APawn* OwnerPawn = TryGetPawnOwner();
    if (OwnerPawn)
    {
        CachedAuraCharacter = Cast<AAuraCharacter>(OwnerPawn);
        if (CachedAuraCharacter)
        {
            AuraMovementComponent=CachedAuraCharacter->GetCharacterMovement();
        }
    }
}

void UAuraAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    if (!CachedAuraCharacter)
    {
        CachedAuraCharacter = Cast<AAuraCharacter>(TryGetPawnOwner());
        if (!CachedAuraCharacter) return;
    }

    //现在你可以从 AuraCharacter 拉取状态变量了
    FVector Velocity = AuraMovementComponent->Velocity;
    GroundSpeed = UKismetMathLibrary::VSizeXY(Velocity);
    // UE_LOG(LogTemp, Warning, TEXT("GroundSpeed: %f"), GroundSpeed);
    bIsInAir = CachedAuraCharacter->GetMovementComponent()->IsFalling();
    
}
