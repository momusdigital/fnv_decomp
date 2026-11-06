
// src/bsmenu/radialtile_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/bsmenu/radialtile.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/bsmenu/radialtile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsmenu/radialtile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct TileImage
{
    TileImage();
    virtual void Dummy();
};
struct FUN_00a21660 : TileImage
{
    FUN_00a21660();
};
struct P03MM
{
    void Deallocate(void*);
};
extern P03MM g_memoryManager;
struct FUN_00a219e0_shell
{
    void* FUN_00a219e0(unsigned int flags);
    void __thiscall DestroyTileImageBase();
};
// ---------------------------------------------------------------------------
// 0x00a21690 - FUN_00a219e0_shell::DestroyTileImageBase()
//
// The original is an unoptimised (/Od) build:
//     00a21690  55                 push ebp
//     00a21691  8b ec              mov ebp, esp
//     00a21693  83 ec 1c           sub esp, 0x1c
//     00a21696  89 4d e4           mov dword ptr [ebp - 0x1c], ecx
//     00a21699  8b 45 e4           mov eax, dword ptr [ebp - 0x1c]
//     00a2169c  c7 00 50 57 09 01  mov dword ptr [eax], 0x01095750
//     00a216a2  8b 4d e4           mov ecx, dword ptr [ebp - 0x1c]
//     00a216a5  e8 16 a0 ce ff     call 0x0070b6c0
//     00a216aa  8b e5              mov esp, ebp
//     00a216ac  5d                 pop ebp
//     00a216ad  c3                 ret
//
// The function puts the vtable pointer of the class back at the front of the
// object (0x01095750 is the vftable of FUN_00a21660) and then chains to the
// base class destructor TileImage::~TileImage() at 0x0070b6c0.
//
// The /Od frame is 0x1c bytes wide: six dead words plus the spilled `this`.
// ---------------------------------------------------------------------------
// The vtable of the class, 0x01095750 in the original binary.  It is only
// ever used by address, so a declaration is enough.
extern void* const FUN_00a21660Vftable[];
// The base class of the object.  Its destructor is defined in another
// translation unit (TileImage::~TileImage(), 0x0070b6c0 in the original
// binary), so it is declared here and never defined.
struct TileImageBase
{
    const void* vtable;  // +0x00, the vtable pointer of the object
    TileImageBase();
    ~TileImageBase();
};
// Six dead words of stack space.  The original /Od build reserved them
// between the frame pointer and the spilled `this` pointer, and nothing ever
// reads or writes them.
struct DeadStackSpace
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

#include <math.h>
struct Value
{
    int unk00;
    int unk04;
    float unk08;
};

extern unsigned int BSStringLength(const char*);
inline unsigned int BSStringCapacityMaximum(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}
extern void* __memcpy(void*, const void*, unsigned int);
void* operator new(unsigned int);
void operator delete(void*);

struct BSString
{
    char* m_data;
    unsigned short m_bufLen;
    unsigned short m_dataLen;

    BSString(unsigned int len = 0)
    {
        m_data = 0;
        SetBufLen(len);
        SetDataLen(len);
    }
    void SetBufLen(unsigned int len)
    {
        m_bufLen = (len <= 0xffff) ? (unsigned short)len : 0xffff;
    }
    void SetDataLen(unsigned int len)
    {
        m_dataLen = (len <= 0xffff) ? (unsigned short)len : 0xffff;
    }
    ~BSString()
    {
        Set(0, 0);
    }
    unsigned int GetMaxLength() const
    {
        return m_dataLen;
    }
    bool Set(const char* text, unsigned int requested)
    {
        unsigned int inputLength = text ? BSStringLength(text) : 0;
        unsigned int length = inputLength;
        unsigned int capacity = BSStringCapacityMaximum(length, requested);
        if (capacity <= GetMaxLength())
        {
            if (capacity)
            {
                if (text)
                    __memcpy(m_data, text, length + 1);
                else
                    m_data[0] = 0;
            }
            else
            {
                if (m_data)
                    delete[] m_data;
                m_data = 0;
                capacity = 0;
                SetDataLen(capacity);
            }
        }
        else
        {
            char* oldData = m_data;
            char* allocation = new char[capacity + 1];
            m_data = allocation;
            if (text)
                __memcpy(m_data, text, length + 1);
            else
                m_data[0] = 0;
            if (oldData)
                delete[] oldData;
            SetDataLen(capacity);
        }
        SetBufLen(length);
        return length != 0;
    }
};

struct Tile
{
    virtual void Dummy();
    float FUN_00a011b0(int trait);
    void* FUN_00a00f30(int trait);

    bool SpecialBoundsCheck(float x, float y);
};

extern float FUN_00706e40();
extern Tile* FUN_00706cd0();
extern int FUN_00406f60(BSString*, const char*, ...);
extern void FUN_005b5e40(const char*);

// @fnv 0x00a216b0
bool Tile::SpecialBoundsCheck(float x, float y)
{
    float a = this->FUN_00a011b0(0x1004);
    float h = this->FUN_00a011b0(0x1005);
    float q = this->FUN_00a011b0(0x1006);
    float a7 = this->FUN_00a011b0(0x1007);
    float f = this->FUN_00a011b0(0x1008);
    float p = this->FUN_00a011b0(0x1009);

    float scale = FUN_00706e40();
    if (scale == 0.0f)
    {
        scale = 1.0f;
    }

    Tile* s = FUN_00706cd0();
    if (s)
    {
        Value* t34 = (Value*)s->FUN_00a00f30(0xfb1);
        if (t34)
        {
            scale = t34->unk08 / scale;
        }
        else
        {
            scale = 1.0f;
        }
    }
    else
    {
        scale = 1.0f;
    }

    x *= scale;
    y *= scale;
    x -= a;
    y -= h;

    float angle8;
    if (y != 0.0f)
    {
        angle8 = atan(-x / y);
    }
    else
    {
        if (x > 0.0f)
        {
            angle8 = 1.57075f;
        }
        else
        {
            angle8 = 4.71238f;
        }
    }

    if (y > 0.0f)
    {
        angle8 += 3.14159;
    }

    if (x < 0.0f && y < 0.0f)
    {
        angle8 += 6.28318;
    }

    if (q <= angle8 && angle8 <= a7)
    {

        float mag5 = sqrt(x * x + y * y);

        BSString b;
        FUN_00406f60(&b, "--- fx %f fy %f  --- Magnitude: %f ", x, y, mag5);
        FUN_005b5e40(b.m_data);

        if (f <= mag5 && mag5 <= p)
        {
            return true;
        }
    }
    return false;
}
