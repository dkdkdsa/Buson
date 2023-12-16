#include "pch.h"
#include "ResMgr.h"
#include "PathMgr.h"
#include "Texture.h"

Texture* ResMgr::FindPokemonTexture(const wstring& key, const PokemonSprite_Type& type)
{

    auto &curkey = _pokemonTextureContainer[key][type];

    return TexFind(curkey);

}

Texture* ResMgr::TexLoad(const wstring& _strKey, const wstring& _strRelativePath)
{
    // 잘 찾았으면 그거 던져주기
    Texture* pTex = TexFind(_strKey);
    if (nullptr != pTex)
        return pTex;

    // 처음에는 없을거니까.. 경로 찾아서
    wstring strFilepath = PathMgr::GetInst()->GetResPath();
    strFilepath += _strRelativePath;
    // 만들어줘가지고..
    pTex = new Texture;
    pTex->Load(strFilepath); // 텍스처 자체를 로드..
    pTex->SetKey(_strKey); // 키 경로 세팅해두고..
    pTex->SetRelativePath(_strRelativePath);
    m_mapTex.insert({ _strKey,pTex }); // 그거를 맵에다가 저장.
    return pTex;
}

Texture* ResMgr::TexFind(const wstring& _strKey)
{
    // 찾아서 return
    auto iter = m_mapTex.find(_strKey);
    if (iter != m_mapTex.end())
    {
        return iter->second;
    }
    return nullptr;
}

void ResMgr::Release()
{
    // Texture
    map<wstring, Texture*>::iterator iter;
    for (iter = m_mapTex.begin(); iter != m_mapTex.end(); ++iter)
    {
        if (nullptr != iter->second)
            delete iter->second;
    }
    m_mapTex.clear();

    // SOUND
    map<wstring, tSoundInfo*>::iterator itersod;
    for (itersod = m_mapSod.begin(); itersod != m_mapSod.end(); ++itersod)
    {
        if (nullptr != itersod->second)
            delete itersod->second;
    }
    m_mapSod.clear();

    // 다 쓰고 난 후 시스템 닫고 반환
    m_pSystem->close();
    m_pSystem->release();
}

void ResMgr::Init()
{
    FMOD::System_Create(&m_pSystem); // 시스템 생성 함수
    // 채널수, 사운드 모드
    if (m_pSystem != nullptr)
        m_pSystem->init((int)SOUND_CHANNEL::END, FMOD_INIT_NORMAL, nullptr);

    LoadSound(L"ButtonClick", L"Sound\\UI\\ButtonClick.wav", false);

    CreatePokemonTexture();

}

void ResMgr::LoadSound(const wstring& _strKey, const wstring& _strReleativePath, bool _IsLoop)
{
    if (FindSound(_strKey))
        return;
    wstring strFilePath = PathMgr::GetInst()->GetResPath();
    strFilePath += _strReleativePath;

    // wstring to string
    std::string str;
    str.assign(strFilePath.begin(), strFilePath.end());

    // 루프할지 말지 결정
    FMOD_MODE eMode = FMOD_LOOP_NORMAL; // 반복 출력
    if (!_IsLoop)
        eMode = FMOD_DEFAULT; // 사운드 1번만 출력

    tSoundInfo* ptSound = new tSoundInfo;
    ptSound->IsLoop = _IsLoop;
    // 사운드 객체를 만드는 것은 system임.
                            //파일경로,  FMOD_MODE, NULL, &sound
    m_pSystem->createSound(str.c_str(), eMode, nullptr, &ptSound->pSound);
    m_mapSod.insert({ _strKey, ptSound });
}

void ResMgr::Play(const wstring& _strKey)
{
    tSoundInfo* ptSound = FindSound(_strKey);
    if (!ptSound)
        return;
    m_pSystem->update(); // play할때 update를 주기적으로 호출해야 사운드가 정지되지 않음.
    SOUND_CHANNEL eChannel = SOUND_CHANNEL::BGM;
    if (!ptSound->IsLoop)
        eChannel = SOUND_CHANNEL::EFFECT;
    // 사운드 재생 함수. &channel로 어떤 채널을 통해 재생되는지 포인터 넘김
    m_pSystem->playSound(ptSound->pSound, nullptr, false, &m_pChannel[(UINT)eChannel]);

}

void ResMgr::Stop(SOUND_CHANNEL _eChannel)
{
    m_pChannel[(UINT)_eChannel]->stop();
}

void ResMgr::Volume(SOUND_CHANNEL _eChannel, float _fVol)
{
    // 0.0 ~ 1.0 볼륨 조절
    m_pChannel[(UINT)_eChannel]->setVolume(_fVol);
}

void ResMgr::Pause(SOUND_CHANNEL _eChannel, bool _Ispause)
{
    // bool값이 true면 일시정지. 단, 이 함수를 쓰려면 Createsound할때 
    // FMOD_MODE가 FMOD_LOOP_NORMAL 이어야 함.
    m_pChannel[(UINT)_eChannel]->setPaused(_Ispause);
}

HFONT ResMgr::LoadFont(const wstring& path, const wstring& fontName, int fontSize)
{

    wstring strFilepath = PathMgr::GetInst()->GetResPath();
    strFilepath += path;

    AddFontResource(path.c_str());

    return CreateFont(fontSize, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH
        | FF_ROMAN, fontName.c_str());

}

tSoundInfo* ResMgr::FindSound(const wstring& _strKey)
{
    map<wstring, tSoundInfo*>::iterator iter = m_mapSod.find(_strKey);

    if (iter == m_mapSod.end())
        return nullptr;
    return iter->second;
}

void ResMgr::CreatePokemonTexture()
{



    //field
    TexLoad(L"001_Field", L"Texture\\Pokemon\\001_Field.bmp");
    TexLoad(L"002_Field", L"Texture\\Pokemon\\002_Field.bmp");
    TexLoad(L"003_Field", L"Texture\\Pokemon\\003_Field.bmp");
    TexLoad(L"004_Field", L"Texture\\Pokemon\\004_Field.bmp");
    TexLoad(L"005_Field", L"Texture\\Pokemon\\005_Field.bmp");
    TexLoad(L"006_Field", L"Texture\\Pokemon\\006_Field.bmp");
    TexLoad(L"007_Field", L"Texture\\Pokemon\\007_Field.bmp");
    TexLoad(L"008_Field", L"Texture\\Pokemon\\008_Field.bmp");
    TexLoad(L"009_Field", L"Texture\\Pokemon\\009_Field.bmp");
    TexLoad(L"010_Field", L"Texture\\Pokemon\\010_Field.bmp");
    TexLoad(L"011_Field", L"Texture\\Pokemon\\011_Field.bmp");
    TexLoad(L"012_Field", L"Texture\\Pokemon\\012_Field.bmp");
    TexLoad(L"013_Field", L"Texture\\Pokemon\\013_Field.bmp");
    TexLoad(L"014_Field", L"Texture\\Pokemon\\014_Field.bmp");
    TexLoad(L"015_Field", L"Texture\\Pokemon\\015_Field.bmp");
    TexLoad(L"016_Field", L"Texture\\Pokemon\\016_Field.bmp");
    TexLoad(L"017_Field", L"Texture\\Pokemon\\017_Field.bmp");
    TexLoad(L"018_Field", L"Texture\\Pokemon\\018_Field.bmp");
    TexLoad(L"019_Field", L"Texture\\Pokemon\\019_Field.bmp");
    TexLoad(L"020_Field", L"Texture\\Pokemon\\020_Field.bmp");
    TexLoad(L"021_Field", L"Texture\\Pokemon\\021_Field.bmp");
    TexLoad(L"022_Field", L"Texture\\Pokemon\\022_Field.bmp");
    TexLoad(L"023_Field", L"Texture\\Pokemon\\023_Field.bmp");
    TexLoad(L"024_Field", L"Texture\\Pokemon\\024_Field.bmp");
    TexLoad(L"025_Field", L"Texture\\Pokemon\\025_Field.bmp");
    TexLoad(L"026_Field", L"Texture\\Pokemon\\026_Field.bmp");
    TexLoad(L"027_Field", L"Texture\\Pokemon\\027_Field.bmp");
    TexLoad(L"028_Field", L"Texture\\Pokemon\\028_Field.bmp");
    TexLoad(L"029_Field", L"Texture\\Pokemon\\029_Field.bmp");
    TexLoad(L"030_Field", L"Texture\\Pokemon\\030_Field.bmp");
    TexLoad(L"031_Field", L"Texture\\Pokemon\\031_Field.bmp");
    TexLoad(L"032_Field", L"Texture\\Pokemon\\032_Field.bmp");
    TexLoad(L"033_Field", L"Texture\\Pokemon\\033_Field.bmp");
    TexLoad(L"034_Field", L"Texture\\Pokemon\\034_Field.bmp");
    TexLoad(L"035_Field", L"Texture\\Pokemon\\035_Field.bmp");
    TexLoad(L"036_Field", L"Texture\\Pokemon\\036_Field.bmp");
    TexLoad(L"037_Field", L"Texture\\Pokemon\\037_Field.bmp");
    TexLoad(L"038_Field", L"Texture\\Pokemon\\038_Field.bmp");
    TexLoad(L"039_Field", L"Texture\\Pokemon\\039_Field.bmp");
    TexLoad(L"040_Field", L"Texture\\Pokemon\\040_Field.bmp");
    TexLoad(L"041_Field", L"Texture\\Pokemon\\041_Field.bmp");
    TexLoad(L"042_Field", L"Texture\\Pokemon\\042_Field.bmp");
    TexLoad(L"043_Field", L"Texture\\Pokemon\\043_Field.bmp");
    TexLoad(L"044_Field", L"Texture\\Pokemon\\044_Field.bmp");
    TexLoad(L"045_Field", L"Texture\\Pokemon\\045_Field.bmp");
    TexLoad(L"046_Field", L"Texture\\Pokemon\\046_Field.bmp");
    TexLoad(L"047_Field", L"Texture\\Pokemon\\047_Field.bmp");
    TexLoad(L"048_Field", L"Texture\\Pokemon\\048_Field.bmp");
    TexLoad(L"049_Field", L"Texture\\Pokemon\\049_Field.bmp");
    TexLoad(L"050_Field", L"Texture\\Pokemon\\050_Field.bmp");
    TexLoad(L"051_Field", L"Texture\\Pokemon\\051_Field.bmp");
    TexLoad(L"052_Field", L"Texture\\Pokemon\\052_Field.bmp");
    TexLoad(L"053_Field", L"Texture\\Pokemon\\053_Field.bmp");
    TexLoad(L"054_Field", L"Texture\\Pokemon\\054_Field.bmp");
    TexLoad(L"055_Field", L"Texture\\Pokemon\\055_Field.bmp");
    TexLoad(L"056_Field", L"Texture\\Pokemon\\056_Field.bmp");
    TexLoad(L"057_Field", L"Texture\\Pokemon\\057_Field.bmp");
    TexLoad(L"058_Field", L"Texture\\Pokemon\\058_Field.bmp");
    TexLoad(L"059_Field", L"Texture\\Pokemon\\059_Field.bmp");
    TexLoad(L"060_Field", L"Texture\\Pokemon\\060_Field.bmp");
    TexLoad(L"061_Field", L"Texture\\Pokemon\\061_Field.bmp");
    TexLoad(L"062_Field", L"Texture\\Pokemon\\062_Field.bmp");
    TexLoad(L"063_Field", L"Texture\\Pokemon\\063_Field.bmp");
    TexLoad(L"064_Field", L"Texture\\Pokemon\\064_Field.bmp");
    TexLoad(L"065_Field", L"Texture\\Pokemon\\065_Field.bmp");
    TexLoad(L"066_Field", L"Texture\\Pokemon\\066_Field.bmp");
    TexLoad(L"067_Field", L"Texture\\Pokemon\\067_Field.bmp");
    TexLoad(L"068_Field", L"Texture\\Pokemon\\068_Field.bmp");
    TexLoad(L"069_Field", L"Texture\\Pokemon\\069_Field.bmp");
    TexLoad(L"070_Field", L"Texture\\Pokemon\\070_Field.bmp");
    TexLoad(L"071_Field", L"Texture\\Pokemon\\071_Field.bmp");
    TexLoad(L"072_Field", L"Texture\\Pokemon\\072_Field.bmp");
    TexLoad(L"073_Field", L"Texture\\Pokemon\\073_Field.bmp");
    TexLoad(L"074_Field", L"Texture\\Pokemon\\074_Field.bmp");
    TexLoad(L"075_Field", L"Texture\\Pokemon\\075_Field.bmp");
    TexLoad(L"076_Field", L"Texture\\Pokemon\\076_Field.bmp");
    TexLoad(L"077_Field", L"Texture\\Pokemon\\077_Field.bmp");
    TexLoad(L"078_Field", L"Texture\\Pokemon\\078_Field.bmp");
    TexLoad(L"079_Field", L"Texture\\Pokemon\\079_Field.bmp");
    TexLoad(L"080_Field", L"Texture\\Pokemon\\080_Field.bmp");
    TexLoad(L"081_Field", L"Texture\\Pokemon\\081_Field.bmp");
    TexLoad(L"082_Field", L"Texture\\Pokemon\\082_Field.bmp");
    TexLoad(L"083_Field", L"Texture\\Pokemon\\083_Field.bmp");
    TexLoad(L"084_Field", L"Texture\\Pokemon\\084_Field.bmp");
    TexLoad(L"085_Field", L"Texture\\Pokemon\\085_Field.bmp");
    TexLoad(L"086_Field", L"Texture\\Pokemon\\086_Field.bmp");
    TexLoad(L"087_Field", L"Texture\\Pokemon\\087_Field.bmp");
    TexLoad(L"088_Field", L"Texture\\Pokemon\\088_Field.bmp");
    TexLoad(L"089_Field", L"Texture\\Pokemon\\089_Field.bmp");
    TexLoad(L"090_Field", L"Texture\\Pokemon\\090_Field.bmp");
    TexLoad(L"091_Field", L"Texture\\Pokemon\\091_Field.bmp");
    TexLoad(L"092_Field", L"Texture\\Pokemon\\092_Field.bmp");
    TexLoad(L"093_Field", L"Texture\\Pokemon\\093_Field.bmp");
    TexLoad(L"094_Field", L"Texture\\Pokemon\\094_Field.bmp");
    TexLoad(L"095_Field", L"Texture\\Pokemon\\095_Field.bmp");
    TexLoad(L"096_Field", L"Texture\\Pokemon\\096_Field.bmp");
    TexLoad(L"097_Field", L"Texture\\Pokemon\\097_Field.bmp");
    TexLoad(L"098_Field", L"Texture\\Pokemon\\098_Field.bmp");
    TexLoad(L"099_Field", L"Texture\\Pokemon\\099_Field.bmp");
    TexLoad(L"100_Field", L"Texture\\Pokemon\\100_Field.bmp");
    TexLoad(L"101_Field", L"Texture\\Pokemon\\101_Field.bmp");
    TexLoad(L"102_Field", L"Texture\\Pokemon\\102_Field.bmp");
    TexLoad(L"103_Field", L"Texture\\Pokemon\\103_Field.bmp");
    TexLoad(L"104_Field", L"Texture\\Pokemon\\104_Field.bmp");
    TexLoad(L"105_Field", L"Texture\\Pokemon\\105_Field.bmp");
    TexLoad(L"106_Field", L"Texture\\Pokemon\\106_Field.bmp");
    TexLoad(L"107_Field", L"Texture\\Pokemon\\107_Field.bmp");
    TexLoad(L"108_Field", L"Texture\\Pokemon\\108_Field.bmp");
    TexLoad(L"109_Field", L"Texture\\Pokemon\\109_Field.bmp");
    TexLoad(L"110_Field", L"Texture\\Pokemon\\110_Field.bmp");
    TexLoad(L"111_Field", L"Texture\\Pokemon\\111_Field.bmp");
    TexLoad(L"112_Field", L"Texture\\Pokemon\\112_Field.bmp");
    TexLoad(L"113_Field", L"Texture\\Pokemon\\113_Field.bmp");
    TexLoad(L"114_Field", L"Texture\\Pokemon\\114_Field.bmp");
    TexLoad(L"115_Field", L"Texture\\Pokemon\\115_Field.bmp");
    TexLoad(L"116_Field", L"Texture\\Pokemon\\116_Field.bmp");
    TexLoad(L"117_Field", L"Texture\\Pokemon\\117_Field.bmp");
    TexLoad(L"118_Field", L"Texture\\Pokemon\\118_Field.bmp");
    TexLoad(L"119_Field", L"Texture\\Pokemon\\119_Field.bmp");
    TexLoad(L"120_Field", L"Texture\\Pokemon\\120_Field.bmp");
    TexLoad(L"121_Field", L"Texture\\Pokemon\\121_Field.bmp");
    TexLoad(L"122_Field", L"Texture\\Pokemon\\122_Field.bmp");
    TexLoad(L"123_Field", L"Texture\\Pokemon\\123_Field.bmp");
    TexLoad(L"124_Field", L"Texture\\Pokemon\\124_Field.bmp");
    TexLoad(L"125_Field", L"Texture\\Pokemon\\125_Field.bmp");
    TexLoad(L"126_Field", L"Texture\\Pokemon\\126_Field.bmp");
    TexLoad(L"127_Field", L"Texture\\Pokemon\\127_Field.bmp");
    TexLoad(L"128_Field", L"Texture\\Pokemon\\128_Field.bmp");
    TexLoad(L"129_Field", L"Texture\\Pokemon\\129_Field.bmp");
    TexLoad(L"130_Field", L"Texture\\Pokemon\\130_Field.bmp");
    TexLoad(L"131_Field", L"Texture\\Pokemon\\131_Field.bmp");
    TexLoad(L"132_Field", L"Texture\\Pokemon\\132_Field.bmp");
    TexLoad(L"133_Field", L"Texture\\Pokemon\\133_Field.bmp");
    TexLoad(L"134_Field", L"Texture\\Pokemon\\134_Field.bmp");
    TexLoad(L"135_Field", L"Texture\\Pokemon\\135_Field.bmp");
    TexLoad(L"136_Field", L"Texture\\Pokemon\\136_Field.bmp");
    TexLoad(L"137_Field", L"Texture\\Pokemon\\137_Field.bmp");
    TexLoad(L"138_Field", L"Texture\\Pokemon\\138_Field.bmp");
    TexLoad(L"139_Field", L"Texture\\Pokemon\\139_Field.bmp");
    TexLoad(L"140_Field", L"Texture\\Pokemon\\140_Field.bmp");
    TexLoad(L"141_Field", L"Texture\\Pokemon\\141_Field.bmp");
    TexLoad(L"142_Field", L"Texture\\Pokemon\\142_Field.bmp");
    TexLoad(L"143_Field", L"Texture\\Pokemon\\143_Field.bmp");
    TexLoad(L"144_Field", L"Texture\\Pokemon\\144_Field.bmp");
    TexLoad(L"145_Field", L"Texture\\Pokemon\\145_Field.bmp");
    TexLoad(L"146_Field", L"Texture\\Pokemon\\146_Field.bmp");
    TexLoad(L"147_Field", L"Texture\\Pokemon\\147_Field.bmp");
    TexLoad(L"148_Field", L"Texture\\Pokemon\\148_Field.bmp");
    TexLoad(L"149_Field", L"Texture\\Pokemon\\149_Field.bmp");
    TexLoad(L"150_Field", L"Texture\\Pokemon\\150_Field.bmp");
    TexLoad(L"151_Field", L"Texture\\Pokemon\\151_Field.bmp");

    //front
    TexLoad(L"001_Battle_Front", L"Texture\\Pokemon\\001_Battle_Front.bmp");
    TexLoad(L"002_Battle_Front", L"Texture\\Pokemon\\002_Battle_Front.bmp");
    TexLoad(L"003_Battle_Front", L"Texture\\Pokemon\\003_Battle_Front.bmp");
    TexLoad(L"004_Battle_Front", L"Texture\\Pokemon\\004_Battle_Front.bmp");
    TexLoad(L"005_Battle_Front", L"Texture\\Pokemon\\005_Battle_Front.bmp");
    TexLoad(L"006_Battle_Front", L"Texture\\Pokemon\\006_Battle_Front.bmp");
    TexLoad(L"007_Battle_Front", L"Texture\\Pokemon\\007_Battle_Front.bmp");
    TexLoad(L"008_Battle_Front", L"Texture\\Pokemon\\008_Battle_Front.bmp");
    TexLoad(L"009_Battle_Front", L"Texture\\Pokemon\\009_Battle_Front.bmp");
    TexLoad(L"010_Battle_Front", L"Texture\\Pokemon\\010_Battle_Front.bmp");
    TexLoad(L"011_Battle_Front", L"Texture\\Pokemon\\011_Battle_Front.bmp");
    TexLoad(L"012_Battle_Front", L"Texture\\Pokemon\\012_Battle_Front.bmp");
    TexLoad(L"013_Battle_Front", L"Texture\\Pokemon\\013_Battle_Front.bmp");
    TexLoad(L"014_Battle_Front", L"Texture\\Pokemon\\014_Battle_Front.bmp");
    TexLoad(L"015_Battle_Front", L"Texture\\Pokemon\\015_Battle_Front.bmp");
    TexLoad(L"016_Battle_Front", L"Texture\\Pokemon\\016_Battle_Front.bmp");
    TexLoad(L"017_Battle_Front", L"Texture\\Pokemon\\017_Battle_Front.bmp");
    TexLoad(L"018_Battle_Front", L"Texture\\Pokemon\\018_Battle_Front.bmp");
    TexLoad(L"019_Battle_Front", L"Texture\\Pokemon\\019_Battle_Front.bmp");
    TexLoad(L"020_Battle_Front", L"Texture\\Pokemon\\020_Battle_Front.bmp");
    TexLoad(L"021_Battle_Front", L"Texture\\Pokemon\\021_Battle_Front.bmp");
    TexLoad(L"022_Battle_Front", L"Texture\\Pokemon\\022_Battle_Front.bmp");
    TexLoad(L"023_Battle_Front", L"Texture\\Pokemon\\023_Battle_Front.bmp");
    TexLoad(L"024_Battle_Front", L"Texture\\Pokemon\\024_Battle_Front.bmp");
    TexLoad(L"025_Battle_Front", L"Texture\\Pokemon\\025_Battle_Front.bmp");
    TexLoad(L"026_Battle_Front", L"Texture\\Pokemon\\026_Battle_Front.bmp");
    TexLoad(L"027_Battle_Front", L"Texture\\Pokemon\\027_Battle_Front.bmp");
    TexLoad(L"028_Battle_Front", L"Texture\\Pokemon\\028_Battle_Front.bmp");
    TexLoad(L"029_Battle_Front", L"Texture\\Pokemon\\029_Battle_Front.bmp");
    TexLoad(L"030_Battle_Front", L"Texture\\Pokemon\\030_Battle_Front.bmp");
    TexLoad(L"031_Battle_Front", L"Texture\\Pokemon\\031_Battle_Front.bmp");
    TexLoad(L"032_Battle_Front", L"Texture\\Pokemon\\032_Battle_Front.bmp");
    TexLoad(L"033_Battle_Front", L"Texture\\Pokemon\\033_Battle_Front.bmp");
    TexLoad(L"034_Battle_Front", L"Texture\\Pokemon\\034_Battle_Front.bmp");
    TexLoad(L"035_Battle_Front", L"Texture\\Pokemon\\035_Battle_Front.bmp");
    TexLoad(L"036_Battle_Front", L"Texture\\Pokemon\\036_Battle_Front.bmp");
    TexLoad(L"037_Battle_Front", L"Texture\\Pokemon\\037_Battle_Front.bmp");
    TexLoad(L"038_Battle_Front", L"Texture\\Pokemon\\038_Battle_Front.bmp");
    TexLoad(L"039_Battle_Front", L"Texture\\Pokemon\\039_Battle_Front.bmp");
    TexLoad(L"040_Battle_Front", L"Texture\\Pokemon\\040_Battle_Front.bmp");
    TexLoad(L"041_Battle_Front", L"Texture\\Pokemon\\041_Battle_Front.bmp");
    TexLoad(L"042_Battle_Front", L"Texture\\Pokemon\\042_Battle_Front.bmp");
    TexLoad(L"043_Battle_Front", L"Texture\\Pokemon\\043_Battle_Front.bmp");
    TexLoad(L"044_Battle_Front", L"Texture\\Pokemon\\044_Battle_Front.bmp");
    TexLoad(L"045_Battle_Front", L"Texture\\Pokemon\\045_Battle_Front.bmp");
    TexLoad(L"046_Battle_Front", L"Texture\\Pokemon\\046_Battle_Front.bmp");
    TexLoad(L"047_Battle_Front", L"Texture\\Pokemon\\047_Battle_Front.bmp");
    TexLoad(L"048_Battle_Front", L"Texture\\Pokemon\\048_Battle_Front.bmp");
    TexLoad(L"049_Battle_Front", L"Texture\\Pokemon\\049_Battle_Front.bmp");
    TexLoad(L"050_Battle_Front", L"Texture\\Pokemon\\050_Battle_Front.bmp");
    TexLoad(L"051_Battle_Front", L"Texture\\Pokemon\\051_Battle_Front.bmp");
    TexLoad(L"052_Battle_Front", L"Texture\\Pokemon\\052_Battle_Front.bmp");
    TexLoad(L"053_Battle_Front", L"Texture\\Pokemon\\053_Battle_Front.bmp");
    TexLoad(L"054_Battle_Front", L"Texture\\Pokemon\\054_Battle_Front.bmp");
    TexLoad(L"055_Battle_Front", L"Texture\\Pokemon\\055_Battle_Front.bmp");
    TexLoad(L"056_Battle_Front", L"Texture\\Pokemon\\056_Battle_Front.bmp");
    TexLoad(L"057_Battle_Front", L"Texture\\Pokemon\\057_Battle_Front.bmp");
    TexLoad(L"058_Battle_Front", L"Texture\\Pokemon\\058_Battle_Front.bmp");
    TexLoad(L"059_Battle_Front", L"Texture\\Pokemon\\059_Battle_Front.bmp");
    TexLoad(L"060_Battle_Front", L"Texture\\Pokemon\\060_Battle_Front.bmp");
    TexLoad(L"061_Battle_Front", L"Texture\\Pokemon\\061_Battle_Front.bmp");
    TexLoad(L"062_Battle_Front", L"Texture\\Pokemon\\062_Battle_Front.bmp");
    TexLoad(L"063_Battle_Front", L"Texture\\Pokemon\\063_Battle_Front.bmp");
    TexLoad(L"064_Battle_Front", L"Texture\\Pokemon\\064_Battle_Front.bmp");
    TexLoad(L"065_Battle_Front", L"Texture\\Pokemon\\065_Battle_Front.bmp");
    TexLoad(L"066_Battle_Front", L"Texture\\Pokemon\\066_Battle_Front.bmp");
    TexLoad(L"067_Battle_Front", L"Texture\\Pokemon\\067_Battle_Front.bmp");
    TexLoad(L"068_Battle_Front", L"Texture\\Pokemon\\068_Battle_Front.bmp");
    TexLoad(L"069_Battle_Front", L"Texture\\Pokemon\\069_Battle_Front.bmp");
    TexLoad(L"070_Battle_Front", L"Texture\\Pokemon\\070_Battle_Front.bmp");
    TexLoad(L"071_Battle_Front", L"Texture\\Pokemon\\071_Battle_Front.bmp");
    TexLoad(L"072_Battle_Front", L"Texture\\Pokemon\\072_Battle_Front.bmp");
    TexLoad(L"073_Battle_Front", L"Texture\\Pokemon\\073_Battle_Front.bmp");
    TexLoad(L"074_Battle_Front", L"Texture\\Pokemon\\074_Battle_Front.bmp");
    TexLoad(L"075_Battle_Front", L"Texture\\Pokemon\\075_Battle_Front.bmp");
    TexLoad(L"076_Battle_Front", L"Texture\\Pokemon\\076_Battle_Front.bmp");
    TexLoad(L"077_Battle_Front", L"Texture\\Pokemon\\077_Battle_Front.bmp");
    TexLoad(L"078_Battle_Front", L"Texture\\Pokemon\\078_Battle_Front.bmp");
    TexLoad(L"079_Battle_Front", L"Texture\\Pokemon\\079_Battle_Front.bmp");
    TexLoad(L"080_Battle_Front", L"Texture\\Pokemon\\080_Battle_Front.bmp");
    TexLoad(L"081_Battle_Front", L"Texture\\Pokemon\\081_Battle_Front.bmp");
    TexLoad(L"082_Battle_Front", L"Texture\\Pokemon\\082_Battle_Front.bmp");
    TexLoad(L"083_Battle_Front", L"Texture\\Pokemon\\083_Battle_Front.bmp");
    TexLoad(L"084_Battle_Front", L"Texture\\Pokemon\\084_Battle_Front.bmp");
    TexLoad(L"085_Battle_Front", L"Texture\\Pokemon\\085_Battle_Front.bmp");
    TexLoad(L"086_Battle_Front", L"Texture\\Pokemon\\086_Battle_Front.bmp");
    TexLoad(L"087_Battle_Front", L"Texture\\Pokemon\\087_Battle_Front.bmp");
    TexLoad(L"088_Battle_Front", L"Texture\\Pokemon\\088_Battle_Front.bmp");
    TexLoad(L"089_Battle_Front", L"Texture\\Pokemon\\089_Battle_Front.bmp");
    TexLoad(L"090_Battle_Front", L"Texture\\Pokemon\\090_Battle_Front.bmp");
    TexLoad(L"091_Battle_Front", L"Texture\\Pokemon\\091_Battle_Front.bmp");
    TexLoad(L"092_Battle_Front", L"Texture\\Pokemon\\092_Battle_Front.bmp");
    TexLoad(L"093_Battle_Front", L"Texture\\Pokemon\\093_Battle_Front.bmp");
    TexLoad(L"094_Battle_Front", L"Texture\\Pokemon\\094_Battle_Front.bmp");
    TexLoad(L"095_Battle_Front", L"Texture\\Pokemon\\095_Battle_Front.bmp");
    TexLoad(L"096_Battle_Front", L"Texture\\Pokemon\\096_Battle_Front.bmp");
    TexLoad(L"097_Battle_Front", L"Texture\\Pokemon\\097_Battle_Front.bmp");
    TexLoad(L"098_Battle_Front", L"Texture\\Pokemon\\098_Battle_Front.bmp");
    TexLoad(L"099_Battle_Front", L"Texture\\Pokemon\\099_Battle_Front.bmp");
    TexLoad(L"100_Battle_Front", L"Texture\\Pokemon\\100_Battle_Front.bmp");
    TexLoad(L"101_Battle_Front", L"Texture\\Pokemon\\101_Battle_Front.bmp");
    TexLoad(L"102_Battle_Front", L"Texture\\Pokemon\\102_Battle_Front.bmp");
    TexLoad(L"103_Battle_Front", L"Texture\\Pokemon\\103_Battle_Front.bmp");
    TexLoad(L"104_Battle_Front", L"Texture\\Pokemon\\104_Battle_Front.bmp");
    TexLoad(L"105_Battle_Front", L"Texture\\Pokemon\\105_Battle_Front.bmp");
    TexLoad(L"106_Battle_Front", L"Texture\\Pokemon\\106_Battle_Front.bmp");
    TexLoad(L"107_Battle_Front", L"Texture\\Pokemon\\107_Battle_Front.bmp");
    TexLoad(L"108_Battle_Front", L"Texture\\Pokemon\\108_Battle_Front.bmp");
    TexLoad(L"109_Battle_Front", L"Texture\\Pokemon\\109_Battle_Front.bmp");
    TexLoad(L"110_Battle_Front", L"Texture\\Pokemon\\110_Battle_Front.bmp");
    TexLoad(L"111_Battle_Front", L"Texture\\Pokemon\\111_Battle_Front.bmp");
    TexLoad(L"112_Battle_Front", L"Texture\\Pokemon\\112_Battle_Front.bmp");
    TexLoad(L"113_Battle_Front", L"Texture\\Pokemon\\113_Battle_Front.bmp");
    TexLoad(L"114_Battle_Front", L"Texture\\Pokemon\\114_Battle_Front.bmp");
    TexLoad(L"115_Battle_Front", L"Texture\\Pokemon\\115_Battle_Front.bmp");
    TexLoad(L"116_Battle_Front", L"Texture\\Pokemon\\116_Battle_Front.bmp");
    TexLoad(L"117_Battle_Front", L"Texture\\Pokemon\\117_Battle_Front.bmp");
    TexLoad(L"118_Battle_Front", L"Texture\\Pokemon\\118_Battle_Front.bmp");
    TexLoad(L"119_Battle_Front", L"Texture\\Pokemon\\119_Battle_Front.bmp");
    TexLoad(L"120_Battle_Front", L"Texture\\Pokemon\\120_Battle_Front.bmp");
    TexLoad(L"121_Battle_Front", L"Texture\\Pokemon\\121_Battle_Front.bmp");
    TexLoad(L"122_Battle_Front", L"Texture\\Pokemon\\122_Battle_Front.bmp");
    TexLoad(L"123_Battle_Front", L"Texture\\Pokemon\\123_Battle_Front.bmp");
    TexLoad(L"124_Battle_Front", L"Texture\\Pokemon\\124_Battle_Front.bmp");
    TexLoad(L"125_Battle_Front", L"Texture\\Pokemon\\125_Battle_Front.bmp");
    TexLoad(L"126_Battle_Front", L"Texture\\Pokemon\\126_Battle_Front.bmp");
    TexLoad(L"127_Battle_Front", L"Texture\\Pokemon\\127_Battle_Front.bmp");
    TexLoad(L"128_Battle_Front", L"Texture\\Pokemon\\128_Battle_Front.bmp");
    TexLoad(L"129_Battle_Front", L"Texture\\Pokemon\\129_Battle_Front.bmp");
    TexLoad(L"130_Battle_Front", L"Texture\\Pokemon\\130_Battle_Front.bmp");
    TexLoad(L"131_Battle_Front", L"Texture\\Pokemon\\131_Battle_Front.bmp");
    TexLoad(L"132_Battle_Front", L"Texture\\Pokemon\\132_Battle_Front.bmp");
    TexLoad(L"133_Battle_Front", L"Texture\\Pokemon\\133_Battle_Front.bmp");
    TexLoad(L"134_Battle_Front", L"Texture\\Pokemon\\134_Battle_Front.bmp");
    TexLoad(L"135_Battle_Front", L"Texture\\Pokemon\\135_Battle_Front.bmp");
    TexLoad(L"136_Battle_Front", L"Texture\\Pokemon\\136_Battle_Front.bmp");
    TexLoad(L"137_Battle_Front", L"Texture\\Pokemon\\137_Battle_Front.bmp");
    TexLoad(L"138_Battle_Front", L"Texture\\Pokemon\\138_Battle_Front.bmp");
    TexLoad(L"139_Battle_Front", L"Texture\\Pokemon\\139_Battle_Front.bmp");
    TexLoad(L"140_Battle_Front", L"Texture\\Pokemon\\140_Battle_Front.bmp");
    TexLoad(L"141_Battle_Front", L"Texture\\Pokemon\\141_Battle_Front.bmp");
    TexLoad(L"142_Battle_Front", L"Texture\\Pokemon\\142_Battle_Front.bmp");
    TexLoad(L"143_Battle_Front", L"Texture\\Pokemon\\143_Battle_Front.bmp");
    TexLoad(L"144_Battle_Front", L"Texture\\Pokemon\\144_Battle_Front.bmp");
    TexLoad(L"145_Battle_Front", L"Texture\\Pokemon\\145_Battle_Front.bmp");
    TexLoad(L"146_Battle_Front", L"Texture\\Pokemon\\146_Battle_Front.bmp");
    TexLoad(L"147_Battle_Front", L"Texture\\Pokemon\\147_Battle_Front.bmp");
    TexLoad(L"148_Battle_Front", L"Texture\\Pokemon\\148_Battle_Front.bmp");
    TexLoad(L"149_Battle_Front", L"Texture\\Pokemon\\149_Battle_Front.bmp");
    TexLoad(L"150_Battle_Front", L"Texture\\Pokemon\\150_Battle_Front.bmp");
    TexLoad(L"151_Battle_Front", L"Texture\\Pokemon\\151_Battle_Front.bmp");

    //back
    TexLoad(L"001_Battle_Back", L"Texture\\Pokemon\\001_Battle_Back.bmp");
    TexLoad(L"002_Battle_Back", L"Texture\\Pokemon\\002_Battle_Back.bmp");
    TexLoad(L"003_Battle_Back", L"Texture\\Pokemon\\003_Battle_Back.bmp");
    TexLoad(L"004_Battle_Back", L"Texture\\Pokemon\\004_Battle_Back.bmp");
    TexLoad(L"005_Battle_Back", L"Texture\\Pokemon\\005_Battle_Back.bmp");
    TexLoad(L"006_Battle_Back", L"Texture\\Pokemon\\006_Battle_Back.bmp");
    TexLoad(L"007_Battle_Back", L"Texture\\Pokemon\\007_Battle_Back.bmp");
    TexLoad(L"008_Battle_Back", L"Texture\\Pokemon\\008_Battle_Back.bmp");
    TexLoad(L"009_Battle_Back", L"Texture\\Pokemon\\009_Battle_Back.bmp");
    TexLoad(L"010_Battle_Back", L"Texture\\Pokemon\\010_Battle_Back.bmp");
    TexLoad(L"011_Battle_Back", L"Texture\\Pokemon\\011_Battle_Back.bmp");
    TexLoad(L"012_Battle_Back", L"Texture\\Pokemon\\012_Battle_Back.bmp");
    TexLoad(L"013_Battle_Back", L"Texture\\Pokemon\\013_Battle_Back.bmp");
    TexLoad(L"014_Battle_Back", L"Texture\\Pokemon\\014_Battle_Back.bmp");
    TexLoad(L"015_Battle_Back", L"Texture\\Pokemon\\015_Battle_Back.bmp");
    TexLoad(L"016_Battle_Back", L"Texture\\Pokemon\\016_Battle_Back.bmp");
    TexLoad(L"017_Battle_Back", L"Texture\\Pokemon\\017_Battle_Back.bmp");
    TexLoad(L"018_Battle_Back", L"Texture\\Pokemon\\018_Battle_Back.bmp");
    TexLoad(L"019_Battle_Back", L"Texture\\Pokemon\\019_Battle_Back.bmp");
    TexLoad(L"020_Battle_Back", L"Texture\\Pokemon\\020_Battle_Back.bmp");
    TexLoad(L"021_Battle_Back", L"Texture\\Pokemon\\021_Battle_Back.bmp");
    TexLoad(L"022_Battle_Back", L"Texture\\Pokemon\\022_Battle_Back.bmp");
    TexLoad(L"023_Battle_Back", L"Texture\\Pokemon\\023_Battle_Back.bmp");
    TexLoad(L"024_Battle_Back", L"Texture\\Pokemon\\024_Battle_Back.bmp");
    TexLoad(L"025_Battle_Back", L"Texture\\Pokemon\\025_Battle_Back.bmp");
    TexLoad(L"026_Battle_Back", L"Texture\\Pokemon\\026_Battle_Back.bmp");
    TexLoad(L"027_Battle_Back", L"Texture\\Pokemon\\027_Battle_Back.bmp");
    TexLoad(L"028_Battle_Back", L"Texture\\Pokemon\\028_Battle_Back.bmp");
    TexLoad(L"029_Battle_Back", L"Texture\\Pokemon\\029_Battle_Back.bmp");
    TexLoad(L"030_Battle_Back", L"Texture\\Pokemon\\030_Battle_Back.bmp");
    TexLoad(L"031_Battle_Back", L"Texture\\Pokemon\\031_Battle_Back.bmp");
    TexLoad(L"032_Battle_Back", L"Texture\\Pokemon\\032_Battle_Back.bmp");
    TexLoad(L"033_Battle_Back", L"Texture\\Pokemon\\033_Battle_Back.bmp");
    TexLoad(L"034_Battle_Back", L"Texture\\Pokemon\\034_Battle_Back.bmp");
    TexLoad(L"035_Battle_Back", L"Texture\\Pokemon\\035_Battle_Back.bmp");
    TexLoad(L"036_Battle_Back", L"Texture\\Pokemon\\036_Battle_Back.bmp");
    TexLoad(L"037_Battle_Back", L"Texture\\Pokemon\\037_Battle_Back.bmp");
    TexLoad(L"038_Battle_Back", L"Texture\\Pokemon\\038_Battle_Back.bmp");
    TexLoad(L"039_Battle_Back", L"Texture\\Pokemon\\039_Battle_Back.bmp");
    TexLoad(L"040_Battle_Back", L"Texture\\Pokemon\\040_Battle_Back.bmp");
    TexLoad(L"041_Battle_Back", L"Texture\\Pokemon\\041_Battle_Back.bmp");
    TexLoad(L"042_Battle_Back", L"Texture\\Pokemon\\042_Battle_Back.bmp");
    TexLoad(L"043_Battle_Back", L"Texture\\Pokemon\\043_Battle_Back.bmp");
    TexLoad(L"044_Battle_Back", L"Texture\\Pokemon\\044_Battle_Back.bmp");
    TexLoad(L"045_Battle_Back", L"Texture\\Pokemon\\045_Battle_Back.bmp");
    TexLoad(L"046_Battle_Back", L"Texture\\Pokemon\\046_Battle_Back.bmp");
    TexLoad(L"047_Battle_Back", L"Texture\\Pokemon\\047_Battle_Back.bmp");
    TexLoad(L"048_Battle_Back", L"Texture\\Pokemon\\048_Battle_Back.bmp");
    TexLoad(L"049_Battle_Back", L"Texture\\Pokemon\\049_Battle_Back.bmp");
    TexLoad(L"050_Battle_Back", L"Texture\\Pokemon\\050_Battle_Back.bmp");
    TexLoad(L"051_Battle_Back", L"Texture\\Pokemon\\051_Battle_Back.bmp");
    TexLoad(L"052_Battle_Back", L"Texture\\Pokemon\\052_Battle_Back.bmp");
    TexLoad(L"053_Battle_Back", L"Texture\\Pokemon\\053_Battle_Back.bmp");
    TexLoad(L"054_Battle_Back", L"Texture\\Pokemon\\054_Battle_Back.bmp");
    TexLoad(L"055_Battle_Back", L"Texture\\Pokemon\\055_Battle_Back.bmp");
    TexLoad(L"056_Battle_Back", L"Texture\\Pokemon\\056_Battle_Back.bmp");
    TexLoad(L"057_Battle_Back", L"Texture\\Pokemon\\057_Battle_Back.bmp");
    TexLoad(L"058_Battle_Back", L"Texture\\Pokemon\\058_Battle_Back.bmp");
    TexLoad(L"059_Battle_Back", L"Texture\\Pokemon\\059_Battle_Back.bmp");
    TexLoad(L"060_Battle_Back", L"Texture\\Pokemon\\060_Battle_Back.bmp");
    TexLoad(L"061_Battle_Back", L"Texture\\Pokemon\\061_Battle_Back.bmp");
    TexLoad(L"062_Battle_Back", L"Texture\\Pokemon\\062_Battle_Back.bmp");
    TexLoad(L"063_Battle_Back", L"Texture\\Pokemon\\063_Battle_Back.bmp");
    TexLoad(L"064_Battle_Back", L"Texture\\Pokemon\\064_Battle_Back.bmp");
    TexLoad(L"065_Battle_Back", L"Texture\\Pokemon\\065_Battle_Back.bmp");
    TexLoad(L"066_Battle_Back", L"Texture\\Pokemon\\066_Battle_Back.bmp");
    TexLoad(L"067_Battle_Back", L"Texture\\Pokemon\\067_Battle_Back.bmp");
    TexLoad(L"068_Battle_Back", L"Texture\\Pokemon\\068_Battle_Back.bmp");
    TexLoad(L"069_Battle_Back", L"Texture\\Pokemon\\069_Battle_Back.bmp");
    TexLoad(L"070_Battle_Back", L"Texture\\Pokemon\\070_Battle_Back.bmp");
    TexLoad(L"071_Battle_Back", L"Texture\\Pokemon\\071_Battle_Back.bmp");
    TexLoad(L"072_Battle_Back", L"Texture\\Pokemon\\072_Battle_Back.bmp");
    TexLoad(L"073_Battle_Back", L"Texture\\Pokemon\\073_Battle_Back.bmp");
    TexLoad(L"074_Battle_Back", L"Texture\\Pokemon\\074_Battle_Back.bmp");
    TexLoad(L"075_Battle_Back", L"Texture\\Pokemon\\075_Battle_Back.bmp");
    TexLoad(L"076_Battle_Back", L"Texture\\Pokemon\\076_Battle_Back.bmp");
    TexLoad(L"077_Battle_Back", L"Texture\\Pokemon\\077_Battle_Back.bmp");
    TexLoad(L"078_Battle_Back", L"Texture\\Pokemon\\078_Battle_Back.bmp");
    TexLoad(L"079_Battle_Back", L"Texture\\Pokemon\\079_Battle_Back.bmp");
    TexLoad(L"080_Battle_Back", L"Texture\\Pokemon\\080_Battle_Back.bmp");
    TexLoad(L"081_Battle_Back", L"Texture\\Pokemon\\081_Battle_Back.bmp");
    TexLoad(L"082_Battle_Back", L"Texture\\Pokemon\\082_Battle_Back.bmp");
    TexLoad(L"083_Battle_Back", L"Texture\\Pokemon\\083_Battle_Back.bmp");
    TexLoad(L"084_Battle_Back", L"Texture\\Pokemon\\084_Battle_Back.bmp");
    TexLoad(L"085_Battle_Back", L"Texture\\Pokemon\\085_Battle_Back.bmp");
    TexLoad(L"086_Battle_Back", L"Texture\\Pokemon\\086_Battle_Back.bmp");
    TexLoad(L"087_Battle_Back", L"Texture\\Pokemon\\087_Battle_Back.bmp");
    TexLoad(L"088_Battle_Back", L"Texture\\Pokemon\\088_Battle_Back.bmp");
    TexLoad(L"089_Battle_Back", L"Texture\\Pokemon\\089_Battle_Back.bmp");
    TexLoad(L"090_Battle_Back", L"Texture\\Pokemon\\090_Battle_Back.bmp");
    TexLoad(L"091_Battle_Back", L"Texture\\Pokemon\\091_Battle_Back.bmp");
    TexLoad(L"092_Battle_Back", L"Texture\\Pokemon\\092_Battle_Back.bmp");
    TexLoad(L"093_Battle_Back", L"Texture\\Pokemon\\093_Battle_Back.bmp");
    TexLoad(L"094_Battle_Back", L"Texture\\Pokemon\\094_Battle_Back.bmp");
    TexLoad(L"095_Battle_Back", L"Texture\\Pokemon\\095_Battle_Back.bmp");
    TexLoad(L"096_Battle_Back", L"Texture\\Pokemon\\096_Battle_Back.bmp");
    TexLoad(L"097_Battle_Back", L"Texture\\Pokemon\\097_Battle_Back.bmp");
    TexLoad(L"098_Battle_Back", L"Texture\\Pokemon\\098_Battle_Back.bmp");
    TexLoad(L"099_Battle_Back", L"Texture\\Pokemon\\099_Battle_Back.bmp");
    TexLoad(L"100_Battle_Back", L"Texture\\Pokemon\\100_Battle_Back.bmp");
    TexLoad(L"101_Battle_Back", L"Texture\\Pokemon\\101_Battle_Back.bmp");
    TexLoad(L"102_Battle_Back", L"Texture\\Pokemon\\102_Battle_Back.bmp");
    TexLoad(L"103_Battle_Back", L"Texture\\Pokemon\\103_Battle_Back.bmp");
    TexLoad(L"104_Battle_Back", L"Texture\\Pokemon\\104_Battle_Back.bmp");
    TexLoad(L"105_Battle_Back", L"Texture\\Pokemon\\105_Battle_Back.bmp");
    TexLoad(L"106_Battle_Back", L"Texture\\Pokemon\\106_Battle_Back.bmp");
    TexLoad(L"107_Battle_Back", L"Texture\\Pokemon\\107_Battle_Back.bmp");
    TexLoad(L"108_Battle_Back", L"Texture\\Pokemon\\108_Battle_Back.bmp");
    TexLoad(L"109_Battle_Back", L"Texture\\Pokemon\\109_Battle_Back.bmp");
    TexLoad(L"110_Battle_Back", L"Texture\\Pokemon\\110_Battle_Back.bmp");
    TexLoad(L"111_Battle_Back", L"Texture\\Pokemon\\111_Battle_Back.bmp");
    TexLoad(L"112_Battle_Back", L"Texture\\Pokemon\\112_Battle_Back.bmp");
    TexLoad(L"113_Battle_Back", L"Texture\\Pokemon\\113_Battle_Back.bmp");
    TexLoad(L"114_Battle_Back", L"Texture\\Pokemon\\114_Battle_Back.bmp");
    TexLoad(L"115_Battle_Back", L"Texture\\Pokemon\\115_Battle_Back.bmp");
    TexLoad(L"116_Battle_Back", L"Texture\\Pokemon\\116_Battle_Back.bmp");
    TexLoad(L"117_Battle_Back", L"Texture\\Pokemon\\117_Battle_Back.bmp");
    TexLoad(L"118_Battle_Back", L"Texture\\Pokemon\\118_Battle_Back.bmp");
    TexLoad(L"119_Battle_Back", L"Texture\\Pokemon\\119_Battle_Back.bmp");
    TexLoad(L"120_Battle_Back", L"Texture\\Pokemon\\120_Battle_Back.bmp");
    TexLoad(L"121_Battle_Back", L"Texture\\Pokemon\\121_Battle_Back.bmp");
    TexLoad(L"122_Battle_Back", L"Texture\\Pokemon\\122_Battle_Back.bmp");
    TexLoad(L"123_Battle_Back", L"Texture\\Pokemon\\123_Battle_Back.bmp");
    TexLoad(L"124_Battle_Back", L"Texture\\Pokemon\\124_Battle_Back.bmp");
    TexLoad(L"125_Battle_Back", L"Texture\\Pokemon\\125_Battle_Back.bmp");
    TexLoad(L"126_Battle_Back", L"Texture\\Pokemon\\126_Battle_Back.bmp");
    TexLoad(L"127_Battle_Back", L"Texture\\Pokemon\\127_Battle_Back.bmp");
    TexLoad(L"128_Battle_Back", L"Texture\\Pokemon\\128_Battle_Back.bmp");
    TexLoad(L"129_Battle_Back", L"Texture\\Pokemon\\129_Battle_Back.bmp");
    TexLoad(L"130_Battle_Back", L"Texture\\Pokemon\\130_Battle_Back.bmp");
    TexLoad(L"131_Battle_Back", L"Texture\\Pokemon\\131_Battle_Back.bmp");
    TexLoad(L"132_Battle_Back", L"Texture\\Pokemon\\132_Battle_Back.bmp");
    TexLoad(L"133_Battle_Back", L"Texture\\Pokemon\\133_Battle_Back.bmp");
    TexLoad(L"134_Battle_Back", L"Texture\\Pokemon\\134_Battle_Back.bmp");
    TexLoad(L"135_Battle_Back", L"Texture\\Pokemon\\135_Battle_Back.bmp");
    TexLoad(L"136_Battle_Back", L"Texture\\Pokemon\\136_Battle_Back.bmp");
    TexLoad(L"137_Battle_Back", L"Texture\\Pokemon\\137_Battle_Back.bmp");
    TexLoad(L"138_Battle_Back", L"Texture\\Pokemon\\138_Battle_Back.bmp");
    TexLoad(L"139_Battle_Back", L"Texture\\Pokemon\\139_Battle_Back.bmp");
    TexLoad(L"140_Battle_Back", L"Texture\\Pokemon\\140_Battle_Back.bmp");
    TexLoad(L"141_Battle_Back", L"Texture\\Pokemon\\141_Battle_Back.bmp");
    TexLoad(L"142_Battle_Back", L"Texture\\Pokemon\\142_Battle_Back.bmp");
    TexLoad(L"143_Battle_Back", L"Texture\\Pokemon\\143_Battle_Back.bmp");
    TexLoad(L"144_Battle_Back", L"Texture\\Pokemon\\144_Battle_Back.bmp");
    TexLoad(L"145_Battle_Back", L"Texture\\Pokemon\\145_Battle_Back.bmp");
    TexLoad(L"146_Battle_Back", L"Texture\\Pokemon\\146_Battle_Back.bmp");
    TexLoad(L"147_Battle_Back", L"Texture\\Pokemon\\147_Battle_Back.bmp");
    TexLoad(L"148_Battle_Back", L"Texture\\Pokemon\\148_Battle_Back.bmp");
    TexLoad(L"149_Battle_Back", L"Texture\\Pokemon\\149_Battle_Back.bmp");
    TexLoad(L"150_Battle_Back", L"Texture\\Pokemon\\150_Battle_Back.bmp");
    TexLoad(L"151_Battle_Back", L"Texture\\Pokemon\\151_Battle_Back.bmp");

    _pokemonTextureContainer[L"001"][PokemonSprite_Type::Field] = L"001_Field";
    _pokemonTextureContainer[L"002"][PokemonSprite_Type::Field] = L"002_Field";
    _pokemonTextureContainer[L"003"][PokemonSprite_Type::Field] = L"003_Field";
    _pokemonTextureContainer[L"004"][PokemonSprite_Type::Field] = L"004_Field";
    _pokemonTextureContainer[L"005"][PokemonSprite_Type::Field] = L"005_Field";
    _pokemonTextureContainer[L"006"][PokemonSprite_Type::Field] = L"006_Field";
    _pokemonTextureContainer[L"007"][PokemonSprite_Type::Field] = L"007_Field";
    _pokemonTextureContainer[L"008"][PokemonSprite_Type::Field] = L"008_Field";
    _pokemonTextureContainer[L"009"][PokemonSprite_Type::Field] = L"009_Field";
    _pokemonTextureContainer[L"010"][PokemonSprite_Type::Field] = L"010_Field";
    _pokemonTextureContainer[L"011"][PokemonSprite_Type::Field] = L"011_Field";
    _pokemonTextureContainer[L"012"][PokemonSprite_Type::Field] = L"012_Field";
    _pokemonTextureContainer[L"013"][PokemonSprite_Type::Field] = L"013_Field";
    _pokemonTextureContainer[L"014"][PokemonSprite_Type::Field] = L"014_Field";
    _pokemonTextureContainer[L"015"][PokemonSprite_Type::Field] = L"015_Field";
    _pokemonTextureContainer[L"016"][PokemonSprite_Type::Field] = L"016_Field";
    _pokemonTextureContainer[L"017"][PokemonSprite_Type::Field] = L"017_Field";
    _pokemonTextureContainer[L"018"][PokemonSprite_Type::Field] = L"018_Field";
    _pokemonTextureContainer[L"019"][PokemonSprite_Type::Field] = L"019_Field";
    _pokemonTextureContainer[L"020"][PokemonSprite_Type::Field] = L"020_Field";
    _pokemonTextureContainer[L"021"][PokemonSprite_Type::Field] = L"021_Field";
    _pokemonTextureContainer[L"022"][PokemonSprite_Type::Field] = L"022_Field";
    _pokemonTextureContainer[L"023"][PokemonSprite_Type::Field] = L"023_Field";
    _pokemonTextureContainer[L"024"][PokemonSprite_Type::Field] = L"024_Field";
    _pokemonTextureContainer[L"025"][PokemonSprite_Type::Field] = L"025_Field";
    _pokemonTextureContainer[L"026"][PokemonSprite_Type::Field] = L"026_Field";
    _pokemonTextureContainer[L"027"][PokemonSprite_Type::Field] = L"027_Field";
    _pokemonTextureContainer[L"028"][PokemonSprite_Type::Field] = L"028_Field";
    _pokemonTextureContainer[L"029"][PokemonSprite_Type::Field] = L"029_Field";
    _pokemonTextureContainer[L"030"][PokemonSprite_Type::Field] = L"030_Field";
    _pokemonTextureContainer[L"031"][PokemonSprite_Type::Field] = L"031_Field";
    _pokemonTextureContainer[L"032"][PokemonSprite_Type::Field] = L"032_Field";
    _pokemonTextureContainer[L"033"][PokemonSprite_Type::Field] = L"033_Field";
    _pokemonTextureContainer[L"034"][PokemonSprite_Type::Field] = L"034_Field";
    _pokemonTextureContainer[L"035"][PokemonSprite_Type::Field] = L"035_Field";
    _pokemonTextureContainer[L"036"][PokemonSprite_Type::Field] = L"036_Field";
    _pokemonTextureContainer[L"037"][PokemonSprite_Type::Field] = L"037_Field";
    _pokemonTextureContainer[L"038"][PokemonSprite_Type::Field] = L"038_Field";
    _pokemonTextureContainer[L"039"][PokemonSprite_Type::Field] = L"039_Field";
    _pokemonTextureContainer[L"040"][PokemonSprite_Type::Field] = L"040_Field";
    _pokemonTextureContainer[L"041"][PokemonSprite_Type::Field] = L"041_Field";
    _pokemonTextureContainer[L"042"][PokemonSprite_Type::Field] = L"042_Field";
    _pokemonTextureContainer[L"043"][PokemonSprite_Type::Field] = L"043_Field";
    _pokemonTextureContainer[L"044"][PokemonSprite_Type::Field] = L"044_Field";
    _pokemonTextureContainer[L"045"][PokemonSprite_Type::Field] = L"045_Field";
    _pokemonTextureContainer[L"046"][PokemonSprite_Type::Field] = L"046_Field";
    _pokemonTextureContainer[L"047"][PokemonSprite_Type::Field] = L"047_Field";
    _pokemonTextureContainer[L"048"][PokemonSprite_Type::Field] = L"048_Field";
    _pokemonTextureContainer[L"049"][PokemonSprite_Type::Field] = L"049_Field";
    _pokemonTextureContainer[L"050"][PokemonSprite_Type::Field] = L"050_Field";
    _pokemonTextureContainer[L"051"][PokemonSprite_Type::Field] = L"051_Field";
    _pokemonTextureContainer[L"052"][PokemonSprite_Type::Field] = L"052_Field";
    _pokemonTextureContainer[L"053"][PokemonSprite_Type::Field] = L"053_Field";
    _pokemonTextureContainer[L"054"][PokemonSprite_Type::Field] = L"054_Field";
    _pokemonTextureContainer[L"055"][PokemonSprite_Type::Field] = L"055_Field";
    _pokemonTextureContainer[L"056"][PokemonSprite_Type::Field] = L"056_Field";
    _pokemonTextureContainer[L"057"][PokemonSprite_Type::Field] = L"057_Field";
    _pokemonTextureContainer[L"058"][PokemonSprite_Type::Field] = L"058_Field";
    _pokemonTextureContainer[L"059"][PokemonSprite_Type::Field] = L"059_Field";
    _pokemonTextureContainer[L"060"][PokemonSprite_Type::Field] = L"060_Field";
    _pokemonTextureContainer[L"061"][PokemonSprite_Type::Field] = L"061_Field";
    _pokemonTextureContainer[L"062"][PokemonSprite_Type::Field] = L"062_Field";
    _pokemonTextureContainer[L"063"][PokemonSprite_Type::Field] = L"063_Field";
    _pokemonTextureContainer[L"064"][PokemonSprite_Type::Field] = L"064_Field";
    _pokemonTextureContainer[L"065"][PokemonSprite_Type::Field] = L"065_Field";
    _pokemonTextureContainer[L"066"][PokemonSprite_Type::Field] = L"066_Field";
    _pokemonTextureContainer[L"067"][PokemonSprite_Type::Field] = L"067_Field";
    _pokemonTextureContainer[L"068"][PokemonSprite_Type::Field] = L"068_Field";
    _pokemonTextureContainer[L"069"][PokemonSprite_Type::Field] = L"069_Field";
    _pokemonTextureContainer[L"070"][PokemonSprite_Type::Field] = L"070_Field";
    _pokemonTextureContainer[L"071"][PokemonSprite_Type::Field] = L"071_Field";
    _pokemonTextureContainer[L"072"][PokemonSprite_Type::Field] = L"072_Field";
    _pokemonTextureContainer[L"073"][PokemonSprite_Type::Field] = L"073_Field";
    _pokemonTextureContainer[L"074"][PokemonSprite_Type::Field] = L"074_Field";
    _pokemonTextureContainer[L"075"][PokemonSprite_Type::Field] = L"075_Field";
    _pokemonTextureContainer[L"076"][PokemonSprite_Type::Field] = L"076_Field";
    _pokemonTextureContainer[L"077"][PokemonSprite_Type::Field] = L"077_Field";
    _pokemonTextureContainer[L"078"][PokemonSprite_Type::Field] = L"078_Field";
    _pokemonTextureContainer[L"079"][PokemonSprite_Type::Field] = L"079_Field";
    _pokemonTextureContainer[L"080"][PokemonSprite_Type::Field] = L"080_Field";
    _pokemonTextureContainer[L"081"][PokemonSprite_Type::Field] = L"081_Field";
    _pokemonTextureContainer[L"082"][PokemonSprite_Type::Field] = L"082_Field";
    _pokemonTextureContainer[L"083"][PokemonSprite_Type::Field] = L"083_Field";
    _pokemonTextureContainer[L"084"][PokemonSprite_Type::Field] = L"084_Field";
    _pokemonTextureContainer[L"085"][PokemonSprite_Type::Field] = L"085_Field";
    _pokemonTextureContainer[L"086"][PokemonSprite_Type::Field] = L"086_Field";
    _pokemonTextureContainer[L"087"][PokemonSprite_Type::Field] = L"087_Field";
    _pokemonTextureContainer[L"088"][PokemonSprite_Type::Field] = L"088_Field";
    _pokemonTextureContainer[L"089"][PokemonSprite_Type::Field] = L"089_Field";
    _pokemonTextureContainer[L"090"][PokemonSprite_Type::Field] = L"090_Field";
    _pokemonTextureContainer[L"091"][PokemonSprite_Type::Field] = L"091_Field";
    _pokemonTextureContainer[L"092"][PokemonSprite_Type::Field] = L"092_Field";
    _pokemonTextureContainer[L"093"][PokemonSprite_Type::Field] = L"093_Field";
    _pokemonTextureContainer[L"094"][PokemonSprite_Type::Field] = L"094_Field";
    _pokemonTextureContainer[L"095"][PokemonSprite_Type::Field] = L"095_Field";
    _pokemonTextureContainer[L"096"][PokemonSprite_Type::Field] = L"096_Field";
    _pokemonTextureContainer[L"097"][PokemonSprite_Type::Field] = L"097_Field";
    _pokemonTextureContainer[L"098"][PokemonSprite_Type::Field] = L"098_Field";
    _pokemonTextureContainer[L"099"][PokemonSprite_Type::Field] = L"099_Field";
    _pokemonTextureContainer[L"100"][PokemonSprite_Type::Field] = L"100_Field";
    _pokemonTextureContainer[L"101"][PokemonSprite_Type::Field] = L"101_Field";
    _pokemonTextureContainer[L"102"][PokemonSprite_Type::Field] = L"102_Field";
    _pokemonTextureContainer[L"103"][PokemonSprite_Type::Field] = L"103_Field";
    _pokemonTextureContainer[L"104"][PokemonSprite_Type::Field] = L"104_Field";
    _pokemonTextureContainer[L"105"][PokemonSprite_Type::Field] = L"105_Field";
    _pokemonTextureContainer[L"106"][PokemonSprite_Type::Field] = L"106_Field";
    _pokemonTextureContainer[L"107"][PokemonSprite_Type::Field] = L"107_Field";
    _pokemonTextureContainer[L"108"][PokemonSprite_Type::Field] = L"108_Field";
    _pokemonTextureContainer[L"109"][PokemonSprite_Type::Field] = L"109_Field";
    _pokemonTextureContainer[L"110"][PokemonSprite_Type::Field] = L"110_Field";
    _pokemonTextureContainer[L"111"][PokemonSprite_Type::Field] = L"111_Field";
    _pokemonTextureContainer[L"112"][PokemonSprite_Type::Field] = L"112_Field";
    _pokemonTextureContainer[L"113"][PokemonSprite_Type::Field] = L"113_Field";
    _pokemonTextureContainer[L"114"][PokemonSprite_Type::Field] = L"114_Field";
    _pokemonTextureContainer[L"115"][PokemonSprite_Type::Field] = L"115_Field";
    _pokemonTextureContainer[L"116"][PokemonSprite_Type::Field] = L"116_Field";
    _pokemonTextureContainer[L"117"][PokemonSprite_Type::Field] = L"117_Field";
    _pokemonTextureContainer[L"118"][PokemonSprite_Type::Field] = L"118_Field";
    _pokemonTextureContainer[L"119"][PokemonSprite_Type::Field] = L"119_Field";
    _pokemonTextureContainer[L"120"][PokemonSprite_Type::Field] = L"120_Field";
    _pokemonTextureContainer[L"121"][PokemonSprite_Type::Field] = L"121_Field";
    _pokemonTextureContainer[L"122"][PokemonSprite_Type::Field] = L"122_Field";
    _pokemonTextureContainer[L"123"][PokemonSprite_Type::Field] = L"123_Field";
    _pokemonTextureContainer[L"124"][PokemonSprite_Type::Field] = L"124_Field";
    _pokemonTextureContainer[L"125"][PokemonSprite_Type::Field] = L"125_Field";
    _pokemonTextureContainer[L"126"][PokemonSprite_Type::Field] = L"126_Field";
    _pokemonTextureContainer[L"127"][PokemonSprite_Type::Field] = L"127_Field";
    _pokemonTextureContainer[L"128"][PokemonSprite_Type::Field] = L"128_Field";
    _pokemonTextureContainer[L"129"][PokemonSprite_Type::Field] = L"129_Field";
    _pokemonTextureContainer[L"130"][PokemonSprite_Type::Field] = L"130_Field";
    _pokemonTextureContainer[L"131"][PokemonSprite_Type::Field] = L"131_Field";
    _pokemonTextureContainer[L"132"][PokemonSprite_Type::Field] = L"132_Field";
    _pokemonTextureContainer[L"133"][PokemonSprite_Type::Field] = L"133_Field";
    _pokemonTextureContainer[L"134"][PokemonSprite_Type::Field] = L"134_Field";
    _pokemonTextureContainer[L"135"][PokemonSprite_Type::Field] = L"135_Field";
    _pokemonTextureContainer[L"136"][PokemonSprite_Type::Field] = L"136_Field";
    _pokemonTextureContainer[L"137"][PokemonSprite_Type::Field] = L"137_Field";
    _pokemonTextureContainer[L"138"][PokemonSprite_Type::Field] = L"138_Field";
    _pokemonTextureContainer[L"139"][PokemonSprite_Type::Field] = L"139_Field";
    _pokemonTextureContainer[L"140"][PokemonSprite_Type::Field] = L"140_Field";
    _pokemonTextureContainer[L"141"][PokemonSprite_Type::Field] = L"141_Field";
    _pokemonTextureContainer[L"142"][PokemonSprite_Type::Field] = L"142_Field";
    _pokemonTextureContainer[L"143"][PokemonSprite_Type::Field] = L"143_Field";
    _pokemonTextureContainer[L"144"][PokemonSprite_Type::Field] = L"144_Field";
    _pokemonTextureContainer[L"145"][PokemonSprite_Type::Field] = L"145_Field";
    _pokemonTextureContainer[L"146"][PokemonSprite_Type::Field] = L"146_Field";
    _pokemonTextureContainer[L"147"][PokemonSprite_Type::Field] = L"147_Field";
    _pokemonTextureContainer[L"148"][PokemonSprite_Type::Field] = L"148_Field";
    _pokemonTextureContainer[L"149"][PokemonSprite_Type::Field] = L"149_Field";
    _pokemonTextureContainer[L"150"][PokemonSprite_Type::Field] = L"150_Field";
    _pokemonTextureContainer[L"151"][PokemonSprite_Type::Field] = L"151_Field";


}