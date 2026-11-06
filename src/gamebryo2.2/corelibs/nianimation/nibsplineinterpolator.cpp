// gamebryo2.2/corelibs/nianimation/nibsplineinterpolator.cpp: SplineShell, NiBSplineInterpolator (10 functions)

#include "nibsplineinterpolator_decls.h"
// Loads the interpolator base data, reads start and end times from the stream, and assigns both spline objects from the stream.
// @fnv 0x00a58080
void NiBSplineInterpolator::LoadBinary(NiStream& stream)
{
    NiInterpolator::LoadBinary(stream);
    stream.input->ReadFloat(m_fStartTime);
    stream.input->ReadFloat(m_fEndTime);
    AssignSplineObject(m_spTransformData, stream.DeserializeObject());
    AssignSplineObject(m_spSplineBasisData, stream.DeserializeObject());
}

struct FUN_00a57f70_shell : public NiBSplineInterpolator
{
    void* GetRTTI();
};

extern "C" const char* g_011f3fe4_arg1;

// @fnv 0x00a57f70
void* FUN_00a57f70_shell::GetRTTI()
{
    return &g_011f3fe4_arg1;
}

struct BaseThunk
{
    bool FUN_00a81fe0(NiStream&);
};
struct ThunkReg
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void RegisterStreamables(NiStream&);
};
struct FUN_00a57e50_shell : public NiBSplineInterpolator
{
    bool LoadNiBSplineInterpolator(NiStream&);
};
// @fnv 0x00a57e50
bool FUN_00a57e50_shell::LoadNiBSplineInterpolator(NiStream& kStream)
{
    if (!((BaseThunk*)this)->FUN_00a81fe0(kStream))
        return false;
    ThunkReg* pFirstStreamable = *(ThunkReg**)&m_spTransformData;
    if (pFirstStreamable)
        pFirstStreamable->RegisterStreamables(kStream);
    ThunkReg* pSecondStreamable = *(ThunkReg**)&m_spSplineBasisData;
    if (pSecondStreamable)
        pSecondStreamable->RegisterStreamables(kStream);
    return true;
}

void __fastcall FUN_00a57f80(void*);
void __cdecl _delete(void*, unsigned int);
struct FUN_00a581e0_shell
{
    void* FUN_00a581e0(unsigned int);
};
// Calls FUN_00a57f80 on this, deletes this with size 0x1c when bit 0 of a1 is set, and returns this.
// @fnv 0x00a581e0
void* FUN_00a581e0_shell::FUN_00a581e0(unsigned int auiFlags)
{
    FUN_00a57f80(this);
    if (auiFlags & 1)
        _delete(this, 0x1c);
    return this;
}

extern double DAT_010231b0;
extern double DAT_010241b0;
struct FUN_00a57d60_holder
{
    char _pad[12];
    float _st;
    float _en;
    void GetActiveTimeRange(float&, float&);
};
// @fnv 0x00a57d60
void FUN_00a57d60_holder::GetActiveTimeRange(float& fBegin, float& m_fEndValue)
{
    if (fBegin == DAT_010231b0 && m_fEndValue == DAT_010241b0)
        m_fEndValue = fBegin = 0.0f;
    else
    {
        fBegin = _st;
        m_fEndValue = _en;
    }
}

class FUN_00a57da0_cls
{
  public:
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
    virtual int v56(int a);
    virtual int v57(int a);
    virtual void v58();
    virtual void v59();
    virtual bool v60();

    int FUN_00a57da0(int a1);
};

// Returns the product of v57(a1) and v56(a1), doubled when v60() is true and quadrupled otherwise.
// @fnv 0x00a57da0
int FUN_00a57da0_cls::FUN_00a57da0(int a1)
{
    if (v60())
    {
        return v57(a1) * v56(a1) * 2;
    }
    return v57(a1) * v56(a1) * 4;
}

struct SplineShell : public NiBSplineInterpolator
{
    virtual int v00();
    virtual int v01();
    virtual int v02();
    virtual int v03();
    virtual int v04();
    virtual int v05();
    virtual int v06();
    virtual int v07();
    virtual int v08();
    virtual int v09();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54();
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59(int param);
    virtual int v60();
    int FUN_00a57e00(int param);
};

int SplineShell::v00()
{
    return 0;
}
int SplineShell::v01()
{
    return 0;
}
int SplineShell::v02()
{
    return 0;
}
int SplineShell::v03()
{
    return 0;
}
int SplineShell::v04()
{
    return 0;
}
int SplineShell::v05()
{
    return 0;
}
int SplineShell::v06()
{
    return 0;
}
int SplineShell::v07()
{
    return 0;
}
int SplineShell::v08()
{
    return 0;
}
int SplineShell::v09()
{
    return 0;
}
int SplineShell::v10()
{
    return 0;
}
int SplineShell::v11()
{
    return 0;
}
int SplineShell::v12()
{
    return 0;
}
int SplineShell::v13()
{
    return 0;
}
int SplineShell::v14()
{
    return 0;
}
int SplineShell::v15()
{
    return 0;
}
int SplineShell::v16()
{
    return 0;
}
int SplineShell::v17()
{
    return 0;
}
int SplineShell::v18()
{
    return 0;
}
int SplineShell::v19()
{
    return 0;
}
int SplineShell::v20()
{
    return 0;
}
int SplineShell::v21()
{
    return 0;
}
int SplineShell::v22()
{
    return 0;
}
int SplineShell::v23()
{
    return 0;
}
int SplineShell::v24()
{
    return 0;
}
int SplineShell::v25()
{
    return 0;
}
int SplineShell::v26()
{
    return 0;
}
int SplineShell::v27()
{
    return 0;
}
int SplineShell::v28()
{
    return 0;
}
int SplineShell::v29()
{
    return 0;
}
int SplineShell::v30()
{
    return 0;
}
int SplineShell::v31()
{
    return 0;
}
int SplineShell::v32()
{
    return 0;
}
int SplineShell::v33()
{
    return 0;
}
int SplineShell::v34()
{
    return 0;
}
int SplineShell::v35()
{
    return 0;
}
int SplineShell::v36()
{
    return 0;
}
int SplineShell::v37()
{
    return 0;
}
int SplineShell::v38()
{
    return 0;
}
int SplineShell::v39()
{
    return 0;
}
int SplineShell::v40()
{
    return 0;
}
int SplineShell::v41()
{
    return 0;
}
int SplineShell::v42()
{
    return 0;
}
int SplineShell::v43()
{
    return 0;
}
int SplineShell::v44()
{
    return 0;
}
int SplineShell::v45()
{
    return 0;
}
int SplineShell::v46()
{
    return 0;
}
int SplineShell::v47()
{
    return 0;
}
int SplineShell::v48()
{
    return 0;
}
int SplineShell::v49()
{
    return 0;
}
int SplineShell::v50()
{
    return 0;
}
int SplineShell::v51()
{
    return 0;
}
int SplineShell::v52()
{
    return 0;
}
int SplineShell::v53()
{
    return 0;
}
int SplineShell::v54()
{
    return 0;
}
int SplineShell::v55()
{
    return 0;
}
int SplineShell::v56()
{
    return 0;
}
int SplineShell::v57()
{
    return 0;
}
int SplineShell::v58()
{
    return 0;
}
int SplineShell::v59(int param)
{
    return 0;
}
int SplineShell::v60()
{
    return 0;
}

struct Basis
{
    void* FUN_00a62660();
};

// @fnv 0x00a57e00
int __thiscall SplineShell::FUN_00a57e00(int param)
{
    int r0 = this->v52();
    if ((unsigned short)param < (unsigned short)r0)
    {
        if (this->m_spTransformData != 0)
        {
            int r1 = this->v59(param);
            if (r1 != 0xffff)
            {
                void* p = ((Basis*)this->m_spSplineBasisData)->FUN_00a62660();
                return *(int*)p;
            }
        }
    }
    return 0;
}

class A57E90Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2C();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3C();
    virtual void vfunc40();
    virtual void vfunc44();
    virtual void vfunc48();
    virtual void vfunc4C();
    virtual void vfunc50();
    virtual void vfunc54();
    virtual void vfunc58();
    virtual bool IsEqual(A57E90Object* pkObject);
};

template <class T> struct A57E90Pointer
{
    T* m_pObject;

    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

class A57E90Controller : public A57E90Object
{
  public:
    bool BaseIsEqual(A57E90Object* pkObject);
    bool FUN_00a57e90(A57E90Object* pkObject);

    int unk04;
    int unk08;
    float m_fLow;
    float m_fHigh;
    A57E90Pointer<A57E90Object> m_spInterpA;
    A57E90Pointer<A57E90Object> m_spInterpB;
};

// @fnv 0x00a57e90
bool A57E90Controller::FUN_00a57e90(A57E90Object* pkObject)
{
    if (!BaseIsEqual(pkObject))
        return false;
    A57E90Controller* pkOther = (A57E90Controller*)pkObject;
    if (m_fLow == pkOther->m_fLow && m_fHigh == pkOther->m_fHigh)
        return true;
    if ((m_spInterpA && !pkOther->m_spInterpA) || (!m_spInterpA && pkOther->m_spInterpA))
        return false;
    if (m_spInterpA && !m_spInterpA->IsEqual(pkOther->m_spInterpA))
        return false;
    if ((m_spInterpB && !pkOther->m_spInterpB) || (!m_spInterpB && pkOther->m_spInterpB))
        return false;
    if (m_spInterpB && !m_spInterpB->IsEqual(pkOther->m_spInterpB))
        return false;
    return false;
}

struct S_00a58160_Out
{
    int unk00;
    int unk04;
    int unk08;
    int(__cdecl* unk0c)(S_00a58160_Out*, void*, unsigned, unsigned*, unsigned);
    __forceinline void Save(void* p)
    {
        unsigned sz = 4;
        unk04 += unk0c(this, p, 4, &sz, 1);
    }
};

struct S_00a58160_Stream
{
    virtual int f00();
    virtual int f01();
    virtual int f02();
    virtual int f03();
    virtual int f04();
    virtual int f05();
    virtual int f06();
    virtual int f07();
    virtual int f08();
    virtual int f09();
    virtual int f10();
    virtual int f11();
    virtual int f12(NiObject*);
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
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    S_00a58160_Out* unk250;
};

struct S_00a58160_Foo : NiBSplineInterpolator
{
    void FUN_00a724d0(S_00a58160_Stream* s);
    void SaveToStream(S_00a58160_Stream* s);
};

// Calls FUN_00a724d0, then saves m_fStartTime and m_fEndTime to the stream and calls f12 twice.
// @fnv 0x00a58160
void S_00a58160_Foo::SaveToStream(S_00a58160_Stream* pStream)
{
    FUN_00a724d0(pStream);
    pStream->unk250->Save(&m_fStartTime);
    pStream->unk250->Save(&m_fEndTime);
    pStream->f12(m_spTransformData);
    pStream->f12(m_spSplineBasisData);
}

class BA58200StringArray
{
  public:
    virtual ~BA58200StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

extern const char* g_pcA58200Name;

char* __cdecl FUN_00a7d330(const char* pcString);
char* __cdecl FUN_00a7d550(const char* pcName, float fValue);

class BA58200Object
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void GetViewerStrings(BA58200StringArray* pkStrings);
};

template <class T> class BA58200Pointer
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }

    T* m_pObject;
};

class BA58200Sequence
{
  public:
    void BaseGetViewerStrings(BA58200StringArray* pkStrings);
    void FUN_00a58200(BA58200StringArray* pkStrings);

    int unk00;
    int unk04;
    int unk08;
    float m_fStartTime;
    float m_fEndTime;
    BA58200Pointer<BA58200Object> m_spFirst;
    BA58200Pointer<BA58200Object> m_spSecond;
};

// @fnv 0x00a58200
void BA58200Sequence::FUN_00a58200(BA58200StringArray* pkStrings)
{
    BaseGetViewerStrings(pkStrings);
    pkStrings->Add(FUN_00a7d330(g_pcA58200Name));
    pkStrings->Add(FUN_00a7d550("m_fStartTime", m_fStartTime));
    pkStrings->Add(FUN_00a7d550("m_fEndTime", m_fEndTime));
    if (m_spFirst)
        m_spFirst->GetViewerStrings(pkStrings);
    if (m_spSecond)
        m_spSecond->GetViewerStrings(pkStrings);
}
