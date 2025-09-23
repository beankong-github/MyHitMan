// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

USTRUCT(BlueprintType)
struct FAttributeSetInitTable
{
	GENERATED_BODY()


	// 어떤 AttributeSet인가
	UPROPERTY(EditAnywhere, Category = "GAS")
	TSubclassOf<class UAttributeSet> AttributeSetClass;

	// 그 세트의 초기값/Min/Max 등을 담은 DataTable (RowStruct=AttributeMetaData)
	UPROPERTY(EditAnywhere, Category = "GAS",
		meta = (AllowedClasses = "DataTable",
			RowType = "/Script/GameplayAbilities.AttributeMetaData"))
	TObjectPtr<class UDataTable> InitDataTable = nullptr;

};

UCLASS()
class MYHITMAN_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void ApplyAttributeTables();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	TObjectPtr<class UAbilitySystemComponent> ASC;

	UPROPERTY(EditAnywhere, Category = "GAS")
	TArray<FAttributeSetInitTable> AttributeInitTables;
};
