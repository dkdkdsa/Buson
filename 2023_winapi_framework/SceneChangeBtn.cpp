#include "pch.h"
#include "SceneChangeBtn.h"
#include "EventMgr.h"
#include "Texture.h"
#include "KeyMgr.h"
#include "ResMgr.h"
#include "EasingManager.h"
#include "TimeMgr.h"

SceneChangeBtn::SceneChangeBtn(Vec2 pos, Vec2 scale, wstring texKey, wstring path, wstring sceneName)
	:UIButton(texKey, path, pos ,scale)
{

	this->sceneName = sceneName;
	m_vPos = pos;
	m_vScale = scale;
	originScale = scale;

}

SceneChangeBtn::~SceneChangeBtn()
{
}

void SceneChangeBtn::Update()
{

	_btnRt = RECT_MAKE((long)m_vPos.x + (long)offset.x, (long)m_vPos.y + (long)offset.y, (long)m_vScale.x, (long)m_vScale.y);

	if (KEY_DOWN(KEY_TYPE::LBUTTON) && PtInRect(&_btnRt, KeyMgr::GetInst()->GetMousePos())) {

		OnClick();

	}

	CheckHover();
	if (isHover) {

		per += fDT * 2.f;

	}
	else {

		per -= fDT * 2.f;

	}

	per = std::clamp(per, 0.f, 1.f);

	m_vScale = EasingManager::GetInst()->EasingVec(originScale, originScale + Vec2(20, 20), per, Ease::InOutBack);

}

void SceneChangeBtn::OnClick()
{

	EventMgr::GetInst()->ChangeScene(sceneName);

}

void SceneChangeBtn::Render(HDC _dc)
{

	int w = _mainTex->GetWidth();
	int h = _mainTex->GetHeight();

	TransparentBlt(
		_dc,
		(m_vPos.x + offset.x) - m_vScale.x / 2,
		(m_vPos.y + offset.y) - m_vScale.y / 2,
		m_vScale.x,
		m_vScale.y,
		_mainTex->GetDC(),
		0,
		0,
		w,
		h,
		RGB(255, 0, 255));

	COLORREF oldColor = SetTextColor(_dc, RGB(255, 255, 255));
	SetBkMode(_dc, 1);

	HFONT font = ResMgr::GetInst()->LoadFont(L"Font\\neodgm.ttf", L"NeoµÕ±Ù¸ð", 40);
	HFONT oldFont = (HFONT)SelectObject(_dc, font);

	TextOut(_dc, (m_vPos.x + offset.x) - 50, (m_vPos.y + offset.y) - 20, L"¹èÆ²!", 3);

	SetTextColor(_dc, oldColor);
	SelectObject(_dc, oldFont);
	DeleteObject(font);

}
