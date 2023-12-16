#include "pch.h"
#include "SkillManager.h"
#include "Skill.h"

void SkillManager::Init()
{

	CreateSkill();

}


void SkillManager::CreateSkill()
{

	map<int, vector<wstring>> grass
	{

		{1, {L"흡수", L"잎날가르기", L"덩굴채찍", L"나뭇잎", L"메가드레인"}},
		{2, {L"흡수", L"잎날가르기", L"덩굴채찍", L"나뭇잎", L"메가드레인", L"기가드레인", L"기관총", L"매지컬리프", L"우드호른", L"그래스믹서", L"에너지볼", L"리프블레이드"}},
		{3, {L"흡수", L"잎날가르기", L"덩굴채찍", L"나뭇잎", L"메가드레인", L"기가드레인", L"기관총", L"매지컬리프", L"우드호른", L"그래스믹서", L"에너지볼", L"리프블레이드", L"하드플랜트", L"리프스톰", L"파워휩", L"우드해머"}}

	};

	_learnSkillContainer.insert({ PokemonType::Grass, grass });

	map<int, vector<wstring>> fire
	{
		{1, {L"불꽃세례", L"니트로차지", L"매지컬플레임", L"불태우기", L"불꽃엄니"}},
		{2, {L"불꽃세례", L"니트로차지", L"매지컬플레임", L"불태우기", L"불꽃엄니", L"불꽃펀치", L"화염자동차", L"브레이즈킥", L"열풍", L"화염방사"}},
		{3, {L"불꽃세례", L"니트로차지", L"매지컬플레임", L"불태우기", L"불꽃엄니", L"불꽃펀치", L"화염자동차", L"브레이즈킥", L"열풍", L"화염방사", L"불대문자", L"블러스트번", L"오버히트", L"플레어드라이브"}}
	};

	_learnSkillContainer.insert({ PokemonType::Fire, fire });

	map<int, vector<wstring>> water
	{
		{1, {L"물대포", L"거품", L"아쿠아제트", L"껍질끼우기"}},
		{2, {L"물대포", L"거품", L"아쿠아제트", L"껍질끼우기", L"거품광선", L"폭포오르기", L"다이빙", L"물의파동", L"아쿠아테일", L"파도타기"}},
		{3, {L"물대포", L"거품", L"아쿠아제트", L"껍질끼우기", L"거품광선", L"폭포오르기", L"다이빙", L"물의파동", L"아쿠아테일", L"파도타기", L"하이드로펌프", L"하이드로캐논"}}
	};

	_learnSkillContainer.insert({ PokemonType::Water, water });

	map<int, vector<wstring>> normal
	{
		{1, {L"막치기", L"연속뺨치기", L"할퀴기", L"풀베기", L"몸통박치기", L"꼬리흔들기", L"째려보기", L"울음소리", L"전광석화"}},
		{2, {L"막치기", L"연속뺨치기", L"할퀴기", L"풀베기", L"몸통박치기", L"꼬리흔들기", L"째려보기", L"울음소리", L"전광석화", L"돌진", L"누르기", L"박치기", L"힘껏치기", L"메가톤펀치", L"스피드스타"}},
		{3, {L"막치기", L"연속뺨치기", L"할퀴기", L"풀베기", L"몸통박치기", L"꼬리흔들기", L"째려보기", L"울음소리", L"전광석화", L"돌진", L"누르기", L"박치기", L"힘껏치기", L"메가톤펀치", L"스피드스타", L"대폭발", L"로케트박치기", L"자폭", L"파괴광선", L"이판사판태클", L"메가톤킥"}}
	};

	_learnSkillContainer.insert({ PokemonType::Normal, normal });

	map<int, vector<wstring>> fighting
	{
		{1, {L"태권당수", L"마하펀치", L"바위깨기", L"발경", L"그로우펀치"}},
		{2, {L"태권당수", L"마하펀치", L"바위깨기", L"발경", L"그로우펀치", L"로킥", L"드레인펀치", L"파동탄", L"스카이업퍼"}},
		{3, {L"태권당수", L"마하펀치", L"바위깨기", L"발경", L"그로우펀치", L"로킥", L"드레인펀치", L"파동탄", L"스카이업퍼", L"기합구슬", L"암해머", L"엄청난힘", L"힘껏펀치"}}
	};

	_learnSkillContainer.insert({ PokemonType::Fighting, fighting });

	map<int, vector<wstring>> ground
	{
		{1, {L"모래뿌리기", L"진흙뿌리기", L"머드숏", L"본러쉬"}},
		{2, {L"모래뿌리기", L"진흙뿌리기", L"머드숏", L"본러쉬", L"뼈다귀치기", L"땅고르기", L"진흙폭탄", L"분함의발구르기"}},
		{3, {L"모래뿌리기", L"진흙뿌리기", L"머드숏", L"본러쉬", L"뼈다귀치기", L"땅고르기", L"진흙폭탄", L"분함의발구르기", L"10만마력", L"드릴라이너", L"대지의힘", L"지진"}}
	};

	_learnSkillContainer.insert({ PokemonType::Ground, ground });

	map<int, vector<wstring>> rock
	{
		{1, {L"떨어뜨리기", L"락블레스트", L"원시의힘", L"돌떨구기"}},
		{2, {L"떨어뜨리기", L"락블레스트", L"원시의힘", L"돌떨구기", L"원시의힘", L"암석봉인", L"스톤샤워", L"파워젬"}},
		{3, {L"떨어뜨리기", L"락블레스트", L"원시의힘", L"돌떨구기", L"원시의힘", L"암석봉인", L"스톤샤워", L"파워젬", L"암석포", L"스톤에지", L"양날박치기"}}
	};

	_learnSkillContainer.insert({ PokemonType::Rock, rock });

	map<int, vector<wstring>> electric
	{
		{1, {L"전기쇼크", L"스파크", L"차지빔", L"일렉트릭네트", L"전격파"}},
		{2, {L"전기쇼크", L"스파크", L"차지빔", L"일렉트릭네트", L"전격파", L"번개펀치", L"10만볼트", L"방전", L"와일드볼트"}},
		{3, {L"전기쇼크", L"스파크", L"차지빔", L"일렉트릭네트", L"전격파", L"번개펀치", L"10만볼트", L"방전", L"와일드볼트", L"볼트태클", L"전자포", L"번개"}}
	};

	_learnSkillContainer.insert({ PokemonType::Electric, electric });

	map<int, vector<wstring>> psychic
	{
		{1, {L"환상빔", L"염동력", L"고속이동", L"하트스탬프"}},
		{2, {L"환상빔", L"염동력", L"고속이동", L"하트스탬프", L"사이코팽", L"사이코쇼크", L"사념의박치기", L"사이코커터"}},
		{3, {L"환상빔", L"염동력", L"고속이동", L"하트스탬프", L"사이코팽", L"사이코쇼크", L"사념의박치기", L"사이코커터", L"신통력", L"사이코키네시스"}}
	};

	_learnSkillContainer.insert({ PokemonType::Psychic, psychic });

	map<int, vector<wstring>> ice
	{
		{1, {L"눈싸라기", L"고드름침", L"얼음뭉치", L"얼음엄니"}},
		{2, {L"눈싸라기", L"고드름침", L"얼음뭉치", L"얼음엄니", L"프리즈드라이", L"냉동펀치", L"고드름떨구기"}},
		{3, {L"눈싸라기", L"고드름침", L"얼음뭉치", L"얼음엄니", L"프리즈드라이", L"냉동펀치", L"고드름떨구기", L"아이스해머", L"눈보라", L"냉동빔"}}
	};

	_learnSkillContainer.insert({ PokemonType::Ice, ice });

	map<int, vector<wstring>> dark
	{
		{1, {L"따라가때리기", L"탁쳐서떨구기", L"승부굳히기", L"바크아웃"}},
		{2, {L"따라가때리기", L"탁쳐서떨구기", L"승부굳히기", L"바크아웃", L"세차게휘두르기", L"지옥찌르기", L"나이트버스트"}},
		{3, {L"따라가때리기", L"탁쳐서떨구기", L"승부굳히기", L"바크아웃", L"세차게휘두르기", L"지옥찌르기", L"나이트버스트", L"악의파동", L"깨물어부수기"}}
	};

	_learnSkillContainer.insert({ PokemonType::Dark, dark });

	map<int, vector<wstring>> flying
	{
		{1, {L"바람일으키기", L"날개치기", L"에어컷터", L"쪼기"}},
		{2, {L"바람일으키기", L"날개치기", L"에어컷터", L"쪼기", L"회전부리", L"제비반환", L"쪼아대기", L"에어슬래시"}},
		{3, {L"바람일으키기", L"날개치기", L"에어컷터", L"쪼기", L"회전부리", L"제비반환", L"쪼아대기", L"에어슬래시", L"폭풍", L"애크러뱃", L"브레이브버드"}}
	};

	_learnSkillContainer.insert({ PokemonType::Flying, flying });

	map<int, vector<wstring>> bug
	{
		{1, {L"더블니들", L"연속자르기", L"은빛바람", L"벌레의저항"}},
		{2, {L"더블니들", L"연속자르기", L"은빛바람", L"벌레의저항", L"벌레의야단법석", L"시저크로스", L"시그널빔", L"흡혈"}},
		{3, {L"더블니들", L"연속자르기", L"은빛바람", L"벌레의저항", L"벌레의야단법석", L"시저크로스", L"시그널빔", L"흡혈", L"메가폰", L"덤벼들기"}}
	};

	_learnSkillContainer.insert({ PokemonType::Bug, bug });

	map<int, vector<wstring>> dragon
	{
		{1, {L"용의숨결", L"회오리", L"더블촙", L"드래곤테일"}},
		{2, {L"용의숨결", L"회오리", L"더블촙", L"드래곤테일", L"용의파동", L"드래곤크루", L"용의춤"}},
		{3, {L"용의숨결", L"회오리", L"더블촙", L"드래곤테일", L"용의파동", L"드래곤크루", L"용의춤", L"역린", L"드래곤다이브", L"용성군"}}
	};

	_learnSkillContainer.insert({ PokemonType::Dragon, dragon });

	map<int, vector<wstring>> poison
	{
		{1, {L"독침", L"용해액", L"독엄니", L"포이즌테일"}},
		{2, {L"독침", L"용해액", L"독엄니", L"포이즌테일", L"크로스포이즌", L"오물폭탄", L"오물웨이브"}},
		{3, {L"독침", L"용해액", L"독엄니", L"포이즌테일", L"크로스포이즌", L"오물폭탄", L"오물웨이브", L"트림", L"더스트슈트"}}
	};

	_learnSkillContainer.insert({ PokemonType::Dragon, poison });

	map<int, vector<wstring>> ghost
	{
		{1, {L"나이트헤드", L"핥기", L"놀래키기", L"야습"}},
		{2, {L"나이트헤드", L"핥기", L"놀래키기", L"야습", L"새도펀치", L"병상첨병", L"섀도크루"}},
		{3, {L"나이트헤드", L"핥기", L"놀래키기", L"야습", L"새도펀치", L"병상첨병", L"섀도크루", L"섀도볼", L"괴상한바람"}}
	};

	_learnSkillContainer.insert({ PokemonType::Ghost, ghost });

	map<int, vector<wstring>> steel
	{
		{1, {L"메탈크로우", L"불릿펀치", L"기어소서", L"마그넷봄"}},
		{2, {L"메탈크로우", L"불릿펀치", L"기어소서", L"마그넷봄", L"아이언헤드", L"러스터캐논", L"미러숏"}},
		{3, {L"메탈크로우", L"불릿펀치", L"기어소서", L"마그넷봄", L"아이언헤드", L"러스터캐논", L"미러숏", L"코멧펀치", L"아이언테일", L"강철날개"}}
	};

	_learnSkillContainer.insert({ PokemonType::Steel, steel });

}

void SkillManager::InitSkillContainer()
{
	Skill skill;
	skill = Skill(
		L"흡수",
		SkillGroup::Attack,
		20,
		100,
		25,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"잎날가르기",
		SkillGroup::Attack,
		55,
		95,
		25,
		PokemonType::Grass,
		BattleEffectGroup::Critical,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"덩굴채찍",
		SkillGroup::Attack,
		45,
		100,
		25,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"나뭇잎",
		SkillGroup::Attack,
		40,
		100,
		40,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"메가드레인",
		SkillGroup::Attack,
		40,
		100,
		15,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"기가드레인",
		SkillGroup::Attack,
		75,
		100,
		10,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"기관총",
		SkillGroup::Attack,
		25,
		100,
		30,
		PokemonType::Grass,
		BattleEffectGroup::Continue,
		0,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"매지컬리프",
		SkillGroup::Attack,
		60,
		100,
		20,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"우드호른",
		SkillGroup::Attack,
		75,
		100,
		10,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"그래스믹서",
		SkillGroup::Attack,
		65,
		90,
		10,
		PokemonType::Grass,
		BattleEffectGroup::DEFRankDown,
		1,
		50
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"에너지볼",
		SkillGroup::Attack,
		90,
		100,
		10,
		PokemonType::Grass,
		BattleEffectGroup::DEFRankDown,
		1,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"리프블레이드",
		SkillGroup::Attack,
		90,
		100,
		15,
		PokemonType::Grass,
		BattleEffectGroup::Critical,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"하드플랜트",
		SkillGroup::Attack,
		150,
		90,
		5,
		PokemonType::Grass,
		BattleEffectGroup::Recoil,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"리프스톰",
		SkillGroup::Attack,
		130,
		90,
		5,
		PokemonType::Grass,
		BattleEffectGroup::MyAtkDown,
		2,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"파워휩",
		SkillGroup::Attack,
		130,
		85,
		10,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"우드해머",
		SkillGroup::Attack,
		120,
		100,
		15,
		PokemonType::Grass,
		BattleEffectGroup::DamageRecoil,
		3,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"불꽃세례",
		SkillGroup::Attack,
		40,
		100,
		25,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"니트로차지",
		SkillGroup::Attack,
		50,
		100,
		20,
		PokemonType::Fire,
		BattleEffectGroup::MySEPUp,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"매지컬플레임",
		SkillGroup::Attack,
		75,
		100,
		10,
		PokemonType::Fire,
		BattleEffectGroup::AtkRankDown,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"불태우기",
		SkillGroup::Attack,
		60,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::None,
		0,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"불꽃엄니",
		SkillGroup::Attack,
		65,
		95,
		15,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"불꽃펀치",
		SkillGroup::Attack,
		75,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"화염자동차",
		SkillGroup::Attack,
		60,
		100,
		25,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"브레이즈킥",
		SkillGroup::Attack,
		85,
		90,
		10,
		PokemonType::Fire,
		BattleEffectGroup::Critical,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"열풍",
		SkillGroup::Attack,
		95,
		90,
		10,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		1,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"화염방사",
		SkillGroup::Attack,
		90,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		1,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"불대문자",
		SkillGroup::Attack,
		110,
		85,
		5,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		1,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"블러스트번",
		SkillGroup::Attack,
		150,
		90,
		5,
		PokemonType::Fire,
		BattleEffectGroup::Recoil,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"오버히트",
		SkillGroup::Attack,
		130,
		90,
		5,
		PokemonType::Fire,
		BattleEffectGroup::MyAtkDown,
		2,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"플레어드라이브",
		SkillGroup::Attack,
		120,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::DamageRecoil,
		3,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"물대포",
		SkillGroup::Attack,
		40,
		100,
		25,
		PokemonType::Water,
		BattleEffectGroup::None,
		3,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"거품",
		SkillGroup::Attack,
		40,
		100,
		30,
		PokemonType::Water,
		BattleEffectGroup::SPERankDown,
		1,
		10
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"아쿠아제트",
		SkillGroup::Attack,
		40,
		100,
		20,
		PokemonType::Water,
		BattleEffectGroup::ActionPriority,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });

	skill = Skill(
		L"껍질끼우기",
		SkillGroup::Attack,
		35,
		85,
		15,
		PokemonType::Water,
		BattleEffectGroup::None,
		1,
		100
	);

	_skillContainer.insert({ skill.Name, &skill });
}

vector<wstring> SkillManager::LearnSkill(PokemonType type, int evolutionCount)
{

	//복사로 가져오기
	auto container = _learnSkillContainer[type][evolutionCount];
	vector<wstring> result;

	for (int i = 0; i < 1000; i++) {

		int idx1 = rand() % container.size();
		int idx2 = rand() % container.size();

		std::swap(container[idx1], container[idx2]);

	}

	for (int i = 0; i < 4; i++) {


		result.push_back(container[i]);

	}

	return result;

}