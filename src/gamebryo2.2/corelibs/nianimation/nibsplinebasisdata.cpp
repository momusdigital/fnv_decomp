// gamebryo2.2/corelibs/nianimation/nibsplinebasisdata.cpp: NiBSplineBasisData, SplineOwner (10 functions)

#include "nibsplinebasisdata_decls.h"

// Calls the base NiObject::LoadBinary, then reads a scalar from the stream into the basis data's field.
// @fnv 0x00a52c10
void NiBSplineBasisData::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    stream.m_pUnderlyingStream->ReadScalar(m_kBSplineBasis.m_iNumControlPoints);
}

struct FUN_00a52bb0_shell : public NiBSplineBasisData
{
    bool IsEqual(NiObject*);
};

bool __stdcall IsSameAs(NiObject* pkObject);

// @fnv 0x00a52bb0
bool FUN_00a52bb0_shell::IsEqual(NiObject* pkObject)
{
    if (!IsSameAs(pkObject))
        return false;

    return *(int*)((char*)pkObject + 8) == *(int*)((char*)this + 8);
}

extern int DAT_01099f24;
void __fastcall FUN_00a5d3d0(void* pThis);
void __cdecl FUN_00aa1460(void* pMem, unsigned int uiSize);

// @fnv 0x00a52be0
void* __fastcall FUN_00a52be0(void* pThis, int, unsigned char flags)
{
    *reinterpret_cast<int**>(pThis) = &DAT_01099f24;
    FUN_00a5d3d0(pThis);
    if (flags & 1)
    {
        FUN_00aa1460(pThis, 0x28);
    }
    return pThis;
}

struct GlobalObjectO2_00a7b610
{
    int x;
};
extern GlobalObjectO2_00a7b610 g_011f403c;
// @fnv 0x00a52af0
GlobalObjectO2_00a7b610* FUN_00a52af0()
{
    return &g_011f403c;
}

namespace fnv_00a52c90 {
struct ActorCombatGroup;
extern int g_011f403c;
void __stdcall AppendCameraPathEntries(void*);
ActorCombatGroup* __cdecl FUN_00a7d330(int);
struct ArrX
{
    void SetSize(unsigned);
    void SetAt(unsigned, ActorCombatGroup*&);
    unsigned char pad[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
// @fnv 0x00a52c90
void __stdcall GetViewerStrings(ArrX* pArray)
{
    AppendCameraPathEntries(pArray);
    ActorCombatGroup* pObject = FUN_00a7d330(g_011f403c);
    unsigned n = pArray->m_usSize;
    if (n >= pArray->m_usMaxSize)
        pArray->SetSize(n + pArray->m_usGrowBy);
    pArray->SetAt(n, pObject);
}
}  // namespace fnv_00a52c90

extern int DAT_01099d3c;

struct FUN_00a51ab0_base
{
    void InitBase(int a1, int a3);
};

struct FUN_00a51ab0_cls : FUN_00a51ab0_base
{
    int m_vptr00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    int m_2c;

    FUN_00a51ab0_cls* FUN_00a51ab0(int a1, int a2, int a3);
};

// Calls InitBase, sets the vtable pointer, zeroes four floats and stores a2 into m_2c, then returns this.
// @fnv 0x00a51ab0
FUN_00a51ab0_cls* FUN_00a51ab0_cls::FUN_00a51ab0(int a1, int a2, int a3)
{
    InitBase(a1, a3);
    m_vptr00 = (int)&DAT_01099d3c;
    *(volatile float*)&m_1c = 0.0f;
    m_20 = 0.0f;
    m_24 = 0.0f;
    m_28 = 0.0f;
    *(volatile int*)&m_2c = a2;
    return this;
}

extern float DAT_01012054;
void* __cdecl FUN_00aa13e0(unsigned int uiSize);

class SplineBase
{
  public:
    SplineBase() throw();
    virtual ~SplineBase() throw();
    unsigned int unk04;
};

struct SplineBlock
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    float m_14;
    unsigned int m_18;
    unsigned int m_1c;
};

class SplineObj : public SplineBase
{
  public:
    SplineObj()
    {
        *(volatile float*)&m_08.m_14 = -1.0f;
        m_08.m_00 = 0;
        m_08.m_18 = 0;
        m_08.m_1c = 3;
    }
    virtual ~SplineObj() throw();
    static void* operator new(unsigned int n) throw()
    {
        return FUN_00aa13e0(n);
    }
    SplineBlock m_08;
};

struct SplineOwner
{
    unsigned int unk00;
    unsigned int unk04;
    SplineBlock m_08;
    void CreateVertexBufferSet(SplineObj* pObj, unsigned char flags);
    SplineObj* CreateSplineObj(unsigned char flags);
};

// @fnv 0x00a52b00
SplineObj* SplineOwner::CreateSplineObj(unsigned char flags)
{
    SplineObj* pResult = new SplineObj;
    CreateVertexBufferSet(pResult, flags);
    pResult->m_08 = m_08;
    return pResult;
}

void* __cdecl FUN_00aa13e0(unsigned int uiSize);

class NiSplineBase
{
  public:
    NiSplineBase();
    virtual ~NiSplineBase();
    static void* operator new(unsigned int uiSize)
    {
        return FUN_00aa13e0(uiSize);
    }
    static void operator delete(void*)
    {}
    unsigned int m_uiRefCount;
};

template <class T, int Degree> class NiBSplineBasisT
{
  public:
    NiBSplineBasisT() : m_iNumControlPoints(0), m_fLastTime(-1.0f), m_iMinControlPoint(0), m_iMaxControlPoint(3)
    {}
    int m_iNumControlPoints;
    T m_afWeights[Degree + 1];
    T m_fLastTime;
    int m_iMinControlPoint;
    int m_iMaxControlPoint;
};

class NiSplineImpl : public NiSplineBase
{
  public:
    NiSplineImpl() throw()
    {}
    virtual ~NiSplineImpl();
    NiBSplineBasisT<float, 3> m_kBasis;
};

// Allocates and constructs a NiSplineImpl via its operator new and returns the new object.
// @fnv 0x00a52b60
NiSplineImpl* CreateNiSplineImpl()
{
    return new NiSplineImpl;
}

class NiStreamSave : public NiStream
{
  public:
    NiBinaryStream* m_pBackingStream;
};
template <class T> inline void WriteScalar(NiBinaryStream* pkOstr, const T& value)
{
    unsigned int componentSize = sizeof(T);
    unsigned int bytesWritten = pkOstr->m_pfnWrite(pkOstr, &value, sizeof(T), &componentSize, 1);
    pkOstr->m_uiStreamFlags += bytesWritten;
}
class FUN_00a52c50_BasisData : public NiObject
{
  public:
    BSplineBasis<float, 3> m_kBSplineBasis;
    void SaveBinaryBase(NiStream& stream);
    void SaveBinary(NiStream& stream);
};

// Saves the base NiObject data and the BSplineBasis control point count to the given NiStream.
// @fnv 0x00a52c50
void FUN_00a52c50_BasisData::SaveBinary(NiStream& stream)
{
    SaveBinaryBase(stream);
    WriteScalar(static_cast<NiStreamSave&>(stream).m_pBackingStream, m_kBSplineBasis.m_iNumControlPoints);
}

extern int DAT_0109a2a4;
void* NiMalloc(unsigned int size);

struct FUN_00a54190_cls
{
    int m_vt;
    void* m_04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short m_0c;
    unsigned short m_0e;
    FUN_00a54190_cls* FUN_00a54190(int n, short a2);
};

// Sets object fields and allocates 4 times m_08 bytes when m_08 is positive.
// @fnv 0x00a54190
FUN_00a54190_cls* FUN_00a54190_cls::FUN_00a54190(int n, short a2)
{
    m_vt = (int)&DAT_0109a2a4;
    m_08 = n;
    m_0e = a2;
    m_0a = 0;
    m_0c = 0;
    if (m_08 > 0)
    {
        unsigned int sz = m_08;
        m_04 = NiMalloc(sz * 4);
    }
    else
    {
        m_04 = 0;
    }
    return this;
}
