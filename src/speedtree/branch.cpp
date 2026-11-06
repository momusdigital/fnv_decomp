
// src/speedtree/branch.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/branch.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_011ad14c;

struct FUN_00b14ae0_class
{
    float FUN_00b14ae0(int id, float a, float b);
};

// Returns 1.0, or 1.0 minus a*b when id equals DAT_011ad14c.
// @fnv 0x00b14ae0
float FUN_00b14ae0_class::FUN_00b14ae0(int id, float a, float b)
{
    float result = 1.0f;
    if (id == DAT_011ad14c)
        result = result - a * b;
    return result;
}

unsigned int __cdecl FUN_00ec7c56(void);

struct FUN_00b15170
{
    char m_00[0xc];
    char* m_0c;
    char* m_10;
    char* GetElement(unsigned int a);
};

// Returns a pointer to the element at index a in the buffer from m_0c to m_10, calling FUN_00ec7c56 if a is out of range.
// @fnv 0x00b15170
char* FUN_00b15170::GetElement(unsigned int uiIndex)
{
    if (uiIndex >= (unsigned int)(m_10 - m_0c))
        FUN_00ec7c56();
    return m_0c + uiIndex;
}

struct NiPoint3
{
    float x, y, z;
};

struct FUN_00b2a180
{
    float a;
    float b;
    float c;
    float Dot(const NiPoint3& point);
};

// @fnv 0x00b2a180
float FUN_00b2a180::Dot(const NiPoint3& point)
{
    return a * point.x + b * point.y + c * point.z;
}

double __cdecl FUN_00ec6054(double);
struct FUN_00b12790_class
{
    float x, y, z;
    void FUN_00b12790();
};
// Normalizes the vector by dividing x, y and z by the square root of the sum of their squares.
// @fnv 0x00b12790
void FUN_00b12790_class::FUN_00b12790()
{
    float fSumOfSquares;
    float fInvSquareRoot;
    fSumOfSquares = x * x + y * y + z * z;
    fInvSquareRoot = 1.0f / (float)FUN_00ec6054((double)fSumOfSquares);
    x *= fInvSquareRoot;
    y *= fInvSquareRoot;
    z *= fInvSquareRoot;
}

struct FUN_00b0cff0_class
{
    float x;
    float y;
    float z;
    NiPoint3* __thiscall ScaleSwizzled(NiPoint3* output, float factor);
};
// Multiplies each component by factor and writes them to output with x/y/z rotated (x<-y, y<-z, z<-x), returning output.
// @fnv 0x00b0cff0
NiPoint3* FUN_00b0cff0_class::ScaleSwizzled(NiPoint3* output, float factor)
{
    float z = factor * this->x;
    float x = factor * this->y;
    float y = factor * this->z;
    output->x = z;
    output->y = x;
    output->z = y;
    return output;
}

extern double __cdecl FUN_00eca190(double value);
struct This : FUN_00b2a180
{
    float FUN_00b12720(const NiPoint3& point);
};
// Computes the dot product of point with this object, clamps it to [-1, 1], and returns the result of FUN_00eca190 on the clamped value.
// @fnv 0x00b12720
float This::FUN_00b12720(const NiPoint3& point)
{
    float value = Dot(point);
    if (value < -1.0f)
        value = -1.0f;
    if (value > 1.0f)
        value = 1.0f;
    return (float)FUN_00eca190(value);
}

struct State
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
    float threshold;
    float upper;
    int count;
};
extern State* DAT_011f8bf4;
struct GlobalObject_00b3f100
{
    float FUN_00b3f130(float, float);
};
extern GlobalObject_00b3f100 g_011f8c05;
struct Link
{
    Link* next;
    float value;
};
struct Owner
{
    bool FUN_00b13b50(Link* link, float input);
};
// @fnv 0x00b13b50
bool Owner::FUN_00b13b50(Link* link, float input)
{
    bool result = false;
    {
        float value = input;
        if (DAT_011f8bf4->count == 0)
        {
            int current = 1;
            Link* index = link;
            Link* next;
            while (index != 0 && (next = index->next) != 0 && current < DAT_011f8bf4->count)
            {
                index = index->next;
                ++current;
            }
            if (index != 0)
                value = index->value;
        }
        if (value > DAT_011f8bf4->threshold)
        {
            if (g_011f8c05.FUN_00b3f130(0.0f, 1.0f) <= DAT_011f8bf4->upper)
                result = true;
        }
    }
    return result;
}

struct B4230Point3
{
    float x;
    float y;
    float z;

    float FastSqrt() const;
};

// Computes the square root of the squared length of the vector via a bit-shift approximation on the float bits.
// @fnv 0x00b14230
float B4230Point3::FastSqrt() const
{
    float fSqrLength = z * z + (y * y + x * x);
    int iSqrtBits = ((*(int*)&fSqrLength) >> 1) + 0x1fc00000;
    return *(float*)&iSqrtBits;
}

// FUN_00b14b10 - blends the first argument towards zero by the second one
// (value - value * factor).  The double literal 0.0 is what makes MSVC 2008
// build the x87 register-to-register multiply instead of the memory-operand one.
struct FUN_00b14b10_class
{
    float FUN_00b14b10(float value, float factor);
};

// @fnv 0x00b14b10
float FUN_00b14b10_class::FUN_00b14b10(float value, float factor)
{
    float result = factor * (0.0 - value) + value;
    return result;
}

struct b14_sub
{
    float x, y, z;
    float FUN_00b04d40(b14_sub* other);
};

struct b14_elem
{
    char unk00[0xc];
    b14_sub sub;
    float unk18;
    char unk1c[0x2c];
};

struct b14_ctx
{
    char unk00[0x20];
    b14_elem* unk20;
    int unk24;
    char unk28[8];
    float unk30;
    void FUN_00b14b40();
};

// @fnv 0x00b14b40
void b14_ctx::FUN_00b14b40()
{
    if (this->unk20 != 0)
    {
        if (this->unk24 > 1)
        {
            this->unk30 = 0.0f;
            for (int i = 0; i < this->unk24 - 1; i++)
            {
                b14_elem* pCurrent = &this->unk20[i];
                float sum;
                b14_elem* m_pActionSuccessor = &this->unk20[i] + 1;
                {
                    int t1;
                    int t2;
                    sum = pCurrent->sub.FUN_00b04d40(&m_pActionSuccessor->sub);
                    this->unk30 = (pCurrent->unk18 + m_pActionSuccessor->unk18) * sum + this->unk30;
                }
            }
        }
    }
}

struct FUN_00b14be0_cls;

struct SegmentEntry
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
    float f40;
    int unk44;
};

struct OutPair
{
    int idx;
    float t;
};

struct FUN_00b14be0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    SegmentEntry* m_20;
    int m_24;
    void FindSegment(OutPair* out, float v);
};

// @fnv 0x00b14be0
void FUN_00b14be0_cls::FindSegment(OutPair* out, float afValue)
{
    if (m_20 != 0 && m_24 >= 2)
    {
        out->idx = 0;
        for (int i = 1; i < m_24; ++i)
        {
            if (afValue < m_20[i].f40)
            {
                out->idx = i - 1;
                break;
            }
        }
        out->t = (afValue - m_20[out->idx].f40) / (m_20[out->idx + 1].f40 - m_20[out->idx].f40);
    }
}

// @fnv 0x00b15110
float __cdecl FUN_00b15110(Link* link)
{
    float ratio;
    Link* rest;
    if (link == 0 || (rest = link->next) == 0)
    {
        return 0.0f;
    }
    {
        Link* next = link->next;
        ratio = FUN_00b15110(next);
        float b = link->value;
        float ret = (1.0f - ratio) * b + ratio;
        return ret;
    }
}

// Stand-in for the game's vector type: three floats plus the vector helpers
// the original calls (difference, normalisation, scaling, sum and dot product).
struct Vec
{
    float x, y, z;
    void FUN_00b12790();                         // normalise in place
    void FUN_00b13040(Vec* out, const Vec* p);   // *out = *this - *p
    Vec* ScaleSwizzled(Vec* out, float factor);  // *out = *this * factor
    void AddVector(Vec* out, const Vec* other);  // *out = *this + *other
    float Dot(const Vec& p);
};

// The class that owns ProjectOntoLine (in the game it derives from the vector
// class, so `this` points at the three floats a, b and c).
struct MyThis
{
    float a, b, c;
    Vec* ProjectOntoLine(Vec* out, Vec* a, Vec* b, Vec* c);
};

// The function projects the point c onto the line through a and b.
//
// This unit is compiled unoptimised, and there the compiler lays the frame
// out in the order of a hash of the local names, so the names below are
// picked to reproduce the original's frame byte for byte:
//   ebp-0x68  the compiler's own temporary for the 0/1 result
//   ebp-0x64  this
//   ebp-0x60 .. ebp-0x2c  56 bytes of dead temporaries (m, o, L, U, i2, l2)
//   ebp-0x28  e   (the scaled direction)
//   ebp-0x1c  dir (the dot product)
//   ebp-0x18  ejne (the normalised direction)
//   ebp-0x0c  z   (c - a)
// @fnv 0x00b3ec40
Vec* MyThis::ProjectOntoLine(Vec* out, Vec* a, Vec* pLineStart, Vec* c)
{
    Vec m;
    Vec o;
    Vec L;
    Vec U;
    float i2;
    float l2;
    Vec e;
    float dir;
    Vec ejne;
    Vec z;
    if ((unsigned char)((a->x == pLineStart->x && a->y == pLineStart->y && a->z == pLineStart->z) ? 1 : 0))
    {
        *out = *a;
        return out;
    }
    pLineStart->FUN_00b13040(&ejne, a);
    ejne.FUN_00b12790();
    c->FUN_00b13040(&z, a);
    dir = z.Dot(ejne);
    a->AddVector(out, ejne.ScaleSwizzled(&e, dir));
    return out;
}

extern unsigned int __cdecl FUN_00ec7c56(void);

struct NiPoint3x
{
    float x, y, z;
};

struct S_00b14280_Entry
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
    float m_ucLowNibble;
    float m_ucHighNibble;
    int unk50;
};

struct S_00b14280_Entries
{
    int unk00;
    int unk04;
    int unk08;
    S_00b14280_Entry* m_pRayStart;
    S_00b14280_Entry* m_kRayEnd;
};

struct S_00b14280_Obj
{
    int unk00;
    NiPoint3x m_pos;
};

struct S_00b14280_List
{
    int unk00;
    int unk04;
    int unk08;
    S_00b14280_Obj** m_pRayStart;
    S_00b14280_Obj** m_kRayEnd;
};

struct S_00b14280_State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00b14280_Entries m_entries;
    int unk24;
    float m_threshold;
};

struct S_00b14280_This
{
    bool IsPointClearOfEntries(const NiPoint3x& pt, unsigned int index, S_00b14280_List* list);
};

// @fnv 0x00b14280
bool S_00b14280_This::IsPointClearOfEntries(const NiPoint3x& aPoint, unsigned int index, S_00b14280_List* list)
{
    bool ok5 = true;
    float r7;
    unsigned int i;
    S_00b14280_Entries* a8;
    S_00b14280_Entries* b;
    S_00b14280_Entry* en7;
    S_00b14280_Obj** p5;
    const NiPoint3x* RunSeventhVirtualOperation;
    a8 = &((S_00b14280_State*)DAT_011f8bf4)->m_entries;
    if ((unsigned char)(((a8->m_kRayEnd - a8->m_pRayStart) == 0) ? 1 : 0) == 0)
    {
        b = &((S_00b14280_State*)DAT_011f8bf4)->m_entries;
        if (index >= (unsigned int)(b->m_kRayEnd - b->m_pRayStart))
            FUN_00ec7c56();
        en7 = &b->m_pRayStart[index];
        r7 = (en7->m_ucLowNibble > en7->m_ucHighNibble) ? en7->m_ucLowNibble : en7->m_ucHighNibble;
        r7 = r7 * ((S_00b14280_State*)DAT_011f8bf4)->m_threshold;
        for (i = 0; i < (unsigned int)(list->m_kRayEnd - list->m_pRayStart) && ok5; i++)
        {
            if (i >= (unsigned int)(list->m_kRayEnd - list->m_pRayStart))
                FUN_00ec7c56();
            p5 = &list->m_pRayStart[i];
            RunSeventhVirtualOperation = &(*p5)->m_pos;
            if (aPoint.x < RunSeventhVirtualOperation->x + r7 && aPoint.x > RunSeventhVirtualOperation->x - r7 &&
                aPoint.y < RunSeventhVirtualOperation->y + r7 && aPoint.y > RunSeventhVirtualOperation->y - r7 &&
                aPoint.z < RunSeventhVirtualOperation->z + r7 && aPoint.z > RunSeventhVirtualOperation->z - r7)
                ok5 = false;
        }
    }
    else
    {
        ok5 = false;
    }
    return ok5;
}

struct AngleState
{
    Vec heading;
    float radians;
    float unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
};

struct FacingTint
{
    int unk00;
    Vec* FUN_00b40430(Vec* out);
    void FUN_00b404c0(Vec* point, int flag);
    void FUN_00b40210(Vec* point, Vec* other, float t);
};

extern double __cdecl FUN_00ec9f30(double value);
extern double DAT_01011588;

// @fnv 0x00b40210
void FacingTint::FUN_00b40210(Vec* point, Vec* other, float t)
{
    Vec goal;
    Vec sample;
    float length;
    float scale;
    Vec scaled;
    Vec dest;
    AngleState basis;
    ((Vec*)((char*)this + 4))->FUN_00b13040(&sample, point);
    sample.FUN_00b12790();
    other->FUN_00b13040(&goal, point);
    goal.FUN_00b12790();
    basis.radians = ((This*)&sample)->FUN_00b12720(*(NiPoint3*)&goal);
    length = (float)(double)(float)FUN_00ec9f30(basis.radians);
    scale = (float)((length + 1.0) * DAT_01011588) * (1.0f - t) + t;
    this->FUN_00b404c0(this->FUN_00b40430(&scaled)->ScaleSwizzled(&dest, scale), 1);
}

#include <stdlib.h>
// Returns a random float between minimum and maximum by scaling rand() to the range width and offsetting by minimum.
// @fnv 0x00b14e90
float RandomFloatInRange(float minimum, float maximum)
{
    float fraction = (float)(rand() / 32767.0);
    float range = maximum - minimum;
    return fraction * range + minimum;
}
