
// src/fallout/ai/mobileobject_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/mobileobject_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/mobileobject_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/mobileobject.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
class ExtraDismemberedLimbs;
class bhkCharacterController;
#include "../../../include/layout_support.h"
#include "../../../include/Actor.h"
#include "../../../include/BaseProcess.h"
#include "mobileobject_private/mobileobject_types_TESPackage.h"
#include "mobileobject_private/mobileobject_interface.h"
#include "../../../include/BSAudio.h"
#include "../../../include/SoundPlaybackHandle.h"
extern TESDataHandler* g_dataHandler;
#include "mobileobject_private/mobileobject_packet.h"
bhkCharacterController* CopyCharacterControllerVector(bhkCharacterController* output, const NiPoint3& point);
struct UnkCallee
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4(int, int);
};
struct UnkRet
{
    char _0[16];
    UnkCallee* p10;
};
struct UnkHolder
{
    char _0[12];
    volatile int mC;
    volatile int m10;
    volatile int m14;
    UnkRet* FUN_00c85750();
    void FUN_00c72210();
};

struct bhkWorldObject;
struct bhkCollisionObject
{
    bhkWorldObject* FUN_006fa820();
};
struct bhkRigidBody_shell
{
    int FUN_00517630();
    void* FUN_00560d80();
    void FUN_00561690(void*);
};
bhkCollisionObject* __cdecl FUN_0043b610(NiAVObject*);
bool __cdecl FUN_00c8cce0(int*);
struct FNV_ALIGN(16) bhkUnaryAction
{
    char buf[16];
    bhkUnaryAction();
    void Set(float, float, float, float);
    void FUN_00553f70(void*);
};
struct Vec3Arg
{
    float* FUN_00560d30(int);
};
class NiNode
{
  public:
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(unsigned int);
};
class NiAVObject
{
  public:
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual NiNode* IsSceneNode();
};

// @fnv 0x0062b930
void __cdecl FUN_0062b930(NiAVObject* apObject, Vec3Arg* apVec, bool abFlag)
{
    if (apObject)
    {
        bhkCollisionObject* j = FUN_0043b610(apObject);
        if (j)
        {
            bhkRigidBody_shell* e = (bhkRigidBody_shell*)j->FUN_006fa820();
            if (e)
            {
                int c = e->FUN_00517630();
                if (FUN_00c8cce0(&c))
                {
                    bhkUnaryAction l;
                    l.Set(*apVec->FUN_00560d30(0), *apVec->FUN_00560d30(1), *apVec->FUN_00560d30(2), 0.0f);
                    if (!abFlag)
                    {
                        l.FUN_00553f70(e->FUN_00560d80());
                    }
                    e->FUN_00561690(&l);
                }
            }
        }
        NiNode* k = apObject->IsSceneNode();
        if (k)
        {
            for (unsigned int ba = 0; ba < k->FUN_0043b480(); ba++)
            {
                NiAVObject* b = k->FUN_0043b4a0(ba);
                FUN_0062b930(b, apVec, abFlag);
            }
        }
    }
}

struct xFilter
{
    xFilter(int, unsigned int, int);
    unsigned int FUN_00559450();
    unsigned int m_uiFilterValue;
};
unsigned int xFUN_005dbe10();
struct xDH;
struct xCinfoSub
{
    void FUN_0056e120();
    void FUN_009ae4a0(xDH*);
    int m_q[12];
};
struct __declspec(align(16)) xCinfo
{
    xCinfo();
    ~xCinfo();
    unsigned int m_uiFilterInfo;
    int m_pCollisionShape;
    int m_pad08[6];
    xCinfoSub m_20;
    int m_pad50[4];
};
struct xNiAlloc
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct xShape : xNiAlloc
{
    xShape(float, bool);
    int m_auiShapeKeys[5];
};
struct xBody : xNiAlloc
{
    xBody(xCinfo*);
    int m_auiShapeKeys[6];
};
int __fastcall xFUN_004ae750(void*);
struct xNode;
struct xWorld;
struct xCell;
xWorld* __fastcall xFUN_004543c0(xCell*);
struct xBodyV
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
    virtual void FUN_9c(xWorld*);
};

struct xPtr
{
    bool operator==(xNode*) const;
    void FUN_0066b0d0(void*);
    xBodyV* operator->();
    void* m_p;
};
struct xDHOwner
{
    xDH* FUN_00461130();
};
struct xRef
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
    virtual xDHOwner* FUN_1d0();
    char m_pad04[0x9c];
    xPtr m_a0;
    xCell* FUN_008d6f30();
    float FUN_00644930();
    void InitHavok();
};

// @fnv 0x009ae280
void xRef::InitHavok()
{
    if (m_a0 == 0 && FUN_008d6f30() && xFUN_004543c0(FUN_008d6f30()))
    {
        xCinfo CINFO;
        xShape* SHAPE = new xShape(FUN_00644930(), true);
        CINFO.m_pCollisionShape = xFUN_004ae750(SHAPE);
        CINFO.m_uiFilterInfo = xFilter(0x29, xFUN_005dbe10(), 0).FUN_00559450();
        if (FUN_1d0())
            CINFO.m_20.FUN_009ae4a0(FUN_1d0()->FUN_00461130());
        else
            CINFO.m_20.FUN_0056e120();
        m_a0.FUN_0066b0d0(new xBody(&CINFO));
        m_a0->FUN_9c(xFUN_004543c0(FUN_008d6f30()));
    }
}

#include <xmmintrin.h>
class Point9BE
{
  public:
    Point9BE();
    Point9BE(float fX, float fY, float fZ);
    float x, y, z;
};

class Matrix9BE
{
  public:
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};

class hkVector4_9BE
{
  public:
    hkVector4_9BE();
    hkVector4_9BE(float fX, float fY, float fZ, float fW);
    void Set(float fX, float fY, float fZ, float fW);
    __m128 m_vComponents;
};

class Filter9BE
{
  public:
    Filter9BE();
    unsigned int GetGroup();
    unsigned int m_uiBits;
};

class Node9BE;

class Entity9BE
{
  public:
    void SetLinearVelocity(const hkVector4_9BE& kMotionVelocity);
};

class WorldObject9BE
{
  public:
    Filter9BE GetFilter();
    Entity9BE* GetEntity();
};

class CollisionObject9BE
{
  public:
    WorldObject9BE* GetWorldObject();
};

class NiNode9BE;

class Node9BE
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual NiNode9BE* IsSceneNode();
    const Matrix9BE& GetRotate();
};

class NiNode9BE : public Node9BE
{
  public:
    unsigned int GetArrayCount();
    Node9BE* GetAt(unsigned int uiIndex);
};

class Shape9BE
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
    Shape9BE(float fRadius, int iType);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

class World9BE
{
  public:
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
    virtual void HandleNode(Node9BE* pkNode, int iA, int iB, unsigned int uiFilterInfo, int iC);
    bool IsActive();
};

class ControllerInfo9BE
{
  public:
    ControllerInfo9BE(int iType);
    ~ControllerInfo9BE();
    void SetScale(float fScale);
    void SetNode(Node9BE* pkNode);
    void SetPosition(const Point9BE* pkPos);
    void SetWorld(World9BE* pkWorld);
    void SetHeight(float m_fGlyphExtent);
    void SetShape(Shape9BE* pkShape);
    void SetFlags(int iFlags);
    void SetFilter(int iIndex, unsigned int uiFilterInfo);
    void SetLayer(int iLayer);
    void SetMode(int iMode);
    __m128 m_q00;
    __m128 m_q10;
    __m128 m_q20;
    __m128 m_q30;
    __m128 m_q40;
    __m128 m_q50;
    __m128 m_q60;
    __m128 m_q70;
    __m128 m_q80;
    __m128 m_q90;
    __m128 m_qa0;
    __m128 m_qb0;
};

class Actor9BE;

class Controller9BE
{
  public:
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
    virtual void SetState(int iState);
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
    Controller9BE(ControllerInfo9BE& kInfo, Actor9BE* pkActor);
    void SetEnabled(bool bEnabled);
    void SetMode(int iMode);
    void SetUp(const hkVector4_9BE& kUp);
    void SetActor(Actor9BE* pkActor);
    void SetFallDistance(float fDistance);
    World9BE* GetWorld();
    void SetWorld(World9BE* pkWorld);
    Node9BE* GetNode();
    void SetNode(Node9BE* pkNode);
    void SetPosition(Point9BE& kPos);
    Filter9BE GetFilter();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
};

class ControllerPtr9BE
{
  public:
    ControllerPtr9BE(Controller9BE* pkController);
    ControllerPtr9BE(const ControllerPtr9BE& kOther);
    ~ControllerPtr9BE();
    Controller9BE* m_pPointer;
};

class Process9BE
{
  public:
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
    virtual void SetController(ControllerPtr9BE spController);
    int IsDead();
};

class Middle9BE
{
  public:
    World9BE* GetWorld();
    float GetFallDistance();
};

class Perks9BE
{
  public:
    virtual void v00();
    virtual void v04();
    virtual int GetLevel(int iPerk);
};

class Target9BE
{
  public:
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
    virtual bool IsActor();
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
    virtual Node9BE* Get3D();
    Filter9BE GetFilter();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    Perks9BE m_kPerks;
};

class Base9BE
{
  public:
    float GetScale();
    bool IsSmall();
    float GetX();
    float GetY();
    float GetZ();
    float GetHeight();
};

class Actor9BE
{
  public:
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
    virtual Node9BE* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const Point9BE* GetPos();
    Controller9BE* GetController();
    Middle9BE* GetMiddle();
    bool IsFlagSet(int iFlag);
    Base9BE* GetBaseObject();
    Target9BE* GetOwner();
    void InitHavok();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    Process9BE* m_pkProcess;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    Target9BE* m_pkTarget;
};

class Setting9BE
{
  public:
    float* GetFloat();
};
extern Setting9BE g_kSettingA9BE;
extern Setting9BE g_kSettingB9BE;
extern const float g_fMaxFallDistance9BE;
extern const float g_fMaxValue9BE;

CollisionObject9BE* __cdecl FUN_004a8b00(Node9BE* pkNode);
CollisionObject9BE* __cdecl FUN_004b5260(Node9BE* pkNode);
WorldObject9BE* __cdecl FUN_004b5a80(Entity9BE* pkEntity);
bool __cdecl FUN_00525420();
float __cdecl FUN_00716440();
void __cdecl FUN_00a582f0(const Matrix9BE& kRot, const Point9BE& kIn, int iFlag, Point9BE& kA, Point9BE& kB);
void __cdecl CopyBlock48(Node9BE* pkNode, int iFlag);
void __cdecl FUN_00c6a0b0(Node9BE* pkNode, int iA, int iB, int iC);
void __cdecl SetSelectionValue(Node9BE* pkNode, float fValue, int iA, int iB);
void __cdecl ApplyCollisionObjectCount(Node9BE* pkNode, float fValue, int iA, int iB);
void __cdecl FUN_00c6a350(Node9BE* pkNode, int iA, int iB, int iC, int iD);
void __cdecl FUN_00c6a3d0(Node9BE* pkNode, unsigned int uiFilterInfo, int iA, int iB);
void __cdecl TraverseObject(Node9BE* pkNode, int iA, int iB, int iC, int iD);
void __cdecl FUN_00c69ee0(Node9BE* pkNode, int iA, int iB);
void __cdecl FUN_00c69f50(Node9BE* pkNode, int iA, int iB);

// @fnv 0x009be0a0
void Actor9BE::InitHavok()
{
    Node9BE* pkNode = Get3D();
    if (!pkNode || !m_pkProcess || m_pkProcess->IsDead())
        return;
    Middle9BE* pkMiddle = GetMiddle();
    World9BE* pkWorld = pkMiddle ? pkMiddle->GetWorld() : 0;
    if (pkWorld)
    {
        if (IsFlagSet(8))
        {
            FUN_00c6a0b0(pkNode, 0, 1, 0);
            FUN_00c6a350(pkNode, 4, 1, 0, 1);
            return;
        }
        CollisionObject9BE* pkCollision = FUN_004a8b00(pkNode);
        WorldObject9BE* pkWorldObject = 0;
        Entity9BE* pkEntity = 0;
        if (IsFlagSet(4))
        {
            FUN_00c6a350(Get3D(), 1, 1, 0, 1);
            if (*g_kSettingA9BE.GetFloat() != 0.0)
            {
                if (GetBaseObject()->GetScale() > 0.0)
                    SetSelectionValue(pkNode, *g_kSettingA9BE.GetFloat() * GetBaseObject()->GetScale(), 1, 0);
                else
                    SetSelectionValue(pkNode, *g_kSettingA9BE.GetFloat(), 1, 0);
            }
            if (*g_kSettingB9BE.GetFloat() != 0.0)
                ApplyCollisionObjectCount(pkNode, *g_kSettingB9BE.GetFloat(), 1, 0);
            TraverseObject(pkNode, 6, 0, 1, 0);
            if (GetOwner())
            {
                if (GetOwner()->IsActor())
                {
                    Target9BE* pkOwner = GetOwner();
                    FUN_00c6a3d0(pkNode, pkOwner->GetFilter().GetGroup(), 1, 0);
                }
                else
                {
                    CollisionObject9BE* pkOwnerCollision = FUN_004b5260(GetOwner()->Get3D());
                    WorldObject9BE* pkOwnerObject = pkOwnerCollision ? pkOwnerCollision->GetWorldObject() : 0;
                    if (pkOwnerObject)
                        FUN_00c6a3d0(pkNode, pkOwnerObject->GetFilter().GetGroup(), 1, 0);
                }
            }
            pkWorld->HandleNode(pkNode, 1, 1, 0, 0);
            if (pkCollision)
            {
                pkWorldObject = FUN_004b5a80(pkCollision->GetWorldObject()->GetEntity());
            }
            else if (pkNode->IsSceneNode())
            {
                NiNode9BE* pkParent = (NiNode9BE*)pkNode;
                if (pkParent->GetArrayCount())
                {
                    for (unsigned int i = 0; i < pkParent->GetArrayCount(); i++)
                    {
                        Node9BE* pkChild = pkParent->GetAt(i);
                        pkCollision = FUN_004a8b00(pkChild);
                        if (pkCollision)
                        {
                            pkWorldObject = FUN_004b5a80(pkCollision->GetWorldObject()->GetEntity());
                            break;
                        }
                    }
                }
            }
            if (pkWorldObject && GetBaseObject()->IsSmall())
            {
                pkEntity = pkWorldObject->GetEntity();
                Point9BE kIntersectionOffset(GetBaseObject()->GetX(), GetBaseObject()->GetY(), GetBaseObject()->GetZ());
                Point9BE kMotionVelocity;
                hkVector4_9BE kHkVelocity;
                Matrix9BE kRot = Get3D()->GetRotate();
                FUN_00a582f0(kRot, Point9BE(0.0f, 0.0f, 0.0f), 1, kIntersectionOffset, kMotionVelocity);
                kHkVelocity.Set(kMotionVelocity.x, kMotionVelocity.y, kMotionVelocity.z, 0.0f);
                pkEntity->SetLinearVelocity(kHkVelocity);
            }
            return;
        }
        Controller9BE* pkController = GetController();
        if (!pkController)
        {
            ControllerInfo9BE kInfo(1);
            kInfo.SetWorld(pkWorld);
            kInfo.SetScale(1.0f);
            kInfo.SetNode(pkNode);
            kInfo.SetPosition(GetPos());
            if (GetBaseObject()->IsSmall())
                kInfo.SetShape(new Shape9BE(1.0f, 1));
            else
                kInfo.SetShape(new Shape9BE(0.1f, 1));
            kInfo.SetMode(0);
            kInfo.SetFlags(0);
            float m_fGlyphExtent = GetBaseObject()->GetHeight();
            if (m_pkTarget && m_pkTarget->IsActor())
            {
                Target9BE* pkTarget = m_pkTarget;
                kInfo.SetFilter(6, pkTarget->GetFilter().GetGroup());
                if (pkTarget->m_kPerks.GetLevel(0x33) > 0)
                    m_fGlyphExtent *= 1.0f / FUN_00716440();
            }
            kInfo.SetHeight(m_fGlyphExtent);
            kInfo.SetLayer(6);
            pkController = new Controller9BE(kInfo, this);
            pkController->SetEnabled(FUN_00525420());
            pkController->SetMode(1);
            hkVector4_9BE kUp(-g_fMaxValue9BE, 0.0f, 0.0f, 0.0f);
            pkController->SetUp(kUp);
            m_pkProcess->SetController(pkController);
            pkController->SetActor(this);
            FUN_00c6a0b0(pkNode, 0, 1, 0);
        }
        if (pkController)
        {
            if (pkMiddle)
                pkController->SetFallDistance(pkMiddle->GetFallDistance());
            else
                pkController->SetFallDistance(g_fMaxFallDistance9BE);
            World9BE* pkOldWorld = pkController->GetWorld();
            pkController->SetWorld(pkWorld);
            Node9BE* pkOldNode = pkController->GetNode();
            bool bReset = true;
            if (pkOldNode != pkNode)
            {
                pkController->SetNode(pkNode);
                if (pkWorld && pkWorld->IsActive())
                {
                    pkController->SetState(0);
                    CopyBlock48(pkController->GetNode(), 1);
                }
                FUN_00c6a350(pkNode, 4, 1, 0, 1);
                bReset = true;
            }
            Point9BE kPos = *GetPos();
            if (pkOldWorld != pkWorld)
            {
                if (pkOldWorld)
                    FUN_00c69ee0(pkNode, 1, 0);
                kPos.z += 8.0;
                bReset = true;
            }
            if (pkWorld)
            {
                pkController->SetPosition(kPos);
                if (bReset)
                {
                    Filter9BE kFilter = pkController->GetFilter();
                    unsigned int uiFilterInfo = kFilter.GetGroup();
                    pkWorld->HandleNode(pkNode, 1, 0, uiFilterInfo, 0);
                }
                else
                {
                    FUN_00c69f50(pkNode, 1, 0);
                }
            }
        }
    }
}
