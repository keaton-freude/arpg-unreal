#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AnchorPointComponent.generated.h"

//USTRUCT()
//struct FAnchorPointDetails
//{
//	GENERATED_BODY()
//public:
//	UPROPERTY(EditAnywhere)
//	UClass* Connector;
//
//	UPROPERTY(EditAnywhere)
//	bool IsConnectorEntrance;
//};


UCLASS( ClassGroup=(MapGeneration), meta=(BlueprintSpawnableComponent) )
class ARPG_API UAnchorPointComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAnchorPointComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	TArray<UClass*> ValidMeshes;
	
	UPROPERTY(EditAnywhere)
	bool IsRoom;

	UPROPERTY(EditAnywhere)
	bool IsConnectorEntrance;
};
