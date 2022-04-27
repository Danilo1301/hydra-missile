#pragma once

#include "pch.h"
#include "SmokeTrail.h"
#include "Thruster.h"

class Missile {
public:
	CObject* m_Object;
	CObject* m_MissileObject = NULL;
	SmokeTrail* m_SmokeTrail;
	Thruster* m_Thruster = NULL;

	Missile(CObject* object);

	void Update();
	void Draw();
	void Destroy();
};