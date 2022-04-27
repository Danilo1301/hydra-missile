#include "Flare.h"
#include "Mod.h"

Flare::Flare(CObject* object, CVector offset) {
	m_Object = object;
	m_Object->m_bIsVisible = false;

	m_Offset = offset;

	m_LastLaunchedExtraFlares = CTimer::m_snTimeInMilliseconds;
}

void Flare::Update() {
	if (!m_FlareObject) {
		Command<Commands::CREATE_OBJECT_NO_OFFSET>(3065, 0, 0, 0, &m_FlareObject);

		//m_FlareObject->m_bUsesCollision = false;
		m_FlareObject->m_pObjectInfo->m_fMass = 200.0f;
		m_FlareObject->m_fMass = 200.0f;
		m_FlareObject->SetIsStatic(false);
		m_FlareObject->AddToMovingList();
		m_FlareObject->m_bIsVisible = false;

		m_Hydra = Mod::GetNearestHydra(m_Object->GetPosition());
		if (m_Hydra) {
			m_FlareObject->m_vecMoveSpeed = m_Hydra->m_vecMoveSpeed;
			m_FlareObject->SetPosn(m_Hydra->TransformFromObjectSpace(m_Offset));
		}
	}

	if (m_FlareObject) {
		float airResistance = 0.98f;

		m_FlareObject->m_pObjectInfo->m_fAirResistance = airResistance;
		m_FlareObject->m_fAirResistance = airResistance;

		float radius = CGeneral::GetRandomNumberInRange(0.5f, 0.9f);

		int lightId = reinterpret_cast<unsigned int>(m_FlareObject) + 20;
		Mod::RegisterCorona(lightId, m_FlareObject, CVector(0, 0, 0), CRGBA(255, 172, 0), radius);

		if (!m_SmokeTrail) {
			m_SmokeTrail = new SmokeTrail();
			m_SmokeTrail->m_Entity = m_FlareObject;
		}

		CVector fposition = m_FlareObject->GetPosition();
		Command< 0x09E5 >(fposition.x, fposition.y, fposition.z, 255, 172, 0, 10.0f);
	}

	if (m_SmokeTrail) m_SmokeTrail->Update();
}

void Flare::Draw() {
	return;

	DrawWorldText("FLARE ORIGIN", m_Object->GetPosition());
	DrawWorldText("FLARE", m_FlareObject->GetPosition());
}

void Flare::Destroy() {
	if (m_SmokeTrail) {
		m_SmokeTrail->Destroy();
		delete m_SmokeTrail;
		m_SmokeTrail = NULL;
	}
	
	if (m_FlareObject) {
		Command<0x0682>(m_FlareObject, 0.0f, 0.0f, 0.0f, false);
		Command<0x0108>(m_FlareObject);
	}
}


