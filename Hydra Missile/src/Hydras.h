#pragma once

#include "pch.h"
#include "Hydra.h"

class Hydras {
public:
	static std::map<CVehicle*, Hydra*> m_Hydras;

	static bool HasHydra(CVehicle* vehicle);
	static Hydra* AddHydra(CVehicle* vehicle);
	static void RemoveHydra(CVehicle* vehicle);

	static void Update();
	static void Draw();
};