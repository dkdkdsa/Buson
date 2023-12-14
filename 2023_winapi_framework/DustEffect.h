#pragma once
#include"Object.h"

class Texture;

class DustEffect : public Object
{

public:
	DustEffect();
	~DustEffect();
	void Update() override;
	void Render(HDC _dc) override;

private:
	Texture* _tex;
	float _per;


};

