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

State* Moving::ControlInput(AMyCharacter& Player)
{
	
	if ((Player.Input->forward_back_movement == 0) && (Player.Input->right_left_movement == 0))
	{
		return new Idle;
	}

	if (Player.Input->jump_is_pressed)
	{
		return new MovingAndJumping;
	}

	return nullptr;
}

void Moving::Start(AMyCharacter& Player)
{
	if (Player.Input->forward_back_movement != 0)
	{
		Player.MoveForwardBack(Player.Input->forward_back_movement);
	}

	if (Player.Input->right_left_movement != 0)
	{
		Player.MoveRightLeft(Player.Input->right_left_movement);
	}
}

void Moving::Update(AMyCharacter& Player)
{

	if (Player.Input->forward_back_movement != 0)
	{
		Player.MoveForwardBack(Player.Input->forward_back_movement);
	}

	if (Player.Input->right_left_movement != 0)
	{
		Player.MoveRightLeft(Player.Input->right_left_movement);
	}

	Player.HandleInput();
}

void Moving::Exit(AMyCharacter& Player)
{
	
}

FString Moving::GetStateName()
{
	return "Moving";
}