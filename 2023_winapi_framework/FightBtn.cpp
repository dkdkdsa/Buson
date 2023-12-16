#include "pch.h"
#include "FightBtn.h"
#include "BattleUIMgr.h"
#include "Core.h"
#include "Texture.h"
#include "KeyMgr.h"
#include "ResMgr.h"

FightBtn::FightBtn() : UIButton(L"Battle_FightBtn.bmp", L"Texture\\Battle\\Button\\Battle_FightBtn.bmp", Vec2({ 0, 0 }), Vec2({ 512, 406 }))
{
	m_strName = L"FightBtn";
	m_vScale = Vec2({ _mainTex->GetWidth() * 2, _mainTex->GetHeight() * 2 });
	auto screenPoint = Core::GetInst()->GetResolution();
	SetPos(Vec2(
		{ (long)(256 - (m_vScale.x / 2))
		, (long)((screenPoint.y / 4) * 2.28f) }));
}

FightBtn::~FightBtn()
{
}

void FightBtn::Update()
{
	_btnRt = RECT_MAKE((long)m_vPos.x, (long)m_vPos.y, (long)m_vScale.x * 2, (long)m_vScale.y * 2);

	if (KEY_DOWN(KEY_TYPE::LBUTTON) && PtInRect(&_btnRt, KeyMgr::GetInst()->GetMousePos())) {

		OnClick();
	}
}

void FightBtn::Render(HDC _dc)
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

void FightBtn::OnClick()
{
	BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::SkillSelect);
	ResMgr::GetInst()->Play(L"ButtonClick");
}