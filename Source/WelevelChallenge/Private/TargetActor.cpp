// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetActor.h"

ATargetActor::ATargetActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ATargetActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATargetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATargetActor::Die_Implementation()
{
	bIsDead = true;
	OnBoolValueChange.Broadcast(bIsDead);
}

void ATargetActor::LoseLife_Implementation(int lifeAmount)
{
	if (lifes <= 0) return;

	lifes -= lifeAmount;

	if (lifes <= 0)
		Die();
}

void ATargetActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATargetActor, bIsDead);
	DOREPLIFETIME(ATargetActor, lifes);
}