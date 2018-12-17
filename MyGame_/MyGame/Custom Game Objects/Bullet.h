#pragma once
#include "Engine/GameCommon/GameObject.h"
#include "Engine/Time/Time.h"

namespace eae6320 {
	class Bullet : public eae6320::GameCommon::GameObject {
	public:
		Bullet(Effect * i_pEffect, eae6320::Assets::cHandle<Mesh> i_Mesh, Physics::sRigidBodyState i_State) :
			GameCommon::GameObject(i_pEffect, i_Mesh, i_State)
		{
			bornTime = (float)Time::ConvertTicksToSeconds(Time::GetCurrentSystemTimeTickCount());
		}
		Bullet(Bullet & i_other) :
			GameCommon::GameObject(i_other.GetEffect(), i_other.GetMesh(), i_other.m_State)
		{
			bornTime = (float)Time::ConvertTicksToSeconds(Time::GetCurrentSystemTimeTickCount());
		}
		//void EventHit(GameObject * i_pObjectHit) override;
		//void EventTick(const float i_secondCountToIntegrate) override;

		float bornTime;
	};
}
