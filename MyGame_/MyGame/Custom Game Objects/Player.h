#pragma once
#include "Engine/GameCommon/GameObject.h"
#include "Engine/GameCommon/Camera.h"
namespace eae6320 {
	class cMyGame;
}

namespace eae6320 {
	class Player : public eae6320::GameCommon::GameObject {
	public:
		Player(Effect * i_pEffect, eae6320::Assets::cHandle<Mesh> i_Mesh, Physics::sRigidBodyState i_State, cMyGame * const i_myGame):
			GameCommon::GameObject(i_pEffect, i_Mesh, i_State),
			m_myGame(i_myGame)
		{
		}
		Player(Player & i_other) :
			GameCommon::GameObject(i_other.GetEffect(), i_other.GetMesh(), i_other.m_State),
			m_myGame(i_other.m_myGame)
		{

		}
		~Player() override;
		void EventTick(const float i_secondCountToIntegrate) override;
		void EventHit(GameObject * i_pObjectHit) override;
		void UpdateGameObjectBasedOnInput() override;

		GameCommon::Camera * m_Camera;
		GameCommon::GameObject * m_Gun;
		cMyGame * const m_myGame;
		bool isOnGround = false;
	};
}
