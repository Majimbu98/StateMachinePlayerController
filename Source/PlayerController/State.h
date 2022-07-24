// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"

class AMyCharacter;

class PLAYERCONTROLLER_API State
{
public:
	State();
	~State();
	virtual State* ControlInput(AMyCharacter& Player);

	//3 Virtual Function that each states must have
	virtual void Start(AMyCharacter& Player) = 0;
	virtual void Update(AMyCharacter& Player) = 0;
	virtual void Exit(AMyCharacter& Player) = 0;

	//Function for knowing the state name
	virtual FString GetStateName();
};
