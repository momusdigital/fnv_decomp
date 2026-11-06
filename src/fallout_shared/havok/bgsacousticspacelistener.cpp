
// src/fallout_shared/havok/bgsacousticspacelistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/bgsacousticspacelistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BGSAcousticSpaceListener
{
    void __thiscall FUN_0061f5d0();
    void* __thiscall Destroy(unsigned int flags);
};

void __cdecl _Deallocate(void* ptr);

// Calls FUN_0061f5d0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0061f5a0
void* __thiscall BGSAcousticSpaceListener::Destroy(unsigned int flags)
{
    FUN_0061f5d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Flt
{
    operator unsigned int() const;
};

struct FUN_0061f6c0_shell
{
    char pad[0xdec];
    Flt flt;
    unsigned int FUN_0061f6c0();
};

// @fnv 0x0061f6c0
unsigned int FUN_0061f6c0_shell::FUN_0061f6c0()
{
    return flt;
}

struct BGSAcousticSpace;
struct TESObjectREFR
{
    BGSAcousticSpace* GetAcousticSpace();
};
struct SoundPlaybackManager
{
    static void __cdecl ResetAcousticSpace(BGSAcousticSpace*);
};
struct NiTMap
{
    void GetNext(void*&, unsigned int&, void*&);
};
struct MyMap
{
    void RemoveAll();
};
struct MapX
{
    void* GetFirstPos();
};
struct FUN_0061f8e0_shell
{
    void FUN_0061f8e0(bool abDoRemoval);
};
// @fnv 0x0061f8e0
void FUN_0061f8e0_shell::FUN_0061f8e0(bool abDoRemoval)
{
    void* pos2 = ((MapX*)((char*)this + 0x18))->GetFirstPos();
    while (pos2)
    {
        unsigned int key;
        void* value2;
        ((NiTMap*)((char*)this + 0x18))->GetNext(pos2, key, value2);
        SoundPlaybackManager::ResetAcousticSpace(((TESObjectREFR*)key)->GetAcousticSpace());
    }
    ((MyMap*)((char*)this + 0x18))->RemoveAll();
}

struct PlayerCharacter
{
    bool FUN_004eaf60();
    unsigned int FUN_0061f6c0();
};
extern PlayerCharacter* _g_thePlayer;
struct W_0043b4f0
{
    unsigned int GetSourceFilesFromObject();
};
struct TESObjectREFR;
TESObjectREFR* __cdecl GetCdBodyRef(void*);
struct RootContactPoint
{
    unsigned int pad0[8];
    unsigned int m_20;
    unsigned int pad1[9];
    unsigned int m_48;
};
struct BGSAcousticSpaceListenerX
{
    void SetCopyMapEntry(TESObjectREFR*);
    bool CheckAcousticSpaceListener(RootContactPoint*);
    unsigned char pad[0x14];
    unsigned char m_ucState;
};
// @fnv 0x0061f7b0
bool BGSAcousticSpaceListenerX::CheckAcousticSpaceListener(RootContactPoint* pPoint)
{
    TESObjectREFR* apTestRef = 0;
    if (_g_thePlayer->FUN_004eaf60())
    {
        if (pPoint->m_48 ==
            reinterpret_cast<W_0043b4f0*>(reinterpret_cast<PlayerCharacter*>(_g_thePlayer)->FUN_0061f6c0())
                ->GetSourceFilesFromObject())
            apTestRef = GetCdBodyRef((void*)pPoint->m_20);
    }
    else
    {
        TESObjectREFR* pAcousticSpaceLeft = GetCdBodyRef((void*)pPoint->m_48);
        if (pAcousticSpaceLeft == reinterpret_cast<TESObjectREFR*>(_g_thePlayer))
            apTestRef = GetCdBodyRef((void*)pPoint->m_20);
    }
    if (apTestRef)
    {
        if (m_ucState)
            SetCopyMapEntry(apTestRef);
        else
            SoundPlaybackManager::ResetAcousticSpace(apTestRef->GetAcousticSpace());
    }
    return false;
}

namespace fnv_0061f940 {
struct MapH
{
    bool RemoveAt(unsigned int);
};
struct SetAtHelper
{
    void SetAt(unsigned int, unsigned int);
};
struct BGSAcousticSpaceListenerX
{
    void UpdateAcousticSpaceRefCounts(float afTime);
};
// @fnv 0x0061f940
void BGSAcousticSpaceListenerX::UpdateAcousticSpaceRefCounts(float afTime)
{
    void* iter = ((MapX*)((char*)this + 0x18))->GetFirstPos();
    while (iter)
    {
        unsigned int icount;
        unsigned int key;
        ((NiTMap*)((char*)this + 0x18))->GetNext(iter, key, (void*&)icount);
        ((SetAtHelper*)((char*)this + 0x18))->SetAt(key, --icount);
    }
    bool bloop = true;
    while (bloop)
    {
        bloop = false;
        void* iter2 = ((MapX*)((char*)this + 0x18))->GetFirstPos();
        while (iter2)
        {
            unsigned int icount;
            unsigned int key;
            ((NiTMap*)((char*)this + 0x18))->GetNext(iter2, key, (void*&)icount);
            if (icount == 0)
            {
                ((MapH*)((char*)this + 0x18))->RemoveAt(key);
                SoundPlaybackManager::ResetAcousticSpace(((TESObjectREFR*)key)->GetAcousticSpace());
                bloop = true;
                break;
            }
        }
    }
}
}  // namespace fnv_0061f940

struct PC_00605d70
{
    bool FUN_004eaf60();
};
struct TgtOps
{
    void* GetSourceFiles();
};
struct FUN_0061f630_shell
{
    void CheckPlayerReference(TESObjectREFR* apEntity);
};
// @fnv 0x0061f630
void FUN_0061f630_shell::CheckPlayerReference(TESObjectREFR* apEntity)
{
    if (!_g_thePlayer)
        return;
    if (((PC_00605d70*)_g_thePlayer)->FUN_004eaf60())
    {
        if (((TgtOps*)apEntity)->GetSourceFiles() ==
            (void*)((W_0043b4f0*)(_g_thePlayer->FUN_0061f6c0()))->GetSourceFilesFromObject())
            SoundPlaybackManager::ResetAcousticSpace(0);
    }
    else
    {
        TESObjectREFR* apTestRef = GetCdBodyRef(((TgtOps*)apEntity)->GetSourceFiles());
        if (apTestRef == (TESObjectREFR*)_g_thePlayer)
            SoundPlaybackManager::ResetAcousticSpace(0);
    }
}

struct FUN_0082eae0_shell
{
    static void __cdecl SetAcousticSpace(BGSAcousticSpace*);
};

struct FNV_GetObjectReference_shell
{
    BGSAcousticSpace* __thiscall _FNV_GetObjectReference();
};

struct FUN_0061f6e0_shell
{
    unsigned char pad[0x14];
    bool m_ucState;
    bool __thiscall FUN_0061f890(TESObjectREFR*, bool);
    bool __thiscall CheckAcousticSpaceEntered(RootContactPoint*);
};

// @fnv 0x0061f6e0
bool __thiscall FUN_0061f6e0_shell::CheckAcousticSpaceEntered(RootContactPoint* pPoint)
{
    TESObjectREFR* pAcousticSpaceRef = 0;

    if (_g_thePlayer->FUN_004eaf60())
    {
        if (pPoint->m_48 == reinterpret_cast<W_0043b4f0*>(_g_thePlayer->FUN_0061f6c0())->GetSourceFilesFromObject())
        {
            pAcousticSpaceRef = GetCdBodyRef(reinterpret_cast<void*>(pPoint->m_20));
        }
    }
    else
    {
        TESObjectREFR* apTestRef = GetCdBodyRef(reinterpret_cast<void*>(pPoint->m_48));
        if (apTestRef == reinterpret_cast<TESObjectREFR*>(_g_thePlayer))
        {
            pAcousticSpaceRef = GetCdBodyRef(reinterpret_cast<void*>(pPoint->m_20));
        }
    }

    if (pAcousticSpaceRef)
    {
        if (!m_ucState || !FUN_0061f890(pAcousticSpaceRef, false))
        {
            FUN_0082eae0_shell::SetAcousticSpace(
                reinterpret_cast<FNV_GetObjectReference_shell*>(pAcousticSpaceRef)->_FNV_GetObjectReference());
        }
        return true;
    }

    return false;
}

struct FUN_0061f5d0_sub
{
    ~FUN_0061f5d0_sub();
};

struct FUN_0061f5d0_base
{
    virtual ~FUN_0061f5d0_base();
};

struct FUN_0061f5d0_cls : FUN_0061f5d0_base
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FUN_0061f5d0_sub m_18;
    virtual ~FUN_0061f5d0_cls();
};

// Destructor of the class; the body is empty, so the compiler-generated member destructors run.
// @fnv 0x0061f5d0
FUN_0061f5d0_cls::~FUN_0061f5d0_cls()
{}

struct S_00620260_A
{
    virtual void vfn_00();
};
struct S_00620260_B
{
    void FUN_006ecd40(S_00620260_B* other);
};
struct S_00620260_T : S_00620260_A, S_00620260_B
{
    S_00620260_T* FindDerivedByKey(int b);
};
struct S_00620260_C
{
    virtual void vfn_00();
    virtual S_00620260_T* vfn_04(int a, int b);
    S_00620260_T* cur;
    S_00620260_T* FUN_00620260(int a, int b);
};
// @fnv 0x00620260
S_00620260_T* S_00620260_C::FUN_00620260(int a, int b)
{
    S_00620260_T* r = cur ? cur->FindDerivedByKey(b) : 0;
    if (!r)
    {
        r = vfn_04(a, b);
        r->FUN_006ecd40(cur);
        cur = r;
    }
    return r;
}
