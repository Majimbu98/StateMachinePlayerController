// Fill out your copyright notice in the Description page of Project Settings.


#include "Idle.h"
#include "Jumping.h"
#include "Moving.h"

Idle::Idle()
{
}

State* Idle::ControlInput(AMyCharacter& Player)
{
	if ((Player.Input->jump_is_pressed))
	{
		return new Jumping;
	}

	if ((Player.Input->forward_back_movement != 0) || (Player.Input->right_left_movement != 0 ))
	{
		return new Moving;
	}

	return nullptr;
}

void Idle::Start(AMyCharacter& Player)
{
}

void Idle::Update(AMyCharacter& Player)
{
	Player.HandleInput();
}

void Idle::Exit(AMyCharacter& Player)
{
}

FString Idle::GetStateName()
{
	return "Idle";
}

Idle::~Idle()
{
}
