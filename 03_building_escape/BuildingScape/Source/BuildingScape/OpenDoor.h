// This is fucking top secret.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGSCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();
	void ResetDefaultState();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.0f;
	
	UPROPERTY(EditAnywhere)
	float MoveDelay= 4.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* volumeTarget;

	//UPROPERTY(EditAnywhere)
	AActor* CurrentActor; //pawn inherits from AActor
	AActor* Owner;
	float LastDoorOpenTime;
	FTransform DefaultPosition;

};
