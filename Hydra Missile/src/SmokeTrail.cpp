#include "SmokeTrail.h"
#include "Fx_c.h"

static float colorToFloat(unsigned char c) {
	return (float)c / 255.0f;
}

SmokeTrail::SmokeTrail() {
	//prt_wheeldirt  prt_collisionsmoke

	/*
	RwV3d offset = { 0.0f, 0.0f, 0.0f };
	m_SmokeFxSystem = g_fxMan.CreateFxSystem("prt_wheeldirt", &offset, nullptr, false);
	if (m_SmokeFxSystem) {
		//smokeFx->CopyParentMatrix();
		m_SmokeFxSystem->Play();
	}
	*/
}

void SmokeTrail::Update() {
	if (m_Entity) {
		m_Position = m_Entity->GetPosition();
	}

	if (!m_Enabled) return;

	if (DistanceBetweenPoints(m_Position, m_LastCreatedParticlePos) > 2.0f) {
		m_LastCreatedParticlePos = m_Position;

		auto vecParticlePos = *(m_Entity->m_matrix) * m_Offset;
		auto smokePart = FxPrtMult_c(
			colorToFloat(m_Color.r),
			colorToFloat(m_Color.g),
			colorToFloat(m_Color.b),
			colorToFloat(m_Color.a),
			1.0F,
			1.0F,
			0.8F
		);

		RwV3d vecParticlePosRW = { vecParticlePos.x, vecParticlePos.y, vecParticlePos.z };
		RwV3d vecVelocityRW = { 0, 0, 0 };

		g_fx.m_pPrtSmokeII3expand->AddParticle(&vecParticlePosRW,
			&vecVelocityRW,
			0.0F,
			&smokePart,
			-1.0F,
			1.2F,
			0.6F,
			false
		);
		
		//Command<0x095C>(position.x, position.y, position.z, 0.0f, 0.0f, 0.0f, 255, 255, 255, 255, 10.0f, 1.0f);

		/*
		CVector position = CVector(m_Position.x, m_Position.y, m_Position.z);
		CVector direction = CVector(0.0f, 0.0f, -1.0f);

		RwMatrix fxMat;
		g_fx.CreateMatFromVec(&fxMat, &position, &direction);
		RwV3d offset = { 0.0f, 0.0f, 0.0f };


		FxSystem_c* smokeFx = g_fxMan.CreateFxSystem("prt_collisionsmoke", &offset, &fxMat, false);
		if (smokeFx) {
			smokeFx->CopyParentMatrix();
			smokeFx->Play();
		}
		*/
	}
}

void SmokeTrail::Destroy() {
}