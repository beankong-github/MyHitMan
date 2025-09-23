// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "WizardPlayerAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class MYHITMAN_API UWizardPlayerAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UWizardPlayerAttributeSet, Health);
	GAMEPLAYATTRIBUTE_VALUE_GETTER(Health);
	GAMEPLAYATTRIBUTE_VALUE_SETTER(Health);
	GAMEPLAYATTRIBUTE_VALUE_INITTER(Health);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Health;
};
