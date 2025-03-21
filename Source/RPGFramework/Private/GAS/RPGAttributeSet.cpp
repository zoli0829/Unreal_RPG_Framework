// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/RPGAttributeSet.h"
#include "Net/UnrealNetwork.h"

URPGAttributeSet::URPGAttributeSet()
{
	
}

void URPGAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME(URPGAttributeSet, Health);
	DOREPLIFETIME(URPGAttributeSet, MaxHealth);
	DOREPLIFETIME(URPGAttributeSet, Stamina);
	DOREPLIFETIME(URPGAttributeSet, MaxStamina);
	DOREPLIFETIME(URPGAttributeSet, Adrenaline);
	DOREPLIFETIME(URPGAttributeSet, MaxAdrenaline);
	DOREPLIFETIME(URPGAttributeSet, ExperiencePoints);
	DOREPLIFETIME(URPGAttributeSet, MaxExperiencePoints);
}

void URPGAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

void URPGAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void URPGAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Health, OldHealth);
}

void URPGAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxHealth, OldMaxHealth);
}

void URPGAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Stamina, OldStamina);
}

void URPGAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxStamina, OldMaxStamina);
}

void URPGAttributeSet::OnRep_Adrenaline(const FGameplayAttributeData& OldAdrenaline)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, Adrenaline, OldAdrenaline);
}

void URPGAttributeSet::OnRep_MaxAdrenaline(const FGameplayAttributeData& OldMaxAdrenaline)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxAdrenaline, OldMaxAdrenaline);
}

void URPGAttributeSet::OnRep_ExperiencePoints(const FGameplayAttributeData& OldExperiencePoints)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, ExperiencePoints, OldExperiencePoints);
}

void URPGAttributeSet::OnRep_MaxExperiencePoints(const FGameplayAttributeData& OldMaxExperiencePoints)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URPGAttributeSet, MaxExperiencePoints, OldMaxExperiencePoints);
}
