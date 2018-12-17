#include "Boss.h"
#include "Bullet.h"
#include "HomingCube.h"
#include "MyGame/cMyGame.h"
#include "Engine/UserInput/UserInput.h"
void eae6320::Boss::EventTick(const float i_secondCountToIntegrate) {
	//Time::ConvertTicksToSeconds(Time::GetCurrentSystemTimeTickCount());
	
	if (timeLastShot == 0 || Time::ConvertTicksToSeconds(Time::GetCurrentSystemTimeTickCount()) - timeLastShot > shootingInterval) {
		timeLastShot = (float)Time::ConvertTicksToSeconds(Time::GetCurrentSystemTimeTickCount());

		UserOutput::DebugPrint("Number of red boxes: %d", numOfMissleLaunched);
		/*
		Physics::sRigidBodyState objState;
		objState.boundingBox.center = Math::sVector(0.0f, 0.0f, 0.0f);
		objState.boundingBox.extends = Math::sVector(0.5f, 0.5f, 0.5f);
		objState.position = m_State.position;
		objState.axis_Z_velocity = 30;

		missleVelocity = rotationDuringInterval * missleVelocity;
		objState.velocity = missleVelocity;


		HomingCube * pGameObject = new HomingCube(m_myGame->masterEffectArray[4], m_myGame->masterMeshArray[8], objState);
		strcpy_s(pGameObject->objectType, "Missile");
		pGameObject->m_target = m_myGame->masterGameObjectArr[0];
		m_myGame->masterGameObjectArr.push_back(pGameObject);
		numOfMissleLaunched++;
		*/
	}
	/*
	if (numOfMissleLaunched > 10 && numOfMissleLaunched <= 20) {
		shootingInterval = 1.0f;
	}
	else if (numOfMissleLaunched > 20) {
		shootingInterval = 0.5f;
	}
	*/
}

void eae6320::Boss::UpdateGameObjectBasedOnInput() {
	if (UserInput::IsKeyPressed(UserInput::KeyCodes::Space)) {
		Physics::sRigidBodyState objState;
		objState.boundingBox.center = Math::sVector(0.0f, 0.0f, 0.0f);
		objState.boundingBox.extends = Math::sVector(0.05f, 0.05f, 0.05f);
		objState.position = m_State.position;
		objState.axis_Z_velocity = 0;

		missleVelocity = rotationDuringInterval * missleVelocity;
		objState.velocity = missleVelocity;


		Bullet * pGameObject = new Bullet(m_myGame->masterEffectArray[4], m_myGame->masterMeshArray[4], objState);
		//strcpy_s(pGameObject->objectType, "Missile");
		//pGameObject->m_target = m_myGame->masterGameObjectArr[0];
		m_myGame->masterGameObjectArr.push_back(pGameObject);
		numOfMissleLaunched++;

	}
}