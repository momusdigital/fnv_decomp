
// src/havok/physics/dynamics/entity/hkprigidbody.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/entity/hkprigidbody.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00ca86c0_class
{
    unsigned int __thiscall FUN_00ca86c0();
};
// @fnv 0x00ca86c0
unsigned int __thiscall FUN_00ca86c0_class::FUN_00ca86c0()
{
    unsigned char m_0xe8 = *(unsigned char*)((char*)this + 0xe8);
    if (m_0xe8 != 4 && m_0xe8 != 5)
        return 0;
    return *(unsigned int*)((char*)this + 0x1f8);
}

struct FUN_00ca88c0_Class
{
    void FUN_00ca88c0(float f);
};

// @fnv 0x00ca88c0
void FUN_00ca88c0_Class::FUN_00ca88c0(float afValue)
{
    ((void(__thiscall*)(void*, float))(*(void**)(*(int*)((char*)this + 0xe0) + 12)))((char*)this + 0xe0, afValue);
}

struct FUN_00ca80c0_Class
{
    int __fastcall FUN_00ca80c0();
};
// @fnv 0x00ca80c0
int __fastcall FUN_00ca80c0_Class::FUN_00ca80c0()
{
    return *(unsigned char*)(this + 0xe9) != 0xff;
}

struct FUN_00ca8900_Class
{
    void FUN_00ca8900(float f, int i);
};

// @fnv 0x00ca8900
void FUN_00ca8900_Class::FUN_00ca8900(float f, int i)
{
    *(float*)((char*)this + 0x90) = f;
}

struct FUN_00ca8910_class
{
    void FUN_00ca8910(float v);
};
// @fnv 0x00ca8910
void FUN_00ca8910_class::FUN_00ca8910(float v)
{
    *(float*)((char*)this + 0x94) = v;
}

struct FUN_00ca80b0_cls
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
    int m_iValueAtF0;

    int* FUN_00ca80b0();
};

// @fnv 0x00ca80b0
int* FUN_00ca80b0_cls::FUN_00ca80b0()
{
    return &m_iValueAtF0;
}

extern float DAT_01016248;
struct Vector3
{
    float x, y, z;
};
struct Output
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44, unk48;
    float value;
};
inline float lowerPair(float left, float right)
{
    return left < right ? left : right;
}
inline float lowerPairReversed(float left, float right)
{
    return left > right ? right : left;
}
// Computes the minimum of the three components of values and stores 0.2 times it in result->value if below DAT_01016248, otherwise 0.1.
// @fnv 0x00ca80d0
void __fastcall ComputeScaledMinimum(const Vector3* values, Output* result)
{
    float firstMinimum = lowerPair(values->x, values->y);
    float minimum = lowerPair(firstMinimum, values->z);
    if (DAT_01016248 > minimum)
        result->value = 0.2 * minimum;
    else
        result->value = 0.1f;
}

struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;
};
struct Subobject
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void update(unsigned int value);
};
struct Owner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    Subobject subobjectE0;
    void FUN_00ca8150(unsigned int value, Vec4* result);
    void FUN_00ca85f0(unsigned int value);
};
// @fnv 0x00ca85f0
void Owner::FUN_00ca85f0(unsigned int value)
{
    subobjectE0.update(value);
    unsigned int source = unk10;
    Vec4 result;
    FUN_00ca8150(source, &result);
}

struct CA86E0Object
{
    int unk00;
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
    int unk30;
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char unkE8;
    unsigned char unkE9;
    unsigned char unkEA;
    unsigned char unkEB;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    void* unk1F8;

    void* FUN_00ca86e0();
};

// @fnv 0x00ca86e0
void* CA86E0Object::FUN_00ca86e0()
{
    if (unkE8 == 4 || unkE8 == 5)
        return unk1F8;
    return 0;
}

struct AudioInterface;
struct AudioInterfaceVTable
{
    void* slot00;
    void* slot04;
    void* slot08;
    void* slot0C;
    void* slot10;
    void* slot14;
    void* slot18;
    void* slot1C;
    void* slot20;
    void* slot24;
    void* slot28;
    void* slot2C;
    void(__thiscall* dispatch)(AudioInterface*, int);
};
struct AudioInterface
{
    AudioInterfaceVTable* vtbl;
};
struct FUN_00ca8800_Class
{
    int unk00;
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
    int unk30;
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    AudioInterface interfaceE0;
    void FUN_00ca8800(int value);
};
extern "C" void __cdecl FUN_00ca8700(FUN_00ca8800_Class* self);
// Calls the interface's dispatch with value, then invokes FUN_00ca8700 on this object.
// @fnv 0x00ca8800
void FUN_00ca8800_Class::FUN_00ca8800(int value)
{
    interfaceE0.vtbl->dispatch(&interfaceE0, value);
    FUN_00ca8700(this);
}

struct CA8830Member
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void setValue(int value);
};

struct CA8830Object;

void __cdecl FUN_00ca8700(CA8830Object* obj);

struct CA8830Object
{
    char unk000[0xe0];
    CA8830Member m_kMemberDescriptor;

    void FUN_00ca8830(int value);
};

// Calls setValue on the member with value, then passes this to FUN_00ca8700.
// @fnv 0x00ca8830
void CA8830Object::FUN_00ca8830(int value)
{
    m_kMemberDescriptor.setValue(value);
    FUN_00ca8700(this);
}

struct SubObject;

typedef void(__thiscall* SubDoFn)(SubObject* apThis, int aiFirst, int aiSecond);

struct SubObjectVtbl
{
    void* fn00;
    void* fn04;
    void* fn08;
    void* fn0c;
    void* fn10;
    void* fn14;
    void* fn18;
    void* fn1c;
    void* fn20;
    void* fn24;
    void* fn28;
    void* fn2c;
    void* fn30;
    void* fn34;
    SubDoFn Do;
};

struct SubObject
{
    SubObjectVtbl* m_pVtbl;
};

void __cdecl FUN_00ca8700(void* apOwner);

struct FUN_00ca8860_cls
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
    SubObject m_sub;
    void FUN_00ca8860(int aiFirst, int aiSecond);
};

// Calls the sub-object's Do virtual with aiFirst and aiSecond, then invokes FUN_00ca8700 on this.
// @fnv 0x00ca8860
void FUN_00ca8860_cls::FUN_00ca8860(int aiFirst, int aiSecond)
{
    m_sub.m_pVtbl->Do(&m_sub, aiFirst, aiSecond);
    FUN_00ca8700(this);
}

struct CA8B80Point3
{
    float x;
    float y;
    float z;
};

struct CA8B80Command
{
    unsigned char m_type;
    void* m_pOwnerObject;
    float x;
    float y;
    float z;
};

struct CA8B80Queue
{
    int unk00;
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
    int unk30;
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
    void* m_bSlotEnabled;

    void Push(CA8B80Command* pkCommand);
};

struct CA8B80Handler
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void SetPosition(const CA8B80Point3& kPos);
};

struct CA8B80Object
{
    int unk00;
    int unk04;
    CA8B80Queue* m_queue;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    CA8B80Handler m_handler;

    void Update();
    void FUN_00ca8b80(const CA8B80Point3& kPos);
};

// @fnv 0x00ca8b80
void CA8B80Object::FUN_00ca8b80(const CA8B80Point3& kPos)
{
    if (m_queue && m_queue->m_bSlotEnabled)
    {
        CA8B80Command kCommand;
        kCommand.m_type = 0x1d;
        kCommand.x = kPos.x;
        kCommand.m_pOwnerObject = this;
        kCommand.y = kPos.y;
        kCommand.z = kPos.z;
        m_queue->Push(&kCommand);
        return;
    }
    Update();
    m_handler.SetPosition(kPos);
}

struct FUN_00ca9240_Base
{
    int unk04;
    unsigned char type;
    FUN_00ca9240_Base(int a, int b, int c);
    virtual void unk00();
};

struct FUN_00ca9240 : FUN_00ca9240_Base
{
    FUN_00ca9240(int a, int b);
    virtual void unk04();
};

// Constructs the base with a and b and a zero, then sets type to 7.
// @fnv 0x00ca9240
FUN_00ca9240::FUN_00ca9240(int aiValueA, int aiValueB) : FUN_00ca9240_Base(aiValueA, aiValueB, 0)
{
    type = 7;
}

struct BaseRecord
{
    virtual void v00();

    int m_i04;
    char m_c08;

    BaseRecord(void* apFirst, void* apSecond, int aiFlag);
};

struct FUN_00ca9270 : BaseRecord
{
    FUN_00ca9270(void* apFirst, void* apSecond);
};

// Constructs the object by forwarding apFirst and apSecond to BaseRecord with flag 0, then sets m_c08 to 2.
// @fnv 0x00ca9270
FUN_00ca9270::FUN_00ca9270(void* apFirst, void* apSecond) : BaseRecord(apFirst, apSecond, 0)
{
    m_c08 = 2;
}

struct FUN_00ca80a0_base
{
    virtual ~FUN_00ca80a0_base();
};

struct FUN_00ca80a0_cls : FUN_00ca80a0_base
{
    virtual ~FUN_00ca80a0_cls();
};

// @fnv 0x00ca80a0
FUN_00ca80a0_cls::~FUN_00ca80a0_cls()
{}

struct S_00ca8630_Owner
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned char unk300;
    unsigned char unk301;
    unsigned char unk302;
    unsigned char unk303;
    unsigned char unk304;
    unsigned char unk305;
    unsigned char unk306;
    unsigned char unk307;
};
struct S_00ca8630_Sub
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
    unsigned short unk0a;
    unsigned short unk0c;
    void SetFlagBits(int a, int b, int c);
    __forceinline void Set(unsigned char v, int a, int b, int c)
    {
        unk09 = v;
        SetFlagBits(a, b, c);
    }
};
struct S_00ca8630_Class
{
    unsigned int unk00;
    unsigned int unk04;
    S_00ca8630_Owner* unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned char unkd4;
    unsigned char unkd5;
    unsigned char unkd6;
    unsigned char unkd7;
    unsigned int unkd8;
    unsigned int unkdc;
    S_00ca8630_Sub unke0;
    void FUN_00ca8630(bool f);
};
// @fnv 0x00ca8630
void S_00ca8630_Class::FUN_00ca8630(bool f)
{
    if (f)
    {
        if (unk08)
        {
            S_00ca8630_Owner* volatile* pv = (S_00ca8630_Owner* volatile*)&unk08;
            S_00ca8630_Owner* o = *pv;
            int c = o->unk307;
            int b = o->unk306;
            int a = o->unk305;
            unke0.Set(unkd4 & 0xf, a, b, c);
        }
        else
        {
            unke0.Set(unkd4 & 0xf, 0, 0, 0);
        }
    }
    else
    {
        unke0.unk09 = 0xff;
        unke0.unk0a = 0;
        unke0.unk0c = 0;
    }
}

struct CA8890Member
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void setValue(int value);
};

struct CA8890Object;

void __cdecl FUN_00ca8700(CA8890Object* obj);

struct CA8890Object
{
    int unk00;
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
    int unk30;
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    CA8890Member m_kMemberDescriptor;

    void FUN_00ca8890(int value);
};

// Calls setValue on the member with value, then calls FUN_00ca8700 on this object.
// @fnv 0x00ca8890
void CA8890Object::FUN_00ca8890(int value)
{
    m_kMemberDescriptor.setValue(value);
    FUN_00ca8700(this);
}

struct SpawnedSub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(float f);
};

struct FUN_00ca88e0_cls
{
    int unk00;
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
    int unk30;
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    SpawnedSub m_sub;

    void FUN_00ca88e0(float f);
};

// @fnv 0x00ca88e0
void FUN_00ca88e0_cls::FUN_00ca88e0(float afValue)
{
    m_sub.v10(afValue);
}

struct CA92A0Allocator;

struct CA92A0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CA92A0Allocator* m_pStreamAllocator;

    CA92A0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" CA92A0MemoryRouter& __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(CA92A0Allocator* alloc, void* array, int numElements, int sizeElem);

struct CA92A0Element
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    static void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
};

struct CA92A0Array
{
    CA92A0Element* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void reserve(CA92A0Allocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(CA92A0Element));
        }
    }

    __forceinline CA92A0Array& operator=(const CA92A0Array& a)
    {
        CA92A0Allocator& alloc = FUN_00c85750().heap();
        const int oldSize = m_iElementCount;
        const int newSize = a.m_iElementCount;
        const int copiedSize = newSize > oldSize ? oldSize : newSize;
        reserve(alloc, newSize);
        {
            const CA92A0Element* src = a.m_data;
            CA92A0Element* dst = m_data;
            for (int i = 0; i < copiedSize; i++)
                dst[i] = src[i];
        }
        {
            const CA92A0Element* src = a.m_data + copiedSize;
            CA92A0Element* dst = m_data + copiedSize;
            for (int i = 0; i < newSize - copiedSize; i++)
                new (dst + i) CA92A0Element(src[i]);
        }
        m_iElementCount = newSize;
        return *this;
    }
};

struct CA92A0Object
{
    int unk00;
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
    int unk30;
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
    CA92A0Array m_entries;

    void CopyEntriesFrom(const CA92A0Object* other);
};

// Copies the m_entries array from other into this object's m_entries via the array assignment operator.
// @fnv 0x00ca92a0
void CA92A0Object::CopyEntriesFrom(const CA92A0Object* other)
{
    m_entries = other->m_entries;
}

struct CA92A0Allocator
{
    virtual void v00();
    virtual void* Alloc(unsigned int auiSize);
};

extern int DAT_010c6c64;

static __forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    do
    {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d += 4;
        s += 4;
    } while (--numQuads > 0);
}

__declspec(align(16)) struct FnvScratch
{
    int unk00;
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
    int unk30;
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    void FUN_00cf5ea0();
};

struct FnvSubObj
{
    void FUN_00cb0c10(unsigned int auiFlags);
};

struct FnvThing
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* v0C(void* pOwner);
};

struct FUN_00ca90c0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    FUN_00ca90c0_cls* Clone();
    void WriteToInfo(FnvScratch* pScratch);
    FUN_00ca90c0_cls* FUN_00ca8c90(FnvScratch* pScratch);
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual int v10();
    void CopyEntriesFrom(FUN_00ca90c0_cls* pSrc);
};

// @fnv 0x00ca90c0
FUN_00ca90c0_cls* FUN_00ca90c0_cls::Clone()
{
    FnvScratch cinfo;
    cinfo.FUN_00cf5ea0();
    WriteToInfo(&cinfo);
    FUN_00ca90c0_cls* pBlock = (FUN_00ca90c0_cls*)FUN_00c85750().heap().Alloc(0x220);
    *(unsigned short*)((char*)pBlock + 4) = 0x220;
    FUN_00ca90c0_cls* pCopy = pBlock->FUN_00ca8c90(&cinfo);
    memCpy16NonEmpty((char*)pCopy + 0xe0, (char*)this + 0xe0, 0x12);
    if (*(char**)((char*)this + 0x1f8))
    {
        char* pObj = (char*)FUN_00c85750().heap().Alloc(0x120);
        *(unsigned short*)(pObj + 4) = 0x120;
        *(int*)(pObj + 0x118) = 0;
        *(int*)pObj = (int)&DAT_010c6c64;
        *(char**)((char*)pCopy + 0x1f8) = pObj;
        memCpy16NonEmpty(pObj, *(char**)((char*)this + 0x1f8), 0x12);
    }
    *(int*)((char*)pCopy + 0x18) = pCopy->v10();
    pCopy->CopyEntriesFrom(this);
    ((FnvSubObj*)((char*)pCopy + 0x74))->FUN_00cb0c10(*(unsigned int*)((char*)this + 0x74) & 0xfffffffe);
    *(int*)((char*)pCopy + 0xc) = *(int*)((char*)this + 0xc);
    if (*(void**)((char*)this + 0xa0))
        *(void**)((char*)pCopy + 0xa0) = ((FnvThing*)*(void**)((char*)this + 0xa0))->v0C(pCopy);
    return pCopy;
}

class hkBoolCA8B
{
  public:
    hkBoolCA8B(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};

class hkpShapeContainerCA8B
{
  public:
    virtual ~hkpShapeContainerCA8B();
    virtual int GetNumChildShapes() const;
};

class hkpShapeCA8B
{
  public:
    virtual ~hkpShapeCA8B();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual const hkpShapeContainerCA8B* GetShapeContainer() const;
    int unk04;
    int unk08;
    int m_type;
};

class hkpShapeCollectionCA8B : public hkpShapeCA8B, public hkpShapeContainerCA8B
{
};

class HostCA8B
{
  public:
    int unk00, unk04, unk08, unk0C;
    const hkpShapeCA8B* m_pCollisionShape;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC;
    int unkD0, unkD4, unkD8, unkDC, unkE0, unkE4;
    unsigned char m_bFlag;

    hkBoolCA8B FUN_00ca8bf0() const;
};

// Returns false for a null shape, type 0xf, or types 7, 8, 9, 10, 0x17 with over 100 child shapes (8 and 10 are skipped when m_bFlag is 4 or 5); else true.
// @fnv 0x00ca8bf0
hkBoolCA8B HostCA8B::FUN_00ca8bf0() const
{
    const hkpShapeCA8B* shape = m_pCollisionShape;
    if (!shape)
        return false;

    bool bOk = true;
    int type = shape->m_type;
    if (m_bFlag != 5 && m_bFlag != 4 && (type == 10 || type == 8))
    {
        if (shape->GetShapeContainer()->GetNumChildShapes() > 100)
            bOk = false;
    }

    if (type == 0x17)
    {
        if (static_cast<const hkpShapeCollectionCA8B*>(m_pCollisionShape)->GetNumChildShapes() > 100)
            bOk = false;
    }
    else if (type == 7)
    {
        if (static_cast<const hkpShapeCollectionCA8B*>(m_pCollisionShape)->GetNumChildShapes() > 100)
            bOk = false;
    }
    else if (type == 0xf)
    {
        bOk = false;
    }
    else if (type == 9)
    {
        if (static_cast<const hkpShapeCollectionCA8B*>(shape)->GetNumChildShapes() > 100)
            bOk = false;
    }
    return bOk;
}

struct S_00ca84b0_Shape
{
    void RetainReference();  // FUN_00c90510
    void removeReference();  // FUN_00c905b0
};

struct S_00ca84b0_Entity;

struct S_00ca84b0_Op
{
    unsigned char m_type;
    S_00ca84b0_Entity* m_pEntity;
    S_00ca84b0_Shape* m_pCollisionShape;
};

struct S_00ca84b0_World
{
    void FUN_00c91160(const S_00ca84b0_Op& op);
    void FUN_00c91120();
    void FUN_00c91140();

    __forceinline void lockCriticalOperations()
    {
        unk94++;
    }
    __forceinline void unlockAndAttemptToExecutePendingOperations()
    {
        unk94--;
        if (unk94 == 0 && !unk9c)
        {
            if (unk8c)
                FUN_00c91120();
            if (unka4 == 1 && unk90)
                FUN_00c91140();
        }
    }

    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    unsigned char unk9c;
    int unka0;
    int unka4;
};

struct S_00ca84b0_Vector4
{
    float x, y, z, w;
};

void FUN_00cb5c10(S_00ca84b0_World* world, S_00ca84b0_Entity* entity);
void FUN_00cb59f0(S_00ca84b0_World* world, S_00ca84b0_Entity* entity);
void NotifyShapeSet(S_00ca84b0_World* world, S_00ca84b0_Entity* entity);
void FUN_00cffcf0(S_00ca84b0_Entity* entity);
// Same-unit static helper (0x00ca80d0): the allowed penetration depth is a fifth of the
// smallest extent, or 0.1 once that extent reaches 0.5.
static __declspec(noinline) void ComputeScaledMinimum(void* pvCollidable, const S_00ca84b0_Vector4& kExtent)
{
    const float* pfExtent = (const float*)&kExtent;
    float fMin = pfExtent[0];
    if (pfExtent[1] < fMin)
        fMin = pfExtent[1];
    if (pfExtent[2] < fMin)
        fMin = pfExtent[2];
    float* pfDepth = (float*)((char*)pvCollidable + 0x4c);
    if (fMin < 0.5f)
        *pfDepth = (float)(fMin * 0.2);
    else
        *pfDepth = 0.1f;
}

struct S_00ca84b0_Entity
{
    virtual void vf0();
    int unk4;
    S_00ca84b0_World* m_pOwningWorld;
    int unkc;
    S_00ca84b0_Shape* m_pCollisionShape;
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
    float m_fAllowedPenetrationDepth;  // 0x5c

    void FUN_00ca8150(S_00ca84b0_Shape* shape, S_00ca84b0_Vector4* extentOut);
    void UpdateBoundingVolume(S_00ca84b0_World* world, S_00ca84b0_Shape* shape);
    int setShape(S_00ca84b0_Shape* shape);
};

// Sets the entity's collision shape, updating penetration depth and notifying the owning world of the change.
// @fnv 0x00ca84b0
int S_00ca84b0_Entity::setShape(S_00ca84b0_Shape* shape)
{
    if (m_pOwningWorld && m_pOwningWorld->unk94)
    {
        S_00ca84b0_Op op;
        op.m_type = 5;
        op.m_pEntity = this;
        op.m_pCollisionShape = shape;
        m_pOwningWorld->FUN_00c91160(op);
        return 0;
    }

    if (m_pOwningWorld)
    {
        m_pOwningWorld->lockCriticalOperations();
        FUN_00cb5c10(m_pOwningWorld, this);
    }

    S_00ca84b0_Shape* oldShape = m_pCollisionShape;
    m_pCollisionShape = shape;
    shape->RetainReference();
    if (oldShape)
        oldShape->removeReference();

    {
        __declspec(align(16)) S_00ca84b0_Vector4 extent;
        FUN_00ca8150(shape, &extent);

        if (oldShape && m_fAllowedPenetrationDepth != 3.40282e38f)
            m_fAllowedPenetrationDepth = -1.0f;
        if (m_fAllowedPenetrationDepth <= 0.0f)
            ComputeScaledMinimum(&m_pCollisionShape, extent);
    }

    if (m_pOwningWorld)
        UpdateBoundingVolume(m_pOwningWorld, shape);
    if (m_pOwningWorld)
        NotifyShapeSet(m_pOwningWorld, this);
    FUN_00cffcf0(this);
    if (m_pOwningWorld)
    {
        FUN_00cb59f0(m_pOwningWorld, this);
        m_pOwningWorld->unlockAndAttemptToExecutePendingOperations();
    }
    return 1;
}

#include <xmmintrin.h>
namespace fnv_00ca8af0 {
struct AllocIface
{
    virtual void* unk00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AllocIface* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750() throw();

struct EventBlock
{
    unsigned char m_type;
    void* m_pSender;
    void* m_pData;
};

struct EventDispatcher
{
    int unk00;
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
    int unk30;
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
    int m_94;

    void FUN_00c91160(EventBlock* ev);
};

struct EventSub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50(void* a1, void* a2);
};

struct FUN_00ca8af0_cls
{
    int unk00;
    int unk04;
    EventDispatcher* m_08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    EventSub m_e0;

    void DispatchEvent(void* a1, void* a2);
    void FUN_00c9c1d0();
};

// @fnv 0x00ca8af0
void FUN_00ca8af0_cls::DispatchEvent(void* a1, void* a2)
{
    if (m_08 != 0)
    {
        if (m_08->m_94 != 0)
        {
            EventBlock ev;
            ev.m_type = 0x1c;
            ev.m_pSender = this;
            AllocHolder* holder = FUN_00c85750();
            ev.m_pData = holder->m_pAllocator->Alloc(0x20);
            *(__m128*)ev.m_pData = *(__m128*)a2;
            *(__m128*)((char*)ev.m_pData + 0x10) = *(__m128*)a1;
            m_08->FUN_00c91160(&ev);
            return;
        }
    }
    FUN_00c9c1d0();
    m_e0.v50(a1, a2);
}
}  // namespace fnv_00ca8af0

struct S_00ca8f50_Vec
{
    __m128 m_vComponents;
};
struct S_00ca8f50_Half
{
    short m_uiFilterValue;
    operator float() const
    {
        int t = ((int)m_uiFilterValue) << 16;
        return *(float*)&t;
    }
};
struct S_00ca8f50_Transform
{
    S_00ca8f50_Vec m_kColumn0;
    S_00ca8f50_Vec m_kColumn1;
    S_00ca8f50_Vec m_kColumn2;
};
struct S_00ca8f50_Sub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void getTransform(S_00ca8f50_Transform& out);
    float FUN_00c86430();
    int unk4;
    unsigned char unk8;
    unsigned char unk9;
    unsigned char unkA;
    unsigned char unkB;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};
extern float DAT_010c7948[];
struct S_00ca8f50_Info
{
    int m0;
    int m4;
    int m8;
    unsigned char mC;
    unsigned char unkD;
    short mE;
    S_00ca8f50_Vec m10;
    S_00ca8f50_Vec m20;
    S_00ca8f50_Vec m30;
    S_00ca8f50_Vec m40;
    S_00ca8f50_Transform m50;
    S_00ca8f50_Vec m80;
    float m90;
    float m94;
    float m98;
    float m9C;
    float mA0;
    float mA4;
    float mA8;
    float mAC;
    float mB0;
    unsigned char mB4;
    unsigned char mB5;
    unsigned char mB6;
    unsigned char mB7;
    unsigned char mB8;
    unsigned char mB9;
    unsigned char mBA;
    unsigned char mBB;
    int unkBC;
};

struct S_00ca8f50_Src
{
    bool FUN_00ca80c0();
    void WriteToInfo(S_00ca8f50_Info* info);
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int m10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned char unk20;
    unsigned char m21;
    unsigned char unk22;
    unsigned char unk23;
    int unk24;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char m2A;
    unsigned char unk2B;
    int m2C;
    int unk30;
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
    float m5C;
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
    unsigned char m8C;
    unsigned char unk8D;
    unsigned char unk8E;
    unsigned char unk8F;
    float m90;
    float m94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    unsigned char unkA8;
    unsigned char unkA9;
    short mAA;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    unsigned char mD0;
    unsigned char mD1;
    unsigned char unkD2;
    unsigned char unkD3;
    int unkD4;
    int unkD8;
    int unkDC;
    S_00ca8f50_Sub mE0;
    S_00ca8f50_Vec m120;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    S_00ca8f50_Vec m160;
    S_00ca8f50_Vec m170;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    float m194;
    float m198;
    unsigned char m19C;
    unsigned char m19D;
    unsigned char m19E;
    unsigned char unk19F;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    S_00ca8f50_Vec m1B0;
    S_00ca8f50_Vec m1C0;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    unsigned char unk1FC;
    unsigned char unk1FD;
    S_00ca8f50_Half m1FE;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int m210;
    int unk214;
    int unk218;
    int unk21C;
};

// Copies fields from this S_00ca8f50_Src into the given S_00ca8f50_Info, including vectors, a transform, and lookup-table values.
// @fnv 0x00ca8f50
void S_00ca8f50_Src::WriteToInfo(S_00ca8f50_Info* info)
{
    info->mBB = m21 & 1;
    info->mB8 = mD0;
    info->mBA = mD1;
    info->mE = mAA;
    info->mB5 = FUN_00ca80c0();
    info->m8 = m210;
    info->mA0 = m90;
    info->mC = m8C;
    info->mA4 = m94;
    info->m94 = m194;
    info->m98 = m198;
    info->m30.m_vComponents = m1B0.m_vComponents;
    info->m40.m_vComponents = m1C0.m_vComponents;
    info->m90 = mE0.FUN_00c86430();
    mE0.getTransform(info->m50);
    info->mB4 = mE0.unk8;
    info->mB6 = m19E;
    info->mA8 = DAT_010c7948[m19C];
    info->mAC = DAT_010c7948[m19D];
    info->m10.m_vComponents = m120.m_vComponents;
    info->m20.m_vComponents = m160.m_vComponents;
    info->m80.m_vComponents = m170.m_vComponents;
    info->m4 = m10;
    info->m0 = m2C;
    info->mB0 = m5C;
    info->mB7 = m2A;
    info->m9C = m1FE;
}

namespace fnv_00ca9210 {
struct S_00ca9210_Alloc
{
    virtual ~S_00ca9210_Alloc();
    virtual void* AllocateMemoryBlock(int n);
    virtual void ReleaseBlock(void* p, int n);
};
struct S_00ca9210_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ca9210_Alloc* m_pStreamAllocator;
    S_00ca9210_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00ca9210_Router* FUN_00c85750();

struct S_00ca9210_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00ca9210_RefObj() throw()
    {}
    void operator delete(void* p)
    {
        S_00ca9210_RefObj* b = static_cast<S_00ca9210_RefObj*>(p);
        FUN_00c85750()->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

struct FUN_00ca9210 : S_00ca9210_RefObj
{
    FUN_00ca9210();
    virtual ~FUN_00ca9210() throw();
};

// @fnv 0x00ca9210
FUN_00ca9210::FUN_00ca9210()
{}
}  // namespace fnv_00ca9210

struct Entity;
struct World;

struct Manager
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void* v5();
    virtual void* v6();
    virtual void* v7();
    virtual void v8(void* ents, int count, World* world, int flags);
};

struct Holder5c
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    virtual void v5(int x);
};

struct World
{
    int unk00;
    int unk04;
    Manager* m_8;
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
    Holder5c* m_5c;
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
    int m_8c;
    int m_90;
    int m_94;
    int unk98;
    unsigned char m_9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
    int unk_a0;
    int m_a4;
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
    unsigned char unk_d4;
    unsigned char unk_d5;
    unsigned char m_d6;
    void __thiscall FUN_00c91160(void* op);
    void __thiscall FUN_00c91120();
    void __thiscall FUN_00c91140();
};

struct Entity
{
    int unk00;
    int unk04;
    World* m_8;
    int unk0c;
    int m_10;
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
    unsigned char m_e8;
    unsigned char* __thiscall FUN_00c9bff0(unsigned char* out);
    void __thiscall FUN_00c9c1d0();
};

struct Op
{
    unsigned char type;
    void* entity;
};

extern void __cdecl FUN_00cf9c60(void* ents, int count, World* world);
extern void __cdecl NotifyEntityRemoved(World* world, Entity* entity);

// Processes an entity by dispatching an operation, updating the world manager, and handling post-processing callbacks based on world state.
// @fnv 0x00ca8700
void __cdecl FUN_00ca8700(Entity* apEntity)
{
    Op op;
    World* world = apEntity->m_8;

    if (!world)
        return;

    if (world->m_94 != 0)
    {
        op.type = 0x16;
        op.entity = apEntity;
        world->FUN_00c91160(&op);
        return;
    }

    world->m_94 = 1;
    {
        Entity* ents[1];
        Manager* pManager = world->m_8;
        ents[0] = apEntity;
        pManager->v8(ents, 1, world, 7);

        if (apEntity->m_10 != 0)
            FUN_00cf9c60(ents, 1, world);
    }

    unsigned char flag;
    if (!*apEntity->FUN_00c9bff0(&flag))
    {
        if (world->m_d6 != 0 && apEntity->m_e8 != 5)
            apEntity->FUN_00c9c1d0();
        NotifyEntityRemoved(world, apEntity);
    }

    if (world->m_5c != 0)
        world->m_5c->v5(0);

    world->m_94 -= 1;
    if (world->m_94 == 0 && world->m_9c == 0)
    {
        if (world->m_8c != 0)
            world->FUN_00c91120();
        if (world->m_a4 == 1 && world->m_90 != 0)
            world->FUN_00c91140();
    }
}

// @fnv 0x00ca8920
void __fastcall FUN_00ca8920(FUN_00ca8860_cls* body, void*, int inertia)
{
    SubObject* motion = &body->m_sub;
    typedef void(__thiscall * SetInertia)(SubObject*, int);
    SetInertia set = reinterpret_cast<SetInertia>(motion->m_pVtbl->fn1c);
    set(motion, inertia);
}
