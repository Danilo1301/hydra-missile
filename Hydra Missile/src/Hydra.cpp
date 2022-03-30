#include "Hydra.h"

Hydra::Hydra(CVehicle* vehicle) {
	m_Vehicle = vehicle;

	m_SmokeTrail = new SmokeTrail();
	m_SmokeTrail->m_Entity = vehicle;
	m_SmokeTrail->m_Offset = CVector(0.0f, -4.0f, 0.0f);	
	m_SmokeTrail->m_Color = CRGBA(0, 0, 255);
}

void Hydra::Update() {
	//bool smokeEnabled = m_Vehicle->m_vecMoveSpeed.Magnitude() > 0.3f;
	bool smokeEnabled = false;

	if (FindPlayerVehicle(0, false) == m_Vehicle && KeyPressed(88))
		smokeEnabled = true;
	
	m_SmokeTrail->m_Enabled = smokeEnabled;
	m_SmokeTrail->Update();
}

void Hydra::Draw() {
	char text[256];
	sprintf(text, "%f %s", m_Vehicle->m_vecMoveSpeed.Magnitude(), m_SmokeTrail->m_Enabled ? "SMOKE" : "--");
	//DrawWorldText(text, m_Vehicle->GetPosition());
}

void Hydra::Destroy() {
	m_SmokeTrail->Destroy();
	delete m_SmokeTrail;
}