// Fill out your copyright notice in the Description page of Project Settings.


#include "Jumping.h"
#include "Idle.h"
#include "Moving.h"
#include "MovingAndJumping.h"

Jumping::Jumping()
{
}

Jumping::~Jumping()
{
}

State* Jumping::ControlInput(AMyCharacter& Player)
{
	if (Player.Input->forward_back_movement != 0 || Player.Input->right_left_movement != 0)
	{
		return new MovingAndJumping;
	}
	return nullptr;
}

void Jumping::Start(AMyCharacter& Player)
{
	Player.JumpStart();
}

void Jumping::Update(AMyCharacter& Player)
{
	if (!Player.GetCharacterMovement()->IsFalling())
	{
		Player.ChangeState(new Idle);
	}
	else
	{
		Player.HandleInput();
	}
}

void Jumping::Exit(AMyCharacter& Player)
{
	Player.JumpEnd();
}

FString Jumping::GetStateName()
{
	return "Jumping";
}
