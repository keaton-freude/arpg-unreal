// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "Classes/Engine/World.h"
#include "TestLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class ARPG_API ATestLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString TestString;


	
protected:
	UFUNCTION(BlueprintCallable, Category = LevelBlueprint)
	void GenerateLevel(UClass* rootClass);
	
};
