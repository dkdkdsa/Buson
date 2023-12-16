#include "pch.h"
#include "SkillSelectBtn.h"
#include "BattleUIMgr.h"
#include "Texture.h"
#include "Core.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "SkillManager.h"
#include "SelectGDI.h"
#include "Skill.h"
#include <string>
#include "BattleMgr.h"
#define stringify( name ) #name

SkillSelectBtn::SkillSelectBtn() : UIButton(L"NormalBtn.bmp", L"Texture\\Battle\\Button\\NormalBtn.bmp", { 256, 1209 }, { 512, 406 })
{
	m_strName = L"SkillSelectBtn";
	m_vScale = Vec2({ _mainTex->GetWidth() * 2, _mainTex->GetHeight() * 2 });
	curSkill = nullptr;

}

SkillSelectBtn::~SkillSelectBtn()
{
}

void SkillSelectBtn::InitSkill(wstring skillKey)
{

	curSkill = SkillManager::GetInst()->GetSkill(skillKey);

	if (curSkill == nullptr) {

		return;

	}

	curPP = curSkill->PP;
	
	switch (curSkill->SkillType)
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
		_mainTex = ResMgr::GetInst()->TexLoad(L"FightBtn.bmp", L"Texture\\Battle\\Button\\FightBtn.bmp");
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

	_btnRt = RECT_MAKE((long)m_vPos.x, (long)m_vPos.y, (long)m_vScale.x, (long)m_vScale.y);

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

	

	SelectGDI(_dc, ResMgr::GetInst()->LoadFont(L"Font\\neodgm.ttf", L"Neo둥근모", 32));
	auto old = SetTextColor(_dc, RGB(0, 0, 0));

	wstring pps = std::to_wstring(curSkill->PP);
	wstring curPPs = std::to_wstring(curPP);


	TextOut(_dc, m_vPos.x - 100, m_vPos.y - 25, curSkill->Name.c_str(), curSkill->Name.length());

	TextOut(_dc, m_vPos.x + 30, m_vPos.y + 10, pps.c_str(), pps.length());
	TextOut(_dc, m_vPos.x + 65, m_vPos.y + 10, curPPs.c_str(), curPPs.length());

	SetTextColor(_dc, old);

}

void SkillSelectBtn::OnClick()
{
	// 추후 배틀 씬 배틀 사이클하고 연결해서
	// 여기서 선택을 하면 배틀 사이클 실행해서
	// 한 턴 돌아가도록 해줘야함

	if (curPP <= 0) return;
	curPP--;
	ResMgr::GetInst()->Play(L"ButtonClick");
	BattleMgr::GetInst()->StartOneTurn(curSkill);
	ResMgr::GetInst()->Play(L"ButtonClick");

}

void SkillSelectBtn::PosInit(BtnPos _btnpos)
{

	auto screenPoint = Core::GetInst()->GetResolution();

	switch (_btnpos) {
	case BtnPos::LT:
		SetPos(Vec2(
			{ screenPoint.x / 2 - 135
			,screenPoint.y / 2 + 90 }));
		break;
	case BtnPos::LB:
		SetPos(Vec2(
			{ screenPoint.x / 2 - 135
			,screenPoint.y / 2 + 210 }));
		break;
	case BtnPos::RT:
		SetPos(Vec2(
			{ screenPoint.x / 2 + 123
			,screenPoint.y / 2 +  90 }));
		break;
	case BtnPos::RB:
		SetPos(Vec2(
			{ screenPoint.x / 2 + 123
			,screenPoint.y / 2 + 210 }));
		break;
	}
}
