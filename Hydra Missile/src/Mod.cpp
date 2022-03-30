#include "Mod.h"
#include "Missiles.h"
#include "Hydras.h"
#include "Flares.h"

Mod::Mod() {
	Events::objectRenderEvent += [](CObject* object) {
		if (object->m_nModelIndex == 345) {
			if (!Missiles::HasMissile(object)) Missiles::AddMissile(object);
		}
		if (object->m_nModelIndex == 354) {
			if (!Flares::HasFlare(object)) Flares::AddFlares(object, 3);
		}
	};

	Events::drawingEvent += []() {
		Missiles::Draw();
		Hydras::Draw();
		Flares::Draw();

		char text[256];
		sprintf(text, "%d missiles; %d flares; %d hydras", Missiles::m_Missiles.size(), Flares::m_Flares.size(), Hydras::m_Hydras.size());
		//DrawScreenText(text, {200, 400});
	};
	
	Events::processScriptsEvent += []() {
		Missiles::Update();
		Hydras::Update();
		Flares::Update();
	};

	Events::objectDtorEvent.after += [](CObject* object) {
		if (Missiles::HasMissile(object)) Missiles::RemoveMissile(object);
		if (Flares::HasFlare(object)) Flares::RemoveFlares(object);
	};

	Events::vehicleSetModelEvent.after += [](CVehicle* vehicle, int modelId) {
		if (modelId == 520) {
			if (!Hydras::HasHydra(vehicle)) Hydras::AddHydra(vehicle);
		}
	};

	Events::vehicleDtorEvent.after += [](CVehicle* vehicle) {
		if (vehicle->m_nModelIndex == 520) {
			if (Hydras::HasHydra(vehicle)) Hydras::RemoveHydra(vehicle);
		}
	};
}

CVehicle* Mod::GetNearestHydra(CVector position) {
	float nearestDistance = INFINITY;
	CVehicle* nearestVehicle = nullptr;

	for (auto vehicle : CPools::ms_pVehiclePool)
	{
		if (vehicle->m_nModelIndex != 520) continue;

		auto vehPos = vehicle->GetPosition();

		float distance = DistanceBetweenPoints(vehPos, position);

		if (distance > nearestDistance) continue;

		nearestDistance = distance;
		nearestVehicle = vehicle;
	}

	return nearestVehicle;
}

void Mod::RegisterCorona(int lightid, CEntity* entity, CVector offset, CRGBA color, float radius) {
	CCoronas::RegisterCorona(
		lightid,
		entity,
		color.r,
		color.g,
		color.b,
		color.a,
		offset,
		radius,
		800.0f,
		eCoronaType::CORONATYPE_SHINYSTAR,
		eCoronaFlareType::FLARETYPE_NONE,
		false,
		false,
		0,
		0.0f,
		false,
		0.1f,
		0,
		15.0f,
		false,
		false
	);
}

Mod mod;