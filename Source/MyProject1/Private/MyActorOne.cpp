// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorOne.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyActorOne::AMyActorOne()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActorOne::BeginPlay()
{
	Super::BeginPlay();
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message from C++ project!"));
}

// Called every frame
void AMyActorOne::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->PrintDistanceToPlayer();
}

void AMyActorOne::PrintDistanceToPlayer()
{
	// get player location
	FVector characterPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	// get actor location
	FVector actorLocation = this->GetActorLocation();

	// calculate distance
	float distance = FVector::Dist(characterPosition, actorLocation);

	FString text = FString::Printf(TEXT("Distance from player to actor = %f"), distance);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, text);
}