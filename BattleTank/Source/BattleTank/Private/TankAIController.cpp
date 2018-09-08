// Copyright Dan Paddock

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

		// Move Towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm
		// Aim towards the player
		// Fire when ready
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

	//	ControlledTank->Fire();
}

