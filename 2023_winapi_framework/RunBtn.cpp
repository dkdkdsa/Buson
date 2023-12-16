#include "pch.h"
#include "RunBtn.h"
#include "BattleUIMgr.h"
#include "Texture.h"
#include "Core.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "EventMgr.h"
RunBtn::RunBtn() : UIButton(L"Battle_RunBtn.bmp", L"Texture\\Battle\\Button\\Battle_RunBtn.bmp", { 0, 0 }, { 512, 406 })
{
	m_strName = L"RunBtn";
	m_vScale = Vec2({ _mainTex->GetWidth() * 2, _mainTex->GetHeight() * 2});
	auto screenPoint = Core::GetInst()->GetResolution();
	SetPos(Vec2(
		{ (long)(256 - (m_vScale.x / 2))
		, (long)(screenPoint.y - m_vScale.y - 25) }));
}

RunBtn::~RunBtn()
{
}

void RunBtn::Update()
{
	_btnRt = RECT_MAKE((long)m_vPos.x, (long)m_vPos.y, (long)m_vScale.x * 2, (long)m_vScale.y * 2);

	if (KEY_DOWN(KEY_TYPE::LBUTTON) && PtInRect(&_btnRt, KeyMgr::GetInst()->GetMousePos())) {

		OnClick();
	}
}

void RunBtn::Render(HDC _dc)
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

void RunBtn::OnClick()
{

	//BattleUIMgr::GetInst()->ChangeBattleUI(BattleUIType::Run);
	//SceneMgr::GetInst()->LoadScene(L"Field_Scene");

	EventMgr::GetInst()->ChangeScene(L"Field_Scene");

}
