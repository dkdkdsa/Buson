#include "pch.h"
#include "pokemon.h"
#include "Skill.h"

void Pokemon::UseSkill(Pokemon* enemyPokemon, Skill* usedSkill) {
	//float damage = 0.44f * (Stats.Attack / enemyPokemon->Stats.Defense); // Default Damage based on level 50
	int damage = Stats.Attack * usedSkill->Damage;
	for (int i = 0; i < Type.size(); ++i) { // Same-type attack bonus 
		if (Type[i] == usedSkill->SkillType)
			damage *= 1.5f;
	}
	for (int i = 0; i < (int)PokemonType::End; ++i) {
		damage *= TypeSheet[(int)usedSkill->SkillType][i];
	}
	int def = enemyPokemon->Stats.Defense * enemyPokemon->Stats.Hp / 0.411f;
	damage = (damage / def * 44) + 2;
	enemyPokemon->Stats.Hp -= damage;
}
