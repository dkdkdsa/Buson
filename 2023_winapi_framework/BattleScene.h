#pragma once
#include "Scene.h"
#include "pokemon.h"
#include "BattleUI.h"

class Texture;
class BattleScene : public Scene
{
public:
	virtual void Init() override;
	// ��Ʋ ���� �������� �Է� ��⸦ �ް� (�̶� �Է��� ��� PtInRect()�� ����ؼ� ���콺 ����Ʈ�� ��Ʈ ���ο� �ִ��� üũ) 
	// �Է��� ������ UI ���� ������Ʈ�� ������ ���ְ� UI �� ���� ��Ű�� �� ������ �ٽ� ������ Ų��. (�ؿ�� �����ӿ�ũ�� ��� ������Ʈ�� �׾��� ��� ǥ��)
	void Update() override;
	void Render(HDC _dc) override;
	void Release() override;
	void PlayEnterBattleIntro();
	void BattleCycle(Skill* selectedSkill);
	void SetCurUI();
private:
	// Pokemons
	std::vector<Pokemon*> _playerPokemons;
	std::vector<Pokemon*> _wildPokemons;

	Texture* _bgTex;


	// Battle UI
	BattleUI* _curUI;
	std::vector<BattleUI*> _battleUIVec;
};