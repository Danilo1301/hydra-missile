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

		//missleObject->m_qAttachedEntityRotation.Set(0, 0, -3.1415 / 2);
		m_MissileObject->m_qAttachedEntityRotation.Set(0, -3.1415 / 2, 0);
		m_MissileObject->m_fScale = 0.55f;
	}
}

void Missile::Draw() {
	//DrawWorldText("MISSILE", m_Object->GetPosition());
}

void Missile::Destroy() {
	m_SmokeTrail->Destroy();
	delete m_SmokeTrail;

	if (m_MissileObject) {
		Command<0x0682>(m_MissileObject, 0.0f, 0.0f, 0.0f, false);
		Command<0x0108>(m_MissileObject);
	}
}