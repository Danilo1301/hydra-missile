#pragma once

#include "pch.h"
#include "SmokeTrail.h"

class Mod {
public:
    static CVehicle* GetNearestHydra(CVector position);
    static void RegisterCorona(int lightid, CEntity* entity, CVector offset, CRGBA color, float radius);

    Mod();
};