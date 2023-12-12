#pragma once
#include "Scene.h"
class IntroScene :
    public Scene
{

public:
	virtual void Init() override;
	void Update() override;
	void Render(HDC _dc) override;
	void Release() override;

};

