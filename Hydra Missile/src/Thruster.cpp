#include "Thruster.h"
#include "Mod.h"
#include "CGeneral.h"

Thruster::Thruster(CEntity* entity, CVector offset) {
	m_Entity = entity;
	m_Offset = offset;
}

void Thruster::Update() {
	int lightId = reinterpret_cast<unsigned int>(m_Entity) + 40;

	int maxLights = 8;
	float maxSize = m_Size;
	float maxDistance = m_Length + CGeneral::GetRandomNumberInRange(0.0f, m_LengthVariation);

	for (int i = 0; i < maxLights; i++)
	{
		float d = i * (maxDistance / maxLights);
		float size = maxSize - (i * (maxSize / maxLights));

		CVector lightPosition = m_Offset - CVector(0, d, 0);

		Mod::RegisterCorona(lightId++, m_Entity, lightPosition, m_Color, size);
	}
}

void Thruster::Draw() {
	return;

	char text[256];
	sprintf(text, "Thruster");
	DrawWorldText(text, m_Entity->TransformFromObjectSpace(m_Offset));
}