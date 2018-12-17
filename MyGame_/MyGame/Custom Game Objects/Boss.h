#pragma once
#include "Engine/GameCommon/GameObject.h"
#include "Engine/Math/sVector.h"
#include "Engine/Math/cMatrix_transformation.h"
#include "Engine/Math/cQuaternion.h"
namespace eae6320 {
	class cMyGame;
}
namespace eae6320 {
	class Boss : public eae6320::GameCommon::GameObject {
	public:
		Boss(Effect * i_pEffect, eae6320::Assets::cHandle<Mesh> i_Mesh, Physics::sRigidBodyState i_State, cMyGame * const i_myGame) :
			GameCommon::GameObject(i_pEffect, i_Mesh, i_State),
			m_myGame(i_myGame)
		{
			shootingInterval = 2.0f;
			missleVelocity = Math::sVector(0, 5, 5);

			Math::cQuaternion rotation4Velocity(0.54f, Math::sVector(0, 0, 1));
			rotationDuringInterval = Math::cMatrix_transformation(rotation4Velocity, Math::sVector(0, 0, 0));

			timeLastShot = 0;
			numOfMissleLaunched = 0;
		}
		Boss(Boss & i_other) :
			GameCommon::GameObject(i_other.GetEffect(), i_other.GetMesh(), i_other.m_State),
			m_myGame(i_other.m_myGame)
		{
			shootingInterval = 2.0f;
			missleVelocity = Math::sVector(0, 5, 5);

			Math::cQuaternion rotation4Velocity(0.54f, Math::sVector(0, 0, 1));
			rotationDuringInterval = Math::cMatrix_transformation(rotation4Velocity, Math::sVector(0, 0, 0));

			timeLastShot = 0;
			numOfMissleLaunched = 0;
		}
		
		void EventTick(const float i_secondCountToIntegrate) override;
		void UpdateGameObjectBasedOnInput() override;

		cMyGame * const m_myGame;
		float shootingInterval;
		float timeLastShot;
		uint8_t numOfMissleLaunched;
		Math::sVector missleVelocity;
		Math::cMatrix_transformation rotationDuringInterval;
	};
}
