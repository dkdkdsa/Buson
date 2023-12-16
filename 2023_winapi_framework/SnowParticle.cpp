#include "pch.h"
#include "SnowParticle.h"
#include "Animator.h"
#include "ResMgr.h"
#include "Texture.h"

SnowParticle::SnowParticle(Vec2 pos)
{

	_tex = ResMgr::GetInst()->TexLoad(L"PTc", L"Texture\\Field\\SnowParticle.bmp");

	CreateAnimator();
	GetAnimator()->CreateAnim(L"Snow", _tex, Vec2(0.f, 0.f),
		Vec2(600, 600), Vec2(0.f, 600.f), 30, 0.1f, Vec2(800, 800));

	GetAnimator()->PlayAnim(L"Snow", true);

	SetPos(pos);

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
