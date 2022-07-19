// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "State.h"
#include "MyCharacter.generated.h"

class State;

UCLASS()
class PLAYERCONTROLLER_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Movement
	void MoveRightLeft(float value);
	void MoveForwardBack(float value);




	//Jump Functions
	void JumpStart();
	void JumpEnd();

	//Camera Rotation
	void RotatePitch(float value);
	void RotateYaw(float value);

	//Player state
	State* mystate;

	//For Changing State
	void ChangeState(State* newstate);

	//Input Player
	UInputComponent* Input;

	//For Verify input
	void HandleInput(UInputComponent* myinput);
};
