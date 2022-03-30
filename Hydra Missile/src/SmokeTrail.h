#pragma once

#include "pch.h"

class SmokeTrail {
private:
	CVector m_LastCreatedParticlePos;
	CVector m_Position;
public:
	bool m_Enabled = true;

	CEntity* m_Entity = nullptr;
	CVector m_Offset;
	CRGBA m_Color = CRGBA(255, 255, 255);

	SmokeTrail();

	void Update();
	void Destroy();
};