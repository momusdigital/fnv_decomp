// gamebryo2.2/corelibs/nimain/nidirectionallight.cpp: NiDirectionalLight, NiDirectionalLightShell, LightDerived (8 functions)

#include "nidirectionallight_decls.h"
// @fnv 0x00a71ec0
void NiDirectionalLight::CopyMemberData(NiDirectionalLight* pDest, CloningProcess& process)
{
    NiLight::CopyMemberData(pDest, process);
    pDest->m_fDimmer = m_fDimmer;
    pDest->m_kAmb = m_kAmb;
    pDest->m_kDiff = m_kDiff;
    pDest->m_kSpec = m_kSpec;
}

void __fastcall FUN_00a71f60(void*);
extern int DAT_0109d7b4;

struct Vec3_00a75c20
{
    float x, y, z;
    Vec3_00a75c20()
    {}
    Vec3_00a75c20(float a, float b, float c) : x(a), y(b), z(c)
    {}
};

// Calls FUN_00a71f60, sets the vtable to &DAT_0109d7b4, stores Vec3(1,0,0) at pThis+0xf0 and byte 3 at pThis+0x9d, then returns pThis.
// @fnv 0x00a75c20
void* __fastcall FUN_00a75c20(char* pObject)
{
    FUN_00a71f60(pObject);
    *(int**)pObject = &DAT_0109d7b4;
    Vec3_00a75c20 v(1.0f, 0.0f, 0.0f);
    *(Vec3_00a75c20*)(pObject + 0xf0) = v;
    *(unsigned char*)(pObject + 0x9d) = 3;
    return pObject;
}

struct FUN_00a75c70_shell : public NiDirectionalLight
{
    void* GetRTTI();
};

struct GlobalObjectO2_00a7b610
{
    int dummy;
};

GlobalObjectO2_00a7b610 g_011f4a68;

// @fnv 0x00a75c70
void* FUN_00a75c70_shell::GetRTTI()
{
    return &g_011f4a68;
}

struct NiDirectionalLightShell : NiDirectionalLight
{
    NiDirectionalLight* __thiscall FUN_00a75c80(int n);
};

extern "C" void __cdecl FUN_00a72010(void);
extern "C" void __cdecl __Dummy_00b6fef0(void* p, int n);

// Calls FUN_00a72010, then if bit 0 of n is set calls __Dummy_00b6fef0 on this with 0xfc, and returns this.
// @fnv 0x00a75c80
NiDirectionalLight* __thiscall NiDirectionalLightShell::FUN_00a75c80(int aiFlags)
{
    FUN_00a72010();
    if (aiFlags & 1)
        __Dummy_00b6fef0(this, 0xfc);
    return this;
}

struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];
struct FUN_00a75cb0_shell : public NiDirectionalLight
{
    void FUN_00a75cb0(NiUpdateData*);
};

struct NiAVObject
{
    void UpdateWorldData(NiUpdateData&);
};

// Calls NiAVObject::UpdateWorldData, copies three floats from offsets 0x68/0x74/0x80 to 0xf0/0xf4/0xf8, and increments the int at 0xa8.
// @fnv 0x00a75cb0
void FUN_00a75cb0_shell::FUN_00a75cb0(NiUpdateData* UpdateData)
{
    ((NiAVObject*)this)->UpdateWorldData(*UpdateData);
    char* p = reinterpret_cast<char*>(this);
    *reinterpret_cast<float*>(p + 0xf0) = *reinterpret_cast<float*>(p + 0x68);
    *reinterpret_cast<float*>(p + 0xf4) = *reinterpret_cast<float*>(p + 0x74);
    *reinterpret_cast<float*>(p + 0xf8) = *reinterpret_cast<float*>(p + 0x80);
    int* q = reinterpret_cast<int*>(p + 0xa8);
    ++*q;
}

namespace fnv_00a75d70 {
template <class T> struct NiTMallocInterface
{
};
template <class T, class A> struct NiTPrimitiveArray
{
    char _pad[8];
    unsigned short m_usMax;
    unsigned short m_usSize;
    unsigned short m_usPad;
    unsigned short m_usGrow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
struct BaseLight
{
    void AppendEffectProperties(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >*);
};
struct GlobalObjectO2_00a7b610
{
    const char* p;
};
extern GlobalObjectO2_00a7b610 g_011f4a68;
char* _FUN_00a7d330(const char*);
struct LightDerived : BaseLight
{
    void GetViewerStrings(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >*);
};
// @fnv 0x00a75d70
void LightDerived::GetViewerStrings(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >* apArray)
{
    AppendEffectProperties(apArray);
    char* s = _FUN_00a7d330(g_011f4a68.p);
    unsigned int sz = apArray->m_usSize;
    if (sz >= apArray->m_usMax)
        apArray->SetSize(sz + apArray->m_usGrow);
    apArray->SetAt(sz, s);
}
}  // namespace fnv_00a75d70

extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
inline void* operator new(unsigned int, void* memory) throw()
{
    return memory;
}
// @fnv 0x00a75d50
NiDirectionalLight* __cdecl CreateNiDirectionalLight()
{
    return new (FUN_00aa13e0(sizeof(NiDirectionalLight))) NiDirectionalLight;
}

class NiObject;

extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
void* __fastcall FUN_00a75c20(char* pObject);

struct FUN_00a75cf0_impl : public NiDirectionalLight
{
    NiObject* CreateClone(CloningProcess* kCloning);
};

// Allocates a NiDirectionalLight, initializes it via FUN_00a75c20, copies member data and m_kWorldDir from the source, and returns the new object.
// @fnv 0x00a75cf0
NiObject* FUN_00a75cf0_impl::CreateClone(CloningProcess* kCloning)
{
    NiDirectionalLight* pkObject = (NiDirectionalLight*)FUN_00aa13e0(sizeof(NiDirectionalLight));

    if (pkObject)
        pkObject = (NiDirectionalLight*)FUN_00a75c20((char*)pkObject);
    else
        pkObject = 0;

    CopyMemberData(pkObject, *kCloning);
    pkObject->m_kWorldDir = m_kWorldDir;
    return (NiObject*)pkObject;
}
