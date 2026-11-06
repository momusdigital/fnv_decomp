// src/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void* g_012026b0;
void* __cdecl FUN_00c285c0();
struct NiBinaryStream
{
    int _0;
    int _4;
    int _8;
    int(__cdecl* _12)(NiBinaryStream*, void*, int, unsigned int*, int);
};
struct NiStream
{
    char _0[0x250];
    NiBinaryStream* m_pBackingStream;
};
struct NiPSysFieldModifier
{
    char _0[0x30];
    void SaveBinary(NiStream&);
};
struct NiPSysRadialFieldModifier : NiPSysFieldModifier
{
    float _30;
    void FUN_00c27770(NiStream&);
};
struct NiPSysPositionModifier
{
    char _pad[0x18];
    NiPSysPositionModifier();
};
extern int DAT_010c0b5c;
struct FUN_00c31ff0 : NiPSysPositionModifier
{
    int _m18;
    float _m1c;
    float _m20;
    bool _m24;
    float _m28;
    float _m2c;
    FUN_00c31ff0();
};
extern "C" char __stdcall FUN_00c32060(void*);
unsigned char __stdcall IsEqual(void* p);
struct S_00c28a90_Arr
{
    int unk00;
    int unk04;
    unsigned short size;
    unsigned short esize;
    unsigned short unk0c;
    unsigned short growBy;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char*&);
};
struct S_00c28a90_Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    void GetViewerStrings(S_00c28a90_Arr* a);
};
extern const char* DAT_012026b0;
char* __cdecl FUN_00a7d330(const char* s);
char* __cdecl FUN_00a7d550(const char* name, float value);
struct S_00c28a90 : S_00c28a90_Base
{
    float m30;
    void WriteToArray(S_00c28a90_Arr* a);
};
__forceinline void S_00c28a90_Add(S_00c28a90_Arr* a, char* s)
{
    unsigned int i = a->esize;
    if (i >= a->size)
        a->FUN_0096ad30(i + a->growBy);
    a->FUN_0096ae90(i, s);
}
struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3 operator-(const NiPoint3& pt) const
    {
        return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
    }
    NiPoint3 operator*(float fScalar) const
    {
        return NiPoint3(fScalar * x, fScalar * y, fScalar * z);
    }
    NiPoint3& operator+=(const NiPoint3& pt)
    {
        x += pt.x;
        y += pt.y;
        z += pt.z;
        return *this;
    }
};
struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
};
struct NiTransform
{
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
    void FUN_004b4880(NiTransform& kDest) const;
    __declspec(noalias) NiTransform FUN_0062c250(const NiTransform& xform) const;
};
struct NiAVObjectStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    NiTransform m_kWorldSpaceTransform;
};
struct Point3ParameterData
{
    NiPoint3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
};
struct NiPSysDataStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NiPoint3* m_pkVertex;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    unsigned short m_usActiveVertices;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    Point3ParameterData* m_pkParticleInfo;
};
struct FieldMod
{
    void* vtbl;
    int m_uiRefCount;
    int m_kName;
    int m_uiUpdateOrder;
    NiAVObjectStandIn* m_pkTarget;
    int m_bModifierActive;
    NiAVObjectStandIn* m_pkFieldObject;
    float m_fInfluence;
    void Update(float fTime, NiPSysDataStandIn* pkData);
};

extern int DAT_010be99c;
void* __cdecl FUN_00aa13e0(unsigned int size);

struct RadialFieldObject_00c285d0 : FUN_00c31ff0
{
    static void* operator new(unsigned int, void* where) throw()
    {
        return where;
    }
    float m30;
    RadialFieldObject_00c285d0()
    {
        m30 = 0.0f;
        *((int*)this) = (int)&DAT_010be99c;
    }
};

struct FUN_00c285d0_cls
{
    int unk0;
    void FUN_00c32020(void* obj, unsigned int a1);
    void* CreateClone(unsigned int a1);
};

// @fnv 0x00c285d0
void* FUN_00c285d0_cls::CreateClone(unsigned int a1)
{
    RadialFieldObject_00c285d0* p = new (FUN_00aa13e0(0x34)) RadialFieldObject_00c285d0;
    FUN_00c32020(p, a1);
    return p;
}
