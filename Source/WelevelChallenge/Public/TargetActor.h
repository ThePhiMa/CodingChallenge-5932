// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Net/UnrealNetwork.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBoolValueChange, const bool, bNewValue);

UCLASS()
class WELEVELCHALLENGE_API ATargetActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATargetActor();

	FOnBoolValueChange OnBoolValueChange;

	UFUNCTION(Server, Reliable)
	void Die();

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void LoseLife(int lifeAmount);

	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable)
	int GetLifesRemaining() { return lifes; }

	UFUNCTION(BlueprintCallable)
	bool IsDead() { return bIsDead; }

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(Replicated)
	bool bIsDead = false;

	UPROPERTY(Replicated)
	int lifes = 100;
};
