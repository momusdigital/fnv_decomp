
// src/fallout/magic/bhktelekinesislistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/bhktelekinesislistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct bhkTelekinesisListener
{
    void FUN_00807910();
    void* Destroy(unsigned int flags);
};

extern "C" void __cdecl _Deallocate(void*);

// Calls FUN_00807910, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008078e0
void* bhkTelekinesisListener::Destroy(unsigned int flags)
{
    FUN_00807910();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00807da0_shell
{
    unsigned short m_0006;
    int FUN_00807da0();
};

// @fnv 0x00807da0
int FUN_00807da0_shell::FUN_00807da0()
{
    return *(unsigned short*)((char*)this + 6) & 0x3fff;
}

void __cdecl FUN_00807cb0(void*, void*);
struct DelVirt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~DelVirt();
};
struct FUN_00807980_shell
{
    void FUN_00807980(void*);
};
// Calls FUN_00807cb0 on the object at this-4 with apEntity, then deletes that object as a DelVirt.
// @fnv 0x00807980
void FUN_00807980_shell::FUN_00807980(void* apEntity)
{
    FUN_00807cb0((void*)((char*)this - 4), apEntity);
    delete (DelVirt*)((char*)this - 4);
}

struct hkpEntity;
struct FUN_008079e0_shell
{
    void FUN_00807a10(hkpEntity*);
    void FUN_008079e0(hkpEntity* entity);
};
// If the byte at offset 0x10 of this is set, calls FUN_00807a10 on the object at this-8 with entity.
// @fnv 0x008079e0
void FUN_008079e0_shell::FUN_008079e0(hkpEntity* entity)
{
    if (*(unsigned char*)((char*)this + 0x10))
        ((FUN_008079e0_shell*)((char*)this - 8))->FUN_00807a10(entity);
}

struct BSAudio
{
    void* GetAudioBackendData();
};
struct ITopic
{
    virtual void u0();
    virtual int u1(int);
};
BSAudio* __cdecl _FUN_00c85750();
// @fnv 0x00807bf0
int GetTopicResult(int aiValue)
{
    int result;
    {
        ITopic* topic = (ITopic*)_FUN_00c85750()->GetAudioBackendData();
        result = topic->u1(aiValue);
    }
    return result;
}

namespace fnv_00807c20 {
struct BSAudio
{
    void* GetAudioBackendData();
};
BSAudio* __cdecl _FUN_00c85750();
struct UnkTopic
{
    virtual void F0();
    virtual void F1();
    virtual void F2(void*, int);
};
// If a1 is non-null, gets an object from _FUN_00c85750 and calls its F2 with a1 and 16.
// @fnv 0x00807c20
void FUN_00807c20(void* a1)
{
    if (a1 != 0)
    {
        void* v = _FUN_00c85750()->GetAudioBackendData();
        ((UnkTopic*)v)->F2(a1, 16);
    }
}
}  // namespace fnv_00807c20

struct FUN_00807d10
{
    char _00[8];
    FUN_00807d10();
    ~FUN_00807d10();
};
struct FUN_00807c50
{
    FUN_00807d10 m00;
    FUN_00807d10 m08;
    FUN_00807c50();
};
// Default constructor that default-constructs the two FUN_00807d10 members m00 and m08.
// @fnv 0x00807c50
FUN_00807c50::FUN_00807c50()
{}

struct hkpEntity
{
    void __thiscall RemoveContactListener(void*);
    void __thiscall AddEntityListener(void*);
    void __thiscall RemoveEntityListener(void*);
};
// @fnv 0x00807cb0
void __cdecl FUN_00807cb0(char* listener, hkpEntity* entity)
{
    entity->RemoveContactListener(listener);
    entity->AddEntityListener(listener ? listener + 4 : 0);
    entity->RemoveEntityListener(listener ? listener + 8 : 0);
}

struct Unk_807d10
{
    Unk_807d10* FUN_00807d10();
};
// Initialises the object: writes 0 at offset 0, 0 at offset 4 and 0x8000 at offset 6, then returns this.
// @fnv 0x00807d10
Unk_807d10* Unk_807d10::FUN_00807d10()
{
    *(int*)this = 0;
    *(short*)((char*)this + 4) = 0;
    *(unsigned short*)((char*)this + 6) = 0x8000;
    return this;
}

struct FUN_00807d40_shell
{
    void FUN_00807d40();
    void FUN_00807d60();
};
// @fnv 0x00807d40
void FUN_00807d40_shell::FUN_00807d40()
{
    FUN_00807d60();
}

int __cdecl FUN_00807dc0(int, int, int);
struct FUN_00807d60_shell
{
    void FUN_00807d60();
};
// If the high bit of the field at offset 6 is clear, calls FUN_00807dc0 with the int at offset 0, the result of FUN_00807da0, and 0x18.
// @fnv 0x00807d60
void FUN_00807d60_shell::FUN_00807d60()
{
    if ((*(unsigned short*)((char*)this + 6) & 0x8000) == 0)
        FUN_00807dc0(*(int*)this, ((FUN_00807da0_shell*)this)->FUN_00807da0(), 0x18);
}

namespace fnv_00807dc0 {
struct BSAudio
{
    void* GetAudioBackendData();
};
BSAudio* _FUN_00c85750();
struct Topic
{
    virtual void m0();
    virtual void m1();
    virtual void m2(int, int);
};
// Gets an object from _FUN_00c85750 and calls its virtual m2 with a and b*4.
// @fnv 0x00807dc0
void FUN_00807dc0(int aiArg1, int aiArg2)
{
    void* t = _FUN_00c85750()->GetAudioBackendData();
    ((Topic*)t)->m2(aiArg1, aiArg2 * 4);
}
}  // namespace fnv_00807dc0

// Candidate for FUN_00807910 (0x00807910, 101 bytes) - bhkTelekinesisListener::~bhkTelekinesisListener()
// The original is the non-deleting destructor of a class whose
//   +0x00 subobject is a base class with a non-trivial destructor,
//   +0x04 member has a non-trivial destructor,
//   +0x08 member has a non-trivial destructor.
// The destruction order (reverse declaration order) and the EH scope-state
// sequence (1 -> 0 -> -1) are produced by the compiler itself.

// base subobject at +0x00 (4 bytes: a vptr in the game)
struct FNV_TK_Base
{
    int unk00;
    ~FNV_TK_Base();
};

// member at +0x04
struct FNV_TK_Member04
{
    int unk00;
    ~FNV_TK_Member04();
};

// member at +0x08
struct FNV_TK_Member08
{
    int unk00;
    ~FNV_TK_Member08();
};

struct FUN_00807910_Listener : FNV_TK_Base
{
    FNV_TK_Member04 unk04;
    FNV_TK_Member08 unk08;
    ~FUN_00807910_Listener();
};

// Destructor for the listener object; destroys its member subobjects and base.
// @fnv 0x00807910
FUN_00807910_Listener::~FUN_00807910_Listener()
{}

// ---------------------------------------------------------------------------
// GetOrCreate807c50 - the lazy "get or create" accessor of the object whose
// member at +0x214 holds a pointer to a FUN_00807c50.
//
// The original is an /Od /EHsc /GS member function:
//
//   push ebp / mov ebp,esp / push -1 / push <ehhandler> / mov eax,fs:[0]
//   push eax / sub esp,0x10 / <security cookie> / lea eax,[ebp-0xc]
//   mov fs:[0],eax / mov [ebp-0x18],ecx            <- the `this` home
//   ... if (this->m_214 == 0) { <allocate 0x10> ; <construct> ; this->m_214 = ... }
//   ... return this->m_214;
//
// The allocation and the construction are ONE new-expression: MSVC calls the
// class-scope allocation function with sizeof(FUN_00807c50) == 0x10, and then
// - only when the allocation did not return null - calls the constructor on the
// fresh memory and keeps ITS return value (the pointer) as the value of the
// new-expression.  Because FUN_00807c50 owns a sub-object with a non-trivial
// destructor, the new-expression needs an exception frame, which is where the
// `mov dword ptr [ebp-4],0` / `mov dword ptr [ebp-4],-1` state variable and
// the /GS cookie come from.
// ---------------------------------------------------------------------------

// The 8-byte sub-object of FUN_00807c50 (a non-trivial destructor is what
// forces the exception frame of the constructor and of the new-expression).
struct FNV_807d10
{
    int m_000;
    short m_004;
    short m_006;
    FNV_807d10();
    ~FNV_807d10();
};

// The 16-byte object that is allocated and constructed by the accessor.
struct FNV_807c50
{
    FNV_807d10 m_00;
    FNV_807d10 m_08;
    FNV_807c50();

    // The game's own heap helper; the class-scope allocation function is
    // what the original's "push 0x10 / call 0x807bf0" pair is.
    static void* operator new(unsigned int n)
    {
        return (void*)(long)GetTopicResult((int)n);
    }
};

// The class that owns GetOrCreate807c50.
struct FNV_807b50_owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    FNV_807c50* m_214;
    FNV_807c50* GetOrCreate807c50();
};

// Returns m_214, allocating a new FNV_807c50 and storing it there first if it is null.
// @fnv 0x00807b50
FNV_807c50* FNV_807b50_owner::GetOrCreate807c50()
{
    if (this->m_214 == 0)
    {
        this->m_214 = new FNV_807c50();
    }
    return this->m_214;
}

namespace TelekinesisRemovalDetail {
struct ActivationArray
{
    unsigned int __thiscall GetShortAtOffset4();
    FUN_008079e0_shell*& __thiscall FUN_00629ab0(unsigned int index);
};

extern "C" hkpEntity* __fastcall FUN_004ae750(void* body);

extern "C" int DAT_0119d900;
extern "C" int DAT_011a0eac;

extern "C" void* __cdecl FNV_DynamicCast(void* object, unsigned long displacement, unsigned int sourceType,
                                         unsigned int targetType, unsigned int flags);

}

// Iterates activation listeners on the hkpEntity and calls FUN_00807a10 on any that are telekinesis shells.
// @fnv 0x00807ac0
void __cdecl FUN_00807ac0(void* body)
{
    using namespace TelekinesisRemovalDetail;
    hkpEntity* entity = FUN_004ae750(body);
    {
        int index;
        for (index = 0; index < (int)reinterpret_cast<ActivationArray*>(
                                    reinterpret_cast<FNV_807b50_owner*>(entity)->GetOrCreate807c50())
                                    ->GetShortAtOffset4();
             ++index)
        {
            FUN_008079e0_shell* listener =
                reinterpret_cast<ActivationArray*>(reinterpret_cast<FNV_807b50_owner*>(entity)->GetOrCreate807c50())
                    ->FUN_00629ab0((unsigned int)index);
            {
                FUN_008079e0_shell* telekinesis = reinterpret_cast<FUN_008079e0_shell*>(
                    FNV_DynamicCast(listener, 0, reinterpret_cast<unsigned int>(&DAT_0119d900),
                                    reinterpret_cast<unsigned int>(&DAT_011a0eac), 0));
                if (telekinesis != 0)
                {
                    telekinesis->FUN_00807a10(entity);
                    index = 0;
                }
            }
        }
    }
}

namespace TelekinesisFinishCurrent {
struct TelekinesisLodView
{
    void FUN_00b4dec0(int);
};

struct TelekinesisFadeNodeView : public TelekinesisLodView
{
};

struct TelekinesisReferenceView
{
    virtual void v000() = 0;
    virtual void v001() = 0;
    virtual void v002() = 0;
    virtual void v003() = 0;
    virtual void v004() = 0;
    virtual void v005() = 0;
    virtual void v006() = 0;
    virtual void v007() = 0;
    virtual void v008() = 0;
    virtual void v009() = 0;
    virtual void v010() = 0;
    virtual void v011() = 0;
    virtual void v012() = 0;
    virtual void v013() = 0;
    virtual void v014() = 0;
    virtual void v015() = 0;
    virtual void v016() = 0;
    virtual void v017() = 0;
    virtual void v018() = 0;
    virtual void v019() = 0;
    virtual void v020() = 0;
    virtual void v021() = 0;
    virtual void v022() = 0;
    virtual void v023() = 0;
    virtual void v024() = 0;
    virtual void v025() = 0;
    virtual void v026() = 0;
    virtual void v027() = 0;
    virtual void v028() = 0;
    virtual void v029() = 0;
    virtual void v030() = 0;
    virtual void v031() = 0;
    virtual void v032() = 0;
    virtual void v033() = 0;
    virtual void v034() = 0;
    virtual void v035() = 0;
    virtual void v036() = 0;
    virtual void v037() = 0;
    virtual void v038() = 0;
    virtual void v039() = 0;
    virtual void v040() = 0;
    virtual void v041() = 0;
    virtual void v042() = 0;
    virtual void v043() = 0;
    virtual void v044() = 0;
    virtual void v045() = 0;
    virtual void v046() = 0;
    virtual void v047() = 0;
    virtual void v048() = 0;
    virtual void v049() = 0;
    virtual void v050() = 0;
    virtual void v051() = 0;
    virtual void v052() = 0;
    virtual void v053() = 0;
    virtual void v054() = 0;
    virtual void v055() = 0;
    virtual void v056() = 0;
    virtual void v057() = 0;
    virtual void v058() = 0;
    virtual void v059() = 0;
    virtual void v060() = 0;
    virtual void v061() = 0;
    virtual void v062() = 0;
    virtual void v063() = 0;
    virtual void v064() = 0;
    virtual void v065() = 0;
    virtual void v066() = 0;
    virtual void v067() = 0;
    virtual void v068() = 0;
    virtual void v069() = 0;
    virtual void v070() = 0;
    virtual void v071() = 0;
    virtual void v072() = 0;
    virtual void v073() = 0;
    virtual void v074() = 0;
    virtual void v075() = 0;
    virtual void v076() = 0;
    virtual void v077() = 0;
    virtual void v078() = 0;
    virtual void v079() = 0;
    virtual void v080() = 0;
    virtual void v081() = 0;
    virtual void v082() = 0;
    virtual void v083() = 0;
    virtual void v084() = 0;
    virtual void v085() = 0;
    virtual void v086() = 0;
    virtual void v087() = 0;
    virtual void v088() = 0;
    virtual void v089() = 0;
    virtual void v090() = 0;
    virtual void v091() = 0;
    virtual void v092() = 0;
    virtual void v093() = 0;
    virtual void v094() = 0;
    virtual void v095() = 0;
    virtual void v096() = 0;
    virtual void v097() = 0;
    virtual void v098() = 0;
    virtual void v099() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void* v116() = 0;
};

struct TelekinesisBodyView
{
    void SetCollisionFilter(unsigned int);
};

struct TelekinesisFinishReceiver : ::bhkTelekinesisListener
{
    void* contactListenerTable;
    void* entityListenerTable;
    void* activationListenerTable;
    TelekinesisReferenceView* pRef;
    TelekinesisBodyView* pBody;
    unsigned int m_Filter;
    void FUN_00807a10(::hkpEntity* entity);
};

extern "C" int DAT_01186044;
extern "C" int DAT_0119ba28;

// If pRef is set, casts its v116() result and calls FUN_00b4dec0(2) on success; then calls SetCollisionFilter, FUN_00807cb0, and deletes this receiver.
// @fnv 0x00807a10
void TelekinesisFinishReceiver::FUN_00807a10(::hkpEntity* entity)
{
    TelekinesisFadeNodeView* pavlod;
    void* pav;

    if (pRef)
    {
        pav = pRef->v116();

        pavlod = static_cast<TelekinesisFadeNodeView*>(::TelekinesisRemovalDetail::FNV_DynamicCast(
            pav, 0, reinterpret_cast<unsigned int>(&DAT_01186044), reinterpret_cast<unsigned int>(&DAT_0119ba28), 0));

        if (pavlod)
            pavlod->FUN_00b4dec0(2);
    }

    pBody->SetCollisionFilter(m_Filter);

    ::FUN_00807cb0(reinterpret_cast<char*>(this), entity);

    delete reinterpret_cast< ::DelVirt*>(this);
}

}
