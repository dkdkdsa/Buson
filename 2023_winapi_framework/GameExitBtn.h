#pragma once
#include "UIButton.h"

class GameExitBtn : public UIButton
{

public:

	GameExitBtn(Vec2 pos, Vec2 scale);
	~GameExitBtn();

	void Update() override;
	void Render(HDC _dc) override;
	void OnClick() override;

private:
	Vec2 origin;
	float per;

};
