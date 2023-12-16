#include "pch.h"
#include "SkillSelectBtn.h"
#include "BattleUIMgr.h"
#include "Texture.h"
#include "Core.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "SkillManager.h"

#define stringify( name ) #name

SkillSelectBtn::SkillSelectBtn() : UIButton(L"NormalBtn.bmp", L"Texture\\Battle\\Button\\NormalBtn.bmp", { 256, 1209 }, { 512, 406 })
{
	m_strName = L"SkillSelectBtn";
	m_vScale = Vec2({ _mainTex->GetWidth() * 2, _mainTex->GetHeight() * 2 });
}

SkillSelectBtn::~SkillSelectBtn()
{
}

void SkillSelectBtn::InitSkill(wstring skillKey)
{

	Skill* skill = SkillManager::GetInst()->GetSkill(skillKey);

	if (skill == nullptr) {

		return;

	}

	switch (skill->SkillType)
	{
	case PokemonType::Normal: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"NormalBtn.bmp", L"Texture\\Battle\\Button\\NormalBtn.bmp");
	}
		break;
	case PokemonType::Fire: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"FireBtn.bmp", L"Texture\\Battle\\Button\\FireBtn.bmp");
	}
		break;
	case PokemonType::Water: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"WaterBtn.bmp", L"Texture\\Battle\\Button\\WaterBtn.bmp");
	}
		break;
	case PokemonType::Electric: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"ElectricBtn.bmp", L"Texture\\Battle\\Button\\ElectricBtn.bmp");
	}
		break;
	case PokemonType::Grass: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"GrassBtn.bmp", L"Texture\\Battle\\Button\\GrassBtn.bmp");
	}
		break;
	case PokemonType::Ice: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"IceBtn.bmp", L"Texture\\Battle\\Button\\IceBtn.bmp");
	}
		break;
	case PokemonType::Fighting: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"FightingBtn.bmp", L"Texture\\Battle\\Button\\FightingBtn.bmp");
	}
		break;
	case PokemonType::Poison: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"PoisonBtn.bmp", L"Texture\\Battle\\Button\\PoisonBtn.bmp");
	}
		break;
	case PokemonType::Ground: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"GroundBtn.bmp", L"Texture\\Battle\\Button\\GroundBtn.bmp");
	}
		break;
	case PokemonType::Flying: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"FlyingBtn.bmp", L"Texture\\Battle\\Button\\FlyingBtn.bmp");
	}
		break;
	case PokemonType::Psychic: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"PsychicBtn.bmp", L"Texture\\Battle\\Button\\PsychicBtn.bmp");
	}
		break;
	case PokemonType::Bug: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"BugBtn.bmp", L"Texture\\Battle\\Button\\BugBtn.bmp");
	}
		break;
	case PokemonType::Rock: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"RockBtn.bmp", L"Texture\\Battle\\Button\\RockBtn.bmp");
	}
		break;
	case PokemonType::Ghost: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"GhostBtn.bmp", L"Texture\\Battle\\Button\\GhostBtn.bmp");
	}
		break;
	case PokemonType::Dragon: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"DragonBtn.bmp", L"Texture\\Battle\\Button\\DragonBtn.bmp");
	}
		break;
	case PokemonType::Dark: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"DarkBtn.bmp", L"Texture\\Battle\\Button\\DarkBtn.bmp");
	}
		break;
	case PokemonType::Steel: {
		_mainTex = ResMgr::GetInst()->TexLoad(L"SteelBtn.bmp", L"Texture\\Battle\\Button\\SteelBtn.bmp");
	}
		break;
	}
}

void SkillSelectBtn::Update()
{

	_btnRt = RECT_MAKE((long)m_vPos.x, (long)m_vPos.y, (long)m_vScale.x * 2, (long)m_vScale.y * 2);

	if (KEY_DOWN(KEY_TYPE::LBUTTON) && PtInRect(&_btnRt, KeyMgr::GetInst()->GetMousePos())) {

		OnClick();
	}

}

void SkillSelectBtn::Render(HDC _dc)
{

	int w = _mainTex->GetWidth();
	int h = _mainTex->GetHeight();

	TransparentBlt(
		_dc,
		m_vPos.x,
		m_vPos.y,
		m_vScale.x,
		m_vScale.y,
		_mainTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

}

void SkillSelectBtn::OnClick()
{
	// 추후 배틀 씬 배틀 사이클하고 연결해서
	// 여기서 선택을 하면 배틀 사이클 실행해서
	// 한 턴 돌아가도록 해줘야함
}

void SkillSelectBtn::PosInit(BtnPos _btnpos)
{
	switch (_btnpos) {
	case BtnPos::LT:
		SetPos(Vec2(
			{ (long)(128 - (m_vScale.x / 2))
			, (long)((203 - (m_vScale.y / 2)) * 3) - 2 }));
		break;
	case BtnPos::LB:
		SetPos(Vec2(
			{ (long)(128 - (m_vScale.x / 2))
			, (long)((203 - (m_vScale.y / 2)) * 3.8f) + 4 }));
		break;
	case BtnPos::RT:
		SetPos(Vec2(
			{ (long)(384 - (m_vScale.x / 2))
			, (long)((203 - (m_vScale.y / 2)) * 3) - 2 }));
		break;
	case BtnPos::RB:
		SetPos(Vec2(
			{ (long)(384 - (m_vScale.x / 2))
			, (long)((203 - (m_vScale.y / 2)) * 3.8f) + 4 }));
		break;
	}
}
