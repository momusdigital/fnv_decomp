// fallout_shared/screencustomsplatter.cpp: ScreenCustomSplatter, BSPortal, BSCustomSplatterExtraData (15 functions)

#include "screencustomsplatter_decls.h"
// Iterates the entries array and calls FUN_00c5dea0 on each non-null PortalEntry before destruction.
// @fnv 0x00c50930
BSPortal::~BSPortal()
{
    unsigned int count = entries.count;
    for (unsigned int uiIndex = 0; uiIndex < count; uiIndex++)
    {
        PortalEntry* value;
        PortalEntry* slot;
        PortalEntry*& entry = entries.data[uiIndex];
        slot = entry;
        value = slot;
        if (value)
            value->FUN_00c5dea0();
    }
}
// @fnv 0x004defb0
void ScreenCustomSplatter::Clear()
{
    if (DAT_011c77e8)
    {
        DAT_011c7810->RemoveAllChildren();
        DAT_011c77dc = 0;
        DAT_011c77ec = 0.0f;
        DAT_011c77e9 = 0;
        SkyTextureManager::LoadTextureFromPath(&DAT_011c7808, DAT_011ce918.String());
        SkyTextureManager::LoadTextureFromPath(&DAT_011c7804, DAT_011ce284.String());
        if (DAT_011f941e)
            SkyTextureManager::LoadTextureFromPath(&DAT_011c780c, DAT_011cede8.String());
    }
}
// @fnv 0x004deb30
void ScreenCustomSplatter::Init()
{
    AutoMemContext mem(MEM_CONTEXT_SCREEN, true,
                       "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\ScreenCustomSplatter.cpp", 189);
    DAT_011c77e8 = DAT_011c77f4.Bool()->b;
    if (DAT_011c77e8)
    {
        GraphicsRenderer* renderer = reinterpret_cast<GraphicsRenderer*>(FUN_0043c4b0());
        float fAspect = (float)renderer->GetRenderTargetWidth() / (float)renderer->GetRenderTargetHeight();
        reinterpret_cast<NiPointer<NiAVObject>&>(DAT_011c781c) = new FUN_00a712f0;
        DAT_011c781c->FUN_00440460(NiPoint3(0.0f, 0.0f, DAT_01022960));
        NiUpdateData update1(0.0f, false, false);
        DAT_011c781c->Update(update1);
        reinterpret_cast<NiCamera*>(DAT_011c781c.operator->())->AimAt(NiPoint3::ZERO, DAT_011a9478);
        NiFrustum frustum(false);
        frustum.ortho = false;
        frustum.top = DAT_01016248;
        frustum.bottom = DAT_0102295c;
        frustum.left = (float)(fAspect * DAT_01011598);
        frustum.right = (float)(fAspect * DAT_01011588);
        frustum.farPlane = DAT_01022958;
        frustum.nearPlane = 1.0f;
        reinterpret_cast<NiCamera*>(DAT_011c781c.operator->())->UpdateViewFrustum(frustum);
        NiUpdateData update2(0.0f, false, false);
        DAT_011c781c->Update(update2);
        DAT_01189500 = frustum.right;
        DAT_01189504 = frustum.top;
        DAT_011c77ec = DAT_011cfc2c.Float()->f;
        DAT_011c77e9 = 0;
        reinterpret_cast<NiPointer<NiAVObject>&>(DAT_011c7810) = new NiNode(0);
        DAT_011c77dc = 0;
        SkyTextureManager::LoadTextureFromPath(&DAT_011c7808, DAT_011ce918.String());
        SkyTextureManager::LoadTextureFromPath(&DAT_011c7804, DAT_011ce284.String());
        if (DAT_011f941e)
            SkyTextureManager::LoadTextureFromPath(&DAT_011c780c, DAT_011cede8.String());
    }
}

class BSFadeNode
{
  public:
    int m_iFadeNodeMode;
    BSFadeNode(const char*);
};
extern BSFadeNode* DAT_011c77e4;
// Allocates a BSFadeNode constructed from the string "CSD" and stores it in DAT_011c77e4.
// @fnv 0x004de580
void CreateCSDFadeNode()
{
    DAT_011c77e4 = new BSFadeNode("CSD");
}

// @fnv 0x004de890
BSFadeNode* FUN_004de890()
{
    return DAT_011c77e4;
}

extern float DAT_011feda4;

// @fnv 0x004de8a0
void FUN_004de8a0(float value)
{
    DAT_011feda4 = value;
}

extern float DAT_011ad874;

// @fnv 0x004de8b0
void FUN_004de8b0(float value)
{
    DAT_011ad874 = value;
}

extern float DAT_011ad878;

// @fnv 0x004de8c0
void FUN_004de8c0(float f)
{
    DAT_011ad878 = f;
}

extern float DAT_011ad878;

// @fnv 0x004de8d0
float FUN_004de8d0()
{
    return DAT_011ad878;
}

struct NiRTTI
{
};
extern NiRTTI g_011c7820;

struct BSCustomSplatterExtraData
{
    const NiRTTI* GetRTTI() const;
};

// @fnv 0x004dead0
const NiRTTI* BSCustomSplatterExtraData::GetRTTI() const
{
    return &g_011c7820;
}

struct FUN_004deb10_shell
{
    void __thiscall FUN_00a7b300();
    void FUN_004deb10();
};

// @fnv 0x004deb10
void FUN_004deb10_shell::FUN_004deb10()
{
    FUN_00a7b300();
}

extern int DAT_010228c4;
struct NiExtraData
{
    char _pad[12];
    NiExtraData(BSFadeNode*);
};
struct Vector4f
{
    int a, b, c, d;
};
struct FUN_004dea80 : NiExtraData
{
    Vector4f q;
    FUN_004dea80(Vector4f* p);
};
// Initialises a NiExtraData-derived object with a vtable pointer and copies the four ints from p into its q member.
// @fnv 0x004dea80
FUN_004dea80::FUN_004dea80(Vector4f* apSource) : NiExtraData(FUN_004de890())
{
    *(int*)this = (int)&DAT_010228c4;
    q = *apSource;
}

void __cdecl _delete(void*, unsigned int);
struct FUN_004deae0_holder
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_004deb10 on this, then deletes this with size 0x1c when bit 0 of flags is set, and returns this.
// @fnv 0x004deae0
void* FUN_004deae0_holder::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<FUN_004deb10_shell*>(this)->FUN_004deb10();
    if (flags & 1)
        _delete(this, 0x1c);
    return this;
}

struct OpacityFadeState
{
    float elapsed;
    float duration;
    float opacity;
    unsigned int count;
};
struct SplatterExtra : NiExtraData
{
    OpacityFadeState* GetOffsetC();
};
struct SplatterObject : NiAVObject
{
    SplatterExtra* FUN_00a5bdd0(BSFadeNode*);
};
struct SplatterNode : NiNode
{
    virtual void virtual00();
    virtual void virtual01();
    virtual void virtual02();
    virtual void virtual03();
    virtual void virtual04();
    virtual void virtual05();
    virtual void virtual06();
    virtual void virtual07();
    virtual void virtual08();
    virtual void virtual09();
    virtual void virtual0a();
    virtual void virtual0b();
    virtual void virtual0c();
    virtual void virtual0d();
    virtual void virtual0e();
    virtual void virtual0f();
    virtual void virtual10();
    virtual void virtual11();
    virtual void virtual12();
    virtual void virtual13();
    virtual void virtual14();
    virtual void virtual15();
    virtual void virtual16();
    virtual void virtual17();
    virtual void virtual18();
    virtual void virtual19();
    virtual void virtual1a();
    virtual void virtual1b();
    virtual void virtual1c();
    virtual void virtual1d();
    virtual void virtual1e();
    virtual void virtual1f();
    virtual void virtual20();
    virtual void virtual21();
    virtual void virtual22();
    virtual void virtual23();
    virtual void virtual24();
    virtual void virtual25();
    virtual void virtual26();
    virtual void virtual27();
    virtual void virtual28();
    virtual void virtual29();
    virtual void virtual2a();
    virtual void virtual2b();
    virtual void virtual2c();
    virtual void virtual2d();
    virtual void virtual2e();
    virtual void virtual2f();
    virtual void virtual30();
    virtual void virtual31();
    virtual void virtual32();
    virtual void virtual33();
    virtual void virtual34();
    virtual void virtual35();
    virtual void virtual36();
    virtual void virtual37();
    virtual void virtual38();
    virtual void virtual39();
    virtual void virtual3a();
    virtual void virtual3b();
    virtual void RemoveAt(unsigned int);
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(unsigned int);
};
struct TimeGlobal
{
    float FUN_0084d030();
};
extern TimeGlobal DAT_011f6394;
extern SettingT_GameSettingCollection_ DAT_011ceeb4, DAT_011cf6a8;
float LinearInterpolate(float, float, float, float, float);
float FUN_0040ebd0(float, float);

// Advances each splatter child's elapsed time, removes expired ones, updates opacity and NiUpdateData, then advances the fade value toward 1.
// @fnv 0x004de600
void FUN_004de600()
{
    if (DAT_011c77e8)
    {
        unsigned int uiChildCount = reinterpret_cast<SplatterNode*>(DAT_011c7810.operator->())->FUN_0043b480();
        float elapsed = DAT_011f6394.FUN_0084d030();
        for (unsigned int index = 0; index < uiChildCount; ++index)
        {
            SplatterObject* child = static_cast<SplatterObject*>(
                reinterpret_cast<SplatterNode*>(DAT_011c7810.operator->())->FUN_0043b4a0(index));
            if (child)
            {
                SplatterExtra* extra = child->FUN_00a5bdd0(FUN_004de890());
                OpacityFadeState* data = extra->GetOffsetC();
                data->elapsed += elapsed;
                if (data->elapsed >= data->duration)
                {
                    DAT_011c77dc -= data->count;
                    reinterpret_cast<SplatterNode*>(DAT_011c7810.operator->())->RemoveAt(index);
                }
                else
                {
                    if (!DAT_011c77e9 && data->elapsed / data->duration >= DAT_011c77ec)
                    {
                        data->opacity = 1.0f - LinearInterpolate(0.0f, 1.0f, DAT_011cfc2c.Float()->f * data->duration,
                                                                 data->duration, data->elapsed);
                    }
                    else if (DAT_011c77e9 && data->elapsed >= data->duration - DAT_011c77ec)
                    {
                        float fFadeFraction = (data->duration - DAT_011c77ec) / data->duration;
                        data->opacity = 1.0f - LinearInterpolate(0.0f, 1.0f, fFadeFraction * data->duration,
                                                                 data->duration, data->elapsed);
                    }
                    NiUpdateData updateData(data->elapsed, true, false);
                    child->Update(updateData);
                }
            }
        }
        FUN_004de8a0(DAT_011ceeb4.Float()->f);
        FUN_004de8b0(DAT_011cf6a8.Float()->f);
        float fade = FUN_004de8d0();
        if (fade < 1.0)
        {
            fade += elapsed / 0.4;
            fade = FUN_0040ebd0(1.0f, fade);
            FUN_004de8c0(fade);
        }
    }
}

struct NiFixedString
{
    const char* m_kHandle;
    NiFixedString(const char* str);
    ~NiFixedString();
};

struct SplatterParams
{
    float fStart;
    float fAlpha;
    float fScale;
    unsigned int ItemUpdateArray;
};

struct SplatterExtraData : NiExtraData
{
    SplatterParams params;
    SplatterExtraData(SplatterParams* p);
    static void* operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
    void* GetList();
};

struct SplatterGeometry
{
    bool AddExtraData(SplatterExtraData* pData);
    void SetName(const NiFixedString& kName);
};

struct SplatterRoot
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual void V53();
    virtual void V54();
    virtual void AttachChildInAvailableSlot(SplatterGeometry* pChild, bool abFirstAvailableSlot);
    void Update(NiUpdateData& kData);
};

extern NiPointer<SplatterRoot> g_spSplatterRoot;
extern SettingT_GameSettingCollection_ g_fSplatterDefaultAlpha;

SplatterGeometry* CreateDebrisNode(unsigned int ItemUpdateArray, float fSizeMin, float fSizeMax);
void FUN_00b81420(SplatterGeometry* pGeom, void* pList);

// @fnv 0x004de8e0
void FUN_004de8e0(unsigned int ItemUpdateArray, float fAlpha, int iUnused, float fSizeMin, float fSizeMax)
{
    if (DAT_011c77e8)
    {
        unsigned int uiNum_2 = ItemUpdateArray;
        if (uiNum_2 > 0)
        {
            SplatterGeometry* pGeom = CreateDebrisNode(uiNum_2, fSizeMin, fSizeMax);
            DAT_011c77dc += uiNum_2;
            SplatterParams kParams2;
            kParams2.fScale = 1.0f;
            kParams2.fStart = 0.0f;
            if (fAlpha > 0.0)
            {
                kParams2.fAlpha = fAlpha;
            }
            else
            {
                kParams2.fAlpha = g_fSplatterDefaultAlpha.Float()->f;
            }
            kParams2.ItemUpdateArray = uiNum_2;
            SplatterExtraData* pExtraData = new SplatterExtraData(&kParams2);
            pGeom->AddExtraData(pExtraData);
            pGeom->SetName(NiFixedString("ScreenSplatterRoot"));
            g_spSplatterRoot->AttachChildInAvailableSlot(pGeom, true);
            FUN_00b81420(pGeom, pExtraData->GetList());
            NiUpdateData kUpdate(0.0f, false, false);
            g_spSplatterRoot->Update(kUpdate);
        }
    }
}
