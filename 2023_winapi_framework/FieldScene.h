#pragma once
#include "Scene.h"
class Field;
class FieldScene : public Scene
{

public:
	virtual void Init() override;
	void Update() override;
	void Render(HDC _dc) override;
	void Release() override;

private:
	int _currentAbleField;
	vector<Field*> _fieldList;

};

