#pragma once

#include "pch.h"
#include "SmokeTrail.h"

class Missile {
public:
	CObject* m_Object;
	CObject* m_MissileObject = nullptr;
	SmokeTrail* m_SmokeTrail;

	Missile(CObject* object);

	void Update();
	void Draw();
	void Destroy();
};