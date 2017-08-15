// This is fucking top secret.

#include "BuildingScape.h"
#include "Grabber.h"
#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("GrabberReportingForDutty"));
	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector PlayerViewLocation;
	FRotator PlayerViewRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewLocation, PlayerViewRotation);
	/*UE_LOG(LogTemp, Error, TEXT("Player Location Vector: %s \nPlayer Rotation %s"),
		*PlayerViewLocation.ToString(),
		*PlayerViewRotation.ToString());
	*/
	/// For Debugging
	FVector VariableDistance(40.f, 40.f, 40.f);
	FVector LineTraceEnd = PlayerViewLocation + VariableDistance * PlayerViewRotation.Vector();
	DrawDebugLine(GetWorld(), PlayerViewLocation, LineTraceEnd, FColor(255, 0, 0), false, 0.f, 0.f, 2.f);


	/// Create a Query for lienTraceSingleByObjectType
	FCollisionQueryParams QueryParams(FName(TEXT("")), false, GetOwner());
	/// Call LineTraceSingleByObjectType to check the hit method event
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		QueryParams
	);

	AActor* HittedActor = Hit.GetActor();
	if (HittedActor)
	{
		UE_LOG(LogTemp, Error, TEXT("Collision with the object: %s"),
			*HittedActor->GetName());
	}
}

