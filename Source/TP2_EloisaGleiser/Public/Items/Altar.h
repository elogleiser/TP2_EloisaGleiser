// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Public/Interfaces/InteractInterface.h"
#include "Components/BoxComponent.h"
#include "Componentes/ActivacionComponent.h"
#include "Altar.generated.h"

UCLASS()
class TP2_ELOISAGLEISER_API AAltar : public AActor, public IInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAltar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	virtual void Interact_Implementation(AActor* Actor) override; 
	
	UFUNCTION()
	UActivacionComponent* GetActivationComponent() const;
	
private:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> BoxCollision;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;
	
    UPROPERTY(VisibleAnywhere)
    TObjectPtr<UActivacionComponent> ActivationComponent;
};
