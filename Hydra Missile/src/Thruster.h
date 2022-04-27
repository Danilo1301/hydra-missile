#pragma once

#include "pch.h"

class Thruster {
public:
	CEntity* m_Entity;
	CVector m_Offset;
	CRGBA m_Color = CRGBA(255, 140, 0);

	float m_Size = 0.6f;
	float m_LengthVariation = 1.8f;
	float m_Length = 2.2f;

	Thruster(CEntity* entity, CVector offset);

	void Update();
	void Draw();
};