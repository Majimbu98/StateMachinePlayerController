// Fill out your copyright notice in the Description page of Project Settings.


#include "State.h"


State::State()
{
}

State* State::ControlInput(AMyCharacter& Player)
{
	return nullptr;
}

FString State::GetStateName()
{
	return TEXT("General State");
}

State::~State()
{
}
