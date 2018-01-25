// Fill out your copyright notice in the Description page of Project Settings.

#include "TestLevelScriptActor.h"
#include "AnchorPointComponent.h"

void ATestLevelScriptActor::GenerateLevel(UClass * rootClass)
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

	auto world = GetWorld();
	AActor* root = world->SpawnActor(rootClass);

	TArray<UAnchorPointComponent*> rootAnchors;

	root->GetComponents(rootAnchors);

	for (auto rootAnchor : rootAnchors)
	{
		UE_LOG(LogTemp, Display, TEXT("Found one!"));

		// grab a valid mesh
		auto randomNum = FMath::RandRange(0, rootAnchor->ValidMeshes.Num() - 1);

		UClass* connectorMesh = rootAnchor->ValidMeshes[randomNum];

		AActor* connector = world->SpawnActor(connectorMesh);

		// from that mesh, find it's anchors. We're looking for an anchor marked as an entrance
		TArray<UAnchorPointComponent*> subAnchors;
		connector->GetComponents(subAnchors);

		for (auto subAnchor : subAnchors)
		{
			if (subAnchor->IsConnectorEntrance)
			{
				// This is an appropriate anchor for us to attach the current rootAnchor to
				FVector pos = (rootAnchor->GetComponentLocation() - connector->GetActorLocation()) -
					(subAnchor->GetComponentLocation() - connector->GetActorLocation());
				//pos += FVector(1000.0f, 0.0f, 0.0f);
				// try spawn
				FTransform transform;
				transform.SetLocation(pos);
				connector->SetActorTransform(transform);
			}
		}

		//auto transform = rootAnchor->GetRelativeTransform();
		//auto connector = world->SpawnActor(rootAnchor->AcceptableConnectors[randomNum], &transform);
	}
}
