// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "MyCharacter.h"

class AMyCharacter;

class PLAYERCONTROLLER_API Idle: public State
{
public:
	Idle();

	virtual State* ControlInput(AMyCharacter& Player) override;

	virtual void Start(AMyCharacter& Player) override;
	virtual void Update(AMyCharacter& Player) override;
	virtual void Exit(AMyCharacter& Player) override;

	virtual FString GetStateName() override;

	~Idle();
};
