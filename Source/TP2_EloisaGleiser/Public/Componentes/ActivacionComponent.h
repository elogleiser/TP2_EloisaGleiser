// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActivacionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActivationCompleted);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TP2_ELOISAGLEISER_API UActivacionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UActivacionComponent();
	
	UFUNCTION(BlueprintCallable)
	void ComenzarActivacion();
	
	UFUNCTION(BlueprintCallable)
	void FinalizarActivacion();
	
	UPROPERTY(BlueprintAssignable)
	FOnActivationCompleted OnActivationCompleted;//delegate

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Activacion", meta = (AllowPrivateAccess = "true"))
	bool bActivado = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Activacion", meta = (AllowPrivateAccess = "true"))
	bool bEnProceso = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Activacion", meta = (AllowPrivateAccess = "true"))
	float TiempoActivacion = 2.0f;
	
	
	FTimerHandle TimerActivacion;
	
};
