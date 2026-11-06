// gamebryo2.2/corelibs/nimain/nilines.cpp: NiLines, LinesCloneSource (8 functions)

#include "nilines_decls.h"
// Sets the geometry data on dest from model, then calls NiAVObject::FUN_00a5ac90 with dest and process.
// @fnv 0x00a80400
void NiLines::CopyMemberData(NiLines* dest, CloningProcess& process)
{
    dest->SetGeometryData(model);
    NiAVObject::FUN_00a5ac90(dest, process);
}

struct NiRenderer;
struct NiLinesSelf
{
    void FUN_00a80610(NiRenderer* pkRenderer);
};
struct NiRenderer
{
    virtual void Unk0();
    char _pad_4[0x1fc];
    int m_iRendererState;
    char _pad_204[4];
    bool m_bRendererFlagA;
};
typedef void(__thiscall* RendererFn)(NiRenderer*, NiLinesSelf*);
// Calls self's render method, then if the renderer's mode is 1 or 2 and its flag is set, invokes the renderer's virtual function at offset 0x1c4.
// @fnv 0x00a747a0
void __fastcall FUN_00a747a0(NiLinesSelf* self, int, NiRenderer* apkRenderer)
{
    self->FUN_00a80610(apkRenderer);
    if ((apkRenderer->m_iRendererState == 1 || apkRenderer->m_iRendererState == 2) &&
        apkRenderer->m_bRendererFlagA == true)
    {
        RendererFn* vt = *(RendererFn**)apkRenderer;
        vt[0x1c4 / 4](apkRenderer, self);
    }
}

struct ActorCombatGroup;
struct GlobalObjectO2_00a7b610;
struct NiCombatArray
{
    virtual ~NiCombatArray();
    ActorCombatGroup** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usESize;
    unsigned short m_usFreeIdx;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, ActorCombatGroup*&);
};
extern GlobalObjectO2_00a7b610* g_011f4a48;
void __stdcall FUN_00a80e70(NiCombatArray*);
ActorCombatGroup* __cdecl FUN_00a7d330(GlobalObjectO2_00a7b610*);
// @fnv 0x00a74830
void __stdcall FUN_00a74830(NiCombatArray* pkStrings)
{
    FUN_00a80e70(pkStrings);
    ActorCombatGroup* pkGroup = FUN_00a7d330(g_011f4a48);
    unsigned int uiIndex = pkStrings->m_usESize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIndex, pkGroup);
}

struct CloningProcess;
struct NiGeometryData;
struct NiObject;
struct NiPoint3;
struct NiRenderer;
struct NiStream;
struct blob16
{
    char b[16];
};
struct NiTriBasedGeom : public NiGeometry
{
    virtual void __vslot_0();
    virtual void GetTrianglePoints(unsigned short, NiPoint3**, NiPoint3**, NiPoint3**);
    virtual void* GetRTTI();
    void CopyMemberData(NiTriBasedGeom*, CloningProcess*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    virtual void GetViewerStrings(void*);
    virtual void ReplaceModelData(NiGeometryData*);
    unsigned short GetTriangleCount();
    void SetNumberOfVertices(unsigned short);
    unsigned short GetNumberOfVertices();
    virtual NiTriBasedGeom* IsTriBasedGeom();
    void GetTriangleVertexIndices(unsigned short, unsigned short*, unsigned short*, unsigned short*);
    void __local_vftable_ctor_closure();
    char _pad_bc[52];
};
typedef char _sizecheck_NiTriBasedGeom[sizeof(NiTriBasedGeom) == 240 ? 1 : -1];
struct NiTriShape : public NiTriBasedGeom
{
    virtual void __vslot_0();
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(NiTriShape*, CloningProcess*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    virtual void GetViewerStrings(void*);
    unsigned int GetTriListLength();
    unsigned short* GetTriangleList();
    virtual void GetTrianglePoints(unsigned short, NiPoint3**, NiPoint3**, NiPoint3**);
    virtual void RenderImmediate(NiRenderer*);
    virtual NiTriShape* IsTriShape();
    virtual void RenderWithRenderer(NiRenderer*);
    void __local_vftable_ctor_closure();
};
typedef char _sizecheck_NiTriShape[sizeof(NiTriShape) == 240 ? 1 : -1];
struct BSResizableTriShape : public NiTriShape
{
    virtual void __vslot_0();
    virtual void SetLocalBound(struct blob16);
    virtual void* GetBoundingVolume();
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSResizableTriShape*, CloningProcess*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    virtual void GetViewerStrings(void*);
    void SetNumPrimitives(unsigned int);
    unsigned int GetNumPrimitives();
    virtual BSResizableTriShape* IsResizableTriShape();
    virtual void RenderImmediate(NiRenderer*);
    virtual void RenderWithRenderer(NiRenderer*);
    virtual void UpdateWorldBound();
    void __local_vftable_ctor_closure();
    unsigned int m_uiValueBeforeLocalBound;
    char LocalBound[16];
    char _pad_104[12];
};
typedef char _sizecheck_BSResizableTriShape[sizeof(BSResizableTriShape) == 272 ? 1 : -1];
struct FUN_00e68810_shell : public NiLines
{
    NiLines* FUN_00e68810();
};

// @fnv 0x00e68810
NiLines* FUN_00e68810_shell::FUN_00e68810()
{
    return this;
}

void __cdecl FUN_00a80470();
// @fnv 0x00a89770
void __cdecl FUN_00a89770()
{
    FUN_00a80470();
}

struct FUN_00a80430_Holder
{
    bool FUN_00a80430(NiStream&);
};
struct FUN_00a9b190 : FUN_00a80430_Holder
{
    bool FUN_00a9b190_Impl(NiStream&);
};
// @fnv 0x00a9b190
bool FUN_00a9b190::FUN_00a9b190_Impl(NiStream& s)
{
    return FUN_00a80430_Holder::FUN_00a80430(s);
}

void FUN_00a80db0();
// @fnv 0x00a9b1a0
void __cdecl FUN_00a9b1a0()
{
    FUN_00a80db0();
}

void* __cdecl NiAllocBlock(unsigned int size);
extern const void* DAT_0109d55c[];

struct LinesTableView
{
    const void** table;
};

struct NiLinesBaseCtor : NiLines
{
    NiLinesBaseCtor();
};

struct __declspec(novtable) LinesCloneObject : NiLinesBaseCtor
{
    int unkBC;
    int unkC0;
    static void* operator new(unsigned int size) throw()
    {
        return NiAllocBlock(size);
    }
    LinesCloneObject() throw() : NiLinesBaseCtor()
    {
        reinterpret_cast<LinesTableView*>(this)->table = DAT_0109d55c;
    }
};

struct LinesCloneSource : NiLines
{
    void FUN_00a80400(NiLines* result, CloningProcess& process);
    NiLines* CreateClone(CloningProcess& process);
};

// Allocates a LinesCloneObject, calls FUN_00a80400 with it and process, and returns it as NiLines.
// @fnv 0x00a747e0
NiLines* LinesCloneSource::CreateClone(CloningProcess& process)
{
    NiLines* result = new LinesCloneObject;
    FUN_00a80400(result, process);
    return result;
}
