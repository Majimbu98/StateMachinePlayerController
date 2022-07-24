// Fill out your copyright notice in the Description page of Project Settings.


#include "Input_Controller.h"

Input_Controller::Input_Controller()
{
	right_left_movement = 0;
	forward_back_movement = 0;
	jump_is_pressed = false;
}

Input_Controller::~Input_Controller()
{
}

void Input_Controller::set_right_left_movement(float value)
{
	this->right_left_movement = value;
}

void Input_Controller::set_forward_back_movement(float value)
{
	this->forward_back_movement = value;
}

void Input_Controller::set_jump_is_pressed(bool is_pressed)
{
	this->jump_is_pressed = is_pressed;
}
