
// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00e63c60: the skeleton of src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp
// with declarations corrected to what the original code does (unit: void __cdecl FUN_00e63c60(bool *); -> int __cdecl FUN_00e63c60(bool *);). Move the function to its real unit once
// that unit declares it this way.

// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkaSplineCompressedAnimation.h"
struct FUN_00e33330_Class
{
    void* __thiscall FUN_00e33330();
};
extern bool DAT_0126efb8;
int __cdecl FUN_00e63c60(bool*);
int __cdecl GetIndexedValueWithOffset(int offset, const int* values, int index, int count);
int __stdcall getNumDataChunks(int a1, int a2);
struct FnvAnimation
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual int slot10(float time, int blockOffset, int parameterA, int blockEnd, int parameterB, int parameterC);

    int unk04;
    int unk08;
    int unk0C;
    int blockOffset;
    int blockEnd;

    int FUN_00e32ee0(float time, int parameterA, int parameterB, int parameterC);
};
typedef void(__cdecl* SplineDecodeFn)(int, void*);
extern int DAT_010eb3b8[];
extern int DAT_010eb3d0[];
extern SplineDecodeFn DAT_011be4b8[];
void __cdecl DecodeSplineFrames(int* cursor, int type, int lastFrame, int firstFrame, int endFrame, void* output);
template <class T> class hkArrayE333
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T* begin() const
    {
        return m_data;
    }
};
struct hkaAnimationDataChunkE333
{
    const char* m_data;
    int m_iElementCount;
    unsigned char m_offset;

    void set(const void* p, int iSize)
    {
        unsigned char offset = static_cast<unsigned char>(reinterpret_cast<unsigned long>(p) & 15);
        m_data = reinterpret_cast<const char*>(reinterpret_cast<unsigned long>(p) & ~15);
        m_offset = offset;
        m_iElementCount = (offset + iSize + 15) & ~15;
    }
};
class hkaSplineCompressedAnimationE333
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
    int unk28;
    int m_iBlockCount;
    int m_iMaxFramesPerBlock;
    int unk34;
    float unk38;
    float m_fBlockInverseDuration;
    float m_fPerFrameDuration;
    hkArrayE333<unsigned int> m_kFirstUInt32Array;
    hkArrayE333<unsigned int> m_kFloatBlockOffsets;
    hkArrayE333<unsigned int> unk5C;
    hkArrayE333<unsigned int> unk68;
    hkArrayE333<unsigned char> m_data;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;

    void GetBlockAndTime(unsigned int frame, float delta, int& blockOut, float& blockTimeOut,
                         unsigned char& quantizedTimeOut) const throw();
    void GetDataChunks(unsigned int frame, float delta, hkaAnimationDataChunkE333* dataChunks, int numDataChunks) const
        throw();
};
typedef char fnv_check_e33350[(sizeof(hkaSplineCompressedAnimationE333) == 0x90) ? 1 : -1];
struct hkMathE334
{
    static int max2(int x, int y)
    {
        return x > y ? x : y;
    }
};
class FUN_00e33400_cls
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
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int* m_offsets;
    int m_numOffsets;
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
    int m_kRayEnd;

    int getMaxSizeOfCombinedDataChunks() const;
};
template <typename T> inline T max2E347(T a, T b)
{
    return a > b ? a : b;
}
template <typename T> inline T min2E347(T a, T b)
{
    return a < b ? a : b;
}
class hkaSplineCompressedAnimationE347
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
    int unk28;
    int m_iBlockCount;
    int m_iMaxFramesPerBlock;
    int unk34;
    float unk38;
    float m_fBlockInverseDuration;
    float m_fPerFrameDuration;

    void GetBlockAndTime(unsigned int frame, float delta, int& blockOut, float& blockTimeOut,
                         unsigned char& quantizedTimeOut) const throw();
};

extern char DAT_010c3aa0[];
extern void __cdecl FUN_00cb1750(const char* message);
extern int __cdecl FUN_00e29910();
extern "C" void _ReadWriteBarrier(void);

static int hexDigit(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    return -1;
}

static char* findDot(char* p)
{
    while (p)
    {
        if (!*p || *p == '.')
        {
            _ReadWriteBarrier();
            break;
        }
        ++p;
    }
    return p;
}

static void invalidKey()
{
    FUN_00cb1750("Product:hka Key Code is invalid.\nPlease contact Havok.com\nNo simulation possible.");
}

// @fnv 0x00e63c60
int __cdecl FUN_00e63c60(bool* valid)
{
    *valid = false;
    int status = 0;
    unsigned long second;
    second = 0xfffffffful;
    int first;
    first = -1;
    char* p;
    p = DAT_010c3aa0 + 2;
    int digit = hexDigit(*p++);
    while (digit >= 0)
    {
        first = (first << 4) + digit;
        digit = hexDigit(*p++);
    }
    p += 2;
    digit = hexDigit(*p++);
    while (digit >= 0)
    {
        second = (second << 4) + digit;
        digit = hexDigit(*p++);
    }

    unsigned char expires = (unsigned char)(((unsigned int)first >> 31) & 1);

    char* dot = findDot(DAT_010c3aa0);
    if (!dot)
    {
        invalidKey();
        return 1;
    }
    dot = findDot(dot + 1);
    if (!dot)
    {
        invalidKey();
        return 1;
    }
    ++dot;

    if (expires)
    {
        first = (first ^ 0xd4efe34a) & 0x7fffffff;
        int now = FUN_00e29910() >> 8;
        int remaining = first - now;
        if (first < now || remaining > 0x96c99)
        {
            FUN_00cb1750(
                "Product:hka Key Code has expired .\nPlease contact Havok.com for an extension.\nNo simulation possible.");
            return 2;
        }
        if (remaining < 0xd2f)
            status = 3;
    }
    else
    {
        int hash = 0;
        while (*dot)
        {
            hash = hash * 23 + *++dot;
        }
        hash = (hash ^ 0xd4efe34a) & 0x7fffffff;
        if (second != hash)
        {
            invalidKey();
            return 1;
        }
    }
    *valid = true;
    return status;
}
