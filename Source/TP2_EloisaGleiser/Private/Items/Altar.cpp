// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Items/Altar.h"

#include "Components/SphereComponent.h"


// Sets default values
AAltar::AAltar()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	RootComponent = BoxCollision;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
	BoxCollision->SetLineThickness(5);
	BoxCollision->SetBoxExtent(FVector(150.0f, 150.0f, 150.0f));
	BoxCollision->SetHiddenInGame(false);
	
	ActivationComponent = CreateDefaultSubobject<UActivacionComponent>(TEXT("ActivationComponent"));
}

// Called when the game starts or when spawned
void AAltar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAltar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAltar::Interact_Implementation(AActor* Actor)
{
	if (ActivationComponent)
	{
		ActivationComponent->ComenzarActivacion();
	}
}

UActivacionComponent* AAltar::GetActivationComponent() const
{
	return ActivationComponent;
}

