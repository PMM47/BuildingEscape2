// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	APlayerController* playerController_ptr = nullptr;
	

	// Called when the game starts
	virtual void BeginPlay() override;

	void setupInputComponent();

	void findPhysicsHandleComponent();

	FVector getReachLineEnd();
	FVector getReachLineStart();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
private:
	float reach = 100.f;
	UPROPERTY(EditAnywhere)
	float maxMass = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* inputComponent = nullptr;
	

	// Ray-cast and grab what's in reach
	void Grab();
	void Release();

	FHitResult getFirstPhysicsBodyInReach();

	void drawDebugLine(FVector playerViewPointLocation, FVector lineTraceEnd);

	

	
};
