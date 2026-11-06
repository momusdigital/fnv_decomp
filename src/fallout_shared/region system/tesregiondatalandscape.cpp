// fallout_shared/region system/tesregiondatalandscape.cpp: TESRegionDataLandscape, ThisT (15 functions)

#include "tesregiondatalandscape_decls.h"
// @fnv 0x004f2a20
bool TESRegionDataLandscape::ReadLandscapeData(TESFile* file)
{
    if (!file)
        return false;
    unsigned int chunk = file->GetChunkID();
    switch (chunk)
    {
    case 0x4e4f4349:
        TESTexture::ReadTextureData(m_pLandscapeTexture, file);
        break;
    }
    return true;
}

// @fnv 0x004f2790
TESRegionDataLandscape::TESRegionDataLandscape()
{
    m_pLandscapeTexture = new TESTexture;
    m_pLandscapeTexture->AssignTextureName("Trees\\CanopyShadow.dds");
}

// Writes 6, 3 and 2 into the first three int slots of pThis and returns pThis.
// @fnv 0x004f31d0
int* __fastcall InitIntArray(int* pIntArray)
{
    pIntArray[0] = 6;
    pIntArray[1] = 3;
    pIntArray[2] = 2;
    return pIntArray;
}

struct FUN_004f32b0_This
{
    void SetMaskedBits(unsigned short, unsigned short, unsigned short);
};

struct FUN_004f32b0_Arg
{
    unsigned short val;
};

// Calls SetMaskedBits with the argument's val, 0x3000 and 0xc.
// @fnv 0x004f32b0
void __fastcall FUN_004f32b0(FUN_004f32b0_This* this_ptr, FUN_004f32b0_Arg aValue)
{
    this_ptr->SetMaskedBits(aValue.val, 0x3000, 0xc);
}

void* __fastcall FUN_004f2930(void* this_ptr);

struct FUN_004f2840_shell
{
    void* __thiscall FUN_004f2840(unsigned int flags);
};

// Calls FUN_004f2930 on this, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x004f2840
void* FUN_004f2840_shell::FUN_004f2840(unsigned int flags)
{
    FUN_004f2930(this);
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_004f29c0_This : TESTexture
{
    void* __thiscall FUN_004f29c0(unsigned int flags);
};

// Destroys the TESTexture base and, when flags has bit 0 set, frees the object, returning this.
// @fnv 0x004f29c0
void* __thiscall FUN_004f29c0_This::FUN_004f29c0(unsigned int flags)
{
    TESTexture::~TESTexture();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct TESModel
{
    unsigned int __thiscall GetModelLength() const;
};

struct FUN_004f2eb0_shell
{
    int _0;
    int _4;
    TESModel* m_pLandscapeTexture;
    bool __thiscall HasModel();
};

// Returns true if the TESModel pointer is set and its model length is non-zero, otherwise false.
// @fnv 0x004f2eb0
bool __thiscall FUN_004f2eb0_shell::HasModel()
{
    if (!this->m_pLandscapeTexture || !this->m_pLandscapeTexture->GetModelLength())
        return false;
    return true;
}

struct BSStr
{
    bool __thiscall Set(const char* s, unsigned int len);
};

struct FNStub
{
    const char* __thiscall GetFullName() const;
};

extern const char $SG5889[];

struct FUN_004f2a70_shell
{
    void* _0;
    void* _4;
    FNStub* _8;
    void __thiscall SetFullName(BSStr& aDest);
};

// @fnv 0x004f2a70
void FUN_004f2a70_shell::SetFullName(BSStr& aDest)
{
    if (!_8)
        aDest.Set($SG5889, 0);
    else
        aDest.Set(_8->GetFullName(), 0);
}

struct FUN_0048e370_obj
{
    void __thiscall FUN_0048e370(unsigned int);
};
void __fastcall WriteSaveData(void* this_ptr);
struct FUN_004f29f0_shell
{
    char _0[8];
    FUN_0048e370_obj* _8;
    void __thiscall Save();
};
// @fnv 0x004f29f0
void __thiscall FUN_004f29f0_shell::Save()
{
    WriteSaveData(this);
    _8->FUN_0048e370(0x4E4F4349);
}

struct Flt
{
    operator unsigned int() const;
};
int __cdecl _stricmp(const char*, const char*);
struct FUN_004f2ab0_shell : public FUN_004f2eb0_shell
{
    bool __thiscall FUN_004f2ab0(const Flt& aName);
};
// @fnv 0x004f2ab0
bool __thiscall FUN_004f2ab0_shell::FUN_004f2ab0(const Flt& aName)
{
    if (m_pLandscapeTexture)
    {
        if (!m_pLandscapeTexture->GetModelLength() ||
            _stricmp(((FNStub*)m_pLandscapeTexture)->GetFullName(), (const char*)aName.operator unsigned int()) != 0)
        {
            ((TESTexture*)m_pLandscapeTexture)->AssignTextureName((const char*)aName.operator unsigned int());
            return true;
        }
    }
    return false;
}

struct NiPixelFormat;
extern const NiPixelFormat gNiPoint3StartupSrc;
struct NiPixelData
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    NiPixelData(unsigned int, unsigned int, const NiPixelFormat&, unsigned int, unsigned int);
    unsigned char* FUN_0064dac0(int, int);
    void AddString();
};
struct NiFixedString
{
    const char* m_kHandle;
    NiFixedString(const char*);
    ~NiFixedString();
};
struct TextureFormatPreferences
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
};
struct NiTexturingProperty
{
    void SetBaseMapClampMode(int);
};
struct FUN_00a6abb0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    FUN_00a6abb0(NiPixelData*, const NiFixedString&, TextureFormatPreferences&);
};
struct GO
{
    operator NiTexturingProperty*() const;
    void operator=(void*);
};
extern GO g_011c7f0c;
float RandomFloat(float, float);
// Creates a 64x64 random RGBA NiPixelData, wraps it in a texturing property named DefaultFullMaskTextureProp, caches it in g_011c7f0c and returns it.
// @fnv 0x004f2ee0
NiTexturingProperty* GetDefaultFullMaskTextureProperty()
{
    NiPixelData* ppixeldata;
    unsigned char* ppixels;
    unsigned int iy;
    TextureFormatPreferences myPrefs;
    unsigned int ix;
    if (g_011c7f0c)
        return g_011c7f0c;
    ppixeldata = new NiPixelData(64, 64, gNiPoint3StartupSrc, 1, 1);
    ppixels = ppixeldata->FUN_0064dac0(0, 0);
    for (iy = 0; iy < 64; iy++)
    {
        for (ix = 0; ix < 64; ix++)
        {
            ppixels[(iy * 64 + ix) * 4 + 0] = (unsigned char)RandomFloat(0, 255.0f);
            ppixels[(iy * 64 + ix) * 4 + 1] = (unsigned char)RandomFloat(0, 255.0f);
            ppixels[(iy * 64 + ix) * 4 + 2] = (unsigned char)RandomFloat(0, 255.0f);
            ppixels[(iy * 64 + ix) * 4 + 3] = (unsigned char)RandomFloat(0, 255.0f);
        }
    }
    ppixeldata->AddString();
    InitIntArray((int*)&myPrefs);
    g_011c7f0c = new FUN_00a6abb0(ppixeldata, NiFixedString("DefaultFullMaskTextureProp"), myPrefs);
    ((NiTexturingProperty*)g_011c7f0c)->SetBaseMapClampMode(0);
    return g_011c7f0c;
}

struct FUN_004f2870
{
    char _0[12];
    FUN_004f2870(const void*);
    ~FUN_004f2870();
};
struct FUN_004f2b10_shell
{
    FUN_004f2870* CreateCopy();
};
// Allocates a new FUN_004f2870 constructed from this object and returns the pointer.
// @fnv 0x004f2b10
FUN_004f2870* FUN_004f2b10_shell::CreateCopy()
{
    FUN_004f2870* pdata = new FUN_004f2870(this);
    return pdata;
}

struct FUN_004f2930_tex
{
    void* FUN_004f29c0(unsigned int flags);
};

struct FUN_004f2930_base
{
    virtual ~FUN_004f2930_base();
    int unk04;
};

struct FUN_004f2930_cls : FUN_004f2930_base
{
    FUN_004f2930_tex* m_08;
    virtual ~FUN_004f2930_cls();
};

// @fnv 0x004f2930
FUN_004f2930_cls::~FUN_004f2930_cls()
{
    FUN_004f2930_tex* copy;
    FUN_004f2930_tex* tmp;
    if (m_08 != 0)
    {
        copy = m_08;
        tmp = copy;
        tmp != 0 ? tmp->FUN_004f29c0(1) : 0;
    }
}

template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT();
    ~BSStringT();
};

extern double DAT_01023b88;
float __cdecl floor(float);

struct ThisT
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual int Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10(BSStringT<char>* s);
    virtual void Slot11(BSStringT<char>* s);
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char FUN_004f1540();
    void FUN_004f15a0(int v);
    bool FUN_004f15c0(unsigned char v);
    unsigned char FUN_005bb4d0();
    void __thiscall UpdateFromSource(ThisT* a1, int a2);
};

// @fnv 0x004f2b90
void __thiscall ThisT::UpdateFromSource(ThisT* a1, int a2)
{
    ThisT* a1p = a1;
    BSStringT<char> str3;
    float f;
    if (!a1 || a1->Slot04() != 5 || !a2)
        return;
    if (m_05)
    {
        FUN_004f15a0(a1p->FUN_004f1540());
        FUN_004f15c0(a1p->FUN_005bb4d0());
        a1p->Slot10(&str3);
        Slot11(&str3);
    }
    else
    {
        if (a1p->m_05)
        {
            return;
        }
        else
        {
            if (m_04)
            {
                if (a1p->FUN_004f1540())
                {
                    if (a1p->FUN_005bb4d0() > FUN_005bb4d0())
                    {
                        FUN_004f15a0(a1p->FUN_004f1540());
                        FUN_004f15c0(a1p->FUN_005bb4d0());
                        a1p->Slot10(&str3);
                        Slot11(&str3);
                    }
                }
                return;
            }
            else
            {
                if (a1p->FUN_004f1540())
                {
                    FUN_004f15a0(a1p->FUN_004f1540());
                    FUN_004f15c0(a1p->FUN_005bb4d0());
                    a1p->Slot10(&str3);
                    Slot11(&str3);
                }
                else
                {
                    if (a1p->FUN_005bb4d0() > FUN_005bb4d0())
                    {
                        a1p->Slot10(&str3);
                        Slot11(&str3);
                    }
                    f = (float)(FUN_005bb4d0() * FUN_005bb4d0() + (100 - FUN_005bb4d0()) * a1p->FUN_005bb4d0());
                    f += (float)((100 - a1p->FUN_005bb4d0()) * FUN_005bb4d0() +
                                 a1p->FUN_005bb4d0() * a1p->FUN_005bb4d0());
                    f *= DAT_01023b88;
                    FUN_004f15c0((unsigned char)floor(f));
                }
            }
        }
    }
}

// TESRegionDataLandscape copy constructor: copy the base region data and clone the texture.

void* __cdecl operator new(unsigned int uiSize);

class F2870Texture
{
  public:
    F2870Texture();
    virtual ~F2870Texture();
    const char* GetTexturePath() const;
    void SetTexturePath(const char* pcPath);

    char* m_pcPath;
    unsigned short m_usLen;
    unsigned short m_usMax;
};

class F2870RegionData
{
  public:
    F2870RegionData(const F2870RegionData& kOther);
    virtual ~F2870RegionData();
    int unk04;
};

class FUN_004f2870_Landscape : public F2870RegionData
{
  public:
    FUN_004f2870_Landscape(const FUN_004f2870_Landscape& kOther);
    virtual ~FUN_004f2870_Landscape();

    F2870Texture* m_pkTexture;
};

// Copy-constructs a landscape region, allocating a new texture and copying the source texture's path into it.
// @fnv 0x004f2870
FUN_004f2870_Landscape::FUN_004f2870_Landscape(const FUN_004f2870_Landscape& kOther) : F2870RegionData(kOther)
{
    m_pkTexture = new F2870Texture;
    m_pkTexture->SetTexturePath(kOther.m_pkTexture->GetTexturePath());
}
