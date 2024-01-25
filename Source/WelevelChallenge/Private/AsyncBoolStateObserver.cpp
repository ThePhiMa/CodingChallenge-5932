// Fill out your copyright notice in the Description page of Project Settings.

#include "TargetActor.h"
#include "ListeningActor.h"
#include "AsyncBoolStateObserver.h"

UAsyncBoolStateObserver::UAsyncBoolStateObserver(const FObjectInitializer& objectInitializer) : Super(objectInitializer)
{ }

UAsyncBoolStateObserver* UAsyncBoolStateObserver::WaitForBoolChange(
	const UObject* worldContextObject, 
	ATargetActor* targetActor, 
	AListeningActor* listeningActor)
{
	UAsyncBoolStateObserver* asyncAction = NewObject<UAsyncBoolStateObserver>();
	asyncAction->TargetActor = targetActor;
	asyncAction->ListeningActor = listeningActor;
	asyncAction->RegisterWithGameInstance(worldContextObject);

	return asyncAction;
}

void UAsyncBoolStateObserver::Activate()
{
	Super::Activate();

	if (IsValid(TargetActor) && (IsValid(ListeningActor)))
	{
		UE_LOG(LogTemp, Log, TEXT("Adding listener to target actor."));
		TargetActor->OnBoolValueChange.AddDynamic(this, &UAsyncBoolStateObserver::OnTargetBoolValueChanged);
	}
}

void UAsyncBoolStateObserver::OnTargetBoolValueChanged(bool bNewValue)
{
	UE_LOG(LogTemp, Log, TEXT("-> OnTargetBoolValueChanged called!"));
	OnBoolValueChange.Broadcast(bNewValue);
}