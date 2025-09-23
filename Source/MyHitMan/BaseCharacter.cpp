// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "BaseCharacterAttributeSet.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("ASC"));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
    ApplyAttributeTables();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::ApplyAttributeTables()
{
    if (!ASC) return;

    // 권장: 서버에서만 초기화 (속성 복제는 ASC가 해줌)
    if (!HasAuthority()) return;
    
    for (const FAttributeSetInitTable& Item : AttributeInitTables)
    {
        if (!Item.AttributeSetClass || !Item.InitDataTable) continue;
    
        // 세트가 없으면 생성
        if (!ASC->GetAttributeSet(Item.AttributeSetClass))
        {
            UAttributeSet* NewSet = NewObject<UAttributeSet>(this, Item.AttributeSetClass);
            ASC->AddAttributeSetSubobject(NewSet);
        }
    
        // DT 적용 (RowStruct=AttributeMetaData 필수)
        ASC->InitStats(Item.AttributeSetClass, Item.InitDataTable);
    }
}

