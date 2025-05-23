﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "MP_ARENA/Public/HelloWorldActor.h"


// Sets default values
AHelloWorldActor::AHelloWorldActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHelloWorldActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hello from BeginPlay!"));
}

// Called every frame
void AHelloWorldActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

