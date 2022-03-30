#pragma once

#include "pch.h"
#include "Missile.h"

class Missiles {
public:
	static std::map<CObject*, Missile*> m_Missiles;

	static bool HasMissile(CObject* object);
	static Missile* AddMissile(CObject* object);
	static void RemoveMissile(CObject* object);

	static void Update();
	static void Draw();
};