
// src/gamebryo2.2/corelibs/nianimation/niflipcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niflipcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00a4f300_shell
{
    void* GetEntryAt(int idx);
};

// @fnv 0x00a4f300
void* FUN_00a4f300_shell::GetEntryAt(int uiIndex)
{
    unsigned short size = *(unsigned short*)((char*)this + 0x42);
    if ((unsigned int)uiIndex < size)
    {
        void** arr = *(void***)((char*)this + 0x3C);
        return arr[uiIndex];
    }
    return 0;
}

extern "C" const void* g_011f3fd4;

// @fnv 0x00a4f5d0
const void* __cdecl FUN_00a4f5d0()
{
    return &g_011f3fd4;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

struct NiFlipController
{
    void* __thiscall FUN_00a4f820();
};

// @fnv 0x00a4f970
void* __cdecl CreateNiFlipController()
{
    void* p = BSFadeNode::operator new(0x54);
    if (p)
        return ((NiFlipController*)p)->FUN_00a4f820();
    return 0;
}

void* __cdecl _NiMalloc(unsigned int);
int __cdecl _NiSprintf(char*, unsigned int, const char*, ...);
struct FUN_00a4f320_Holder
{
    const char* __thiscall GetFormattedValue();
};
// Returns the cached string at offset 0x50, lazily formatting the integer at offset 0x4c into a 15-byte buffer with "%d" if it is null.
// @fnv 0x00a4f320
const char* __thiscall FUN_00a4f320_Holder::GetFormattedValue()
{
    char* pcFormattedValue = *(char**)((char*)this + 0x50);
    if (!pcFormattedValue)
    {
        pcFormattedValue = (char*)_NiMalloc(15);
        *(char**)((char*)this + 0x50) = pcFormattedValue;
        _NiSprintf(pcFormattedValue, 15, "%d", *(unsigned int*)((char*)this + 0x4c));
        pcFormattedValue = *(char**)((char*)this + 0x50);
    }
    return pcFormattedValue;
}

struct NiRTTI
{
    void* _00;
    NiRTTI* m_pkBase;
};
extern NiRTTI g_011f49a4;
struct NiObjectNET
{
    virtual void f0();
    virtual void f1();
    virtual NiRTTI* GetRTTI();
};
// Walks pkTarget's NiRTTI base chain and returns true if it reaches g_011f49a4, false for a null target or RTTI.
// @fnv 0x00a4f5e0
bool __stdcall FUN_00a4f5e0(NiObjectNET* pkTarget)
{
    if (!pkTarget)
        return false;
    NiRTTI* pkRTTI = pkTarget->GetRTTI();
    if (!pkRTTI)
        return false;
    while (pkRTTI)
    {
        if (pkRTTI == &g_011f49a4)
            return true;
        pkRTTI = pkRTTI->m_pkBase;
    }
    return false;
}

struct Proxy570
{
    void __thiscall FUN_00a4f570();
};
void __cdecl _delete(void*, unsigned int);
struct Proxy880
{
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// Calls FUN_00a4f570 on this, then if bit 0 of a1 is set frees this with _delete and returns this.
// @fnv 0x00a4f880
void* __thiscall Proxy880::DestroyIfFlagged(unsigned int auiFlags)
{
    ((Proxy570*)this)->FUN_00a4f570();
    if (auiFlags & 1)
        _delete(this, 0x54);
    return this;
}

struct CloningProcess
{
};
struct NiAlphaController
{
    void __thiscall CopyMemberData(NiAlphaController*, CloningProcess&);
};
struct FlipCopy : NiAlphaController
{
    void __thiscall FUN_00a4f8a0(void*, unsigned int);
    void* GetSrc(unsigned int i)
    {
        unsigned short cnt = *(unsigned short*)((char*)this + 0x42);
        void** arr = *(void***)((char*)this + 0x3c);
        if (i < cnt)
            return arr[i];
        return 0;
    }
    void __thiscall FUN_00a4f920(NiAlphaController*, CloningProcess&);
};
// Calls the base copy, copies the int at offset 0x4c to dst, then copies each source entry via GetSrc and FUN_00a4f8a0.
// @fnv 0x00a4f920
void __thiscall FlipCopy::FUN_00a4f920(NiAlphaController* dst, CloningProcess& proc)
{
    NiAlphaController::CopyMemberData(dst, proc);
    *(int*)((char*)dst + 0x4c) = *(int*)((char*)this + 0x4c);
    for (unsigned int i = 0; i < *(unsigned short*)((char*)this + 0x42); ++i)
    {
        void* e = ((FlipCopy*)this)->GetSrc(i);
        ((FlipCopy*)dst)->FUN_00a4f8a0(e, i);
    }
}

struct FUN_00a40520 : BSFadeNode
{
    unsigned char _pad[12];
    unsigned char m_uiObjectFlags;
    unsigned char _pad2[39];
    __declspec(nothrow) FUN_00a40520(bool, float, unsigned char);
};
// @fnv 0x00a4f2c0
FUN_00a40520* __stdcall CreateBlendInterpolator(unsigned short usIndex, bool bManagerControlled, bool bAccumulateAnimations,
                                     float fWeightThreshold, unsigned char ucArraySize)
{
    FUN_00a40520* pkInterp = new FUN_00a40520(bManagerControlled, fWeightThreshold, ucArraySize);
    pkInterp->m_uiObjectFlags |= 2;
    return pkInterp;
}

struct NiStream;
struct NiTexture
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
    virtual bool __thiscall RegisterStreamables(NiStream&);
};
struct BaseA
{
    bool __thiscall FUN_00a57780(NiStream&);
};
struct ProxyFlip : BaseA
{
    bool __thiscall FUN_00a4f350(NiStream& kStream);
};
// @fnv 0x00a4f350
bool ProxyFlip::FUN_00a4f350(NiStream& kStream)
{
    if (!FUN_00a57780(kStream))
        return false;
    unsigned int uiSize = *(unsigned short*)((char*)this + 0x42);
    unsigned int uiIndex;
    NiTexture* pkTexture;
    for (uiIndex = 0; uiIndex < uiSize; ++uiIndex)
    {
        pkTexture = (*(NiTexture***)((char*)this + 0x3C))[uiIndex];
        if (pkTexture)
            pkTexture->RegisterStreamables(kStream);
    }
    return true;
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};

struct NiObject
{
};

struct FUN_00a4fa20_shell : FlipCopy
{
    void* CreateFlipController(CloningProcess& kCloning);
};

// Allocates a NiFlipController, initialises it via FUN_00a4f820, copies from kCloning via FUN_00a4f920, and returns it as a NiObject.
// @fnv 0x00a4fa20
void* FUN_00a4fa20_shell::CreateFlipController(CloningProcess& kCloning)
{
    NiFlipController* pkObject = (NiFlipController*)A51BF0Base::operator new(0x54);
    if (pkObject)
        pkObject = (NiFlipController*)pkObject->FUN_00a4f820();
    else
        pkObject = 0;
    FUN_00a4f920((NiAlphaController*)pkObject, kCloning);
    return (NiObject*)pkObject;
}

struct FUN_00a4f270_cls
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int m_48;

    void __thiscall GetFloatValue(float* out);
};

// @fnv 0x00a4f270
void FUN_00a4f270_cls::GetFloatValue(float* pfOut)
{
    *pfOut = (float)m_48;
}

struct FUN_00a4f290_class
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

    bool __thiscall FUN_00a57c10(FUN_00a4f290_class*);
    unsigned char __thiscall IsEqual(FUN_00a4f290_class*);
};

// Returns 0 if FUN_00a57c10 fails, otherwise returns whether unk4c equals param->unk4c.
// @fnv 0x00a4f290
unsigned char FUN_00a4f290_class::IsEqual(FUN_00a4f290_class* param)
{
    if (!FUN_00a57c10(param))
    {
        return 0;
    }

    return unk4c == param->unk4c;
}

struct FNVStream
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
    virtual void SaveLink(void*);
};
struct FNVWriter
{
    void* unk00;
    unsigned int written;
    void* unk08;
    unsigned int(__cdecl* Write)(FNVWriter*, const void*, unsigned int, unsigned int*, unsigned int);
    void SaveResult(const void* data)
    {
        unsigned int bytes = 4;
        unsigned int result = Write(this, data, 4, &bytes, 1);
        written += result;
    }
};
struct FNVBaseController
{
    void __thiscall FUN_00a57c00(FNVStream*);
};
struct FNVFlipController : FNVBaseController
{
    void __thiscall SaveToStream(FNVStream*);
};
// Calls the base save, writes the field at 0x4c and a count, then saves each of the count objects from the array at 0x3c via the stream.
// @fnv 0x00a4f4e0
void __thiscall FNVFlipController::SaveToStream(FNVStream* stream)
{
    FUN_00a57c00(stream);
    FNVWriter* writer = *(FNVWriter**)((char*)stream + 0x250);
    writer->SaveResult((char*)this + 0x4c);

    unsigned int count = *(unsigned short*)((char*)this + 0x42);
    writer = *(FNVWriter**)((char*)stream + 0x250);
    {
        unsigned int bytes = 4;
        writer->written += writer->Write(writer, &count, 4, &bytes, 1);
    }
    for (unsigned int i = 0; i < count; ++i)
    {
        void* object = (*(void***)((char*)this + 0x3c))[i];
        stream->SaveLink(object);
    }
}

char** FUN_005e0ba0(unsigned int ItemUpdateArray) throw();

template <class T> class A4F820Array
{
  public:
    A4F820Array(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = FUN_005e0ba0(m_usMaxSize);
        else
            m_pBase = 0;
    }
    virtual ~A4F820Array() throw();

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

template <class T> class A4F820PrimitiveArray : public A4F820Array<T>
{
  public:
    A4F820PrimitiveArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) : A4F820Array<T>(uiMaxSize, uiGrowBy)
    {}
    virtual ~A4F820PrimitiveArray() throw();
};

class A4F820Controller
{
  public:
    A4F820Controller();
    virtual ~A4F820Controller();
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
};

class FUN_00a4f820 : public A4F820Controller
{
  public:
    FUN_00a4f820();
    virtual ~FUN_00a4f820();

    A4F820PrimitiveArray<char*> m_kNames;
    int m_iActive;
    int m_iArrayLength;
    int m_iFlags;
};

// @fnv 0x00a4f820
FUN_00a4f820::FUN_00a4f820() : m_kNames(1, 1)
{
    m_iActive = 0;
    m_iArrayLength = 0;
    m_iFlags = 0;
}

void* FUN_00aa1070(unsigned int uiSize);
void* FUN_00ec61c0(void* pDest, int iValue, int iCount);

struct FUN_00a6d220
{
    FUN_00a6d220();
    virtual void v00();
    int unk;
    int unkCur;
    int unk0c;
    int unkValue;
    int uNewnk;
    int uTmpnk;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
};

struct MapBase_a4d
{
    MapBase_a4d(unsigned int uiHashSize = 37)
    {
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        unsigned int uiSize = sizeof(void*) * m_uiHashSize;
        m_ppkHashTable = (void**)FUN_00aa1070(uiSize);
        FUN_00ec61c0(m_ppkHashTable, 0, m_uiHashSize * sizeof(void*));
    }
    virtual void v00();
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

struct MapMid_a4d : MapBase_a4d
{
    MapMid_a4d(unsigned int uiHashSize = 37) : MapBase_a4d(uiHashSize)
    {
        m_bCopy = false;
    }
    bool m_bCopy;
};

struct Map_a4d : MapMid_a4d
{
    Map_a4d(unsigned int uiHashSize = 37) : MapMid_a4d(uiHashSize)
    {}
    virtual void v00();
};

struct FUN_00a4da20_cls : FUN_00a6d220
{
    FUN_00a4da20_cls();
    virtual void v00();
    Map_a4d kMap;
};

// Default constructor for a class that embeds a Map_a4d, which initialises its hash table with the default size.
// @fnv 0x00a4da20
FUN_00a4da20_cls::FUN_00a4da20_cls()
{}

// NiFlipController::Update: advance the interpolator, round its value to a texture index, clamp it,
// and assign that texture to the affected map (regular map slot, or shader map at index - 0x400).
struct NiTextureF;
struct NiObjectNETF;
extern float DAT_01096324;         // NiTimeController::INVALID_TIME
extern const double DAT_01016408;  // 0.5
struct NiUpdateDataF
{
    float m_fTime;
};

struct NiInterpolatorF
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
    virtual bool Update(float fTime, NiObjectNETF* pkInterpTarget, float& fValue);
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
    virtual bool AlwaysUpdate() const;
};

struct MapF
{
    void SetTexture(NiTextureF* pkTexture);
};
struct ShaderMapArrayF
{
    void* m_vtbl;
    MapF** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short GetSize() const
    {
        return m_usSize;
    }
};
struct NiTexturingPropertyF
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void* m_aMapsVtbl;
    MapF** m_aMapsBase;
    unsigned short m_usMapsMax;
    unsigned short m_usMapsSize;
    int unk28;
    ShaderMapArrayF* m_pShaderMaps;
    MapF* GetShaderMap(unsigned int uiIndex) const;
    unsigned int GetShaderMapCount() const
    {
        return m_pShaderMaps ? m_pShaderMaps->GetSize() : 0;
    }
};

struct NiFlipControllerF
{
    void* m_vtbl;
    unsigned int m_uiRefCount;
    unsigned short m_uiObjectFlags;
    unsigned short unk0A;
    float m_fFrequency;
    float m_fPhase;
    float m_fLoKeyTime;
    float m_fHiKeyTime;
    float m_fStartTime;
    float m_fLastTime;
    float m_fWeightAdjustedLastTime;
    float m_fControllerTime;
    NiObjectNETF* m_pkTarget;
    void* m_spNextController;
    NiInterpolatorF* m_spControllerInterpolator;
    void* m_kTexturesVtbl;
    NiTextureF** m_kTexturesBase;
    unsigned short m_usTexturesMax;
    unsigned short m_usTexturesSize;
    unsigned short unk44;
    unsigned short unk46;
    unsigned int m_uiPosition;
    unsigned int m_eAffectedMap;

    unsigned short GetField(unsigned short uMask, unsigned short uPos) const
    {
        return (m_uiObjectFlags & uMask) >> uPos;
    }
    bool GetManagerControlled() const
    {
        return ((m_uiObjectFlags >> 5) & 1) ? true : false;
    }
    bool AdvanceController(float fTime);
    void UpdateFlipController(NiUpdateDataF& kUpdate);
};

// Advances the flip controller's interpolator and applies the resulting texture index to the target's affected map or shader map.
// @fnv 0x00a4f3a0
void NiFlipControllerF::UpdateFlipController(NiUpdateDataF& kUpdate)
{
    if (GetManagerControlled())
    {
        m_fControllerTime = DAT_01096324;
    }
    else if (AdvanceController(kUpdate.m_fTime) &&
             (!m_spControllerInterpolator || !m_spControllerInterpolator->AlwaysUpdate()))
    {
        return;
    }

    if (m_spControllerInterpolator)
    {
        float fValue;
        if (m_spControllerInterpolator->Update(m_fControllerTime, m_pkTarget, fValue))
        {
            unsigned int uiSize = m_usTexturesSize;
            m_uiPosition = (unsigned int)(fValue + DAT_01016408);
            if (m_uiPosition >= uiSize)
                m_uiPosition = uiSize - 1;

            NiTexturingPropertyF* pkProp = (NiTexturingPropertyF*)m_pkTarget;
            if (pkProp)
            {
                if (m_eAffectedMap < pkProp->m_usMapsSize && pkProp->m_aMapsBase[m_eAffectedMap])
                {
                    pkProp->m_aMapsBase[m_eAffectedMap]->SetTexture(m_kTexturesBase[m_uiPosition]);
                }
                else
                {
                    unsigned int uiShaderMapIndex = m_eAffectedMap - 0x400;
                    if (uiShaderMapIndex < pkProp->GetShaderMapCount() && pkProp->GetShaderMap(uiShaderMapIndex))
                    {
                        pkProp->GetShaderMap(uiShaderMapIndex)->SetTexture(m_kTexturesBase[m_uiPosition]);
                    }
                }
            }
        }
    }
}

void __cdecl NiFree(void* pkData) throw();
void __cdecl FUN_004b0220(void* pkData) throw();
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long* plCount);

struct F570RefObject
{
    virtual void v00() throw();
    virtual void DeleteThis() throw();
    long m_uiRefCount;
};

template <class T> struct F570Ptr
{
    T* m_p;

    ~F570Ptr() throw()
    {
        if (m_p)
        {
            F570RefObject* pkObject = m_p;
            if (InterlockedDecrement(&pkObject->m_uiRefCount) == 0)
                pkObject->DeleteThis();
        }
    }
};

struct F570Array
{
    virtual ~F570Array() throw()
    {
        FUN_004b0220(m_pBase);
    }

    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

struct F570Base
{
    virtual ~F570Base() throw();

    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    int m_unk30;
};

struct FUN_00a4f570 : F570Base
{
    virtual ~FUN_00a4f570() throw();

    F570Ptr<F570RefObject> m_sp34;
    F570Array m_kTextureSwapList;
    float m_f48;
    int m_i4C;
    void* m_pkBuf;
};

// Frees m_pkBuf with NiFree and clears the pointer to null.
// @fnv 0x00a4f570
FUN_00a4f570::~FUN_00a4f570() throw()
{
    NiFree(m_pkBuf);
    m_pkBuf = 0;
}

struct NiStream;
void __stdcall FUN_00a57c70(NiStream* stream);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long* lpAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long* lpAddend);

struct StreamIo
{
    void* m_00;
    unsigned int m_iFirstInteger;
    unsigned int(__cdecl* Transfer)(StreamIo*, const void*, unsigned int, unsigned int*, unsigned int);
    void Read4(const void* data)
    {
        unsigned int bytes = 4;
        unsigned int result = Transfer(this, data, 4, &bytes, 1);
        m_iFirstInteger += result;
    }
};

struct NiStream
{
    char m_000[0xd8];
    unsigned int m_d8;
    char m_dc[0x170];
    StreamIo* m_io;
    unsigned int __thiscall FUN_00a64670();
};

struct MemoryManager
{
    void* __thiscall Allocate(unsigned int size);
};
extern MemoryManager DAT_011f6238;

struct NiMemObject
{
    static void* operator new(unsigned int size);
    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};

struct FUN_00a5d3a0 : NiMemObject
{
    virtual void Virt0();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
    FUN_00a5d3a0() throw();
};

struct NiFloatData : FUN_00a5d3a0
{
    int m_08Count;
    void* m_0cKeys;
    int m_10Type;
    unsigned char m_14TypeByte;
    NiFloatData() throw()
    {
        m_08Count = 0;
        m_0cKeys = 0;
        m_10Type = 0;
        m_14TypeByte = 0;
    }
    void __thiscall FUN_00a3cdc0(void* keys, unsigned int count, int type);
};

struct NiFloatInterpolator : FUN_00a5d3a0
{
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    NiFloatInterpolator(NiFloatData* data) throw();
    virtual void Slot002();
    virtual void Slot003();
    virtual void Slot004();
    virtual void Slot005();
    virtual void Slot006();
    virtual void Slot007();
    virtual void Slot008();
    virtual void Slot009();
    virtual void Slot010();
    virtual void Slot011();
    virtual void Slot012();
    virtual void Slot013();
    virtual void Slot014();
    virtual void Slot015();
    virtual void Slot016();
    virtual void Slot017();
    virtual void Slot018();
    virtual void Slot019();
    virtual void Slot020();
    virtual void Slot021();
    virtual void Slot022();
    virtual void Slot023();
    virtual void Slot024();
    virtual void Slot025();
    virtual void Slot026();
    virtual void Slot027();
    virtual void Slot028();
    virtual void Slot029();
    virtual void Slot030();
    virtual void Slot031();
    virtual void Slot032();
    virtual void Slot033();
    virtual void Slot034();
    virtual void Slot035();
    virtual void Slot036();
    virtual void Slot037();
    virtual void Slot038();
    virtual void Slot039();
    virtual void Slot040();
    virtual void Slot041();
    virtual void Slot042();
    virtual void Slot043();
    virtual void Slot044();
    virtual void Slot045();
    virtual void Slot046();
    virtual void VirtBc();
};

struct KeyPair
{
    float t;
    float v;
    ~KeyPair();
};

void* operator new[](unsigned int size)
{
    return DAT_011f6238.Allocate(size);
}

struct CtrlA4F610
{
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    float m_14;
    float m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    NiFloatInterpolator* m_34Interp;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    void __thiscall LoadFromStream(NiStream* stream);
};

// Reads a float range and step from the stream, builds a NiFloatData key array and a NiFloatInterpolator, and stores it in m_34Interp.
// @fnv 0x00a4f610
void __thiscall CtrlA4F610::LoadFromStream(NiStream* stream)
{
    FUN_00a57c70(stream);
    stream->m_io->Read4(&m_4c);
    if (stream->m_d8 < 0x0a010068)
    {
        float fStart;
        float fStep;
        stream->m_io->Read4(&fStart);
        stream->m_io->Read4(&fStep);
        unsigned int count = stream->FUN_00a64670();
        NiFloatData* data = new NiFloatData();
        if (count > 0)
        {
            KeyPair* keys = new KeyPair[count + 1];
            float run = fStart;
            for (unsigned int i = 0; i < count; ++i)
            {
                keys[i].t = run;
                keys[i].v = (float)i;
                run += fStep;
            }
            keys[count].t = run;
            keys[count].v = (float)(count - 1);
            data->FUN_00a3cdc0(keys, count + 1, 5);
            m_14 = fStart;
            m_18 = run;
        }
        NiFloatInterpolator* interp = new NiFloatInterpolator(data);
        NiFloatInterpolator* pOldInterp = m_34Interp;
        if (pOldInterp != interp)
        {
            if (pOldInterp)
            {
                if (InterlockedDecrement(&pOldInterp->m_iObjectReferenceCount) == 0)
                    pOldInterp->DeleteThis();
            }
            m_34Interp = interp;
            if (interp)
                InterlockedIncrement(&interp->m_iObjectReferenceCount);
        }
        m_34Interp->VirtBc();
    }
    else
    {
        stream->FUN_00a64670();
    }
}

struct S00a4f8a0_Arr
{
    void __thiscall Grow(unsigned int n);
    void __thiscall Put(unsigned int i, void** slot);
    unsigned int unk00;
    void** unk04;
    unsigned short unk08;
    unsigned short unk0a;
    unsigned short unk0c;
    unsigned short unk0e;
};

struct FUN_00a4f8a0_Ref
{
    virtual void v0();
    virtual void Release();
    long m_iObjectReferenceCount;
};

struct FUN_00a4f8a0_Obj
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
    S00a4f8a0_Arr arr;
};

// Grows the array if needed, increments the reference count of p, stores a copy of p in the array slot, then decrements the count and releases if zero.
// @fnv 0x00a4f8a0
void __thiscall FlipCopy::FUN_00a4f8a0(void* apRef, unsigned int aiIndex)
{
    FUN_00a4f8a0_Obj* pObj = (FUN_00a4f8a0_Obj*)this;
    if (pObj->arr.unk0a <= aiIndex)
    {
        pObj->arr.Grow(aiIndex + 1);
    }
    FUN_00a4f8a0_Ref* pRef = (FUN_00a4f8a0_Ref*)apRef;
    apRef = pRef;
    void* slot = apRef;
    if (pRef != 0)
    {
        InterlockedIncrement(&pRef->m_iObjectReferenceCount);
    }
    S00a4f8a0_Arr* pArr = &pObj->arr;
    if (aiIndex >= pArr->unk08)
    {
        pArr->Grow(aiIndex + pArr->unk0e);
    }
    pArr->Put(aiIndex, &slot);
    if (pRef != 0)
    {
        if (InterlockedDecrement(&pRef->m_iObjectReferenceCount) == 0)
        {
            pRef->Release();
        }
    }
}

struct A4F990Stream
{
    unsigned int __thiscall FUN_00a63460() throw();
    F570RefObject* __thiscall FUN_00a63430() throw();
};

struct A4F990Array
{
    void __thiscall FUN_0060bef0(unsigned int uiSize) throw();
    void __thiscall FUN_0060c120(unsigned int uiIndex, F570RefObject* const& pkObj) throw();
};

struct A4F990Base
{
    void __thiscall FUN_00a57630(A4F990Stream& kStream) throw();
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
    void* unk2C;
    void* unk30;
    void* unk34;
    A4F990Array m_kTextureSwapList;
};

struct A4F990Flip : A4F990Base
{
    void __thiscall LinkObject(A4F990Stream& kStream) throw();
};

// Calls FUN_00a57630, then, when unk2C is nonnull, reads a count and stores that many F570RefObject pointers in m_kTextureSwapList.
// @fnv 0x00a4f990
void A4F990Flip::LinkObject(A4F990Stream& kStream) throw()
{
    FUN_00a57630(kStream);
    if (unk2C)
    {
        unsigned int uiSize = kStream.FUN_00a63460();
        m_kTextureSwapList.FUN_0060bef0(uiSize);
        for (unsigned int i = 0; i < uiSize; i++)
        {
            F570RefObject* pkTex = kStream.FUN_00a63430();
            F570RefObject* spTex = pkTex;
            if (pkTex)
                InterlockedIncrement(&pkTex->m_uiRefCount);
            m_kTextureSwapList.FUN_0060c120(i, spTex);
            if (pkTex)
            {
                if (InterlockedDecrement(&pkTex->m_uiRefCount) == 0)
                    pkTex->DeleteThis();
            }
        }
    }
}
