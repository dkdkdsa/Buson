#pragma once
#include "Object.h"
#include "UIButton.h"

class BattleUI
	: public Object
{
public:
	BattleUI(wstring textureKey, wstring path, Vec2 pos, Vec2 scale);
	~BattleUI();
public:
	void Update() override;
	void Render(HDC _dc) override;
	const bool GetEnable() const { return m_IsAlive; }
	void SetEnable(bool value) {
		m_IsAlive = value;
	}
	std::vector<UIButton*>& GetBtnVec() {
		return _buttons;
	}
	void SetBtnVec(UIButton* uibtn) {
		_buttons.push_back(uibtn);
	}
private:
	std::vector<UIButton*> _buttons;
	Texture* _mainTex;
	Texture* _backgroundTex;
	RECT _uiRect;
	bool _enable;
};