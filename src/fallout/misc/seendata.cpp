// fallout/misc/seendata.cpp: SeenData, IntSeenData, SeenData_S, SeenDataShell and more (25 functions)

#include "seendata_decls.h"

// @fnv 0x0087a0e0
void SeenData::LoadGame(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData(m_uiSeenData, 0x20);
}

// @fnv 0x00879940
IntSeenData::IntSeenData()
{
    m_ppVirtualMethodTable = &DAT_01083fc4;
    memset(m_uiSeenData, 0, 0x20);
}

// Sets position from the index's row/column scaled by DAT_011a31e8 when index < DAT_011a31ec, otherwise to FLT_MAX.
// @fnv 0x00879bd0
void SeenData::GetPositionForIndex(unsigned int index, NiPoint3& position)
{
    float remainder;
    float quotient;

    if (index < DAT_011a31ec)
    {
        remainder = static_cast<float>(index % 16);
        quotient = static_cast<float>(index >> 4);
        position = NiPoint3(DAT_011a31e8 * remainder, DAT_011a31e8 * quotient, 0.0f);
    }
    else
    {
        position = NiPoint3(3.402823466e+38F, 3.402823466e+38F, 3.402823466e+38F);
    }
}

// @fnv 0x0087a570
void IntSeenData::LoadGame(BGSLoadFormBuffer* pLoadBuffer)
{
    struct LoadCursor
    {
        unsigned int count;
        IntSeenData* section;
    } cursor;
    cursor.count = pLoadBuffer->ReadElementCount();
    cursor.section = this;
    for (unsigned int index = 0; index < cursor.count; ++index)
    {
        pLoadBuffer->ReadTypedData(&cursor.section->m_cFirstByte, 1);
        pLoadBuffer->ReadTypedData(&cursor.section->m_cFollowingByte, 1);
        cursor.section->SeenData::LoadGame(pLoadBuffer);
        if (index < cursor.count - 1)
            cursor.section->m_pNext = new IntSeenData(0, 0);
        cursor.section = cursor.section->m_pNext;
    }
}

struct FUN_008799f0_shell : public SeenData
{
    bool IsBitSet(unsigned int);
};

// Tests whether the bit at index aiBit is set in the bit array stored at offset 4 of this object.
// @fnv 0x008799f0
bool FUN_008799f0_shell::IsBitSet(unsigned int aiBit)
{
    unsigned int iIndex = aiBit >> 5;
    unsigned int iWhichBit = aiBit - (iIndex << 5);
    if ((1 << iWhichBit) & ((unsigned int*)((char*)this + 4))[iIndex])
        return true;
    else
        return false;
}

struct S79a
{
    unsigned int pad;
    unsigned int arr[1];
    bool SetSeenBitReturningPrevious(unsigned int idx, bool set);
};
// Reads the bit at idx from the bit array, sets or clears it depending on set, and returns the previous bit value.
// @fnv 0x00879a40
bool S79a::SetSeenBitReturningPrevious(unsigned int auiIndex, bool set)
{
    unsigned int aWord;
    unsigned int bBit;
    aWord = auiIndex >> 5;
    bBit = auiIndex - (aWord << 5);
    {
        bool old = (1 << bBit) & arr[aWord] ? true : false;
        if (set)
            arr[aWord] |= 1 << bBit;
        else
            arr[aWord] &= ~(1 << bBit);
        return old;
    }
}

struct SettingT_GCol
{
    float* Float();
};
extern SettingT_GCol originalRuntimeFloatSetting37;
// @fnv 0x00879bb0
float GetRuntimeFloatSetting37()
{
    return *originalRuntimeFloatSetting37.Float();
}

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011df198;
struct Pt
{
    float x, y, z;
    void _ref_006815c0();
    Pt& operator+=(const NiPoint3&);
    Pt operator-(const NiPoint3&) const;
    float Length() const;
};
float __cdecl GetRuntimeFloatSetting37();
struct SeenData_S
{
    bool IsBitSet(unsigned int);
    void SetSeenBitReturningPrevious(unsigned int, bool);
    bool HasEnoughSeenPoints(const NiPoint3& a, const NiPoint3& b);
};

// @fnv 0x00879ad0
bool SeenData_S::HasEnoughSeenPoints(const NiPoint3& aPoint, const NiPoint3& aOffset)
{
    int iSeenCount = 0;
    for (unsigned int uiIndex = 0; uiIndex < DAT_011a31ec; uiIndex++)
    {
        if (!IsBitSet(uiIndex))
        {
            Pt diff;
            diff._ref_006815c0();
            SeenData::GetPositionForIndex(uiIndex, reinterpret_cast<NiPoint3&>(diff));
            diff += aOffset;
            {
                Pt delta = diff - aPoint;
                if (delta.Length() < GetRuntimeFloatSetting37())
                {
                    SetSeenBitReturningPrevious(uiIndex, true);
                    iSeenCount++;
                }
            }
        }
        else
        {
            iSeenCount++;
        }
    }
    return iSeenCount >= *g_011df198.Int();
}

int __cdecl TruncateFloatToInt(float);

// Quantizes pos.x and pos.y to multiples of DAT_011a31e8 within their 4096-unit cells and sets pos.z to 0.
// @fnv 0x00879ca0
void SnapToGridCell(NiPoint3& pos)
{
    int cellY;
    int subX;
    int cellX;
    int iSubCellY;
    subX = TruncateFloatToInt(pos.x) >> 12;
    cellX = TruncateFloatToInt(pos.y) >> 12;
    cellY = (int)(TruncateFloatToInt(pos.x - (subX << 12)) / DAT_011a31e8);
    iSubCellY = (int)(TruncateFloatToInt(pos.y - (cellX << 12)) / DAT_011a31e8);
    pos.x = (subX << 12) + cellY * DAT_011a31e8;
    pos.y = (cellX << 12) + iSubCellY * DAT_011a31e8;
    pos.z = 0.0f;
}

// @fnv 0x00879d90
float FUN_00879d90()
{
    return DAT_011a31e8;
}

struct FUN_0087a030_shell
{
    unsigned short __thiscall GetSaveSize(bool abRecursing);
};

// Returns the save size for this object: a fixed 0x20 bytes, ignoring the recursion flag.
// @fnv 0x0087a030
unsigned short FUN_0087a030_shell::GetSaveSize(bool abRecursing)
{
    unsigned short isize = 0;
    isize += 0x20;
    return isize;
}

struct TESSaveLoadGame
{
    void ReadTypedData(void*, unsigned int);
};

TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_0087a090_shell
{
    void __thiscall FUN_0087a090(unsigned short);
};

// @fnv 0x0087a090
void __thiscall FUN_0087a090_shell::FUN_0087a090(unsigned short)
{
    g_TESSaveLoadGame->ReadTypedData((void*)((char*)this + 4), 0x20);
}

struct BGSSaveFormBuffer
{
    void __thiscall SaveData(void*, int, int);
};

struct FUN_0087a0c0_shell
{
    void SaveFormData(void* buf);
};

// Calls SaveData on the buffer with this+4 and a size of 0x20.
// @fnv 0x0087a0c0
void __thiscall FUN_0087a0c0_shell::SaveFormData(void* buf)
{
    ((BGSSaveFormBuffer*)buf)->SaveData((char*)this + 4, 0x20, 0);
}

struct Class_00879970
{
    void SetVtable();
    void* FUN_00879970(unsigned int);
};
void __cdecl _Deallocate(void*);
// @fnv 0x00879970
void* Class_00879970::FUN_00879970(unsigned int flags)
{
    SetVtable();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0087a060 {
struct TESSaveLoadGame
{
    void FUN_008579b0(void* a1, int a2);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct Proxy87060
{
    int _0;
    int _4;
    void FUN_0087a060(bool abRecursing);
};
// Passes the address of _4 and size 0x20 to TESSaveLoadGame::FUN_008579b0.
// @fnv 0x0087a060
void Proxy87060::FUN_0087a060(bool abRecursing)
{
    g_TESSaveLoadGame->FUN_008579b0(&_4, 0x20);
}
}  // namespace fnv_0087a060

void _Deallocate(void*);
struct FUN_0087a140_Target
{
    void FUN_0087a170();
    void* FUN_0087a140(unsigned int);
};
// Calls FUN_0087a170, then if the low bit of flags is set deallocates this, and returns this.
// @fnv 0x0087a140
void* FUN_0087a140_Target::FUN_0087a140(unsigned int flags)
{
    FUN_0087a170();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_0087a4e0 {
struct BGSSaveGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveFormBuffer
{
    void SaveData(void* p, int a, int b);
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int a, unsigned int b);
};
struct FUN_0087a0c0_shell
{
    void SaveFormData(void* p);
};
struct IntSeenData_0087a4e0
{
    void* p;
    IntSeenData_0087a4e0* m_pNext;
    void SaveToBuffer(BGSSaveFormBuffer* buffer);
};
// Saves each node's bytes at offsets 0x24 and 0x25 and its linked data to the buffer, then writes the node count at the recorded position.
// @fnv 0x0087a4e0
void IntSeenData_0087a4e0::SaveToBuffer(BGSSaveFormBuffer* buffer)
{
    unsigned int icount = 0;
    unsigned int icountPosition = buffer->FUN_00865f20();
    IntSeenData_0087a4e0* pNode = this;
    while (pNode)
    {
        buffer->SaveData((void*)((char*)pNode + 0x24), 1, 0);
        buffer->SaveData((void*)((char*)pNode + 0x25), 1, 0);
        ((FUN_0087a0c0_shell*)pNode)->SaveFormData(buffer);
        pNode = *(IntSeenData_0087a4e0**)((char*)pNode + 0x28);
        ++icount;
    }
    buffer->FUN_00865ff0(icount, icountPosition);
}
}  // namespace fnv_0087a4e0

extern void* DAT_01083fc4;

struct FUN_008799a0_shell
{
    void SetVtable();
};

// @fnv 0x008799a0
void FUN_008799a0_shell::SetVtable()
{
    *(void**)this = &DAT_01083fc4;
}

namespace fnv_0087a3e0 {
extern int _data_011c16bc;

class SaveManager
{
};

extern SaveManager* DAT_011de45c;

class TESSaveLoadGame
{
  public:
    void ReadTypedData(void* data, unsigned int size);
};

struct FUN_0087a090_shell
{
    void FUN_0087a090(unsigned short value);
};

struct FUN_0087a3e0_vtable
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(unsigned short value);
};

struct FUN_0087a3e0_shell
{
    void FUN_0087a3e0(unsigned short aiCount);
};

// @fnv 0x0087a3e0
void FUN_0087a3e0_shell::FUN_0087a3e0(unsigned short aiCount)
{
    reinterpret_cast<FUN_0087a090_shell*>(this)->FUN_0087a090(0xffff);

    if (aiCount == 0xffff)
        reinterpret_cast<TESSaveLoadGame*>(DAT_011de45c)->ReadTypedData(&aiCount, 2);

    reinterpret_cast<TESSaveLoadGame*>(DAT_011de45c)->ReadTypedData(reinterpret_cast<unsigned char*>(this) + 0x24, 1);
    reinterpret_cast<TESSaveLoadGame*>(DAT_011de45c)->ReadTypedData(reinterpret_cast<unsigned char*>(this) + 0x25, 1);

    aiCount--;

    if (aiCount > 0)
    {
        *reinterpret_cast<IntSeenData**>(reinterpret_cast<unsigned char*>(this) + 0x28) = new IntSeenData(0, 0);

        reinterpret_cast<FUN_0087a3e0_vtable*>(
            *reinterpret_cast<IntSeenData**>(reinterpret_cast<unsigned char*>(this) + 0x28))
            ->f6(aiCount);
    }
}
}  // namespace fnv_0087a3e0

struct ImageSpaceEffectParam
{
    float r, g, b, a;
    ImageSpaceEffectParam(float, float, float, float);
};
struct Position
{
    float x, y, z;
    void FUN_006815c0();
    Position& FUN_0063c8a0(const NiPoint3&);
};
struct Marker
{
    void FUN_004bc1f0(float, float, float);
};
Marker* __cdecl CreateSquareLines(float, ImageSpaceEffectParam*, int);
void __cdecl FUN_00879bd0(unsigned int, Position&);
struct Parent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void Attach(Marker*, int);
};
struct SeenDataShell : SeenData
{
    bool IsBitSet(unsigned int);
    void AttachMarkersForSeenData(Parent*, const NiPoint3&, int);
};
// @fnv 0x00879f20
void SeenDataShell::AttachMarkersForSeenData(Parent* parent, const NiPoint3& offset, int unused)
{
    if (parent)
    {
        ImageSpaceEffectParam effectColor(1.0f, 0.0f, 0.0f, 0.0f);
        float half = DAT_011a31e8 / 2.0;
        for (unsigned int i3 = 0; i3 < DAT_011a31ec; i3++)
        {
            if (IsBitSet(i3))
            {
                Position position;
                position.FUN_006815c0();
                FUN_00879bd0(i3, position);
                position.FUN_0063c8a0(offset);
                Marker* marker3 = CreateSquareLines(DAT_011a31e8, &effectColor, 1);
                parent->Attach(marker3, 1);
                marker3->FUN_004bc1f0(position.x + half, position.y + half, position.z);
            }
        }
    }
}

struct B87A200Point3
{
    float x;
    float y;
    float z;

    B87A200Point3* Set(float fX, float fY, float fZ);
};

class B87A200Listener
{
  public:
    virtual void vfunc00();
    virtual void Update(void* pvContext, B87A200Point3* pkPosition, bool bFlag);
};

class B87A200Cell
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    char m_cX;
    char m_cY;
    char unk26;
    char unk27;
    B87A200Listener* m_pkListener;

    void AttachMarkersForSeenData(void* pvContext, B87A200Point3* pkCenter, bool bFlag);
    void FUN_0087a200(void* pvContext, B87A200Point3* pkPosition, bool bFlag);
};

// Computes the cell centre from m_cX/m_cY, forwards it to AttachMarkersForSeenData, then notifies m_pkListener with the position and flag.
// @fnv 0x0087a200
void B87A200Cell::FUN_0087a200(void* pvContext, B87A200Point3* pkPosition, bool bFlag)
{
    int iX = m_cX;
    int iY = m_cY;
    B87A200Point3 kTargetCenter;
    kTargetCenter.Set((float)((iX << 12) + 2048), (float)((iY << 12) + 2048), pkPosition->z);
    AttachMarkersForSeenData(pvContext, &kTargetCenter, bFlag);
    if (m_pkListener)
        m_pkListener->Update(pvContext, pkPosition, bFlag);
}

class A2A0Child
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual unsigned short GetSaveSize(bool bFull);
};

class A2A0Base
{
  public:
    unsigned short GetBaseSaveSize(bool bFull);
};

class A2A0Object : public A2A0Base
{
  public:
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
    A2A0Child* m_pkChild;

    unsigned short FUN_0087a2a0(bool bFull);
};

// Computes the save size: base size, plus 2 when not full, plus 2, plus the child's save size if m_pkChild is set.
// @fnv 0x0087a2a0
unsigned short A2A0Object::FUN_0087a2a0(bool bFull)
{
    unsigned short usSize = 0;
    usSize += GetBaseSaveSize(false);
    if (!bFull)
        usSize += 2;
    usSize += 1;
    usSize += 1;
    if (m_pkChild)
        usSize += m_pkChild->GetSaveSize(true);
    return usSize;
}

struct SaveDataWriter
{
    void FUN_008579b0(void* data, unsigned int size);
};
extern SaveDataWriter* DAT_011de45c;

struct SeenSectionDispatcher
{
    virtual void Release();
    virtual void LoadGame();
    virtual void GetSaveSize();
    virtual void SaveGame();
    virtual void SaveSeenSection(bool abRecursing);
};

struct FUN_0087a330_shell : SeenData
{
    char m_cFirstByte;
    char m_cFollowingByte;
    unsigned short layoutPadding26;
    FUN_0087a330_shell* m_pNext;

    void FUN_0087a060(bool abRecursing);
    void SaveSeenSection(bool abRecursing);
};

// Writes the section's two bytes and, when not recursing, the section count, then recurses into the next section.
// @fnv 0x0087a330
void FUN_0087a330_shell::SaveSeenSection(bool abRecursing)
{
    FUN_0087a330_shell* pSection;
    FUN_0087a060(false);
    if (!abRecursing)
    {
        unsigned short usSectionCount;
        usSectionCount = 1;
        pSection = this;
        while ((pSection = pSection->m_pNext) != 0)
        {
            ++usSectionCount;
        }
        DAT_011de45c->FUN_008579b0(&usSectionCount, 2);
    }
    DAT_011de45c->FUN_008579b0(&m_cFirstByte, 1);
    DAT_011de45c->FUN_008579b0(&m_cFollowingByte, 1);
    if (m_pNext)
    {
        reinterpret_cast<SeenSectionDispatcher*>(m_pNext)->SaveSeenSection(true);
    }
}

extern float DAT_011a31e8;
// Converts a world position into cell-local x/y offsets, dividing by DAT_011a31e8, using centered or grid-aligned cell origins.
// @fnv 0x00879da0
void WorldToCellOffset(const NiPoint3& position, bool centered, int& x, int& y)
{
    if (centered)
    {
        int cellX = (TruncateFloatToInt(position.x) - 2048) >> 12;
        int cellY = (TruncateFloatToInt(position.y) - 2048) >> 12;
        x = TruncateFloatToInt(position.x) - ((cellX << 12) + 2048);
        x /= (int)DAT_011a31e8;
        y = TruncateFloatToInt(position.y) - ((cellY << 12) + 2048);
        y /= (int)DAT_011a31e8;
    }
    else
    {
        int gridX = TruncateFloatToInt(position.x) >> 12;
        int gridY = TruncateFloatToInt(position.y) >> 12;
        x = TruncateFloatToInt(position.x) - (gridX << 12);
        x /= (int)DAT_011a31e8;
        y = TruncateFloatToInt(position.y) - (gridY << 12);
        y /= (int)DAT_011a31e8;
    }
}

// Destructor: delete the owned helper object; the base part is destroyed afterwards.

class A170Helper
{
  public:
    virtual ~A170Helper();
};

class A170Base
{
  public:
    virtual ~A170Base();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

class FUN_0087a170 : public A170Base
{
  public:
    virtual ~FUN_0087a170();

    A170Helper* m_pkHelper;
};

// Destructor that deletes the owned helper object pointed to by m_pkHelper.
// @fnv 0x0087a170
FUN_0087a170::~FUN_0087a170()
{
    delete m_pkHelper;
}
