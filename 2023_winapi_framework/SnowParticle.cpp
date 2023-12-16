#include "pch.h"
#include "SnowParticle.h"
#include "Animator.h"
#include "ResMgr.h"
#include "Texture.h"

SnowParticle::SnowParticle(Vec2 pos)
{

	_tex = ResMgr::GetInst()->TexLoad(L"EFT", L"Texture\\Effect\\MargeEffect.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnim(L"Snow", _tex, Vec2(0.f, 0.f),
		Vec2(600, 600), Vec2(600.f, 0.f), 70, 0.1f, Vec2({ 96, 96 }));
	GetAnimator()->PlayAnim(L"Snow", false);

}

SnowParticle::~SnowParticle()
{
}

void SnowParticle::Update()
{

	GetAnimator()->Update();

}

void SnowParticle::Render(HDC _dc)
{

	Component_Render(_dc);

}
