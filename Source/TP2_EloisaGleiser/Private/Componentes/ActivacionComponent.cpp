// Fill out your copyright notice in the Description page of Project Settings.


#include "Componentes/ActivacionComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Engine/Engine.h"


// Sets default values for this component's properties
UActivacionComponent::UActivacionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UActivacionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActivacionComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UActivacionComponent::ComenzarActivacion()
{
	if (bActivado || bEnProceso)
	{
		return;
	}
	bEnProceso = true;
	GetWorld()->GetTimerManager().SetTimer(TimerActivacion, this, &UActivacionComponent::FinalizarActivacion,TiempoActivacion,false);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("Comenzando activacion"));
	}
	
}

void UActivacionComponent::FinalizarActivacion()
{
	bEnProceso = false;
	bActivado = true;
	
	OnActivationCompleted.Broadcast();
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Activacion completada"));
	}
}

