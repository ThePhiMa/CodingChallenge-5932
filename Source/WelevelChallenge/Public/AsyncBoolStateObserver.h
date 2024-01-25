// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncBoolStateObserver.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetBoolValueChange, const bool, bNewValue);

class ATargetActor;
class AListeningActor;

/**
 * 
 */
UCLASS()
class WELEVELCHALLENGE_API UAsyncBoolStateObserver : public UBlueprintAsyncActionBase
{
	GENERATED_UCLASS_BODY()

public:
	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
	//~UBlueprintAsyncActionBase interface

	UPROPERTY(BlueprintAssignable)
	FOnTargetBoolValueChange OnBoolValueChange;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", DefaultToSelf = "listeningActor", WorldContext = "worldContextObject"), Category = "Game Logic|Observer")
	static UAsyncBoolStateObserver* WaitForBoolChange(
		const UObject* worldContextObject,
		ATargetActor* targetActor,
		AListeningActor* listeningActor);
	
	UPROPERTY()
	ATargetActor* TargetActor;

	UPROPERTY()
	AListeningActor* ListeningActor;

	UFUNCTION()
	void OnTargetBoolValueChanged(bool bNewValue);
};
