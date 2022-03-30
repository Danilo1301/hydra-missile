#include "Hydras.h"

std::map<CVehicle*, Hydra*> Hydras::m_Hydras;

bool Hydras::HasHydra(CVehicle* vehicle) {
	return m_Hydras.find(vehicle) != m_Hydras.end();
}

Hydra* Hydras::AddHydra(CVehicle* vehicle) {
	Hydra* hydra = new Hydra(vehicle);
	m_Hydras.insert(std::pair<CVehicle*, Hydra*>(vehicle, hydra));
	return hydra;
}

void Hydras::RemoveHydra(CVehicle* vehicle) {
	Hydra* hydra = m_Hydras[vehicle];
	m_Hydras.erase(vehicle);
	hydra->Destroy();
	delete hydra;
}

void Hydras::Update() {
	for (auto pair : m_Hydras)
	{
		Hydra* hydra = pair.second;
		hydra->Update();
	}
}

void Hydras::Draw() {
	for (auto pair : m_Hydras)
	{
		Hydra* hydra = pair.second;
		hydra->Draw();
	}
}