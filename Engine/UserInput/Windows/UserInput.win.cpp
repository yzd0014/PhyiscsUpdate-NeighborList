// Includes
//=========

#include "../UserInput.h"

#include <Engine/Windows/Includes.h>
#include "Engine/UserOutput/UserOutput.h"
#include <iostream>
#include "Winuser.h"
// Interface
//==========
//right now this function only works for middle mouse button 
bool eae6320::UserInput::IsKeyEdgeTriggered(const uint_fast8_t i_keyCode) {
	bool currentState = IsKeyPressed(i_keyCode);
	bool output = false;
	//index 0: left mouse button, 1: middle mouse button, 2: right mouse button, 3: space bar
	if (i_keyCode == KeyCodes::MiddleMouseButton) {
		if (KeyState::lastFrameKeyState[1] == 0 && currentState) {
			output = true;
		}
		if (currentState) {
			KeyState::lastFrameKeyState[1] = 1;
		}
		else {
			KeyState::lastFrameKeyState[1] = 0;
		}
	}
	else if (i_keyCode == KeyCodes::Space) {
		if (KeyState::lastFrameKeyState[3] == 0 && currentState) {
			output = true;
		}
		if (currentState) {
			KeyState::lastFrameKeyState[3] = 1;
		}
		else {
			KeyState::lastFrameKeyState[3] = 0;
		}
	}
	
	return output;
}

bool eae6320::UserInput::IsKeyPressed( const uint_fast8_t i_keyCode )
{
	const auto keyState = GetAsyncKeyState( i_keyCode );
	const short isKeyDownMask = ~1;
	return ( keyState & isKeyDownMask ) != 0;
}

double eae6320::UserInput::GetMouseXVelocity() {
	int xDistance;
	POINT screenPos[1];
	GetCursorPos(screenPos);
	if (MouseMovement::xPosCached < 0) {
		xDistance = 0;
	}
	else {
		xDistance = (int)screenPos[0].x - MouseMovement::xPosCached;
		/*
		if (abs(xDistance) > 600) {
			eae6320::UserOutput::DebugPrint("wrong");
		}
		*/
	}
	MouseMovement::xPosCached = (int)screenPos[0].x;
	
	//eae6320::UserOutput::DebugPrint("%d", xDistance);
	return xDistance / MouseMovement::elapsedSeconds;
}

double eae6320::UserInput::GetMouseYVelocity() {
	int yDistance;
	POINT screenPos[1];
	GetCursorPos(screenPos);
	if (MouseMovement::yPosCached < 0) {
		yDistance = 0;
	}
	else {
		yDistance = (int)screenPos[0].y - MouseMovement::yPosCached;
	
	}
	MouseMovement::yPosCached = (int)screenPos[0].y;

	//eae6320::UserOutput::DebugPrint("%d", xDistance);
	return -1 * yDistance / MouseMovement::elapsedSeconds;
}

void eae6320::UserInput::ClampCursorPosition() {
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	POINT screenPos[1];
	GetCursorPos(screenPos);
	int currentX, currentY;
	currentX = (int)screenPos[0].x;
	currentY = (int)screenPos[0].y;
	//clamp for x
	if (currentX > screenWidth - 5) {
		SetCursorPos(5, currentY);
		currentX = 5;
		
		MouseMovement::xPosCached = currentX;
		MouseMovement::yPosCached = currentY;
	}
	if (currentX < 5) {
		SetCursorPos(screenWidth - 5, currentY);
		currentX = screenWidth - 5;
		
		MouseMovement::xPosCached = currentX;
		MouseMovement::yPosCached = currentY;
	}

	//clamp for y
	if (currentY > screenHeight - 5) {
		SetCursorPos(currentX, 5);
		currentY = 5;

		MouseMovement::xPosCached = currentX;
		MouseMovement::yPosCached = currentY;
	}
	if (currentY < 5) {
		SetCursorPos(currentX, screenHeight - 5);
		currentY = screenHeight - 5;

		MouseMovement::xPosCached = currentX;
		MouseMovement::yPosCached = currentY;
	}
}