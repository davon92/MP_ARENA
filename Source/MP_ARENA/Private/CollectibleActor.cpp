// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectibleActor.h"

#include "Components/CapsuleComponent.h"

// Sets default values
ACollectibleActor::ACollectibleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>("CapsuleComp");
	RootComponent = CapsuleComp;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComp");
	StaticMeshComp -> SetupAttachment(CapsuleComp);

	

}

// Called when the game starts or when spawned
void ACollectibleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACollectibleActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("Collectible Has Been Overlapped"));
	OnPlatformTriggered.Broadcast();
	Destroy();
}

// Called every frame
void ACollectibleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

