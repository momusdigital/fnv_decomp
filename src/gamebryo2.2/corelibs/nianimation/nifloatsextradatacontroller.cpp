
#include <windows.h>
// src/gamebryo2.2/corelibs/nianimation/nifloatsextradatacontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nifloatsextradatacontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3fcc;

// @fnv 0x00a4ef60
void* __cdecl FUN_00a4ef60()
{
    return &g_011f3fcc;
}

int* __fastcall InitTimeController(int*);
extern int DAT_0109928c;
extern int EmptyFS;

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

// @fnv 0x00a4f000
int* __cdecl FUN_00a4f000()
{
    int* p = static_cast<int*>(BSFadeNode::operator new(0x48));
    if (p)
    {
        InitTimeController(p);
        p[0] = reinterpret_cast<int>(&DAT_0109928c);
        p[0x10] = 0xffffffff;
        p[0x11] = EmptyFS;
        return p;
    }
    return 0;
}

struct ExtraStub
{
    float GetValueAt(int);
};
struct InterpStub
{
    InterpStub* FUN_00a3c390(float);
};
struct FUN_00a4ef70_shell
{
    char _pad[60];
    ExtraStub* e;
    int idx;
    InterpStub* CreateInterpStub(unsigned short);
};
// @fnv 0x00a4ef70
InterpStub* FUN_00a4ef70_shell::CreateInterpStub(unsigned short usIndex)
{
    InterpStub* p = (InterpStub*)BSFadeNode::operator new(0x18);
    if (p)
        return p->FUN_00a3c390(e->GetValueAt(idx));
    return 0;
}

struct CloningProcess
{
    void* m_pCloneMap;
};
struct NiPSysModifierCtlr
{
    void CopyMemberData(NiPSysModifierCtlr*, CloningProcess&);
};
struct NiFloatsExtraDataController : NiPSysModifierCtlr
{
    void* m_pVtbl;
    int m_iFloatsExtraDataIndex;
    int m_kCtlrID;
    NiFloatsExtraDataController* CreateClone(CloningProcess&);
};
// Allocates and constructs a NiFloatsExtraDataController copy, runs the clone helper, then copies the extra data index from this object.
// @fnv 0x00a4efb0
NiFloatsExtraDataController* NiFloatsExtraDataController::CreateClone(CloningProcess& kCloning)
{
    NiFloatsExtraDataController* pkObject = static_cast<NiFloatsExtraDataController*>(BSFadeNode::operator new(0x48));
    if (pkObject)
    {
        InitTimeController(reinterpret_cast<int*>(pkObject));
        *reinterpret_cast<int**>(pkObject) = &DAT_0109928c;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(pkObject) + 0x40) = -1;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(pkObject) + 0x44) = EmptyFS;
    }
    else
    {
        pkObject = 0;
    }
    CopyMemberData(pkObject, kCloning);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(pkObject) + 0x40) =
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x40);
    return pkObject;
}

namespace fnv_00a4f1a0 {
struct NiStream;
struct NiBinaryStream
{
    int _00;
    int position;
    int _08;
    int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
};
struct NiStream
{
    char _00[0x250];
    NiBinaryStream* m_pBackingStream;
};
struct Base00
{
    char _00[0x40];
    void FUN_00a57130(NiStream&);
};
struct NiFloatsExtraDataController : Base00
{
    float m_fCurrentValue;
    void FUN_00a4f1a0(NiStream&);
};
// Calls the base loader, then reads a 4-byte float from the stream into the controller's float field and advances the stream position.
// @fnv 0x00a4f1a0
void NiFloatsExtraDataController::FUN_00a4f1a0(NiStream& stream)
{
    FUN_00a57130(stream);
    NiBinaryStream* __restrict input = stream.m_pBackingStream;
    unsigned int size = 4;
    input->position += input->read(input, &m_fCurrentValue, 4, &size, 1);
}
}  // namespace fnv_00a4f1a0

namespace fnv_00a4f080 {
struct NiRTTI;
struct GlobalObjectO2_00a7b610
{
    char x;
};
extern GlobalObjectO2_00a7b610 g_011f3738;
struct NiObject
{
    NiObject* DynamicCast(const NiRTTI*);
};
struct PoseInterpStub
{
    void SetFloatValue(float);
};
struct NiInterpolator : NiObject
{
};
struct NiFloatInterpolator : PoseInterpStub
{
};
struct Unk89020
{
    float GetValueAt(int);
};
struct NiFloatsExtraDataController
{
    char _pad[0x3c];
    Unk89020* unk3c;
    int unk40;
    void ApplyInterpolatorValue(NiInterpolator*, unsigned short);
};
// Casts the interpolator to a float interpolator and applies the value obtained from unk3c->GetValueAt(unk40).
// @fnv 0x00a4f080
void NiFloatsExtraDataController::ApplyInterpolatorValue(NiInterpolator* pkInterp, unsigned short usIndex)
{
    NiFloatInterpolator* pkFloatInterp;
    if (!pkInterp)
        pkFloatInterp = 0;
    else
        pkFloatInterp = (NiFloatInterpolator*)pkInterp->DynamicCast((const NiRTTI*)&g_011f3738);
    pkFloatInterp->SetFloatValue(unk3c->GetValueAt(unk40));
}
}  // namespace fnv_00a4f080

namespace fnv_00a4f150 {
struct NiBinaryStream
{
    int _00;
    int _04;
    int(__cdecl* _08)(void*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadFloat(float& f)
    {
        unsigned int tmp = 4;
        _04 += _08(this, &f, 4, &tmp, 1);
    }
};
struct NiStream
{
    char _pad0[0xD8];
    unsigned int m_uiNifVersion;
    char _pad1[0x170];
    NiBinaryStream* m_pUnderlyingStream;
    void ResetStreamState();
};
struct NiPSysModifierCtlr
{
    char _pad[0x40];
    void LoadBinary(NiStream&);
};
struct NiFloatsExtraDataController : NiPSysModifierCtlr
{
    float m_fValue;
    void FUN_00a4f150(NiStream&);
};
// @fnv 0x00a4f150
void NiFloatsExtraDataController::FUN_00a4f150(NiStream& kStream)
{
    NiPSysModifierCtlr::LoadBinary(kStream);
    kStream.m_pUnderlyingStream->ReadFloat(m_fValue);
    if (kStream.m_uiNifVersion < 0x0A010068)
        kStream.ResetStreamState();
}
}  // namespace fnv_00a4f150

extern "C" void* g_011f3fcc;
extern int DAT_01099270;

struct StreamStub
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    void FUN_0096ad30(unsigned int offset);
    void FUN_0096ae90(unsigned int index, void** result);
};

void __stdcall FUN_00a57420(StreamStub* stream);
void* __cdecl FUN_00a7d330(void* source);
void* __cdecl FUN_00a7d4d0(int* name, void* object);

struct ControllerStub
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    void* unk40;
    void GetViewerStrings(StreamStub* stream);
};

// @fnv 0x00a4f1e0
void ControllerStub::GetViewerStrings(StreamStub* stream)
{
    FUN_00a57420(stream);
    void* value = FUN_00a7d330(g_011f3fcc);
    unsigned int index = stream->unk0A;
    if (index >= stream->unk08)
        stream->FUN_0096ad30(index + stream->unk0E);
    stream->FUN_0096ae90(index, &value);
    value = FUN_00a7d4d0(&DAT_01099270, unk40);
    index = stream->unk0A;
    if (index >= stream->unk08)
        stream->FUN_0096ad30(index + stream->unk0E);
    stream->FUN_0096ae90(index, &value);
}

extern char* DAT_0109b220;
extern "C" unsigned int __cdecl strlen(const char*);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct NiGlobalStringTable
{
    static char* AddString(const char*);
};
void* __cdecl NiMalloc(unsigned int);
void __cdecl NiFree(void*);
char* __cdecl FUN_00a305b0(char*, unsigned int, const char*, char*, int);

struct FixedString
{
    char* m_pString;
    FixedString& operator=(const char* pcStr)
    {
        char* old = m_pString;
        if (old != pcStr)
        {
            m_pString = NiGlobalStringTable::AddString(pcStr);
            if (old != DAT_0109b220)
                InterlockedDecrement((long volatile*)(old - 8));
        }
        return *this;
    }
};

struct StrHolder
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    char* m_pPrefix;
    int unk3c;
    int m_iIndex;
    FixedString m_str;
    char* GetFormattedString();
};

// Returns m_str.m_pString, lazily building it from m_pPrefix and m_iIndex via FUN_00a305b0 when m_str is empty.
// @fnv 0x00a4ebd0
char* StrHolder::GetFormattedString()
{
    if (m_str.m_pString != DAT_0109b220)
        return m_str.m_pString;
    m_str = 0;
    char* prefix = m_pPrefix;
    if (prefix)
    {
        unsigned int size = strlen(prefix) + 0xf;
        char* buf = (char*)NiMalloc(size);
        FUN_00a305b0(buf, size, "%s[%d]", prefix, m_iIndex);
        m_str = buf;
        NiFree(buf);
    }
    return m_str.m_pString;
}

extern float DAT_01096324;
struct SplineEvaluationState
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Reserved21();
    virtual void Reserved22();
    virtual void Reserved23();
    virtual void Reserved24();
    virtual void Reserved25();
    virtual void Reserved26();
    virtual void Reserved27();
    virtual void Reserved28();
    virtual void Reserved29();
    virtual void Reserved30();
    virtual void Reserved31();
    virtual void Reserved32();
    virtual void Reserved33();
    virtual void Reserved34();
    virtual void Reserved35();
    virtual void Reserved36();
    virtual void Reserved37();
    virtual void Reserved38();
    virtual bool Update(float time, void* target, float& value);
    virtual void Reserved40();
    virtual void Reserved41();
    virtual void Reserved42();
    virtual void Reserved43();
    virtual void Reserved44();
    virtual void Reserved45();
    virtual void Reserved46();
    virtual void Reserved47();
    virtual void Reserved48();
    virtual void Reserved49();
    virtual void Reserved50();
    virtual void Reserved51();
    virtual void Reserved52();
    virtual bool AlwaysUpdate();
};
struct NiFloatsExtraData
{
    void SetValue(int index, float value);
};
struct FloatController
{
    unsigned int unk00, unk04;
    unsigned short flags;
    unsigned short unk0a;
    unsigned int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    float lastTime;
    void* target;
    unsigned int unk30;
    SplineEvaluationState* interpolator;
    unsigned int unk38;
    NiFloatsExtraData* extraData;
    int index;
    bool FUN_00a36250(float time);
    bool IsManaged() const
    {
        return ((unsigned char)(flags >> 5) & 1) != 0;
    }
    void FUN_00a4f0c0(float* updateData);
};
// Updates lastTime for managed controllers, evaluates the interpolator when present, and writes a successful value to extraData.
// @fnv 0x00a4f0c0
void FloatController::FUN_00a4f0c0(float* updateData)
{
    if (IsManaged())
    {
        lastTime = DAT_01096324;
    }
    else if (FUN_00a36250(*updateData))
    {
        if (!interpolator || !interpolator->AlwaysUpdate())
            return;
    }
    float value;
    if (interpolator && interpolator->Update(lastTime, target, value))
    {
        if (extraData)
            extraData->SetValue(index, value);
    }
}

namespace fnv_00c312f0 {
struct NiFixedString
{
    bool Exists();
    unsigned int GetLength();
    unsigned int GetRefCount();
    bool Equals(char*);
    bool EqualsNoCase(char*);
    bool Contains(char*);
    bool HasSuffix(char*);
    unsigned int QHandle();
    void Init();
    void* __vecDelDtor(unsigned int);
    char* m_kHandle;
};
typedef char _sizecheck_NiFixedString[sizeof(NiFixedString) == 4 ? 1 : -1];

extern int EmptyFS;

struct NiTransformController
{
    void CopyMemberData(NiTransformController* pkDest, void* kCloning);
};

struct NiFloatsExtraDataController : NiTransformController
{
    char m_ucUnknownByte[0x38];
    NiFixedString m_kName;
    void FUN_00c312f0(NiFloatsExtraDataController* pkDest, void* kCloning);
};

// Copies NiTransformController member data and transfers the NiFixedString name reference count between pkDest and the source.
// @fnv 0x00c312f0
void NiFloatsExtraDataController::FUN_00c312f0(NiFloatsExtraDataController* pkDest, void* kCloning)
{
    NiTransformController::CopyMemberData(pkDest, kCloning);
    char* pcName = m_kName.m_kHandle;
    if (pkDest->m_kName.m_kHandle != pcName)
    {
        if (pcName != (char*)EmptyFS)
            InterlockedIncrement((volatile long*)(pcName - 8));
        char* pcOldName = pkDest->m_kName.m_kHandle;
        if (pcOldName != (char*)EmptyFS)
            InterlockedDecrement((volatile long*)(pcOldName - 8));
        pkDest->m_kName.m_kHandle = pcName;
    }
}
}  // namespace fnv_00c312f0

extern int DAT_0109928c;

struct BaseController
{
    void FUN_00a572d0();
};

struct MyController : BaseController
{

    void* volatile vtable;

    unsigned int field04;

    unsigned int field08;

    unsigned int field0c;

    unsigned int field10;

    unsigned int field14;

    unsigned int field18;

    unsigned int field1c;

    unsigned int field20;

    unsigned int field24;

    unsigned int field28;

    unsigned int field2c;

    unsigned int field30;

    unsigned int field34;

    unsigned int field38;

    unsigned int field3c;

    unsigned int field40;

    unsigned char* volatile sharedStorage;

    MyController* FUN_00a4f040(unsigned int destroyFlag);
};

void __cdecl FUN_00aa1460(void*, unsigned int);

// Releases shared storage, calls FUN_00a572d0, and frees this when destroyFlag bit 0 is set.
// @fnv 0x00a4f040
MyController* MyController::FUN_00a4f040(unsigned int destroyFlag)
{

    this->vtable = &DAT_0109928c;

    unsigned char* storage = this->sharedStorage;

    if (storage != (unsigned char*)DAT_0109b220)
    {

        InterlockedDecrement((long volatile*)(storage - 8));
    }

    this->FUN_00a572d0();

    if ((destroyFlag & 1) != 0)
    {

        FUN_00aa1460(this, sizeof(*this));
    }

    return this;
}
