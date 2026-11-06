
// src/fallout/ai/character_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESBoundObject). The skeleton of src/fallout/ai/character.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "character_decls_rtti_character.h"
bool __fastcall Character_GetTrespassing(Character* self);
void __fastcall FUN_008d1e90(Character* this_ptr, float value);
struct FUN_008d34b0_shell : public Character
{
    void FUN_008d34b0(BGSLoadFormBuffer*);
};
struct FUN_008d34d0_shell : public Character
{
    void FUN_008d34d0(BGSLoadFormBuffer*);
};
struct FUN_008d34f0_shell : public Character
{
    void RevertAndResetFields(BGSLoadFormBuffer*);
};
extern double _gModifierZero;
struct FUN_009dcc80_target
{
    NiPoint3 GetVec(float);
};
struct FUN_008b3b30_shell
{
    NiPoint3* GetAddTopicList();
    NiPoint3 FUN_008b3b30(float f);
};
struct FUN_008d1e70_t
{
    unsigned char GetByteAtOffset1C0();
};
void __cdecl _Deallocate(void*);
struct FUN_008d1f10_shell : public Character
{
    void FUN_008d2060();
    FUN_008d1f10_shell* FUN_008d1f10(unsigned int aiFlags);
};
int __cdecl FUN_00646310(void*, int, float*, float*);
struct FUN_008d24a0_shell : public Character
{
    int FUN_008d24a0();
};
struct FUN_008d32b0_shell : public Character
{
    unsigned short FUN_008a9020(unsigned int);
    unsigned short FUN_008d32b0(unsigned int aiFlags);
};
struct FUN_008a9380_target
{
    void SaveActorData(unsigned int);
};
struct FUN_008d32f0_shell
{
    void FUN_008d32f0(unsigned int aiFlags);
};
struct FUN_008d3310_shell : public Character
{
    void FUN_008a9940(unsigned int, unsigned int);
    void FUN_008d3310(unsigned int aiFlags, unsigned int aiCurrentFlags);
};
struct TESSaveLoadGame
{
    bool FUN_0055f5b0();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct FUN_008d3330_shell : public Character
{
    void FUN_008aa210(unsigned int);
    void FUN_008d3330(unsigned int aiFlags);
};
struct FUN_008d3380_shell : public Character
{
    void FUN_008aa4c0(unsigned int, unsigned int);
    void FUN_008d3380(unsigned int, unsigned int);
};
struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};
struct FUN_008d33a0_shell : public Character
{
    void FUN_008aaf40(BGSSaveFormBuffer*);
    void SaveFormData(BGSSaveFormBuffer*);
};
struct FUN_009396f0_shell
{
    void SetFieldD64(int value);
};
bool __fastcall FUN_00524d10(bool*);
struct FUN_00950ad0_shell : public PlayerCharacter
{
    BipedAnim* GetBipedAnimation(bool);
    BipedAnim* FUN_00950ad0();
};
struct MediaLocation;
struct MediaLocationController;
struct MusicMarkerReference
{
    TESObjectREFR* m_pMarkerReference;
    MediaLocation* m_pAudioMarkerData;
};
typedef char _sizecheck_AudioMarkerInfo[sizeof(MusicMarkerReference) == 8 ? 1 : -1];
struct FUN_009698a0_shell : public PlayerCharacter
{
    MediaLocationController* GetMediaLocationController();
};
struct BGSTalkingActivator
{
    TESObjectREFR* GetTempRef() const;
};
struct TESObject
{
    BGSTalkingActivator* GetNext();
};
struct ExtraDataList_Accessor
{
    void FUN_0042e060(BGSTalkingActivator*, TESObjectREFR*);
    void* FUN_0042e110();
};
struct Slot12cHolder
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void Method12c(TESObjectREFR*);
};
struct FUN_008b1910_shell
{
    TESObjectREFR* FUN_008b1910(TESObjectREFR* apRefr, TESObjectREFR*& apOutRefr);
};
struct TopicH
{
    NiPoint3* GetAddTopicList();
};
struct bhkCharacterController
{
    void FUN_0066ca00(void*);
};
struct MobileObject_Standin
{
    bhkCharacterController* GetPhysicsCharacterController();
};
struct HolderFUN
{
    void FUN_0066ca00(void*);
};
struct Point3 : public NiPoint3
{
    Point3 operator*(float) const;
    Point3& operator+=(const Point3&);
};
struct FUN_00968690_shell : public Character
{
    NiPoint3 FUN_00968690(float f);
};
struct SoundPlaybackHandle
{
    void SetFormType(int formType);
};
struct FUN_0087d4a0
{
    FUN_0087d4a0(bool value);
    ~FUN_0087d4a0();
};
struct FUN_008d1f40_t : public FUN_0087d4a0
{
    FUN_008d1f40_t(bool abadd);
};
struct CharacterCallStandin
{
    void FUN_008d4e80();
};
extern int DAT_0108695c;
extern int DAT_010869a4;
extern int DAT_010869d4;
extern int DAT_01086a0c;
extern int DAT_01086a60;
extern int DAT_01086a6c;
struct FUN_00573150_shell
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4()
    {}
    virtual void v5()
    {}
    virtual void v6()
    {}
    virtual void v7()
    {}
    virtual void v8()
    {}
    virtual void v9()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54()
    {}
    virtual void v55()
    {}
    virtual void v56()
    {}
    virtual void v57()
    {}
    virtual void v58()
    {}
    virtual void v59()
    {}
    virtual void v60()
    {}
    virtual void v61()
    {}
    virtual void v62()
    {}
    virtual void v63()
    {}
    virtual void v64()
    {}
    virtual void v65()
    {}
    virtual void v66()
    {}
    virtual void v67()
    {}
    virtual void v68()
    {}
    virtual void v69()
    {}
    virtual void v70()
    {}
    virtual void v71()
    {}
    virtual void v72()
    {}
    virtual void v73()
    {}
    virtual void v74()
    {}
    virtual void v75()
    {}
    virtual void v76()
    {}
    virtual void v77()
    {}
    virtual void v78()
    {}
    virtual void v79()
    {}
    virtual void v80()
    {}
    virtual void v81()
    {}
    virtual void v82()
    {}
    virtual void v83()
    {}
    virtual void v84()
    {}
    virtual void v85()
    {}
    virtual void v86()
    {}
    virtual void v87()
    {}
    virtual void v88()
    {}
    virtual void v89()
    {}
    virtual void v90()
    {}
    virtual void v91()
    {}
    virtual void v92()
    {}
    virtual void v93()
    {}
    virtual void v94()
    {}
    virtual void v95()
    {}
    virtual void v96()
    {}
    virtual void v97()
    {}
    virtual void v98()
    {}
    virtual void v99()
    {}
    virtual void v100()
    {}
    virtual void v101()
    {}
    virtual void v102()
    {}
    virtual void v103()
    {}
    virtual void v104()
    {}
    virtual void v105()
    {}
    virtual void v106()
    {}
    virtual void v107()
    {}
    virtual void v108()
    {}
    virtual void v109()
    {}
    virtual void v110()
    {}
    virtual void v111()
    {}
    virtual void v112()
    {}
    virtual void v113()
    {}
    virtual void v114()
    {}
    virtual void v115()
    {}
    virtual void v116()
    {}
    virtual void v117()
    {}
    virtual void v118()
    {}
    virtual void v119()
    {}
    virtual void v120()
    {}
    virtual void v121()
    {}
    virtual void v122()
    {}

    void CallLastVirtualMethod();
};
struct Str
{
    void* a;
    int b;
    int c;
    Str();
    Str(const Str&);
    ~Str();
    Str& operator=(const Str&);
    const char* CStr();
    Str& Fn7480();
    void SetPos(float, float, float);
    void SetRate(int);
    void SetObj(void*);
    void Set8830(int);
    void Set8e60(void(__cdecl*)(unsigned int, int), unsigned int);
    int Get8b30();
};
struct Named
{
    const char* CStr();
};
struct Obj
{
    unsigned int GetID();
    void Fn150();
    void Fn170(int, void*);
    Named* GetName();
};
struct Obj2
{
    Obj* GetObj2();
};
struct Sub
{
    Obj2* GetObj();
    Named* GetNamed();
    Named* GetNamed2();
};
struct Proc
{
    ~Proc();
    Obj* GetObj();
    void Fn7b0();
    Sub* GetSub();
};
struct Arg
{
    Proc* Create(void*, int, int, int, int);
};
struct Mgr
{
    void Add(const char*, void (*)(), unsigned int);
};
Mgr* GetMgr();
struct Audio
{
    Str GetHandle(const char*, int, int);
};
Audio* GetAudio();
struct Setting
{
    float* Get();
};
struct BoolSetting
{
    bool* Get();
};
extern Setting DAT_011e060c;
extern BoolSetting DAT_011d8928;
extern const double DAT_01017a40;
void Callback();
void __cdecl CB3(unsigned int, int);
void __cdecl FmtStr(char*, int, const char*);
void __cdecl Spawn(const char*, Str, NiPoint3, int, int);
struct Inner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void Play(int, Str);
};
struct Self
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void* Get1d0();
    virtual void w117();
    virtual void w118();
    virtual void w119();
    virtual void w120();
    virtual void w121();
    virtual void w122();
    virtual void w123();
    virtual void w124();
    virtual NiPoint3* GetPos();
    char pad04[0x64];
    Inner* inner;
    char pad6c[0x13];
    bool flag7f;
    bool flag80;
    void Fn4250();
    void Fn7ad20(Arg*);
    void Fn7ace0(Obj*);
    unsigned int GetID();
    Str MakeStr(Obj*, int, int, int);
    bool Check();
    Str PlaySoundOnObject(Arg* arg, int p2, bool p3, bool p4, int p5, bool p6);
};
struct FUN_008ac850_object
{
    void __thiscall SetWaterForm(void* value);
};
struct FUN_008ac850_owner
{
    virtual void* f0000();
    virtual void* f0001();
    virtual void* f0002();
    virtual void* f0003();
    virtual void* f0004();
    virtual void* f0005();
    virtual void* f0006();
    virtual void* f0007();
    virtual void* f0008();
    virtual void* f0009();
    virtual void* f0010();
    virtual void* f0011();
    virtual void* f0012();
    virtual void* f0013();
    virtual void* f0014();
    virtual void* f0015();
    virtual void* f0016();
    virtual void* f0017();
    virtual void* f0018();
    virtual void* f0019();
    virtual void* f0020();
    virtual void* f0021();
    virtual void* f0022();
    virtual void* f0023();
    virtual void* f0024();
    virtual void* f0025();
    virtual void* f0026();
    virtual void* f0027();
    virtual void* f0028();
    virtual void* f0029();
    virtual void* f0030();
    virtual void* f0031();
    virtual void* f0032();
    virtual void* f0033();
    virtual void* f0034();
    virtual void* f0035();
    virtual void* f0036();
    virtual void* f0037();
    virtual void* f0038();
    virtual void* f0039();
    virtual void* f0040();
    virtual void* f0041();
    virtual void* f0042();
    virtual void* f0043();
    virtual void* f0044();
    virtual void* f0045();
    virtual void* f0046();
    virtual void* f0047();
    virtual void* f0048();
    virtual void* f0049();
    virtual void* f0050();
    virtual void* f0051();
    virtual void* f0052();
    virtual void* f0053();
    virtual void* f0054();
    virtual void* f0055();
    virtual void* f0056();
    virtual void* f0057();
    virtual void* f0058();
    virtual void* f0059();
    virtual void* f0060();
    virtual void* f0061();
    virtual void* f0062();
    virtual void* f0063();
    virtual void* f0064();
    virtual void* f0065();
    virtual void* f0066();
    virtual void* f0067();
    virtual void* f0068();
    virtual void* f0069();
    virtual void* f0070();
    virtual void* f0071();
    virtual void* f0072();
    virtual void* f0073();
    virtual void* f0074();
    virtual void* f0075();
    virtual void* f0076();
    virtual void* f0077();
    virtual void* f0078();
    virtual void* f0079();
    virtual void* f0080();
    virtual void* f0081();
    virtual void* f0082();
    virtual void* f0083();
    virtual void* f0084();
    virtual void* f0085();
    virtual void* f0086();
    virtual void* f0087();
    virtual void* f0088();
    virtual void* f0089();
    virtual void* f0090();
    virtual void* f0091();
    virtual void* f0092();
    virtual void* f0093();
    virtual void* f0094();
    virtual void* f0095();
    virtual void* f0096();
    virtual void* f0097();
    virtual void* f0098();
    virtual void* f0099();
    virtual void* f0100();
    virtual void* f0101();
    virtual void* f0102();
    virtual void* f0103();
    virtual void* f0104();
    virtual void* f0105();
    virtual void* f0106();
    virtual void* f0107();
    virtual void* f0108();
    virtual void* f0109();
    virtual void* f0110();
    virtual void* f0111();
    virtual void* f0112();
    virtual void* f0113();
    virtual void* f0114();
    virtual void* f0115();
    virtual void* f0116();
    virtual void* f0117();
    virtual void* f0118();
    virtual void* f0119();
    virtual void* f0120();
    virtual void* f0121();
    virtual void* f0122();
    virtual void* f0123();
    virtual void* f0124();
    virtual void* f0125();
    virtual void* f0126();
    virtual void* f0127();
    virtual void* f0128();
    virtual void* f0129();
    virtual void* f0130();
    virtual void* f0131();
    virtual void* f0132();
    virtual void* f0133();
    virtual void* f0134();
    virtual void* f0135();
    virtual void* f0136();
    virtual void* f0137();
    virtual void* f0138();
    virtual void* f0139();
    virtual void* f0140();
    virtual void* f0141();
    virtual void* f0142();
    virtual void* f0143();
    virtual void* f0144();
    virtual void* f0145();
    virtual void* f0146();
    virtual void* f0147();
    virtual void* f0148();
    virtual void* f0149();
    virtual void* f0150();
    virtual void* f0151();
    virtual void* f0152();
    virtual void* f0153();
    virtual void* f0154();
    virtual void* f0155();
    virtual void* f0156();
    virtual void* f0157();
    virtual void* f0158();
    virtual void* f0159();
    virtual void* f0160();
    virtual void* f0161();
    virtual void* f0162();
    virtual void* f0163();
    virtual void* f0164();
    virtual void* f0165();
    virtual void* f0166();
    virtual void* f0167();
    virtual void* f0168();
    virtual void* f0169();
    virtual void* f0170();
    virtual void* f0171();
    virtual void* f0172();
    virtual void* f0173();
    virtual void* f0174();
    virtual void* f0175();
    virtual void* f0176();
    virtual void* f0177();
    virtual void* f0178();
    virtual void* f0179();
    virtual void* f0180();
    virtual void* f0181();
    virtual void* f0182();
    virtual void* f0183();
    virtual void* f0184();
    virtual void* f0185();
    virtual void* f0186();
    virtual void* f0187();
    virtual void* f0188();
    virtual void* f0189();
    virtual void* f0190();
    virtual void* f0191();
    virtual void* f0192();
    virtual void* f0193();
    virtual void* f0194();
    virtual void* f0195();
    virtual void* f0196();
    virtual void* f0197();
    virtual void* f0198();
    virtual void* f0199();
    virtual void* f0200();
    virtual void* f0201();
    virtual void* f0202();
    virtual void* f0203();
    virtual void* f0204();
    virtual void* f0205();
    virtual void* f0206();
    virtual void* f0207();
    virtual void* f0208();
    virtual void* f0209();
    virtual void* f0210();
    virtual void* f0211();
    virtual void* f0212();
    virtual void* f0213();
    virtual void* f0214();
    virtual void* f0215();
    virtual void* f0216();
    virtual void* f0217();
    virtual void* f0218();
    virtual void* f0219();
    virtual void* f0220();
    virtual void* f0221();
    virtual void* f0222();
    virtual void* f0223();
    virtual void* f0224();
    virtual void* f0225();
    virtual void* f0226();
    virtual void* f0227();
    virtual void* f0228();
    virtual void* f0229();
    virtual void* f0230();
    virtual void* f0231();
    virtual void* f0232();
    virtual void* f0233();
    virtual void* f0234();
    virtual void* f0235();
    virtual void* f0236();
    virtual void* f0237();
    virtual void* f0238();
    virtual void* f0239();
    virtual void* f0240();
    virtual void* f0241();
    virtual void* f0242();
    virtual void* f0243();
    virtual void* f0244();
    virtual void* f0245();
    virtual void* f0246();
    virtual void* f0247();
    virtual void* f0248();
    virtual void* f0249();
    virtual void* f0250();
    virtual void* f0251();
    virtual void* f0252();
    virtual void* f0253();
    virtual void* f0254();
    virtual void* f0255();
    virtual void* f0256();
    virtual void* f0257();
    virtual void* f0258();
    virtual void* f0259();
    virtual void* f0260();
    virtual void* f0261();
    virtual void* f0262();
    virtual void* f0263();
    virtual void* f0264();
    virtual void* f0265();
    virtual FUN_008ac850_object* f0266();

    void __thiscall FUN_008ac850(void* value);
};
// Pool of 1000 entry pointers (all null) plus three 4-slot tables, all cleared on construction.
struct PoolEntry;
class PoolEntryArray
{
  public:
    void* m_pVtbl;
    PoolEntry** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    PoolEntryArray(unsigned int uiMaxSize, unsigned int uiGrowBy);
    ~PoolEntryArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, PoolEntry* const& rpEntry);
};
class FUN_0096a850 : public PoolEntryArray
{
  public:
    void* m_apActive[4];
    void* m_apPending[4];
    void* m_apFree[4];

    FUN_0096a850();
};
struct ActorAVVtbl
{
    virtual void a000();
    virtual void a001();
    virtual void a002();
    virtual void a003();
    virtual void a004();
    virtual void a005();
    virtual void a006();
    virtual void a007();
    virtual void a008();
    virtual void a009();
    virtual void a00a();
    virtual void a00b();
    virtual void a00c();
    virtual void a00d();
    virtual void a00e();
    virtual void a00f();
    virtual void a010();
    virtual void a011();
    virtual void a012();
    virtual void a013();
    virtual void a014();
    virtual void a015();
    virtual void a016();
    virtual void a017();
    virtual void a018();
    virtual void a019();
    virtual void a01a();
    virtual void a01b();
    virtual void a01c();
    virtual void a01d();
    virtual void a01e();
    virtual void a01f();
    virtual void a020();
    virtual void a021();
    virtual void a022();
    virtual void a023();
    virtual void a024();
    virtual void a025();
    virtual void a026();
    virtual void a027();
    virtual void a028();
    virtual void a029();
    virtual void a02a();
    virtual void a02b();
    virtual void a02c();
    virtual void a02d();
    virtual void a02e();
    virtual void a02f();
    virtual void a030();
    virtual void a031();
    virtual void a032();
    virtual void a033();
    virtual void a034();
    virtual void a035();
    virtual void a036();
    virtual void a037();
    virtual void a038();
    virtual void a039();
    virtual void a03a();
    virtual void a03b();
    virtual void a03c();
    virtual void a03d();
    virtual void a03e();
    virtual void a03f();
    virtual void a040();
    virtual void a041();
    virtual void a042();
    virtual void a043();
    virtual void a044();
    virtual void a045();
    virtual void a046();
    virtual void a047();
    virtual void a048();
    virtual void a049();
    virtual void a04a();
    virtual void a04b();
    virtual void a04c();
    virtual void a04d();
    virtual void a04e();
    virtual void a04f();
    virtual void a050();
    virtual void a051();
    virtual void a052();
    virtual void a053();
    virtual void a054();
    virtual void a055();
    virtual void a056();
    virtual void a057();
    virtual void a058();
    virtual void a059();
    virtual void a05a();
    virtual void a05b();
    virtual void a05c();
    virtual void a05d();
    virtual void a05e();
    virtual void a05f();
    virtual void a060();
    virtual void a061();
    virtual void a062();
    virtual void a063();
    virtual void a064();
    virtual void a065();
    virtual void a066();
    virtual void a067();
    virtual void a068();
    virtual void a069();
    virtual void a06a();
    virtual void a06b();
    virtual void a06c();
    virtual void a06d();
    virtual void a06e();
    virtual void a06f();
    virtual void a070();
    virtual void a071();
    virtual void a072();
    virtual void a073();
    virtual void a074();
    virtual void a075();
    virtual void a076();
    virtual void a077();
    virtual void a078();
    virtual void a079();
    virtual void a07a();
    virtual void a07b();
    virtual void a07c();
    virtual void a07d();
    virtual void a07e();
    virtual void a07f();
    virtual void a080();
    virtual void a081();
    virtual void a082();
    virtual void a083();
    virtual void a084();
    virtual void a085();
    virtual void a086();
    virtual void a087();
    virtual void a088();
    virtual void a089();
    virtual void a08a();
    virtual void a08b();
    virtual void a08c();
    virtual void a08d();
    virtual void a08e();
    virtual void a08f();
    virtual void a090();
    virtual void a091();
    virtual void a092();
    virtual void a093();
    virtual void a094();
    virtual void a095();
    virtual void a096();
    virtual void a097();
    virtual void a098();
    virtual void a099();
    virtual void a09a();
    virtual void a09b();
    virtual void a09c();
    virtual void a09d();
    virtual void a09e();
    virtual void a09f();
    virtual void a0a0();
    virtual void a0a1();
    virtual void a0a2();
    virtual void a0a3();
    virtual void a0a4();
    virtual void a0a5();
    virtual void a0a6();
    virtual void a0a7();
    virtual void a0a8();
    virtual void a0a9();
    virtual void a0aa();
    virtual void a0ab();
    virtual void a0ac();
    virtual void a0ad();
    virtual void a0ae();
    virtual void a0af();
    virtual void a0b0();
    virtual void a0b1();
    virtual void a0b2();
    virtual void a0b3();
    virtual void a0b4();
    virtual void a0b5();
    virtual void a0b6();
    virtual void a0b7();
    virtual void a0b8();
    virtual void a0b9();
    virtual void a0ba();
    virtual void a0bb();
    virtual void a0bc();
    virtual void a0bd();
    virtual void a0be();
    virtual void a0bf();
    virtual void a0c0();
    virtual void a0c1();
    virtual void a0c2();
    virtual void a0c3();
    virtual void a0c4();
    virtual void a0c5();
    virtual void a0c6();
    virtual void a0c7();
    virtual void a0c8();
    virtual void a0c9();
    virtual void a0ca();
    virtual void a0cb();
    virtual void a0cc();
    virtual void a0cd();
    virtual void a0ce();
    virtual void a0cf();
    virtual void a0d0();
    virtual void a0d1();
    virtual void a0d2();
    virtual void a0d3();
    virtual void a0d4();
    virtual void a0d5();
    virtual void a0d6();
    virtual void a0d7();
    virtual void a0d8();
    virtual void a0d9();
    virtual void a0da();
    virtual void a0db();
    virtual void a0dc();
    virtual void a0dd();
    virtual void a0de();
    virtual void a0df();
    virtual void a0e0();
    virtual void a0e1();
    virtual void a0e2();
    virtual void a0e3();
    virtual void a0e4();
    virtual void a0e5();
    virtual void a0e6();
    virtual void a0e7();
    virtual void a0e8();
    virtual void a0e9();
    virtual void a0ea();
    virtual void a0eb();
    virtual void a0ec();
    virtual void a0ed();
    virtual void a0ee();
    virtual void a0ef();
    virtual void a0f0();
    virtual void a0f1();
    virtual void a0f2();
    virtual void a0f3();
    virtual void a0f4();
    virtual void a0f5();
    virtual void a0f6();
    virtual void a0f7();
    virtual void a0f8();
    virtual void a0f9();
    virtual void a0fa();
    virtual void a0fb();
    virtual void a0fc();
    virtual void a0fd();
    virtual void a0fe();
    virtual void a0ff();
    virtual void a100();
    virtual void a101();
    virtual void a102();
    virtual void a103();
    virtual void a104();
    virtual void a105();
    virtual void a106();
    virtual void a107();
    virtual void a108();
    virtual void a109();
    virtual void a10a();
    virtual void a10b();
    virtual void a10c();
    virtual void a10d();
    virtual void a10e();
    virtual void a10f();
    virtual void a110();
    virtual void a111();
    virtual void a112();
    virtual void a113();
    virtual void a114();
    virtual void a115();
    virtual void a116();
    virtual void a117();
    virtual void a118();
    virtual void a119();
    virtual void a11a();
    virtual void a11b();
    virtual void a11c();
    virtual void a11d();
    virtual void a11e();
    virtual void a11f();
    virtual void a120();
    virtual void a121();
    virtual void a122();
    virtual float GetAVModifierEntry(int aiAV, bool* abFound);
    virtual void SetAVModifierEntry(int aiAV, float afValue);
};
struct ActorBaseAVVtbl
{
    virtual void b000();
    virtual void b001();
    virtual void b002();
    virtual void b003();
    virtual void b004();
    virtual void b005();
    virtual void b006();
    virtual void b007();
    virtual void b008();
    virtual void b009();
    virtual void b00a();
    virtual void b00b();
    virtual void b00c();
    virtual void b00d();
    virtual void b00e();
    virtual void b00f();
    virtual void b010();
    virtual void b011();
    virtual void b012();
    virtual void b013();
    virtual void b014();
    virtual void b015();
    virtual void b016();
    virtual void b017();
    virtual void b018();
    virtual void b019();
    virtual void b01a();
    virtual void b01b();
    virtual void b01c();
    virtual void b01d();
    virtual void b01e();
    virtual void b01f();
    virtual void b020();
    virtual void b021();
    virtual void b022();
    virtual void b023();
    virtual void b024();
    virtual void b025();
    virtual void b026();
    virtual void b027();
    virtual void b028();
    virtual void b029();
    virtual void b02a();
    virtual void b02b();
    virtual void b02c();
    virtual void b02d();
    virtual void b02e();
    virtual void b02f();
    virtual void b030();
    virtual void b031();
    virtual void b032();
    virtual void b033();
    virtual void b034();
    virtual void b035();
    virtual void b036();
    virtual void b037();
    virtual void b038();
    virtual void b039();
    virtual void b03a();
    virtual void b03b();
    virtual void b03c();
    virtual void b03d();
    virtual void b03e();
    virtual void b03f();
    virtual void b040();
    virtual void b041();
    virtual void b042();
    virtual void b043();
    virtual void b044();
    virtual void b045();
    virtual void b046();
    virtual void b047();
    virtual void b048();
    virtual void b049();
    virtual void b04a();
    virtual void b04b();
    virtual void b04c();
    virtual void b04d();
    virtual void b04e();
    virtual void b04f();
    virtual void b050();
    virtual void b051();
    virtual void b052();
    virtual void b053();
    virtual void b054();
    virtual void b055();
    virtual void b056();
    virtual void b057();
    virtual void b058();
    virtual void b059();
    virtual void b05a();
    virtual void b05b();
    virtual void b05c();
    virtual void b05d();
    virtual void b05e();
    virtual void b05f();
    virtual void b060();
    virtual void b061();
    virtual void b062();
    virtual void b063();
    virtual void b064();
    virtual void b065();
    virtual void b066();
    virtual void ModBaseAV(int aiAV, int aiAmount);
};
bool __cdecl IsAVModifiable(int aiAV);
void __cdecl OnAVChanged(int aiAV);
void __cdecl NotifyAVChange(ActorValueOwner* apOwner, int aiAV, float afOld, float afDelta, int aiFlag);
struct ActorAVUpdater
{
    void UpdateAV(int aiAV, bool abFlag);
};
struct FUN_0093a8f0_shell : public Actor
{
    void FUN_0093a8f0(int aiAV, int aiAmount);
};
extern "C" void* __cdecl CreatePackageByType(int);
struct XA8a
{
    unsigned char GetExtraDataVersion();
};
struct XAObj
{
    void FUN_00826b40(int);
    void FUN_00826b90(int);
    void FUN_00671d30(void*);
    void FUN_00984f60(int);
    void* FUN_00671d10(int);
    void FUN_00672fc0(void*);
};
struct XPObj
{
    XPObj();
    ~XPObj();
    void SetLocType(int);
    void SetLocReference(void*);
    void* unk00;
    void* unk04;
    void* unk08;
};
struct XVObj
{
    XVObj();
    ~XVObj();
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
};
struct XTmpObj
{
    void FUN_006800b0();
    void FUN_00680110();
    void FUN_00403550();
};
struct XMember
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void Attach(int, void*);
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void Detach(int);
};
struct XUpdatable
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void Update();
};
struct XObj
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void Finish(XAObj*, int, int);
    void FUN_009694d0(void* arg0);
    void FUN_005cc7a0(int);
    void FUN_00950340(int);
    XUpdatable* FUN_008d8520();
    void* unk04[25];
    XMember* member68;
};

class TESObjectARMO : public TESBoundObject
{
};
struct FUN_004bc5f0
{
    void* extraData;
    int count;
    TESBoundObject* object;
    ~FUN_004bc5f0();
    TESBoundObject* FUN_0044ddc0();
    float FUN_004be0b0(ActorValueOwner*);
};
struct EquipmentList536
{
    FUN_004bc5f0* FUN_004c8c10(int, bool);
};
struct ExtraList536
{
    EquipmentList536* FUN_00418520();
};
struct Character536 : Character
{
    ExtraList536* FUN_005d43c0();
    float FUN_008d2110();
};
// @fnv 0x008d2110
float Character536::FUN_008d2110()
{
    int count = 0;
    TESObjectARMO* forms3[20];
    forms3[0] = 0;
    if (m_fSecondValue < _gModifierZero)
    {
        m_fSecondValue = 0.0f;
        EquipmentList536* list6 = FUN_005d43c0()->FUN_00418520();
        FUN_004bc5f0* item7 = 0;
        if (list6)
        {
            for (int index = 0; index < 20; ++index)
            {
                item7 = list6->FUN_004c8c10(index, false);
                if (item7)
                {
                    TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(item7->FUN_0044ddc0());
                    if (armor)
                    {
                        bool found4 = false;
                        if (count != 0)
                        {
                            for (int scan5 = 0; scan5 < count && !found4; ++scan5)
                                found4 = forms3[scan5] == armor;
                        }
                        if (!found4)
                        {
                            m_fSecondValue += item7->FUN_004be0b0(static_cast<ActorValueOwner*>(this));
                            forms3[count] = armor;
                            ++count;
                        }
                    }
                    delete item7;
                    item7 = 0;
                }
            }
        }
    }
    return m_fSecondValue;
}

float __cdecl FUN_0040ebd0(float a, float b);

// Adapted from an unverified 2026-10-23 contribution by another contributor.

struct InventoryEntry_8d22b0
{
    ~InventoryEntry_8d22b0();
    TESBoundObject* GetBaseObject();
    float GetEntryWeight(ActorValueOwner* owner);
};
struct InventoryData_8d22b0
{
    InventoryEntry_8d22b0* GetEquippedEntry(int index, int flags);
};
struct ContainerChanges_8d22b0
{
    InventoryData_8d22b0* GetData();
};

union SETTING_VALUE
{
    float f;
    int i;
    unsigned int u;
    char* str;
};
template <> class SettingT<GameSettingCollection>
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1016;

struct FUN_008d22b0_shell : public Actor
{
    int unk1b4;
    float m_kEighthUnshownMember;
    ContainerChanges_8d22b0* GetContainerChanges_();
    float FUN_008d22b0();
};

// @fnv 0x008d22b0
float FUN_008d22b0_shell::FUN_008d22b0()
{
    int iCount = 0;
    TESObjectARMO* armors[20];
    armors[0] = 0;
    if (m_kEighthUnshownMember < 0.0)
    {
        m_kEighthUnshownMember = 0.0f;
        InventoryData_8d22b0* items = GetContainerChanges_()->GetData();
        InventoryEntry_8d22b0* entry = 0;
        if (items)
        {
            for (int i = 0; i < 20; i++)
            {
                entry = items->GetEquippedEntry(i, 0);
                if (entry)
                {
                    TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>(entry->GetBaseObject());
                    if (armor)
                    {
                        bool found = false;
                        if (iCount)
                        {
                            for (int j = 0; j < iCount && !found; j++)
                            {
                                found = armors[j] == armor;
                            }
                        }
                        if (!found)
                        {
                            m_kEighthUnshownMember += entry->GetEntryWeight(this);
                            armors[iCount++] = armor;
                        }
                    }
                    delete entry;
                    entry = 0;
                }
            }
        }
    }
    return originalRuntimeFloatSetting1016.Float()->f > 0.0
               ? FUN_0040ebd0(m_kEighthUnshownMember, originalRuntimeFloatSetting1016.Float()->f)
               : m_kEighthUnshownMember;
}

class TESObjectCLOT : public TESBoundObject
{
};
struct InventoryEntryWeight534
{
    double FUN_004bd400();
};
struct EquipmentList534
{
    FUN_004bc5f0* FUN_004c8c10(int, bool);
};
struct ExtraList534
{
    EquipmentList534* FUN_00418520();
};
extern Setting DAT_011d0ca8, DAT_011d1104, DAT_011d0d14, DAT_011d043c;
struct Character534 : Character
{
    ExtraList534* FUN_005d43c0();
    float FUN_008d3110();
};
// @fnv 0x008d3110
float Character534::FUN_008d3110()
{
    float weight = 0.0f;
    EquipmentList534* list = FUN_005d43c0()->FUN_00418520();
    FUN_004bc5f0* item9 = 0;
    int index2;
    TESObjectARMO* armor7;
    TESObjectCLOT* clothing;
    if (list)
    {
        for (index2 = 0; index2 < 20; ++index2)
        {
            item9 = list->FUN_004c8c10(index2, false);
            if (item9)
            {
                armor7 = dynamic_cast<TESObjectARMO*>(item9->FUN_0044ddc0());
                clothing = dynamic_cast<TESObjectCLOT*>(item9->FUN_0044ddc0());
                if (armor7)
                    weight +=
                        ((InventoryEntryWeight534*)item9)->FUN_004bd400() * *DAT_011d0ca8.Get() + *DAT_011d1104.Get();
                else if (clothing)
                    weight +=
                        ((InventoryEntryWeight534*)item9)->FUN_004bd400() * *DAT_011d0d14.Get() + *DAT_011d043c.Get();
                // GetEquippedItem returns an owned temporary inventory entry.
                delete item9;
                item9 = 0;
            }
        }
    }
    if (weight > 100.0)
        weight = 100.0f;
    return weight;
}
