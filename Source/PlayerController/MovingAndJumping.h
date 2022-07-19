// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "State.h"
#include "CoreMinimal.h"

/**
 * 
 */
class PLAYERCONTROLLER_API MovingAndJumping: public State
{
public:
	MovingAndJumping();
	~MovingAndJumping();

	virtual State* ControlInput(AMyCharacter& Player, UInputComponent* Input) override;

	virtual void Start(AMyCharacter& Player) override;
	virtual void Update(AMyCharacter& Player) override;
	virtual void Exit(AMyCharacter& Player) override;

	virtual FString GetStateName() override;
};
