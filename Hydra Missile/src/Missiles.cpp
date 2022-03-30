#include "Missiles.h"

std::map<CObject*, Missile*> Missiles::m_Missiles;

bool Missiles::HasMissile(CObject* object) {
	return m_Missiles.find(object) != m_Missiles.end();
}

Missile* Missiles::AddMissile(CObject* object) {
	Missile* missile = new Missile(object);
	m_Missiles.insert(std::pair<CObject*, Missile*>(object, missile));
	return missile;
}

void Missiles::RemoveMissile(CObject* object) {
	Missile* missile = m_Missiles[object];
	m_Missiles.erase(object);
	missile->Destroy();
	delete missile;
}

void Missiles::Update() {
	for (auto pair : m_Missiles)
	{
		Missile* missile = pair.second;
		missile->Update();
	}
}

void Missiles::Draw() {
	for (auto pair : m_Missiles)
	{
		Missile* missile = pair.second;
		missile->Draw();
	}
}