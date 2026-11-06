
// src/fallout/misc/saveload/bgssaveformbuffer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/saveload/bgssaveformbuffer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00865aa0_shell
{
    unsigned char c;
    void __thiscall SetFlags(unsigned int a);
};

// Stores the low 2 bits of a into the upper 2 bits of c, preserving c's lower 6 bits.
// @fnv 0x00865aa0
void __thiscall FUN_00865aa0_shell::SetFlags(unsigned int a)
{
    c = (c & 0x3f) | (a << 6);
}

struct FUN_00865b10_shell
{
    unsigned char c;
    unsigned int __thiscall GetValuePlusNine();
};

unsigned int __cdecl GetSaveIntegerSizeTag(unsigned int);
unsigned int __cdecl FUN_00845d70(unsigned int);
struct _ref_0084e3a0_shell
{
    unsigned int __thiscall _ref_0084e3a0();
};

// Calls _ref_0084e3a0, passes the result through GetSaveIntegerSizeTag and FUN_00845d70, then returns that value plus 9.
// @fnv 0x00865b10
unsigned int __thiscall FUN_00865b10_shell::GetValuePlusNine()
{
    unsigned int value = FUN_00845d70(GetSaveIntegerSizeTag(reinterpret_cast<_ref_0084e3a0_shell*>(this)->_ref_0084e3a0()));
    return value + 9;
}

struct TESForm
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
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
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual bool IsReference();
};
struct TESObjectREFR : TESForm
{
};
struct BGSSaveFormBuffer
{
    virtual TESForm* GetForm();
    TESObjectREFR* GetFormAsReference();
};
// Returns the buffer's form cast to TESObjectREFR if it is a reference, otherwise returns null.
// @fnv 0x00865b40
TESObjectREFR* BGSSaveFormBuffer::GetFormAsReference()
{
    TESForm* pform = GetForm();
    if (pform)
    {
        if (pform->IsReference())
        {
            return (TESObjectREFR*)pform;
        }
    }
    return 0;
}

namespace fnv_00865b80 {
struct Actor;
struct TESObjectREFR
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54()
    {}
    virtual void v55()
    {}
    virtual void v56()
    {}
    virtual void v57()
    {}
    virtual void v58()
    {}
    virtual void v59()
    {}
    virtual void v60()
    {}
    virtual void v61()
    {}
    virtual void v62()
    {}
    virtual void v63()
    {}
    virtual bool IsActor()
    {
        return false;
    }
};
struct Actor : TESObjectREFR
{
};
struct BGSSaveFormBuffer
{
    virtual void b00()
    {}
    virtual TESObjectREFR* GetReference()
    {
        return 0;
    }
    Actor* GetActorReference();
};
// Returns the buffer's reference cast to Actor if it is an actor, otherwise returns null.
// @fnv 0x00865b80
Actor* BGSSaveFormBuffer::GetActorReference()
{
    TESObjectREFR* pref = GetReference();
    if (pref && pref->IsActor())
        return (Actor*)pref;
    return 0;
}
}  // namespace fnv_00865b80

namespace fnv_00865ad0 {
struct PackedFormID
{
    void __thiscall WriteFormIDBytes(unsigned int a);
};
struct BGSFormInfo
{
    void __thiscall FUN_00853670(unsigned int a);
};
struct BGSSaveFormBuffer
{
    unsigned char _pad[0x14];
    PackedFormID m_FormIDIndex;
    unsigned int m_iChangeFlags;
    BGSFormInfo m_FormInfo;
    unsigned char m_cVersion;
    void __thiscall InitFormEntry(unsigned int aiFormID, unsigned int aiChangeFlags, unsigned int aeFormType,
                                  unsigned char acVersion);
};

// Stores the form ID, change flags, form type and version into this save-form buffer's fields.
// @fnv 0x00865ad0
void BGSSaveFormBuffer::InitFormEntry(unsigned int aiFormID, unsigned int aiChangeFlags, unsigned int aeFormType,
                                      unsigned char acVersion)
{
    ((PackedFormID*)((char*)this + 0x14))->WriteFormIDBytes(aiFormID);
    ((unsigned int*)((char*)this + 0x17))[0] = aiChangeFlags;
    ((BGSFormInfo*)((char*)this + 0x1b))->FUN_00853670(aeFormType);
    ((unsigned char*)this + 0x1c)[0] = acVersion;
}
}  // namespace fnv_00865ad0

struct BGSSaveGameBuffer
{
    virtual void bufferMethod();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    BGSSaveGameBuffer();
    ~BGSSaveGameBuffer();
};
struct FormLoadContext
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    FormLoadContext();
};
struct FUN_008659c0 : BGSSaveGameBuffer
{
    FormLoadContext header;
    int unk20;
    FUN_008659c0();
};
// @fnv 0x008659c0
FUN_008659c0::FUN_008659c0() : BGSSaveGameBuffer(), header()
{
    unk20 = 0;
}

struct FUN_00865c80_shell
{
    unsigned char c;
    void __thiscall FUN_00865c80(void* buffer, unsigned int value);
};
struct FUN_00846330_shell
{
    void __thiscall WriteToFile(void* data, int size);
};

unsigned int __cdecl GetSaveIntegerSizeTag(unsigned int);
void __cdecl WriteValueByType(void*, unsigned int, unsigned int);
struct FUN_00865a30_owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void __thiscall FUN_00865a30(void* buffer);
};
// @fnv 0x00865a30
void FUN_00865a30_owner::FUN_00865a30(void* buffer)
{
    unsigned int secondValue = ((_ref_0084e3a0_shell*)this)->_ref_0084e3a0();
    unsigned int firstValue = GetSaveIntegerSizeTag(secondValue);
    ((FUN_00865aa0_shell*)((char*)this + 0x1b))->SetFlags(firstValue);
    ((FUN_00846330_shell*)buffer)->WriteToFile((char*)this + 0x14, 9);
    WriteValueByType(buffer, secondValue, firstValue);
    ((FUN_00865c80_shell*)this)->FUN_00865c80(buffer, secondValue);
}
