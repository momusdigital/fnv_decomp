
// src/havok/physics/collide/shape/compound/collection/extendedmeshshape/hkpextendedmeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/extendedmeshshape/hkpextendedmeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d554a0_class
{
    int m_d0;
    int __thiscall getNumChildShapes();
    int __thiscall GetOrInitValue();
};

// @fnv 0x00d554a0
int __thiscall FUN_00d554a0_class::GetOrInitValue()
{
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xd0) < 0)
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xd0) = getNumChildShapes();
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xd0);
}

void __cdecl FUN_00d26230(void* first, void* second, void* third, float value, int last);
struct FUN_00d56040_shell
{
    void __thiscall FUN_00d56040(void* first, float value, int last);
};
// Calls FUN_00d26230 with first, the two buffers at offsets 0x90 and 0xa0 of this, value and last.
// @fnv 0x00d56040
void __thiscall FUN_00d56040_shell::FUN_00d56040(void* first, float value, int last)
{
    FUN_00d26230(first, (unsigned char*)this + 0x90, (unsigned char*)this + 0xa0, value, last);
}

struct hkMemoryAllocator;

struct AudioMgr
{
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
__declspec(nothrow) BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

__declspec(nothrow) void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);

struct hkShortArray
{
    short* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserveExactly(int n)
    {
        AudioMgr* m = audio();
        if (getCapacity() < n)
            FUN_00c908c0(m->heap(), this, n, sizeof(short));
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(short));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
};

struct Elem
{
    char pad0[0x14];
    int m_uiItemCount;
    char pad1[0x4c - 0x18];
    int m_offset;
    char pad2[0x60 - 0x50];
};

struct FUN_00d56070_class
{
    char pad0[0xb0];
    int m_bits;
    Elem* m_pElements;
    int m_iCapacityFlags;
    char pad1[0xcc - 0xbc];
    hkShortArray m_aiIndexedValues;
    void SetShortAtKey(int key, short value);
};

// @fnv 0x00d56070
void FUN_00d56070_class::SetShortAtKey(int key, short sValue)
{
    if (m_aiIndexedValues.m_iElementCount == 0)
    {
        int total = 0;
        for (int i = 0; i < m_iCapacityFlags; i++)
        {
            m_pElements[i].m_offset = total;
            total += m_pElements[i].m_uiItemCount;
        }
        m_aiIndexedValues.reserveExactly(total);
        m_aiIndexedValues.SetSizeAndGrow(total);
    }
    if ((key & 0x80000000) == 0)
    {
        unsigned idx = (unsigned)(key & 0x7fffffff) >> (32 - m_bits);
        int sub = key & (0xffffffffu >> m_bits);
        m_aiIndexedValues.m_data[m_pElements[idx].m_offset + sub] = sValue;
    }
}

struct S_00d56880_Alloc
{
};
struct S_00d56880_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_00d56880_Alloc* m_pStreamAllocator;
    static S_00d56880_Router& FUN_00c85750();
    S_00d56880_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
};
void __cdecl FUN_00c908c0(S_00d56880_Alloc& a, void* arr, int n, int elemSize);

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct S_00d56880_Elem
{
    unsigned char unk0;
    unsigned char unk1;
    short unk2;
    int unk4;
    short unk8;
    short unka;
    int unkc;
    int unk10;
    void* m_data;
    int m_iElementCount;
    int m_cap;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    S_00d56880_Elem()
    {
        unk8 = 0;
        unk2 = 0;
        unka = 1;
        unk0 = 1;
        unk1 = 1;
        unkc = 0;
        unk4 = 0;
        unk10 = 0;
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
    }
};

struct S_00d56880_Array
{
    S_00d56880_Elem* m_data;
    int m_iElementCount;
    int m_cap;
    int getCapacity() const
    {
        return m_cap & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(S_00d56880_Alloc& a, int n)
    {
        if (getCapacity() < n)
        {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(a, this, newSize, sizeof(S_00d56880_Elem));
        }
    }
    __forceinline S_00d56880_Elem* expandBy(int n)
    {
        S_00d56880_Alloc& a = S_00d56880_Router::FUN_00c85750().heap();
        int oldsize = m_iElementCount;
        GrowArrayCapacity(a, oldsize + n);
        S_00d56880_Elem* p = m_data + m_iElementCount;
        for (int i = 0; i < n; i++)
            new (p + i) S_00d56880_Elem();
        m_iElementCount += n;
        return m_data + oldsize;
    }
};

struct S_00d56880
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    S_00d56880_Array m_aiIndexedValues;
    S_00d56880_Elem* AppendElement();
};

// Appends one default-constructed element to the array and returns a pointer to it.
// @fnv 0x00d56880
S_00d56880_Elem* S_00d56880::AppendElement()
{
    return m_aiIndexedValues.expandBy(1);
}

struct FUN_00d55520_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_18;
};

// @fnv 0x00d55520
int __stdcall FUN_00d55520(FUN_00d55520_cls* a1)
{
    return a1->m_18;
}

struct SpawnedOwner
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
    int m_0xdc;

    int FUN_00d55530(int aiIndex);
};

struct FUN_00d555d0_cls
{
    int m_d0;
    int GetSpawnedValue(int aiKey);
};

// Looks up the entry for aiKey via FUN_00d55530 on the owning object and returns its first int, or the owner's m_0xdc when not found.
// @fnv 0x00d555d0
int FUN_00d555d0_cls::GetSpawnedValue(int aiKey)
{
    SpawnedOwner* outer = (SpawnedOwner*)((char*)this - 0x10);
    int* v = (int*)outer->FUN_00d55530(aiKey);
    if (v != 0)
    {
        return *v;
    }
    return outer->m_0xdc;
}

struct Child
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual int v18(int a1, int a2);
};

struct Group
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Child** m_14;
    int m_18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    unsigned int m_3c;
};

struct FUN_00d55a90_cls
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
    Group* m_0c0;
    int m_0c4;

    int __thiscall calcSizeForSpu(int a1, int a2);
};

// @fnv 0x00d55a90
int FUN_00d55a90_cls::calcSizeForSpu(int a1, int a2)
{
    int i = 0;
    if (m_0c4 > 0)
    {
        volatile int off = 0;
        do
        {
            Group* pGroup = m_0c0;
            pGroup = (Group*)((char*)pGroup + off);
            for (int iChildIndex = 0; iChildIndex < pGroup->m_18; ++iChildIndex)
            {
                Child* c = pGroup->m_14[iChildIndex];
                int r = c->v18(a1, 0x100);
                unsigned int uiFlags = pGroup->m_3c & 0xc0ffffffu;
                int limit;
                if (uiFlags == 0)
                    limit = 0x200;
                else if (uiFlags == 1)
                    limit = 0x1d0;
                else
                    limit = 0x1a0;
                if (r < 0 || r > limit)
                    return -1;
            }
            ++i;
            off += 0x40;
        } while (i < m_0c4);
    }
    return 0xf0;
}

struct __declspec(align(16)) S_00d55bd0_Vector4
{
    float x;
    float y;
    float z;
    float w;
};

struct S_00d55bd0_Bool
{
    char m_cBooleanValue;
    S_00d55bd0_Bool(bool b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct S_00d55bd0_Shape
{
    int unk0;
    int unk4;
    int unk8;
    int m_type;
};

struct S_00d55bd0_TriangleShape : S_00d55bd0_Shape
{
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_00d55bd0_Vector4 m_kVertexA;
    S_00d55bd0_Vector4 m_kVertexB;
    S_00d55bd0_Vector4 m_kVertexC;
};

S_00d55bd0_Bool IsDegenerateTriangle(const S_00d55bd0_Vector4& a, const S_00d55bd0_Vector4& b,
                                     const S_00d55bd0_Vector4& c, float tolerance);

struct S_00d55bd0_TrianglesSubpart
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int m_iTriangleCount;
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
};

struct S_00d55bd0_ShapesSubpart
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int m_iChildShapeCount;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
};

static const float DAT_011b2e90 = 1e-07f;

struct S_00d55bd0_MeshShape
{
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void vf10();
    virtual const S_00d55bd0_Shape* GetShapeForKey(unsigned int key, void* buffer) const;
    int unk4;
    int unk8;
    int unkc;
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
    int m_iNumBitsForSubpartIndex;
    S_00d55bd0_TrianglesSubpart* m_kTrianglesSubparts;
    unsigned int m_numTrianglesSubparts;
    int unkac;
    S_00d55bd0_ShapesSubpart* m_kShapesSubparts;
    unsigned int m_numShapesSubparts;

    unsigned int FindNextNonDegenerateShapeKey(unsigned int initialKey) const;
};

// @fnv 0x00d55bd0
unsigned int S_00d55bd0_MeshShape::FindNextNonDegenerateShapeKey(unsigned int initialKey) const
{
    // hkpShapeBuffer (512 bytes, 16-aligned); non-char element type, see brief
    __declspec(align(16)) unsigned int buffer[128];

    unsigned int subpartIndex = (initialKey & 0x7fffffff) >> (32 - m_iNumBitsForSubpartIndex);
    int terminalIndex = initialKey & (~0U >> m_iNumBitsForSubpartIndex);
    unsigned int subpartType = initialKey & 0x80000000;

    while (1)
    {
        if (subpartType == 0)
        {
            if (++terminalIndex >= m_kTrianglesSubparts[subpartIndex].m_iTriangleCount)
            {
                subpartIndex++;
                terminalIndex = 0;
                if (subpartIndex >= m_numTrianglesSubparts)
                {
                    if (m_numShapesSubparts == 0)
                    {
                        return 0xffffffff;
                    }
                    subpartIndex = 0;
                    subpartType = 0x80000000;
                    terminalIndex = -1;
                    continue;
                }
            }
        }
        else
        {
            if (++terminalIndex >= m_kShapesSubparts[subpartIndex].m_iChildShapeCount)
            {
                subpartIndex++;
                if (subpartIndex >= m_numShapesSubparts)
                {
                    return 0xffffffff;
                }
                terminalIndex = 0;
            }
        }

        unsigned int key = (subpartIndex << (32 - m_iNumBitsForSubpartIndex)) | subpartType | terminalIndex;
        const S_00d55bd0_Shape* shape = GetShapeForKey(key, buffer);
        if (shape->m_type == 3)
        {
            const S_00d55bd0_TriangleShape* pTriangle = static_cast<const S_00d55bd0_TriangleShape*>(shape);
            if (IsDegenerateTriangle(pTriangle->m_kVertexA, pTriangle->m_kVertexB, pTriangle->m_kVertexC, DAT_011b2e90))
            {
                continue;
            }
        }
        return key;
    }
}

namespace fnv_00d56160 {
__declspec(align(16)) struct FUN_00d56160_vec
{
    float x;
    float y;
    float z;
    float w;
};

__declspec(align(16)) struct FUN_00d56160_out
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FUN_00d56160_vec m_20;
    FUN_00d56160_vec m_30;
    FUN_00d56160_vec m_40;
};

struct FUN_00d56160_big
{
    FUN_00d56160_out m_out;
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
};

struct FUN_00d56160_items
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_uiItemCount;
};

struct FUN_00d56160_sub
{
    FUN_00d56160_out* FUN_00d55ce0(unsigned int value, FUN_00d56160_out* out);
};

extern float DAT_011b2e90;
unsigned char* __cdecl IsDegenerateTriangle(unsigned char* out, FUN_00d56160_vec* a, FUN_00d56160_vec* b,
                                            FUN_00d56160_vec* c, float r);

struct FUN_00d56160_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d56160_sub m_sub;
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
    int m_b0;

    int Vec4(FUN_00d56160_items* items, unsigned int value);
};

// 16-byte aligned four-float vector structure with x, y, z and w components.
// @fnv 0x00d56160
int FUN_00d56160_cls::Vec4(FUN_00d56160_items* items, unsigned int value)
{
    int count = 0;

    for (int i = 0; i < items->m_uiItemCount; ++i)
    {
        FUN_00d56160_big tmp;
        unsigned char hit;
        FUN_00d56160_out* r = m_sub.FUN_00d55ce0((value << (32 - m_b0)) | i, &tmp.m_out);
        if (*IsDegenerateTriangle(&hit, &r->m_20, &r->m_30, &r->m_40, DAT_011b2e90) == 0)
        {
            ++count;
        }
    }
    return count;
}
}  // namespace fnv_00d56160

struct hkReferencedObject
{
    void removeReference();
};
struct BufferAllocator
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Release(void* data, unsigned bytes);
};
struct BSAudio
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    BufferAllocator* allocator;
};
BSAudio* FUN_00c85750();
struct Container
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    hkReferencedObject** data;
    int count;
    unsigned capacityFlags;
    void FUN_00d56800();
};
// @fnv 0x00d56800
void Container::FUN_00d56800()
{
    BufferAllocator* allocator = FUN_00c85750()->allocator;
    int savedCount = count;
    hkReferencedObject** savedData = data;
    for (int i = 0; i < savedCount; ++i)
    {
        if (savedData[i])
            savedData[i]->removeReference();
        savedData[i] = 0;
    }
    count = 0;
    if (!(capacityFlags & 0x80000000u))
        allocator->Release(data, (capacityFlags & 0x3fffffffu) * 4u);
    capacityFlags = 0x80000000u;
    data = 0;
}

namespace fnv_00d56e00 {
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct BSAudio
{
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

BSAudio* FUN_00c85750();

extern "C" char DAT_010d0ecc[];
extern "C" char DAT_010d0ea8[];
extern "C" char DAT_010c6fb0[];
extern "C" char DAT_0102e388[];

struct Elem40
{
    int v00, v04, v08, v0c, v10, v14, v18, v1c;
    int v20, v24, v28, v2c, v30, v34, v38, v3c;
    void FUN_00d56800();
};

struct Elem60
{
    int v00, v04, v08, v0c, v10, v14, v18, v1c;
    int v20, v24, v28, v2c, v30, v34, v38, v3c;
    int v40, v44, v48, v4c, v50, v54, v58, v5c;
};

template <class T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void ClearAndRelease()
    {
        hkMemoryAllocator& alloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void destroyAndDeallocate()
    {
        hkMemoryAllocator& alloc = FUN_00c85750()->heap();
        int n = m_iElementCount;
        T* p = m_data;
        for (int i = 0; i < n; i++)
        {
            p[i].FUN_00d56800();
        }
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct Obj
{
    void* m_vtbl;
    int unk04, unk08, unk0c;
    void* m_vtbl10;
    int unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0;
    hkArray<Elem60> mb4;
    hkArray<Elem40> mc0;
    hkArray<short> mcc;
    void FUN_00d56e00();
};

// Resets the object's two vtables and clears the mcc, mc0 and mb4 arrays, destroying mc0's elements and freeing their storage.
// @fnv 0x00d56e00
void Obj::FUN_00d56e00()
{
    m_vtbl = DAT_010d0ecc;
    m_vtbl10 = DAT_010d0ea8;
    mcc.ClearAndRelease();
    mc0.destroyAndDeallocate();
    mb4.ClearAndRelease();
    m_vtbl10 = DAT_010c6fb0;
    m_vtbl = DAT_0102e388;
}
}  // namespace fnv_00d56e00

struct FUN_00d55b40_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float unk20[4];
    float unk30[4];
    float unk40[4];
};

struct __declspec(align(16)) FUN_00d55b40_Buffer
{
    int v[128];
};

extern char* __cdecl IsDegenerateTriangle(char* result, const void* v0, const void* v1, const void* v2, float tol);

struct bhkShapeOwner
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual int v3(int);
    virtual void* v4();
    virtual void* v5(int, void*);
    struct
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
    } unk04;
    int unk_a8;
    int unk_ac;
    int unk_b0;
    int unk_b4;
    int GetShapeKey();
};

// @fnv 0x00d55b40
int bhkShapeOwner::GetShapeKey()
{
    FUN_00d55b40_Shape* shape;
    FUN_00d55b40_Buffer buffer;
    char degenerate;
    unsigned int key;

    if (this->unk_a8 + this->unk_b4 == 0)
        return -1;

    key = (this->unk_a8 != 0) ? 0u : 0x80000000u;

    shape = (FUN_00d55b40_Shape*)this->v5((int)key, &buffer);

    if (shape->unk0c != 3)
        return (int)key;

    char* result = IsDegenerateTriangle(&degenerate, &shape->unk20[0], &shape->unk30[0], &shape->unk40[0], 1.0e-7f);

    if (*result == 0)
        return (int)key;

    return this->v3((int)key);
}

// @fnv 0x00d554e0
void __stdcall FUN_00d554e0(int a)
{}

// @fnv 0x00d554f0
void __stdcall FUN_00d554f0(int a0)
{}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

struct hkVector4D562
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

struct ElemD562
{
    unsigned char m_b0;
    unsigned char m_b1;
    short m_s2;
    int m_i4;
    short m_s8;
    short m_sA;
    int m_iC;
    int m_i10;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    hkVector4D562 m_kVec;
    int unk40, unk44;
    unsigned char unk48;
    unsigned char m_b49;
    short unk4A;
    int unk4C;
    int m_i50;
    int unk54, unk58, unk5C;

    ElemD562()
    {
        m_s8 = 0;
        m_s2 = 0;
        m_b0 = 0;
        m_b1 = 1;
        m_sA = 1;
        m_iC = 0;
        m_i4 = 0;
        m_i10 = 0;
        m_b49 = 0;
        m_kVec.setZero4();
        m_i50 = 0;
    }
};

struct ArrayD562
{
    ElemD562* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocator& alloc, int n)
    {
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(ElemD562));
        }
    }
    __forceinline ElemD562& AllocatePair()
    {
        hkMemoryAllocator& alloc = audio()->heap();
        int oldSize = m_iElementCount;
        reserve(alloc, oldSize + 1);
        new (m_data + m_iElementCount) ElemD562();
        m_iElementCount += 1;
        return m_data[oldSize];
    }
};

struct OwnerD562
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    ElemD562 m_kInline;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    int unkB0;
    ArrayD562 m_kArray;

    ElemD562* FUN_00d562f0();
};

// Returns a pointer to a new ElemD562, using the inline element when the array is empty, otherwise calling AllocatePair on m_kArray.
// @fnv 0x00d562f0
ElemD562* OwnerD562::FUN_00d562f0()
{
    if (m_kArray.m_iElementCount == 0)
    {
        m_kArray.m_data = &m_kInline;
        m_kArray.m_iElementCount = 1;
        m_kArray.m_iCapacityState = 0x80000001;
        return &m_kInline;
    }
    return &m_kArray.AllocatePair();
}

namespace fnv_00d569c0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_set_ps1(float fA);
extern "C" __m128 _mm_setzero_ps();

struct hkVector4D569
{
    __m128 m_vComponents;

    hkVector4D569()
    {}
    hkVector4D569(const hkVector4D569& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4D569& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void SetAllComponents(float fA)
    {
        m_vComponents = _mm_set_ps1(fA);
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

template <class T> struct hkArrayD569
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD569() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkBaseObjectD569
{
  public:
    virtual ~hkBaseObjectD569() throw();
};

class hkReferencedObjectD569 : public hkBaseObjectD569
{
  public:
    virtual ~hkReferencedObjectD569() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShapeD569 : public hkReferencedObjectD569
{
  public:
    virtual ~hkpShapeD569() throw();

    unsigned long m_ulUserData;
    unsigned int m_type;
};

class hkpShapeContainerD569
{
  public:
    virtual ~hkpShapeContainerD569() throw();
};

class FUN_00d21410 : public hkpShapeD569, public hkpShapeContainerD569
{
  public:
    FUN_00d21410(unsigned int uiType, unsigned char ucCollectionType) throw();
    virtual ~FUN_00d21410() throw();

    char m_bDisableWelding;
    unsigned char m_eCollectionType;
};

struct hkpExtendedMeshShapeTrianglesSubpartD569
{
    hkpExtendedMeshShapeTrianglesSubpartD569()
    {
        m_type = 0;
        m_materialIndexStridingPad = 0;
        m_pVertexBase = 0;
        m_pIndexBase = 0;
        m_bFlipAlternateTriangles = 0;
        m_iTriangleOffset = 0;
        m_iMaterialIndexType = 1;
        m_iVertexStriding = 0;
        m_iIndexStriding = 0;
        m_iNumTriangles = 1;
        m_kVertexTransform.setZero4();
    }

    unsigned char m_type;
    unsigned char m_iMaterialIndexType;
    unsigned short m_iIndexStriding;
    const void* m_pVertexBase;
    unsigned short m_iVertexStriding;
    unsigned short m_iNumTriangles;
    const void* m_materialIndexStridingPad;
    const void* m_pIndexBase;
    unsigned int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    hkVector4D569 m_kVertexTransform;
    unsigned int unk60, unk64;
    unsigned char unk68;
    unsigned char m_bFlipAlternateTriangles;
    unsigned short unk6A;
    unsigned int unk6C;
    int m_iTriangleOffset;
    unsigned int unk74, unk78, unk7C;
};

class FUN_00d569c0 : public FUN_00d21410
{
  public:
    FUN_00d569c0(float fRadius, int iNumBitsForSubpartIndex) throw();
    virtual ~FUN_00d569c0() throw();

    unsigned int unk18, unk1C;
    hkpExtendedMeshShapeTrianglesSubpartD569 m_kTrianglesSubpart;
    hkVector4D569 m_kScaling;
    hkVector4D569 m_kAabbHalfExtents;
    hkVector4D569 m_kAabbCenter;
    int m_iNumBitsForSubpartIndex;
    hkArrayD569<void*> m_kTrianglesSubparts;
    hkArrayD569<void*> m_kShapesSubparts;
    hkArrayD569<unsigned short> m_kWeldingInfo;
    unsigned char m_eWeldingType;
    unsigned int m_uiShapeFlags;
    int m_iFinishingFlag;
    float m_fTriangleRadius;
};

static const float DAT_0104e148 = -3.40282e+38f;

// Initializes an extended mesh shape with the given triangle radius and subpart index bits, setting default scaling, AABB, and welding type.
// @fnv 0x00d569c0
FUN_00d569c0::FUN_00d569c0(float afTriangleRadius, int iNumBitsForSubpartIndex) throw() : FUN_00d21410(0xe, 1)
{
    m_fTriangleRadius = afTriangleRadius;
    m_kScaling.SetAllComponents(1.0f);
    m_uiShapeFlags = 0;
    m_iFinishingFlag = 0;
    m_iNumBitsForSubpartIndex = iNumBitsForSubpartIndex;
    m_eWeldingType = 6;
    m_kAabbHalfExtents.SetAllComponents(DAT_0104e148);
    m_kAabbCenter.setZero4();
}
}  // namespace fnv_00d569c0

struct FUN_00d554c0_Class
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
    __m128 unk80;
    void FUN_00d554c0(const __m128* value);
};

// @fnv 0x00d554c0
void FUN_00d554c0_Class::FUN_00d554c0(const __m128* value)
{
    unk80 = *value;
}

extern "C" void _ReadWriteBarrier(void);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);

extern float DAT_0104da48;
extern __m128 DAT_010c44d0;

struct hkVec4
{
    __m128 m_vComponents;
    void setMin4(const hkVec4& a, const hkVec4& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    void setMax4(const hkVec4& a, const hkVec4& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
};
struct hkAabbS
{
    hkVec4 m_kMinimumCorner;
    hkVec4 m_kMaximumCorner;
};
struct hkQuatS
{
    hkVec4 m_vec;
};
struct hkTransformS
{
    hkVec4 m_kColumn0;
    hkVec4 m_kColumn1;
    hkVec4 m_kColumn2;
    hkVec4 m_vTranslation;
    void FUN_00cb2d90(const hkQuatS& q);
};
struct hkShapeS
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const hkTransformS& t, float tolerance, hkAabbS& out) const;
};
struct ShapeHolderS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkShapeS** m_shapes;
    int m_numShapes;
    int unk1C;
    hkQuatS m_rotation;
    hkVec4 m_vTranslation;
};

// Computes the combined axis-aligned bounding box of all shapes in src by transforming each shape's AABB and merging the min/max corners.
// @fnv 0x00d558b0
static __declspec(noinline) void FUN_00d558b0(const ShapeHolderS* apShapeHolder, hkAabbS* out)
{
    __m128 v = _mm_load_ss(&DAT_0104da48);
    out->m_kMinimumCorner.m_vComponents = _mm_shuffle_ps(v, v, 0);
    out->m_kMaximumCorner.m_vComponents = _mm_xor_ps(out->m_kMinimumCorner.m_vComponents, DAT_010c44d0);
    hkTransformS t;
    t.m_vTranslation = apShapeHolder->m_vTranslation;
    t.FUN_00cb2d90(apShapeHolder->m_rotation);
    for (int i = 0; i < apShapeHolder->m_numShapes; i++)
    {
        hkAabbS a;
        apShapeHolder->m_shapes[i]->getAabb(t, 0.0f, a);
        __m128 omin = out->m_kMinimumCorner.m_vComponents;
        _ReadWriteBarrier();
        __m128 mn = _mm_min_ps(omin, a.m_kMinimumCorner.m_vComponents);
        __m128 omax = out->m_kMaximumCorner.m_vComponents;
        _ReadWriteBarrier();
        out->m_kMinimumCorner.m_vComponents = mn;
        out->m_kMaximumCorner.m_vComponents = _mm_max_ps(omax, a.m_kMaximumCorner.m_vComponents);
    }
}

ShapeHolderS* volatile g_src;
hkAabbS* volatile g_out;
extern void SomeOtherCall_d558(hkAabbS*);

void CallTarget_d558b0()
{
    ShapeHolderS* s = g_src;
    hkAabbS* o = g_out;
    FUN_00d558b0(s, o);
    SomeOtherCall_d558(o);
}

// @fnv 0x00d55500
void FUN_00d55500()
{}

extern "C"
{
    __m128 _mm_set_ps1(float a);
    __m128 _mm_setr_ps(float a, float b, float c, float d);
    __m128 _mm_xor_ps(__m128 a, __m128 b);
    __m128 _mm_min_ps(__m128 a, __m128 b);
    __m128 _mm_max_ps(__m128 a, __m128 b);
}

typedef float hkReal;

extern __m128 DAT_010c44d0;

struct hkTransformq;
extern hkTransformq DAT_01268370;

struct __declspec(align(16)) hkVector4q
{
    __m128 m_vComponents;

    hkVector4q()
    {}
    hkVector4q(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w = 0.0f)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void SetAllComponents(hkReal r)
    {
        m_vComponents = _mm_set_ps1(r);
    }
    __forceinline void setMin4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMax4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }
    void FUN_00c7f640(const hkTransformq& t, const hkVector4q& v);
};

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

struct TrianglesSubpart
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_iTriangleCount;
    const char* m_pMaterialIndexBase;
    int m_iTriangleIndexStride;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    const char* m_pMaterialDataBase;
    int m_iMaterialStriding;
    signed char m_ucIndexStridingType;
};

// Computes the axis-aligned bounding box of all triangle vertices in a subpart, applying scale and a fixed transform, and stores the result in aabb.
// @fnv 0x00d55680
void __cdecl FUN_00d55680(const TrianglesSubpart& part, const hkVector4q& scale, hkAabbq& aabb)
{
    aabb.m_kMinimumCorner.SetAllComponents(3.40282e+38f);
    aabb.m_kMaximumCorner.m_vComponents = _mm_xor_ps(aabb.m_kMinimumCorner.m_vComponents, DAT_010c44d0);
    for (int i = 0; i < part.m_iTriangleCount; i++)
    {
        const hkReal* v0;
        const hkReal* v1;
        const hkReal* v2;
        switch (part.m_ucIndexStridingType)
        {
        case 1: {
            const unsigned char* t = (const unsigned char*)(part.m_pMaterialDataBase + i * part.m_iMaterialStriding);
            v0 = (const hkReal*)(part.m_pMaterialIndexBase + t[0] * part.m_iTriangleIndexStride);
            v1 = (const hkReal*)(part.m_pMaterialIndexBase + t[1] * part.m_iTriangleIndexStride);
            v2 = (const hkReal*)(part.m_pMaterialIndexBase + t[2] * part.m_iTriangleIndexStride);
            break;
        }
        case 2: {
            const unsigned short* t = (const unsigned short*)(part.m_pMaterialDataBase + i * part.m_iMaterialStriding);
            v0 = (const hkReal*)(part.m_pMaterialIndexBase + t[0] * part.m_iTriangleIndexStride);
            v1 = (const hkReal*)(part.m_pMaterialIndexBase + t[1] * part.m_iTriangleIndexStride);
            v2 = (const hkReal*)(part.m_pMaterialIndexBase + t[2] * part.m_iTriangleIndexStride);
            break;
        }
        default: {
            const unsigned int* t = (const unsigned int*)(part.m_pMaterialDataBase + i * part.m_iMaterialStriding);
            v0 = (const hkReal*)(part.m_pMaterialIndexBase + t[0] * part.m_iTriangleIndexStride);
            v1 = (const hkReal*)(part.m_pMaterialIndexBase + t[1] * part.m_iTriangleIndexStride);
            v2 = (const hkReal*)(part.m_pMaterialIndexBase + t[2] * part.m_iTriangleIndexStride);
            break;
        }
        }
        {
            hkVector4q vertex;
            vertex.set(v0[0] * scale(0), v0[1] * scale(1), v0[2] * scale(2));
            hkVector4q transformed;
            transformed.FUN_00c7f640(DAT_01268370, vertex);
            aabb.m_kMinimumCorner.setMin4(aabb.m_kMinimumCorner, transformed);
            aabb.m_kMaximumCorner.setMax4(aabb.m_kMaximumCorner, transformed);
        }
        {
            hkVector4q vertex;
            vertex.set(*(const volatile float*)&v1[0] * scale(0), v1[1] * scale(1), v1[2] * scale(2));
            hkVector4q transformed;
            transformed.FUN_00c7f640(DAT_01268370, vertex);
            aabb.m_kMinimumCorner.setMin4(aabb.m_kMinimumCorner, transformed);
            aabb.m_kMaximumCorner.setMax4(aabb.m_kMaximumCorner, transformed);
        }
        {
            hkVector4q vertex;
            vertex.set(v2[0] * scale(0), v2[1] * scale(1), v2[2] * scale(2));
            hkVector4q transformed;
            transformed.FUN_00c7f640(DAT_01268370, vertex);
            aabb.m_kMinimumCorner.setMin4(aabb.m_kMinimumCorner, transformed);
            aabb.m_kMaximumCorner.setMax4(aabb.m_kMaximumCorner, transformed);
        }
    }
}

struct VertexScratch
{
    __m128 q;
    __forceinline float& at(int i)
    {
        return ((float*)&q)[i];
    }
    __forceinline void load(const float* p)
    {
        at(0) = p[0];
        at(1) = p[1];
        at(2) = p[2];
    }
};
extern "C" void _ReadWriteBarrier(void);
extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_and_ps(__m128, __m128);
    void _mm_store_ss(float*, __m128);
}

extern int DAT_010c749c;
extern int DAT_010d0e5c;
extern __m128 DAT_010c4c10;
extern float DAT_011b153c;

void __cdecl CopySixteenByteBlocks(void* dst, const void* src);
void __cdecl FUN_00d570d0(void* dst, const void* src);

struct HelperC9E340
{
    void FUN_00c9e340(int type, float radius, const S_00d55bd0_Shape* child, int unk);
};
struct HelperCB2D90
{
    void FUN_00cb2d90(const void* rotation);
};
struct HelperD5D7A0
{
    const S_00d55bd0_Shape* FUN_00d5d7a0(const S_00d55bd0_Shape* child, const void* transform, int unk);
};

struct MeshSubpartTriangle
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_iTriangleCount;
    const void* m_pMaterialIndexBase;  // 0x18
    int m_iTriangleIndexStride;        // 0x1c
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S_00d55bd0_Vector4 m_kVertexTransform;  // 0x30
    const void* m_pMaterialDataBase;        // 0x40
    int m_iMaterialStriding;                // 0x44
    char m_ucIndexStridingType;             // 0x48
    char m_bFlipAlternateTriangles;         // 0x49
    short unk4A;                            // 0x4a
    int m_weldingInfoOffset;                // 0x4c
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
};

struct MeshSubpartShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    const S_00d55bd0_Shape** m_kChildShapes;  // 0x14
    int m_iChildShapeCount;                   // 0x18
    int unk1C;
    int m_rotation[4];  // 0x20
    union
    {
        S_00d55bd0_Vector4 m_vTranslation;
        struct
        {
            float tx, ty, tz;
            int m_type;
        };
    };
};

struct Transform
{
    S_00d55bd0_Vector4 m_rotation[3];
    S_00d55bd0_Vector4 m_vTranslation;
};

struct TriangleShape
{
    int vtable;                             // 0x00
    short unk04;                            // 0x04
    short m_iObjectReferenceCount;          // 0x06
    int m_ulUserData;                       // 0x08
    int m_type;                             // 0x0c
    float m_fSphereRadius;                  // 0x10
    short m_kWeldingInfo;                   // 0x14
    char m_eWeldingType;                    // 0x16
    char m_ucWeldingPadding;                // 0x17
    int unk18;                              // 0x18
    int unk1c;                              // 0x1c
    S_00d55bd0_Vector4 m_kVertexA;          // 0x20
    S_00d55bd0_Vector4 m_kVertexB;          // 0x30
    S_00d55bd0_Vector4 m_kVertexC;          // 0x40
    S_00d55bd0_Vector4 m_kVertexTransform;  // 0x50

    __forceinline void setVertices(const __m128* vertices)
    {
        *(__m128*)&m_kVertexA = vertices[0];
        *(__m128*)&m_kVertexB = vertices[1];
        *(__m128*)&m_kVertexC = vertices[2];
    }

    __forceinline TriangleShape(float radius)
    {
        m_iObjectReferenceCount = 1;
        m_fSphereRadius = radius;
        m_ulUserData = 0;
        m_type = 3;
        vtable = (int)&DAT_010c749c;
        m_kWeldingInfo = 0;
        m_eWeldingType = 6;
        *(__m128*)&m_kVertexTransform = _mm_setzero_ps();
        m_ucWeldingPadding = 0;
    }
};

static __forceinline void getIndices(const MeshSubpartTriangle& r, unsigned int terminalIndex, int* indices)
{
    const char* ext = (const char*)r.m_pMaterialDataBase + terminalIndex * r.m_iMaterialStriding;
    long flip = r.m_bFlipAlternateTriangles & terminalIndex;

    switch (r.m_ucIndexStridingType)
    {
    case 1: {
        const unsigned char* transformType;
        transformType = (const unsigned char*)ext;
        indices[0] = transformType[0];
        unsigned short p = flip + 1;
        short off2 = (flip ^ 1) + 1;
        indices[1] = transformType[(short)p];
        indices[2] = transformType[(int)off2];
        break;
    }
    case 2: {
        const unsigned short* transformType = (const unsigned short*)ext;
        indices[0] = transformType[0];
        short p = 1 + flip;
        short off2 = (flip ^ 1) + 1;
        indices[1] = transformType[(short)p];
        indices[2] = transformType[(int)off2];
        break;
    }
    case 3: {
        const unsigned int* transformType = (const unsigned int*)ext;
        indices[0] = transformType[0];
        int p = flip + 1;
        short off2 = (flip ^ 1) + 1;
        indices[1] = transformType[(short)p];
        indices[2] = transformType[(int)off2];
        break;
    }
    default:
        indices[0] = 0;
        indices[1] = 0;
        indices[2] = 0;
        break;
    }
}

struct ExtendedMeshShape : S_00d55bd0_MeshShape
{
    int unkb8;
    const unsigned short* m_weldingInfoData;  // 0xbc
    int m_weldingInfoSize;                    // 0xc0
    int unkc4;                                // 0xc4
    char m_eWeldingType;                      // 0xc8
    char unkc9;
    short unkca;
    int unkcc;
    int unkd0;
    float m_fTriangleRadius;  // 0xd4
    int unkd8;

    const S_00d55bd0_Shape* FUN_00d55ce0(unsigned int key, void* buffer) const;
};

// Resolves a subpart key to a TriangleShape or child shape, applying scale, welding info, and optional transform into the caller buffer.
// @fnv 0x00d55ce0
const S_00d55bd0_Shape* ExtendedMeshShape::FUN_00d55ce0(unsigned int key, void* buffer) const
{
    __declspec(align(16)) unsigned int subpartStorage[45];
    unsigned int numBits = m_iNumBitsForSubpartIndex;
    unsigned int uiSubpartIndex = (key & 0x7fffffff) >> (32 - numBits);
    unsigned int terminalIndex = key & (~0u >> numBits);

    if (!(key & 0x80000000))
    {
        void* subpartBuffer = (void*)(((unsigned int)subpartStorage + 0x5f) & ~0x5f);
        const MeshSubpartTriangle* r;
        if (m_numTrianglesSubparts == 1)
        {
            r = (const MeshSubpartTriangle*)&unk10;
        }
        else
        {
            CopySixteenByteBlocks(subpartBuffer, (const char*)m_kTrianglesSubparts + uiSubpartIndex * 96);
            r = (const MeshSubpartTriangle*)subpartBuffer;
        }

        union
        {
            int indices[3];
            S_00d55bd0_Vector4 scale;
        } scratch;
        getIndices(*r, terminalIndex, scratch.indices);
        const void* n = r->m_pMaterialIndexBase;
        long iIndexStride = r->m_iTriangleIndexStride;

        TriangleShape* __restrict triangle = new (buffer) TriangleShape(DAT_011b153c);
        triangle->m_eWeldingType = m_eWeldingType;
        triangle->m_fSphereRadius = m_fTriangleRadius;

        __m128 indexBase = *(__m128*)&r->m_kVertexTransform;
        __m128 vSquared = _mm_mul_ps(indexBase, indexBase);
        __m128 vShuffled = _mm_shuffle_ps(vSquared, vSquared, 0x55);
        __m128 c = _mm_add_ss(vShuffled, vSquared);
        __m128 vertexStriding = _mm_shuffle_ps(vSquared, vSquared, 0xaa);
        __m128 subpartIndex = _mm_add_ss(vertexStriding, c);
        float fLengthSq;
        _mm_store_ss(&fLengthSq, subpartIndex);

        triangle->m_type = 3;
        triangle->m_ucWeldingPadding = (fLengthSq > 0.0f);
        *(__m128*)&triangle->m_kVertexTransform = indexBase;

        unsigned short weldingInfo;
        if (m_weldingInfoSize == 0)
            weldingInfo = 0;
        else
            weldingInfo = m_weldingInfoData[r->m_weldingInfoOffset + terminalIndex];

        triangle->m_kWeldingInfo = weldingInfo;

        const float* pVertexA = (const float*)((const char*)n + scratch.indices[0] * iIndexStride);
        const float* pVertexB = (const float*)((const char*)n + scratch.indices[1] * iIndexStride);
        const float* pVertexC = (const float*)((const char*)n + scratch.indices[2] * iIndexStride);

        scratch.scale = *(const S_00d55bd0_Vector4*)&unk70;

        VertexScratch v;
        __m128 vertices[3];
        v.at(0) = pVertexA[0];
        v.at(1) = pVertexA[1];
        v.at(2) = pVertexA[2];
        vertices[0] = _mm_mul_ps(*(__m128*)&v, *(__m128*)&scratch.scale);

        v.at(0) = pVertexB[0];
        v.at(1) = pVertexB[1];
        v.at(2) = pVertexB[2];
        vertices[1] = _mm_mul_ps(*(__m128*)&v, *(__m128*)&scratch.scale);

        v.at(0) = pVertexC[0];
        v.at(1) = pVertexC[1];
        v.at(2) = pVertexC[2];
        vertices[2] = _mm_mul_ps(*(__m128*)&v, *(__m128*)&scratch.scale);
        triangle->setVertices(vertices);

        return (const S_00d55bd0_Shape*)triangle;
    }
    else
    {
        void* subpartBuffer = (void*)(((unsigned int)subpartStorage + 0x3f) & ~0x3f);
        FUN_00d570d0(subpartBuffer, (const char*)m_kShapesSubparts + (uiSubpartIndex << 6));
        const MeshSubpartShape* pSubpartShape = (const MeshSubpartShape*)subpartBuffer;

        int mvA = pSubpartShape->m_type & 0xc0ffffff;
        const S_00d55bd0_Shape* childShape = pSubpartShape->m_kChildShapes[terminalIndex];
        if (!mvA)
        {
            return childShape;
        }
        if (mvA == 1)
        {
            if (buffer)
            {
                float radius = ((const TriangleShape*)childShape)->m_fSphereRadius;
                ((HelperC9E340*)buffer)->FUN_00c9e340(0xb, radius, childShape, 0);
                ((TriangleShape*)buffer)->vtable = (int)&DAT_010d0e5c;
                __m128 scale = _mm_and_ps(*(__m128*)&pSubpartShape->m_vTranslation, DAT_010c4c10);
                *(__m128*)&((TriangleShape*)buffer)->m_kVertexA = scale;
                ((TriangleShape*)buffer)->unk1c = 0;
                return (const S_00d55bd0_Shape*)buffer;
            }
        }
        else
        {
            Transform transform;
            transform.m_vTranslation = pSubpartShape->m_vTranslation;
            ((HelperCB2D90*)&transform)->FUN_00cb2d90(&pSubpartShape->m_rotation);

            if (buffer)
            {
                return ((HelperD5D7A0*)buffer)->FUN_00d5d7a0(childShape, &transform, 0);
            }
        }
        return 0;
    }
}

extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern __m128 DAT_010c71d0;
struct MeshEntry
{
    void FUN_00d4ad60(int);
};
struct MeshOwner
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
    __m128 m_vHalfExtents;
    __m128 m_kCenterPosition;
    int unkB0, unkB4, unkB8, unkBC;
    ShapeHolderS* m_shapes;
    int m_uiItemCount;
    int unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int m_children;
    S_00d56880_Elem* AppendElement();
    int FUN_00d55520(int);
    int addShapesSubpart(volatile int);
};
// Appends a shape element, expands the owner AABB to include it, and returns the new element index.
// @fnv 0x00d56900
int MeshOwner::addShapesSubpart(volatile int key)
{
    S_00d56880_Elem* elem = AppendElement();
    ((MeshEntry*)elem)->FUN_00d4ad60(key);
    hkAabbS bounds;
    __m128 lo = _mm_sub_ps(m_kCenterPosition, m_vHalfExtents);
    __m128 hi = _mm_add_ps(m_vHalfExtents, m_kCenterPosition);
    FUN_00d558b0((ShapeHolderS*)elem, &bounds);
    __m128 mn = _mm_min_ps(lo, bounds.m_kMinimumCorner.m_vComponents);
    __m128 mx = _mm_max_ps(hi, bounds.m_kMaximumCorner.m_vComponents);
    _mm_store_ps((float*)&m_kCenterPosition, _mm_mul_ps(_mm_add_ps(mx, mn), DAT_010c71d0));
    m_vHalfExtents = _mm_mul_ps(_mm_sub_ps(mx, mn), DAT_010c71d0);
    m_children += FUN_00d55520(key);
    return m_uiItemCount - 1;
}

namespace fnv_00d56200 {
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_10;
};

struct SubBuf
{
    void* m_00;
    int m_04;
    int m_08;
};

AudioHolder* __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(void* a, void* b, int c, int d);

struct Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* p, int n);
};

struct FUN_00d56200_cls
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
    char* m_b4;
    int m_b8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    SubBuf m_cc;
    unsigned char m_d8;
    void initWeldingInfo(int a1);
};

// Stores a1 in m_d8; if a1 is 6 frees and resets m_cc, else writes running totals into the 0x60-byte records of m_b4 and grows m_cc to the total.
// @fnv 0x00d56200
void FUN_00d56200_cls::initWeldingInfo(int a1)
{
    m_d8 = (unsigned char)a1;
    if (a1 != 6)
    {
        int total = 0;
        int i = 0;
        if (m_b8 > total)
        {
            char* base = m_b4;
            int off = 0;
            do
            {
                *(int*)(base + off + 0x4c) = total;
                base = m_b4;
                total += *(int*)(base + off + 0x14);
                off += 0x60;
                ++i;
            } while (i < m_b8);
        }
        SubBuf* sub = &m_cc;
        AudioHolder* pHolder = FUN_00c85750();
        if ((sub->m_08 & 0x3fffffff) < total)
            FUN_00c908c0(pHolder->m_10, sub, total, 2);
        AudioHolder* pHolder2 = FUN_00c85750();
        void* alloc2 = pHolder2->m_10;
        int size = sub->m_08 & 0x3fffffff;
        if (size < total)
        {
            int cap = size * 2;
            if (total >= cap)
                cap = total;
            FUN_00c908c0(alloc2, sub, cap, 2);
        }
        sub->m_04 = total;
        return;
    }
    AudioHolder* pHolder = FUN_00c85750();
    Allocator* alloc = (Allocator*)pHolder->m_10;
    int size = m_cc.m_08;
    int zero = 0;
    m_cc.m_04 = zero;
    if ((m_cc.m_08 & 0x80000000u) == 0)
    {
        alloc->v10(m_cc.m_00, (size & 0x3fffffff) * 2);
    }
    m_cc.m_00 = 0;
    m_cc.m_08 = (int)0x80000000;
    return;
}

// initWeldingInfo wrapper for the pack
}  // namespace fnv_00d56200

struct ChanEntry
{
    unsigned char unk00;
    unsigned char type;
    short scale;
    unsigned char* data;
    unsigned short stride;
    short unk0A;
    unsigned char* base;
    unsigned char* get(unsigned int off)
    {
        unsigned char* pData = data;
        unsigned char* pBase = base;
        int iScale = scale;
        if (pData)
        {
            unsigned char* p = pData + stride * off;
            if (type == 1)
                return pBase + *p * iScale;
            return pBase + *(unsigned short*)p * iScale;
        }
        return 0;
    }
};
struct ChanGroup
{
    ChanEntry ch;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
};
struct ChanGroupNeg
{
    ChanEntry ch;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
};
struct SpawnedOwnerQ
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    ChanEntry inlineCh;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    unsigned int bits;
    ChanGroup* groups;
    unsigned int numGroups;
    int unkBC;
    ChanGroupNeg* negGroups;
    int FUN_00d55530(int aiIndex);
};
// Splits aiIndex into a group number and offset, picks an entry from groups, negGroups (high bit set) or the inline entry, and returns its get(offset) or 0.
// @fnv 0x00d55530
int SpawnedOwnerQ::FUN_00d55530(int aiIndex)
{
    unsigned int m_iGridX = ((unsigned int)aiIndex & 0x7fffffff) >> (32 - bits);
    unsigned int iOffset = (0xffffffffu >> bits) & aiIndex;
    ChanEntry* pEntry;
    ChanEntry* pArr;
    if (((unsigned int)aiIndex & 0x80000000u) == 0)
    {
        if (numGroups == 1)
        {
            pEntry = &inlineCh;
            goto have;
        }
        if (m_iGridX >= numGroups)
            return 0;
        pArr = &groups[m_iGridX].ch;
    }
    else
        pArr = &negGroups[m_iGridX].ch;
    pEntry = pArr;
have:
    return (int)pEntry->get(iOffset);
}

extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);

extern float DAT_01011d78;

struct __declspec(align(16)) Vec4Q
{
    float x, y, z, w;
    void __thiscall FUN_00c7f640(const void* transform, const Vec4Q* point);
};

struct AabbQ
{
    Vec4Q m_kMinimumCorner;
    Vec4Q m_kMaximumCorner;
};

struct Vec3
{
    float x, y, z;
};

// Scales a Vec3 point, transforms it via a matrix, and expands the AabbQ min/max corners to include the result.
// @fnv 0x00d55600
static __declspec(noinline) void __cdecl FUN_00d55600(const Vec3* apPoint, const Vec3* scale, const void* transform,
                                                      AabbQ* aabb)
{
    float x = apPoint->x * scale->x;
    float y = apPoint->y * scale->y;
    float z = apPoint->z * scale->z;
    Vec4Q p;
    *(__m128*)&p = _mm_setr_ps(x, y, z, DAT_01011d78);
    Vec4Q out;
    out.FUN_00c7f640(transform, &p);
    __m128 o = *(__m128*)&out;
    *(__m128*)&aabb->m_kMinimumCorner = _mm_min_ps(*(__m128*)&aabb->m_kMinimumCorner, o);
    *(__m128*)&aabb->m_kMaximumCorner = _mm_max_ps(*(__m128*)&aabb->m_kMaximumCorner, o);
}

void keep_alive_b11424(const Vec3* self, const Vec3* scale, const void* transform, AabbQ* aabb)
{
    FUN_00d55600(self, scale, transform, aabb);
}

extern "C" __m128 _mm_load_ps1(const float* p);
extern "C" __m128 _mm_min_ps(__m128, __m128);
struct hkVector4D563
{

    __m128 m_vComponents;

    hkVector4D563()
    {}

    hkVector4D563(const hkVector4D563& v)
    {
        m_vComponents = v.m_vComponents;
    }

    void operator=(const hkVector4D563& v)
    {
        m_vComponents = v.m_vComponents;
    }

    void SetAllComponents(const float& f)
    {
        m_vComponents = _mm_load_ps1(&f);
    }

    void setAdd4(const hkVector4D563& a, const hkVector4D563& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }

    void setSub4(const hkVector4D563& a, const hkVector4D563& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }

    void add4(const hkVector4D563& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }

    void sub4(const hkVector4D563& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }

    void mul4(const __m128& s)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, s);
    }

    void setMin4(const hkVector4D563& a, const hkVector4D563& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }

    void setMax4(const hkVector4D563& a, const hkVector4D563& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
};

struct hkAabbD563
{

    hkVector4D563 m_kMinimumCorner;

    hkVector4D563 m_kMaximumCorner;

    void includeAabb(const hkAabbD563& other)
    {

        m_kMinimumCorner.setMin4(m_kMinimumCorner, other.m_kMinimumCorner);

        m_kMaximumCorner.setMax4(m_kMaximumCorner, other.m_kMaximumCorner);
    }
};

struct hkpD563Tree
{
    void FUN_00d4abf0(void* arg);
};

struct hkpD563Key
{
    unsigned int unk00, unk04, unk08, unk0c;
};

void __cdecl FUN_00d55680(hkpD563Tree* tree, const hkpD563Key* key, hkAabbD563* out);

class hkpD563Shape
{

  public:
    hkpD563Tree* FUN_00d562f0();

    int Vec4(void* arg, int level);

    void addTrianglesSubpart(void* arg);

    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;

    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;

    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;

    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;

    hkpD563Key m_key;

    hkVector4D563 m_kAabbHalfExtents;

    hkVector4D563 m_kAabbCenter;

    unsigned int unkB0, unkB4;

    int m_numLevels;

    unsigned int unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;

    int m_total;

    float m_fScalar;
};

// Updates the shape's AABB by querying the tree, expanding by m_fScalar, and accumulating m_total from FUN_00d56160.
// @fnv 0x00d563a0
void hkpD563Shape::addTrianglesSubpart(void* arg)
{

    hkpD563Tree* tree = FUN_00d562f0();

    tree->FUN_00d4abf0(arg);

    hkAabbD563 existing;

    hkAabbD563 updated;

    existing.m_kMinimumCorner.setSub4(m_kAabbCenter, m_kAabbHalfExtents);

    existing.m_kMaximumCorner.setAdd4(m_kAabbHalfExtents, m_kAabbCenter);

    FUN_00d55680(tree, &m_key, &updated);

    hkVector4D563 tolerance;

    tolerance.SetAllComponents(m_fScalar);

    hkAabbD563 expanded;

    expanded.m_kMinimumCorner.setSub4(updated.m_kMinimumCorner, tolerance);

    expanded.m_kMaximumCorner.setAdd4(updated.m_kMaximumCorner, tolerance);

    existing.includeAabb(expanded);

    hkVector4D563 center;

    center.setAdd4(existing.m_kMinimumCorner, existing.m_kMaximumCorner);

    center.mul4(DAT_010c71d0);

    m_kAabbCenter = center;

    hkVector4D563 halfExtents;

    halfExtents.setSub4(existing.m_kMaximumCorner, existing.m_kMinimumCorner);

    halfExtents.mul4(DAT_010c71d0);

    m_kAabbHalfExtents = halfExtents;

    int lastLevel = m_numLevels - 1;

    m_total += Vec4(arg, lastLevel);
}

extern "C"
{
    __m128 _mm_cmple_ps(__m128 a, __m128 b);
    int _mm_movemask_ps(__m128 a);
}

typedef signed char hkInt8;
typedef short hkInt16;
typedef unsigned short hkUint16;

extern const __m128 g_hkQuadZero;
extern const __m128 g_hkQuadAbsMask;

struct hkConvexShapeS
{
    void RetainReference() const;
    void removeReference() const;
};

template <class T> struct hkRefPtrS
{
    T* m_pRetainedObject;

    __forceinline hkRefPtrS() : m_pRetainedObject(0)
    {}
    __forceinline void operator=(T* e)
    {
        if (e)
        {
            e->RetainReference();
        }
        if (m_pRetainedObject)
        {
            m_pRetainedObject->removeReference();
        }
        m_pRetainedObject = e;
    }
};

template <typename T> struct hkArrS
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
    }

    __forceinline static void construct(T* p, int n)
    {
        for (int i = 0; i < n; i++)
        {
            new (p + i) T;
        }
    }

    __forceinline T* _expandBy(hkMemoryAllocator& alloc, int n)
    {
        int oldsize = m_iElementCount;
        GrowArrayCapacity(alloc, oldsize + n);
        construct(m_data + m_iElementCount, n);
        m_iElementCount += n;
        return m_data + oldsize;
    }

    __forceinline T* expandBy(int n)
    {
        return _expandBy(audio()->heap(), n);
    }
};

struct hkVector4f
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkQuaternionS
{
    __m128 m_vec;
    void FUN_00cb26e0(const void* rotation);
};

struct hkBoolS
{
    char m_cBooleanValue;
    hkBoolS(bool b) : m_cBooleanValue(b)
    {}
};

struct hkTransformD566
{
    hkVector4f m_kColumn0;
    hkVector4f m_kColumn1;
    hkVector4f m_kColumn2;
    hkVector4f m_vTranslation;

    hkBoolS FUN_00cd4e00(const hkTransformD566& other, hkReal epsilon) const;
};

extern const hkTransformD566 g_hkTransformIdentity;

struct hkVector4CompS
{
    __m128 m_uiMask;
    __forceinline bool allAreSetXYZ() const
    {
        return (_mm_movemask_ps(m_uiMask) & 7) == 7;
    }
};

struct ShapesSubpartT
{
    hkInt8 m_type;
    hkInt8 m_iMaterialIndexType;
    hkInt16 m_iIndexStriding;
    const void* m_pVertexBase;
    hkUint16 m_iVertexStriding;
    hkUint16 m_iNumTriangles;
    const void* m_pIndexBase;
    unsigned int m_ulUserData;
    hkArrS<hkRefPtrS<hkConvexShapeS> > m_kChildShapes;
    hkQuaternionS m_rotation;
    hkVector4f m_vTranslation;

    __forceinline void initSubpart(hkInt8 type)
    {
        m_type = type;
        m_iMaterialIndexType = 1;
        m_iVertexStriding = 0;
        m_iIndexStriding = 0;
        m_iNumTriangles = 1;
        m_pIndexBase = 0;
        m_pVertexBase = 0;
        m_ulUserData = 0;
    }
    ShapesSubpartT* FUN_00d56660(hkConvexShapeS* const* childShapes, int numChildShapes,
                                 const hkTransformD566& transform);
};

static __forceinline hkVector4CompS compareEquals3(const hkVector4f& a, const __m128& b, hkReal epsilon)
{
    const __m128 diff = _mm_and_ps(_mm_sub_ps(*(const __m128*)&a, b), g_hkQuadAbsMask);
    const __m128 eps = _mm_set_ps1(epsilon);
    hkVector4CompS c;
    c.m_uiMask = _mm_cmple_ps(diff, eps);
    return c;
}

// Initializes a convex subpart with child shapes and a transform, storing translation flags in the w component of m_vTranslation.
// @fnv 0x00d56660
ShapesSubpartT* ShapesSubpartT::FUN_00d56660(hkConvexShapeS* const* childShapes, int numChildShapes,
                                             const hkTransformD566& transform)
{
    initSubpart(1);
    m_kChildShapes.init();
    m_rotation.FUN_00cb26e0(&transform);
    m_vTranslation = transform.m_vTranslation;

    hkRefPtrS<hkConvexShapeS>* dst = m_kChildShapes.expandBy(numChildShapes);
    for (int i = 0; i < numChildShapes; i++)
    {
        dst[i] = childShapes[i];
    }

    hkVector4CompS isZero = compareEquals3(m_vTranslation, g_hkQuadZero, 0.001f);
    int flags = (isZero.allAreSetXYZ() ? 0 : 1) |
                (transform.FUN_00cd4e00(g_hkTransformIdentity, 0.001f).m_cBooleanValue ? 0 : 2);
    *(int*)&m_vTranslation.w = flags | 0x3f000000;
    return this;
}

struct hkMemoryAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* AllocateBufferWithSize(int* reqNumInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct SrcElem
{
    int f0, f4, f8, fc;
    char f10, f11;
    char p12_0, p12_1;
    int f14;
    char f18;
    char p19_0, p19_1, p19_2;
    int f1c, f20;
    unsigned short f24;
    char p26_0, p26_1;
    int f28;
    unsigned short f2c;
    char p2e_0, p2e_1;
    unsigned short f30;
    char p32_0, p32_1;
    int f34;
};

struct Src
{
    int p0_00, p0_04, p0_08, p0_0c, p0_10, p0_14, p0_18, p0_1c;
    __m128 v20;
    int f30;
    SrcElem* arr;
    int count;
    int p3c;
    unsigned short* us;
    int m_usPassCountLocal;
    int p48;
    char f4c;
    char p4d_0, p4d_1, p4d_2;
    float f50;
};

struct WeldingElem
{
    char a0, a1;
    unsigned short a2;
    int a4;
    unsigned short a8, aa;
    int ac;
    int a10;
    int a14, a18, a1c, a20, a24, a28, a2c;
    __m128 a30;
    int a40, a44;
    char a48, a49, a4a, a4b;
    int a4c, a50;
    int a54, a58, a5c;

    WeldingElem()
    {
        a0 = 0;
        a1 = 1;
        a8 = 0;
        a2 = 0;
        aa = 1;
        ac = 0;
        a4 = 0;
        a10 = 0;
        a49 = 0;
        a30 = _mm_setzero_ps();
        a50 = 0;
    }
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_cap;

    hkArray() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
    int getCapacity() const
    {
        return m_cap & 0x3fffffff;
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(T));
        }
    }
};

struct Base1
{
    virtual void v1();
    int unk04, unk08, unk0c;
};

struct Base2
{
    virtual void v2();
    int unk14, unk18, unk1c;
};

struct FUN_00d21410 : public Base1, public Base2
{
    FUN_00d21410(int, int) throw();
};

struct FUN_00d56ab0 : public FUN_00d21410
{
    virtual void v1();
    virtual void v2();

    WeldingElem m_sub;
    __m128 m_c80;
    int m_p90_0, m_p90_4, m_p90_8, m_p90_c, m_p90_10, m_p90_14, m_p90_18, m_p90_1c;
    int m_cb0;
    hkArray<WeldingElem> m_aiIndexedValues;
    hkArray<int> m_arr2;
    hkArray<unsigned short> m_w;
    char m_cd8;
    char m_pd9_0, m_pd9_1, m_pd9_2;
    int m_cdc;
    int m_ce0;
    float m_ce4;

    FUN_00d56ab0(Src& input);
    void __thiscall FUN_00d55950();
};

// Constructs the object by copying fields from input, allocating and copying m_w, initializing m_aiIndexedValues from input.arr, and calling FUN_00d55950.
// @fnv 0x00d56ab0
FUN_00d56ab0::FUN_00d56ab0(Src& input) : FUN_00d21410(14, 1)
{
    Src* s = &input;
    hkArray<WeldingElem>& arr = m_aiIndexedValues;
    m_c80 = s->v20;
    m_ce4 = s->f50;
    m_cb0 = s->f30;
    m_cd8 = s->f4c;
    AudioMgr* m = audio();
    hkMemoryAllocator* pAllocator = m->unk10;
    int cap = m_w.m_cap;
    int curCap = cap & 0x3fffffff;
    if (curCap < s->m_usPassCountLocal)
    {
        if ((cap & 0x80000000) == 0)
            pAllocator->ReturnMemory(m_w.m_data, curCap * 2);
        {
            int iSize = s->m_usPassCountLocal * 2;
            m_w.m_data = (unsigned short*)pAllocator->AllocateBufferWithSize(&iSize);
            m_w.m_cap = iSize / 2;
        }
    }
    int num = s->m_usPassCountLocal;
    m_w.m_iElementCount = num;
    unsigned short* dst = m_w.m_data;
    const unsigned short* src = s->us;
    for (int i = 0; i < num; i++)
        dst[i] = src[i];
    int count = s->count;
    if (count == 1)
    {
        arr.m_data = &m_sub;
        arr.m_iElementCount = 1;
        arr.m_cap = 0x80000001;
    }
    else
    {
        arr.reserve(count);
        int oldSize = arr.m_iElementCount;
        int n = count - oldSize;
        WeldingElem* p = arr.m_data + oldSize;
        for (int i = 0; i < n; i++)
            new (p + i) WeldingElem();
        arr.m_iElementCount = count;
    }
    m_cdc = 0;
    for (unsigned i = 0; (int)i < s->count; i++)
    {
        arr.m_data[i].a14 = s->arr[i].f1c;
        arr.m_data[i].a4 = s->arr[i].f20;
        arr.m_data[i].a8 = s->arr[i].f24;
        arr.m_data[i].a1 = s->arr[i].f11;
        arr.m_data[i].ac = s->arr[i].f28;
        arr.m_data[i].a2 = s->arr[i].f2c;
        arr.m_data[i].aa = s->arr[i].f30;
        arr.m_data[i].a18 = s->arr[i].f0;
        arr.m_data[i].a1c = s->arr[i].f4;
        arr.m_data[i].a20 = s->arr[i].f8;
        arr.m_data[i].a40 = s->arr[i].fc;
        arr.m_data[i].a48 = s->arr[i].f10;
        arr.m_data[i].a44 = s->arr[i].f14;
        arr.m_data[i].a4c = s->arr[i].f34;
        arr.m_data[i].a30 = _mm_setzero_ps();
        arr.m_data[i].a49 = s->arr[i].f18;
    }
    FUN_00d55950();
    m_ce0 = reinterpret_cast<FUN_00d554a0_class*>(static_cast<Base2*>(this))->getNumChildShapes();
}
