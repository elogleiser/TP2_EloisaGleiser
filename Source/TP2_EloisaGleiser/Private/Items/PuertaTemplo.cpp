// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/PuertaTemplo.h"
#include "Items/Altar.h"
#include "Componentes/ActivacionComponent.h"



// Sets default values
APuertaTemplo::APuertaTemplo()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
}

// Called when the game starts or when spawned
void APuertaTemplo::BeginPlay()
{
	Super::BeginPlay();
	
	for (AAltar* Altar : Altares)
	{
		if (Altar)
		{
			
			UActivacionComponent* AltarActivationComponent = Altar->GetActivationComponent();

			if (AltarActivationComponent)
			{
				AltarActivationComponent->OnActivationCompleted.AddDynamic(this, &APuertaTemplo::OnAltarActivado);
			}
		}
	}
}



// Called every frame
void APuertaTemplo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APuertaTemplo::OnAltarActivado()
{
	AltaresActivados++;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
		-1,2.f,FColor::Cyan,TEXT("Altares activados: ") + FString::FromInt(AltaresActivados));
	}

	if (AltaresActivados >= AltaresNecesarios)
	{
		AbrirPuertaTemplo();
	}
}

void APuertaTemplo::AbrirPuertaTemplo()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("La puerta se abrio"));
	}

	Destroy();
}

