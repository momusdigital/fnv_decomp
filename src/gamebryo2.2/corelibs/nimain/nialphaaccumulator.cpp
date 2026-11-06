// gamebryo2.2/corelibs/nimain/nialphaaccumulator.cpp: NiAlphaAccumulator, CloneAccumulator (17 functions)

#include "nialphaaccumulator_decls.h"

// Constructs the accumulator: sets the vtable pointer and zeroes the list count, head, tail and the remaining members.
// @fnv 0x00aa0f00
NiAlphaAccumulator::NiAlphaAccumulator()
{
    *(volatile unsigned int*)this = (unsigned int)&kVtbl_NiBackToFrontAccumulator;
    m_kUnsortedGeometryList.m_kItemCount.m_uiCount = 0;
    m_kUnsortedGeometryList.m_pkHead = 0;
    m_kUnsortedGeometryList.m_pkTail = 0;
    m_pkGeometryList = 0;
    m_iGeometryCount = 0;
    m_iGeometryCapacity = 0;
    m_ppGeometries = 0;
    m_pfGeometrySortValues = 0;
}

extern float DAT_01096b8c;
extern int EmptyFS;
extern int DAT_011a8400;
extern int DAT_011a8404;
extern int DAT_011a8408;
extern int DAT_011f3704;
extern int DAT_011f3708;
extern int DAT_011f370c;
extern int DAT_011f3710;

struct DummyObj
{
    int f00, f04, f08;
    int f0c, f10, f14, f18;
    float f1c;
    int f20, f24, f28;
    int f2c, f30, f34, f38;
    float f3c;
    int f40;
};

// @fnv 0x00a433b0
DummyObj* __fastcall InitFromGlobals(DummyObj* pThis)
{
    pThis->f00 = DAT_011a8400;
    pThis->f04 = DAT_011a8404;
    pThis->f08 = DAT_011a8408;
    pThis->f0c = DAT_011f3704;
    pThis->f10 = DAT_011f3708;
    pThis->f14 = DAT_011f370c;
    pThis->f18 = DAT_011f3710;
    pThis->f1c = DAT_01096b8c;
    pThis->f20 = DAT_011a8400;
    pThis->f24 = DAT_011a8404;
    pThis->f28 = DAT_011a8408;
    pThis->f2c = DAT_011f3704;
    pThis->f30 = DAT_011f3708;
    pThis->f34 = DAT_011f370c;
    pThis->f38 = DAT_011f3710;
    pThis->f3c = DAT_01096b8c;
    pThis->f40 = EmptyFS;
    return pThis;
}

struct FUN_00a43350_shell
{
    unsigned int GetKeyContent(unsigned short usChannel);
};
// @fnv 0x00a43350
unsigned int FUN_00a43350_shell::GetKeyContent(unsigned short usChannel)
{
    return usChannel ? 6 : 0;
}

struct GlobalObjectO2_00a7b610
{
    char c;
};
extern GlobalObjectO2_00a7b610 g_011f3ed8;
// Returns the address of the global object g_011f3ed8.
// @fnv 0x00a43360
GlobalObjectO2_00a7b610* __cdecl FUN_00a43360()
{
    return &g_011f3ed8;
}

struct FUN_00a43450_fs
{
    char* pszString;
};
struct FUN_00a43450_stream
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void RegisterFixedString(FUN_00a43450_fs* kString);
};
struct FUN_00a43450_data
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual bool RegisterStreamables(FUN_00a43450_stream& kStream);
};
struct FUN_00a43450_link
{
    char pad[0x40];
    FUN_00a43450_fs kName;
};
struct FUN_00aa0ad0_base
{
    bool FUN_00aa0ad0(FUN_00a43450_stream* arStream);
};
struct FUN_00a43450_shell : FUN_00aa0ad0_base
{
    char pad[0xc - 1];
    FUN_00a43450_link* Links;
    unsigned int m_uiLinkCount;
    char pad2[0x20 - 0x14];
    FUN_00a43450_data* m_pData;
    bool FUN_00a43450(FUN_00a43450_stream* arStream);
};
// Calls the base register, then registers each link's name string and the data object's streamables with the stream; returns the base result.
// @fnv 0x00a43450
bool FUN_00a43450_shell::FUN_00a43450(FUN_00a43450_stream* arStream)
{
    bool bret = FUN_00aa0ad0(arStream);
    if (bret)
    {
        for (unsigned int ui = 0; ui < m_uiLinkCount; ui++)
            arStream->RegisterFixedString(&Links[ui].kName);
        FUN_00a43450_data* pkLerp = m_pData;
        if (pkLerp)
            pkLerp->RegisterStreamables(*arStream);
    }
    return bret;
}

struct NiObject;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_00a9b510_shell : public NiAlphaAccumulator
{
    bool FUN_00a9b510(NiObject*);
};

struct FUN_00aa0ae0_stub
{
    char FUN_00aa0ae0(NiObject* pkObject);
};
// @fnv 0x00a9b510
bool FUN_00a9b510_shell::FUN_00a9b510(NiObject* pkObject)
{
    bool b = ((FUN_00aa0ae0_stub*)this)->FUN_00aa0ae0(pkObject) != 0;
    return b;
}

struct FUN_00a9b530_shell : public NiAlphaAccumulator
{
    void* GetRTTI();
};

extern const char* const g_011fa000_arg1;
// @fnv 0x00a9b530
void* FUN_00a9b530_shell::GetRTTI()
{
    return (void*)&g_011fa000_arg1;
}

void* __cdecl FUN_00aa13e0(unsigned int);

struct Base0_a43370
{
    virtual void v0();
    int unk04;
    int unk08;
    Base0_a43370() throw();
};

struct Base1_a43370 : Base0_a43370
{
    int unk0c;
    int unk10;
    float unk14;
    float unk18;
    int unk1c;
    Base1_a43370() throw() : unk0c(0), unk10(0), unk14(0.0f), unk18(0.0f), unk1c(0)
    {}
};

struct Ptr_a43370
{
    void* p;
    Ptr_a43370() throw() : p(0)
    {}
};

struct Derived_a43370 : Base1_a43370
{
    Ptr_a43370 unk20;
    Derived_a43370() throw()
    {}
    static void* __cdecl operator new(unsigned int s) throw()
    {
        return FUN_00aa13e0(s);
    }
};

// Allocates and default-constructs a Derived_a43370 object via its operator new and returns the pointer.
// @fnv 0x00a43370
Derived_a43370* __cdecl CreateDerivedA43370()
{
    return new Derived_a43370();
}

extern int DAT_011f4748;

struct FUN_00b58570_Class
{
    void* __thiscall FUN_00b58570(void* arg);
};

struct FUN_00a9b850_Prop
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    union
    {
        unsigned char unk18;
        unsigned short unk18w;
    };
};

struct FUN_00a9b850_Obj
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00C();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01C();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02C();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03C();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04C();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05C();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06C();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07C();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08C();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09C();
    virtual void vfn_0A0();
    virtual void vfn_0A4();
    virtual void vfn_0A8();
    virtual void vfn_0AC();
    virtual void vfn_0B0();
    virtual void vfn_0B4();
    virtual void vfn_0B8();
    virtual void vfn_0BC();
    virtual void vfn_0C0();
    virtual void vfn_0C4();
    virtual void vfn_0C8();
    virtual void vfn_0CC();
    virtual void vfn_0D0();
    virtual void vfn_0D4();
    virtual void vfn_0D8();
    virtual void vfn_0DC(int arg);
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
    unsigned int unk30;
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
    FUN_00a9b850_Prop* m9c;
};

struct FUN_00a9b850_shell : public NiAlphaAccumulator
{
    bool FUN_00a9b850(FUN_00a9b850_Obj* a1);
};

// @fnv 0x00a9b850
bool FUN_00a9b850_shell::FUN_00a9b850(FUN_00a9b850_Obj* pObject)
{
    FUN_00a9b850_Prop* p = pObject->m9c;
    int g = DAT_011f4748;
    if ((p->unk18 & 1) && (!m_bSkipObjectsWithFlag13 || !((unsigned char)(p->unk18w >> 13) & 1)) &&
        ((unsigned char)~(pObject->unk30 >> 6) & 1))
    {
        reinterpret_cast<FUN_00b58570_Class*>(&m_kUnsortedGeometryList)->FUN_00b58570(&pObject);
        return true;
    }
    pObject->vfn_0DC(g);
    return true;
}

void FUN_00a95ca0();
// @fnv 0x00a43330
void FUN_00a43330()
{
    FUN_00a95ca0();
}

struct C8CCC0Base
{
    bool IsEqual(const C8CCC0Base&) const;
};
struct FUN_00a43340 : C8CCC0Base
{
    bool IsEqual(const FUN_00a43340&);
};
// @fnv 0x00a43340
bool FUN_00a43340::IsEqual(const FUN_00a43340& apObject)
{
    return C8CCC0Base::IsEqual(apObject);
}

void __cdecl FUN_00aa0ac0();
// @fnv 0x00a9b4f0
void __cdecl FUN_00a9b4f0()
{
    FUN_00aa0ac0();
}

void __cdecl FUN_00aa0ad0();
// @fnv 0x00a9b500
void __cdecl FUN_00a9b500()
{
    FUN_00aa0ad0();
}

struct S00a9b570_Pt
{
    float x, y, z;
};
struct S00a9b570_Bound
{
    S00a9b570_Pt m_kCenter;
    float m_fBoundRadius;
};
extern S00a9b570_Bound DAT_011f4288;
void __cdecl FUN_00aa10f0(void* p);
void* __cdecl FUN_00aa1070(unsigned int n);

inline float S00a9b570_Dot(const S00a9b570_Pt& a, const S00a9b570_Pt& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline float S00a9b570_Closest(const float& r, const S00a9b570_Pt& c, const S00a9b570_Pt& d)
{
    return S00a9b570_Dot(c, d) - r;
}

struct S00a9b570_Mat
{
    float m_afEntries[3][3];
    void GetCol(unsigned int c, S00a9b570_Pt& p) const
    {
        p.x = m_afEntries[0][c];
        p.y = m_afEntries[1][c];
        p.z = m_afEntries[2][c];
    }
};

struct S00a9b570_Cam
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
    S00a9b570_Mat m_kRotate;
    S00a9b570_Pt GetWorldTranslation() const
    {
        S00a9b570_Pt d;
        m_kRotate.GetCol(0, d);
        return d;
    }
};

struct S00a9b570_Geom
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    S00a9b570_Bound* volatile m_pkBound;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    int unk84, unk88, unk8c;
    float m_fFogDepth;
    const S00a9b570_Bound& GetBoundingVolume() const
    {
        const S00a9b570_Bound* p = m_pkBound;
        return p ? *p : DAT_011f4288;
    }
};

struct S00a9b570_Node
{
    S00a9b570_Node* m_pkNext;
    S00a9b570_Node* m_pkPrev;
    S00a9b570_Geom* m_element;
};

struct S00a9b570_List
{
    S00a9b570_Node* m_pkHead;
    S00a9b570_Node* m_pkTail;
    unsigned int m_uiCount;
    S00a9b570_Node* GetHeadPos() const
    {
        return m_pkHead;
    }
    unsigned int GetSize() const
    {
        return m_uiCount;
    }
    S00a9b570_Geom* const& GetNext(S00a9b570_Node*& pos) const
    {
        S00a9b570_Geom* const& e = pos->m_element;
        pos = pos->m_pkNext;
        return e;
    }
};

struct S00a9b570_Acc
{
    unsigned int unk00;
    unsigned int unk04;
    S00a9b570_Cam* m_pkAccumulationCamera;
    S00a9b570_List m_kUnsortedGeometryList;
    S00a9b570_List* m_pkList;
    int m_iGeometryCount;
    int m_iGeometryCapacity;
    S00a9b570_Geom** m_ppGeometries;
    float* m_pfGeometrySortValues;
    int m_iCurrentItem;
    bool m_bSkipObjectsWithFlag13;
    bool m_bSkipObjectsWithFlag14;
    bool m_bInterface;

    void Sort();
    void FUN_00aa0b40(int start, int finish);
};

// @fnv 0x00a9b570
void S00a9b570_Acc::Sort()
{
    if (!m_pkList)
        m_pkList = &m_kUnsortedGeometryList;
    m_iGeometryCount = m_pkList->GetSize();
    if (m_iGeometryCount == 0)
        return;
    if (m_iGeometryCount > m_iGeometryCapacity)
    {
        FUN_00aa10f0(m_ppGeometries);
        m_iGeometryCapacity = m_iGeometryCount;
        m_ppGeometries = (S00a9b570_Geom**)FUN_00aa1070(m_iGeometryCapacity * sizeof(S00a9b570_Geom*));
        FUN_00aa10f0(m_pfGeometrySortValues);
        m_pfGeometrySortValues = (float*)FUN_00aa1070(m_iGeometryCapacity * sizeof(float));
    }
    S00a9b570_Node* kPos = m_pkList->GetHeadPos();
    S00a9b570_Pt kViewDir = m_pkAccumulationCamera->GetWorldTranslation();
    int i;
    if (m_bInterface)
    {
        for (i = 0; i < m_iGeometryCount; i++)
        {
            m_ppGeometries[i] = m_pkList->GetNext(kPos);
            m_pfGeometrySortValues[i] = m_ppGeometries[i]->m_fFogDepth;
        }
    }
    else if (m_bSkipObjectsWithFlag14)
    {
        for (i = 0; i < m_iGeometryCount; i++)
        {
            m_ppGeometries[i] = m_pkList->GetNext(kPos);
            S00a9b570_Geom* g = m_ppGeometries[i];
            m_pfGeometrySortValues[i] =
                S00a9b570_Closest(g->GetBoundingVolume().m_fBoundRadius, g->GetBoundingVolume().m_kCenter, kViewDir);
        }
    }
    else
    {
        for (i = 0; i < m_iGeometryCount; i++)
        {
            m_ppGeometries[i] = m_pkList->GetNext(kPos);
            m_pfGeometrySortValues[i] = S00a9b570_Dot(m_ppGeometries[i]->GetBoundingVolume().m_kCenter, kViewDir);
        }
    }
    FUN_00aa0b40(0, m_iGeometryCount - 1);
}

struct DelS
{
    static void operator delete(void*, unsigned int);
};
struct FUN_00aa0dc0 : DelS
{
    char pad[0x30];
    virtual ~FUN_00aa0dc0();
};
struct FUN_00a9b540 : FUN_00aa0dc0
{
    virtual ~FUN_00a9b540();
};
// @fnv 0x00a9b540
FUN_00a9b540::~FUN_00a9b540()
{}

namespace fnv_00a9b790 {
class NiRenderer;
extern NiRenderer* DAT_011f4748;

struct S00a9b790_Node
{
    S00a9b790_Node* m_pkNext;
    S00a9b790_Node* m_pkPrev;
    void* m_element;
};

struct S00a9b790_NodeAllocator
{
    S00a9b790_Node* FUN_0043a010();
};

class S00a9b790_NiAlphaProperty
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short m_uiObjectFlags;
    bool GetAlphaBlending() const
    {
        return (m_uiObjectFlags & 1) != 0;
    }
    bool GetNoSorter() const
    {
        return ((m_uiObjectFlags >> 13) & 1) != 0;
    }
};

class S00a9b790_NiGeometry
{
  public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void RenderImmediate(NiRenderer* pkRenderer);

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
    unsigned int m_uiObjectFlags;
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
    S00a9b790_NiAlphaProperty* m_pkAlpha;

    bool GetSortObject() const
    {
        return !((m_uiObjectFlags >> 6) & 1);
    }
    const S00a9b790_NiAlphaProperty* GetAlpha() const
    {
        return m_pkAlpha;
    }
};

class S00a9b790_NiVisibleArray
{
  public:
    S00a9b790_NiGeometry** m_ppSavableObjects;
    unsigned int m_uiNextBlockSize;
    unsigned int GetCount() const
    {
        return m_uiNextBlockSize;
    }
    S00a9b790_NiGeometry& GetAt(unsigned int i) const
    {
        return *m_ppSavableObjects[i];
    }
};

class S00a9b790_VNiAccumulator
{
  public:
    unsigned int m_layout0;
    unsigned int m_layout4;
    void* m_pkAccumulationCamera;
};

class S00a9b790_VNiBackToFrontAccumulator : public S00a9b790_VNiAccumulator
{
  public:
    struct ItemList
    {
        S00a9b790_Node* m_pkHead;
        S00a9b790_Node* m_pkTail;
        struct Allocator
        {
            unsigned int m_uiCount;
        } m_kItemCount;
    } m_kUnsortedGeometryList;
    ItemList* m_pkGeometryList;
    int m_iGeometryCount;
    int m_iGeometryCapacity;
    void** m_ppGeometries;
    float* m_pfGeometrySortValues;
    int m_iCurrentItem;
};

class S00a9b790_VNiAlphaAccumulator : public S00a9b790_VNiBackToFrontAccumulator
{
  public:
    bool m_bSkipObjectsWithFlag13;
    bool m_bSkipObjectsWithFlag14;
    bool m_bInterface;
    unsigned char m_padding33;

    void AddTail(S00a9b790_NiGeometry* pkObject)
    {
        S00a9b790_Node* pkNode = ((S00a9b790_NodeAllocator*)&m_kUnsortedGeometryList.m_kItemCount)->FUN_0043a010();
        pkNode->m_element = pkObject;
        pkNode->m_pkNext = 0;
        pkNode->m_pkPrev = m_kUnsortedGeometryList.m_pkTail;
        S00a9b790_Node* pkTail = m_kUnsortedGeometryList.m_pkTail;
        if (pkTail)
            pkTail->m_pkNext = pkNode;
        else
            m_kUnsortedGeometryList.m_pkHead = pkNode;
        m_kUnsortedGeometryList.m_kItemCount.m_uiCount++;
        m_kUnsortedGeometryList.m_pkTail = pkNode;
    }
    __forceinline void Body(S00a9b790_NiVisibleArray& kArray);
};

void S00a9b790_VNiAlphaAccumulator::Body(S00a9b790_NiVisibleArray& kArray)
{
    NiRenderer* pkRenderer = DAT_011f4748;
    const unsigned int uiQuantity = kArray.GetCount();
    for (unsigned int i = 0; i < uiQuantity; i++)
    {
        S00a9b790_NiGeometry& kObject = kArray.GetAt(i);
        const S00a9b790_NiAlphaProperty* pkAlpha = kObject.GetAlpha();
        if (pkAlpha->GetAlphaBlending() && !(m_bSkipObjectsWithFlag13 && pkAlpha->GetNoSorter()) &&
            kObject.GetSortObject())
        {
            AddTail(&kObject);
        }
        else
        {
            kObject.RenderImmediate(pkRenderer);
        }
    }
}

struct S00a9b790_Acc : NiAlphaAccumulator
{
    void FUN_00a9b790(S00a9b790_NiVisibleArray& kArray);
};
// @fnv 0x00a9b790
void S00a9b790_Acc::FUN_00a9b790(S00a9b790_NiVisibleArray& kArray)
{
    ((S00a9b790_VNiAlphaAccumulator*)this)->Body(kArray);
}
}  // namespace fnv_00a9b790

struct NiObject;
struct CloningProcess;
extern unsigned int kVtbl_NiAlphaAccumulator;
struct CloneBaseInitializer
{
    void FUN_00aa0f00();
};
struct CloneCopyHelper
{
    void FUN_00aa0ab0(void*, CloningProcess*);
};
struct CloneAccumulator : NiAlphaAccumulator
{
    NiObject* CreateClone(CloningProcess*);
};

// Allocates a NiAlphaAccumulator clone, initializes it, copies skip flags, and returns the new object.
// @fnv 0x00a9b730
NiObject* CloneAccumulator::CreateClone(CloningProcess* cloning)
{
    NiAlphaAccumulator* clone = (NiAlphaAccumulator*)FUN_00aa13e0(sizeof(NiAlphaAccumulator));
    if (clone)
    {
        ((CloneBaseInitializer*)clone)->FUN_00aa0f00();
        clone->m_layout0 = (unsigned int)&kVtbl_NiAlphaAccumulator;
        clone->m_bSkipObjectsWithFlag13 = true;
        clone->m_bSkipObjectsWithFlag14 = false;
        clone->m_bInterface = false;
    }
    else
    {
        clone = 0;
    }
    ((CloneCopyHelper*)this)->FUN_00aa0ab0(clone, cloning);
    clone->m_bSkipObjectsWithFlag13 = m_bSkipObjectsWithFlag13;
    clone->m_bSkipObjectsWithFlag14 = m_bSkipObjectsWithFlag14;
    return (NiObject*)clone;
}
