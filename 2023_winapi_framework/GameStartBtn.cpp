#include "pch.h"
#include "GameStartBtn.h"
#include "Texture.h"
#include "EventMgr.h"
#include "TimeMgr.h"
#include "EasingManager.h"
#include "ResMgr.h"

GameStartBtn::GameStartBtn(Vec2 pos, Vec2 scale) : UIButton(L"StartBt", L"Texture\\Intro\\StartBtn.bmp", pos, scale)
{

	m_vPos = pos;
	m_vScale = scale;
	origin = scale;
	per = 0;

}

GameStartBtn::~GameStartBtn()
{
}

void GameStartBtn::Update()
{

	UIButton::Update();

	if (isHover) {

		per += fDT * 3.5f;

	}
	else {

		per -= fDT * 3.5f;

	}

	per = std::clamp(per, 0.f, 1.f);

	m_vScale = EasingManager::GetInst()->EasingVec(origin, origin + Vec2(20, 20), per, Ease::InOutSine);

}

void GameStartBtn::Render(HDC _dc)
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

void GameStartBtn::OnClick()
{

	ResMgr::GetInst()->Play(L"ButtonClick");
	EventMgr::GetInst()->ChangeScene(L"Field_Scene");

}
