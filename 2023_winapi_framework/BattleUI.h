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
	virtual void Init();
	void Update() override;
	void Render(HDC _dc) override;
	virtual void Release() {
		for (int i = 0; i < _buttons.size(); ++i) {
			delete _buttons[i];
		}
		_buttons.clear();
	}
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
protected:
	std::vector<UIButton*> _buttons;
	Texture* _mainTex;
	Texture* _backgroundTex;
	RECT _uiRect;
	bool _enable;
};