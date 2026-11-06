
// src/gamebryo2.2/corelibs/nicollision/nicollisiondata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nicollisiondata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern void* g_0126fab4;

// @fnv 0x00eacd20
void* __cdecl FUN_00eacd20()
{
    return &g_0126fab4;
}

extern "C" void* __cdecl _NiMalloc(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
int __cdecl NiSprintf(char*, unsigned int, const char*, ...);

// Allocates a string sized from pcPrefix and formats it as "<pcPrefix> = <mode name>" based on eMode, returning the buffer.
// @fnv 0x00eacef0
char* __stdcall FUN_00eacef0(const char* pcPrefix, unsigned int eMode)
{
    char* pString;
    unsigned int uiBufferSize;

    uiBufferSize = strlen(pcPrefix) + 0x11;
    pString = (char*)_NiMalloc(uiBufferSize);
    switch (eMode)
    {
    case 0:
        NiSprintf(pString, uiBufferSize, "%s = USE_OBB", pcPrefix);
        break;
    case 1:
        NiSprintf(pString, uiBufferSize, "%s = USE_TRI", pcPrefix);
        break;
    case 2:
        NiSprintf(pString, uiBufferSize, "%s = USE_ABV", pcPrefix);
        break;
    case 3:
        NiSprintf(pString, uiBufferSize, "%s = NOTEST", pcPrefix);
        break;
    case 4:
        NiSprintf(pString, uiBufferSize, "%s = USE_NIBOUND", pcPrefix);
        break;
    default:
        NiSprintf(pString, uiBufferSize, "%s = UNKNOWN!!!", pcPrefix);
        break;
    }
    return pString;
}

extern "C" void* _NiPoint3_ZERO;
extern unsigned char DAT_011f4270;
extern unsigned char DAT_011f4274;

struct NiPoint3
{
    float x, y, z;
};

struct NiCollisionData
{
    NiPoint3 FUN_00eacd30();
};

// @fnv 0x00eacd30
NiPoint3 NiCollisionData::FUN_00eacd30()
{
    NiPoint3 p;
    *(unsigned int*)&p.x = *(unsigned int*)&_NiPoint3_ZERO;
    *(unsigned int*)&p.y = *(unsigned int*)&DAT_011f4270;
    *(unsigned int*)&p.z = *(unsigned int*)&DAT_011f4274;
    return p;
}

namespace fnv_00eace50 {
struct NiBoundingVolume
{
    virtual void v0();
    virtual void v1();
    virtual void v2(int);
    virtual void v3();
    virtual void v4();
    virtual void v5(NiBoundingVolume*, void*);
    virtual NiBoundingVolume* v6();
};
struct NiCollisionData
{
    char _00[8];
    char* _08;
    char _0c[32];
    NiBoundingVolume* _2c;
    NiBoundingVolume* _30;
    void SetBoundingVolume(NiBoundingVolume* pkBV);
};
// @fnv 0x00eace50
void NiCollisionData::SetBoundingVolume(NiBoundingVolume* pkBV)
{
    if (_2c)
        _2c->v2(1);
    if (_30)
        _30->v2(1);
    _2c = pkBV;
    if (pkBV)
    {
        _30 = pkBV->v6();
        if (_08)
            _30->v5(_2c, _08 + 0x68);
    }
    else
    {
        _30 = 0;
    }
}
}  // namespace fnv_00eace50

extern void* __cdecl FUN_00e9cab0(void*);
struct FUN_00eace50_shell
{
    void __thiscall SetBoundingVolume(void*);
};
struct FUN_00eaceb0_shell
{
    void* vft;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void __thiscall AssignFromSource(void*);
};
// @fnv 0x00eaceb0
void __thiscall FUN_00eaceb0_shell::AssignFromSource(void* pSource)
{
    ((void(__thiscall*)(void*, void*))(*(void***)this)[35])(this, *(void**)pSource);
    m_24 = *(void**)((char*)pSource + 4);
    if (*(int*)((char*)pSource + 8))
    {
        void* bv = FUN_00e9cab0(*(void**)((char*)pSource + 12));
        ((FUN_00eace50_shell*)this)->SetBoundingVolume(bv);
    }
}

namespace fnv_00ead0b0 {
struct NiCollisionData
{
    void FUN_00eacde0();
    void* DestroyIfFlagged(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Calls FUN_00eacde0, then deletes this with size 0x50 when bit 0 of uFlags is set, and returns this.
// @fnv 0x00ead0b0
void* NiCollisionData::DestroyIfFlagged(unsigned int auiFlags)
{
    FUN_00eacde0();
    if (auiFlags & 1)
        _delete(this, 0x50);
    return this;
}
}  // namespace fnv_00ead0b0

namespace fnv_00ead610 {
struct CloningProcess
{
    int _00;
};
struct NiBoundingVolume
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual NiBoundingVolume* Clone();
};
struct NiCollisionData
{
    char _00[0x24];
    int m_ePropagationMode;
    int m_eCollisionMode;
    NiBoundingVolume* m_pkModelABV;
    char _30[4];
    void* m_pCollisionObject;
    char _38[8];
    void* m_pWorldVertices;
    void FUN_00aa1000(NiCollisionData*, CloningProcess&);
    void SetBoundingVolume(NiBoundingVolume*);
    void FUN_00ead1e0();
    void FUN_00ead250();
    void CreateTriData(int);
    void CloneCollisionData(NiCollisionData*, CloningProcess&);
};
// @fnv 0x00ead610
void NiCollisionData::CloneCollisionData(NiCollisionData* pkDest, CloningProcess& kCloning)
{
    FUN_00aa1000(pkDest, kCloning);
    pkDest->m_ePropagationMode = m_ePropagationMode;
    pkDest->m_eCollisionMode = m_eCollisionMode;
    if (m_pkModelABV)
        pkDest->SetBoundingVolume(m_pkModelABV->Clone());
    if (m_pCollisionObject)
    {
        if (!pkDest->m_pWorldVertices)
        {
            pkDest->FUN_00ead1e0();
            pkDest->FUN_00ead250();
        }
        pkDest->CreateTriData(1);
    }
}
}  // namespace fnv_00ead610

namespace fnv_00ead330 {
struct Helper38
{
    char _pad[0x38];
    unsigned char m_uiObjectFlags;
};
struct NiAVObject
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual int f6();
    char _pad[0xb8 - 4];
    Helper38* m_pkHelper;
};
struct NiCollisionObject
{
    void SetSceneObject(NiAVObject* pkObj);
    char _pad0[8];
    NiAVObject* m_pkSceneObj;
    char _pad1[0x28 - 12];
};
struct NiCollisionData : NiCollisionObject
{
    int m_eCollisionMode;
    void SetSceneGraphObject(NiAVObject* pkSceneObject);
};
// @fnv 0x00ead330
void NiCollisionData::SetSceneGraphObject(NiAVObject* pkSceneObject)
{
    SetSceneObject(pkSceneObject);
    int iMode = m_eCollisionMode;
    NiAVObject* pkObj = m_pkSceneObj;
    if (!pkObj)
        return;
    if (!pkObj->f6())
        return;
    Helper38* pkHelper = pkObj->m_pkHelper;
    if (!pkHelper)
        return;
    if (iMode == 0 || iMode == 1)
        pkHelper->m_uiObjectFlags |= 0x33;
}
}  // namespace fnv_00ead330

namespace fnv_00ead760 {
struct NiStream
{
    unsigned char _pad[0xD8];
    unsigned int m_uiNifVersion;
};
struct TargetObj
{
    unsigned char _pad[0x38];
    unsigned char m_ucFlag;
};
struct SceneObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual int Pred();
    unsigned char _pad2[0xB4];
    TargetObj* m_pFlagTarget;
};
struct NiCollisionObject
{
    virtual void LinkObject(NiStream&);
    int _m04;
    SceneObj* m_pkScene;
};
struct NiCollisionData : NiCollisionObject
{
    unsigned char _padC[0x1C];
    int m_eCollisionMode;
    void FUN_00ead760(NiStream&);
};
// @fnv 0x00ead760
void NiCollisionData::FUN_00ead760(NiStream& kStream)
{
    NiCollisionObject::LinkObject(kStream);
    if (kStream.m_uiNifVersion < 0x0A000110)
    {
        int iMode = m_eCollisionMode;
        SceneObj* pkScene = m_pkScene;
        if (pkScene)
        {
            if (pkScene->Pred())
            {
                TargetObj* pkTarget = pkScene->m_pFlagTarget;
                if (pkTarget)
                {
                    if (iMode == 0 || iMode == 1)
                        pkTarget->m_ucFlag |= 0x33;
                }
            }
        }
    }
}
}  // namespace fnv_00ead760

namespace fnv_00ead870 {
struct StrArr
{
    unsigned char _pad[8];
    unsigned short m_usMax;
    unsigned short m_usSize;
    unsigned short _pad2;
    unsigned short m_usGrow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    unsigned short GetSize() const
    {
        return m_usSize;
    }
    unsigned short GetAllocatedSize() const
    {
        return m_usMax;
    }
    unsigned short GetGrowSize() const
    {
        return m_usGrow;
    }
};
char* __cdecl _FUN_00a7d330(const char*);
struct NiCollisionData
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
    virtual void VirtAt64(StrArr*);
    void FUN_00a81100(StrArr*);
    void FUN_00ead870(StrArr*);
};
// @fnv 0x00ead870
void NiCollisionData::FUN_00ead870(StrArr* pkStrings)
{
    FUN_00a81100(pkStrings);
    char* pszDup = _FUN_00a7d330((const char*)g_0126fab4);
    unsigned int uiSize = pkStrings->GetSize();
    unsigned int uiMax = pkStrings->GetAllocatedSize();
    if (uiSize >= uiMax)
        pkStrings->SetSize(uiSize + pkStrings->GetGrowSize());
    pkStrings->SetAt(uiSize, pszDup);
    VirtAt64(pkStrings);
}
}  // namespace fnv_00ead870

// FUN_00eacd00 - forwards its single argument to the collection's stream
// writer and reports the writer's byte sized result as a bool.
//
// Original body (18 bytes):
//   mov eax, dword ptr [esp + 4]
//   push eax
//   call  <stream writer>
//   test al, al
//   setne al
//   ret 4
//
// The writer is the collection's "write to stream" helper; it is declared
// here with a byte sized result because the original only looks at AL.

extern "C" unsigned char __stdcall MyColl_WriteToStream(void* pStream);

// @fnv 0x00eacd00
bool __stdcall FUN_00eacd00(void* pStream)
{
    return MyColl_WriteToStream(pStream);
}

extern unsigned char DAT_010f18bc;
extern unsigned int DAT_011f426c;

struct FUN_00eacd60
{
    void* m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;
    unsigned char m_48;
    unsigned char m_49;
    unsigned short unk4a;
    unsigned short m_4c;
    unsigned char m_4e;

    void Init(unsigned int);
    FUN_00eacd60();
};

// Constructor: calls Init(0), zeroes several fields, stores pointers to DAT_010f18bc and values from DAT_011f426c/4270/4274, and sets m_24=2, m_28=3.
// @fnv 0x00eacd60
FUN_00eacd60::FUN_00eacd60()
{
    Init(0);
    m_40 = 0;
    m_44 = 0;
    m_48 = 0;
    m_49 = 0;
    m_00 = (void*)&DAT_010f18bc;
    m_0c = DAT_011f426c;
    m_10 = *(unsigned int*)&DAT_011f4270;
    m_14 = *(unsigned int*)&DAT_011f4274;
    m_18 = DAT_011f426c;
    m_1c = *(unsigned int*)&DAT_011f4270;
    m_20 = *(unsigned int*)&DAT_011f4274;
    m_4c = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
    m_38 = 0;
    m_3c = 0;
    m_4e = 0;
    m_24 = 2;
    m_28 = 3;
}

extern unsigned char DAT_010f18bc;
extern unsigned char DAT_011f6238;

struct FUN_00aa4060_shell
{
    void __thiscall FUN_00aa4060(unsigned int);
};

struct FUN_00a80fc0_shell
{
    void __thiscall FUN_00a80fc0();
};

struct SpawnedObj
{
    virtual void v00(int);
    virtual void v04(int);
    virtual void v08(int);
};

struct FUN_00eacde0_cls
{
    void* m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    SpawnedObj* m_2c;
    SpawnedObj* m_30;
    SpawnedObj* m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;

    void FUN_00eacde0();
};

// @fnv 0x00eacde0
void FUN_00eacde0_cls::FUN_00eacde0()
{
    unsigned int a = m_40;
    m_00 = &DAT_010f18bc;
    ((FUN_00aa4060_shell*)&DAT_011f6238)->FUN_00aa4060(a);
    ((FUN_00aa4060_shell*)&DAT_011f6238)->FUN_00aa4060(m_44);
    if (m_2c != 0)
    {
        m_2c->v08(1);
    }
    if (m_30 != 0)
    {
        m_30->v08(1);
    }
    if (m_34 != 0)
    {
        m_34->v00(1);
    }
    m_34 = 0;
    ((FUN_00a80fc0_shell*)this)->FUN_00a80fc0();
}

extern void(__cdecl* g_011aa050)(unsigned short, unsigned int, void*, void*);

struct S_00ead250_Second
{
    virtual void m00()
    {}
    virtual void m04()
    {}
    virtual void m08()
    {}
    virtual void m0c()
    {}
    virtual void m10()
    {}
    virtual void m14()
    {}
    virtual void m18()
    {}
    virtual void m1c()
    {}
    virtual void m20()
    {}
    virtual void m24()
    {}
    virtual void m28()
    {}
    virtual void m2c()
    {}
    virtual void m30()
    {}
    virtual void m34()
    {}
    virtual void m38()
    {}
    virtual void m3c()
    {}
    virtual void m40()
    {}
    virtual void m44()
    {}
    virtual void m48()
    {}
    virtual void m4c()
    {}
    virtual void m50()
    {}
    virtual void m54()
    {}
    virtual void m58()
    {}
    virtual void m5c()
    {}
    virtual void m60()
    {}
    virtual void m64()
    {}
    virtual void m68()
    {}
    virtual void m6c()
    {}
    virtual void m70()
    {}
    virtual void m74()
    {}
    virtual void m78()
    {}
    virtual void m7c()
    {}
    virtual void m80()
    {}
    virtual void m84()
    {}
    virtual void m88()
    {}
    virtual void m8c()
    {}
    virtual unsigned short m90()
    {
        return 0;
    }

    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    unsigned int unk20;
};

struct S_00ead250_First
{
    virtual void m00()
    {}
    virtual void m04()
    {}
    virtual void m08()
    {}
    virtual void m0c()
    {}
    virtual void m10()
    {}
    virtual void m14()
    {}
    virtual S_00ead250_First* m18()
    {
        return 0;
    }

    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6c;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7c;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8c;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9c;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    S_00ead250_Second* unkB8;
};

struct S_00ead250
{
    void* unk00;
    void* unk04;
    S_00ead250_First* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    unsigned char unk48;

    void FUN_00ead250();
};

// If unk08's m18() result is non-null and unk40 and unk48 are set, calls g_011aa050 with the second object's unk20 and m90() and clears unk48.
// @fnv 0x00ead250
void S_00ead250::FUN_00ead250()
{
    S_00ead250_First* first = unk08;

    if (first != 0)
    {
        S_00ead250_First* object = first->m18();

        if (object != 0 && unk40 != 0 && unk48 != 0)
        {
            S_00ead250_Second* second = object->unkB8;
            unsigned int value20 = second->unk20;
            unsigned short value90 = second->m90();

            g_011aa050(value90, value20, unk40, (void*)((char*)object + 0x68));

            unk48 = 0;
        }
    }
}

struct FUN_00ead2b0_node
{
    void* vft;
    FUN_00ead2b0_node* m_04;
};

struct FUN_00ead2b0_cls
{
    virtual void unk00();
    virtual void unk04();
    virtual FUN_00ead2b0_node* unk08();
    virtual int unk0c();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    FUN_00ead2b0_cls* m_2c;
    bool __thiscall Probe(void* p);
    bool __thiscall MatchesOther(FUN_00ead2b0_cls* other);
};

// Checks Probe(other), a node list for g_0126fab4, equal m_28/m_24, and equal m_2c unk0c values; returns true on match, false otherwise.
// @fnv 0x00ead2b0
bool FUN_00ead2b0_cls::MatchesOther(FUN_00ead2b0_cls* other)
{
    FUN_00ead2b0_node* node;
    FUN_00ead2b0_cls* a;
    FUN_00ead2b0_cls* b;
    if (!Probe(other))
    {
        goto fail;
    }
    if (other == 0)
    {
        goto fail;
    }
    node = other->unk08();
    if (node == 0)
    {
        goto fail;
    }
    do
    {
        if (node == (FUN_00ead2b0_node*)&g_0126fab4)
        {
            goto found;
        }
        node = node->m_04;
    } while (node != 0);
    goto fail;
found:
    if (other->m_28 != m_28)
    {
        goto fail;
    }
    if (other->m_24 != m_24)
    {
        goto fail;
    }
    a = other->m_2c;
    if (a == 0)
    {
        goto tail;
    }
    b = m_2c;
    if (b != 0)
    {
        int ra = a->unk0c();
        int rb = b->unk0c();
        if (ra == rb)
        {
            goto ok;
        }
        goto fail;
    }
tail:
    if (a != m_2c)
    {
        goto fail;
    }
ok:
    return true;
fail:
    return false;
}

struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};

extern NiRTTI g_NiTriShapeRTTI;
extern NiRTTI g_NiTriStripsRTTI;

struct MemoryManager
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
extern MemoryManager _g_memoryManager;

void* __cdecl NiMalloc(unsigned int size);

inline void NiFreeHelper(void* p)
{
    _g_memoryManager.Deallocate(p);
}

struct NiObjectStub
{
    virtual void v00();
    virtual void v04();
    virtual const NiRTTI* GetRTTI() const;
    bool IsKindOfType(const NiRTTI* pkRTTI) const
    {
        const NiRTTI* pkTmp = GetRTTI();
        while (pkTmp)
        {
            if (pkTmp == pkRTTI)
                return true;
            pkTmp = pkTmp->m_pBaseRTTI;
        }
        return false;
    }
};

struct GeomData
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
    virtual void GetTriangleVertexIndices(unsigned int i, unsigned short& i0, unsigned short& i1,
                                          unsigned short& i2) const;

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    void* m_pkVertex;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    unsigned short m_usTriangles;

    unsigned short* GetTriListImpl();
    unsigned short* GetTriangleList()
    {
        return GetTriListImpl();
    }
    void* GetVertices() const
    {
        return m_pkVertex;
    }
    unsigned short GetTriangleCount() const
    {
        return m_usTriangles;
    }
};

struct GeomObj : NiObjectStub
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    GeomData* m_spGeometryData;
    GeomData* GetModelData() const
    {
        return m_spGeometryData;
    }
    void* GetVertices() const
    {
        return m_spGeometryData->GetVertices();
    }
};

struct TriData
{
    TriData(unsigned short usTriangles, unsigned short* pusTriList, void* pkVertex, void* pkWorldVertex, int iParam);
    static void* operator new(unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
    static void operator delete(void* p, const char* pcFile);
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
};

inline bool IsKindOfHelper(const NiRTTI& rtti, NiObjectStub* obj)
{
    if (obj)
    {
        for (const NiRTTI* r = obj->GetRTTI(); r; r = r->m_pBaseRTTI)
        {
            if (r == &rtti)
                return true;
        }
    }
    return false;
}

struct CollisionData
{
    int unk00;
    int unk04;
    GeomObj* m_pkSceneObject;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    TriData* m_pkTriData;
    int unk38;
    int unk3C;
    void* m_pWorldVertices;

    void CreateWorldVertexData();
    void CreateWorldNormals();
    void CreateTriData(int iParam);
};

// Builds m_pkTriData from the scene object's triangle or triangle-strip geometry, creating world normals first if needed.
// @fnv 0x00ead380
void CollisionData::CreateTriData(int iParam)
{
    if (m_pkSceneObject && m_pkSceneObject->IsKindOfType(&g_NiTriShapeRTTI))
    {
        if (m_pkTriData)
            return;
        if (!m_pWorldVertices)
        {
            CreateWorldVertexData();
            CreateWorldNormals();
        }
        GeomObj* pkShape = m_pkSceneObject;
        m_pkTriData =
            new TriData(pkShape->m_spGeometryData->GetTriangleCount(), pkShape->m_spGeometryData->GetTriangleList(),
                        pkShape->m_spGeometryData->GetVertices(), m_pWorldVertices, iParam);
    }
    else if (m_pkSceneObject && m_pkSceneObject->IsKindOfType(&g_NiTriStripsRTTI))
    {
        if (m_pkTriData)
            return;
        if (!m_pWorldVertices)
        {
            CreateWorldVertexData();
            CreateWorldNormals();
        }
        GeomObj* pkStrips = m_pkSceneObject;
        unsigned int uiTriangleCount = 0;
        unsigned int uiTriangles = pkStrips->m_spGeometryData->m_usTriangles;
        unsigned short* pusTriList = (unsigned short*)NiMalloc(uiTriangles * 3 * sizeof(unsigned short));
        unsigned short* p = pusTriList;
        for (unsigned int i = 0; i < uiTriangles; i++)
        {
            pkStrips->m_spGeometryData->GetTriangleVertexIndices(i, p[0], p[1], p[2]);
            if (p[0] != p[1] && p[0] != p[2] && p[1] != p[2])
            {
                p += 3;
                uiTriangleCount++;
            }
        }
        m_pkTriData = new TriData(uiTriangleCount, pusTriList, pkStrips->m_spGeometryData->GetVertices(),
                                  m_pWorldVertices, iParam);
        NiFreeHelper(pusTriList);
    }
}

// Stand-in model for the NiCollisionData-like object that owns UpdateCollideState.
//
// Layout of the "other collision object" (the one this->m_08 points at):
//   +0x00  vptr
//   +0xb8  pointer to a small flags object
// The virtual used by the original lives at vtable offset 0x18 (slot 6) and
// returns a value that is tested.
struct FNV_CollideFlags
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
    unsigned char m_38;
};

struct FNV_Collide
{
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
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAc;
    int unkB0;
    int unkB4;
    FNV_CollideFlags* m_b8;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
};

struct FNV_Owner
{
    int unk00;
    int unk04;
    FNV_Collide* m_08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_24;
    int m_28;
    int m_2c;

    void UpdateCollideState(unsigned int arg, unsigned int arg2);

    // "then" arm of the m_2c test: the partner object's slot-6 virtual is
    // invoked and its result is ignored.
    __forceinline void DoThen()
    {
        FNV_Collide* obj = m_08;
        if (obj)
            obj->v6();
    }

    // "else" arm: the partner's slot-6 virtual result gates a flag update.
    __forceinline void DoElse()
    {
        FNV_Collide* obj = m_08;
        m_28 = 0;
        if (obj)
        {
            if (obj->v6())
            {
                FNV_CollideFlags* flags = obj->m_b8;
                if (flags)
                    flags->m_38 |= 0x33;
            }
        }
    }
};

// @fnv 0x00ead550
void FNV_Owner::UpdateCollideState(unsigned int arg, unsigned int arg2)
{
    (void)arg2;
    if (arg >= 0x0a000106u)
        return;
    switch (m_24)
    {
    case 0:
        m_24 = 3;
        if (m_2c != 0)
        {
            m_28 = 2;
            DoThen();
        }
        else
        {
            DoElse();
        }
        break;
    case 1:
        m_24 = 3;
        break;
    case 2:
        m_24 = 0;
        if (m_2c != 0)
        {
            m_28 = 2;
            DoThen();
        }
        else
        {
            DoElse();
        }
        break;
    case 3:
        m_24 = 2;
        if (m_2c != 0)
        {
            m_28 = 2;
            DoThen();
        }
        else
        {
            DoElse();
        }
        break;
    case 4:
        m_24 = 2;
        break;
    }
}

struct NiBinaryStreamStandIn
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void SetEndianSwap(bool bSwap);

    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStreamStandIn* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
    template <class T> T ReadV()
    {
        T v;
        unsigned int uiSize = sizeof(T);
        unsigned int n = m_pfnRead(this, &v, sizeof(T), &uiSize, 1);
        T r = v;
        m_uiStreamFlags += n;
        return r;
    }
    template <class T> unsigned int Read(T* pValue)
    {
        unsigned int uiSize = sizeof(T);
        return BinaryRead(pValue, sizeof(T), &uiSize, 1);
    }
};

struct NiStreamImpl
{
    char pad[0xd8];
    unsigned int m_uiNifVersion;
    char pad2[0x24c - 0xdc];
    NiBinaryStreamStandIn* m_pUnderlyingStream;
    unsigned int GetFileVersion() const
    {
        return m_uiNifVersion;
    }
};

template <class T> inline void ReadBinaryValue(NiStreamImpl& stream, T& value)
{
    stream.m_pUnderlyingStream->Read(&value);
}

template <class T> inline T LoadValue(NiStreamImpl& stream)
{
    return stream.m_pUnderlyingStream->ReadV<T>();
}

struct Obj_ead
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual int v06();
};

Obj_ead* __cdecl FUN_00e9cab0(NiStreamImpl& stream);

struct FUN_00ead670_cls
{
    char pad[0x24];
    int m_i24;
    int m_i28;
    Obj_ead* m_pkObj;
    int m_i30;

    void FUN_00a80fd0(NiStreamImpl& stream);
    void LoadFromStream(NiStreamImpl& stream);
};

// Reads two ints (or one for older file versions), a bool, and if set loads an object and stores its v06() result.
// @fnv 0x00ead670
void FUN_00ead670_cls::LoadFromStream(NiStreamImpl& stream)
{
    FUN_00a80fd0(stream);
    if (stream.GetFileVersion() >= 0x0A000106)
    {
        m_i24 = LoadValue<int>(stream);
        m_i28 = LoadValue<int>(stream);
    }
    else
    {
        m_i24 = LoadValue<int>(stream);
    }
    bool bHasObject;
    ReadBinaryValue(stream, bHasObject);
    if (bHasObject)
    {
        m_pkObj = FUN_00e9cab0(stream);
        m_i30 = m_pkObj->v06();
    }
}

class EAD7B0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(EAD7B0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(EAD7B0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class EAD7B0Object;

class EAD7B0Stream
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void SaveLinkID(EAD7B0Object* pkObject);
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    EAD7B0BinaryStream* m_pBackingStream;
};

template <class T>
inline void EAD7B0BinaryStreamSave(EAD7B0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void EAD7B0SaveBinary(EAD7B0Stream& kStream, const T& value)
{
    EAD7B0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class EAD7B0Saveable
{
  public:
    virtual void vfn00();
    virtual void SaveBinary(EAD7B0Stream& kStream);
};

class EAD7B0Base
{
  public:
    void SaveBinaryBase(EAD7B0Stream& kStream);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

class EAD7B0Object : public EAD7B0Base
{
  public:
    void FUN_00ead7b0(EAD7B0Stream& kStream);

    int m_iValue0;
    int m_iValue1;
    EAD7B0Saveable* m_pkChild;
};

// Saves the base fields, m_iValue0 and m_iValue1, then a presence flag and the child's SaveBinary if m_pkChild is set.
// @fnv 0x00ead7b0
void EAD7B0Object::FUN_00ead7b0(EAD7B0Stream& kStream)
{
    SaveBinaryBase(kStream);
    EAD7B0SaveBinary(kStream, m_iValue0);
    EAD7B0SaveBinary(kStream, m_iValue1);
    if (m_pkChild)
    {
        EAD7B0SaveBinary(kStream, true);
        m_pkChild->SaveBinary(kStream);
    }
    else
    {
        EAD7B0SaveBinary(kStream, false);
    }
}

void* __cdecl FUN_00aa13e0(unsigned int);

struct FUN_00eacd60_shell
{
    void* __thiscall FUN_00eacd60();
};

struct FUN_00eada20_cls
{
    void __thiscall CloneCollisionData(void* a, void* b);
    void* __thiscall CreateClone(void* arg);
};

// @fnv 0x00eada20
void* __thiscall FUN_00eada20_cls::CreateClone(void* arg)
{
    void* result;
    void* mem = FUN_00aa13e0(0x50);
    if (mem != 0)
    {
        result = ((FUN_00eacd60_shell*)mem)->FUN_00eacd60();
    }
    else
    {
        result = 0;
    }
    CloneCollisionData(result, arg);
    return result;
}

extern unsigned char DAT_0126fab0;

struct NiPoint3b
{
    float x, y, z;
};

struct M_004b4500
{
    NiPoint3b FUN_004b4500(const NiPoint3* pkPoint);
};

struct NiTransform : M_004b4500
{
};

struct NiCollUpdateTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14(void* pkObject, NiTransform& kWorld);
};

struct NiCollDataStandIn;

struct NiAVObjectStandIn
{
    void* m_pkVtable;
    int m_iRefCount;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    NiAVObjectStandIn* m_pParentNode;
    NiCollDataStandIn* m_pkCollisionObject;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5C;
    int m_i60;
    int m_i64;
    NiTransform m_kWorldSpaceTransform;
};

struct NiCollDataStandIn
{
    void* m_pkVtable;
    int m_iRefCount;
    NiAVObjectStandIn* m_pkSceneObject;
    NiPoint3b m_kLocalVelocity;
    NiPoint3b m_kWorldVelocity;
    int m_ePropagate;
    int m_eCollisionMode;
    void* m_pkCollisionObject;
    NiCollUpdateTarget* m_pkTarget;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    unsigned char m_b48;
    unsigned char m_b49;
    int m_i4C;

    __declspec(noinline) NiAVObjectStandIn* FUN_00ead0d0(NiAVObjectStandIn* pkNode);
    void UpdateCollision(NiAVObjectStandIn* pkObject);
};

__forceinline NiPoint3b operator+(const NiPoint3b& kA, const NiPoint3b& kB)
{
    NiPoint3b kResult;
    kResult.x = kA.x + kB.x;
    kResult.y = kA.y + kB.y;
    kResult.z = kA.z + kB.z;
    return kResult;
}

NiAVObjectStandIn* NiCollDataStandIn::FUN_00ead0d0(NiAVObjectStandIn* pkNode)
{
    if (pkNode == 0)
        return 0;
    do
    {
        pkNode = pkNode->m_pParentNode;
        if (pkNode == 0)
            return 0;
    } while (pkNode->m_pkCollisionObject == 0);
    return pkNode;
}

// @fnv 0x00ead0f0
void NiCollDataStandIn::UpdateCollision(NiAVObjectStandIn* pkObject)
{
    if (m_pkCollisionObject)
    {
        m_pkTarget->v14(m_pkCollisionObject, m_pkSceneObject->m_kWorldSpaceTransform);
    }
    if (DAT_0126fab0)
    {
        NiAVObjectStandIn* pkParent = m_pkSceneObject->m_pParentNode;
        if (pkParent)
        {
            NiCollDataStandIn* pkData = 0;
            if (m_pkSceneObject)
            {
                NiAVObjectStandIn* pkNode = m_pkSceneObject->m_pParentNode;
                if (pkNode)
                {
                    if (pkNode->m_pkCollisionObject == 0)
                        pkNode = FUN_00ead0d0(pkNode);
                    if (pkNode)
                        pkData = pkNode->m_pkCollisionObject;
                }
            }
            if (pkData)
            {
                m_kWorldVelocity =
                    pkData->m_kWorldVelocity + pkParent->m_kWorldSpaceTransform.FUN_004b4500((const NiPoint3*)&m_kLocalVelocity);
            }
            else
            {
                m_kWorldVelocity = pkParent->m_kWorldSpaceTransform.FUN_004b4500((const NiPoint3*)&m_kLocalVelocity);
            }
        }
        else
        {
            m_kWorldVelocity = m_kLocalVelocity;
        }
    }
    m_b49 = m_b48 = true;
}

struct StrArr
{
    void* m_pVtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& pcElement);
    unsigned int Add(char* pcElement)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
};
struct NiPoint3Viewer
{
    float x, y, z;
    char* FUN_00a59af0(const char* pcPrefix);
};
char* FUN_00a7d330(char* pcText);
struct NiCollisionModel
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void GetViewerStrings(const char* pcPrefix, StrArr* pkStrings);
};
struct FUN_00a81160_base
{
    void WriteToStream(StrArr* pkStrings);
};
struct FUN_00ead8d0_shell : FUN_00a81160_base
{
    int unk00;
    int unk04;
    int unk08;
    NiPoint3Viewer m_kLocalVelocity;
    NiPoint3Viewer m_kWorldVelocity;
    unsigned int m_ePropagationMode;
    unsigned int m_eCollisionMode;
    NiCollisionModel* m_pkModelABV;
    char* FormatName(const char* pcPrefix, unsigned int eMode);
    char* FUN_00eacef0(const char* pcPrefix, unsigned int eMode);
    void AddViewerStrings(StrArr* pkStrings);
};

// Appends viewer strings for propagation/collision modes, the ABV model and local/world velocities to pkStrings.
// @fnv 0x00ead8d0
void FUN_00ead8d0_shell::AddViewerStrings(StrArr* pkStrings)
{
    WriteToStream(pkStrings);
    pkStrings->Add(FUN_00a7d330((char*)g_0126fab4));
    unsigned int propagationMode = m_ePropagationMode;
    pkStrings->Add(FormatName("m_ePropagationMode", propagationMode));
    unsigned int collisionMode = m_eCollisionMode;
    pkStrings->Add(FUN_00eacef0("m_eCollisionMode", collisionMode));
    if (m_pkModelABV)
        m_pkModelABV->GetViewerStrings("m_pkModelABV->Type", pkStrings);
    pkStrings->Add(m_kLocalVelocity.FUN_00a59af0("m_kLocalVelocity"));
    pkStrings->Add(m_kWorldVelocity.FUN_00a59af0("m_kWorldVelocity"));
}

extern const char str_010f19fc[];
extern const char str_010f19e0[];
extern const char str_010f19c8[];
extern const char str_010f19b0[];
extern const char str_0109b2ec[];

extern "C" unsigned int __cdecl strlen(const char*);
void* __cdecl FUN_00aa1070(unsigned int size);
void FUN_00a305b0(char* buf, unsigned int size, const char* fmt, const char* name);

// Obtains a buffer sized from name length and formats name into it using the mode-selected format string.
// @fnv 0x00eacfd0
char* __stdcall FormatName(const char* name, int mode)
{
    unsigned int len = strlen(name);
    char* buf = (char*)FUN_00aa1070(len + 0x20);
    switch (mode)
    {
    case 0:
        FUN_00a305b0(buf, len + 0x20, str_010f19fc, name);
        break;
    case 1:
        FUN_00a305b0(buf, len + 0x20, str_010f19e0, name);
        break;
    case 2:
        FUN_00a305b0(buf, len + 0x20, str_010f19c8, name);
        break;
    case 3:
        FUN_00a305b0(buf, len + 0x20, str_010f19b0, name);
        break;
    default:
        FUN_00a305b0(buf, len + 0x20, str_0109b2ec, name);
        break;
    }
    return buf;
}

struct Allocator
{
    void* __thiscall FUN_00aa3e40(unsigned int bytes);
};
void* __cdecl operator new[](unsigned int n)
{
    return reinterpret_cast<Allocator&>(DAT_011f6238).FUN_00aa3e40(n);
}
struct Point
{
    float x, y, z;
};
struct GeometryData
{
    void* m_00;
    void* m_04;
    unsigned short vertexCount;
    unsigned short m_0a;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    unsigned short geomFlags;
};
struct Geometry
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    void* m_40;
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    void* m_60;
    void* m_64;
    void* m_68;
    void* m_6c;
    void* m_70;
    void* m_74;
    void* m_78;
    void* m_7c;
    void* m_80;
    void* m_84;
    void* m_88;
    void* m_8c;
    void* m_90;
    void* m_94;
    void* m_98;
    void* m_9c;
    void* m_a0;
    void* m_a4;
    void* m_a8;
    void* m_ac;
    void* m_b0;
    void* m_b4;
    GeometryData* geometryData;
};
struct Node
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual Geometry* GetGeometry();
};
struct Target
{
    void* m_00;
    void* m_04;
    Node* node;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    Point* points;
    unsigned int m_44;
    unsigned char hasPoints;
    unsigned char m_49;
    unsigned short pointCount;
    unsigned short geomFlags;
    void FUN_00ead1e0();
};
// @fnv 0x00ead1e0
void Target::FUN_00ead1e0()
{
    if (node)
    {
        Geometry* geometry = node->GetGeometry();
        if (geometry && !points)
        {
            unsigned short count = geometry->geometryData->vertexCount;
            if (count != 0)
            {
                pointCount = count;
                points = new Point[count];
                hasPoints = 1;
                geomFlags = geometry->geometryData->geomFlags;
            }
        }
    }
}
