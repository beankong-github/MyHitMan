// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseCharacterAttributeSet.generated.h"

UCLASS()
class MYHITMAN_API UBaseCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UBaseCharacterAttributeSet();

	ATTRIBUTE_ACCESSORS_BASIC(UBaseCharacterAttributeSet, Health)

	ATTRIBUTE_ACCESSORS_BASIC(UBaseCharacterAttributeSet, Damage)

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Damage;

};
