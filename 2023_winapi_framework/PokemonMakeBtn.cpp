#include "pch.h"
#include "PokemonMakeBtn.h"
#include "PokemonManager.h"
#include "SceneMgr.h"
#include "FieldScene.h"
#include "Field.h"
#include "EasingManager.h"
#include "TimeMgr.h"

PokemonMakeBtn::PokemonMakeBtn() : UIButton(L"", L"asdf", Vec2({ 300, 100 }), Vec2({300, 75}))
{

	originScale = m_vScale;

}

void PokemonMakeBtn::Update()
{

	UIButton::Update();

	if (isHover) {

		per += fDT * 1.5f;

	}
	else {

		per -= fDT * 1.5f;

	}

	per = std::clamp(per, 0.f, 1.f);

	m_vScale = EasingManager::GetInst()->EasingVec(originScale, originScale + Vec2(20, 20), per, Ease::InOutBack);

}

void PokemonMakeBtn::OnClick()
{

	auto* field = _fieldScene->GetAbleField();
	field->AddPokemon(*PokemonManager::GetInst()->GetRamdomPokemonByLevel(1));

}
