// Fill out your copyright notice in the Description page of Project Settings.

#include "RPGCharacter.h"
#include "GAS/RPGAttributeSet.h"

// Sets default values
ARPGCharacter::ARPGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialise Ability System Component
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	// Initialise Attribute Set
	AttributeSet = CreateDefaultSubobject<URPGAttributeSet>(TEXT("AttributeSet"));

	// Set Character Level
	CharacterLevel = 1;
}

int32 ARPGCharacter::GetCharacterLevel() const
{
	return CharacterLevel;
}

float ARPGCharacter::GetHealth() const
{
	if(!AttributeSet) { return 0.0f; }

	return AttributeSet->GetHealth();
}

float ARPGCharacter::GetMaxHealth() const
{
	if(!AttributeSet) { return 0.0f; }

	return AttributeSet->GetMaxHealth();
}

float ARPGCharacter::GetStamina() const
{
	if(!AttributeSet) { return 0.0f; }

	return AttributeSet->GetStamina();
}

float ARPGCharacter::GetMaxStamina() const
{
	if(!AttributeSet) { return 0.0f; }

	return AttributeSet->GetMaxStamina();
}

float ARPGCharacter::GetAdrenaline() const
{
	if(!AttributeSet) { return 0.0f; }

	return AttributeSet->GetAdrenaline();
}

float ARPGCharacter::GetMaxAdrenaline() const
{
	if(!AttributeSet) { return 0.0f; }

	return AttributeSet->GetMaxAdrenaline();
}

float ARPGCharacter::GetExperiencePoints() const
{
	if(!AttributeSet) { return 0.0f; }

	return AttributeSet->GetExperiencePoints();
}

float ARPGCharacter::GetMaxExperiencePoints() const
{
	if(!AttributeSet) { return 0.0f; }

	return AttributeSet->GetMaxExperiencePoints();
}

// Called when the game starts or when spawned
void ARPGCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARPGCharacter::SetTestAbilities()
{
	if(!AbilitySystemComponent) { return; }

	if(GetLocalRole() == ROLE_Authority)
	{
		for (TSubclassOf<UGameplayAbility>& TestAbility : TestAbilities)
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(TestAbility, GetCharacterLevel(), INDEX_NONE, this));
		}
	}
}

// Called every frame
void ARPGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARPGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ARPGCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if(!AbilitySystemComponent) { return; }

	SetTestAbilities();

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	FGameplayEffectSpecHandle NewHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffects, CharacterLevel, EffectContext);
	
	if(NewHandle.IsValid())
	{
		FActiveGameplayEffectHandle ActiveHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*NewHandle.Data.Get(), AbilitySystemComponent);
	}
}

UAbilitySystemComponent* ARPGCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

