#pragma once
#include "Scene.h"
#include "pokemon.h"
class Texture;
class BattleScene : public Scene
{
public:
	virtual void Init() override;
private:
	// 배틀 씬의 업뎃에서 입력 대기를 받고 (이때 입력의 경우 PtInRect()를 사용해서 마우스 포인트가 렉트 내부에 있는지 체크) 
	// 입력이 들어오면 UI 외의 오브젝트의 업뎃을 꺼주고 UI 만 업뎃 시키고 다 끝나면 다시 업뎃을 킨다. (준용쌤 프레임워크의 경우 오브젝트가 죽었다 라고 표현)
	void Update();
	void Render(HDC _dc);
	void PlayEnterBattleIntro();
	void BattleCycle(Skill selectedSkill);
private:
	// Pokemons
	std::vector<Pokemon*> _playerPokemons;
	std::vector<Pokemon*> _wildPokemons;

	// Battle UI
	Texture* _menuBackgroundTex;
};