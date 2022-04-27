#include "Hydra.h"

bool useThruster = false;

Hydra::Hydra(CVehicle* vehicle) {
	m_Vehicle = vehicle;

	m_SmokeTrail = new SmokeTrail();
	m_SmokeTrail->m_Entity = vehicle;
	m_SmokeTrail->m_Offset = CVector(0.0f, -7.1f, 0.35f);
	m_SmokeTrail->m_Color = CRGBA(0, 0, 255);

	if (useThruster) {
		m_Thruster = new Thruster(m_Vehicle, CVector(0.0f, -7.1f, 0.35f));
		m_Thruster->m_Color = CRGBA(255, 140, 0, 120);
	}
}

void Hydra::Update() {
	if (m_SmokeTrail) {
		//bool smokeEnabled = m_Vehicle->m_vecMoveSpeed.Magnitude() > 0.3f;
		bool smokeEnabled = false;

		if (FindPlayerVehicle(0, false) == m_Vehicle && KeyPressed(88)) smokeEnabled = true;

		m_SmokeTrail->m_Enabled = smokeEnabled;
		m_SmokeTrail->Update();
	}
	

	if(m_Thruster) m_Thruster->Update();
}

void Hydra::Draw() {
	char text[256];
	sprintf(text, "%f %s", m_Vehicle->m_vecMoveSpeed.Magnitude(), m_SmokeTrail->m_Enabled ? "SMOKE" : "--");
	//DrawWorldText(text, m_Vehicle->GetPosition());

	if(m_Thruster) m_Thruster->Draw();
}

void Hydra::Destroy() {
	if (m_SmokeTrail) {
		m_SmokeTrail->Destroy();
		delete m_SmokeTrail;
		m_SmokeTrail = NULL;
	}
}