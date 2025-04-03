// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpBase.h"

#include "Components/SphereComponent.h"


// Sets default values
APowerUpBase::APowerUpBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;
	Collision->SetCollisionProfileName("OverlapAllDynamic");
	Collision->OnComponentBeginOverlap.AddDynamic(this, &APowerUpBase::OnOverlapBegin);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	
	
}

// Called when the game starts or when spawned
void APowerUpBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerUpBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APowerUpBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,bool bFromSweep, const FHitResult& SweepResult)
{
	// Basic interaction — override in BP or subclasses
	UE_LOG(LogTemp, Warning, TEXT("PowerUp picked up by: %s"), *OtherActor->GetName());
	Destroy();
}

