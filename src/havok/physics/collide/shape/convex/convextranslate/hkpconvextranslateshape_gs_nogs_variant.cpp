
// src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpConvexTranslateShape.h"
// FUN_00dd5e60 : the stub family - load a sub-object pointer out of `this`
// and tail-jump to one of its virtuals.
//   mov ecx,[ecx+0x18] / mov eax,[ecx] / mov edx,[eax+0x2c] / jmp edx
// The target is in EDX, so the virtual takes NO stack argument.  MSVC puts the
// first virtual at vptr+0 (the RTTI pointer is at [vftable-4]), so vtable
// offset 0x2c needs twelve virtuals: eleven dummies and the real one.
struct Sub_dd5e60
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
};
struct Own_dd5e60
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Sub_dd5e60* m_sub;  // at +0x18
    void __thiscall FUN_00dd5e60();
};
class hkpShapeCollectionDD5E
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual int getChildShapes(int iKey, int iBufferSize) throw();
};
class hkpShapeBufferDD5E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkpShapeCollectionDD5E* m_pShapeCollection;
    int m_offset;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkpShapeCollectionDD5E m_inlineCollection;

    int GetChildShapes(int iKey, int iBufferSize);
};
struct Sub_dd5e70
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C(const char* name, void* child, int flags);
};
extern int DAT_01268940;
struct Own_dd5e70
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_sub;

    void __thiscall FUN_00c90360(Sub_dd5e70* object, const int* attribute);
    void __thiscall AttachChildAndAttribute(Sub_dd5e70* object, int unused);
};
struct FUN_00dd5ea0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* FUN_00dd5ea0();
};

#include <xmmintrin.h>
struct FUN_00dd5fa0_VTable
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
    virtual void v44(void* value);
};

struct FUN_00dd5fa0_Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00dd5fa0_VTable* m_sub;
    __m128 m_vTranslation;

    void __thiscall getCentreImpl(__m128* value);
};

// @fnv 0x00dd5fa0
void __thiscall FUN_00dd5fa0_Object::getCentreImpl(__m128* value)
{
    m_sub->v44(value);
    *value = _mm_add_ps(m_vTranslation, *value);
}

struct Child_dd5fd0
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
    virtual void v34(hkVector4* v);
};

struct Struct_dd5fd0 : public hkpConvexTranslateShape
{
    void __thiscall getFirstVertex(hkVector4* v);
};

// @fnv 0x00dd5fd0
void __thiscall Struct_dd5fd0::getFirstVertex(hkVector4* v)
{
    Child_dd5fd0* child = (Child_dd5fd0*)m_pContainedShape.m_pContainedShape;
    child->v34(v);

    __m128 translation = *(__m128*)&m_vTranslation;
    __m128 value = *(__m128*)v;
    *(__m128*)v = _mm_add_ps(translation, value);
}
