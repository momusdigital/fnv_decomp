
// src/bsmenu/debugtext.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsmenu/debugtext.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct DebugText {
    int GetEntry(int);
};

// @fnv 0x00a0e750
int DebugText::GetEntry(int aiIndex)
{
    return *(int*)((char*)this + aiIndex * 4 + 0x2284);
}

namespace fnv_00a11860 {
enum DEBUGTEXT_LOCATION { DTL_NONE };
struct DebugText {
    int m_lines[0x861];
    void __thiscall SetLine(DEBUGTEXT_LOCATION aeLoc, int aiLine);
};
// @fnv 0x00a11860
void __thiscall DebugText::SetLine(DEBUGTEXT_LOCATION aeLoc, int aiLine)
{
    *(int*)((char*)this + 0x2284 + (int)aeLoc * 4) = aiLine;
}
}  // namespace fnv_00a11860

struct GlobalObject_00a7b610;

extern GlobalObject_00a7b610 g_011f33d4;

struct FUN_00a11b70_shell {
    GlobalObject_00a7b610* __thiscall GetGlobalObject();
};

// @fnv 0x00a11b70
GlobalObject_00a7b610* __thiscall FUN_00a11b70_shell::GetGlobalObject()
{
    return &g_011f33d4;
}

struct DebugText_00a0e430 {
    void __thiscall AddScaledValue(int a, int b);
};

// Adds the value at this+0x2280 multiplied by b to the int at this+0x2284 indexed by a.
// @fnv 0x00a0e430
void __thiscall DebugText_00a0e430::AddScaledValue(int aiIndex, int aiMultiplier)
{
    *(int*)((char*)this + 0x2284 + aiIndex * 4) += *(int*)((char*)this + 0x2280) * aiMultiplier;
}

struct VCall_00a0e470 {
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4(int, int, int, const char*, char*, int);
};
// @fnv 0x00a0e470
int __cdecl FUN_00a0e470(DebugText* apDebugText, int aiX, const char* apFormatString, ...)
{
    int iret;
    {
        char* args;
        args = (char*)(&apFormatString + 1);
        iret = ((VCall_00a0e470*)apDebugText)->f4(aiX, 0, 1, apFormatString, args, 0);
    }
    return iret;
}

struct FakeV_00a0e4b0 {
    virtual void f0() {}
    virtual void f1() {}
    virtual void f2() {}
    virtual void f3() {}
    virtual int f4(int, int, int, int, char*, int) { return 0; }
};
// Calls the virtual method f4 on p with a, b, c, d, a pointer to e, and 0, returning its result.
// @fnv 0x00a0e4b0
int __cdecl InvokeVirtualWithArgs(FakeV_00a0e4b0* apObject, int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5)
{
    char* args;
    int iret;
    args = (char*)&aiArg5;
    iret = apObject->f4(aiArg1, aiArg2, aiArg3, aiArg4, args, 0);
    return iret;
}

struct FUN_00a0e580_VTab {
    virtual int m0();
    virtual int m1();
    virtual int m2();
    virtual int m3();
    virtual int m4();
    virtual int m5();
    virtual int __thiscall m6(int, int, const char*, char*, int);
};
// @fnv 0x00a0e580
int __cdecl FUN_00a0e580(FUN_00a0e580_VTab* pThis, int aeLocation, int aeJustify, const char* apFormatString, ...)
{
    char* args;
    int iret;
    args = (char*)(&apFormatString + 1);
    iret = pThis->m6(aeLocation, aeJustify, apFormatString, args, 0);
    return iret;
}

struct RgbaColor { float r; float g; float b; float a; };
struct FakeCall {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4(int, int, int, const char*, char*, const RgbaColor&);
};
// Forwards a format string and its varargs to the object's virtual f4 with x, 0, 1 and a color, returning its result.
// @fnv 0x00a0e690
int FUN_00a0e690(DebugText* aObj, int aiX, const RgbaColor& arColor, const char* apFormatString, ...)
{
    char* args;
    int iret;
    args = (char*)(&apFormatString + 1);
    iret = ((FakeCall*)aObj)->f4(aiX, 0, 1, apFormatString, args, arColor);
    return iret;
}

struct FUN_00a0e6d0_this {
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int VFunc(int, int, int, const char*, char*, void*);
};
// Forwards p1, p3, p4, p5, the varargs pointer and p2 to the virtual VFunc and returns its result.
// @fnv 0x00a0e6d0
int __cdecl InvokeVFuncWithVarArgs(FUN_00a0e6d0_this* pObject, int aiArg1, void* apArg2, int aiArg3, int aiArg4, const char* p5, ...)
{
    int iret;
    {
        char* args;
        args = (char*)(&p5 + 1);
        iret = pObject->VFunc(aiArg1, aiArg3, aiArg4, p5, args, apArg2);
    }
    return iret;
}

namespace fnv_00a0e710 {
typedef char* va_list;
struct RgbaColor { float r; };
enum DEBUGTEXT_LOCATION { DEBUGTEXT_LOCATION_0 };
enum DEBUGTEXT_JUSTIFY { DEBUGTEXT_JUSTIFY_0 };
struct Thiss {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual int vf18(DEBUGTEXT_LOCATION, DEBUGTEXT_JUSTIFY, const char*, va_list, const RgbaColor*);
};
// Forwards a format string and its va_list to the virtual vf18 debug-text method and returns its result.
// @fnv 0x00a0e710
int FUN_00a0e710(Thiss* pThis, const RgbaColor* apTextColor, DEBUGTEXT_LOCATION aeLocation, DEBUGTEXT_JUSTIFY aeJustify, const char* apFormatString, ...)
{
    va_list args;
    int iret;
    args = (va_list)&apFormatString + 4;
    iret = pThis->vf18(aeLocation, aeJustify, apFormatString, args, apTextColor);
    return iret;
}
}  // namespace fnv_00a0e710

extern "C" unsigned char __cdecl IsDebugTextVisible();
extern int DAT_011f33dc;
extern void (__stdcall *DAT_00fdf05c)(int*);

// @fnv 0x00a11820
void __cdecl FUN_00a11820()
{
    if (IsDebugTextVisible())
        DAT_00fdf05c(&DAT_011f33dc);
}

struct NiTMapItem {
    unsigned int key;
    void* data;
    void* extra;
};
struct NiTPointerMap {
    void NewItem(NiTMapItem* item);
};
struct P03MM {
    void* __thiscall Allocate(unsigned int size);
};
extern P03MM g_memoryManager;
struct ChangeData;
struct FUN_00a11c00_shell {
    void FUN_00a11c00(NiTMapItem* item);
};
// Allocates a 12-byte map item, stores item->key in its extra field, and inserts it into the map via NewItem.
// @fnv 0x00a11c00
void FUN_00a11c00_shell::FUN_00a11c00(NiTMapItem* item)
{
    NiTMapItem* created = (NiTMapItem*)g_memoryManager.Allocate(0xc);
    NiTMapItem* temp = created;
    temp->extra = (void*)item->key;
    ((NiTPointerMap*)this)->NewItem(temp);
}

struct BSSimpleArray {
    int _pad;
    void** m_data;
    unsigned int __thiscall FUN_00a11ee0();
    unsigned int __thiscall FUN_00a11d20(void* &aValue);
};
// @fnv 0x00a11d20
unsigned int __thiscall BSSimpleArray::FUN_00a11d20(void* &aValue)
{
    unsigned int uiIndex = FUN_00a11ee0();
    {
        unsigned int n;
        for (n = 0; n < 1; ++n) {
            void** p = m_data + uiIndex + n;
        }
    }
    m_data[uiIndex] = aValue;
    return uiIndex;
}

struct PendingObj {
    void FUN_00a0dcc0();
};

struct PendingOwner {
    void FUN_00aa4060(PendingObj* p);
};

extern PendingOwner g_011f6238;
extern PendingObj* g_011f33a8;

// If g_011f33a8 is set, calls FUN_00a0dcc0 on it, passes it to g_011f6238.FUN_00aa4060, then clears g_011f33a8.
// @fnv 0x00a0dae0
void __cdecl ClearPendingObject() {
    if (g_011f33a8 != 0) {
        PendingObj* b = g_011f33a8;
        PendingObj* a = b;
        void* r;
        if (a != 0) {
            if ((a->FUN_00a0dcc0(), 1) & 1) {
                g_011f6238.FUN_00aa4060(a);
            }
            r = a;
        } else {
            r = 0;
        }
        g_011f33a8 = 0;
    }
}

struct Setting { int unk00; int value; };
extern Setting DAT_011f33c8,DAT_011debac,DAT_011deec0;
extern int DAT_01202800;
struct Record { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34; float* unk38; };
extern Record** DAT_011f33f8;
bool FUN_00703150();
struct LayoutObject {
 int unk0000,unk0004,unk0008,unk000c,unk0010,unk0014,unk0018,unk001c,unk0020,unk0024;
 int unk0028,unk002c,unk0030,unk0034,unk0038,unk003c,unk0040,unk0044,unk0048,unk004c;
 int unk0050,unk0054,unk0058,unk005c,unk0060,unk0064,unk0068,unk006c,unk0070,unk0074;
 int unk0078,unk007c,unk0080,unk0084,unk0088,unk008c,unk0090,unk0094,unk0098,unk009c;
 int unk00a0,unk00a4,unk00a8,unk00ac,unk00b0,unk00b4,unk00b8,unk00bc,unk00c0,unk00c4;
 int unk00c8,unk00cc,unk00d0,unk00d4,unk00d8,unk00dc,unk00e0,unk00e4,unk00e8,unk00ec;
 int unk00f0,unk00f4,unk00f8,unk00fc,unk0100,unk0104,unk0108,unk010c,unk0110,unk0114;
 int unk0118,unk011c,unk0120,unk0124,unk0128,unk012c,unk0130,unk0134,unk0138,unk013c;
 int unk0140,unk0144,unk0148,unk014c,unk0150,unk0154,unk0158,unk015c,unk0160,unk0164;
 int unk0168,unk016c,unk0170,unk0174,unk0178,unk017c,unk0180,unk0184,unk0188,unk018c;
 int unk0190,unk0194,unk0198,unk019c,unk01a0,unk01a4,unk01a8,unk01ac,unk01b0,unk01b4;
 int unk01b8,unk01bc,unk01c0,unk01c4,unk01c8,unk01cc,unk01d0,unk01d4,unk01d8,unk01dc;
 int unk01e0,unk01e4,unk01e8,unk01ec,unk01f0,unk01f4,unk01f8,unk01fc,unk0200,unk0204;
 int unk0208,unk020c,unk0210,unk0214,unk0218,unk021c,unk0220,unk0224,unk0228,unk022c;
 int unk0230,unk0234,unk0238,unk023c,unk0240,unk0244,unk0248,unk024c,unk0250,unk0254;
 int unk0258,unk025c,unk0260,unk0264,unk0268,unk026c,unk0270,unk0274,unk0278,unk027c;
 int unk0280,unk0284,unk0288,unk028c,unk0290,unk0294,unk0298,unk029c,unk02a0,unk02a4;
 int unk02a8,unk02ac,unk02b0,unk02b4,unk02b8,unk02bc,unk02c0,unk02c4,unk02c8,unk02cc;
 int unk02d0,unk02d4,unk02d8,unk02dc,unk02e0,unk02e4,unk02e8,unk02ec,unk02f0,unk02f4;
 int unk02f8,unk02fc,unk0300,unk0304,unk0308,unk030c,unk0310,unk0314,unk0318,unk031c;
 int unk0320,unk0324,unk0328,unk032c,unk0330,unk0334,unk0338,unk033c,unk0340,unk0344;
 int unk0348,unk034c,unk0350,unk0354,unk0358,unk035c,unk0360,unk0364,unk0368,unk036c;
 int unk0370,unk0374,unk0378,unk037c,unk0380,unk0384,unk0388,unk038c,unk0390,unk0394;
 int unk0398,unk039c,unk03a0,unk03a4,unk03a8,unk03ac,unk03b0,unk03b4,unk03b8,unk03bc;
 int unk03c0,unk03c4,unk03c8,unk03cc,unk03d0,unk03d4,unk03d8,unk03dc,unk03e0,unk03e4;
 int unk03e8,unk03ec,unk03f0,unk03f4,unk03f8,unk03fc,unk0400,unk0404,unk0408,unk040c;
 int unk0410,unk0414,unk0418,unk041c,unk0420,unk0424,unk0428,unk042c,unk0430,unk0434;
 int unk0438,unk043c,unk0440,unk0444,unk0448,unk044c,unk0450,unk0454,unk0458,unk045c;
 int unk0460,unk0464,unk0468,unk046c,unk0470,unk0474,unk0478,unk047c,unk0480,unk0484;
 int unk0488,unk048c,unk0490,unk0494,unk0498,unk049c,unk04a0,unk04a4,unk04a8,unk04ac;
 int unk04b0,unk04b4,unk04b8,unk04bc,unk04c0,unk04c4,unk04c8,unk04cc,unk04d0,unk04d4;
 int unk04d8,unk04dc,unk04e0,unk04e4,unk04e8,unk04ec,unk04f0,unk04f4,unk04f8,unk04fc;
 int unk0500,unk0504,unk0508,unk050c,unk0510,unk0514,unk0518,unk051c,unk0520,unk0524;
 int unk0528,unk052c,unk0530,unk0534,unk0538,unk053c,unk0540,unk0544,unk0548,unk054c;
 int unk0550,unk0554,unk0558,unk055c,unk0560,unk0564,unk0568,unk056c,unk0570,unk0574;
 int unk0578,unk057c,unk0580,unk0584,unk0588,unk058c,unk0590,unk0594,unk0598,unk059c;
 int unk05a0,unk05a4,unk05a8,unk05ac,unk05b0,unk05b4,unk05b8,unk05bc,unk05c0,unk05c4;
 int unk05c8,unk05cc,unk05d0,unk05d4,unk05d8,unk05dc,unk05e0,unk05e4,unk05e8,unk05ec;
 int unk05f0,unk05f4,unk05f8,unk05fc,unk0600,unk0604,unk0608,unk060c,unk0610,unk0614;
 int unk0618,unk061c,unk0620,unk0624,unk0628,unk062c,unk0630,unk0634,unk0638,unk063c;
 int unk0640,unk0644,unk0648,unk064c,unk0650,unk0654,unk0658,unk065c,unk0660,unk0664;
 int unk0668,unk066c,unk0670,unk0674,unk0678,unk067c,unk0680,unk0684,unk0688,unk068c;
 int unk0690,unk0694,unk0698,unk069c,unk06a0,unk06a4,unk06a8,unk06ac,unk06b0,unk06b4;
 int unk06b8,unk06bc,unk06c0,unk06c4,unk06c8,unk06cc,unk06d0,unk06d4,unk06d8,unk06dc;
 int unk06e0,unk06e4,unk06e8,unk06ec,unk06f0,unk06f4,unk06f8,unk06fc,unk0700,unk0704;
 int unk0708,unk070c,unk0710,unk0714,unk0718,unk071c,unk0720,unk0724,unk0728,unk072c;
 int unk0730,unk0734,unk0738,unk073c,unk0740,unk0744,unk0748,unk074c,unk0750,unk0754;
 int unk0758,unk075c,unk0760,unk0764,unk0768,unk076c,unk0770,unk0774,unk0778,unk077c;
 int unk0780,unk0784,unk0788,unk078c,unk0790,unk0794,unk0798,unk079c,unk07a0,unk07a4;
 int unk07a8,unk07ac,unk07b0,unk07b4,unk07b8,unk07bc,unk07c0,unk07c4,unk07c8,unk07cc;
 int unk07d0,unk07d4,unk07d8,unk07dc,unk07e0,unk07e4,unk07e8,unk07ec,unk07f0,unk07f4;
 int unk07f8,unk07fc,unk0800,unk0804,unk0808,unk080c,unk0810,unk0814,unk0818,unk081c;
 int unk0820,unk0824,unk0828,unk082c,unk0830,unk0834,unk0838,unk083c,unk0840,unk0844;
 int unk0848,unk084c,unk0850,unk0854,unk0858,unk085c,unk0860,unk0864,unk0868,unk086c;
 int unk0870,unk0874,unk0878,unk087c,unk0880,unk0884,unk0888,unk088c,unk0890,unk0894;
 int unk0898,unk089c,unk08a0,unk08a4,unk08a8,unk08ac,unk08b0,unk08b4,unk08b8,unk08bc;
 int unk08c0,unk08c4,unk08c8,unk08cc,unk08d0,unk08d4,unk08d8,unk08dc,unk08e0,unk08e4;
 int unk08e8,unk08ec,unk08f0,unk08f4,unk08f8,unk08fc,unk0900,unk0904,unk0908,unk090c;
 int unk0910,unk0914,unk0918,unk091c,unk0920,unk0924,unk0928,unk092c,unk0930,unk0934;
 int unk0938,unk093c,unk0940,unk0944,unk0948,unk094c,unk0950,unk0954,unk0958,unk095c;
 int unk0960,unk0964,unk0968,unk096c,unk0970,unk0974,unk0978,unk097c,unk0980,unk0984;
 int unk0988,unk098c,unk0990,unk0994,unk0998,unk099c,unk09a0,unk09a4,unk09a8,unk09ac;
 int unk09b0,unk09b4,unk09b8,unk09bc,unk09c0,unk09c4,unk09c8,unk09cc,unk09d0,unk09d4;
 int unk09d8,unk09dc,unk09e0,unk09e4,unk09e8,unk09ec,unk09f0,unk09f4,unk09f8,unk09fc;
 int unk0a00,unk0a04,unk0a08,unk0a0c,unk0a10,unk0a14,unk0a18,unk0a1c,unk0a20,unk0a24;
 int unk0a28,unk0a2c,unk0a30,unk0a34,unk0a38,unk0a3c,unk0a40,unk0a44,unk0a48,unk0a4c;
 int unk0a50,unk0a54,unk0a58,unk0a5c,unk0a60,unk0a64,unk0a68,unk0a6c,unk0a70,unk0a74;
 int unk0a78,unk0a7c,unk0a80,unk0a84,unk0a88,unk0a8c,unk0a90,unk0a94,unk0a98,unk0a9c;
 int unk0aa0,unk0aa4,unk0aa8,unk0aac,unk0ab0,unk0ab4,unk0ab8,unk0abc,unk0ac0,unk0ac4;
 int unk0ac8,unk0acc,unk0ad0,unk0ad4,unk0ad8,unk0adc,unk0ae0,unk0ae4,unk0ae8,unk0aec;
 int unk0af0,unk0af4,unk0af8,unk0afc,unk0b00,unk0b04,unk0b08,unk0b0c,unk0b10,unk0b14;
 int unk0b18,unk0b1c,unk0b20,unk0b24,unk0b28,unk0b2c,unk0b30,unk0b34,unk0b38,unk0b3c;
 int unk0b40,unk0b44,unk0b48,unk0b4c,unk0b50,unk0b54,unk0b58,unk0b5c,unk0b60,unk0b64;
 int unk0b68,unk0b6c,unk0b70,unk0b74,unk0b78,unk0b7c,unk0b80,unk0b84,unk0b88,unk0b8c;
 int unk0b90,unk0b94,unk0b98,unk0b9c,unk0ba0,unk0ba4,unk0ba8,unk0bac,unk0bb0,unk0bb4;
 int unk0bb8,unk0bbc,unk0bc0,unk0bc4,unk0bc8,unk0bcc,unk0bd0,unk0bd4,unk0bd8,unk0bdc;
 int unk0be0,unk0be4,unk0be8,unk0bec,unk0bf0,unk0bf4,unk0bf8,unk0bfc,unk0c00,unk0c04;
 int unk0c08,unk0c0c,unk0c10,unk0c14,unk0c18,unk0c1c,unk0c20,unk0c24,unk0c28,unk0c2c;
 int unk0c30,unk0c34,unk0c38,unk0c3c,unk0c40,unk0c44,unk0c48,unk0c4c,unk0c50,unk0c54;
 int unk0c58,unk0c5c,unk0c60,unk0c64,unk0c68,unk0c6c,unk0c70,unk0c74,unk0c78,unk0c7c;
 int unk0c80,unk0c84,unk0c88,unk0c8c,unk0c90,unk0c94,unk0c98,unk0c9c,unk0ca0,unk0ca4;
 int unk0ca8,unk0cac,unk0cb0,unk0cb4,unk0cb8,unk0cbc,unk0cc0,unk0cc4,unk0cc8,unk0ccc;
 int unk0cd0,unk0cd4,unk0cd8,unk0cdc,unk0ce0,unk0ce4,unk0ce8,unk0cec,unk0cf0,unk0cf4;
 int unk0cf8,unk0cfc,unk0d00,unk0d04,unk0d08,unk0d0c,unk0d10,unk0d14,unk0d18,unk0d1c;
 int unk0d20,unk0d24,unk0d28,unk0d2c,unk0d30,unk0d34,unk0d38,unk0d3c,unk0d40,unk0d44;
 int unk0d48,unk0d4c,unk0d50,unk0d54,unk0d58,unk0d5c,unk0d60,unk0d64,unk0d68,unk0d6c;
 int unk0d70,unk0d74,unk0d78,unk0d7c,unk0d80,unk0d84,unk0d88,unk0d8c,unk0d90,unk0d94;
 int unk0d98,unk0d9c,unk0da0,unk0da4,unk0da8,unk0dac,unk0db0,unk0db4,unk0db8,unk0dbc;
 int unk0dc0,unk0dc4,unk0dc8,unk0dcc,unk0dd0,unk0dd4,unk0dd8,unk0ddc,unk0de0,unk0de4;
 int unk0de8,unk0dec,unk0df0,unk0df4,unk0df8,unk0dfc,unk0e00,unk0e04,unk0e08,unk0e0c;
 int unk0e10,unk0e14,unk0e18,unk0e1c,unk0e20,unk0e24,unk0e28,unk0e2c,unk0e30,unk0e34;
 int unk0e38,unk0e3c,unk0e40,unk0e44,unk0e48,unk0e4c,unk0e50,unk0e54,unk0e58,unk0e5c;
 int unk0e60,unk0e64,unk0e68,unk0e6c,unk0e70,unk0e74,unk0e78,unk0e7c,unk0e80,unk0e84;
 int unk0e88,unk0e8c,unk0e90,unk0e94,unk0e98,unk0e9c,unk0ea0,unk0ea4,unk0ea8,unk0eac;
 int unk0eb0,unk0eb4,unk0eb8,unk0ebc,unk0ec0,unk0ec4,unk0ec8,unk0ecc,unk0ed0,unk0ed4;
 int unk0ed8,unk0edc,unk0ee0,unk0ee4,unk0ee8,unk0eec,unk0ef0,unk0ef4,unk0ef8,unk0efc;
 int unk0f00,unk0f04,unk0f08,unk0f0c,unk0f10,unk0f14,unk0f18,unk0f1c,unk0f20,unk0f24;
 int unk0f28,unk0f2c,unk0f30,unk0f34,unk0f38,unk0f3c,unk0f40,unk0f44,unk0f48,unk0f4c;
 int unk0f50,unk0f54,unk0f58,unk0f5c,unk0f60,unk0f64,unk0f68,unk0f6c,unk0f70,unk0f74;
 int unk0f78,unk0f7c,unk0f80,unk0f84,unk0f88,unk0f8c,unk0f90,unk0f94,unk0f98,unk0f9c;
 int unk0fa0,unk0fa4,unk0fa8,unk0fac,unk0fb0,unk0fb4,unk0fb8,unk0fbc,unk0fc0,unk0fc4;
 int unk0fc8,unk0fcc,unk0fd0,unk0fd4,unk0fd8,unk0fdc,unk0fe0,unk0fe4,unk0fe8,unk0fec;
 int unk0ff0,unk0ff4,unk0ff8,unk0ffc,unk1000,unk1004,unk1008,unk100c,unk1010,unk1014;
 int unk1018,unk101c,unk1020,unk1024,unk1028,unk102c,unk1030,unk1034,unk1038,unk103c;
 int unk1040,unk1044,unk1048,unk104c,unk1050,unk1054,unk1058,unk105c,unk1060,unk1064;
 int unk1068,unk106c,unk1070,unk1074,unk1078,unk107c,unk1080,unk1084,unk1088,unk108c;
 int unk1090,unk1094,unk1098,unk109c,unk10a0,unk10a4,unk10a8,unk10ac,unk10b0,unk10b4;
 int unk10b8,unk10bc,unk10c0,unk10c4,unk10c8,unk10cc,unk10d0,unk10d4,unk10d8,unk10dc;
 int unk10e0,unk10e4,unk10e8,unk10ec,unk10f0,unk10f4,unk10f8,unk10fc,unk1100,unk1104;
 int unk1108,unk110c,unk1110,unk1114,unk1118,unk111c,unk1120,unk1124,unk1128,unk112c;
 int unk1130,unk1134,unk1138,unk113c,unk1140,unk1144,unk1148,unk114c,unk1150,unk1154;
 int unk1158,unk115c,unk1160,unk1164,unk1168,unk116c,unk1170,unk1174,unk1178,unk117c;
 int unk1180,unk1184,unk1188,unk118c,unk1190,unk1194,unk1198,unk119c,unk11a0,unk11a4;
 int unk11a8,unk11ac,unk11b0,unk11b4,unk11b8,unk11bc,unk11c0,unk11c4,unk11c8,unk11cc;
 int unk11d0,unk11d4,unk11d8,unk11dc,unk11e0,unk11e4,unk11e8,unk11ec,unk11f0,unk11f4;
 int unk11f8,unk11fc,unk1200,unk1204,unk1208,unk120c,unk1210,unk1214,unk1218,unk121c;
 int unk1220,unk1224,unk1228,unk122c,unk1230,unk1234,unk1238,unk123c,unk1240,unk1244;
 int unk1248,unk124c,unk1250,unk1254,unk1258,unk125c,unk1260,unk1264,unk1268,unk126c;
 int unk1270,unk1274,unk1278,unk127c,unk1280,unk1284,unk1288,unk128c,unk1290,unk1294;
 int unk1298,unk129c,unk12a0,unk12a4,unk12a8,unk12ac,unk12b0,unk12b4,unk12b8,unk12bc;
 int unk12c0,unk12c4,unk12c8,unk12cc,unk12d0,unk12d4,unk12d8,unk12dc,unk12e0,unk12e4;
 int unk12e8,unk12ec,unk12f0,unk12f4,unk12f8,unk12fc,unk1300,unk1304,unk1308,unk130c;
 int unk1310,unk1314,unk1318,unk131c,unk1320,unk1324,unk1328,unk132c,unk1330,unk1334;
 int unk1338,unk133c,unk1340,unk1344,unk1348,unk134c,unk1350,unk1354,unk1358,unk135c;
 int unk1360,unk1364,unk1368,unk136c,unk1370,unk1374,unk1378,unk137c,unk1380,unk1384;
 int unk1388,unk138c,unk1390,unk1394,unk1398,unk139c,unk13a0,unk13a4,unk13a8,unk13ac;
 int unk13b0,unk13b4,unk13b8,unk13bc,unk13c0,unk13c4,unk13c8,unk13cc,unk13d0,unk13d4;
 int unk13d8,unk13dc,unk13e0,unk13e4,unk13e8,unk13ec,unk13f0,unk13f4,unk13f8,unk13fc;
 int unk1400,unk1404,unk1408,unk140c,unk1410,unk1414,unk1418,unk141c,unk1420,unk1424;
 int unk1428,unk142c,unk1430,unk1434,unk1438,unk143c,unk1440,unk1444,unk1448,unk144c;
 int unk1450,unk1454,unk1458,unk145c,unk1460,unk1464,unk1468,unk146c,unk1470,unk1474;
 int unk1478,unk147c,unk1480,unk1484,unk1488,unk148c,unk1490,unk1494,unk1498,unk149c;
 int unk14a0,unk14a4,unk14a8,unk14ac,unk14b0,unk14b4,unk14b8,unk14bc,unk14c0,unk14c4;
 int unk14c8,unk14cc,unk14d0,unk14d4,unk14d8,unk14dc,unk14e0,unk14e4,unk14e8,unk14ec;
 int unk14f0,unk14f4,unk14f8,unk14fc,unk1500,unk1504,unk1508,unk150c,unk1510,unk1514;
 int unk1518,unk151c,unk1520,unk1524,unk1528,unk152c,unk1530,unk1534,unk1538,unk153c;
 int unk1540,unk1544,unk1548,unk154c,unk1550,unk1554,unk1558,unk155c,unk1560,unk1564;
 int unk1568,unk156c,unk1570,unk1574,unk1578,unk157c,unk1580,unk1584,unk1588,unk158c;
 int unk1590,unk1594,unk1598,unk159c,unk15a0,unk15a4,unk15a8,unk15ac,unk15b0,unk15b4;
 int unk15b8,unk15bc,unk15c0,unk15c4,unk15c8,unk15cc,unk15d0,unk15d4,unk15d8,unk15dc;
 int unk15e0,unk15e4,unk15e8,unk15ec,unk15f0,unk15f4,unk15f8,unk15fc,unk1600,unk1604;
 int unk1608,unk160c,unk1610,unk1614,unk1618,unk161c,unk1620,unk1624,unk1628,unk162c;
 int unk1630,unk1634,unk1638,unk163c,unk1640,unk1644,unk1648,unk164c,unk1650,unk1654;
 int unk1658,unk165c,unk1660,unk1664,unk1668,unk166c,unk1670,unk1674,unk1678,unk167c;
 int unk1680,unk1684,unk1688,unk168c,unk1690,unk1694,unk1698,unk169c,unk16a0,unk16a4;
 int unk16a8,unk16ac,unk16b0,unk16b4,unk16b8,unk16bc,unk16c0,unk16c4,unk16c8,unk16cc;
 int unk16d0,unk16d4,unk16d8,unk16dc,unk16e0,unk16e4,unk16e8,unk16ec,unk16f0,unk16f4;
 int unk16f8,unk16fc,unk1700,unk1704,unk1708,unk170c,unk1710,unk1714,unk1718,unk171c;
 int unk1720,unk1724,unk1728,unk172c,unk1730,unk1734,unk1738,unk173c,unk1740,unk1744;
 int unk1748,unk174c,unk1750,unk1754,unk1758,unk175c,unk1760,unk1764,unk1768,unk176c;
 int unk1770,unk1774,unk1778,unk177c,unk1780,unk1784,unk1788,unk178c,unk1790,unk1794;
 int unk1798,unk179c,unk17a0,unk17a4,unk17a8,unk17ac,unk17b0,unk17b4,unk17b8,unk17bc;
 int unk17c0,unk17c4,unk17c8,unk17cc,unk17d0,unk17d4,unk17d8,unk17dc,unk17e0,unk17e4;
 int unk17e8,unk17ec,unk17f0,unk17f4,unk17f8,unk17fc,unk1800,unk1804,unk1808,unk180c;
 int unk1810,unk1814,unk1818,unk181c,unk1820,unk1824,unk1828,unk182c,unk1830,unk1834;
 int unk1838,unk183c,unk1840,unk1844,unk1848,unk184c,unk1850,unk1854,unk1858,unk185c;
 int unk1860,unk1864,unk1868,unk186c,unk1870,unk1874,unk1878,unk187c,unk1880,unk1884;
 int unk1888,unk188c,unk1890,unk1894,unk1898,unk189c,unk18a0,unk18a4,unk18a8,unk18ac;
 int unk18b0,unk18b4,unk18b8,unk18bc,unk18c0,unk18c4,unk18c8,unk18cc,unk18d0,unk18d4;
 int unk18d8,unk18dc,unk18e0,unk18e4,unk18e8,unk18ec,unk18f0,unk18f4,unk18f8,unk18fc;
 int unk1900,unk1904,unk1908,unk190c,unk1910,unk1914,unk1918,unk191c,unk1920,unk1924;
 int unk1928,unk192c,unk1930,unk1934,unk1938,unk193c,unk1940,unk1944,unk1948,unk194c;
 int unk1950,unk1954,unk1958,unk195c,unk1960,unk1964,unk1968,unk196c,unk1970,unk1974;
 int unk1978,unk197c,unk1980,unk1984,unk1988,unk198c,unk1990,unk1994,unk1998,unk199c;
 int unk19a0,unk19a4,unk19a8,unk19ac,unk19b0,unk19b4,unk19b8,unk19bc,unk19c0,unk19c4;
 int unk19c8,unk19cc,unk19d0,unk19d4,unk19d8,unk19dc,unk19e0,unk19e4,unk19e8,unk19ec;
 int unk19f0,unk19f4,unk19f8,unk19fc,unk1a00,unk1a04,unk1a08,unk1a0c,unk1a10,unk1a14;
 int unk1a18,unk1a1c,unk1a20,unk1a24,unk1a28,unk1a2c,unk1a30,unk1a34,unk1a38,unk1a3c;
 int unk1a40,unk1a44,unk1a48,unk1a4c,unk1a50,unk1a54,unk1a58,unk1a5c,unk1a60,unk1a64;
 int unk1a68,unk1a6c,unk1a70,unk1a74,unk1a78,unk1a7c,unk1a80,unk1a84,unk1a88,unk1a8c;
 int unk1a90,unk1a94,unk1a98,unk1a9c,unk1aa0,unk1aa4,unk1aa8,unk1aac,unk1ab0,unk1ab4;
 int unk1ab8,unk1abc,unk1ac0,unk1ac4,unk1ac8,unk1acc,unk1ad0,unk1ad4,unk1ad8,unk1adc;
 int unk1ae0,unk1ae4,unk1ae8,unk1aec,unk1af0,unk1af4,unk1af8,unk1afc,unk1b00,unk1b04;
 int unk1b08,unk1b0c,unk1b10,unk1b14,unk1b18,unk1b1c,unk1b20,unk1b24,unk1b28,unk1b2c;
 int unk1b30,unk1b34,unk1b38,unk1b3c,unk1b40,unk1b44,unk1b48,unk1b4c,unk1b50,unk1b54;
 int unk1b58,unk1b5c,unk1b60,unk1b64,unk1b68,unk1b6c,unk1b70,unk1b74,unk1b78,unk1b7c;
 int unk1b80,unk1b84,unk1b88,unk1b8c,unk1b90,unk1b94,unk1b98,unk1b9c,unk1ba0,unk1ba4;
 int unk1ba8,unk1bac,unk1bb0,unk1bb4,unk1bb8,unk1bbc,unk1bc0,unk1bc4,unk1bc8,unk1bcc;
 int unk1bd0,unk1bd4,unk1bd8,unk1bdc,unk1be0,unk1be4,unk1be8,unk1bec,unk1bf0,unk1bf4;
 int unk1bf8,unk1bfc,unk1c00,unk1c04,unk1c08,unk1c0c,unk1c10,unk1c14,unk1c18,unk1c1c;
 int unk1c20,unk1c24,unk1c28,unk1c2c,unk1c30,unk1c34,unk1c38,unk1c3c,unk1c40,unk1c44;
 int unk1c48,unk1c4c,unk1c50,unk1c54,unk1c58,unk1c5c,unk1c60,unk1c64,unk1c68,unk1c6c;
 int unk1c70,unk1c74,unk1c78,unk1c7c,unk1c80,unk1c84,unk1c88,unk1c8c,unk1c90,unk1c94;
 int unk1c98,unk1c9c,unk1ca0,unk1ca4,unk1ca8,unk1cac,unk1cb0,unk1cb4,unk1cb8,unk1cbc;
 int unk1cc0,unk1cc4,unk1cc8,unk1ccc,unk1cd0,unk1cd4,unk1cd8,unk1cdc,unk1ce0,unk1ce4;
 int unk1ce8,unk1cec,unk1cf0,unk1cf4,unk1cf8,unk1cfc,unk1d00,unk1d04,unk1d08,unk1d0c;
 int unk1d10,unk1d14,unk1d18,unk1d1c,unk1d20,unk1d24,unk1d28,unk1d2c,unk1d30,unk1d34;
 int unk1d38,unk1d3c,unk1d40,unk1d44,unk1d48,unk1d4c,unk1d50,unk1d54,unk1d58,unk1d5c;
 int unk1d60,unk1d64,unk1d68,unk1d6c,unk1d70,unk1d74,unk1d78,unk1d7c,unk1d80,unk1d84;
 int unk1d88,unk1d8c,unk1d90,unk1d94,unk1d98,unk1d9c,unk1da0,unk1da4,unk1da8,unk1dac;
 int unk1db0,unk1db4,unk1db8,unk1dbc,unk1dc0,unk1dc4,unk1dc8,unk1dcc,unk1dd0,unk1dd4;
 int unk1dd8,unk1ddc,unk1de0,unk1de4,unk1de8,unk1dec,unk1df0,unk1df4,unk1df8,unk1dfc;
 int unk1e00,unk1e04,unk1e08,unk1e0c,unk1e10,unk1e14,unk1e18,unk1e1c,unk1e20,unk1e24;
 int unk1e28,unk1e2c,unk1e30,unk1e34,unk1e38,unk1e3c,unk1e40,unk1e44,unk1e48,unk1e4c;
 int unk1e50,unk1e54,unk1e58,unk1e5c,unk1e60,unk1e64,unk1e68,unk1e6c,unk1e70,unk1e74;
 int unk1e78,unk1e7c,unk1e80,unk1e84,unk1e88,unk1e8c,unk1e90,unk1e94,unk1e98,unk1e9c;
 int unk1ea0,unk1ea4,unk1ea8,unk1eac,unk1eb0,unk1eb4,unk1eb8,unk1ebc,unk1ec0,unk1ec4;
 int unk1ec8,unk1ecc,unk1ed0,unk1ed4,unk1ed8,unk1edc,unk1ee0,unk1ee4,unk1ee8,unk1eec;
 int unk1ef0,unk1ef4,unk1ef8,unk1efc,unk1f00,unk1f04,unk1f08,unk1f0c,unk1f10,unk1f14;
 int unk1f18,unk1f1c,unk1f20,unk1f24,unk1f28,unk1f2c,unk1f30,unk1f34,unk1f38,unk1f3c;
 int unk1f40,unk1f44,unk1f48,unk1f4c,unk1f50,unk1f54,unk1f58,unk1f5c,unk1f60,unk1f64;
 int unk1f68,unk1f6c,unk1f70,unk1f74,unk1f78,unk1f7c,unk1f80,unk1f84,unk1f88,unk1f8c;
 int unk1f90,unk1f94,unk1f98,unk1f9c,unk1fa0,unk1fa4,unk1fa8,unk1fac,unk1fb0,unk1fb4;
 int unk1fb8,unk1fbc,unk1fc0,unk1fc4,unk1fc8,unk1fcc,unk1fd0,unk1fd4,unk1fd8,unk1fdc;
 int unk1fe0,unk1fe4,unk1fe8,unk1fec,unk1ff0,unk1ff4,unk1ff8,unk1ffc,unk2000,unk2004;
 int unk2008,unk200c,unk2010,unk2014,unk2018,unk201c,unk2020,unk2024,unk2028,unk202c;
 int unk2030,unk2034,unk2038,unk203c,unk2040,unk2044,unk2048,unk204c,unk2050,unk2054;
 int unk2058,unk205c,unk2060,unk2064,unk2068,unk206c,unk2070,unk2074,unk2078,unk207c;
 int unk2080,unk2084,unk2088,unk208c,unk2090,unk2094,unk2098,unk209c,unk20a0,unk20a4;
 int unk20a8,unk20ac,unk20b0,unk20b4,unk20b8,unk20bc,unk20c0,unk20c4,unk20c8,unk20cc;
 int unk20d0,unk20d4,unk20d8,unk20dc,unk20e0,unk20e4,unk20e8,unk20ec,unk20f0,unk20f4;
 int unk20f8,unk20fc,unk2100,unk2104,unk2108,unk210c,unk2110,unk2114,unk2118,unk211c;
 int unk2120,unk2124,unk2128,unk212c,unk2130,unk2134,unk2138,unk213c,unk2140,unk2144;
 int unk2148,unk214c,unk2150,unk2154,unk2158,unk215c,unk2160,unk2164,unk2168,unk216c;
 int unk2170,unk2174,unk2178,unk217c,unk2180,unk2184,unk2188,unk218c,unk2190,unk2194;
 int unk2198,unk219c,unk21a0,unk21a4,unk21a8,unk21ac,unk21b0,unk21b4,unk21b8,unk21bc;
 int unk21c0,unk21c4,unk21c8,unk21cc,unk21d0,unk21d4,unk21d8,unk21dc,unk21e0,unk21e4;
 int unk21e8,unk21ec,unk21f0,unk21f4,unk21f8,unk21fc,unk2200,unk2204,unk2208,unk220c;
 int unk2210,unk2214,unk2218,unk221c,unk2220,unk2224,unk2228,unk222c,unk2230,unk2234;
 int unk2238,unk223c,unk2240,unk2244,unk2248,unk224c,unk2250,unk2254,unk2258,unk225c;
 int unk2260,unk2264,unk2268,unk226c,unk2270,unk2274,unk2278,unk227c;
 int height;
 int positions[3];
 int left,right,center;
 void UpdateLayoutPositions();
};
// Computes height from a record's unk38, fills positions[3] from a margin setting, and sets left/right/center from the right margin setting.
// @fnv 0x00a0e2a0
void LayoutObject::UpdateLayoutPositions() {
 int* c = &DAT_011f33c8 ? &DAT_011f33c8.value : (DAT_01202800=0,&DAT_01202800);
 Record** e = DAT_011f33f8;
 Record* j = e[*c-1];
 height = (int)((j->unk38 ? *j->unk38 : 0.0f)+3.0);
 int l;
 for (l=0;l<3;l++) {
  int* margin = &DAT_011debac ? &DAT_011debac.value : (DAT_01202800=0,&DAT_01202800);
  positions[l] = *margin + (FUN_00703150() ? 4 : 1)*height;
 }
    {
 int* rightMargin = &DAT_011deec0 ? &DAT_011deec0.value : (DAT_01202800=0,&DAT_01202800);
 right = 0x500 - *rightMargin;
    }
    {
 int* fonts = &DAT_011deec0 ? &DAT_011deec0.value : (DAT_01202800=0,&DAT_01202800);
 left = *fonts;
    }
 center = ((right-left)>>1)+left;}

struct E4F0Block256 {
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
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
};

struct RgbaColor;

extern "C" int __cdecl FUN_00ecddf1(char* buf, unsigned int n, const char* fmt, char* args);

struct E4F0DebugText {
    E4F0Block256 m_block00;
    E4F0Block256 m_block01;
    E4F0Block256 m_block02;
    E4F0Block256 m_block03;
    E4F0Block256 m_block04;
    E4F0Block256 m_block05;
    E4F0Block256 m_block06;
    E4F0Block256 m_block07;
    E4F0Block256 m_block08;
    E4F0Block256 m_block09;
    E4F0Block256 m_block10;
    E4F0Block256 m_block11;
    E4F0Block256 m_block12;
    E4F0Block256 m_block13;
    E4F0Block256 m_block14;
    E4F0Block256 m_block15;
    E4F0Block256 m_block16;
    E4F0Block256 m_block17;
    E4F0Block256 m_block18;
    E4F0Block256 m_block19;
    E4F0Block256 m_block20;
    E4F0Block256 m_block21;
    E4F0Block256 m_block22;
    E4F0Block256 m_block23;
    E4F0Block256 m_block24;
    E4F0Block256 m_block25;
    E4F0Block256 m_block26;
    E4F0Block256 m_block27;
    E4F0Block256 m_block28;
    E4F0Block256 m_block29;
    E4F0Block256 m_block30;
    E4F0Block256 m_block31;
    E4F0Block256 m_block32;
    E4F0Block256 m_block33;
    int unk2200;
    int unk2204;
    int unk2208;
    int unk220C;
    int unk2210;
    int unk2214;
    int unk2218;
    int unk221C;
    int unk2220;
    int unk2224;
    int unk2228;
    int unk222C;
    int unk2230;
    int unk2234;
    int unk2238;
    int unk223C;
    int unk2240;
    int unk2244;
    int unk2248;
    int unk224C;
    int unk2250;
    int unk2254;
    int unk2258;
    int unk225C;
    int unk2260;
    int unk2264;
    int unk2268;
    int unk226C;
    int unk2270;
    int unk2274;
    int unk2278;
    int unk227C;
    int unk2280;
    int m_aiLineY[32];

    int Print(const char* pcText, float fX, float fY, int iFlags, int m_iPayloadInteger, float fScale, int iUnused, const RgbaColor* pkColor);
    int PrintFormattedLine(int iX, int iLine, int iFlags, const char* pcFormat, char* pArgs, const RgbaColor* pkColor);
};

// Formats pcFormat with pArgs into a 200-byte buffer, then prints it at iX and the line's Y from m_aiLineY[iLine].
// @fnv 0x00a0e4f0
int E4F0DebugText::PrintFormattedLine(int iX, int iLine, int iFlags, const char* pcFormat, char* pArgs, const RgbaColor* pkColor)
{
    char acBuffer2[200];
    FUN_00ecddf1(acBuffer2, 200, pcFormat, pArgs);
    int iResult = Print(acBuffer2, (float)iX, (float)m_aiLineY[iLine], iFlags, -1, -1.0f, 0, pkColor);
    return iResult;
}

// 256-byte span of not-yet-identified fields.
struct A0E5C0Block {
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
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
};

int FUN_00ecddf1(char* pcBuffer, unsigned int uiSize, const char* pcFormat, char* pArgs);

class A0E5C0DebugText {
public:
    A0E5C0Block m_kBlock00;
    A0E5C0Block m_kBlock01;
    A0E5C0Block m_kBlock02;
    A0E5C0Block m_kBlock03;
    A0E5C0Block m_kBlock04;
    A0E5C0Block m_kBlock05;
    A0E5C0Block m_kBlock06;
    A0E5C0Block m_kBlock07;
    A0E5C0Block m_kBlock08;
    A0E5C0Block m_kBlock09;
    A0E5C0Block m_kBlock10;
    A0E5C0Block m_kBlock11;
    A0E5C0Block m_kBlock12;
    A0E5C0Block m_kBlock13;
    A0E5C0Block m_kBlock14;
    A0E5C0Block m_kBlock15;
    A0E5C0Block m_kBlock16;
    A0E5C0Block m_kBlock17;
    A0E5C0Block m_kBlock18;
    A0E5C0Block m_kBlock19;
    A0E5C0Block m_kBlock20;
    A0E5C0Block m_kBlock21;
    A0E5C0Block m_kBlock22;
    A0E5C0Block m_kBlock23;
    A0E5C0Block m_kBlock24;
    A0E5C0Block m_kBlock25;
    A0E5C0Block m_kBlock26;
    A0E5C0Block m_kBlock27;
    A0E5C0Block m_kBlock28;
    A0E5C0Block m_kBlock29;
    A0E5C0Block m_kBlock30;
    A0E5C0Block m_kBlock31;
    A0E5C0Block m_kBlock32;
    A0E5C0Block m_kBlock33;
    int unk2200;
    int unk2204;
    int unk2208;
    int unk220C;
    int unk2210;
    int unk2214;
    int unk2218;
    int unk221C;
    int unk2220;
    int unk2224;
    int unk2228;
    int unk222C;
    int unk2230;
    int unk2234;
    int unk2238;
    int unk223C;
    int unk2240;
    int unk2244;
    int unk2248;
    int unk224C;
    int unk2250;
    int unk2254;
    int unk2258;
    int unk225C;
    int unk2260;
    int unk2264;
    int unk2268;
    int unk226C;
    int unk2270;
    int unk2274;
    int unk2278;
    int unk227C;
    int m_iLineHeight;
    int m_aiY[3];
    int m_aiX[3];

    int Print(const char* pcText, float fX, float fY, int m_iPayloadInteger, int iAlign, float fScale, int iFlags, const RgbaColor* pkColor);
    int PrintFormattedAtSlot(int iSlot, int m_iPayloadInteger, const char* pcFormat, char* pArgs, const RgbaColor* pkColor);
};

// Formats pcFormat with pArgs into a 200-byte buffer, prints it at slot iSlot's X/Y, advances that slot's Y by m_iLineHeight, and returns the print result.
// @fnv 0x00a0e5c0
int A0E5C0DebugText::PrintFormattedAtSlot(int iSlot, int m_iPayloadInteger, const char* pcFormat, char* pArgs, const RgbaColor* pkColor) {
    int iResult;
    char acText[200];
    FUN_00ecddf1(acText, sizeof(acText), pcFormat, pArgs);
    iResult = Print(acText, (float)m_aiX[iSlot], (float)m_aiY[iSlot], m_iPayloadInteger, -1, -1.0f, 0, pkColor);
    m_aiY[iSlot] += m_iLineHeight;
    return iResult;
}

struct ListNode_b5742 {
    ListNode_b5742* m_00;
    ListNode_b5742* m_04;
    unsigned int m_08;
};

struct FUN_00aa4060_shell {
    void __thiscall FUN_00aa4060(void* p);
};
extern FUN_00aa4060_shell DAT_011f6238;

struct FUN_00a1c080_shell {
    unsigned int __thiscall PopFront();
};
struct FUN_00a11fa0_shell {
    unsigned int __thiscall RemoveNextNode();
};

struct FUN_00a11e10_cls {
    ListNode_b5742* m_00;
    ListNode_b5742* m_04;
    unsigned int m_08;

    unsigned int RemoveNode(ListNode_b5742** pNode);
};

// @fnv 0x00a11e10
unsigned int FUN_00a11e10_cls::RemoveNode(ListNode_b5742** pNode) {
    unsigned int unk00[6];
    ListNode_b5742* node3 = *pNode;
    if (node3 == m_00) {
        *pNode = node3->m_00;
        return reinterpret_cast<FUN_00a1c080_shell*>(this)->PopFront();
    }
    if (node3 == m_04) {
        *pNode = 0;
        return reinterpret_cast<FUN_00a11fa0_shell*>(this)->RemoveNextNode();
    }
    ListNode_b5742* prev = node3->m_04;
    ListNode_b5742* pNext = node3->m_00;
    *pNode = pNext;
    if (prev != 0) {
        prev->m_00 = pNext;
    }
    if (pNext != 0) {
        pNext->m_04 = prev;
    }
    unsigned int uiData = node3->m_08;
    node3->m_08 = 0;
    {
    ListNode_b5742* pDead = node3;
    DAT_011f6238.FUN_00aa4060(pDead);
    }
    m_08 = m_08 - 1;
    return uiData;}

struct FUN_00a11ee0_cls {
    virtual void* Slot0();
    virtual void* Alloc(unsigned int count);
    void** m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReservedSize;
    void Grow(unsigned int newCap, unsigned int oldSize);
    unsigned int FUN_00a11ee0();
};

// Ensures capacity by allocating or growing the buffer when full, then increments the count and returns the previous index.
// @fnv 0x00a11ee0
unsigned int FUN_00a11ee0_cls::FUN_00a11ee0() {
    unsigned int unkC, tmp0, a0;
    unsigned int cap;
    unsigned int newCap;
    bool fullTmp;
    if (m_uiLogicalSize == m_iReservedSize)
        fullTmp = true;
    else
        fullTmp = false;
    if (fullTmp) {
        if (m_iReservedSize == 0) {
            cap = 4;
            m_pBuffer = (void**)Alloc(cap);
            m_iReservedSize = cap;
        } else {
            newCap = (m_iReservedSize > 0x400) ? m_iReservedSize + 0x400 : m_iReservedSize * 2;
            Grow(newCap, m_uiLogicalSize);
            m_iReservedSize = newCap;
        }
    }
    m_uiLogicalSize++;
    return m_uiLogicalSize - 1;
}

struct Point2DResult {
    float fX;
    float fY;
    int iFlags;
    int iUnk0C;
    int iResult;
};
struct DebugTextItem { Point2DResult* pData; };
struct DebugTextEntry {
    float fX;
    float fY;
    int iFlags;
    int iUnk0C;
    int iResult;
    char pad[0x2c - 0x14];
};
struct FUN_00a10630_shell {
    int unk0000;
    DebugTextEntry m_aEntries[200];
    char pad2264[0x2270 - 0x2264];
    void* m_pVtbl;
    DebugTextItem** m_ppItems;
    unsigned int m_uiItemCount;
    int FindDebugTextResult(float fX, float fY, int iFlags);
};

// Searches the item list, then the 200-entry table, for a matching fX/fY/iFlags and returns its iResult, or 0 if none match.
// @fnv 0x00a10630
int FUN_00a10630_shell::FindDebugTextResult(float fX, float fY, int iFlags) {
    unsigned int i;
    int j2;
    unsigned int ItemUpdateArray;
    for (i = 0; i < (ItemUpdateArray = m_uiItemCount); i++) {
        if (m_ppItems[i]->pData->fX == fX && m_ppItems[i]->pData->fY == fY && m_ppItems[i]->pData->iFlags == iFlags) {
            DebugTextItem*& rEntry = m_ppItems[i];
            int iResult = rEntry->pData->iResult;
            return iResult;
        }
    }
    for (j2 = 0; j2 < 200; j2++) {
        if (m_aEntries[j2].fX == fX && m_aEntries[j2].fY == fY && m_aEntries[j2].iFlags == iFlags) {
            int iResult = m_aEntries[j2].iResult;
            return iResult;
        }
    }
    return 0;
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

#include <string.h>
extern "C" void __cdecl FUN_00ecc7b0(char* destination, const char* source, unsigned int limit);
struct SearchString {
    const char* data;
    unsigned short length;
    unsigned short capacity;
};
struct SearchEntry {
    float x;
    float y;
    int flags;
    int unk0c;
    SearchString text;
    int unk18, unk1c, unk20, unk24, unk28;
};
struct SearchPointer { SearchEntry* value; };
struct SearchText {
    int unk00;
    SearchEntry entries[200];
    int unk2264, unk2268, unk226c, unk2270;
    SearchPointer** dynamicEntries;
    unsigned int dynamicCount;
    bool FUN_00a103e0(char* destination, float x, float y, int flags);
};
// @fnv 0x00a103e0
bool SearchText::FUN_00a103e0(char* destination, float x, float y, int flags)
{
    bool found = false;
    *destination = 0;
    unsigned int i;
    int j;
    {
    unsigned int count;
    for (i = 0; !found && (count = dynamicCount, i < count); ++i) {
        if (dynamicEntries[i]->value->x == x &&
            dynamicEntries[i]->value->y == y &&
            dynamicEntries[i]->value->flags == flags) {
            if (destination) {
                SearchPointer** entry = &dynamicEntries[i];
                {
                {
                const char* lengthData;
                {
                SearchString* text = &(*entry)->value->text;
                if ((text->length == 65535 ? (lengthData = text->data, strlen(lengthData)) : text->length) != 0) {
                    SearchPointer** copyEntry = &dynamicEntries[i];
                    {
                    const char* source = (*copyEntry)->value->text.data;
                    FUN_00ecc7b0(destination, source, 2046);
                    }
                }
                }
                }
            }
            }
            found = true;
        }
    }
    }
    for (j = 0; !found && j < 200; ++j) {
        if (entries[j].x == x && entries[j].y == y && entries[j].flags == flags) {
            if (destination) {
                {
                const char* lengthData;
                {
                SearchString* text = &entries[j].text;
                if ((text->length == 65535 ? (lengthData = text->data, strlen(lengthData)) : text->length) != 0) {
                    const char* source = entries[j].text.data;
                    FUN_00ecc7b0(destination, source, 2046);
                }
                }
                }
            }
            found = true;
        }
    }
    return found;
}

#include <windows.h>
// Releases the global critical section when the game is running in a mode that
// still owns it.
// @fnv 0x00a11840
void __cdecl ReleaseLock()
{
    if (IsDebugTextVisible() != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_011f33dc);
    }
}
