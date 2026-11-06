
// src/gamebryo2.2/corelibs/nianimation/nilightcolorcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nilightcolorcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" bool __stdcall FUN_00a57780(void*);

// @fnv 0x00a461c0
char __stdcall FUN_00a461c0(void* kStream)
{
    char result = 0;
    result = FUN_00a57780(kStream) ? 1 : 0;
    return result;
}

struct FUN_00a4d1b0_shell
{
    unsigned char m_flag;
    const char* __thiscall GetLightTypeName();
};

// @fnv 0x00a4d1b0
const char* __thiscall FUN_00a4d1b0_shell::GetLightTypeName()
{
    unsigned char flag = *(unsigned char*)((char*)this + 0x38);
    const char* result = "Ambient";
    if (!(flag & 1))
        result = "Diffuse";
    return result;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f3fa8;

// @fnv 0x00a4d200
GlobalObjectO2_00a7b610* __cdecl FUN_00a4d200()
{
    return &g_011f3fa8;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

struct NiLightColorController
{
    void __thiscall FUN_00a57c80();
};

extern int DAT_01098dd4;

// @fnv 0x00a4d500
void* __cdecl FUN_00a4d500()
{
    void* p = BSFadeNode::operator new(0x3c);
    if (p)
    {
        NiLightColorController* pController = (NiLightColorController*)p;
        pController->FUN_00a57c80();
        *(short*)((char*)p + 0x38) = 0;
        *(void**)p = &DAT_01098dd4;
        return p;
    }
    return 0;
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct NiColor
{
    float r;
    float g;
    float b;
};
struct NiLight
{
    unsigned char _pad[0xC8];
    NiColor m_k1;
    NiColor m_k2;
};
struct S00a4d150
{
    unsigned char _a[0x2C];
    NiLight* m_pLight;
    unsigned char _b[8];
    unsigned short m_uiObjectFlags;
    void GetLightColor(NiPoint3& kValue);
};
// Reads the light's first or second color depending on the flag and writes its RGB components into kValue.
// @fnv 0x00a4d150
void S00a4d150::GetLightColor(NiPoint3& kValue)
{
    NiColor kColor;
    NiLight* apTargetLight = m_pLight;
    if (apTargetLight)
    {
        if (m_uiObjectFlags & 1)
            kColor = apTargetLight->m_k1;
        else
            kColor = apTargetLight->m_k2;
        kValue.x = kColor.r;
        kValue.y = kColor.g;
        kValue.z = kColor.b;
    }
}

struct NiObject
{
};
bool __stdcall FUN_00a57c10(void*);
struct FUN_00a4d1d0_holder
{
    bool __thiscall IsEqual(NiObject* pkObject);
};
// Checks pkObject via FUN_00a57c10, then compares bit 0 of the inverted byte at offset 0x38 with the byte at this+0x38 and returns the result.
// @fnv 0x00a4d1d0
bool __thiscall FUN_00a4d1d0_holder::IsEqual(NiObject* pkObject)
{
    NiLightColorController* pkControl = (NiLightColorController*)pkObject;
    if (!FUN_00a57c10(pkControl))
        return false;
    unsigned char v = *(unsigned char*)((char*)pkControl + 0x38);
    v = ~v;
    v ^= *(unsigned char*)((char*)this + 0x38);
    v &= 1;
    return v;
}

struct FakeRTTI
{
    const char* m_pcName;
    FakeRTTI* m_pkBase;
};
extern FakeRTTI g_011f4a68_arg1;
struct NiObjectNET
{
    virtual void Unk0();
    virtual void Unk1();
    virtual FakeRTTI* GetRTTI();
};
// Walks the RTTI chain of pkTarget and returns true if it reaches g_011f4a68_arg1, false if pkTarget is null or the chain ends.
// @fnv 0x00a4d210
bool __stdcall FUN_00a4d210(NiObjectNET* pkTarget)
{
    if (!pkTarget)
        return false;
    for (FakeRTTI* p = pkTarget->GetRTTI(); p; p = p->m_pkBase)
    {
        if (p == &g_011f4a68_arg1)
            return true;
    }
    return false;
}

void __cdecl _delete(void*, unsigned int);
struct B462
{
    void __thiscall FUN_00a6d290();
};
struct R462
{
    virtual void f0();
    virtual void f1();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct H462
{
    void* __thiscall DestroyAndFree(unsigned int);
};
// @fnv 0x00a4d460
void* __thiscall H462::DestroyAndFree(unsigned int auiFlags)
{
    *(void* volatile*)this = (void*)&DAT_01098dd4;
    void* p = *(void* volatile*)((char*)this + 0x34);
    if (p)
    {
        if (InterlockedDecrement((long volatile*)((char*)p + 4)) == 0)
            ((R462*)p)->f1();
    }
    ((B462*)this)->FUN_00a6d290();
    if (auiFlags & 1)
        _delete(this, 0x3c);
    return this;
}

struct CloningProcess
{
    void* m_pCloneMap;
};
struct NiAlphaController
{
    void __thiscall CopyMemberData(NiAlphaController*, CloningProcess&);
};
struct CloneHost
{
    char _pad[0x38];
    unsigned short m_uiObjectFlags;
    void* __thiscall CreateClone(CloningProcess&);
};
// @fnv 0x00a4d4b0
void* __thiscall CloneHost::CreateClone(CloningProcess& kCloning)
{
    CloneHost* pkObject = (CloneHost*)BSFadeNode::operator new(0x3c);
    if (pkObject)
    {
        ((NiLightColorController*)pkObject)->FUN_00a57c80();
        *(void**)pkObject = (void*)&DAT_01098dd4;
        pkObject->m_uiObjectFlags = 0;
    }
    else
    {
        pkObject = 0;
    }
    ((NiAlphaController*)this)->CopyMemberData((NiAlphaController*)pkObject, kCloning);
    pkObject->m_uiObjectFlags = m_uiObjectFlags;
    return pkObject;
}

struct StrArr
{
    unsigned short m_uiItemCount;
    unsigned short m_iElementCount;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
void __stdcall FUN_00a57d10(StrArr*);
char* __cdecl FUN_00a7d330(GlobalObjectO2_00a7b610*);
// @fnv 0x00a4d5a0
void __stdcall FUN_00a4d5a0(StrArr* pkStrings)
{
    FUN_00a57d10(pkStrings);
    char* p = FUN_00a7d330(*(GlobalObjectO2_00a7b610**)&g_011f3fa8);
    unsigned int uiIndex = ((unsigned short*)pkStrings)[5];
    if (uiIndex >= ((unsigned short*)pkStrings)[4])
        pkStrings->SetSize(((unsigned short*)pkStrings)[7] + uiIndex);
    pkStrings->SetAt(uiIndex, p);
}

struct NiBinaryStream
{
    char _0[4];
    int _4;
    void* _8;
    int(__cdecl* _c)(NiBinaryStream*, void*, int, unsigned int*, int);
};
struct NiStream
{
    char _pad[0x250];
    NiBinaryStream* _250;
};
struct Base840
{
    char _0[0x38];
    void __thiscall FUN_00a57c00(NiStream&);
};
struct Stand840 : Base840
{
    short _38;
    void __thiscall WriteToStream(NiStream&);
};
// @fnv 0x00a4b840
void __thiscall Stand840::WriteToStream(NiStream& stream)
{
    Base840::FUN_00a57c00(stream);
    NiBinaryStream* __restrict out = stream._250;
    unsigned int size = 2;
    out->_4 += out->_c(out, &_38, 2, &size, 1);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
void* __cdecl FUN_00aa13e0(unsigned int);

struct RefObject
{
    virtual void Unknown00();
    virtual void ReleaseObject();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual void Unknown06();
    virtual void Unknown07();
    virtual void Unknown08();
    virtual void Unknown09();
    virtual void Unknown10();
    virtual void Unknown11();
    virtual void Unknown12();
    virtual void Unknown13();
    virtual void Unknown14();
    virtual void Unknown15();
    virtual void Unknown16();
    virtual void Unknown17();
    virtual void Unknown18();
    virtual void Unknown19();
    virtual void Unknown20();
    virtual void Unknown21();
    virtual void Unknown22();
    virtual void Unknown23();
    virtual void Unknown24();
    virtual void Unknown25();
    virtual void Unknown26();
    virtual void Unknown27();
    virtual void Unknown28();
    virtual void Unknown29();
    virtual void Unknown30();
    virtual void Unknown31();
    virtual void Unknown32();
    virtual void Unknown33();
    virtual void Unknown34();
    virtual void Unknown35();
    virtual void Unknown36();
    virtual void Unknown37();
    virtual void Unknown38();
    virtual void Unknown39();
    virtual void Unknown40();
    virtual void Unknown41();
    virtual void Unknown42();
    virtual void Unknown43();
    virtual void Unknown44();
    virtual void Unknown45();
    virtual void Unknown46();
    virtual void Activate();
    volatile long referenceCount;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    RefObject* __thiscall FUN_00a495f0(RefObject* source);
};
struct VersionedDataBlock
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
    unsigned int version;
    RefObject* __thiscall FUN_00a63430();
};
void __stdcall FUN_00a57630(VersionedDataBlock* stream);
struct Host
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
    RefObject* activeObject;
    void __thiscall LoadActiveObject(VersionedDataBlock* stream);
};
// Reads a stream, and for older versions creates a RefObject from it, swaps it into activeObject with reference counting, then activates it.
// @fnv 0x00a4d3a0
void __thiscall Host::LoadActiveObject(VersionedDataBlock* stream)
{
    FUN_00a57630(stream);
    if (stream->version >= 0x0a010068)
        return;
    RefObject* source = stream->FUN_00a63430();
    if (source)
        InterlockedIncrement(&source->referenceCount);
    void* memory = FUN_00aa13e0(sizeof(RefObject));
    RefObject* fresh = memory ? static_cast<RefObject*>(memory)->FUN_00a495f0(source) : 0;
    RefObject* old = activeObject;
    if (old != fresh)
    {
        if (old && InterlockedDecrement(&old->referenceCount) == 0)
            old->ReleaseObject();
        activeObject = fresh;
        if (fresh)
            InterlockedIncrement(&fresh->referenceCount);
    }
    activeObject->Activate();
    if (source && InterlockedDecrement(&source->referenceCount) == 0)
        source->ReleaseObject();
}

extern float DAT_01096324;
extern NiColor DAT_011f4998;
extern FakeRTTI g_011f4a28;

struct NiControllerOutput_00a4d240
{
    void __thiscall FUN_004bc280(const NiPoint3& value);
    void __thiscall SetEffectColor(const NiColor& value);
};

struct DynCastObj : NiObject
{
    NiControllerOutput_00a4d240* __thiscall DynamicCast(FakeRTTI* type);
};

struct Controller34
{
    void** vtable;
};

struct NiTimeController
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short flags08;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    float value28;
    NiObject* output2c;
    unsigned int unk30;
    Controller34* controller34;
    unsigned int flags38;

    bool __thiscall FUN_00a36250(float value);
    void __thiscall EvaluateAndApplyOutput(float& parameter);
};

// Evaluates the controller output into a clamped 0..1 vector and writes it to the output object, swapping vector/color when flags38 bit 0 is set.
// @fnv 0x00a4d240
void NiTimeController::EvaluateAndApplyOutput(float& parameter)
{
    if ((unsigned char)(flags08 >> 5) & 1)
        value28 = DAT_01096324;
    else if (FUN_00a36250(parameter))
    {
        if (controller34 == 0)
            return;
        if (!((bool(__thiscall**)(Controller34*))(controller34->vtable + 53))[0](controller34))
            return;
    }

    Controller34* controller = controller34;
    if (controller == 0)
        return;

    NiPoint3 sourceValues;
    NiPoint3 kClampedValues;
    typedef bool(__thiscall * Evaluate)(Controller34*, float, NiObject*, NiPoint3*);
    if (!((Evaluate)controller->vtable[37])(controller, value28, output2c, &sourceValues))
        return;

    kClampedValues.x = sourceValues.x;
    kClampedValues.y = sourceValues.y;
    kClampedValues.z = sourceValues.z;
    if (kClampedValues.x < 0.0f)
        kClampedValues.x = 0.0f;
    else if (kClampedValues.x > 1.0f)
        kClampedValues.x = 1.0f;
    if (kClampedValues.y < 0.0f)
        kClampedValues.y = 0.0f;
    else if (kClampedValues.y > 1.0f)
        kClampedValues.y = 1.0f;
    if (kClampedValues.z < 0.0f)
        kClampedValues.z = 0.0f;
    else if (kClampedValues.z > 1.0f)
        kClampedValues.z = 1.0f;

    if (output2c == 0)
        return;
    NiControllerOutput_00a4d240* pOutput = ((DynCastObj*)output2c)->DynamicCast(&g_011f4a28);
    if ((flags38 & 1) != 0)
    {
        pOutput->FUN_004bc280(kClampedValues);
        pOutput->SetEffectColor(DAT_011f4998);
    }
    else
    {
        pOutput->FUN_004bc280((const NiPoint3&)DAT_011f4998);
        pOutput->SetEffectColor((const NiColor&)kClampedValues);
    }
}

struct FUN_00a38e00
{
    FUN_00a38e00();
    virtual void vfn_0000();
};
struct FUN_00a57c80 : FUN_00a38e00
{
    FUN_00a57c80();
};
// @fnv 0x00a57c80
FUN_00a57c80::FUN_00a57c80()
{}

struct BinaryStream_d530
{
    unsigned int unk00;
    unsigned int position;
    unsigned int(__cdecl* read)(BinaryStream_d530*, void*, unsigned int, unsigned int*, unsigned int);

    void ReadFlags(unsigned short& value)
    {
        unsigned int componentSize = sizeof(value);
        unsigned int bytesRead = read(this, &value, sizeof(value), &componentSize, 1);
        position += bytesRead;
    }
};

struct Stream_d530 : VersionedDataBlock
{
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
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
    BinaryStream_d530* input;
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
    unsigned short unk284;
    unsigned short legacyFlags;

    void FUN_00a645b0();
};

struct LoadHost_d530 : Host
{
    unsigned short flags;

    void FUN_00a57c70(Stream_d530& stream);
    void ReadFromStream(Stream_d530& stream);
};

// @fnv 0x00a4d530
void LoadHost_d530::ReadFromStream(Stream_d530& stream)
{
    FUN_00a57c70(stream);
    if (stream.version < 0x0a000102)
    {
        flags = (stream.legacyFlags >> 5) & 0x3f;
    }
    else
    {
        stream.input->ReadFlags(flags);
    }
    if (stream.version < 0x0a010068)
        stream.FUN_00a645b0();
}
