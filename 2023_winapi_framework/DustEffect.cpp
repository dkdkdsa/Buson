#include "pch.h"
#include "DustEffect.h"
#include"Texture.h"
#include"Animator.h"
#include "ResMgr.h"
#include "TimeMgr.h"
#include "EventMgr.h"

DustEffect::DustEffect()
{

	_tex = ResMgr::GetInst()->TexLoad(L"EFT", L"Texture\\Effect\\MargeEffect.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnim(L"EFEFEF", _tex, Vec2(0.f, 0.f),
		Vec2(32, 32), Vec2(32.f, 0.f), 5, 0.05f, Vec2({96, 96}));
	GetAnimator()->PlayAnim(L"EFEFEF", false);

}

DustEffect::~DustEffect()
{
}

void DustEffect::Update()
{

	_per += fDT;

	if (_per > 0.23f) {

		EventMgr::GetInst()->DeleteObject(this);

	}

	GetAnimator()->Update();

}

void DustEffect::Render(HDC _dc)
{

	Component_Render(_dc);

}
