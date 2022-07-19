// Fill out your copyright notice in the Description page of Project Settings.


#include "Idle.h"
#include "Jumping.h"
#include "Moving.h"

Idle::Idle()
{
}

State* Idle::ControlInput(AMyCharacter& Player, UInputComponent* Input)
{
	if ((Input->GetAxisValue("Jump")) == 1.0f)
	{
		return new Jumping;
	}

	if (Input->GetAxisKeyValue("Forward/Back") != 0 || Input->GetAxisKeyValue("Right/Left") != 0 )
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
	Player.HandleInput(Player.Input);
}

void Idle::Exit(AMyCharacter& Player)
{
}

FString Idle::GetStateName()
{
	return TEXT("Idle");
}

Idle::~Idle()
{
}
