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
		{2, {L"물대포", L"거품", L"아쿠아제트", L"껍질끼우기", L"거품광선", L"폭포오르기", L"물의파동", L"아쿠아테일", L"파도타기"}},
		{3, {L"물대포", L"거품", L"아쿠아제트", L"껍질끼우기", L"거품광선", L"폭포오르기", L"물의파동", L"아쿠아테일", L"파도타기", L"하이드로펌프", L"하이드로캐논"}}
	};

	_learnSkillContainer.insert({ PokemonType::Water, water });

	map<int, vector<wstring>> normal
	{
		{1, {L"막치기", L"연속뺨치기", L"할퀴기", L"풀베기", L"몸통박치기", L"꼬리흔들기", L"째려보기", L"울음소리", L"전광석화"}},
		{2, {L"막치기", L"연속뺨치기", L"할퀴기", L"풀베기", L"몸통박치기", L"꼬리흔들기", L"째려보기", L"울음소리", L"전광석화", L"돌진", L"누르기", L"박치기", L"힘껏치기", L"메가톤펀치", L"스피드스타"}},
		{3, {L"막치기", L"연속뺨치기", L"할퀴기", L"풀베기", L"몸통박치기", L"꼬리흔들기", L"째려보기", L"울음소리", L"전광석화", L"돌진", L"누르기", L"박치기", L"힘껏치기", L"메가톤펀치", L"스피드스타", L"대폭발", L"자폭", L"파괴광선", L"이판사판태클", L"메가톤킥"}}
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
		{2, {L"떨어뜨리기", L"락블레스트", L"원시의힘", L"돌떨구기", L"암석봉인", L"스톤샤워", L"파워젬"}},
		{3, {L"떨어뜨리기", L"락블레스트", L"원시의힘", L"돌떨구기", L"암석봉인", L"스톤샤워", L"파워젬", L"암석포", L"스톤에지", L"양날박치기"}}
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

	_learnSkillContainer.insert({ PokemonType::Poison, poison });

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
	_skillContainer.insert({ L"흡수", new Skill(
		L"흡수",
		SkillGroup::Attack,
		20,
		100,
		25,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100)
	});

	_skillContainer.insert({ L"잎날가르기", new Skill(
		L"잎날가르기",
		SkillGroup::Attack,
		55,
		95,
		25,
		PokemonType::Grass,
		BattleEffectGroup::Critical,
		1,
		100) 
	});

	_skillContainer.insert({ L"덩굴채찍", new Skill(
		L"덩굴채찍",
		SkillGroup::Attack,
		45,
		100,
		25,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100) 
	});

	_skillContainer.insert({ L"나뭇잎", new Skill(
		L"나뭇잎",
		SkillGroup::Attack,
		40,
		100,
		40,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100) 
	});

	_skillContainer.insert({ L"메가드레인", new Skill(
		L"메가드레인",
		SkillGroup::Attack,
		40,
		100,
		15,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100) 
	});

	_skillContainer.insert({ L"기가드레인", new Skill(
		L"기가드레인",
		SkillGroup::Attack,
		75,
		100,
		10,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100)
	});

	_skillContainer.insert({ L"기관총", new Skill(
		L"기관총",
		SkillGroup::Attack,
		25,
		100,
		30,
		PokemonType::Grass,
		BattleEffectGroup::Continue,
		0,
		100)
	});

	_skillContainer.insert({ L"매지컬리프", new Skill(
		L"매지컬리프",
		SkillGroup::Attack,
		60,
		100,
		20,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100)
	});

	_skillContainer.insert({ L"우드호른", new Skill(
		L"우드호른",
		SkillGroup::Attack,
		75,
		100,
		10,
		PokemonType::Grass,
		BattleEffectGroup::Drain,
		2,
		100)
	});

	_skillContainer.insert({ L"그래스믹서", new Skill(
		L"그래스믹서",
		SkillGroup::Attack,
		65,
		90,
		10,
		PokemonType::Grass,
		BattleEffectGroup::DEFRankDown,
		1,
		50)
	});

	_skillContainer.insert({ L"에너지볼", new Skill(
		L"에너지볼",
		SkillGroup::Attack,
		90,
		100,
		10,
		PokemonType::Grass,
		BattleEffectGroup::DEFRankDown,
		1,
		10)
	});

	_skillContainer.insert({ L"리프블레이드", new Skill(
		L"리프블레이드",
		SkillGroup::Attack,
		90,
		100,
		15,
		PokemonType::Grass,
		BattleEffectGroup::Critical,
		1,
		100)
	});

	_skillContainer.insert({ L"하드플랜트", new Skill(
		L"하드플랜트",
		SkillGroup::Attack,
		150,
		90,
		5,
		PokemonType::Grass,
		BattleEffectGroup::Recoil,
		1,
		100)
	});

	_skillContainer.insert({ L"리프스톰", new Skill(
		L"리프스톰",
		SkillGroup::Attack,
		130,
		90,
		5,
		PokemonType::Grass,
		BattleEffectGroup::MyAtkDown,
		2,
		100)
	});

	_skillContainer.insert({ L"파워휩", new Skill(
		L"파워휩",
		SkillGroup::Attack,
		130,
		85,
		10,
		PokemonType::Grass,
		BattleEffectGroup::None,
		0,
		100)
	});

	_skillContainer.insert({ L"우드해머", new Skill(
		L"우드해머",
		SkillGroup::Attack,
		120,
		100,
		15,
		PokemonType::Grass,
		BattleEffectGroup::DamageRecoil,
		3,
		100)
	});

	_skillContainer.insert({ L"불꽃세례", new Skill(
		L"불꽃세례",
		SkillGroup::Attack,
		40,
		100,
		25,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10)
	});

	_skillContainer.insert({ L"니트로차지", new Skill(
		L"니트로차지",
		SkillGroup::Attack,
		50,
		100,
		20,
		PokemonType::Fire,
		BattleEffectGroup::MySEPUp,
		1,
		100)
	});

	_skillContainer.insert({ L"매지컬플레임", new Skill(
		L"매지컬플레임",
		SkillGroup::Attack,
		75,
		100,
		10,
		PokemonType::Fire,
		BattleEffectGroup::AtkRankDown,
		1,
		100)
	});

	_skillContainer.insert({ L"불태우기", new Skill(
		L"불태우기",
		SkillGroup::Attack,
		60,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::None,
		0,
		100)
	});

	_skillContainer.insert({ L"불꽃엄니", new Skill(
		L"불꽃엄니",
		SkillGroup::Attack,
		65,
		95,
		15,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10)
	});

	_skillContainer.insert({ L"불꽃펀치", new Skill(
		L"불꽃펀치",
		SkillGroup::Attack,
		75,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10)
	});

	_skillContainer.insert({ L"화염자동차", new Skill(
		L"화염자동차",
		SkillGroup::Attack,
		60,
		100,
		25,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		0,
		10)
	});

	_skillContainer.insert({ L"브레이즈킥", new Skill(
		L"브레이즈킥",
		SkillGroup::Attack,
		85,
		90,
		10,
		PokemonType::Fire,
		BattleEffectGroup::Critical,
		1,
		100)
	});

	_skillContainer.insert({ L"열풍", new Skill(
		L"열풍",
		SkillGroup::Attack,
		95,
		90,
		10,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		1,
		10)
	});

	_skillContainer.insert({ L"화염방사", new Skill(
		L"화염방사",
		SkillGroup::Attack,
		90,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		1,
		10)
	});

	_skillContainer.insert({ L"불대문자", new Skill(
		L"불대문자",
		SkillGroup::Attack,
		110,
		85,
		5,
		PokemonType::Fire,
		BattleEffectGroup::Burn,
		1,
		10)
	});

	_skillContainer.insert({ L"블러스트번", new Skill(
		L"블러스트번",
		SkillGroup::Attack,
		150,
		90,
		5,
		PokemonType::Fire,
		BattleEffectGroup::Recoil,
		1,
		100)
	});

	_skillContainer.insert({ L"오버히트", new Skill(
		L"오버히트",
		SkillGroup::Attack,
		130,
		90,
		5,
		PokemonType::Fire,
		BattleEffectGroup::MyAtkDown,
		2,
		100)
	});

	_skillContainer.insert({ L"플레어드라이브", new Skill(
		L"플레어드라이브",
		SkillGroup::Attack,
		120,
		100,
		15,
		PokemonType::Fire,
		BattleEffectGroup::DamageRecoil,
		3,
		100)
	});

	_skillContainer.insert({ L"물대포", new Skill(
		L"물대포",
		SkillGroup::Attack,
		40,
		100,
		25,
		PokemonType::Water,
		BattleEffectGroup::None,
		3,
		100)
	});

	_skillContainer.insert({ L"거품", new Skill(
		L"거품",
		SkillGroup::Attack,
		40,
		100,
		30,
		PokemonType::Water,
		BattleEffectGroup::SPERankDown,
		1,
		10)
	});

	_skillContainer.insert({ L"아쿠아제트", new Skill(
		L"아쿠아제트",
		SkillGroup::Attack,
		40,
		100,
		20,
		PokemonType::Water,
		BattleEffectGroup::ActionPriority,
		1,
		100)
	});

	_skillContainer.insert({ L"껍질끼우기", new Skill(
		L"껍질끼우기",
		SkillGroup::Attack,
		35,
		85,
		15,
		PokemonType::Water,
		BattleEffectGroup::None,
		1,
		100)
	});

	_skillContainer.insert({ L"거품광선", new Skill(
		L"거품광선",
		SkillGroup::Attack,
		65,
		100,
		20,
		PokemonType::Water,
		BattleEffectGroup::SPERankDown,
		1,
		10)
	});

	_skillContainer.insert({ L"폭포오르기", new Skill(
		L"폭포오르기",
		SkillGroup::Attack,
		80,
		100,
		15,
		PokemonType::Water,
		BattleEffectGroup::Flinch,
		1,
		20)
	});

	_skillContainer.insert({ L"물의파동", new Skill(
		L"물의파동",
		SkillGroup::Attack,
		60,
		100,
		20,
		PokemonType::Water,
		BattleEffectGroup::Confusion,
		1,
		20)
	});

	_skillContainer.insert({ L"아쿠아테일", new Skill(
		L"아쿠아테일",
		SkillGroup::Attack,
		90,
		90,
		10,
		PokemonType::Water,
		BattleEffectGroup::None,
		1,
		20)
	});

	_skillContainer.insert({ L"파도타기", new Skill(
		L"파도타기",
		SkillGroup::Attack,
		90,
		100,
		15,
		PokemonType::Water,
		BattleEffectGroup::None,
		1,
		20)
	});

	_skillContainer.insert({ L"하이드로펌프", new Skill(
		L"하이드로펌프",
		SkillGroup::Attack,
		110,
		80,
		5,
		PokemonType::Water,
		BattleEffectGroup::None,
		1,
		20)
	});

	_skillContainer.insert({ L"하이드로캐논", new Skill(
		L"하이드로캐논",
		SkillGroup::Attack,
		150,
		90,
		5,
		PokemonType::Water,
		BattleEffectGroup::Recoil,
		1,
		100)
	});

	_skillContainer.insert({ L"막치기", new Skill(
		L"막치기",
		SkillGroup::Attack,
		40,
		100,
		35,
		PokemonType::Normal,
		BattleEffectGroup::None,
		1,
		100)
	});

	_skillContainer.insert({ L"연속뺨치기", new Skill(
		L"연속뺨치기",
		SkillGroup::Attack,
		15,
		85,
		10,
		PokemonType::Normal,
		BattleEffectGroup::Continue,
		1,
		100)
	});

	_skillContainer.insert({ L"할퀴기", new Skill(
	L"할퀴기",
	SkillGroup::Attack,
	40,
	100,
	35,
	PokemonType::Normal,
	BattleEffectGroup::None,
	1,
	100)
	});

	_skillContainer.insert({ L"풀베기", new Skill(
	L"풀베기",
	SkillGroup::Attack,
	50,
	95,
	30,
	PokemonType::Normal,
	BattleEffectGroup::None,
	1,
	100)
	});

	_skillContainer.insert({ L"몸통박치기", new Skill(
	L"몸통박치기",
	SkillGroup::Attack,
	40,
	100,
	35,
	PokemonType::Normal,
	BattleEffectGroup::None,
	1,
	100)
	});

	_skillContainer.insert({ L"꼬리흔들기", new Skill(
	L"꼬리흔들기",
	SkillGroup::Status,
	0,
	100,
	30,
	PokemonType::Normal,
	BattleEffectGroup::DEFRankDown,
	1,
	100)
	});

	_skillContainer.insert({ L"째려보기", new Skill(
	L"째려보기",
	SkillGroup::Status,
	0,
	100,
	30,
	PokemonType::Normal,
	BattleEffectGroup::DEFRankDown,
	1,
	100)
	});

	_skillContainer.insert({ L"울음소리", new Skill(
	L"울음소리",
	SkillGroup::Status,
	0,
	100,
	40,
	PokemonType::Normal,
	BattleEffectGroup::AtkRankDown,
	1,
	100)
	});

	_skillContainer.insert({ L"전광석화", new Skill(
	L"전광석화",
	SkillGroup::Attack,
	40,
	100,
	30,
	PokemonType::Normal,
	BattleEffectGroup::ActionPriority,
	1,
	100)
	});

	_skillContainer.insert({ L"돌진", new Skill(
	L"돌진",
	SkillGroup::Attack,
	90,
	85,
	20,
	PokemonType::Normal,
	BattleEffectGroup::DamageRecoil,
	4,
	100)
	});

	_skillContainer.insert({ L"누르기", new Skill(
	L"누르기",
	SkillGroup::Attack,
	85,
	100,
	15,
	PokemonType::Normal,
	BattleEffectGroup::Paralysis,
	0,
	30)
	});

	_skillContainer.insert({ L"박치기", new Skill(
	L"박치기",
	SkillGroup::Attack,
	70,
	100,
	15,
	PokemonType::Normal,
	BattleEffectGroup::Flinch,
	0,
	30)
	});

	_skillContainer.insert({ L"힘껏치기", new Skill(
	L"힘껏치기",
	SkillGroup::Attack,
	80,
	75,
	20,
	PokemonType::Normal,
	BattleEffectGroup::None,
	0,
	30)
	});

	_skillContainer.insert({ L"메가톤펀치", new Skill(
	L"메가톤펀치",
	SkillGroup::Attack,
	80,
	85,
	20,
	PokemonType::Normal,
	BattleEffectGroup::None,
	0,
	30)
	});

	_skillContainer.insert({ L"스피드스타", new Skill(
	L"스피드스타",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Normal,
	BattleEffectGroup::None,
	0,
	30)
	});

	_skillContainer.insert({ L"대폭발", new Skill(
	L"대폭발",
	SkillGroup::Attack,
	250,
	100,
	5,
	PokemonType::Normal,
	BattleEffectGroup::DeadRecoil,
	0,
	100)
	});

	_skillContainer.insert({ L"자폭", new Skill(
	L"자폭",
	SkillGroup::Attack,
	200,
	100,
	5,
	PokemonType::Normal,
	BattleEffectGroup::DeadRecoil,
	0,
	100)
	});

	_skillContainer.insert({ L"파괴광선", new Skill(
	L"파괴광선",
	SkillGroup::Attack,
	150,
	90,
	5,
	PokemonType::Normal,
	BattleEffectGroup::Recoil,
	0,
	100)
	});

	_skillContainer.insert({ L"이판사판태클", new Skill(
	L"이판사판태클",
	SkillGroup::Attack,
	120,
	100,
	15,
	PokemonType::Normal,
	BattleEffectGroup::DamageRecoil,
	3,
	100)
	});

	_skillContainer.insert({ L"메가톤킥", new Skill(
	L"메가톤킥",
	SkillGroup::Attack,
	120,
	75,
	5,
	PokemonType::Normal,
	BattleEffectGroup::None,
	3,
	100)
	});

	_skillContainer.insert({ L"태권당수", new Skill(
	L"태권당수",
	SkillGroup::Attack,
	50,
	100,
	25,
	PokemonType::Fighting,
	BattleEffectGroup::Critical,
	1,
	100)
	});

	_skillContainer.insert({ L"마하펀치", new Skill(
	L"마하펀치",
	SkillGroup::Attack,
	40,
	100,
	30,
	PokemonType::Fighting,
	BattleEffectGroup::ActionPriority,
	1,
	100)
	});

	_skillContainer.insert({ L"바위깨기", new Skill(
	L"바위깨기",
	SkillGroup::Attack,
	40,
	100,
	15,
	PokemonType::Fighting,
	BattleEffectGroup::DEFRankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"발경", new Skill(
	L"발경",
	SkillGroup::Attack,
	60,
	100,
	10,
	PokemonType::Fighting,
	BattleEffectGroup::Paralysis,
	1,
	30)
		});

	_skillContainer.insert({ L"그로우펀치", new Skill(
	L"그로우펀치",
	SkillGroup::Attack,
	40,
	100,
	20,
	PokemonType::Fighting,
	BattleEffectGroup::MyAtkUp,
	1,
	100)
		});

	_skillContainer.insert({ L"로킥", new Skill(
	L"로킥",
	SkillGroup::Attack,
	65,
	100,
	20,
	PokemonType::Fighting,
	BattleEffectGroup::SPERankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"드레인펀치", new Skill(
	L"드레인펀치",
	SkillGroup::Attack,
	75	,
	100,
	10,
	PokemonType::Fighting,
	BattleEffectGroup::Drain,
	2,
	100)
		});

	_skillContainer.insert({ L"파동탄", new Skill(
	L"파동탄",
	SkillGroup::Attack,
	80	,
	100,
	20,
	PokemonType::Fighting,
	BattleEffectGroup::None,
	2,
	100)
		});

	_skillContainer.insert({ L"스카이업퍼", new Skill(
	L"스카이업퍼",
	SkillGroup::Attack,
	85	,
	90,
	15,
	PokemonType::Fighting,
	BattleEffectGroup::None,
	2,
	100)
		});

	_skillContainer.insert({ L"기합구슬", new Skill(
	L"기합구슬",
	SkillGroup::Attack,
	120	,
	70,
	5,
	PokemonType::Fighting,
	BattleEffectGroup::DEFRankDown,
	1,
	10)
		});

	_skillContainer.insert({ L"암해머", new Skill(
	L"암해머",
	SkillGroup::Attack,
	100	,
	90,
	10,
	PokemonType::Fighting,
	BattleEffectGroup::SPERankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"엄청난힘", new Skill(
	L"엄청난힘",
	SkillGroup::Attack,
	120	,
	100,
	5,
	PokemonType::Fighting,
	BattleEffectGroup::MyA_DDown,
	1,
	100)
		});

	_skillContainer.insert({ L"힘껏펀치", new Skill(
	L"힘껏펀치",
	SkillGroup::Attack,
	150	,
	100,
	20,
	PokemonType::Fighting,
	BattleEffectGroup::ActionPriority,
	5,
	100)
		});

	_skillContainer.insert({ L"모래뿌리기", new Skill(
	L"모래뿌리기",
	SkillGroup::Status,
	0,
	100,
	15,
	PokemonType::Ground,
	BattleEffectGroup::AccuracyDown,
	1,
	100)
		});

	_skillContainer.insert({ L"진흙뿌리기", new Skill(
	L"진흙뿌리기",
	SkillGroup::Attack,
	20,
	100,
	10,
	PokemonType::Ground,
	BattleEffectGroup::AccuracyDown,
	1,
	100)
		});

	_skillContainer.insert({ L"머드숏", new Skill(
	L"머드숏",
	SkillGroup::Attack,
	55,
	95,
	15,
	PokemonType::Ground,
	BattleEffectGroup::SPERankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"본러쉬", new Skill(
	L"본러쉬",
	SkillGroup::Attack,
	25,
	90,
	10,
	PokemonType::Ground,
	BattleEffectGroup::Continue,
	1,
	100)
		});

	_skillContainer.insert({ L"뼈다귀치기", new Skill(
	L"뼈다귀치기",
	SkillGroup::Attack,
	65,
	85,
	10,
	PokemonType::Ground,
	BattleEffectGroup::Flinch,
	1,
	10)
		});

	_skillContainer.insert({ L"땅고르기", new Skill(
	L"땅고르기",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Ground,
	BattleEffectGroup::SPERankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"진흙폭탄", new Skill(
	L"진흙폭탄",
	SkillGroup::Attack,
	65,
	85,
	10,
	PokemonType::Ground,
	BattleEffectGroup::AccuracyDown,
	1,
	30)
		});

	_skillContainer.insert({ L"분함의발구르기", new Skill(
	L"분함의발구르기",
	SkillGroup::Attack,
	75,
	100,
	10,
	PokemonType::Ground,
	BattleEffectGroup::None,
	1,
	30)
		});

	_skillContainer.insert({ L"10만마력", new Skill(
	L"10만마력",
	SkillGroup::Attack,
	95,
	95,
	10,
	PokemonType::Ground,
	BattleEffectGroup::None,
	1,
	30)
		});

	_skillContainer.insert({ L"드릴라이너", new Skill(
	L"드릴라이너",
	SkillGroup::Attack,
	80,
	95,
	10,
	PokemonType::Ground,
	BattleEffectGroup::Critical,
	1,
	100)
		});

	_skillContainer.insert({ L"대지의힘", new Skill(
	L"대지의힘",
	SkillGroup::Attack,
	90,
	100,
	10,
	PokemonType::Ground,
	BattleEffectGroup::DEFRankDown,
	1,
	10)
		});

	_skillContainer.insert({ L"지진", new Skill(
	L"지진",
	SkillGroup::Attack,
	100,
	100,
	10,
	PokemonType::Ground,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"떨어뜨리기", new Skill(
	L"떨어뜨리기",
	SkillGroup::Attack,
	50,
	100,
	15,
	PokemonType::Rock,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"락블레스트", new Skill(
	L"락블레스트",
	SkillGroup::Attack,
	25,
	90,
	10,
	PokemonType::Rock,
	BattleEffectGroup::Continue,
	1,
	100)
		});

	_skillContainer.insert({ L"원시의힘", new Skill(
	L"원시의힘",
	SkillGroup::Attack,
	60,
	100,
	5,
	PokemonType::Rock,
	BattleEffectGroup::MyStatAllUp,
	1,
	10)
		});

	_skillContainer.insert({ L"돌떨구기", new Skill(
	L"돌떨구기",
	SkillGroup::Attack,
	50,
	90,
	20,
	PokemonType::Rock,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"암석봉인", new Skill(
	L"암석봉인",
	SkillGroup::Attack,
	60,
	95,
	15,
	PokemonType::Rock,
	BattleEffectGroup::SPERankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"스톤샤워", new Skill(
	L"스톤샤워",
	SkillGroup::Attack,
	75,
	90,
	10,
	PokemonType::Rock,
	BattleEffectGroup::Flinch,
	1,
	30)
		});

	_skillContainer.insert({ L"파워젬", new Skill(
	L"파워젬",
	SkillGroup::Attack,
	80,
	100,
	20,
	PokemonType::Rock,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"암석포", new Skill(
	L"암석포",
	SkillGroup::Attack,
	150,
	90,
	5,
	PokemonType::Rock,
	BattleEffectGroup::Recoil,
	1,
	100)
		});

	_skillContainer.insert({ L"스톤에지", new Skill(
	L"스톤에지",
	SkillGroup::Attack,
	100,
	80,
	5,
	PokemonType::Rock,
	BattleEffectGroup::Critical,
	1,
	100)
		});

	_skillContainer.insert({ L"양날박치기", new Skill(
	L"양날박치기",
	SkillGroup::Attack,
	150,
	80,
	5,
	PokemonType::Rock,
	BattleEffectGroup::DamageRecoil,
	2,
	100)
		});

	_skillContainer.insert({ L"전기쇼크", new Skill(
	L"전기쇼크",
	SkillGroup::Attack,
	40,
	100,
	30,
	PokemonType::Electric,
	BattleEffectGroup::Paralysis,
	2,
	10)
		});

	_skillContainer.insert({ L"스파크", new Skill(
	L"스파크",
	SkillGroup::Attack,
	65,
	100,
	20,
	PokemonType::Electric,
	BattleEffectGroup::Paralysis,
	2,
	30)
		});

	_skillContainer.insert({ L"차지빔", new Skill(
	L"차지빔",
	SkillGroup::Attack,
	50,
	90,
	10,
	PokemonType::Electric,
	BattleEffectGroup::MyAtkUp,
	1,
	70)
		});

	_skillContainer.insert({ L"일렉트릭네트", new Skill(
	L"일렉트릭네트",
	SkillGroup::Attack,
	55,
	95,
	15,
	PokemonType::Electric,
	BattleEffectGroup::SPERankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"전격파", new Skill(
	L"전격파",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Electric,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"번개펀치", new Skill(
	L"번개펀치",
	SkillGroup::Attack,
	75,
	100,
	15,
	PokemonType::Electric,
	BattleEffectGroup::Paralysis,
	1,
	10)
		});

	_skillContainer.insert({ L"10만볼트", new Skill(
	L"10만볼트",
	SkillGroup::Attack,
	90,
	100,
	15,
	PokemonType::Electric,
	BattleEffectGroup::Paralysis,
	1,
	10)
		});

	_skillContainer.insert({ L"방전", new Skill(
	L"방전",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Electric,
	BattleEffectGroup::Paralysis,
	1,
	30)
		});

	_skillContainer.insert({ L"와일드볼트", new Skill(
	L"와일드볼트",
	SkillGroup::Attack,
	90,
	100,
	15,
	PokemonType::Electric,
	BattleEffectGroup::DamageRecoil,
	4,
	100)
		});

	_skillContainer.insert({ L"볼트태클", new Skill(
	L"볼트태클",
	SkillGroup::Attack,
	120,
	100,
	15,
	PokemonType::Electric,
	BattleEffectGroup::DamageRecoil,
	3,
	100)
		});

	_skillContainer.insert({ L"전자포", new Skill(
	L"전자포",
	SkillGroup::Attack,
	120,
	50,
	5,
	PokemonType::Electric,
	BattleEffectGroup::Paralysis,
	3,
	100)
		});

	_skillContainer.insert({ L"번개", new Skill(
	L"번개",
	SkillGroup::Attack,
	110,
	70,
	10,
	PokemonType::Electric,
	BattleEffectGroup::Paralysis,
	3,
	30)
		});

	_skillContainer.insert({ L"환상빔", new Skill(
	L"환상빔",
	SkillGroup::Attack,
	65,
	100,
	20,
	PokemonType::Psychic,
	BattleEffectGroup::Confusion,
	3,
	10)
		});

	_skillContainer.insert({ L"염동력", new Skill(
	L"염동력",
	SkillGroup::Attack,
	50,
	100,
	25,
	PokemonType::Psychic,
	BattleEffectGroup::Confusion,
	3,
	10)
		});

	_skillContainer.insert({ L"고속이동", new Skill(
	L"고속이동",
	SkillGroup::Status,
	0,
	100,
	30,
	PokemonType::Psychic,
	BattleEffectGroup::MySEPUp,
	3,
	100)
		});

	_skillContainer.insert({ L"하트스탬프", new Skill(
	L"하트스탬프",
	SkillGroup::Attack,
	60,
	100,
	25,
	PokemonType::Psychic,
	BattleEffectGroup::Flinch,
	3,
	30)
		});

	_skillContainer.insert({ L"사이코팽", new Skill(
	L"사이코팽",
	SkillGroup::Attack,
	85,
	100,
	10,
	PokemonType::Psychic,
	BattleEffectGroup::None,
	3,
	100)
		});

	_skillContainer.insert({ L"사이코쇼크", new Skill(
	L"사이코쇼크",
	SkillGroup::Attack,
	80,
	100,
	10,
	PokemonType::Psychic,
	BattleEffectGroup::None,
	3,
	100)
		});

	_skillContainer.insert({ L"사념의박치기", new Skill(
	L"사념의박치기",
	SkillGroup::Attack,
	80,
	90,
	15,
	PokemonType::Psychic,
	BattleEffectGroup::Flinch,
	3,
	20)
		});

	_skillContainer.insert({ L"사이코커터", new Skill(
	L"사이코커터",
	SkillGroup::Attack,
	70,
	100,
	20,
	PokemonType::Psychic,
	BattleEffectGroup::Critical,
	3,
	100)
		});

	_skillContainer.insert({ L"신통력", new Skill(
	L"신통력",
	SkillGroup::Attack,
	80,
	100,
	20,
	PokemonType::Psychic,
	BattleEffectGroup::Critical,
	3,
	10)
		});

	_skillContainer.insert({ L"사이코키네시스", new Skill(
	L"사이코키네시스",
	SkillGroup::Attack,
	90,
	100,
	10,
	PokemonType::Psychic,
	BattleEffectGroup::DEFRankDown,
	1,
	10)
		});

	_skillContainer.insert({ L"눈싸라기", new Skill(
	L"눈싸라기",
	SkillGroup::Attack,
	40,
	100,
	25,
	PokemonType::Ice,
	BattleEffectGroup::Freeze,
	1,
	10)
		});

	_skillContainer.insert({ L"고드름침", new Skill(
	L"고드름침",
	SkillGroup::Attack,
	25,
	100,
	30,
	PokemonType::Ice,
	BattleEffectGroup::Continue,
	1,
	100)
		});

	_skillContainer.insert({ L"얼음뭉치", new Skill(
	L"얼음뭉치",
	SkillGroup::Attack,
	40,
	100,
	30,
	PokemonType::Ice,
	BattleEffectGroup::ActionPriority,
	1,
	100)
		});

	_skillContainer.insert({ L"얼음엄니", new Skill(
	L"얼음엄니",
	SkillGroup::Attack,
	65,
	95,
	15,
	PokemonType::Ice,
	BattleEffectGroup::Freeze,
	1,
	10)
		});

	_skillContainer.insert({ L"프리즈드라이", new Skill(
	L"프리즈드라이",
	SkillGroup::Attack,
	70,
	100,
	20,
	PokemonType::Ice,
	BattleEffectGroup::Freeze,
	1,
	10)
		});

	_skillContainer.insert({ L"냉동펀치", new Skill(
	L"냉동펀치",
	SkillGroup::Attack,
	75,
	100,
	15,
	PokemonType::Ice,
	BattleEffectGroup::Freeze,
	1,
	10)
		});

	_skillContainer.insert({ L"고드름떨구기", new Skill(
	L"고드름떨구기",
	SkillGroup::Attack,
	85,
	90,
	10,
	PokemonType::Ice,
	BattleEffectGroup::Flinch,
	1,
	30)
		});

	_skillContainer.insert({ L"아이스해머", new Skill(
	L"아이스해머",
	SkillGroup::Attack,
	100,
	90,
	10,
	PokemonType::Ice,
	BattleEffectGroup::MySPEDown,
	1,
	100)
		});

	_skillContainer.insert({ L"눈보라", new Skill(
	L"눈보라",
	SkillGroup::Attack,
	110,
	70,
	5,
	PokemonType::Ice,
	BattleEffectGroup::Freeze,
	1,
	10)
		});

	_skillContainer.insert({ L"냉동빔", new Skill(
	L"냉동빔",
	SkillGroup::Attack,
	90,
	100,
	10,
	PokemonType::Ice,
	BattleEffectGroup::Freeze,
	1,
	10)
		});

	_skillContainer.insert({ L"따라가때리기", new Skill(
	L"따라가때리기",
	SkillGroup::Attack,
	40,
	100,
	20,
	PokemonType::Dark,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"탁쳐서떨구기", new Skill(
	L"탁쳐서떨구기",
	SkillGroup::Attack,
	65,
	100,
	20,
	PokemonType::Dark,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"승부굳히기", new Skill(
	L"승부굳히기",
	SkillGroup::Attack,
	60,
	100,
	10,
	PokemonType::Dark,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"바크아웃", new Skill(
	L"바크아웃",
	SkillGroup::Attack,
	55,
	95,
	15,
	PokemonType::Dark,
	BattleEffectGroup::AtkRankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"세차게휘두르기", new Skill(
	L"세차게휘두르기",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Dark,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"지옥찌르기", new Skill(
	L"지옥찌르기",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Dark,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"나이트버스트", new Skill(
	L"나이트버스트",
	SkillGroup::Attack,
	85,
	95,
	10,
	PokemonType::Dark,
	BattleEffectGroup::AccuracyDown,
	1,
	40)
		});

	_skillContainer.insert({ L"깨물어부수기", new Skill(
	L"깨물어부수기",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Dark,
	BattleEffectGroup::DEFRankDown,
	1,
	20)
		});

	_skillContainer.insert({ L"바람일으키기", new Skill(
	L"바람일으키기",
	SkillGroup::Attack,
	40,
	100,
	35,
	PokemonType::Flying,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"날개치기", new Skill(
	L"날개치기",
	SkillGroup::Attack,
	60,
	100,
	35,
	PokemonType::Flying,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"에어컷터", new Skill(
	L"에어컷터",
	SkillGroup::Attack,
	60,
	95,
	25,
	PokemonType::Flying,
	BattleEffectGroup::Critical,
	1,
	100)
		});

	_skillContainer.insert({ L"쪼기", new Skill(
	L"쪼기",
	SkillGroup::Attack,
	35,
	100,
	35,
	PokemonType::Flying,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"회전부리", new Skill(
	L"회전부리",
	SkillGroup::Attack,
	35,
	100,
	35,
	PokemonType::Flying,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"제비반환", new Skill(
	L"제비반환",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Flying,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"쪼아대기", new Skill(
	L"쪼아대기",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Flying,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"에어슬래시", new Skill(
	L"에어슬래시",
	SkillGroup::Attack,
	75,
	95,
	15,
	PokemonType::Flying,
	BattleEffectGroup::Flinch,
	1,
	30)
		});

	_skillContainer.insert({ L"폭풍", new Skill(
	L"폭풍",
	SkillGroup::Attack,
	110,
	70,
	10,
	PokemonType::Flying,
	BattleEffectGroup::Confusion,
	1,
	30)
		});

	_skillContainer.insert({ L"애크러뱃", new Skill(
	L"애크러뱃",
	SkillGroup::Attack,
	55,
	100,
	15,
	PokemonType::Flying,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"브레이브버드", new Skill(
	L"브레이브버드",
	SkillGroup::Attack,
	120,
	100,
	15,
	PokemonType::Flying,
	BattleEffectGroup::DamageRecoil,
	3,
	100)
		});

	_skillContainer.insert({ L"더블니들", new Skill(
	L"더블니들",
	SkillGroup::Attack,
	25,
	100,
	20,
	PokemonType::Bug,
	BattleEffectGroup::None,
	3,
	100)
		});

	_skillContainer.insert({ L"연속자르기", new Skill(
	L"연속자르기",
	SkillGroup::Attack,
	40,
	95,
	20,
	PokemonType::Bug,
	BattleEffectGroup::None,
	3,
	100)
		});

	_skillContainer.insert({ L"은빛바람", new Skill(
	L"은빛바람",
	SkillGroup::Attack,
	60,
	100,
	5,
	PokemonType::Bug,
	BattleEffectGroup::MyStatAllUp,
	3,
	10)
		});

	_skillContainer.insert({ L"벌레의저항", new Skill(
	L"벌레의저항",
	SkillGroup::Attack,
	50,
	100,
	20,
	PokemonType::Bug,
	BattleEffectGroup::AtkRankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"벌레의야단법석", new Skill(
	L"벌레의야단법석",
	SkillGroup::Attack,
	90,
	100,
	10,
	PokemonType::Bug,
	BattleEffectGroup::AtkRankDown,
	1,
	10)
		});

	_skillContainer.insert({ L"시저크로스", new Skill(
	L"시저크로스",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Bug,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"시그널빔", new Skill(
	L"시그널빔",
	SkillGroup::Attack,
	75,
	100,
	15,
	PokemonType::Bug,
	BattleEffectGroup::Confusion,
	1,
	10)
		});

	_skillContainer.insert({ L"흡혈", new Skill(
	L"흡혈",
	SkillGroup::Attack,
	80,
	100,
	10,
	PokemonType::Bug,
	BattleEffectGroup::Drain,
	2,
	100)
		});

	_skillContainer.insert({ L"메가폰", new Skill(
	L"메가폰",
	SkillGroup::Attack,
	120,
	85,
	10,
	PokemonType::Bug,
	BattleEffectGroup::None,
	2,
	100)
		});

	_skillContainer.insert({ L"덤벼들기", new Skill(
	L"덤벼들기",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Bug,
	BattleEffectGroup::AtkRankDown,
	1,
	100)
		});

	_skillContainer.insert({ L"용의숨결", new Skill(
	L"용의숨결",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Dragon,
	BattleEffectGroup::Paralysis,
	1,
	30)
		});

	_skillContainer.insert({ L"회오리", new Skill(
	L"회오리",
	SkillGroup::Attack,
	40,
	100,
	20,
	PokemonType::Dragon,
	BattleEffectGroup::Flinch,
	1,
	20)
		});

	_skillContainer.insert({ L"더블촙", new Skill(
	L"더블촙",
	SkillGroup::Attack,
	40,
	90,
	15,
	PokemonType::Dragon,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"드래곤테일", new Skill(
	L"드래곤테일",
	SkillGroup::Attack,
	60,
	90,
	10,
	PokemonType::Dragon,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"용의파동", new Skill(
	L"용의파동",
	SkillGroup::Attack,
	85,
	100,
	10,
	PokemonType::Dragon,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"드래곤크루", new Skill(
	L"드래곤크루",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Dragon,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"용의춤", new Skill(
	L"용의춤",
	SkillGroup::Status,
	0,
	100,
	20,
	PokemonType::Dragon,
	BattleEffectGroup::MyA_SUp,
	1,
	100)
		});

	_skillContainer.insert({ L"역린", new Skill(
	L"역린",
	SkillGroup::Attack,
	120,
	100,
	10,
	PokemonType::Dragon,
	BattleEffectGroup::MyConfusion,
	1,
	100)
		});

	_skillContainer.insert({ L"드래곤다이브", new Skill(
	L"드래곤다이브",
	SkillGroup::Attack,
	100,
	75,
	10,
	PokemonType::Dragon,
	BattleEffectGroup::Flinch,
	1,
	20)
		});

	_skillContainer.insert({ L"용성군", new Skill(
	L"용성군",
	SkillGroup::Attack,
	130,
	90,
	5,
	PokemonType::Dragon,
	BattleEffectGroup::MyAtkDown,
	2,
	20)
		});

	_skillContainer.insert({ L"독침", new Skill(
	L"독침",
	SkillGroup::Attack,
	15,
	100,
	35,
	PokemonType::Poison,
	BattleEffectGroup::Poison,
	2,
	30)
		});

	_skillContainer.insert({ L"용해액", new Skill(
	L"용해액",
	SkillGroup::Attack,
	40,
	100,
	30,
	PokemonType::Poison,
	BattleEffectGroup::DEFRankDown,
	2,
	10)
		});

	_skillContainer.insert({ L"독엄니", new Skill(
	L"독엄니",
	SkillGroup::Attack,
	50,
	100,
	15,
	PokemonType::Poison,
	BattleEffectGroup::Poison,
	2,
	50)
		});

	_skillContainer.insert({ L"포이즌테일", new Skill(
	L"포이즌테일",
	SkillGroup::Attack,
	50,
	100,
	25,
	PokemonType::Poison,
	BattleEffectGroup::Poison,
	2,
	10)
		});

	_skillContainer.insert({ L"크로스포이즌", new Skill(
	L"크로스포이즌",
	SkillGroup::Attack,
	70,
	100,
	20,
	PokemonType::Poison,
	BattleEffectGroup::Poison,
	2,
	10)
		});

	_skillContainer.insert({ L"오물폭탄", new Skill(
	L"오물폭탄",
	SkillGroup::Attack,
	90,
	100,
	10,
	PokemonType::Poison,
	BattleEffectGroup::Poison,
	2,
	30)
		});

	_skillContainer.insert({ L"오물웨이브", new Skill(
	L"오물웨이브",
	SkillGroup::Attack,
	95,
	100,
	10,
	PokemonType::Poison,
	BattleEffectGroup::Poison,
	2,
	10)
		});

	_skillContainer.insert({ L"트림", new Skill(
	L"트림",
	SkillGroup::Attack,
	120,
	90,
	10,
	PokemonType::Poison,
	BattleEffectGroup::None,
	2,
	100)
		});

	_skillContainer.insert({ L"더스트슈트", new Skill(
	L"더스트슈트",
	SkillGroup::Attack,
	120,
	80,
	5,
	PokemonType::Poison,
	BattleEffectGroup::Poison,
	2,
	30)
		});

	_skillContainer.insert({ L"나이트헤드", new Skill(
	L"나이트헤드",
	SkillGroup::Attack,
	0,
	100,
	5,
	PokemonType::Ghost,
	BattleEffectGroup::LvDamage,
	1,
	100)
		});

	_skillContainer.insert({ L"핥기", new Skill(
	L"핥기",
	SkillGroup::Attack,
	30,
	100,
	30,
	PokemonType::Ghost,
	BattleEffectGroup::Paralysis,
	1,
	30)
		});

	_skillContainer.insert({ L"놀래키기", new Skill(
	L"놀래키기",
	SkillGroup::Attack,
	30,
	100,
	15,
	PokemonType::Ghost,
	BattleEffectGroup::Flinch,
	1,
	30)
		});

	_skillContainer.insert({ L"야습", new Skill(
	L"야습",
	SkillGroup::Attack,
	40,
	100,
	30,
	PokemonType::Ghost,
	BattleEffectGroup::ActionPriority,
	1,
	100)
		});

	_skillContainer.insert({ L"새도펀치", new Skill(
	L"새도펀치",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Ghost,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"병상첨병", new Skill(
	L"병상첨병",
	SkillGroup::Attack,
	65,
	100,
	10,
	PokemonType::Ghost,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"섀도크루", new Skill(
	L"섀도크루",
	SkillGroup::Attack,
	70,
	100,
	15,
	PokemonType::Ghost,
	BattleEffectGroup::Critical,
	1,
	100)
		});

	_skillContainer.insert({ L"섀도볼", new Skill(
	L"섀도볼",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Ghost,
	BattleEffectGroup::DEFRankDown,
	1,
	20)
		});

	_skillContainer.insert({ L"괴상한바람", new Skill(
	L"괴상한바람",
	SkillGroup::Attack,
	60,
	100,
	5,
	PokemonType::Ghost,
	BattleEffectGroup::MyStatAllUp,
	1,
	100)
		});

	_skillContainer.insert({ L"메탈크로우", new Skill(
	L"메탈크로우",
	SkillGroup::Attack,
	50,
	95,
	35,
	PokemonType::Steel,
	BattleEffectGroup::MyAtkDown,
	1,
	10)
		});

	_skillContainer.insert({ L"불릿펀치", new Skill(
	L"불릿펀치",
	SkillGroup::Attack,
	40,
	100,
	30,
	PokemonType::Steel,
	BattleEffectGroup::ActionPriority,
	1,
	100)
		});

	_skillContainer.insert({ L"기어소서", new Skill(
	L"기어소서",
	SkillGroup::Attack,
	50,
	85,
	10,
	PokemonType::Steel,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"마그넷봄", new Skill(
	L"마그넷봄",
	SkillGroup::Attack,
	60,
	100,
	20,
	PokemonType::Steel,
	BattleEffectGroup::None,
	1,
	100)
		});

	_skillContainer.insert({ L"아이언헤드", new Skill(
	L"아이언헤드",
	SkillGroup::Attack,
	80,
	100,
	15,
	PokemonType::Steel,
	BattleEffectGroup::Flinch,
	1,
	30)
		});

	_skillContainer.insert({ L"러스터캐논", new Skill(
	L"러스터캐논",
	SkillGroup::Attack,
	80,
	100,
	10,
	PokemonType::Steel,
	BattleEffectGroup::DEFRankDown,
	1,
	10)
		});

	_skillContainer.insert({ L"미러숏", new Skill(
	L"미러숏",
	SkillGroup::Attack,
	65,
	85,
	10,
	PokemonType::Steel,
	BattleEffectGroup::AccuracyDown,
	1,
	30)
		});

	_skillContainer.insert({ L"코멧펀치", new Skill(
	L"코멧펀치",
	SkillGroup::Attack,
	90,
	90,
	10,
	PokemonType::Steel,
	BattleEffectGroup::MyAtkUp,
	1,
	20)
		});

	_skillContainer.insert({ L"아이언테일", new Skill(
	L"아이언테일",
	SkillGroup::Attack,
	100,
	75,
	15,
	PokemonType::Steel,
	BattleEffectGroup::DEFRankDown,
	1,
	30)
		});

	_skillContainer.insert({ L"강철날개", new Skill(
	L"강철날개",
	SkillGroup::Attack,
	70,
	90,
	25,
	PokemonType::Steel,
	BattleEffectGroup::MyDEFUp,
	1,
	10)
		});
}

vector<wstring> SkillManager::LearnSkill(vector<PokemonType> types, int evolutionCount)
{

	int len = 4 / types.size();
	vector<wstring> result;

	for (int k = 0; k < types.size(); k++) {

		auto type = types[k];

		//복사로 가져오기
		auto container = _learnSkillContainer[type][evolutionCount];

		for (int i = 0; i < 1000; i++) {

			int idx1 = rand() % container.size();
			int idx2 = rand() % container.size();

			std::swap(container[idx1], container[idx2]);

		}

		for (int i = 0; i < len; i++) {


			result.push_back(container[i]);

		}

	}

	return result;

}