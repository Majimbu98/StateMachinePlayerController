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

State* Jumping::ControlInput(AMyCharacter& Player, UInputComponent* Input)
{
	if (Input->GetAxisKeyValue("Forward/Back") != 0 || Input->GetAxisKeyValue("Right/Left") != 0)
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
		Player.HandleInput(Player.Input);
	}
}

void Jumping::Exit(AMyCharacter& Player)
{
	Player.JumpEnd();
}

FString Jumping::GetStateName()
{
	return TEXT("Jumping");
}
