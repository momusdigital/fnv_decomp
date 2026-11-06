
// src/fallout/magic/magicprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_0081aa80_shell
{
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    FUN_0081aa80_shell* FUN_0081aa80(void* a, void* b, void* c);
};

// Stores the three arguments into the object's fields and returns this.
// @fnv 0x0081aa80
FUN_0081aa80_shell* FUN_0081aa80_shell::FUN_0081aa80(void* pFirst, void* pSecond, void* pThird)
{
    m_kPointA = pFirst;
    m_kPointB = pSecond;
    m_iThirdValue = pThird;
    return this;
}

struct Call741e0
{
    void FUN_00c741e0(int a);
};
extern int DAT_010795b8;
extern int DAT_010795d4;
extern int DAT_010795e4;
struct FUN_00806eb0
{
    FUN_00806eb0(int a1, int a2);
};
// Calls FUN_00c741e0 with a1, installs three vtable pointers at offsets 0x0, 0x3E0 and 0x410, and stores a2 at offset 0x650.
// @fnv 0x00806eb0
FUN_00806eb0::FUN_00806eb0(int aiArg, int aiValue)
{
    ((Call741e0*)this)->FUN_00c741e0(aiArg);
    *(void**)this = (void*)&DAT_010795e4;
    *(void**)((char*)this + 0x3E0) = (void*)&DAT_010795d4;
    *(void**)((char*)this + 0x410) = (void*)&DAT_010795b8;
    *(int*)((char*)this + 0x650) = aiValue;
}

struct TESSaveLoadGame
{
    unsigned char FUN_008df040();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_0081e830_shell
{
    unsigned short GetSaveRecordSize(unsigned int a);
    unsigned int __thiscall FUN_00931ff0(unsigned int);
};

// Computes a save record size: adds the result of FUN_00931ff0(a) plus 12, and 4 more each when the save version is at least 0x48 and 0x64.
// @fnv 0x0081e830
unsigned short FUN_0081e830_shell::GetSaveRecordSize(unsigned int a)
{
    unsigned short usSize = 0;
    usSize += (unsigned short)FUN_00931ff0(a);
    usSize += 4;
    usSize += 4;
    usSize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x48)
        usSize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x64)
        usSize += 4;
    return usSize;
}

struct PC7d
{
    void FUN_00484ce0(unsigned int, int);
};
struct FUN_00484d20_Class
{
    void ForwardToSaveLoadGame(int, int);
};
struct FUN_00932070_shell
{
    void SaveProcess(unsigned int);
};
struct FUN_00818be0_shell
{
    unsigned int FUN_00818be0();
};
struct FUN_0040a1e0_shell
{
    unsigned int GetMagicItemFormID();
};
struct FUN_0081e8c0_shell : FUN_00932070_shell
{
    void SaveGame(unsigned int aiFlags);
};
// @fnv 0x0081e8c0
void FUN_0081e8c0_shell::SaveGame(unsigned int aiFlags)
{
    SaveProcess(aiFlags);
    unsigned int icasterID =
        reinterpret_cast<FUN_00818be0_shell*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x94))
            ->FUN_00818be0();
    reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame(reinterpret_cast<int>(&icasterID), 4);
    unsigned int ispellID =
        reinterpret_cast<FUN_0040a1e0_shell*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x98))
            ->GetMagicItemFormID();
    reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame(reinterpret_cast<int>(&ispellID), 4);
    reinterpret_cast<PC7d*>(this)->FUN_00484ce0(
        reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0xa4), 4);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x48)
        reinterpret_cast<PC7d*>(this)->FUN_00484ce0(
            reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x90), 4);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x64)
        reinterpret_cast<PC7d*>(this)->FUN_00484ce0(
            reinterpret_cast<unsigned int>(reinterpret_cast<unsigned char*>(this) + 0x8c), 4);
}

struct STR00
{
    void FUN_00484d00(void*, unsigned int);
};
struct FUN_00484d40_Host
{
    void FUN_00484d40(unsigned int*, int);
};
struct FUN_0081e980_shell
{
    void __thiscall SetProcessLevel(unsigned int, unsigned int);
    void __thiscall LoadGame2(unsigned int, unsigned int);
};
// @fnv 0x0081e980
void __thiscall FUN_0081e980_shell::LoadGame2(unsigned int a, unsigned int b)
{
    SetProcessLevel(a, b);
    unsigned int icasterID;
    ((FUN_00484d40_Host*)this)->FUN_00484d40(&icasterID, 4);
    *(unsigned int*)((char*)this + 0x94) = icasterID;
    unsigned int ispellID;
    ((FUN_00484d40_Host*)this)->FUN_00484d40(&ispellID, 4);
    *(unsigned int*)((char*)this + 0x98) = ispellID;
    ((STR00*)this)->FUN_00484d00((char*)this + 0xa4, 4);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x48)
        ((STR00*)this)->FUN_00484d00((char*)this + 0x90, 4);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x64)
        ((STR00*)this)->FUN_00484d00((char*)this + 0x8c, 4);
}

struct Form
{
    virtual void FUN_00800000() = 0;
    virtual Form* FUN_00800004() = 0;
};

struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_0081aa80
{
    Form* m_pForm;
    unsigned int m_uiCurrentValue;
    FUN_0081aa80* m_pNext;

    FUN_0081aa80(Form* pForm, unsigned int value, FUN_0081aa80* pNext);
};

struct S3c60
{
    unsigned char m_auiShapeKeys[0xc8];
    FUN_0081aa80* m_pEntries;

    int GetArchetype();
    bool AddAudioFormEntry(Form* pForm, ArrSI* pAudio);
};

unsigned int __fastcall _ref_0084e3a0(ArrSI* pAudio);
void* __cdecl operator new(unsigned int);

// @fnv 0x0081a960
bool S3c60::AddAudioFormEntry(Form* pForm, ArrSI* pAudio)
{
    if (!pForm || !pAudio)
        return false;

    if (pAudio->GetFlags() != GetArchetype())
        return true;

    Form* form = pForm->FUN_00800004();
    unsigned int value = _ref_0084e3a0(pAudio);

    FUN_0081aa80* node = m_pEntries;
    while (node)
    {
        if (node->m_pForm == form && node->m_uiCurrentValue == value)
            return false;
        node = node->m_pNext;
    }

    FUN_0081aa80* pNewEntry = new FUN_0081aa80(form, value, m_pEntries);
    m_pEntries = pNewEntry;
    return true;
}

struct NiFixedString
{
    NiFixedString(const char*);
    ~NiFixedString();

    char m_data[4];
};

struct Calendar;

struct NiAVObject
{
    virtual void v000()
    {}
    virtual void v001()
    {}
    virtual void v002()
    {}
    virtual void v003()
    {}
    virtual void v004()
    {}
    virtual void v005()
    {}
    virtual void v006()
    {}
    virtual void v007()
    {}
    virtual void v008()
    {}
    virtual void v009()
    {}
    virtual void v010()
    {}
    virtual void v011()
    {}
    virtual void v012()
    {}
    virtual void v013()
    {}
    virtual void v014()
    {}
    virtual void v015()
    {}
    virtual void v016()
    {}
    virtual void v017()
    {}
    virtual void v018()
    {}
    virtual void v019()
    {}
    virtual void v020()
    {}
    virtual void v021()
    {}
    virtual void v022()
    {}
    virtual void v023()
    {}
    virtual void v024()
    {}
    virtual void v025()
    {}
    virtual void v026()
    {}
    virtual void v027()
    {}
    virtual void v028()
    {}
    virtual void v029()
    {}
    virtual void v030()
    {}
    virtual void v031()
    {}
    virtual void v032()
    {}
    virtual void v033()
    {}
    virtual void v034()
    {}
    virtual void v035()
    {}
    virtual void v036()
    {}
    virtual void v037()
    {}
    virtual void v038()
    {}
    virtual Calendar* v039(const NiFixedString&);
    virtual void v040()
    {}
    virtual void v041()
    {}
    virtual void v042()
    {}
    virtual void v043()
    {}
    virtual void v044()
    {}
    virtual void v045()
    {}
    virtual void v046()
    {}
    virtual void v047()
    {}
    virtual void v048()
    {}
    virtual void v049()
    {}
    virtual void v050()
    {}
    virtual void v051()
    {}
    virtual void v052()
    {}
    virtual void v053()
    {}
    virtual void v054()
    {}
    virtual void v055()
    {}
    virtual void v056()
    {}
    virtual void v057()
    {}
    virtual void v058(NiAVObject*);
};

struct Calendar : public NiAVObject
{
    Calendar* GetDaysPassed();
};

struct MagicProjectile
{
    virtual void v000()
    {}
    virtual void v001()
    {}
    virtual void v002()
    {}
    virtual void v003()
    {}
    virtual void v004()
    {}
    virtual void v005()
    {}
    virtual void v006()
    {}
    virtual void v007()
    {}
    virtual void v008()
    {}
    virtual void v009()
    {}
    virtual void v010()
    {}
    virtual void v011()
    {}
    virtual void v012()
    {}
    virtual void v013()
    {}
    virtual void v014()
    {}
    virtual void v015()
    {}
    virtual void v016()
    {}
    virtual void v017()
    {}
    virtual void v018()
    {}
    virtual void v019()
    {}
    virtual void v020()
    {}
    virtual void v021()
    {}
    virtual void v022()
    {}
    virtual void v023()
    {}
    virtual void v024()
    {}
    virtual void v025()
    {}
    virtual void v026()
    {}
    virtual void v027()
    {}
    virtual void v028()
    {}
    virtual void v029()
    {}
    virtual void v030()
    {}
    virtual void v031()
    {}
    virtual void v032()
    {}
    virtual void v033()
    {}
    virtual void v034()
    {}
    virtual void v035()
    {}
    virtual void v036()
    {}
    virtual void v037()
    {}
    virtual void v038()
    {}
    virtual void v039()
    {}
    virtual void v040()
    {}
    virtual void v041()
    {}
    virtual void v042()
    {}
    virtual void v043()
    {}
    virtual void v044()
    {}
    virtual void v045()
    {}
    virtual void v046()
    {}
    virtual void v047()
    {}
    virtual void v048()
    {}
    virtual void v049()
    {}
    virtual void v050()
    {}
    virtual void v051()
    {}
    virtual void v052()
    {}
    virtual void v053()
    {}
    virtual void v054()
    {}
    virtual void v055()
    {}
    virtual void v056()
    {}
    virtual void v057()
    {}
    virtual void v058()
    {}
    virtual void v059()
    {}
    virtual void v060()
    {}
    virtual void v061()
    {}
    virtual void v062()
    {}
    virtual void v063()
    {}
    virtual void v064()
    {}
    virtual void v065()
    {}
    virtual void v066()
    {}
    virtual void v067()
    {}
    virtual void v068()
    {}
    virtual void v069()
    {}
    virtual void v070()
    {}
    virtual void v071()
    {}
    virtual void v072()
    {}
    virtual void v073()
    {}
    virtual void v074()
    {}
    virtual void v075()
    {}
    virtual void v076()
    {}
    virtual void v077()
    {}
    virtual void v078()
    {}
    virtual void v079()
    {}
    virtual void v080()
    {}
    virtual void v081()
    {}
    virtual void v082()
    {}
    virtual void v083()
    {}
    virtual void v084()
    {}
    virtual void v085()
    {}
    virtual void v086()
    {}
    virtual void v087()
    {}
    virtual void v088()
    {}
    virtual void v089()
    {}
    virtual void v090()
    {}
    virtual void v091()
    {}
    virtual void v092()
    {}
    virtual void v093()
    {}
    virtual void v094()
    {}
    virtual void v095()
    {}
    virtual void v096()
    {}
    virtual void v097()
    {}
    virtual void v098()
    {}
    virtual void v099()
    {}
    virtual void v100()
    {}
    virtual void v101()
    {}
    virtual void v102()
    {}
    virtual void v103()
    {}
    virtual void v104()
    {}
    virtual void v105()
    {}
    virtual void v106()
    {}
    virtual void v107()
    {}
    virtual void v108()
    {}
    virtual void v109()
    {}
    virtual void v110()
    {}
    virtual void v111()
    {}
    virtual void v112()
    {}
    virtual void v113()
    {}
    virtual void v114()
    {}
    virtual void v115()
    {}
    virtual NiAVObject* v116();

    void FUN_0081e730();
};

Calendar* NiAVObject::v039(const NiFixedString&)
{
    return 0;
}

void NiAVObject::v058(NiAVObject*)
{}

// Gets the "MagicAreaDisplay" child node and, if its GetDaysPassed() returns a node, passes the child to that node's v058.
// @fnv 0x0081e730
void MagicProjectile::FUN_0081e730()
{
    NiAVObject* pAreaDisplay = v116() ? v116()->v039(NiFixedString("MagicAreaDisplay")) : 0;

    if (pAreaDisplay)
    {
        if (static_cast<Calendar*>(pAreaDisplay)->GetDaysPassed())
        {
            static_cast<Calendar*>(pAreaDisplay)->GetDaysPassed()->v058(pAreaDisplay);
        }
    }
}

namespace fnv_0081ea40 {
struct FUN_00932490_shell
{
    void SetProcessFlags(unsigned int, unsigned int);
};

struct MagicCaster
{
    static MagicCaster* __cdecl GetCasterByHandle(unsigned int);
};

struct EffectItem
{
};

struct EffectItemList_shell
{
    EffectItem* FindCostliestEffectItem(int, int);
};

struct ES_0081c630
{
};

struct MI_0081c630
{
    ES_0081c630* GetEffectSettingForRange(int);
};

struct MagicItem
{
    unsigned char m_ucUnknownByte[0x0c];
    EffectItemList_shell m_effectItemList;

    static MagicItem* __cdecl GetMagicItemByID(unsigned int);
};

struct MobileObject
{
    unsigned int GetCurrentProcessLevel();
};

struct ActorDeletionQueue
{
    void FUN_0096d470(MobileObject*, int);
};

struct Host096d450
{
    void FUN_0096d450(MobileObject*, int, bool, bool, MobileObject*);
};

struct MagicProjectile;

struct SaveManager
{
    void AddFormToList(MagicProjectile*);
};

extern SaveManager* DAT_011de45c;
extern int DAT_011e0e80;

struct MagicProjectile
{
    virtual void v000()
    {}
    virtual void v001()
    {}
    virtual void v002()
    {}
    virtual void v003()
    {}
    virtual void v004()
    {}
    virtual void v005()
    {}
    virtual void v006()
    {}
    virtual void v007()
    {}
    virtual void v008()
    {}
    virtual void v009()
    {}
    virtual void v010()
    {}
    virtual void v011()
    {}
    virtual void v012()
    {}
    virtual void v013()
    {}
    virtual void v014()
    {}
    virtual void v015()
    {}
    virtual void v016()
    {}
    virtual void v017()
    {}
    virtual void v018()
    {}
    virtual void v019()
    {}
    virtual void v020()
    {}
    virtual void v021()
    {}
    virtual void v022()
    {}
    virtual void v023()
    {}
    virtual void v024()
    {}
    virtual void v025()
    {}
    virtual void v026()
    {}
    virtual void v027()
    {}
    virtual void v028()
    {}
    virtual void v029()
    {}
    virtual void v030()
    {}
    virtual void v031()
    {}
    virtual void v032()
    {}
    virtual void v033()
    {}
    virtual void v034()
    {}
    virtual void v035()
    {}
    virtual void v036()
    {}
    virtual void v037()
    {}
    virtual void v038()
    {}
    virtual void v039()
    {}
    virtual void v040()
    {}
    virtual void v041()
    {}
    virtual void v042()
    {}
    virtual void v043()
    {}
    virtual void v044()
    {}
    virtual void v045()
    {}
    virtual void v046()
    {}
    virtual void v047()
    {}
    virtual void v048()
    {}
    virtual void v049()
    {}
    virtual void v050()
    {}
    virtual void v051()
    {}
    virtual void v052()
    {}
    virtual void v053()
    {}
    virtual void v054()
    {}
    virtual void v055()
    {}
    virtual void v056()
    {}
    virtual void v057()
    {}
    virtual void v058()
    {}
    virtual void v059()
    {}
    virtual void v060()
    {}
    virtual void v061()
    {}
    virtual void v062()
    {}
    virtual void v063()
    {}
    virtual void v064()
    {}
    virtual void v065()
    {}
    virtual void v066()
    {}
    virtual void v067()
    {}
    virtual void v068()
    {}
    virtual void v069()
    {}
    virtual void v070()
    {}
    virtual void v071()
    {}
    virtual void v072()
    {}
    virtual void v073()
    {}
    virtual void v074()
    {}
    virtual void v075()
    {}
    virtual void v076()
    {}
    virtual void v077()
    {}
    virtual void v078()
    {}
    virtual void v079()
    {}
    virtual void v080()
    {}
    virtual void v081()
    {}
    virtual void v082()
    {}
    virtual void v083()
    {}
    virtual void v084()
    {}
    virtual void v085()
    {}
    virtual void v086()
    {}
    virtual void v087()
    {}
    virtual void v088()
    {}
    virtual void v089()
    {}
    virtual void v090()
    {}
    virtual void v091()
    {}
    virtual void v092()
    {}
    virtual void v093()
    {}
    virtual void v094()
    {}
    virtual void v095()
    {}
    virtual void v096()
    {}
    virtual void v097()
    {}
    virtual void v098()
    {}
    virtual void v099()
    {}
    virtual void v100()
    {}
    virtual void v101()
    {}
    virtual void v102()
    {}
    virtual void v103()
    {}
    virtual void v104()
    {}
    virtual void v105()
    {}
    virtual void v106()
    {}
    virtual void v107()
    {}
    virtual void v108()
    {}
    virtual void v109()
    {}
    virtual void v110()
    {}
    virtual void v111()
    {}
    virtual void v112()
    {}
    virtual void v113()
    {}
    virtual void v114(int)
    {}

    unsigned char m_ucUnknownByte[0x90];
    MagicCaster* m_magicCaster;
    MagicItem* m_magicItem;
    EffectItem* m_effectItem;
    ES_0081c630* m_avEffect;

    void ResolveMagicReferences(unsigned int, unsigned int);
};

// @fnv 0x0081ea40
void MagicProjectile::ResolveMagicReferences(unsigned int aiFlags, unsigned int aiOldFlags)
{
    unsigned int ispellID;
    unsigned int icasterID;

    icasterID = reinterpret_cast<unsigned int>(m_magicCaster);
    m_magicCaster = MagicCaster::GetCasterByHandle(icasterID);

    ispellID = reinterpret_cast<unsigned int>(m_magicItem);
    m_magicItem = MagicItem::GetMagicItemByID(ispellID);

    m_effectItem = m_magicItem->m_effectItemList.FindCostliestEffectItem(2, 0);
    m_avEffect = reinterpret_cast<MI_0081c630*>(m_magicItem)->GetEffectSettingForRange(0);

    this->v114(0);

    reinterpret_cast<FUN_00932490_shell*>(this)->SetProcessFlags(aiFlags, aiOldFlags);

    reinterpret_cast<ActorDeletionQueue*>(&DAT_011e0e80)
        ->FUN_0096d470(reinterpret_cast<MobileObject*>(this),
                       static_cast<int>(reinterpret_cast<MobileObject*>(this)->GetCurrentProcessLevel()));

    reinterpret_cast<Host096d450*>(&DAT_011e0e80)
        ->FUN_0096d450(reinterpret_cast<MobileObject*>(this),
                       static_cast<int>(reinterpret_cast<MobileObject*>(this)->GetCurrentProcessLevel()), false, false,
                       0);

    if (!m_magicCaster || !m_magicItem)
        DAT_011de45c->AddFormToList(this);
}
}  // namespace fnv_0081ea40

struct EventData
{
    bool HasDetrimentalEffect();
    bool HasNonDetrimentalEffect();
};
struct Event
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int GetType();
    int id;
    int state;
    EventData data;
};
struct Handler
{
    virtual void Handle4(void*, bool);
    virtual void Handle10(void*, bool);
    virtual void v2();
    virtual void v3();
    virtual void Handle1(void*, int, bool);
    virtual void v5();
    virtual void v6();
    virtual void HandleYes();
    virtual void HandleNo();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int HasError();
    virtual void v14();
    virtual void v15();
    virtual void SetEvent(Event*);
    virtual void v17();
    virtual void SetValue(int);
    void FUN_00818af0(int, const char*);
    bool FUN_00815480(Event*, int, bool);
};
extern char DAT_0107acc8[];
extern char DAT_0107acac[];
extern char DAT_01183140[];
extern char DAT_01183060[];
extern "C" void* __cdecl FUN_00ec43fb(Event*, int, const char*, const char*, int);
// Checks evt->data, dispatches by evt->GetType() to Handle4/Handle1/Handle10, else logs errors and calls SetEvent/SetValue then HandleYes or HandleNo.
// @fnv 0x00815480
bool Handler::FUN_00815480(Event* pEvent, int value, bool flag)
{
    if (pEvent->data.HasDetrimentalEffect())
    {
        FUN_00818af0(5, DAT_0107acc8);
        return false;
    }
    switch (pEvent->GetType())
    {
    case 4:
        Handle4(FUN_00ec43fb(pEvent, 0, DAT_01183140, DAT_01183060, 0), flag);
        return true;
        break;
    case 1:
        Handle1(FUN_00ec43fb(pEvent, 0, DAT_01183140, DAT_01183060, 0), value, flag);
        return true;
        break;
    case 10:
        Handle10(FUN_00ec43fb(pEvent, 0, DAT_01183140, DAT_01183060, 0), flag);
        return true;
    }
    if (HasError())
    {
        FUN_00818af0(6, DAT_0107acac);
        return false;
    }
    SetEvent(pEvent);
    SetValue(value);
    if (pEvent->data.HasNonDetrimentalEffect() && value)
    {
        HandleYes();
    }
    else
    {
        HandleNo();
    }
    return true;
}

struct HighProcess
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
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    HighProcess();
};
struct PrimaryRef
{
    virtual void v();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
struct SecondaryRef
{
    virtual void v();
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
    HighProcess* process;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
};
struct MobileObject : PrimaryRef, SecondaryRef
{
    MobileObject();
    ~MobileObject();
};
struct FUN_0081dbb0 : MobileObject
{
    float unk88, unk8c, unk90;
    int unk94, unk98, unk9c, unka0;
    void FUN_0046a010(bool);
    void* FUN_007af430();
    void FUN_00575690(void*);
    FUN_0081dbb0();
};
// Initializes the object, zeroes its float and int fields, allocates a HighProcess, and calls FUN_00575690 with the result of FUN_007af430.
// @fnv 0x0081dbb0
FUN_0081dbb0::FUN_0081dbb0()
{
    FUN_0046a010(true);
    unk90 = 0.0f;
    unk94 = 0;
    unk98 = 0;
    unk9c = 0;
    unka0 = 0;
    unk88 = 0.0f;
    unk8c = 0.0f;
    process = new HighProcess;
    FUN_00575690(FUN_007af430());
}

struct MarkerErrorSub
{
    virtual void v000()
    {}
    virtual void v001()
    {}
    virtual void v002()
    {}
    virtual void v003()
    {}
    virtual void v004()
    {}
    virtual void v005()
    {}
    virtual void v006(const char* name);
};

struct MarkerErrorObj
{
    unsigned char unk00[0x3c];
    MarkerErrorSub m_sub;
    unsigned char unk40[0xdc - 0x40];

    MarkerErrorObj();
};

struct MarkerErrorMgr
{
    void FUN_004603b0(MarkerErrorObj* pObj);
};

extern MarkerErrorObj* DAT_011dc774;
extern MarkerErrorMgr* DAT_011c3f2c;

// Creates the marker_error.nif object on first call, registers it with DAT_011c3f2c, and returns the cached DAT_011dc774 instance.
// @fnv 0x0081e310
MarkerErrorObj* __cdecl GetMarkerErrorObj()
{
    if (DAT_011dc774 == 0)
    {
        MarkerErrorObj* pObj = new MarkerErrorObj();
        pObj->m_sub.v006("marker_error.nif");
        DAT_011dc774 = pObj;
        DAT_011c3f2c->FUN_004603b0(DAT_011dc774);
    }
    return DAT_011dc774;
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3(float fX, float fY, float fZ);
};
struct MADName
{
    char* m_kHandle;
    MADName(const char* pcString);
    ~MADName();
};
struct NiMemObject
{
    static void* operator new(unsigned int uiSize);
};
struct FUN_00a75650 : NiMemObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48;
    FUN_00a75650();
    void FUN_004534f0(const float* pColor);
    void FUN_004bc450(const NiPoint3& kPoint);
};
struct MADNode;
struct MADObject
{
    virtual void v00(), v01(), v02();
    virtual MADNode* IsSceneNode();
    virtual void v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(), v14(), v15(), v16(), v17(),
        v18(), v19();
    virtual void v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(), v32(), v33(),
        v34(), v35(), v36(), v37(), v38();
    virtual MADObject* GetObjectByName(const MADName& kName);
    float GetFloatAt64();
    void AssignFixedString(const MADName& kName);
    void FUN_00440460(const void* pData);
    void FUN_00439410(FUN_00a75650* pProperty);
};
struct MADNode : MADObject
{
    virtual void v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(), v48(), v49(), v50(), v51(), v52(), v53(),
        v54();
    virtual void AttachChildInAvailableSlot(MADObject* pChild, bool abFirstAvailableSlot);
    void FUN_00a5a040();
};
struct MADCount
{
    int FUN_00404420();
};
struct MADSetting
{
    float* FUN_00403e20();
};
extern MADSetting DAT_011d15e0;
extern const char DAT_011f426c[];
extern const float DAT_011a9b7c[];
struct MADHandle
{
    void* m_pObject;
    MADHandle& operator=(const MADHandle& kOther);
};
MADObject* __cdecl FUN_00c56680(float fRadius, int iSlices, int iStacks, int iUnk);
void __cdecl GetLayerColor(void* pObject, const NiPoint3& kPoint);
struct MagicAreaOwner
{
    virtual void v000(), v001(), v002(), v003(), v004(), v005(), v006(), v007(), v008(), v009();
    virtual void v010(), v011(), v012(), v013(), v014(), v015(), v016(), v017(), v018(), v019();
    virtual void v020(), v021(), v022(), v023(), v024(), v025(), v026(), v027(), v028(), v029();
    virtual void v030(), v031(), v032(), v033(), v034(), v035(), v036(), v037(), v038(), v039();
    virtual void v040(), v041(), v042(), v043(), v044(), v045(), v046(), v047(), v048(), v049();
    virtual void v050(), v051(), v052(), v053(), v054(), v055(), v056(), v057(), v058(), v059();
    virtual void v060(), v061(), v062(), v063(), v064(), v065(), v066(), v067(), v068(), v069();
    virtual void v070(), v071(), v072(), v073(), v074(), v075(), v076(), v077(), v078(), v079();
    virtual void v080(), v081(), v082(), v083(), v084(), v085(), v086(), v087(), v088(), v089();
    virtual void v090(), v091(), v092(), v093(), v094(), v095(), v096(), v097(), v098(), v099();
    virtual void v100(), v101(), v102(), v103(), v104(), v105(), v106(), v107(), v108(), v109();
    virtual void v110(), v111(), v112(), v113(), v114(), v115();
    virtual MADObject* Get3D();
    MADCount* FUN_00586150();
    MADHandle FUN_00931ed0();
    void CreateMagicAreaDisplay();
};
// Builds a sphere node named "MagicAreaDisplay" sized from the magic area count and setting, applies a material, and attaches it to the 3D root's node.
// @fnv 0x0081aab0
void MagicAreaOwner::CreateMagicAreaDisplay()
{
    MADObject* pRoot = Get3D();
    if (!pRoot || pRoot->GetObjectByName(MADName("MagicAreaDisplay")))
    {
        return;
    }
    MADNode* pNode2 = pRoot->IsSceneNode();
    if (pNode2)
    {
        float fRadius3 = FUN_00586150()->FUN_00404420() * *DAT_011d15e0.FUN_00403e20() / pRoot->GetFloatAt64();
        MADObject* pDisplaySphere = FUN_00c56680(fRadius3, 10, 10, 0);
        pDisplaySphere->AssignFixedString(MADName("MagicAreaDisplay"));
        pDisplaySphere->FUN_00440460(DAT_011f426c);
        NiPoint3 kZero_(0.0f, 0.0f, 0.0f);
        GetLayerColor(FUN_00931ed0().m_pObject, kZero_);
        FUN_00a75650* pMaterial = new FUN_00a75650;
        pMaterial->FUN_004534f0(DAT_011a9b7c);
        pMaterial->FUN_004534f0(DAT_011a9b7c);
        pMaterial->FUN_004bc450(kZero_);
        pDisplaySphere->FUN_00439410(pMaterial);
        pNode2->AttachChildInAvailableSlot(pDisplaySphere, true);
        pNode2->FUN_00a5a040();
    }
}

struct ActorDeletionQueue
{
    float FUN_0096d490();
};
extern ActorDeletionQueue DAT_011e0e80;

struct Interface
{
    float FUN_007014e0(int);
};
extern Interface* DAT_011d8804;

extern const double DAT_01012060;
extern const double DAT_010290d0;

struct Class_0081df60
{
    virtual void vf_000();
    virtual void vf_001();
    virtual void vf_002();
    virtual void vf_003();
    virtual void vf_004();
    virtual void vf_005();
    virtual void vf_006();
    virtual void vf_007();
    virtual void vf_008();
    virtual void vf_009();
    virtual void vf_00a();
    virtual void vf_00b();
    virtual void vf_00c();
    virtual void vf_00d();
    virtual void vf_00e();
    virtual void vf_00f();
    virtual void vf_010();
    virtual void vf_011();
    virtual void vf_012();
    virtual void vf_013();
    virtual void vf_014();
    virtual void vf_015();
    virtual void vf_016();
    virtual void vf_017();
    virtual void vf_018();
    virtual void vf_019();
    virtual void vf_01a();
    virtual void vf_01b();
    virtual void vf_01c();
    virtual void vf_01d();
    virtual void vf_01e();
    virtual void vf_01f();
    virtual void vf_020();
    virtual void vf_021();
    virtual void vf_022();
    virtual void vf_023();
    virtual void vf_024();
    virtual void vf_025();
    virtual void vf_026();
    virtual void vf_027();
    virtual void vf_028();
    virtual void vf_029();
    virtual void vf_02a();
    virtual void vf_02b();
    virtual void vf_02c();
    virtual void vf_02d();
    virtual void vf_02e();
    virtual void vf_02f();
    virtual void vf_030();
    virtual void vf_031();
    virtual void vf_032();
    virtual void vf_033();
    virtual void vf_034();
    virtual void vf_035();
    virtual void vf_036();
    virtual void vf_037();
    virtual void vf_038();
    virtual void vf_039();
    virtual void vf_03a();
    virtual void vf_03b();
    virtual void vf_03c();
    virtual void vf_03d();
    virtual void vf_03e();
    virtual void vf_03f();
    virtual void vf_040();
    virtual void vf_041();
    virtual void vf_042();
    virtual void vf_043();
    virtual void vf_044();
    virtual void vf_045();
    virtual void vf_046();
    virtual void vf_047();
    virtual void vf_048();
    virtual void vf_049();
    virtual void vf_04a();
    virtual void vf_04b();
    virtual void vf_04c();
    virtual void vf_04d();
    virtual void vf_04e();
    virtual void vf_04f();
    virtual void vf_050();
    virtual void vf_051();
    virtual void vf_052();
    virtual void vf_053();
    virtual void vf_054();
    virtual void vf_055();
    virtual void vf_056();
    virtual void vf_057();
    virtual void vf_058();
    virtual void vf_059();
    virtual void vf_05a();
    virtual void vf_05b();
    virtual void vf_05c();
    virtual void vf_05d();
    virtual void vf_05e();
    virtual void vf_05f();
    virtual void vf_060();
    virtual void vf_061();
    virtual void vf_062();
    virtual void vf_063();
    virtual void vf_064();
    virtual void vf_065();
    virtual void vf_066();
    virtual void vf_067();
    virtual void vf_068();
    virtual void vf_069();
    virtual void vf_06a();
    virtual void vf_06b();
    virtual void vf_06c();
    virtual void vf_06d();
    virtual void vf_06e();
    virtual void vf_06f();
    virtual void vf_070();
    virtual void vf_071();
    virtual void vf_072();
    virtual void vf_073();
    virtual void vf_074();
    virtual void vf_075();
    virtual void vf_076();
    virtual void vf_077();
    virtual void vf_078();
    virtual void vf_079();
    virtual void vf_07a();
    virtual void vf_07b();
    virtual void vf_07c();
    virtual void vf_07d();
    virtual void vf_07e();
    virtual void vf_07f();
    virtual void vf_080();
    virtual void vf_081();
    virtual void vf_082();
    virtual void vf_083();
    virtual void vf_084();
    virtual void vf_085();
    virtual void vf_086();
    virtual void vf_087();
    virtual void vf_088();
    virtual void vf_089();
    virtual void vf_08a();
    virtual void vf_08b();
    virtual void vf_08c();
    virtual void vf_08d();
    virtual void vf_08e();
    virtual void vf_08f();
    virtual void vf_090();
    virtual void vf_091();
    virtual void vf_092();
    virtual void vf_093();
    virtual void vf_094();
    virtual void vf_095();
    virtual void vf_096();
    virtual void vf_097();
    virtual void vf_098();
    virtual void vf_099();
    virtual void vf_09a();
    virtual void vf_09b();
    virtual void vf_09c();
    virtual void vf_09d();
    virtual void vf_09e();
    virtual void vf_09f();
    virtual void vf_0a0();
    virtual void vf_0a1();
    virtual void vf_0a2();
    virtual void vf_0a3();
    virtual void vf_0a4();
    virtual void vf_0a5();
    virtual void vf_0a6();
    virtual void vf_0a7();
    virtual void vf_0a8();
    virtual void vf_0a9();
    virtual void vf_0aa();
    virtual void vf_0ab();
    virtual void vf_0ac();
    virtual void vf_0ad();
    virtual void vf_0ae();
    virtual void vf_0af();
    virtual void vf_0b0();
    virtual void vf_0b1();
    virtual void vf_0b2();
    virtual void vf_0b3();
    virtual void vf_0b4();
    virtual void vf_0b5();
    virtual void vf_0b6();
    virtual void vf_0b7();
    virtual void vf_0b8();
    virtual void vf_0b9();
    virtual void vf_0ba();
    virtual void vf_0bb();
    virtual void vf_0bc();
    virtual void vf_0bd();
    virtual void vf_2f8(float dt);

    char pad[0x90 - 4];
    float unk90;
    char pad2[0xa4 - 0x90 - 4];
    float unka4;

    void Update(int param_1);
};

// Computes clamped delta time from the global clock, accumulates it into unk90, and calls vf_2f8 when the interface check passes.
// @fnv 0x0081df60
void Class_0081df60::Update(int param_1)
{
    float dt3;
    float time = DAT_011e0e80.FUN_0096d490();
    dt3 = time - unka4;

    if (unka4 > time || unka4 < 0.0)
    {
        dt3 = 0.0f;
        if (time > 0.0 && time < 0.30000001192092896)
        {
            dt3 = time;
        }
    }

    unka4 = time;
    if (DAT_011d8804->FUN_007014e0(1) > 0.0)
        return;
    unk90 += dt3;
    vf_2f8(dt3);
}

namespace fnv_0081e040 {
struct Vector3
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

struct GameTimerRecord
{
    unsigned int GetTime() const;
};

struct S86a0
{
    int GetProjectileType();
};

void* __cdecl operator new(unsigned int size);

struct Host096d450
{
    void __thiscall FUN_0096d450(void* object, int a, bool b, bool c, void* d);
};

extern Host096d450 DAT_011e0e80;

struct FUN_0080f810
{
    unsigned char m_data[0xc4];

    FUN_0080f810(void* a, int b, GameTimerRecord* c, unsigned int d, Vector3 e, Vector3 f, unsigned int g, unsigned int h);
};

struct FUN_00811980
{
    unsigned char m_data[0xd8];

    FUN_00811980(void* a, int b, GameTimerRecord* c, unsigned int d, Vector3 e, Vector3 f);
};

struct FUN_00819360
{
    unsigned char m_data[0xd0];

    FUN_00819360(void* a, int b, GameTimerRecord* c, unsigned int d, Vector3 e, Vector3 f, unsigned int g, unsigned int h);
};

struct FUN_00822920
{
    unsigned char m_data[0xa8];

    FUN_00822920(void* a, int b, GameTimerRecord* c, unsigned int d, Vector3 e, Vector3 f);
};

FUN_0080f810::FUN_0080f810(void*, int, GameTimerRecord*, unsigned int, Vector3, Vector3, unsigned int, unsigned int)
{}

FUN_00811980::FUN_00811980(void*, int, GameTimerRecord*, unsigned int, Vector3, Vector3)
{}

FUN_00819360::FUN_00819360(void*, int, GameTimerRecord*, unsigned int, Vector3, Vector3, unsigned int, unsigned int)
{}

FUN_00822920::FUN_00822920(void*, int, GameTimerRecord*, unsigned int, Vector3, Vector3)
{}

// Constructs one of four class instances based on projectile->GetProjectileType() and passes it to DAT_011e0e80.
// @fnv 0x0081e040
void __cdecl FUN_0081e040(void* a, unsigned int b, unsigned int c, int d, GameTimerRecord* timer, S86a0* projectile,
                          Vector3 first, Vector3 second)
{
    void* result = 0;
    unsigned int currentTime;

    currentTime = projectile ? (unsigned int)projectile : timer->GetTime();

    switch (projectile->GetProjectileType())
    {
    case 0:
        result = new FUN_0080f810(a, d, timer, currentTime, first, second, b, c);
        break;

    case 1:
        result = new FUN_00811980(a, d, timer, currentTime, first, second);
        break;

    case 3:
        result = new FUN_00819360(a, d, timer, currentTime, first, second, b, c);
        break;

    case 2:
        result = new FUN_00822920(a, d, timer, currentTime, first, second);
        break;
    }

    if (result)
        DAT_011e0e80.FUN_0096d450(result, 0, 0, 0, 0);
}
}  // namespace fnv_0081e040
