// Fill out your copyright notice in the Description page of Project Settings.


#include "WizardPlayer.h"
#include"WizardPlayerAttributeSet.h"

// Sets default values
AWizardPlayer::AWizardPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("ASC"));
	//CharacterAttributeSet = CreateDefaultSubobject<UABCharacterAttributeSet>(TEXT("CharacterAttributeSet"));
	//ASC->AddAttributeSetSubobject<UABCharacterAttributeSet>(CharacterAttributeSet);
}

// Called when the game starts or when spawned
void AWizardPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWizardPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWizardPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

