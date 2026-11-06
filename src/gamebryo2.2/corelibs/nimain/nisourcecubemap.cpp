
// src/gamebryo2.2/corelibs/nimain/nisourcecubemap.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nisourcecubemap.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

class NiStream;

extern "C"
{
    char __stdcall AttachToListener(NiStream* kStream);
}

// @fnv 0x00a60850
bool __stdcall RegisterStreamables(NiStream& kStream)
{
    return AttachToListener(&kStream);
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f4454;

// @fnv 0x00a60cb0
GlobalObjectO2_00a7b610* __cdecl FUN_00a60cb0()
{
    return &g_011f4454;
}

struct NiSourceTexture
{
    NiSourceTexture();
};

struct NiSourceCubeMap : NiSourceTexture
{
    NiSourceCubeMap();
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

// @fnv 0x00a60f30
NiSourceCubeMap* __cdecl CreateNiSourceCubeMap()
{
    void* p = BSFadeNode::operator new(0x4c);
    if (p)
    {
        NiSourceCubeMap* n = static_cast<NiSourceCubeMap*>(p);
        n->NiSourceTexture::NiSourceTexture();
        *(unsigned int*)(n) = 0x0109babc;
        *(unsigned int*)((char*)n + 0x48) = 0;
        return n;
    }
    return 0;
}

struct NiObject;

struct NiSourceCubeMapShell : NiSourceCubeMap
{
    bool __thiscall FUN_00a5fae0(NiObject*);
    bool __thiscall IsEqual(NiObject* pkObject);
};

// Calls FUN_00a5fae0 on pkObject, then compares four fields of this and pkObject and returns true only if all match.
// @fnv 0x00a60880
bool __thiscall NiSourceCubeMapShell::IsEqual(NiObject* pkObject)
{
    if (FUN_00a5fae0(pkObject))
    {
        NiSourceCubeMap* pkTexture = reinterpret_cast<NiSourceCubeMap*>(pkObject);
        if (reinterpret_cast<const unsigned int*>(this)[6] == reinterpret_cast<const unsigned int*>(pkTexture)[6] &&
            reinterpret_cast<const unsigned int*>(this)[8] == reinterpret_cast<const unsigned int*>(pkTexture)[8] &&
            reinterpret_cast<const unsigned int*>(this)[7] == reinterpret_cast<const unsigned int*>(pkTexture)[7] &&
            reinterpret_cast<const unsigned char*>(this)[0x40] ==
                reinterpret_cast<const unsigned char*>(pkTexture)[0x40])
            return true;
    }
    return false;
}

struct NiRenderer
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual bool __thiscall CreateCube(void*) = 0;
    static NiRenderer* ms_pRenderer;
};
struct DelObj
{
    virtual ~DelObj();
};
struct Thunk60800
{
    bool __thiscall CreateCubeOrRelease();
};
// @fnv 0x00a60800
bool __thiscall Thunk60800::CreateCubeOrRelease()
{
    NiRenderer* pkRenderer = NiRenderer::ms_pRenderer;
    if (pkRenderer)
    {
        if (!pkRenderer->CreateCube(this))
        {
            DelObj* p1 = *(DelObj**)((char*)this + 0x44);
            if (p1)
            {
                delete p1;
                *(DelObj**)((char*)this + 0x44) = 0;
            }
            return false;
        }
    }
    DelObj* p2 = *(DelObj**)((char*)this + 0x44);
    if (p2)
    {
        delete p2;
        *(DelObj**)((char*)this + 0x44) = 0;
    }
    return true;
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct Base60770
{
    void GetFileStrings(StrArr*);
};
char* __cdecl _FUN_00a7d330(char*);
struct Host61480 : Base60770
{
    void AppendGlobalString(StrArr*);
};
// @fnv 0x00a61480
void Host61480::AppendGlobalString(StrArr* pkStrings)
{
    GetFileStrings(pkStrings);
    char* psz = _FUN_00a7d330(*(char**)&g_011f4454);
    unsigned int uiSize = *(unsigned short*)((char*)pkStrings + 0xa);
    unsigned int uiCap = *(unsigned short*)((char*)pkStrings + 8);
    if (uiSize >= uiCap)
    {
        unsigned int uiGrow = *(unsigned short*)((char*)pkStrings + 0xe);
        pkStrings->SetSize(uiSize + uiGrow);
    }
    pkStrings->SetAt(uiSize, psz);
}

namespace fnv_00a60ba0 {
extern "C" void* __cdecl memset(void*, int, unsigned int);
__declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p) throw();
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p) throw();

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis() throw();
    long m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

class NiObject : public NiRefObject
{
};

template <class T> class NiPointer
{
  public:
    NiPointer(T* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPointer() throw() : m_pObject(0)
    {}
    ~NiPointer() throw()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointer& operator=(T* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

class NiStream
{
  public:
    NiObject* GetLoadedObject() throw();
    unsigned int GetLinkID() throw();
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
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    unsigned int m_uiNifVersion;
};

class NiSourceTexture2 : public NiObject
{
  public:
    void LinkObject(NiStream& kStream) throw();
};

class NiSourceCubeMap2 : public NiSourceTexture2
{
  public:
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

    void FUN_00a60ba0(NiStream& kStream);
    void LinkObjectOld(NiStream& kStream) throw();
    void SetFaces(NiObject* p0, NiObject* p1, NiObject* p2, NiObject* p3, NiObject* p4, NiObject* p5) throw();
};

// @fnv 0x00a60ba0
void NiSourceCubeMap2::FUN_00a60ba0(NiStream& kStream)
{
    if (kStream.m_uiNifVersion < 0x0A030006)
    {
        NiSourceTexture2::LinkObject(kStream);
        NiObject* apkFaces[6];
        memset(apkFaces, 0, sizeof(apkFaces));
        if (kStream.GetLinkID() == 6)
        {
            for (unsigned int i = 0; i < 6; i++)
            {
                NiObject* pkObj = kStream.GetLoadedObject();
                if (apkFaces[i] != pkObj)
                {
                    if (apkFaces[i])
                        apkFaces[i]->DecRefCount();
                    apkFaces[i] = pkObj;
                    if (pkObj)
                        pkObj->IncRefCount();
                }
            }
        }
        if (unk3c == 0)
            SetFaces(apkFaces[0], apkFaces[1], apkFaces[2], apkFaces[3], apkFaces[4], apkFaces[5]);
        NiObject** ppkFace = apkFaces + 6;
        for (int j = 5; j >= 0; j--)
        {
            --ppkFace;
            if (*ppkFace)
                (*ppkFace)->DecRefCount();
        }
    }
    else
    {
        LinkObjectOld(kStream);
    }
}
}  // namespace fnv_00a60ba0

struct NiObject
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
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual bool v81(void* pkShell);
};

extern "C"
{
    void* __cdecl FUN_00aa13e0(unsigned int size);
    void __cdecl FUN_00a57500(char** pp);
    void __cdecl FUN_00a76960(char** pp, unsigned int* p);
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct SpawnedBase
{
    SpawnedBase();
    virtual ~SpawnedBase()
    {}
};

struct SpawnedCubeShell : SpawnedBase
{
    virtual ~SpawnedCubeShell()
    {}
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
    SpawnedCubeShell()
    {
        m_48 = 0;
    }
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    unsigned int m_18, m_1c, m_20;
    unsigned int unk24, unk28, unk2c;
    char* m_30;
    unsigned int m_34;
    unsigned int unk38, unk3c, unk40, unk44;
    unsigned int m_48;
};

extern "C" char* DAT_0109b220;
extern "C" unsigned char DAT_011a9594;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);

// @fnv 0x00a60f60
SpawnedCubeShell* __cdecl CreateSpawnedCubeShell(char** ppName, NiObject* pOwner, unsigned int* pVals)
{
    void* mem = FUN_00aa13e0(0x4c);
    SpawnedCubeShell* pShell = mem != 0 ? new (mem) SpawnedCubeShell() : 0;
    pShell->m_18 = pVals[0];
    pShell->m_1c = pVals[1];
    pShell->m_20 = pVals[2];
    char* s = *ppName;
    char** ppStoredName = &pShell->m_30;
    if (*ppStoredName != s)
    {
        if (s != DAT_0109b220)
        {
            InterlockedIncrement((long volatile*)(s - 8));
        }
        if (*ppStoredName != DAT_0109b220)
        {
            InterlockedDecrement((long volatile*)(*ppStoredName - 8));
        }
        *ppStoredName = s;
    }
    FUN_00a57500(ppStoredName);
    FUN_00a76960(ppStoredName, &pShell->m_34);
    if (pShell->m_48 != 0)
    {
        pShell->m_48 = 0;
    }
    if (DAT_011a9594 != 0)
    {
        pShell->v41();
        if (pOwner != 0 && !pOwner->v81(pShell))
        {
            delete pShell;
            return 0;
        }
    }
    return pShell;
}

namespace fnv_00a61040 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* value);
extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
extern "C" void __cdecl FUN_00a57500(char** ppName);
extern "C" void __cdecl FUN_00a76960(char** ppName, void* pExtra);

extern int DAT_0109b220;

struct FUN_00a5fc10_cls
{
    virtual void v00(int a);
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
    FUN_00a5fc10_cls() throw();
};

struct SpawnedObject : FUN_00a5fc10_cls
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
    int m_1c;
    int m_20;
    int unk24;
    int unk28;
    int unk2c;
    char* m_30;
    int m_34;
    int unk38;
    int unk3c;
    int unk40;
    int m_44;
    int m_48;

    static void* __cdecl operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }

    SpawnedObject() throw() : FUN_00a5fc10_cls()
    {
        m_48 = 0;
    }
};

// @fnv 0x00a61040
SpawnedObject* __cdecl FUN_00a61040(char** ppName, int aValue, NiRenderer* pRenderer, int* pVec)
{
    SpawnedObject* p = new SpawnedObject();
    p->m_18 = pVec[0];
    p->m_1c = pVec[1];
    p->m_20 = pVec[2];

    char* name = *ppName;
    char** ppNameSlot = &p->m_30;
    if (*ppNameSlot != name)
    {
        if ((int)name != DAT_0109b220)
        {
            InterlockedIncrement((long volatile*)(name - 8));
        }
        char* old = *ppNameSlot;
        if ((int)old != DAT_0109b220)
        {
            InterlockedDecrement((long volatile*)(old - 8));
        }
        *ppNameSlot = name;
    }

    FUN_00a57500(ppNameSlot);
    FUN_00a76960(ppNameSlot, &p->m_34);

    if (p->m_48 != 0)
    {
        p->m_48 = 0;
    }

    p->m_44 = aValue;
    p->v41();

    if (pRenderer != 0 && !pRenderer->CreateCube(p))
    {
        p->v00(1);
        return 0;
    }
    return p;
}
}  // namespace fnv_00a61040

struct TextureFormatPreferences
{
    int ePixelLayout;
    int eAlphaFmt;
    int eMipMapped;
};

struct NiCubeBase
{
    NiCubeBase() throw();
    static void* __cdecl operator new(unsigned int);
    virtual ~NiCubeBase();
};

struct NiCubeMap : NiCubeBase
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    TextureFormatPreferences m_kTextureFormatPreferences;
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

    NiCubeMap()
    {
        unk48 = 0;
    }
    virtual ~NiCubeMap();
    void Load(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, struct LoadBuffer* pkBuf);
};

struct LoadBuffer
{
    int unk00;
    void Init();
    void Shutdown();
    int unk04;
    char m_acPath[260];
    char m_acAltPath[260];
};

struct CubeRenderer
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
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual bool CreateCube(NiCubeMap* pkMap);
};

// @fnv 0x00a61120
NiCubeMap* __cdecl CreateCubeMap(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, CubeRenderer* pkRenderer,
                                 int iUnused, const TextureFormatPreferences* pkPrefs)
{
    NiCubeMap* pkMap = new NiCubeMap;
    pkMap->m_kTextureFormatPreferences = *pkPrefs;

    LoadBuffer kBuf;
    kBuf.Init();
    pkMap->Load(a1, a2, a3, a4, a5, a6, &kBuf);

    if (pkMap->unk48)
        pkMap->unk48 = 0;

    if (pkRenderer && (!pkMap->unk3C || !pkRenderer->CreateCube(pkMap)))
    {
        delete pkMap;
        kBuf.Shutdown();
        return 0;
    }

    kBuf.Shutdown();
    return pkMap;
}

class NiStream;

struct NiBinaryStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(NiBinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class NiStream
{
  public:
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
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    unsigned int m_uiNifVersion;
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
    NiBinaryStream* m_pUnderlyingStream;

    void ReadCString(char*& pcString);
    void ReadUnsignedInteger(unsigned int ItemUpdateArray);
    int ResetStreamState();
};

void NiFree(void* p);

template <class T> inline unsigned int NiBinaryStreamLoad(NiBinaryStream* pkStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return pkStream->BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}

template <class T> inline unsigned int ReadBinaryValue(NiStream& kStream, T& value)
{
    return NiBinaryStreamLoad(kStream.m_pUnderlyingStream, &value, 1);
}

inline void LoadBool(NiStream& kStream, bool& bValue)
{
    char cValue = bValue;
    ReadBinaryValue(kStream, cValue);
    bValue = (cValue != 0);
}

inline void LoadChar(NiStream& kStream, char& cValue)
{
    ReadBinaryValue(kStream, cValue);
}

inline void LoadEnum(NiStream& kStream, int& eValue)
{
    int iValue;
    ReadBinaryValue(kStream, iValue);
    eValue = iValue;
}

struct CubeTexBase
{
    virtual void v00();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }
    void LoadBinaryTexture(NiStream& kStream);
    void LoadBinarySource(NiStream& kStream);
};

struct CubeMapLoader : CubeTexBase
{
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_ePreferredPixelLayout;
    int m_eAlphaFormat;
    int m_eMipFlag;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    bool m_bIsStatic;

    void CreateFaces(char* pc0, char* pc1, char* pc2, char* pc3, char* pc4, char* pc5, int iParam);
    void LoadBinary(NiStream& kStream);
};

// @fnv 0x00a612a0
void CubeMapLoader::LoadBinary(NiStream& kStream)
{
    if (kStream.m_uiNifVersion < 0x0A030006)
    {
        LoadBinaryTexture(kStream);
        IncRefCount();

        char cCreateFaces = 0;
        LoadChar(kStream, cCreateFaces);

        char* apcFaceNames[6] = {};
        unsigned int i;
        for (i = 0; i < 6; i++)
            kStream.ReadCString(apcFaceNames[i]);

        kStream.ReadUnsignedInteger(6);
        for (i = 0; i < 6; i++)
            kStream.ResetStreamState();

        if (cCreateFaces)
            CreateFaces(apcFaceNames[0], apcFaceNames[1], apcFaceNames[2], apcFaceNames[3], apcFaceNames[4],
                        apcFaceNames[5], kStream.unk1E8);

        for (i = 0; i < 6; i++)
            NiFree(apcFaceNames[i]);

        LoadEnum(kStream, m_ePreferredPixelLayout);
        LoadEnum(kStream, m_eMipFlag);
        LoadEnum(kStream, m_eAlphaFormat);
        bool oldStatic = m_bIsStatic;
        LoadBool(kStream, oldStatic);
        m_bIsStatic = oldStatic;
        DecRefCount();
    }
    else
    {
        LoadBinarySource(kStream);
    }
}

void __cdecl SaveBinary();

// @fnv 0x00a60870
void __cdecl FUN_00a60870()
{
    SaveBinary();
}

struct NiGPUProgram;

template <class T> class NiPointer
{
  public:
    NiPointer<T>& operator=(T* pObject);
    bool operator==(T* pObject) const
    {
        return m_pObject == pObject;
    }
    T* m_pObject;
};

struct ProgramFactory_a60
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual NiGPUProgram* CreateProgram(char* pcName, int iFlags, void* pvDefines);
};
ProgramFactory_a60* __cdecl FUN_00a76640();

struct ShaderPass_a60
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
    char* m_pcProgramName;
    int unk38;
    NiPointer<NiGPUProgram> m_spShaderProgram;
    int unk40;
    void* m_pvDefines;
    void EnsureProgramCreated();
};
// @fnv 0x00a608c0
void ShaderPass_a60::EnsureProgramCreated()
{
    if (m_spShaderProgram == 0 && m_pcProgramName != DAT_0109b220)
    {
        ProgramFactory_a60* pkFactory = FUN_00a76640();
        char* pcName = m_pcProgramName;
        m_spShaderProgram = pkFactory->CreateProgram(pcName, 0, m_pvDefines);
        m_pvDefines = 0;
    }
}

extern "C" unsigned int __cdecl strlen(const char* s);
extern "C" void* __cdecl memset(void* d, int v, unsigned int n);

struct S00a60cc0_Ref
{
    virtual void v00();
    virtual void DeleteThis();
    long m_ref;
};

struct S00a60cc0_Mgr
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual S00a60cc0_Ref* Create(char* buf, int a, int b);
};

struct S00a60cc0_Loader
{
    virtual void v00();
    virtual void v01();
    virtual bool v02(char* buf, int size);
    void SetPath(void* p);
};

void* __cdecl FUN_00aa1070(unsigned int size);
int __cdecl FUN_00ec65a6(char* dst, unsigned int n, const char* src);
void __cdecl FUN_00aa2a00(char* p);
void* __cdecl GetPathWithExtension(char* p);
bool __cdecl FUN_00aa1a30(const char* p, int a);

static __forceinline void S00a60cc0_ReleaseAll(S00a60cc0_Ref** res)
{
    S00a60cc0_Ref** pp = res + 6;
    int n = 5;
    do
    {
        S00a60cc0_Ref* p = *--pp;
        if (p)
        {
            if (InterlockedDecrement(&p->m_ref) == 0)
                p->DeleteThis();
        }
    } while (--n >= 0);
}

struct S00a60cc0_Target
{
    void FUN_00a60940(S00a60cc0_Ref* r0, S00a60cc0_Ref* r1, S00a60cc0_Ref* r2, S00a60cc0_Ref* r3, S00a60cc0_Ref* r4,
                      S00a60cc0_Ref* r5);
    void LoadResources(char* a1, char* a2, char* a3, char* a4, char* a5, char* a6, S00a60cc0_Loader* a7);
};

// Loads six resources by name via a loader and manager, storing the created refs and calling FUN_00a60940 on success.
// @fnv 0x00a60cc0
void S00a60cc0_Target::LoadResources(char* apName0, char* apName1, char* apName2, char* apName3, char* apName4,
                                     char* apName5, S00a60cc0_Loader* apLoader)
{
    S00a60cc0_Ref* res[6];
    memset(res, 0, sizeof(res));
    char* names[6] = {apName0, apName1, apName2, apName3, apName4, apName5};
    S00a60cc0_Mgr* mgr = (S00a60cc0_Mgr*)FUN_00a76640();
    char buf[260];
    for (unsigned int idx = 0; idx < 6; idx++)
    {
        char* src = names[idx];
        unsigned int len = strlen(src) + 1;
        char* copy = (char*)FUN_00aa1070(len);
        FUN_00ec65a6(copy, len, src);
        FUN_00aa2a00(copy);
        void* tmp = GetPathWithExtension(copy);
        apLoader->SetPath(tmp);
        apLoader->v01();
        if (apLoader->v02(buf, 260))
        {
        retry:
            if (!FUN_00aa1a30(buf, 0))
            {
                if (apLoader->v02(buf, 260))
                    goto retry;
                goto tail;
            }
            S00a60cc0_Ref* pNew = mgr->Create(buf, 0, 0);
            S00a60cc0_Ref* old = res[idx];
            if (old != pNew)
            {
                if (old && InterlockedDecrement(&old->m_ref) == 0)
                    old->DeleteThis();
                res[idx] = pNew;
                if (pNew)
                    InterlockedIncrement(&pNew->m_ref);
            }
            NiFree(tmp);
            NiFree(copy);
        }
    tail:
        if (!res[idx])
        {
            S00a60cc0_ReleaseAll(res);
            return;
        }
    }
    FUN_00a60940(res[0], res[1], res[2], res[3], res[4], res[5]);
    S00a60cc0_ReleaseAll(res);
}

extern "C" void* DAT_0109babc;
extern "C" void __cdecl FUN_00aa1460(void*, unsigned int);
extern "C" void _ReadWriteBarrier();

struct CubePixels
{
    virtual void slot0();
    virtual void Destroy() throw();
    volatile long refs;
};

struct CubeCleanup
{
    void* vtable;
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38;
    CubePixels* pixels;
    unsigned int unk40, unk44, unk48;

    void FUN_00a5fca0();
    void* FUN_00a61250(unsigned int flags);
};

// Releases pixels, calls FUN_00a5fca0, and calls FUN_00aa1460 with this and sizeof(CubeCleanup) when flags & 1.
// @fnv 0x00a61250
void* CubeCleanup::FUN_00a61250(unsigned int flags)
{
    vtable = &DAT_0109babc;
    _ReadWriteBarrier();
    CubePixels* old = pixels;
    if (old)
    {
        if (!InterlockedDecrement(&old->refs))
            old->Destroy();
        pixels = 0;
    }
    FUN_00a5fca0();
    if (flags & 1)
        FUN_00aa1460(this, sizeof(CubeCleanup));
    return this;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" void* __cdecl FUN_00aa13e0(unsigned int);
void __cdecl FUN_00ec44d0(void*, const void*, unsigned int) throw();
struct PixelFormat
{
    unsigned int unk00;
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
};
struct Pixels
{
    virtual void slot0();
    virtual void Destroy() throw();
    volatile long refs;
    PixelFormat format;
    unsigned char* data;
    unsigned int* widths;
    unsigned int* heights;
    unsigned int* offsets;
    unsigned int levels;
    unsigned int unk64, unk68, unk6c, unk70;
    static void* __cdecl operator new(unsigned int size) throw();
    __declspec(nothrow) unsigned int Width() const
    {
        return *widths;
    }
    __declspec(nothrow) unsigned int Height() const
    {
        return *heights;
    }
    __declspec(nothrow) unsigned int Size(unsigned int level) const
    {
        return offsets[level + 1] - offsets[level];
    }
    __declspec(nothrow) unsigned char* Data(unsigned int level, unsigned int face = 0) const
    {
        return data + offsets[level] + offsets[levels] * face;
    }
    unsigned char* SourceData(unsigned int level) const
    {
        return &data[offsets[level]];
    }
    Pixels(unsigned int, unsigned int, const PixelFormat&, unsigned int, unsigned int) throw();
};
struct PixelPtr
{
    Pixels* ptr;
    __declspec(nothrow) __forceinline void operator=(Pixels* value)
    {
        if (ptr != value)
        {
            Pixels* old = ptr;
            if (old && !InterlockedDecrement(&old->refs))
                old->Destroy();
            ptr = value;
            if (ptr)
                InterlockedIncrement(&ptr->refs);
        }
    }
};
struct CubeHost
{
    unsigned int unk00;
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
    PixelPtr pixels;
    void FUN_00a60940(Pixels*, Pixels*, Pixels*, Pixels*, Pixels*, Pixels*);
};
// Allocates a Pixels object with six faces, copies each level from the six inputs, then releases their references.
// @fnv 0x00a60940
void CubeHost::FUN_00a60940(Pixels* a, Pixels* b, Pixels* c, Pixels* d, Pixels* e, Pixels* f)
{
    void* storage = FUN_00aa13e0(sizeof(Pixels));
    Pixels* created;
    if (storage)
    {
        unsigned int levels = a->levels;
        unsigned int height = *a->heights;
        unsigned int width = *a->widths;
        created = ::new (storage) Pixels(width, height, a->format, levels, 6);
    }
    else
        created = 0;
    pixels = created;
    PixelPtr facePtrs[6];
    memset(facePtrs, 0, sizeof(facePtrs));
    facePtrs[0] = a;
    facePtrs[1] = b;
    facePtrs[2] = c;
    facePtrs[3] = d;
    facePtrs[4] = e;
    facePtrs[5] = f;
    for (unsigned int face = 0; face < 6; ++face)
    {
        for (unsigned int level = 0; level < facePtrs[face].ptr->levels; ++level)
        {
            Pixels* dst = pixels.ptr;
            unsigned int size = facePtrs[face].ptr->Size(level);
            unsigned char* source = facePtrs[face].ptr->SourceData(level);
            FUN_00ec44d0(dst->Data(level, face), source, size);
        }
    }
    PixelPtr* cursor = facePtrs + 6;
    for (int cleanup = 5; cleanup >= 0; --cleanup)
    {
        Pixels* old = (--cursor)->ptr;
        if (old && !InterlockedDecrement(&old->refs))
            old->Destroy();
    }
}
