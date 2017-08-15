// This is fucking top secret.

#include "BuildingScape.h"
#include "OpenDoor.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	// ...
	CurrentActor = GetWorld()->GetFirstPlayerController()->GetPawn();
	Owner = GetOwner();
	DefaultPosition = Owner->GetTransform();
}

void UOpenDoor::OpenDoor()
{
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (volumeTarget->IsOverlappingActor(CurrentActor)) {
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if ((LastDoorOpenTime>0) && (MoveDelay <= GetWorld()->GetTimeSeconds() - LastDoorOpenTime))
		CloseDoor();
	
}

void UOpenDoor::CloseDoor() {
	UE_LOG(LogTemp, Warning, TEXT("Clossing Door"));
	ResetDefaultState();
	
}

void UOpenDoor::ResetDefaultState()
{
	LastDoorOpenTime = 0;
	Owner->SetActorTransform(DefaultPosition);
}
