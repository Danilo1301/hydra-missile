#pragma once

#include "pch.h"
#include "SmokeTrail.h"

class Hydra {
public:
	CVehicle* m_Vehicle;
	SmokeTrail* m_SmokeTrail;

	Hydra(CVehicle* vehicle);

	void Update();
	void Draw();
	void Destroy();
};