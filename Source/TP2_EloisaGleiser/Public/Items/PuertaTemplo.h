// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items/Altar.h"
#include "PuertaTemplo.generated.h"

UCLASS()
class TP2_ELOISAGLEISER_API APuertaTemplo : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APuertaTemplo();
	UFUNCTION(BlueprintCallable)
	virtual void OnAltarActivado();
	
	UFUNCTION(BlueprintCallable)
	virtual void AbrirPuertaTemplo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Puerta", meta = (AllowPrivateAccess = "true"))
	float AltaresNecesarios = 3;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Puerta", meta = (AllowPrivateAccess = "true"))
	float AltaresActivados= 0;
	
	UPROPERTY(EditAnywhere, Category="Puerta", meta = (AllowPrivateAccess = "true"))
	TArray<TObjectPtr<AAltar>> Altares;
	
	
};
