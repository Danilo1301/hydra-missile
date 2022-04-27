#pragma once

#include "pch.h"
#include "SmokeTrail.h"
#include "Thruster.h"

class Hydra {
public:
	CVehicle* m_Vehicle;
	SmokeTrail* m_SmokeTrail = NULL;
	Thruster* m_Thruster = NULL;

	Hydra(CVehicle* vehicle);

	void Update();
	void Draw();
	void Destroy();
};