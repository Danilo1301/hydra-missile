#include "Flares.h"

std::vector<Flare*> Flares::m_Flares;

bool Flares::HasFlare(CObject* object) {
	for (Flare* flare : m_Flares)
	{
		if (flare->m_Object == object) return true;
	}
	return false;
}

void Flares::AddFlares(CObject* object, int amount) {
	auto flareL = AddFlare(object, { -1.8f, 0, -1.4f });
	auto flareR = AddFlare(object, { 1.8f, 0, -1.4f });

	flareL->m_ExtraFlaresAmount = amount;
	flareR->m_ExtraFlaresAmount = amount;
}

Flare* Flares::AddFlare(CObject* object, CVector offset) {
	Flare* flare = new Flare(object, offset);
	m_Flares.push_back(flare);
	return flare;
}

void Flares::RemoveFlares(CObject* object) {
	std::vector<Flare*> toRemove;

	for (Flare* flare : m_Flares)
	{
		if (flare->m_Object == object) {
			toRemove.push_back(flare);
		}
	}

	for (Flare* flare : toRemove)
	{
		m_Flares.erase(std::find(m_Flares.begin(), m_Flares.end(), flare));
		flare->Destroy();
		delete flare;
	}
}

void Flares::Update() {
	for (Flare* flare : m_Flares)
	{
		flare->Update();

		auto now = CTimer::m_snTimeInMilliseconds;

		if (now - flare->m_LastLaunchedExtraFlares >= 200 && flare->m_ExtraFlaresAmount > 0) {
			flare->m_LastLaunchedExtraFlares = now;
			flare->m_ExtraFlaresAmount--;

			AddFlare(flare->m_Object, flare->m_Offset - CVector(0.3f, 0, 0));
		}
	}
}

void Flares::Draw() {
	for (Flare* flare : m_Flares)
	{
		flare->Draw();
	}
}