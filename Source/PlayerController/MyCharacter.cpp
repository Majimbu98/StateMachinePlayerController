// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include "PlayerControllerGameModeBase.h"
#include "Idle.h"
#include "Jumping.h"
#include "Moving.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	mystate = new Idle;

	mystate->Start(*this);

	Input = new Input_Controller;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	mystate = new Idle;

	mystate->Start(*this);

	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//For printing string name of the current state
	this->PrintState(mystate->GetStateName());

	mystate->Update(*this);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Rotating Camera
	InputComponent->BindAxis("Up/DownRotation", this, &AMyCharacter::RotatePitch);
	InputComponent->BindAxis("LateralRotation", this, &AMyCharacter::RotateYaw);

	//Those functions are called into state's state machine

	//Jump
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::PressJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::ReleaseJump);

	//Movement
	InputComponent->BindAxis("Right/Left", this, &AMyCharacter::RightLeftMovement);
	InputComponent->BindAxis("Forward/Back", this, &AMyCharacter::ForwardBackMovement);

	//Save Input Variab
	//UInputComponent* Input = PlayerInputComponent;
}

void AMyCharacter::RotatePitch(float value)
{
	AddControllerPitchInput(value);
}

void AMyCharacter::RotateYaw(float value)
{
	AddControllerYawInput(value);
}

void AMyCharacter::PressJump()
{
	Input->set_jump_is_pressed(true);
}

void AMyCharacter::ReleaseJump()
{
	Input->set_jump_is_pressed(false);
}

void AMyCharacter::ForwardBackMovement(float value)
{
	Input->set_forward_back_movement(value);
}

void AMyCharacter::RightLeftMovement(float value)
{
	Input->set_right_left_movement(value);
}


void AMyCharacter::MoveRightLeft(float value)
{
	if (value)
	{
		AddMovementInput(GetActorRightVector(), value);
	}
}

void AMyCharacter::MoveForwardBack(float value)
{
	if (value)
	{
		AddMovementInput(GetActorForwardVector(), value);
	}
}

void AMyCharacter::HandleInput()
{
	State* newstate = mystate->ControlInput(*this);
	if (newstate != nullptr)
	{
		this->ChangeState(newstate);
	}
}

void AMyCharacter::PrintState(const FString State)
{
	wchar_t* currentstate = TCHAR_TO_WCHAR(*State);
	GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Black, FString::Printf(TEXT("State: %s"), currentstate));
}

void AMyCharacter::ChangeState(State* newstate)
{
	mystate->Exit(*this);
	delete mystate;
	mystate = newstate;
	mystate->Start(*this);
}

void AMyCharacter::JumpStart()
{
	this->bPressedJump = true;
}

void AMyCharacter::JumpEnd()
{
	this->bPressedJump = false;
}