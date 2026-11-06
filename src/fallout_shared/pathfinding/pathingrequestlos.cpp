// fallout_shared/pathfinding/pathingrequestlos.cpp: PathingRequestLOS, PathingRequestLOS_ (10 functions)

#include <math.h>

// @fnv 0x004b1480
float WrapAngle(float angle)
{
    if (angle < 0.0)
        angle = fmod((float)(angle + 6.2831854820251465), 6.2831854820251465f);
    else if (angle >= 6.2831854820251465)
        angle = fmod(angle, 6.2831854820251465f);
    return angle;
}

struct PathingRequestLOS
{
    virtual ~PathingRequestLOS();
    static void operator delete(void* p, unsigned int size);
    void* DestroyAndFree(unsigned int flags);
};
// Runs the destructor and, when bit 0 of flags is set, frees the object with operator delete of size 0xd8; returns this.
// @fnv 0x006e5890
void* PathingRequestLOS::DestroyAndFree(unsigned int flags)
{
    this->PathingRequestLOS::~PathingRequestLOS();
    if (flags & 1)
        PathingRequestLOS::operator delete(this, 0xd8);
    return this;
}

struct C006e39d0
{
    void FUN_006e39d0();
};
void __cdecl _delete(void*, unsigned int);
struct S006e3a50
{
    void* FUN_006e3a50(unsigned int);
};
// Calls FUN_006e39d0 on this, deletes this with size 24 when flags has bit 0 set, and returns this.
// @fnv 0x006e3a50
void* S006e3a50::FUN_006e3a50(unsigned int flags)
{
    reinterpret_cast<C006e39d0*>(this)->FUN_006e39d0();
    if (flags & 1)
        _delete(this, 24);
    return this;
}

struct BGSLoadFormBuffer
{
    void ReadTypedData(void* dest, unsigned int size);
    int ReadElementCount();
};
struct ParentSpaceNode
{
    char data[12];
};
struct BSSimpleArray_ParentSpaceNode
{
    ParentSpaceNode& GetAt(int index);
    void SetSize(int size, int flags);
};
struct PathingRequest
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};
struct PathingRequestLOS_ : public PathingRequest
{
    void FUN_006e5c00(BGSLoadFormBuffer* buffer);
};
// Calls LoadGame, then reads a count and that many 12-byte nodes into the array at offset 0xb4, followed by fields at 0xc4, 0xc8 and 0xd4.
// @fnv 0x006e5c00
void PathingRequestLOS_::FUN_006e5c00(BGSLoadFormBuffer* buffer)
{
    LoadGame(buffer);
    unsigned int count = buffer->ReadElementCount();
    ((BSSimpleArray_ParentSpaceNode*)((char*)this + 0xb4))->SetSize(count, 1);
    unsigned int i = 0;
    for (; i < count; ++i)
    {
        ParentSpaceNode& node = ((BSSimpleArray_ParentSpaceNode*)((char*)this + 0xb4))->GetAt(i);
        buffer->ReadTypedData(&node, 12);
    }
    buffer->ReadTypedData((char*)this + 0xc4, 4);
    buffer->ReadTypedData((char*)this + 0xc8, 12);
    buffer->ReadTypedData((char*)this + 0xd4, 4);
}

struct S_006e5a40
{
    int a;
    int b;
    int c;
};
struct C_006e5a40
{
    char pad[0xC8];
    S_006e5a40 s;
    float f;
    void FUN_006e5a40(S_006e5a40 v, float w);
};
// Stores the given S_006e5a40 value into s and the float w into f.
// @fnv 0x006e5a40
void C_006e5a40::FUN_006e5a40(S_006e5a40 v, float w)
{
    s = v;
    f = w;
}

struct PathingRequestCopyHelper
{
    void CopyTo(PathingRequest*);
};
struct Helper62d0
{
    Helper62d0& operator=(const Helper62d0&);
};
struct BSSimpleArray_1024
{
    void CopyTo(BSSimpleArray_1024*);
};
struct FUN_006e5a80_shell : public PathingRequest
{
    void FUN_006e5a80(PathingRequest* apDest);
};
// @fnv 0x006e5a80
void FUN_006e5a80_shell::FUN_006e5a80(PathingRequest* apDest)
{
    PathingRequest* pdest = apDest;
    ((PathingRequestCopyHelper*)this)->CopyTo(pdest);
    *(Helper62d0*)((char*)pdest + 0xb0) = *(Helper62d0*)((char*)this + 0xb0);
    ((BSSimpleArray_1024*)((char*)this + 0xb4))->CopyTo((BSSimpleArray_1024*)((char*)pdest + 0xb4));
    *(float*)((char*)pdest + 0xc4) = *(float*)((char*)this + 0xc4);
    ((C_006e5a40*)pdest)->FUN_006e5a40(*(S_006e5a40*)((char*)this + 0xc8), *(float*)((char*)this + 0xd4));
}

struct BGSSaveGameBuffer
{
    void FUN_00865f60(unsigned int flags);
};

struct BGSSaveFormBuffer : public BGSSaveGameBuffer
{
    void SaveData(void* data, int size, int flags);
};

struct StandIn5740
{
    void FUN_006e3230(BGSSaveFormBuffer* buffer);
};

struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};

struct FUN_006e5b20_shell : public PathingRequestLOS_
{
    void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x006e5b20
void FUN_006e5b20_shell::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<StandIn5740*>(this)->FUN_006e3230(apSaveGameBuffer);

    unsigned int isaveGameCount =
        (reinterpret_cast<unsigned int>(this) + 0xB4) != 0
            ? reinterpret_cast<TESObjectREFR_GetFlags_Helper*>(reinterpret_cast<char*>(this) + 0xB4)->CallGetFlags()
            : 0;

    reinterpret_cast<BGSSaveGameBuffer*>(apSaveGameBuffer)->FUN_00865f60(isaveGameCount);

    {
        unsigned int i;
        for (i = 0; i < isaveGameCount; ++i)
        {
            ParentSpaceNode& node =
                reinterpret_cast<BSSimpleArray_ParentSpaceNode*>(reinterpret_cast<char*>(this) + 0xB4)->GetAt(i);

            apSaveGameBuffer->SaveData(&node, 0xC, 0);
        }
    }

    apSaveGameBuffer->SaveData(reinterpret_cast<char*>(this) + 0xC4, 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<char*>(this) + 0xC8, 0xC, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<char*>(this) + 0xD4, 4, 0);
}

extern float g_fFUN006e57e0_c4;

class FUN_006e57e0_base
{
  public:
    FUN_006e57e0_base();
    virtual ~FUN_006e57e0_base();
};

class FUN_006e57e0_sub_b0
{
  public:
    FUN_006e57e0_sub_b0(int a);
    ~FUN_006e57e0_sub_b0();
    unsigned int m_00;
};

class FUN_006e57e0_sub_b4
{
  public:
    FUN_006e57e0_sub_b4();
    ~FUN_006e57e0_sub_b4();
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
};

class FUN_006e57e0_sub_c8
{
  public:
    FUN_006e57e0_sub_c8();
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
};

class FUN_006e57e0 : public FUN_006e57e0_base
{
  public:
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    FUN_006e57e0_sub_b0 m_b0;
    FUN_006e57e0_sub_b4 m_b4;
    float m_c4;
    FUN_006e57e0_sub_c8 m_c8;
    float m_d4;

    FUN_006e57e0();
    virtual ~FUN_006e57e0();
};

// Initializes the object's base and sub-objects, sets m_c4 from g_fFUN006e57e0_c4 and m_d4 to 0.0f.
// @fnv 0x006e57e0
FUN_006e57e0::FUN_006e57e0() : FUN_006e57e0_base(), m_b0(0), m_b4(), m_c8()
{
    m_c4 = g_fFUN006e57e0_c4;
    m_d4 = 0.0f;
}

struct S_006e58d0_Base
{
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
    virtual ~S_006e58d0_Base();
};
struct S_006e58d0_M0
{
    int unk00;
    ~S_006e58d0_M0();
};
struct S_006e58d0_M4
{
    int unk00;
    ~S_006e58d0_M4();
};

struct __declspec(novtable) FUN_006e58d0 : S_006e58d0_Base
{
    S_006e58d0_M0 m_b0;
    S_006e58d0_M4 m_b4;
    virtual ~FUN_006e58d0();
};
// Empty destructor for the object; the base and member destructors run implicitly.
// @fnv 0x006e58d0
FUN_006e58d0::~FUN_006e58d0()
{}

// Copy constructor of a path-target object: copy the base and the target ref, re-derive the node list,
// and re-place it at the source's position and radius.

struct E5940Point3
{
    float x;
    float y;
    float z;
};

class E5940Base
{
  public:
    E5940Base(const E5940Base& kOther);
    virtual ~E5940Base();
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
};

class E5940TargetRef
{
  public:
    E5940TargetRef(const E5940TargetRef& kOther);
    ~E5940TargetRef();
    void* m_pkTarget;
};

class E5940NodeList
{
  public:
    E5940NodeList();
    ~E5940NodeList();
    void CopyTo(E5940NodeList* pkDest) const;
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class E5940Flags
{
  public:
    E5940Flags();
    int m_iFlags;
};

class FUN_006e5940 : public E5940Base
{
  public:
    FUN_006e5940(const FUN_006e5940& kOther);
    virtual ~FUN_006e5940();

    E5940Point3& GetPosition(E5940Point3& kPos) const;
    float GetRadius() const;
    void Place(E5940Point3 kPos, float fRadius);

    E5940TargetRef m_kRoomNode;
    E5940NodeList m_kNodeArray;
    float m_fWeight;
    E5940Flags m_kFlags;
};

// Copy-constructs from kOther: copies base, target ref and weight, copies the node list, then places this at kOther's position and radius.
// @fnv 0x006e5940
FUN_006e5940::FUN_006e5940(const FUN_006e5940& kOther)
    : E5940Base(kOther), m_kRoomNode(kOther.m_kRoomNode), m_fWeight(kOther.m_fWeight)
{
    kOther.m_kNodeArray.CopyTo(&m_kNodeArray);
    E5940Point3 kPos;
    Place(kOther.GetPosition(kPos), kOther.GetRadius());
}
