#include "pch.h"
#include "PokemonMakeBtn.h"
#include "PokemonManager.h"
#include "SceneMgr.h"
#include "FieldScene.h"
#include "Field.h"
#include "EasingManager.h"
#include "TimeMgr.h"
#include "Texture.h"
#include "pokemon.h"
#include "FieldObject.h"
#include "DustEffect.h"

PokemonMakeBtn::PokemonMakeBtn() : UIButton(L"PC", L"Texture\\Field\\PokemonCreateBtn.bmp", Vec2({ 500, 90 }), Vec2({300, 75}))
{

	m_vScale = Vec2({ 340, 100 });
	originScale = m_vScale;

}

void PokemonMakeBtn::Update()
{

	UIButton::Update();

	if (isHover) {

		per += fDT * 2.5f;

	}
	else {

		per -= fDT * 2.5f;

	}

	per = std::clamp(per, 0.f, 1.f);

	m_vScale = EasingManager::GetInst()->EasingVec(originScale, originScale + Vec2(20, 20), per, Ease::InOutCubic);

}

void PokemonMakeBtn::OnClick()
{

	auto* field = _fieldScene->GetAbleField();
	auto pos = field->AddPokemon(PokemonManager::GetInst()->GetRamdomPokemonByLevel(1))->GetPos();
	
	auto* dust = new DustEffect();
	dust->SetPos(pos);

	_fieldScene->AddObject(dust, OBJECT_GROUP::DEFAULT);

}

void PokemonMakeBtn::Render(HDC _dc)
{

	int w = _mainTex->GetWidth();
	int h = _mainTex->GetHeight();

	TransparentBlt(
		_dc,
		m_vPos.x - m_vScale.x / 2,
		m_vPos.y - m_vScale.y / 2,
		m_vScale.x,
		m_vScale.y,
		_mainTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

}
