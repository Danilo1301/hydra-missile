#include "Missile.h"

Missile::Missile(CObject* object) {
	m_Object = object;
	m_Object->m_bIsVisible = false;

	m_SmokeTrail = new SmokeTrail();
	m_SmokeTrail->m_Entity = m_Object;
}

void Missile::Update() {
	m_SmokeTrail->Update();

	if (!Command<Commands::HAS_MODEL_LOADED>(3786)) {
		Command<Commands::REQUEST_MODEL>(3786);
	}

	if (!m_MissileObject && Command<Commands::HAS_MODEL_LOADED>(3786)) {
		Command<Commands::CREATE_OBJECT>(3786, 0.0f, 0.0f, 5.0f, &m_MissileObject);
		Command<Commands::SET_OBJECT_COLLISION>(m_MissileObject, false);
		Command<Commands::ATTACH_OBJECT_TO_OBJECT>(m_MissileObject, m_Object, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

		m_MissileObject->m_qAttachedEntityRotation.Set(0, -3.1415f / 2, 0);
		m_MissileObject->m_fScale = 0.55f;

		m_Thruster = new Thruster(m_Object, CVector(0, -0.5f, 0));
		m_Thruster->m_Size = 0.25f;
		m_Thruster->m_LengthVariation = 4.0f;
	}

	if (m_MissileObject) {
		CVector fposition = m_MissileObject->GetPosition();
		Command< 0x09E5 >(fposition.x, fposition.y, fposition.z, 255, 172, 0, 30.0f);
	}

	if (m_Thruster) m_Thruster->Update();
}

void Missile::Draw() {
	//DrawWorldText("MISSILE", m_Object->GetPosition());
}

void Missile::Destroy() {
	m_SmokeTrail->Destroy();
	delete m_SmokeTrail;
	m_SmokeTrail = NULL;

	if (m_MissileObject) {
		Command<0x0682>(m_MissileObject, 0.0f, 0.0f, 0.0f, false);
		Command<0x0108>(m_MissileObject);
		m_MissileObject = NULL;
	}

	delete m_Thruster;
	m_Thruster = NULL;
}