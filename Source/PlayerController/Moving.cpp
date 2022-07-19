// Fill out your copyright notice in the Description page of Project Settings.


#include "Moving.h"
#include "Idle.h"
#include "MovingAndJumping.h"

Moving::Moving()
{
}

Moving::~Moving()
{
}

State* Moving::ControlInput(AMyCharacter& Player, UInputComponent* Input)
{

	if ((Input->GetAxisKeyValue("Forward/Back") == 0) && (Input->GetAxisKeyValue("Right/Left") == 0))
	{
		return new Idle;
	}

	if (Input->GetAxisValue("Jump") == 1.0f)
	{
		return new MovingAndJumping;
	}

	return nullptr;
}

void Moving::Start(AMyCharacter& Player)
{
	if (Player.Input->GetAxisKeyValue("Forward/Back") != 0)
	{
		Player.MoveForwardBack(Player.Input->GetAxisKeyValue("Forward/Back"));
	}

	if (Player.Input->GetAxisKeyValue("Right/Left") != 0)
	{
		Player.MoveRightLeft(Player.Input->GetAxisKeyValue("Right/Left"));
	}
}

void Moving::Update(AMyCharacter& Player)
{

	if (Player.Input->GetAxisKeyValue("Forward/Back") != 0)
	{
		Player.MoveForwardBack(Player.Input->GetAxisKeyValue("Forward/Back"));
	}

	if (Player.Input->GetAxisKeyValue("Right/Left") != 0)
	{
		Player.MoveRightLeft(Player.Input->GetAxisKeyValue("Right/Left"));
	}

	Player.HandleInput(Player.Input);
}

void Moving::Exit(AMyCharacter& Player)
{
	
}

FString Moving::GetStateName()
{
	return TEXT("Moving");
}