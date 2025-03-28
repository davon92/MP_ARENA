// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectibleActor.generated.h"

class UStaticMeshComponent;
class UCapsuleComponent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateTrigger);
UCLASS()
class MP_ARENA_API ACollectibleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectibleActor();

protected:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* CapsuleComp;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintAssignable)
	FDelegateTrigger OnPlatformTriggered;
};
