// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


class PLAYERCONTROLLER_API Input_Controller
{
public:
	Input_Controller();
	~Input_Controller();

	void set_right_left_movement(float value);
	void set_forward_back_movement(float value);
	void set_jump_is_pressed(bool is_pressed);

	float right_left_movement;
	float forward_back_movement;
	bool jump_is_pressed;
};
