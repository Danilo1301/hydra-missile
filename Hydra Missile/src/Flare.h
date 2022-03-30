#pragma once

#include "pch.h"
#include "SmokeTrail.h"

class Flare {
public:
	CObject* m_Object;
	CObject* m_FlareObject = nullptr;
	SmokeTrail* m_SmokeTrail = nullptr;
	CVehicle* m_Hydra = nullptr;
	CVector m_Offset;

	int m_ExtraFlaresAmount = 0;
	unsigned int m_LastLaunchedExtraFlares = 0;

	Flare(CObject* object, CVector offset);

	void Update();
	void Draw();
	void Destroy();
};