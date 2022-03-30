#pragma once

#include "pch.h"
#include "Flare.h"

class Flares {
public:
	static std::vector<Flare*> m_Flares;

	static bool HasFlare(CObject* object);
	static Flare* AddFlare(CObject* object, CVector offset);
	static void AddFlares(CObject* object, int amount);
	static void RemoveFlares(CObject* object);

	static void Update();
	static void Draw();
};