
// src/gamebryo2.2/corelibs/nimain/nirenderedcubemap.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nirenderedcubemap.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00ee8220_shell
{
    void* __thiscall GetWidth();
};

// @fnv 0x00ee8220
void* __thiscall FUN_00ee8220_shell::GetWidth()
{
    void* p = *(void**)(this + 0x4C);
    return *(void**)((char*)p + 8);
}

struct FUN_00ee8230_shell
{
    int __thiscall GetHeight();
};

// @fnv 0x00ee8230
int __thiscall FUN_00ee8230_shell::GetHeight()
{
    int* p = *(int**)((char*)this + 0x4c);
    return *(int*)((char*)p + 0xc);
}

extern "C" void* DAT_012708e4;

// @fnv 0x00ee82a0
void* __cdecl FUN_00ee82a0()
{
    return &DAT_012708e4;
}

void __cdecl operator delete(void* p, size_t size);
void* __cdecl operator new(size_t);
struct NiRenderedCubeMap
{
    virtual ~NiRenderedCubeMap();
    void __thiscall FUN_00ee82b0();
};
struct NiRenderedCubeMap_shell : NiRenderedCubeMap
{
    void* __thiscall FUN_00ee8440(unsigned int flags);
};
// Calls FUN_00ee82b0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00ee8440
void* __thiscall NiRenderedCubeMap_shell::FUN_00ee8440(unsigned int flags)
{
    FUN_00ee82b0();
    if (flags & 1)
        operator delete(this, 0x64);
    return this;
}

extern "C" void _ReadWriteBarrier(void);
#include <string.h>
extern int DAT_0109b944;
extern int DAT_0110102c;
struct NiProperty
{
    NiProperty() throw();
    int* m_pVtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct Mid_ee8240 : NiProperty
{
    Mid_ee8240() throw()
    {
        m_pVtbl = &DAT_0109b944;
        m_iA = 6;
        m_iB = 3;
        m_iC = 2;
        m_iD = 0;
        FUN_00a5f7b0();
        m_i30 = 0;
        _ReadWriteBarrier();
    }
    void FUN_00a5f7b0() throw();
    int m_iA;
    int m_iB;
    int m_iC;
    volatile int m_iD;
    int unk28;
    int unk2C;
    int m_i30;
};
struct FUN_00ee8240 : Mid_ee8240
{
    FUN_00ee8240() throw();
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int m_i48;
    int m_i4C;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5C;
    int m_i60;
};
// Constructor for FUN_00ee8240 that sets the vtable pointer and zero-initializes m_i4C through m_i60 plus m_i48.
// @fnv 0x00ee8240
FUN_00ee8240::FUN_00ee8240() throw()
{
    m_pVtbl = &DAT_0110102c;
    memset(&m_i4C, 0, 0x18);
    m_i48 = 0;
}

#include <windows.h>
struct Ref
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
};
struct Item
{
    virtual ~Item();
};
extern int DAT_0109b944;
struct Obj
{
    virtual void baseSlot() = 0;
    int pad04;
    int pad08;
    int pad0c;
    int pad10;
    int pad14;
    int pad18;
    int pad1c;
    int pad20;
    Item* item24;
    int pad28;
    int pad2c;
    Ref* ref30;
    int pad34;
    int pad38;
    int pad3c;
    int pad40;
    int pad44;
    int pad48;
    Ref* ref4c;
    Ref* ref50;
    Ref* ref54;
    Ref* ref58;
    Ref* ref5c;
    Ref* ref60;
    Ref* end64;
    void FUN_00ee82b0();
    void FUN_00a5f800();
    void DestroyFogProperty();
};
// Releases the six Ref pointers and item24, resets the vtable to DAT_0109b944, then calls FUN_00a5f800 and DestroyFogProperty.
// @fnv 0x00ee82b0
void Obj::FUN_00ee82b0()
{
    Ref** next = &end64;
    int count = 5;
    do
    {
        Ref* p = *--next;
        if (p && InterlockedDecrement((volatile long*)p + 1) == 0)
            p->slot1();
        --count;
    } while (count >= 0);
    Ref* p = ref30;
    if (p && InterlockedDecrement((volatile long*)p + 1) == 0)
        p->slot1();
    *(int*)this = (int)&DAT_0109b944;
    if (item24)
        delete item24;
    FUN_00a5f800();
    DestroyFogProperty();
}

struct S_00ee8330_RefObject
{
    virtual ~S_00ee8330_RefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((LONG*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((LONG*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct S_00ee8330_Buffer : S_00ee8330_RefObject
{
    static S_00ee8330_Buffer* Create(unsigned int uiWidth, unsigned int uiHeight);
};

template <class T> struct S_00ee8330_Ptr
{
    T* m_pObject;
    S_00ee8330_Ptr& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

struct S_00ee8330_FormatPrefs
{
    int m_ePreferredPixelLayout;
    int m_eAlphaFormat;
    int m_eMipFlag;
};

extern bool DAT_011f4ac0;
extern int DAT_011ab3c8;
extern bool DAT_011ab3c4;

struct S_00ee8330_Renderer;

inline bool S_00ee8330_IsPowerOf2(unsigned int ui)
{
    if (ui == 0)
        return false;
    return (ui & (ui - 1)) == 0;
}

struct S_00ee8330_CubeMap
{
    static void* operator new(size_t n);
    S_00ee8330_CubeMap() throw();
    virtual ~S_00ee8330_CubeMap();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    S_00ee8330_FormatPrefs m_kTextureFormatPreferences;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    bool m_b40;
    bool m_b41;
    int m_i44;
    int unk48;
    S_00ee8330_Ptr<S_00ee8330_Buffer> m_kFaceBuffers[6];

    static S_00ee8330_CubeMap* FUN_00ee8330(unsigned int uiSize, S_00ee8330_Renderer* pkRenderer,
                                            S_00ee8330_FormatPrefs& kPrefs);
};

struct S_00ee8330_Renderer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual bool CreateRenderedCubeMapRendererData(S_00ee8330_CubeMap* pkCubeMap);
};

// Allocates a cube map, creates six face buffers, copies three globals into fields, and calls the renderer to create renderer data.
// @fnv 0x00ee8330
S_00ee8330_CubeMap* S_00ee8330_CubeMap::FUN_00ee8330(unsigned int uiFaceSize, S_00ee8330_Renderer* pkRenderer,
                                                     S_00ee8330_FormatPrefs& kPrefs)
{
    if (!pkRenderer || !S_00ee8330_IsPowerOf2(uiFaceSize))
        return 0;

    S_00ee8330_CubeMap* pkThis = new S_00ee8330_CubeMap;
    pkThis->m_kTextureFormatPreferences = kPrefs;

    for (unsigned int ui = 0; ui < 6; ui++)
        pkThis->m_kFaceBuffers[ui] = S_00ee8330_Buffer::Create(uiFaceSize, uiFaceSize);

    pkThis->m_b41 = DAT_011f4ac0;
    pkThis->m_i44 = DAT_011ab3c8;
    pkThis->m_b40 = DAT_011ab3c4;

    if (!pkRenderer->CreateRenderedCubeMapRendererData(pkThis))
    {
        delete pkThis;
        return 0;
    }
    return pkThis;
}
