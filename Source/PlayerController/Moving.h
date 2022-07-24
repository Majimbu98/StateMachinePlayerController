// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "State.h"
#include "CoreMinimal.h"
#include "MyCharacter.h"

class AMyCharacter;

class PLAYERCONTROLLER_API Moving: public State
{
public:
	Moving();
	~Moving();

	virtual State* ControlInput(AMyCharacter& Player) override;

	virtual void Start(AMyCharacter& Player) override;
	virtual void Update(AMyCharacter& Player) override;
	virtual void Exit(AMyCharacter& Player) override;

	virtual FString GetStateName() override;
};
