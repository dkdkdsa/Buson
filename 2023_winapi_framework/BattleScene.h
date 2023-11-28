#pragma once
#include "Scene.h"
#include "pokemon.h"
class Texture;
class BattleScene : public Scene
{
public:
	virtual void Init() override;
private:
	// ��Ʋ ���� �������� �Է� ��⸦ �ް� (�̶� �Է��� ��� PtInRect()�� ����ؼ� ���콺 ����Ʈ�� ��Ʈ ���ο� �ִ��� üũ) 
	// �Է��� ������ UI ���� ������Ʈ�� ������ ���ְ� UI �� ���� ��Ű�� �� ������ �ٽ� ������ Ų��. (�ؿ�� �����ӿ�ũ�� ��� ������Ʈ�� �׾��� ��� ǥ��)
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