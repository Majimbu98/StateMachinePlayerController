// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingAndJumping.h"

MovingAndJumping::MovingAndJumping()
{
}

MovingAndJumping::~MovingAndJumping()
{
}

State* MovingAndJumping::ControlInput(AMyCharacter& Player)
{
	/*
	if (Player.Input->forward_back_movement != 0)
	{
		Player.MoveForwardBack(Player.Input->forward_back_movement);
	}

	if (Player.Input->right_left_movement != 0)
	{
		Player.MoveRightLeft(Player.Input->right_left_movement);
	}

	if (!Player.GetCharacterMovement()->IsFalling())
	{
		Player.ChangeState(new Idle);
	}
	else
	{
		Player.HandleInput();
	}

	*/

	return nullptr;
}

void MovingAndJumping::Start(AMyCharacter& Player)
{
}

void MovingAndJumping::Update(AMyCharacter& Player)
{

	
}

void MovingAndJumping::Exit(AMyCharacter& Player)
{

}

FString MovingAndJumping::GetStateName()
{
	return "MovingAndJumping";
}