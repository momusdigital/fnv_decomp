
// src/havok/common/serialize/data/dict/hkdataobjectdict_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/serialize/data/dict/hkdataobjectdict.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/serialize/data/dict/hkdataobjectdict.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/data/dict/hkdataobjectdict.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00dc72e0_class
{
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_p4;
    void* m_p5;
    void* m_p6;
    void* m_p7;
    void FUN_00dc72e0(void* pArg, void* pVal);
};
struct FUN_00dc8a60_class
{
    char m_data[0x28];
    char* FUN_00dc8a60(int arg);
};
struct FUN_00dc8fc0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    void ResetEntries();
    void Reset();
};
struct FUN_00dc9540_class
{
    int __thiscall FUN_00dc9540(int a);
};
struct FUN_00dc9550_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void* m_pc;
    void* m_p10;
    void FUN_00dc9550(void** out, int idx);
};
struct FUN_00dc9ab0_class
{
    int* __thiscall FUN_00dc9ab0(int a);
};
extern int DAT_010d707c;
struct FUN_00dca1c0
{
    void* m0;
    unsigned short m4;
    unsigned short m6;
    int m8;
    int m12;
    int m16;
    int m20;
    FUN_00dca1c0();
};
struct FUN_00dca1f0
{
    int m0;
    int m4;
    int m8;
    int mc;
    void __thiscall Set(char* a, char b);
};
struct FUN_00dca5d0_Class
{
    float* SetFloatAt(int index, float value);
};
struct FUN_00dcad80_node
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
};
struct FUN_00dcad80
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int GetNumMembers();
};
struct FUN_00dcb0d0_class
{
    int* m_p;
    void FUN_00dcb0d0(int* p);
};
struct FUN_00dcb170_class
{
    int __thiscall FUN_00dcb170(int);
};
struct FUN_00dcb2b0_StandIn
{
    int __thiscall FUN_00dcb2b0(int);
};
struct FUN_00dcb490_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int __thiscall FUN_00dcb490(int);
};
void __stdcall FUN_00dc72f0(int* p);
struct FUN_00dc9530_StandIn
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    char FUN_00dc9530(int a);
};
struct FUN_00dca5c0_Class
{
    float* m_p0;
    float* m_p4;
    float* m_p8;
    float* m_pc;
    float FUN_00dca5c0(int index);
};
struct FUN_00dc8e50_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int* FindEntry(int value);
};
struct FUN_00dca2b0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    __int64* m_iThirdValue;
    __int64 __thiscall asInt64(int index);
};
struct FUN_00dcb0c0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void SetPair(void** out, int value);
};
struct FUN_00dcb190_Elem
{
    void* m0;
    void* m4;
};
struct FUN_00dcb190_Inner
{
    void* m0;
    void* m4;
    void* m8;
    FUN_00dcb190_Elem* m_data;
};
struct FUN_00dcb190_Class
{
    void* m0;
    void* m4;
    void* m8;
    FUN_00dcb190_Inner* m_iThirdValue;
    void* __thiscall FUN_00dcb190(int index);
};
struct FUN_00dc6fd0_VTable
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void(__thiscall* m_8)(void*);
};
struct FUN_00dc6fd0_Intermediate
{
    char m_00[0x20];
    void* m_20;
};
struct FUN_00dc6fd0_class
{
    char m_00[0x0C];
    FUN_00dc6fd0_Intermediate* m_0C;
    void FUN_00dc6fd0();
};
struct FUN_00dc6ff0_Stream
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void call(void*, unsigned char)
    {}
};
struct FUN_00dc6ff0_Wrapper
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    FUN_00dc6ff0_Stream* m20;
};
struct FUN_00dc6ff0_class
{
    void* m00;
    void* m04;
    void* m08;
    FUN_00dc6ff0_Wrapper* m0c;
    unsigned char* m10;

    void FUN_00dc6ff0(const unsigned char* data, int count);
};
struct FUN_00dc7030_Target
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void va() = 0;
    virtual void vb() = 0;
    virtual void vc() = 0;
    virtual void FUN_00dc7030_virtual(unsigned char* p, float value) = 0;
};
struct FUN_00dc7030_Holder
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    FUN_00dc7030_Target* m20;
};
struct FUN_00dc7030_StandIn
{
    void* m00;
    void* m04;
    void* m08;
    FUN_00dc7030_Holder* m0c;
    unsigned char* m10;

    void __thiscall FUN_00dc7030(float* values, int count);
};
struct FUN_00dc7070_target
{
    virtual void FUN_00dc7070_v0() = 0;
    virtual void FUN_00dc7070_v1() = 0;
    virtual void FUN_00dc7070_v2() = 0;
    virtual void FUN_00dc7070_v3() = 0;
    virtual void FUN_00dc7070_v4() = 0;
    virtual void FUN_00dc7070_v5() = 0;
    virtual void FUN_00dc7070_v6() = 0;
    virtual void FUN_00dc7070_v7() = 0;
    virtual void* FUN_00dc7070_v8(int) = 0;
};
struct FUN_00dc7070_holder
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc7070_target* m_20;
};
struct FUN_00dc7070_class
{
    void* m_00;
    int m_04;
    void* m_08;
    FUN_00dc7070_holder* m_0c;
    int m_10;

    void* FUN_00dc7070(int a);
};
struct FUN_00dc7090_vtable
{
    void* m_slots[10];
};
struct FUN_00dc7090_target
{
    FUN_00dc7090_vtable* m_ppVirtualMethodTable;
};
struct FUN_00dc7090_wrapper
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc7090_target* m_20;
};
struct FUN_00dc7090_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dc7090_wrapper* m_0c;
    int m_10;
    void __thiscall InvokeTargetMethod(int a, int b);
};
typedef void(__thiscall* FUN_00dc7090_call)(void*, int, int);
struct FUN_00dc70e0_Virtual
{
    virtual void F0() = 0;
    virtual void F1() = 0;
    virtual void F2() = 0;
    virtual void F3() = 0;
    virtual void F4() = 0;
    virtual void F5() = 0;
    virtual void F6() = 0;
    virtual void F7() = 0;
    virtual void F8() = 0;
    virtual void F9() = 0;
    virtual void F10() = 0;
    virtual void Call(int value, void* data) = 0;
};
struct FUN_00dc70e0_Intermediate
{
    char m_00[0x20];
    FUN_00dc70e0_Virtual* m_20;
};
struct FUN_00dc70e0_class
{
    char m_00[0x0c];
    FUN_00dc70e0_Intermediate* m_0c;
    int m_10;

    void __thiscall CallAtOffset(int offset, void* data);
};
struct FUN_00dc7110_Target
{
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual int FUN_00dc7110_virtual(int) = 0;
};
struct FUN_00dc7110_Intermediate
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc7110_Target* m_20;
};
struct FUN_00dc7110_Class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dc7110_Intermediate* m_0c;
    int m_10;
    int GetVirtualResult(int a);
};
struct FUN_00dc7180_callee
{
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual int FUN_00dc7180(int, int) = 0;
};
struct FUN_00dc7180_middle
{
    char m_ucUnknownByte[0x20];
    FUN_00dc7180_callee* m_callee;
};
struct FUN_00dc7180_class
{
    char m_ucUnknownByte[0x0c];
    FUN_00dc7180_middle* m_middle;
    int m_uiFilterValue;

    int __thiscall FUN_00dc7180(int a, int b);
};
struct FUN_00dc71b0_target
{
    virtual void m00() = 0;
    virtual void m04() = 0;
    virtual void m08() = 0;
    virtual void m0c() = 0;
    virtual void m10() = 0;
    virtual void m14() = 0;
    virtual void m18() = 0;
    virtual void m1c() = 0;
    virtual void m20() = 0;
    virtual void m24(int) = 0;
    virtual void m28() = 0;
    virtual void m2c() = 0;
    virtual void m30() = 0;
    virtual void m34() = 0;
    virtual void m38() = 0;
    virtual void m3c() = 0;
    virtual void m40() = 0;
    virtual void m44() = 0;
    virtual int m48(int) = 0;
};
struct FUN_00dc71b0_inner
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    FUN_00dc71b0_target* m20;
};
struct FUN_00dc71b0_class
{
    void* m00;
    void* m04;
    void* m08;
    FUN_00dc71b0_inner* m0c;
    int m10;
    int __thiscall GetOffsetValue(int);
};
struct FUN_00dc7220_VirtualBase
{
// @fnv 0x00dc7220
    virtual void FUN_00dc7220_v00()
    {}
    virtual void FUN_00dc7220_v01()
    {}
    virtual void FUN_00dc7220_v02()
    {}
    virtual void FUN_00dc7220_v03()
    {}
    virtual void FUN_00dc7220_v04()
    {}
    virtual void FUN_00dc7220_v05()
    {}
    virtual void FUN_00dc7220_v06()
    {}
    virtual void FUN_00dc7220_v07()
    {}
    virtual void FUN_00dc7220_v08()
    {}
    virtual void FUN_00dc7220_v09()
    {}
    virtual void FUN_00dc7220_v10()
    {}
    virtual void FUN_00dc7220_v11()
    {}
    virtual void FUN_00dc7220_v12()
    {}
    virtual void FUN_00dc7220_v13()
    {}
    virtual void FUN_00dc7220_v14()
    {}
    virtual void FUN_00dc7220_v15()
    {}
    virtual void FUN_00dc7220_v16()
    {}
    virtual void FUN_00dc7220_v17()
    {}
    virtual void FUN_00dc7220_v18()
    {}
    virtual void FUN_00dc7220_v19()
    {}
    virtual void FUN_00dc7220_v20()
    {}
};
struct FUN_00dc7220_Virtual : FUN_00dc7220_VirtualBase
{
    virtual void FUN_00dc7220_virtual(int, int)
    {}
};
struct FUN_00dc7220_Holder
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc7220_Virtual* m_20;
};
struct FUN_00dc7220_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dc7220_Holder* m_0c;
    int m_10;

    void FUN_00dc7220(int a, int b);
};
void FUN_00dc7220_class::FUN_00dc7220(int a, int b)
{
    m_0c->m_20->FUN_00dc7220_virtual(m_10 + a, b);
}
struct FUN_00dc7270_virtual
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void FUN_00dc7270_virtual_call(int, int) = 0;
};
struct FUN_00dc7270_manager
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc7270_virtual* m_20;
};
struct FUN_00dc7270_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dc7270_manager* m_0c;
    int m_10;
    void __thiscall DispatchOffsetCall(int, int);
};
struct Receiver
{
    void FUN_009ba760(void* pArg);
};
struct FUN_00dc72a0_data
{
    char m_00[0x2c];
    void* m_2c;
};
struct FUN_00dc72a0_class
{
    char m_00[8];
    FUN_00dc72a0_data* m_08;

    void* __thiscall ForwardToReceiver(Receiver* m_pReceiver);
};
// FUN_00dcaaf0 placeholder: __thiscall member taking two pointer args (ret 8)
struct FUN_00dcaaf0_Class
{
    void FUN_00dcaaf0(void* a, void* b);
};
// Stand-in for the refcounted object at [edi+8] with virtual dtor (vtable slot 0)
struct FUN_00dc7cc0_RefCounted
{
    virtual void FUN_00dc7cc0_vtbl0(int);
    int m_auiShapeKeys;       // +0x4
    int m_refcount;  // +0x8
};
// Object whose vtable slot at +0x10 is called with no args, returns a pointer
struct FUN_00dc7cc0_VtblObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get();  // +0x10
};
struct FUN_00dc7cc0_Class
{
    void AssignRefCountedSlot(void** a, void** b);
};
struct FUN_00dc89d0_vt
{
    virtual void v0();
    virtual int v1();
};
struct FUN_00dc89d0
{
    void* m0;
    void* m4;
    void* m8;
    void* mc;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    FUN_00dc89d0_vt* m20;
    int __thiscall getType();
};
struct FUN_00dc8a00_Array
{
    virtual void FUN_00dc8a00_0() = 0;
    virtual void FUN_00dc8a00_1() = 0;
    virtual void FUN_00dc8a00_2() = 0;
    virtual void FUN_00dc8a00(int value) = 0;
};
struct FUN_00dc8a00_class
{
    char m_00[0x20];
    FUN_00dc8a00_Array* m_p20;
    int m_24;

    void FUN_00dc8a00(int value);
};
struct FUN_00dc8a20_impl
{
    virtual void FUN_00dc8a20_0();
    virtual void FUN_00dc8a20_1();
    virtual void FUN_00dc8a20_2();
    virtual void FUN_00dc8a20_3();
    virtual void FUN_00dc8a20_4(int value);
};
struct FUN_00dc8a20_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc8a20_impl* m_20;
    int m_24;

    void setSize(int value);
};
struct FUN_00dc8a40_Inner
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    virtual int getSize();
    virtual int FUN_00dc8a40_b();
    virtual int FUN_00dc8a40_c();
    virtual int FUN_00dc8a40_d();
    virtual int FUN_00dc8a40_e();
    virtual int FUN_00dc8a40_f();
};
struct FUN_00dc8a40_Class
{
    char m_data[0x20];
    FUN_00dc8a40_Inner* m_p20;
    int m_24;
    int getSize();
};
struct FUN_00dc9a20_Allocator
{
    virtual void FUN_00dc9a20_0() = 0;
    virtual void FUN_00dc9a20_1() = 0;
    virtual void FUN_00dc9a20_Deallocate(void* object, unsigned short size) = 0;
};
struct FUN_00dc9a20_Router
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void* m_pc;
    FUN_00dc9a20_Allocator* m_pThreadAllocator;
};
FUN_00dc9a20_Router* _D1A0E0GetMemoryRouter();
struct FUN_00dc9a20_class
{
    void* m_p0;
    unsigned short m_iElementCount;

    void __thiscall FUN_00dc96a0();
    unsigned long* __thiscall FUN_00dc9a20(unsigned long flags);
};
struct FUN_00dc9ad0_class
{
    char m_000[0x0c];
    float* m_p0c;
    char m_010[0x08];
    int m_18;

    void __thiscall CopyRow(int multiplier, const float* source);
};
struct FUN_00dca080_StandIn
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int* m_iThirdValue;
    int __thiscall FUN_00dca080(int i);
};
extern int DAT_010d7114;
struct FUN_00dca260_Class
{
    int m0;
    unsigned short m4;
    unsigned short m6;
    int m8;
    int mc;
    int m10;
    int m14;
    FUN_00dca260_Class();
};
struct FUN_00dca280_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    __int64* m_iThirdValue;
    int __thiscall asInt(int index);
};
struct FUN_00dca290_StandIn
{
    void* m_00;
    void* m_04;
    void* m_08;
    __int64* m_0c;
    void __thiscall FUN_00dca290(int index, int value);
};
extern int DAT_010d71ac;
struct FUN_00dca5a0_Class
{
    void* m0;
    unsigned short m4;
    unsigned short m6;
    int m8;
    int m12;
    int m16;
    int m20;
    FUN_00dca5a0_Class();
};
extern int DAT_010d7244;
struct FUN_00dca650
{
    int* m0;
    unsigned short m4;
    unsigned short m6;
    int m8;
    int m12;
    int m16;
    int m20;

    FUN_00dca650();
};
struct FUN_00dcb120_InternedString
{
    int m_iOwnerObjectOffset;
};
struct FUN_00dcb120_Inner
{
    void* m0;
    void* m4;
    void* m8;
    int m_iThirdValue;
    int m_10;
};
struct FUN_00dcb120_Class
{
    void* m0;
    void* m4;
    void* m8;
    FUN_00dcb120_Inner* m_iThirdValue;
    int __thiscall HasMember(int member);
};
struct FUN_00dcb250_item
{
    virtual void FUN_00dcb250_item_v0();
    virtual void FUN_00dcb250_item_v1();
    virtual void FUN_00dcb250_item_v2();
    virtual void FUN_00dcb250_item_call(void* arg);
};
struct FUN_00dcb250_entry
{
    void* m_iWordAt00;
    FUN_00dcb250_item* m_iWordAt04;
};
struct FUN_00dcb250_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    FUN_00dcb250_entry* m_iThirdValue;
    int m_10;

    void CallItems(void* arg);
};
struct FUN_00dcb280_Elem
{
    virtual void FUN_00dcb280_0();
    virtual void FUN_00dcb280_1();
    virtual void FUN_00dcb280_2();
    virtual void FUN_00dcb280_3();
    virtual void FUN_00dcb280_4(int value);
};
struct FUN_00dcb280_Item
{
    void* m_00;
    FUN_00dcb280_Elem* m_04;
};
struct FUN_00dcb280_Class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dcb280_Item* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;

    void FUN_00dcb280(int value);
};
struct FUN_00dc9570_StandIn
{
    void __thiscall FUN_00dc9570(int a, int b);
};
struct FUN_00dcb320_Class
{
    int m_00;
    int m_04;
    int m_08;
    char* m_0c;
    int CallWithArgs(int a, int b);
};
struct FUN_00dcb3a0_Entry
{
    void* m_iWordAt00;
    void* m_cByteAtOffset1;
};
struct FUN_00dcb3a0_Element
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18()
    {}
    virtual void f19()
    {}
    virtual void f20()
    {}
    virtual void f21()
    {}
    virtual int f22(int value)
    {
        return value;
    }
};
struct FUN_00dcb3a0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    FUN_00dcb2b0_StandIn* m_iThirdValue;
    int m_10;

    int __thiscall FUN_00dcb3a0(int index);
};
struct FUN_00dcb3d0_virtual
{
    virtual int f00(int) = 0;
    virtual int f01(int) = 0;
    virtual int f02(int) = 0;
    virtual int f03(int) = 0;
    virtual int f04(int) = 0;
    virtual int f05(int) = 0;
    virtual int f06(int) = 0;
    virtual int f07(int) = 0;
    virtual int f08(int) = 0;
    virtual int f09(int) = 0;
    virtual int f10(int) = 0;
    virtual int f11(int) = 0;
    virtual int f12(int) = 0;
    virtual int f13(int) = 0;
    virtual int f14(int) = 0;
    virtual int f15(int) = 0;
    virtual int f16(int) = 0;
};
struct FUN_00dcb3d0_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dcb2b0_StandIn* m_0c;
    int m_10;
    __int64 __thiscall CallVirtualOnElement(int);
};
struct FUN_00dcb400_Target
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void target(int value) = 0;
};
struct FUN_00dcb400_Class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dcb2b0_StandIn* m_0c;
    int m_10;
    void __thiscall DispatchToIndexedTarget(int value);
};
struct FUN_00dcb6f0_Object
{
// @fnv 0x00dcb6f0
    virtual void FUN_00dcb6f0_0()
    {}
    virtual void FUN_00dcb6f0_1()
    {}
    virtual void FUN_00dcb6f0_2()
    {}
    virtual void FUN_00dcb6f0_3()
    {}
    virtual void FUN_00dcb6f0_4()
    {}
    virtual void FUN_00dcb6f0_5()
    {}
    virtual void FUN_00dcb6f0_6()
    {}
    virtual void FUN_00dcb6f0_7()
    {}
    virtual void FUN_00dcb6f0_8()
    {}
    virtual void FUN_00dcb6f0_9()
    {}
    virtual void FUN_00dcb6f0_10()
    {}
    virtual void FUN_00dcb6f0_11(int, int)
    {}
};
struct FUN_00dcb5d0_Entry
{
    void* m_p0;
    FUN_00dcb6f0_Object* m_p4;
};
struct FUN_00dcb5d0_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    FUN_00dcb5d0_Entry* m_iThirdValue;
    int __thiscall FUN_00dcb5d0(int);
};
struct FUN_00dcb6f0_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    FUN_00dcb5d0_Class* m_iThirdValue;
    int m_10;
    void __thiscall FUN_00dcb6f0(int, int);
};
void __thiscall FUN_00dcb6f0_Class::FUN_00dcb6f0(int arg0, int arg1)
{
    int index = m_iThirdValue->FUN_00dcb5d0(arg0);
    m_iThirdValue->m_iThirdValue[index].m_p4->FUN_00dcb6f0_11(m_10, arg1);
}
struct FUN_00dcb790_Element;
struct FUN_00dcb790_Pair
{
    void* m_iWordAt00;
    FUN_00dcb790_Element* m_iWordAt04;
};
struct FUN_00dcb790_Element
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9(int a, int b)
    {}
};
struct FUN_00dcb5d0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    FUN_00dcb790_Pair* m_iThirdValue;

    __declspec(noinline) int __thiscall FUN_00dcb5d0(int a)
    {
        return 0;
    }
};
struct FUN_00dcb790_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    FUN_00dcb5d0_class* m_iThirdValue;
    int m_10;

    void __thiscall DispatchToElement(int a, int b, int c);
};
struct FUN_00dc6fe0_inner
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
};
struct FUN_00dc6fe0_cls
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00dc6fe0_inner* m_0c;
    int FUN_00dc6fe0();
};
struct FnvCpu_FUN_00dc7390_CpuTarget
{
    void FUN_00dc9240();
};
struct FnvCpu_FUN_00dc7390_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    FnvCpu_FUN_00dc7390_CpuTarget* target;
    void FUN_00dc7390();
};
struct CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void Invoke();
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    CpuInterface* target;
    void FUN_00dc89e0();
};
struct FUN_00dc9b00_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int getSize();
};
struct FUN_00dc9b10_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    void FUN_00dc9b10();
};
struct FUN_00dc70c0_Target
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual int V10(unsigned char* pucData);
};
struct FUN_00dc70c0_Holder
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc70c0_Target* m_20;
};
struct FUN_00dc70c0_cls
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dc70c0_Holder* m_0c;
    unsigned char* m_10;

    int FUN_00dc70c0(int iOffset);
};
struct FUN_00dc7130_Target
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual int V13(unsigned char* pucData, float fValue);
};
struct FUN_00dc7130_Holder
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc7130_Target* m_20;
};
struct FUN_00dc7130_cls
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dc7130_Holder* m_0c;
    unsigned char* m_10;

    int FUN_00dc7130(int iOffset, float fValue);
};
struct DispatchInterface
{
    virtual int slot00() = 0;
    virtual int slot04() = 0;
    virtual int slot08() = 0;
    virtual int slot0c() = 0;
    virtual int slot10() = 0;
    virtual int slot14() = 0;
    virtual int slot18() = 0;
    virtual int slot1c() = 0;
    virtual int slot20() = 0;
    virtual int slot24() = 0;
    virtual int slot28() = 0;
    virtual int slot2c() = 0;
    virtual int slot30() = 0;
    virtual int slot34() = 0;
    virtual int slot38() = 0;
    virtual int slot3c() = 0;
    virtual int Dispatch(int address) = 0;
};
struct DispatchHolder
{
    void* member00;
    void* member04;
    void* member08;
    void* member0c;
    void* member10;
    void* member14;
    void* member18;
    void* member1c;
    DispatchInterface* volatile member20;
};
struct DispatchAdapter
{
    void* member00;
    void* member04;
    void* member08;
    DispatchHolder* member0c;
    int member10;
    int DispatchAtOffset(int offset);
};
struct FUN_00dc71d0_target
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual int v19(int, int, int) = 0;
};
struct FUN_00dc71d0_holder
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc71d0_target* m_20;
};
struct FUN_00dc71d0_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dc71d0_holder* m_0c;
    int m_10;

    int InvokeTargetVirtual(int a, int b, int c);
};
class hkStreamDC72
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual int seekTo(int iOffset);
    virtual void V21();
    virtual int tellFrom(int iOffset);
};
struct hkStreamHolderDC72
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkStreamDC72* m_stream;
};
class hkSubStreamDC72
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStreamHolderDC72* m_holder;
    int m_baseOffset;

    int SeekTo(int iOffset);
};
class hkStreamDC7B
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual int seekTo(int iOffset);
    virtual void V21();
    virtual int tellFrom(int iOffset);
};
struct hkStreamHolderDC7B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkStreamDC7B* m_stream;
};
class hkSubStreamDC7B
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStreamHolderDC7B* m_holder;
    int m_baseOffset;

    int TellFromOffset(int iOffset);
};
struct DC7300Callee
{
    void* GetValue(void* a, int b);
};
class DC7300Owner
{
  public:
    int unk00;
    int unk04;
    DC7300Callee* m_callee;

    void* FUN_00dc7300(void* p);
};
struct FUN_00dc92d0_Obj
{
    int __thiscall CollectShapes(int a, int b, int c, int* d);
};
struct FUN_00dc73a0_Holder
{
    int unk00;
    int unk04;
    FUN_00dc92d0_Obj* unk08;
    void __thiscall CallWithReset(int a, int* b);
};
struct FUN_00dc92d0_StandIn
{
    int CollectShapes(int, int, int, int);
};
struct FUN_00dc73c0_class
{
    void* m0;
    void* m4;
    FUN_00dc92d0_StandIn* m8;
    int InitAndRun(int a, int b);
};
struct hkAllocatorDC76
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterDC76
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0C;
    hkAllocatorDC76* m_pkHeap;
    hkAllocatorDC76& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterDC76* __cdecl FUN_00c85750() throw();
extern "C" char* __cdecl FUN_00cb1410(const char* pcStr) throw();
template <typename T> struct hkArrayDC76
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayDC76() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrayDC76() throw()
    {
        hkAllocatorDC76& kAlloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};
class FUN_00d47a80_class
{
  public:
    void* GetValue(const void* pvKey, int iDefault) throw();
    void FUN_00d874d0(const char* pcKey, const void* pvValue) throw();
};
class hkDataClassImplDC76;
class hkDataObjectImplDC76;
class hkDataArrayImplDC76;
class hkDataClassImplDC76
{
  public:
    void FUN_00dc9470(const char* pcName) throw();
};
class hkDataObjectImplDC76
{
  public:
    void FUN_00dc90f0(const char* pcName) throw();
};
class hkDataArrayImplDC76
{
  public:
    void FUN_00dc8ea0(const char* pcName) throw();
};
class FUN_00dba680_cls
{
  public:
    hkDataClassImplDC76* m_pClassImpl;
    const void* FUN_00dba680() throw();
};
class hkDataWorldImplDC76
{
  public:
    int m_00[0x13];
    FUN_00d47a80_class m_stringPool;

    void CollectShapes(const void* pvClass, int iRecurse, int iUnk,
                       hkArrayDC76<hkDataObjectImplDC76*>& kObjectsOut) throw();
    void FUN_00dc9180(hkDataClassImplDC76* pkClass, int iRecurse,
                      hkArrayDC76<hkDataArrayImplDC76*>& kArraysOut) throw();

    const char* InternString(const char* pcStr)
    {
        if (pcStr)
        {
            const char* pcPooled = (const char*)m_stringPool.GetValue(pcStr, 0);
            if (pcPooled == 0)
            {
                pcPooled = FUN_00cb1410(pcStr);
                m_stringPool.FUN_00d874d0(pcPooled, pcPooled);
            }
            return pcPooled;
        }
        return 0;
    }
    void GetObjectsOfClass(const void* pvClass, hkArrayDC76<hkDataObjectImplDC76*>& kObjectsOut)
    {
        kObjectsOut.clear();
        CollectShapes(pvClass, 1, 0, kObjectsOut);
    }
};
class hkDataWorldDC76
{
  public:
    int m_00;
    int m_04;
    hkDataWorldImplDC76* m_pClassImpl;

    void FUN_00dc7600(FUN_00dba680_cls& kClass, const char* pcName) throw();
};
struct FUN_00dcab50_StandIn
{
    int m0;
    int m4;
    int m8;
    void __thiscall FUN_00dcab50(int a, int b);
};
struct FUN_00dc7dc0_StandIn
{
    int m0;
    int m4;
    int m8;
    void __thiscall FUN_00dc7dc0(int a, int b);
};
struct hkRefObjDC88
{
    virtual void deletingDtor(unsigned int flags);
    int unk04;
    int m_iObjectReferenceCount;
};
struct FUN_00dba660
{
    hkRefObjDC88* m_ptr;
    ~FUN_00dba660() throw();
};
struct FUN_00dba650 : public FUN_00dba660
{
    FUN_00dba650(hkRefObjDC88* p) throw();
};
struct FUN_00dcbdd0_cls
{
    void FUN_00dcbdd0(hkRefObjDC88* p);
};
struct hkObjDC88
{
    int unk00;
    int unk04;
    FUN_00dcbdd0_cls* m_08;

    void ReleaseRef(FUN_00dba660& handle);
};
struct FUN_00dc8fe0_entry
{
    int key;
    int next;
};
struct FUN_00dc8fe0_class
{
    FUN_00dc8fe0_entry* m_iWordAt00;

    void FUN_00dcb4b0(void* key, int index);
    void __thiscall FUN_00dc8fe0(void* key, int* value);
};
int __stdcall LookupWithDefault(void* key);
struct hkMapPairDC90
{
    int key;
    int val;
};
struct FUN_00cb18f0_t
{
    hkMapPairDC90* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int FindSlot(int key);
    int RemoveEntry(int it);
};
struct hkLinkDC90
{
    int m_uiFilterValue;
    int m_next;
};
class hkMultiMapDC90
{
  public:
    hkLinkDC90* m_ppLinks;
    int unk04;
    int unk08;
    FUN_00cb18f0_t m_pHashFunction;
    int m_kFreeListEntries;

    void RemoveKey(int key);
};
struct FUN_00dc9710_Obj
{
    void __thiscall FUN_00dc9710(int* out, int value, int count);
};
struct FUN_00dc97f0_Class : public FUN_00dc9710_Obj
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;

    void __thiscall SetSlotValue(int index, void* value);
};
struct FUN_00dc9830_Object
{
    virtual void vf00();
    virtual int vf04();
    int m_08;
};
struct FUN_00dc9830_Local
{
    int unk00;
    int unk04;
};
struct FUN_00dc9830_Class
{
    void* m_00;
    void* m_04;
    int m_08;
    void* m_0c;
    void* m_10;

    void __thiscall FUN_00dc9710(void* a, int b, int c);
    void __thiscall AddObjectToSlot(int value, FUN_00dc9830_Object* obj);
};
extern "C" char* __cdecl FUN_00cb1410(const char* pcString);
struct hkResultDC98
{
    void* m_item;
    int m_uiEdgeIndex;
    hkResultDC98()
    {}
};
struct hkEntryDC98
{
    int m_key;
    int m_04;
    char* m_uiFilterValue;
    int m_0c;
};
class hkObjDC98
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkEntryDC98* m_entries;

    hkResultDC98 FUN_00dc9710(int iKey, int iType) throw();
    void SetStringEntry(int iKey, const char* pcValue) throw();
};
struct FUN_00dc98d0_Local
{
    float value;
    int index;
};
struct FUN_00dc98d0_StandIn
{
    void* m0;
    void* m4;
    void* m8;
    void* mc;
    void* m10;

    void FUN_00dc9710(float* out, int a, int b);
    void SetValueAt(int index, float value);
};
struct hkHalfDC99
{
    short m_uiFilterValue;
    operator float() const
    {
        int t = m_uiFilterValue << 16;
        return *reinterpret_cast<float*>(&t);
    }
};
struct hkResultDC99
{
    void* m_item;
    int m_uiEdgeIndex;
    hkResultDC99()
    {}
};
struct hkEntryDC99
{
    int m_key;
    int m_04;
    float m_uiFilterValue;
    int m_0c;
};
class hkObjDC99
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkEntryDC99* m_entries;

    hkResultDC99 FUN_00dc9710(int iKey, int iType) throw();
    void SetEntryValue(int iKey, hkHalfDC99 kValue) throw();
};
struct hkMemberInfoDC99
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_type;
};
struct hkResultDC99C
{
    hkMemberInfoDC99* m_item;
    int m_uiEdgeIndex;
    hkResultDC99C()
    {}
};
struct hkEntryDC99C
{
    int m_key;
    int m_04;
    union
    {
        __int64 m_int;
        float m_vValue;
    };
};
class hkObjDC99C
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkEntryDC99C* m_entries;

    hkResultDC99C FUN_00dc9710(int iKey, int iType) throw();
    void assign(int iKey, __int64 iValue) throw();
};
class hkBaseDC9A
{
  public:
    hkBaseDC9A() : m_06(0), m_08(0)
    {}
    virtual ~hkBaseDC9A() throw();

    unsigned short m_04;
    unsigned short m_06;
    int m_08;
};
template <class T> class hkArrayDC9A
{
  public:
    hkArrayDC9A() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class FUN_00dc9a50 : public hkBaseDC9A
{
  public:
    FUN_00dc9a50(int iArg) throw();
    virtual ~FUN_00dc9a50() throw();

    hkArrayDC9A<int> m_ppData;
    int m_18;
};
struct FUN_00dc9a80_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_type;

    int GetTypeCode() const;
};
extern "C" void __movsd(unsigned long* pDst, const unsigned long* pSrc, unsigned int ItemUpdateArray);
class hkMemoryAllocatorDC9D;
struct hkMemoryRouterDC9D
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDC9D* m_pStreamAllocator;

    hkMemoryAllocatorDC9D& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDC9D {
extern "C" hkMemoryRouterDC9D& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorDC9D& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
inline void memCpy4DC9D(void* pvDst, const void* pvSrc, unsigned int iNumWords)
{
    __movsd((unsigned long*)pvDst, (const unsigned long*)pvSrc, iNumWords);
}
struct hkPairDC9D
{
    int m_kPointA;
    int m_kPointB;
};
template <class T> class hkArrayDC9D
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorDC9D& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void _setSizeZero(hkMemoryAllocatorDC9D& kAlloc, int n)
    {
        reserve(kAlloc, n);
        int iNumToFill = n - m_iElementCount;
        T* pDst = m_data + m_iElementCount;
        if (iNumToFill > 0)
        {
            pDst[0].m_kPointA = 0;
            pDst[0].m_kPointB = 0;
            memCpy4DC9D(pDst + 1, pDst, ((iNumToFill - 1) * sizeof(T) + 3) >> 2);
        }
        m_iElementCount = n;
    }
    __forceinline void setSizeZero(int n)
    {
        _setSizeZero(hkRouterDC9D::FUN_00c85750().heap(), n);
    }
};
class hkObjDC9D
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkArrayDC9D<hkPairDC9D> m_pairs;

    void SetPairCount(int n);
};
class hkMemoryAllocatorDC9F
{
  public:
    virtual ~hkMemoryAllocatorDC9F() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterDC9F
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDC9F* m_pStreamAllocator;
    hkMemoryAllocatorDC9F& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDC9F {
extern "C" hkMemoryRouterDC9F& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayDC9F
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorDC9F& kAlloc = hkRouterDC9F::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
class hkRefObjDC9F
{
  public:
    virtual ~hkRefObjDC9F() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkBufferDC9F : public hkRefObjDC9F
{
  public:
    int unk08;
    hkArrayDC9F<void*> m_data;

    virtual ~hkBufferDC9F() throw()
    {
        m_data.ClearAndRelease();
    }

    static void operator delete(void* p) throw()
    {
        hkRouterDC9F::FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkBufferDC9F*>(p)->m_usMemSizeAndFlags);
    }
    hkBufferDC9F* FUN_00dc9fd0(unsigned int uiFlags) throw();
};
class hkRefDCA0
{
  public:
    virtual ~hkRefDCA0();
    int unk04;
    int m_iObjectReferenceCount;

    void addRef()
    {
        ++m_iObjectReferenceCount;
    }
    void release()
    {
        if (--m_iObjectReferenceCount == 0)
            delete this;
    }
};
class hkHolderDCA0
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkRefDCA0** m_kTrackedObjects;

    void SetElement(int i, hkRefDCA0* p);
};
struct FUN_00dca1e0_class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char* unk0C;
    unsigned int FUN_00dca1e0(int index);
};
struct hkEntryDCA2
{
    int m_kPointA;
    int m_kPointB;
};
class hkObjDCA2
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkEntryDCA2* m_entries;

    void FUN_00dca2d0(int i, hkEntryDCA2 e);
};
class hkMemoryAllocatorDCA3;
struct hkMemoryRouterDCA3
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorDCA3* m_pTemp;
    hkMemoryAllocatorDCA3* m_pStreamAllocator;
    hkMemoryAllocatorDCA3& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDCA3 {
extern "C" hkMemoryRouterDCA3& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorDCA3& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
template <class T> class hkArrayDCA3
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorDCA3& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterDCA3::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};
struct hkBoolDCA3
{
    char m_cBooleanValue;
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
class hkObjDCA3
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkArrayDCA3<__int64> m_iSlotIds;

    void CopyBoolArray(const hkBoolDCA3* src, int n);
};
class hkMemoryAllocatorDCA4;
struct hkMemoryRouterDCA4
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorDCA4* m_pTemp;
    hkMemoryAllocatorDCA4* m_pStreamAllocator;
    hkMemoryAllocatorDCA4& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDCA4 {
extern "C" hkMemoryRouterDCA4& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorDCA4& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
template <class T> class hkArrayDCA4
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorDCA4& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterDCA4::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};
class hkObjDCA4
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkArrayDCA4<__int64> m_iSlotIds;

    void CopyShortsToArray(const short* src, int n);
};
void __cdecl FUN_00cb13c0(int iString);
extern "C" char* __cdecl FUN_00cb1410(const char* pcString);
class hkObjDCA6
{
  public:
    int unk00;
    int unk04;
    int unk08;
    char** m_pStringFunctions;

    void SetStringAt(int i, const char* pcValue);
};
class hkMemoryAllocatorDCA6
{
  public:
    virtual ~hkMemoryAllocatorDCA6() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterDCA6
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCA6* m_pStreamAllocator;
    hkMemoryAllocatorDCA6& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDCA6 {
extern "C" hkMemoryRouterDCA6& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayDCA6
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorDCA6& kAlloc = hkRouterDCA6::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
class hkRefObjDCA6
{
  public:
    virtual ~hkRefObjDCA6() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
void __cdecl FUN_00cb13c0(int p) throw();
class FUN_00dca6b0 : public hkRefObjDCA6
{
  public:
    int unk08;
    hkArrayDCA6<int> m_pStringFunctions;

    virtual ~FUN_00dca6b0() throw();
};
class hkMemoryAllocatorDCA7
{
  public:
    virtual ~hkMemoryAllocatorDCA7() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterDCA7
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCA7* m_pStreamAllocator;
    hkMemoryAllocatorDCA7& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDCA7 {
extern "C" hkMemoryRouterDCA7& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayDCA7
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorDCA7& kAlloc = hkRouterDCA7::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
class hkRefObjDCA7
{
  public:
    virtual ~hkRefObjDCA7() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkBufferDCA7 : public hkRefObjDCA7
{
  public:
    int unk08;
    hkArrayDCA7<char> m_data;

    virtual ~hkBufferDCA7() throw()
    {
        m_data.ClearAndRelease();
    }

    static void operator delete(void* p) throw()
    {
        hkRouterDCA7::FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkBufferDCA7*>(p)->m_usMemSizeAndFlags);
    }
    hkBufferDCA7* FUN_00dca750(unsigned int uiFlags) throw();
};
class hkMemoryAllocatorDCB7
{
  public:
    virtual ~hkMemoryAllocatorDCB7() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterDCB7
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCB7* m_pStreamAllocator;
    hkMemoryAllocatorDCB7& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDCB7 {
extern "C" hkMemoryRouterDCB7& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayDCB7
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorDCB7& kAlloc = hkRouterDCB7::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
class hkRefObjDCB7
{
  public:
    virtual ~hkRefObjDCB7() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkBufferDCB7 : public hkRefObjDCB7
{
  public:
    int unk08;
    hkArrayDCB7<__int64> m_data;

    virtual ~hkBufferDCB7() throw()
    {
        m_data.ClearAndRelease();
    }

    static void operator delete(void* p) throw()
    {
        hkRouterDCB7::FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkBufferDCB7*>(p)->m_usMemSizeAndFlags);
    }
    hkBufferDCB7* FUN_00dca7b0(unsigned int uiFlags) throw();
};
template <class T> class hkArrayDCAB
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayDCAB() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
class hkTypeRegistryDCAB
{
  public:
    void FUN_00dc8d70(void* pvHandleOut, int iType) throw();
};
struct hkTypeHandleDCAB
{
    int m_iOwnerObjectOffset;

    hkTypeHandleDCAB(hkTypeRegistryDCAB* pkRegistry, int iType)
    {
        pkRegistry->FUN_00dc8d70(this, iType);
    }
};
struct hkTypeOwnerDCAB
{
    int unk00;
    int unk04;
    hkTypeRegistryDCAB* m_registry;
};
class hkReferencedObjectDCAB
{
  public:
    hkReferencedObjectDCAB() : m_ulUserData(0)
    {
        m_sReferenceCount = 0;
    }
    virtual ~hkReferencedObjectDCAB() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_ulUserData;
};
class FUN_00dcabb0 : public hkReferencedObjectDCAB
{
  public:
    hkTypeOwnerDCAB* m_pOwnerObject;
    hkTypeHandleDCAB m_handle;
    int m_flags;
    int m_uiItemCount;
    hkArrayDCAB<int> m_entries;
    hkArrayDCAB<int> m_ppNames;
    hkArrayDCAB<int> m_iSlotIds;

    FUN_00dcabb0(hkTypeOwnerDCAB* pkOwner, int iType, int iFlags) throw();
    virtual ~FUN_00dcabb0() throw();
};
struct Obj00dcb210
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
};
struct Entry00dcb210
{
    int unk00;
    Obj00dcb210* p;
};
struct Cls00dcb210
{
    int unk00;
    int unk04;
    int unk08;
    Entry00dcb210* m_aiIndexedValues;
    int m_uiItemCount;
    int unk14;
    int unk18;
    int m_flag;
    void FUN_00dcb210();
};
class hkAccessorDCB3
{
  public:
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual int getInt(int obj) throw();
};
struct hkMemberDCB3
{
    const char* m_name;
    hkAccessorDCB3* m_accessor;
};
class hkImplDCB3
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberDCB3* m_members;

    int FUN_00dcb2b0(int iName) throw();
};
class hkObjDCB3
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplDCB3* m_pClassImpl;
    int m_10;

    int GetMemberInt(int iName, int iUnused) throw();
};
class hkObjectDCB3
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual int V10(int iValue);
};
struct hkEntryDCB3
{
    int m_key;
    hkObjectDCB3* m_object;
};
struct hkTableDCB3
{
    int m_00;
    int m_04;
    int m_08;
    hkEntryDCB3* m_entries;

    int FUN_00dcb2b0(int iKey);
};
class hkOwnerDCB3
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkTableDCB3* m_table;
    int m_10;

    int FUN_00dcb370(int iKey);
};
struct hkValueDCB4
{
    int m_00;
    int m_04;
    hkValueDCB4()
    {}
};
class hkAccessorDCB4
{
  public:
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual void v08() throw();
    virtual void v09() throw();
    virtual void v10() throw();
    virtual void v11() throw();
    virtual void v12() throw();
    virtual void v13() throw();
    virtual hkValueDCB4 getValue(int obj) throw();
};
struct hkMemberDCB4
{
    const char* m_name;
    hkAccessorDCB4* m_accessor;
};
class hkImplDCB4
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberDCB4* m_members;

    int FUN_00dcb2b0(int iName) throw();
};
class hkObjDCB4
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplDCB4* m_pClassImpl;
    int m_10;

    hkValueDCB4 GetMemberValue(int iName) throw();
};
struct hkPairDCB6
{
    int m_00;
    int m_04;
};
class hkAccessorDCB6
{
  public:
    void FUN_00dcaf70(int obj, hkPairDCB6 v) throw();
};
struct hkMemberDCB6
{
    const char* m_name;
    hkAccessorDCB6* m_accessor;
};
class hkImplDCB6
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberDCB6* m_members;

    int FUN_00dcb5d0(int iName) throw();
};
class hkObjDCB6
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplDCB6* m_pClassImpl;
    int m_10;

    void FUN_00dcb650(int iName, const hkPairDCB6& v) throw();
};
struct FUN_00dcb690_Object
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21(int, int);
};
struct FUN_00dcb690_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    FUN_00dcb5d0_Class* m_iThirdValue;
    int m_10;
    void __thiscall DispatchToIndexedObject(int a, int b);
};
struct FUN_00dcb6c0_Target
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18()
    {}
    virtual void f19()
    {}
    virtual void f20()
    {}
    virtual void f21()
    {}
    virtual void f22()
    {}
    virtual void FUN_00dcb650(int a, int b)
    {}
};
struct FUN_00dcb6c0_Element
{
    FUN_00dcb6c0_Target* m_p0;
    void* m_p4;
};
struct FUN_00dcb6c0_Array
{
    void* m_p0;
    FUN_00dcb6c0_Element m_p4;
};
struct FUN_00dcb5d0_Obj
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    FUN_00dcb6c0_Array* m_pC;

    int __thiscall FUN_00dcb5d0(int a);
};
struct FUN_00dcb6c0_Obj
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    FUN_00dcb5d0_Obj* m_pC;
    int m_p10;

    void __thiscall FUN_00dcb6c0(int a, int b);
};
class hkAccessorXdcb720
{
  public:
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual void v08() throw();
    virtual void v09() throw();
    virtual void v10() throw();
    virtual void v11() throw();
    virtual void v12() throw();
    virtual void target(int obj, float v) throw();
};
struct hkMemberXdcb720
{
    const char* m_name;
    hkAccessorXdcb720* m_accessor;
};
class hkImplXdcb720
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberXdcb720* m_members;

    int FUN_00dcb5d0(int iName) throw();
};
class hkObjXdcb720
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplXdcb720* m_pClassImpl;
    int m_10;

    void FUN_00dcb720(int iName, float v) throw();
};
class hkAccessorXdcb760
{
  public:
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual void v08() throw();
    virtual void v09() throw();
    virtual void v10() throw();
    virtual void v11() throw();
    virtual void v12() throw();
    virtual void v13() throw();
    virtual void v14() throw();
    virtual void target(int obj, int v) throw();
};
struct hkMemberXdcb760
{
    const char* m_name;
    hkAccessorXdcb760* m_accessor;
};
class hkImplXdcb760
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberXdcb760* m_members;

    int FUN_00dcb5d0(int iName) throw();
};
class hkObjXdcb760
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplXdcb760* m_pClassImpl;
    int m_10;

    void FUN_00dcb760(int iName, int v) throw();
};
struct FUN_00dcb7c0_Object
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void FUN_00dcb7c0_17(int a, int b);
};
struct FUN_00dcb7c0_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    FUN_00dcb5d0_Class* m_iThirdValue;
    int m_10;
    void __thiscall CallObjectVirtual(int arg0, int arg1);
};
class hkAccessorXdcb7f0
{
  public:
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual void v08() throw();
    virtual void v09() throw();
    virtual void v10() throw();
    virtual void v11() throw();
    virtual void v12() throw();
    virtual void v13() throw();
    virtual void v14() throw();
    virtual void v15() throw();
    virtual void v16() throw();
    virtual void target(int obj, int v) throw();
};
struct hkMemberXdcb7f0
{
    const char* m_name;
    hkAccessorXdcb7f0* m_accessor;
};
class hkImplXdcb7f0
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberXdcb7f0* m_members;

    int FUN_00dcb5d0(int iName) throw();
};
class hkObjXdcb7f0
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplXdcb7f0* m_pClassImpl;
    int m_10;

    void FUN_00dcb7f0(int iName, short v) throw();
};
class hkAccessorXdcb820
{
  public:
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual void v08() throw();
    virtual void v09() throw();
    virtual void v10() throw();
    virtual void v11() throw();
    virtual void v12() throw();
    virtual void v13() throw();
    virtual void v14() throw();
    virtual void v15() throw();
    virtual void v16() throw();
    virtual void target(int obj, int v) throw();
};
struct hkMemberXdcb820
{
    const char* m_name;
    hkAccessorXdcb820* m_accessor;
};
class hkImplXdcb820
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberXdcb820* m_members;

    int FUN_00dcb5d0(int iName) throw();
};
class hkObjXdcb820
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplXdcb820* m_pClassImpl;
    int m_10;

    void FUN_00dcb820(int iName, int v) throw();
};
class hkObjectDCB8
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual int V19(int iOwner, int iArg0, int iArg1);
};
struct hkEntryDCB8
{
    int m_key;
    hkObjectDCB8* m_object;
};
struct hkTableDCB8
{
    int m_00;
    int m_04;
    int m_08;
    hkEntryDCB8* m_entries;

    int FUN_00dcb5d0(int iKey);
};
class hkOwnerDCB8
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkTableDCB8* m_table;
    int m_10;

    int DispatchToEntryObject(int iKey, int iArg0, int iArg1);
};
struct FUN_00dcba40_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int FUN_00dcba40(int* out, int a, int b);
    int asArray(int a);
};
struct hkResultDCB
{
    void* m_item;
    int m_uiEdgeIndex;
    hkResultDCB()
    {}
};
struct hkEntryDCB
{
    int m_key;
    int m_04;
    int m_uiFilterValue;
    int m_0c;
};
class hkObjDCB
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkEntryDCB* m_entries;

    hkResultDCB FUN_00dcba40(int iKey, int iType) throw();
    int FUN_00dcbc20(int iKey) throw();
};
struct FUN_00dcbc50_Item
{
    int unk00;
    int unk04;
    __int64 value;
};
struct FUN_00dcbc50_Argument
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int count;
};
struct FUN_00dcbc50_Result
{
    FUN_00dcbc50_Argument* entry;
    int index;
};
struct FUN_00dcbc50_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00dcbc50_Item* items;

    void FUN_00dcba40(FUN_00dcbc50_Result* result, FUN_00dcbc50_Argument* argument, int mode);
    __int64 GetItemValue(FUN_00dcbc50_Argument* argument);
};
char* __cdecl StrDup7320(const char* pcString);
struct StringMap7320
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct Registry7320
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
    StringMap7320 m_kNodePool;

    void Rename(const char* pcOldName, const char* pcNewName);
    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDup7320(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};
struct ClassInfo7320
{
    const char* GetName() const;
};
class Owner7320
{
  public:
    void FUN_00dc7320(const ClassInfo7320* pkClass, const char* pcNewName);
    int unk00;
    int unk04;
    Registry7320* m_pkRegistry;
};
static unsigned int FUN_00dc73e0(unsigned int value);
unsigned int AllocationBlockCount(unsigned int value);
struct Memory7DE0
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes);
};
struct Context7DE0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Memory7DE0* m_pkMemory;
};
Context7DE0* GetContext7DE0();
struct Shape7DE0
{
    Shape7DE0() throw() : m_usFlags(0), m_iRefCount(0)
    {}
    virtual ~Shape7DE0();
    static __forceinline void* operator new(unsigned int nbytes) throw()
    {
        Context7DE0* pkContext = GetContext7DE0();
        Shape7DE0* pkShape = static_cast<Shape7DE0*>(pkContext->m_pkMemory->allocateChunk(nbytes));
        pkShape->m_usMemSize = (unsigned short)nbytes;
        return pkShape;
    }
    void AddRef()
    {
        m_iRefCount++;
    }
    unsigned short m_usMemSize;
    unsigned short m_usFlags;
    int m_iRefCount;
};
struct Container7DE0
{
    Container7DE0() throw() : m_usFlags(0), m_iArrayLength(0)
    {}
    virtual ~Container7DE0();
    unsigned short m_usSize;
    unsigned short m_usFlags;
    int m_iArrayLength;
    void* m_pkOwnerManager;
    void AddOwner(void* pkOwner)
    {
        m_iArrayLength++;
        m_pkOwnerManager = pkOwner;
    }
};
struct Wrapper7DE0 : public Shape7DE0
{
    __forceinline Wrapper7DE0(Shape7DE0* pkChild, int iData) throw() : m_pkChild(pkChild)
    {
        int one = 1;
        m_iData = iData;
        pkChild->m_iRefCount += one;
        m_kContainer.m_iArrayLength += one;
        m_kContainer.m_pkOwnerManager = this;
    }
    Container7DE0 m_kContainer;
    int unk1C;
    Shape7DE0* m_pkChild;
    volatile int m_iData;
};
struct ShapeA7DE0 : public Shape7DE0
{
    ShapeA7DE0() throw();
    int unk0C;
    int unk10;
    int unk14;
};
struct ShapeB7DE0 : public Shape7DE0
{
    ShapeB7DE0() throw();
    int unk0C;
    int unk10;
    int unk14;
};
struct ShapeC7DE0 : public Shape7DE0
{
    ShapeC7DE0() throw();
    int unk0C;
    int unk10;
    int unk14;
};
struct ShapeD7DE0 : public Shape7DE0
{
    ShapeD7DE0(int iStride) throw();
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct ShapeE7DE0 : public Shape7DE0
{
    ShapeE7DE0(int iArg) throw();
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct ShapeF7DE0 : public Shape7DE0
{
    ShapeF7DE0(int iArg) throw();
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct ShapeG7DE0 : public Shape7DE0
{
    ShapeG7DE0() throw();
    int unk0C;
    int unk10;
    int unk14;
};
Shape7DE0* FUN_00dc7de0(unsigned int uiType, int iArg, int iData);
class hkObjDC82
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void setTarget(void* target);
};
class hkRegistryDC82
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0a();
    virtual void vfn_0b();
    virtual void vfn_0c();
    virtual void vfn_0d();
    virtual void vfn_0e();
    virtual void vfn_0f();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void registerObject(void* key, hkObjDC82* obj);
};
struct hkCtxDC82
{
    hkRegistryDC82* m_registry;
};
struct hkDescDC82
{
    void* m_key;
    int unk04;
    unsigned int m_flags;
    void* m_type;
    void* m_target;
};
hkObjDC82* __cdecl FUN_00dc7de0(unsigned int flags, void* type, void* owner);
hkObjDC82* __stdcall CreateAndRegisterObject(hkCtxDC82* ctx, hkDescDC82* desc);
struct Src80
{
    virtual void s00();
    virtual int GetType();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual int Get8(int idx);
    virtual void s09();
    virtual int Get10(int idx);
    virtual void s11();
    virtual float Get12(int idx);
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int Get16(int idx);
    virtual void s17();
    virtual __int64 Get18(int idx);
    virtual void s19();
    virtual int Get20(int idx);
};
struct Setter80
{
    virtual void t00();
    virtual void t01();
    virtual void t02();
    virtual void t03();
    virtual void t04();
    virtual void t05();
    virtual void t06();
    virtual void t07();
    virtual void t08();
    virtual void Set9(int idx, int val);
    virtual void t10();
    virtual void Set11(int idx, int val);
    virtual void t12();
    virtual void Set13(int idx, float val);
    virtual void t14();
    virtual void t15();
    virtual void t16();
    virtual void Set17(int idx, int val);
    virtual void t18();
    virtual void Set19(int idx, __int64 val);
    virtual void t20();
    virtual void Set21(int idx, int val);
    int m_s04;
    int m_s08;
    int m_s0c;
};
struct DC8A80
{
    int m_00;
    int m_04;
    int m_08;
    Setter80 m_0c;
    int m_1c;
    int m_20;
    int m_24;
    void __thiscall CopyFromSource(int a, Src80* src);
};
class hkMemoryAllocatorDC8C
{
  public:
    virtual ~hkMemoryAllocatorDC8C() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterDC8C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDC8C* m_pStreamAllocator;

    hkMemoryAllocatorDC8C& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDC8C {
extern "C" hkMemoryRouterDC8C& __cdecl FUN_00c85750() throw();
}

class hkBaseObjDC8C
{
  public:
    virtual ~hkBaseObjDC8C() throw()
    {}
};
class hkRefObjDC8C : public hkBaseObjDC8C
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    virtual ~hkRefObjDC8C() throw()
    {}

    static void operator delete(void* p)
    {
        hkRouterDC8C::FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkRefObjDC8C*>(p)->m_usMemSizeAndFlags);
    }
};
class hkSharedDC8C
{
  public:
    virtual void deleteThis(int flags) throw();
    int unk04;
    int m_uiItemCount;

    void release() throw()
    {
        if (--m_uiItemCount == 0)
            deleteThis(1);
    }
};
class hkMemberDC8C : public hkBaseObjDC8C
{
  public:
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
class hkObjDC8C : public hkRefObjDC8C
{
  public:
    int unk08;
    hkMemberDC8C m_kMemberDescriptor;
    hkSharedDC8C* m_pSharedObject;

    virtual ~hkObjDC8C() throw()
    {
        m_pSharedObject->release();
    }

    hkObjDC8C* FUN_00dc8cd0(unsigned int flags);
};
char* __cdecl FUN_00cb1410(const char* pcString);
struct StringMapDC8F20
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void remove(const char* pcKey);
    void insert(const char* pcKey, void* pvValue);

    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int m_flags;
};
struct NamedEntryDC8F20
{
    void* m_ppVirtualMethodTable;
    int m_iObjectReferenceCount;
    const char* m_name;
};
struct NameRegistryDC8F20
{
    StringMapDC8F20 m_iSlotIds;
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
    StringMapDC8F20 m_kNodePool;
    StringMapDC8F20 m_entries;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = FUN_00cb1410(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
    void FUN_00dc8f20(const char* pcOldName, const char* pcNewName);
};
struct Entry_dc90f0
{
    int key;
    int flags;
    __int64 value;
};
struct Metadata_dc90f0
{
    int unk00, unk04, unk08, unk0C;
    void* type;
};
struct Registry_dc90f0
{
    Metadata_dc90f0* FindEntry(int key);
};
void __cdecl ReleaseDataValues(void* type, __int64* value, int count);
struct Object_dc90f0
{
    int unk00, unk04, unk08;
    Registry_dc90f0* registry;
    Entry_dc90f0* entries;
    int count;

    void FUN_00dc90f0(int key);
};
class hkMemoryAllocatorDC92;
struct hkMemoryRouterDC92
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDC92* m_pStreamAllocator;
};
namespace hkRouterDC92 {
extern "C" hkMemoryRouterDC92& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();
struct hkBoolDC92
{
    char m_cBooleanValue;
    hkBoolDC92()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
template <class T> __forceinline void constructWithCopyDC92(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <class T> struct hkArrayDC92
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& e)
    {
        hkMemoryRouterDC92& router = hkRouterDC92::FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        constructWithCopyDC92<T>(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};
class hkMapDC92
{
  public:
    int FUN_00d87410();
    char* SetBoolFromThreshold(char* out, int it);
    bool isValid(int it)
    {
        char valid;
        SetBoolFromThreshold(&valid, it);
        return valid != 0;
    }
    int FUN_00d87440(int it);
    int FindNextUsedSlot(int it);

    void FUN_00dc9240(hkArrayDC92<int>& out);
};
class hkMemoryAllocatorDC9;
struct hkMemoryRouterDC9
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDC9* m_pStreamAllocator;
};
hkMemoryRouterDC9* __cdecl GetMemoryRouterDC9() throw();
void __cdecl ReserveMoreDC9(hkMemoryAllocatorDC9* pkHeap, void* pkArray, int iElemSize);
template <typename T> struct hkArrayDC9
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <typename T> inline void ConstructWithCopyDC9(T* pDst, int iCount, const T& kItem)
{
    for (int i = 0; i < iCount; ++i)
        pDst[i] = kItem;
}
template <typename T> inline void PushBackDC9(hkArrayDC9<T>& kArray, const T& kItem)
{
    hkMemoryRouterDC9* pkRouter = GetMemoryRouterDC9();
    if (kArray.m_iElementCount == (kArray.m_iCapacityState & 0x3fffffff))
        ReserveMoreDC9(pkRouter->m_pStreamAllocator, &kArray, sizeof(T));
    ConstructWithCopyDC9(kArray.m_data + kArray.m_iElementCount, 1, kItem);
    kArray.m_iElementCount++;
}
class ShapeDC9
{
};
class ShapeGroupDC9
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual int GetNumShapes();
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
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual ShapeDC9* GetShape(int iIndex);
};
struct KeyDC9;
class LinkDC9
{
  public:
    virtual void v00();
    virtual void v04();
    virtual KeyDC9* GetKey();
};
struct OwnerDC9;
OwnerDC9* __stdcall FindOwnerDC9(KeyDC9* pkKey, int iFlags);
template <class T> struct MultiMapDC9
{
    struct Entry
    {
        T m_kValue;
        int m_iNext;
    };
    int Find(OwnerDC9* pkOwner);
    Entry* m_pkEntryArray;
};
class ShapeRegistryDC9
{
  public:
    void CollectShapes(KeyDC9* pkKey, int bRecurse, int bGroups, hkArrayDC9<ShapeDC9*>* pkShapesOut);
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    MultiMapDC9<LinkDC9*> m_kLinks;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    MultiMapDC9<ShapeDC9*> m_kShapes;
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
    MultiMapDC9<ShapeGroupDC9*> m_kObjectGroups;
};
char* __cdecl StrDup9570(const char* pcString);
struct StringMap9570
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct Registry9570
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
    StringMap9570 m_kNodePool;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDup9570(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};
struct RegistryHolder9570
{
    int unk00;
    int unk04;
    Registry9570* m_pkRegistry;
};
struct PooledName9570
{
    PooledName9570(const char* pcName)
    {
        m_pcName = pcName;
    }
    const char* m_pcName;
};
class Owner9570
{
  public:
    PooledName9570 FUN_00dc9570(const char* pcName);
    int unk00;
    int unk04;
    int unk08;
    RegistryHolder9570* m_pkHolder;
};
class hkMemoryAllocatorDC9E;
struct hkMemoryRouterDC9E
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDC9E* m_pStreamAllocator;

    hkMemoryAllocatorDC9E& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDC9E {
extern "C" hkMemoryRouterDC9E& __cdecl FUN_00c85750() throw();
}

class hkMapDC9E
{
  public:
    unsigned long LookupHashEntry(unsigned long key, unsigned long def);
    void FUN_00cb1870(hkMemoryAllocatorDC9E& alloc, unsigned long key, unsigned long val);
    int unk00[2];
};
struct KeyDC9E
{
    unsigned long m_iOwnerObjectOffset;
};
struct EntryDC9E
{
    unsigned long m_iOwnerObjectOffset;
    unsigned long m_next;
};
class OwnerDC9E
{
  public:
    EntryDC9E* m_pEntries;
    int unk04[2];
    hkMapDC9E m_kFormatEntries;

    int AllocateSlot();
    void FUN_00dc9ec0(unsigned long key, const KeyDC9E* pkVal);
};
extern int DAT_010d6fe4;
extern "C" void _ReadWriteBarrier(void);
struct FUN_00dca040_class
{
    void* m0;
    unsigned short m4;
    unsigned short m6;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    void* __thiscall Init(void* arg);
};
class hkMemoryAllocatorDCA5;
struct hkMemoryRouterDCA5
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorDCA5* m_pTemp;
    hkMemoryAllocatorDCA5* m_pStreamAllocator;
    hkMemoryAllocatorDCA5& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace fnvc_adapt {
extern "C" hkMemoryRouterDCA5& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorDCA5& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
template <class T> class hkArrayDCA5
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorDCA5& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(fnvc_adapt::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};
class hkObjDCA5
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkArrayDCA5<__int64> m_data;

    void CopyFrom(const __int64* src, int n);
};
class Obj
{
  public:
    virtual void v0();
    virtual void v1();
    virtual const char* getName();
    virtual void v3();
    virtual void* GetIteratorKey();
};
struct Find
{
    char* SetBoolFromThreshold(char*, int);
};
struct Add
{
    void FUN_00d874d0(const char*, int);
};
struct Map
{
    void FUN_00dc9ec0(void*, Obj**);
};
struct Registry
{
    int a, b, c, d;
    Map map;
    int FindStringKey(const char*);
    void RegisterObject(Obj* volatile obj);
};
struct DCAAObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* GetIteratorKey();
};
struct DCAAMapEntry
{
    DCAAObject* value;
    int next;
};
struct DCAAMap
{
    DCAAMapEntry* entries;
    int __thiscall LookupWithDefault(void* key);
    void __thiscall FUN_00dcb4b0(void* key, int index);
    void __thiscall FUN_00dc9ec0(void* key, DCAAObject** value);
};
struct DCAAOwner
{
    int unk00, unk04, unk08, unk0c;
    DCAAMap table;
    void __thiscall FUN_00dcaaf0(void* volatile key, DCAAObject* object);
};
char* __cdecl StrDupDCAC(const char* pcString);
struct hkBoolDCAC
{
    hkBoolDCAC(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    char m_cBooleanValue;
};
struct StringMapDCAC
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct RegistryDCAC
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
    StringMapDCAC m_kNodePool;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDupDCAC(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};
class ClassDCAC
{
  public:
    virtual void v00();
    virtual void v04();
    virtual const char* GetName() const;
    virtual void v0c();
    virtual const ClassDCAC* GetParent() const;
};
struct RegistryHolderDCAC
{
    int unk00;
    int unk04;
    RegistryDCAC* m_pkRegistry;
};
struct NameHolderDCAC
{
    int unk00;
    int unk04;
    const char* m_pcName;
};
class CheckerDCAC
{
  public:
    hkBoolDCAC FUN_00dcac80(const ClassDCAC* pkClass);

    int unk00;
    int unk04;
    int unk08;
    RegistryHolderDCAC* m_pkHolder;
    NameHolderDCAC* m_pkTarget;
};
char* __cdecl StrDupADA0(const char* pcString);
struct StringMapADA0
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct RegistryADA0
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
    StringMapADA0 m_kNodePool;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDupADA0(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};
struct RegistryHolderADA0
{
    int unk00;
    int unk04;
    RegistryADA0* m_pkRegistry;
};
struct MemberADA0
{
    const char* m_pcName;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
class ClassADA0
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual int GetNumDeclaredOffset() const;
    virtual void v1c();
    virtual void v20();
    virtual int GetMemberBase() const;
    int getMemberIndexByName(const char* pcName) const;

    int unk04;
    int unk08;
    RegistryHolderADA0* m_pkHolder;
    int unk10;
    int unk14;
    const ClassADA0* m_pParentNode;
    int unk1c;
    int unk20;
    int unk24;
    MemberADA0* m_pkMembers;
    int m_iNumMembers;
};
struct PairDCB1
{
    int iFirst;
    int iSecond;
};
class SourceDCB1
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual PairDCB1 v03(int iKey);
};
class TargetDCB1
{
  public:
    void FUN_00dcaf70(void* pArg, PairDCB1 kPair);
};
struct EntryDCB1
{
    int iKey;
    TargetDCB1* pkTarget;
};
class FUN_00dcb1c0_C
{
  public:
    int unk00;
    int unk04;
    int unk08;
    EntryDCB1* m_pEntries;
    int m_iNumEntries;

    void ApplySourceToEntries(void* pArg, SourceDCB1* pkSource);
};
char* __cdecl StrDupB2B0(const char* pcString);
struct StringMapB2B0
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct RegistryB2B0
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
    StringMapB2B0 m_kNodePool;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDupB2B0(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};
struct RegistryHolderB2B0
{
    int unk00;
    int unk04;
    RegistryB2B0* m_pkRegistry;
};
struct ContextB2B0
{
    int unk00;
    int unk04;
    int unk08;
    RegistryHolderB2B0* m_pkHolder;
};
struct EntryB2B0
{
    const char* m_pcName;
    int m_iValue;
};
class TableB2B0
{
  public:
    int FUN_00dcb2b0(const char* pcName);
    int unk00;
    int unk04;
    int unk08;
    EntryB2B0* m_pkEntryArray;
    int m_iNumEntries;
    int unk14;
    ContextB2B0* m_pkContext;
};
struct HeapDCB990
{
    virtual void v00();
    virtual void v04();
    virtual void ReleaseBlock(void* p, int nbytes) throw();
    virtual void v0C();
    virtual void ReturnMemory(void* p, int nbytes) throw();
};
struct RouterDCB990
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    HeapDCB990* m_pkHeap;
};
RouterDCB990* GetRouterDCB990() throw();
struct ReferencedDCB990
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};
template <class T> struct RefPtrDCB990
{
    ~RefPtrDCB990() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    void operator=(T* e) throw()
    {
        if (e)
            e->FUN_00c90510();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = e;
    }
    T* m_pRetainedObject;
};
template <class T> __forceinline void DestructDCB990(T* t, int n) throw()
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}
template <class T> struct ArrayDCB990
{
    __forceinline void clear() throw()
    {
        DestructDCB990(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease() throw()
    {
        RouterDCB990* pkRouter = GetRouterDCB990();
        HeapDCB990& kHeap = *pkRouter->m_pkHeap;
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kHeap.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct EntryDCB990
{
    int unk00;
    RefPtrDCB990<ReferencedDCB990> m_spShape;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct PairDCB990
{
    int m_iA;
    int m_iB;
};
struct ObjectDCB990
{
    __forceinline ~ObjectDCB990() throw()
    {
        m_kPairs.ClearAndRelease();
    }
    static void operator delete(void* p, unsigned int nbytes) throw()
    {
        RouterDCB990* pkRouter = GetRouterDCB990();
        pkRouter->m_pkHeap->ReleaseBlock(p, (int)nbytes);
    }
    int unk00;
    ArrayDCB990<PairDCB990> m_kPairs;
};
extern ReferencedDCB990 g_kDefaultDCB990;
struct ContainerDCB990
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    RefPtrDCB990<ReferencedDCB990> m_spDefault;
    int unk14;
    int unk18;
    ArrayDCB990<ObjectDCB990*> m_kThirdFollowingStreamField;
    ArrayDCB990<EntryDCB990> m_kEntries;
    void ClearEntries();
};

struct S00dc7d20_Ref
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void FUN_00c905b0() throw();
};

struct S00dc7d20_Ptr
{
    S00dc7d20_Ref* m_pRetainedObject;
    __forceinline ~S00dc7d20_Ptr() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
    }
};

struct S00dc7d20_Pool
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
    void* GetValue(const void* pvKey, int iDefault) throw();
    void FUN_00d874d0(const char* pcKey, const void* pvValue) throw();
};

struct S00dc7d20_World
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
    S00dc7d20_Pool m_stringPool;

    const char* InternString(const char* pcStr)
    {
        if (pcStr)
        {
            const char* pcPooled = (const char*)m_stringPool.GetValue(pcStr, 0);
            if (pcPooled == 0)
            {
                pcPooled = FUN_00cb1410(pcStr);
                m_stringPool.FUN_00d874d0(pcPooled, pcPooled);
            }
            return pcPooled;
        }
        return 0;
    }
    static const char* FUN_00cb1410(const char* pcStr) throw();
    S00dc7d20_Ptr FUN_00dc8d70(const char* pcTypeName) throw();
};

class S00dc7d20_Class
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int FindMemberIndexByName(const char* pcName);
    void FUN_00dc9470(const char* pcName) throw();
    void FUN_00dc9f20(const char* pcName, int iType, const S00dc7d20_Ptr& kType, int iCount) throw();
};

class S00dc7d20_Cls
{
  public:
    int unk00;
    int unk04;
    S00dc7d20_World* m_pOwningWorld;

    void FUN_00dc7d20(S00dc7d20_Class** ppClass, const char* pcName, int iType, const char* pcTypeName, int iCount);
};

// @fnv 0x00dc7d20
void S00dc7d20_Cls::FUN_00dc7d20(S00dc7d20_Class** ppClass, const char* pcName, int iType, const char* pcTypeName,
                                 int iCount)
{
    S00dc7d20_Class* pkClass = *ppClass;
    const char* pcPooled = m_pOwningWorld->InternString(pcName);
    if (pkClass->FindMemberIndexByName(pcName) != -1)
        pkClass->FUN_00dc9470(pcPooled);
    pkClass->FUN_00dc9f20(pcPooled, iType, m_pOwningWorld->FUN_00dc8d70(pcTypeName), iCount);
}

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

struct hkAllocX
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& numBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);

    template <typename T> __forceinline T* _bufAlloc(int& numInOut)
    {
        if (numInOut)
        {
            int numBytes = numInOut * sizeof(T);
            void* p = AllocateBufferWithSize(numBytes);
            numInOut = numBytes / (int)sizeof(T);
            return static_cast<T*>(p);
        }
        return 0;
    }
};

struct hkRouterX
{
    void* m_aiEntries;
    void* unk04;
    void* unk08;
    hkAllocX* m_pTemp;
    hkAllocX* m_pStreamAllocator;
    hkAllocX& temp()
    {
        return *m_pTemp;
    }
    hkAllocX& heap()
    {
        return *m_pStreamAllocator;
    }
};

static __forceinline hkRouterX& getRouterX()
{
    return *reinterpret_cast<hkRouterX*>(FUN_00c85750());
}

void __cdecl FUN_00c908c0(hkAllocX& alloc, void* array, int numElem, int sizeElem) throw();

template <typename T> struct hkHeapArrX
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkHeapArrX() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkHeapArrX()
    {
        _clearAndDeallocate(getRouterX().heap());
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void _clearAndDeallocate(hkAllocX& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(hkAllocX& alloc, int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void reserve(int n)
    {
        GrowArrayCapacity(getRouterX().heap(), n);
    }
};

template <typename T> struct hkTempArrX
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkTempArrX(int n) : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {
        hkAllocX& alloc = getRouterX().temp();
        T* p = alloc._bufAlloc<T>(n);
        int cap = n ? n : 0x80000000;
        m_data = p;
        m_iElementCount = n;
        m_iCapacityState = cap;
        for (int i = 0; i < n; i++)
            new (p + i) T();
    }
    __forceinline ~hkTempArrX()
    {
        hkAllocX& alloc = getRouterX().temp();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
};

class hkDataClassImplX
{
  public:
    virtual void v00();
    virtual void v04();
    virtual const char* getName() const;
};

struct hkDataMemberInfoX
{
    const char* m_name;
    hkDataClassImplX* m_pOwnerObject;
    int m_type;
    hkDataClassImplX* m_valueClass;
    int m_iFlags;
    hkDataMemberInfoX() : m_name(0), m_pOwnerObject(0), m_type(0), m_valueClass(0), m_iFlags(0)
    {}
};

struct hkDataMemberCinfoX
{
    const char* m_name;
    int m_type;
    const char* m_valueClass;
    int m_iFlags;
};

struct hkDataClassCinfoX
{
    const char* name;
    int version;
    const char* parent;
    hkHeapArrX<hkDataMemberCinfoX> members;
};

class hkDataClassX
{
  public:
    hkDataClassImplX* m_pClassImpl;

    hkDataClassX(hkDataClassImplX* impl) throw();
    ~hkDataClassX() throw();
    int GetObjectKind() const throw();
    const char* getName() const throw();
    int GetNumOwnMembers() const throw();
    hkDataClassX getParent() const throw();
    int GetNumAllMembers() const throw();
    void GetAllMemberInfo(hkTempArrX<hkDataMemberInfoX>& out) const throw();
};

class hkDataWorldDictX
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual hkDataClassImplX* newClass(const hkDataClassCinfoX& cinfo);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual hkDataClassImplX* GetClassFromName(const char* name) const;

    void addClassMemberX(hkDataClassX& pClassInfo, const char* name, int type, const char* className,
                         int aiFlags) throw();
    hkDataClassImplX* FUN_00dc85a0(const char* name, const hkDataWorldDictX& worldFrom);
};

// @fnv 0x00dc85a0
hkDataClassImplX* hkDataWorldDictX::FUN_00dc85a0(const char* name, const hkDataWorldDictX& worldFrom)
{
    if (hkDataClassImplX* c = GetClassFromName(name))
        return c;
    hkDataClassX klassFrom(worldFrom.GetClassFromName(name));
    hkDataClassCinfoX cinfo;
    cinfo.name = klassFrom.getName();
    cinfo.version = klassFrom.GetNumOwnMembers();
    hkDataClassX parent = klassFrom.getParent();
    if (parent.GetObjectKind())
    {
        cinfo.parent = 0;
    }
    else
    {
        cinfo.parent = parent.getName();
        if (hkDataClassImplX* c = GetClassFromName(cinfo.name))
            return c;
    }
    hkDataClassImplX* clsImpl = newClass(cinfo);
    hkTempArrX<hkDataMemberInfoX> minfos(klassFrom.GetNumAllMembers());
    klassFrom.GetAllMemberInfo(minfos);
    cinfo.members.reserve(minfos.GetLogicalSize());
    hkDataClassX pClassInfo(clsImpl);
    for (int i = 0; i < minfos.GetLogicalSize(); i++)
    {
        hkDataMemberInfoX& m = minfos[i];
        const char* className = 0;
        if (m.m_valueClass)
        {
            className = m.m_valueClass->getName();
            FUN_00dc85a0(className, worldFrom);
        }
        addClassMemberX(pClassInfo, m.m_name, m.m_type, className, m.m_iFlags);
    }
    return clsImpl;
}

struct hkMemAllocDC82
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct hkRouterDC82
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemAllocDC82* m_pStreamAllocator;
    hkMemAllocDC82& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterNsDC82 {
extern "C" hkRouterDC82& __cdecl FUN_00c85750() throw();
}

struct hkRefObjDC82
{
    void RetainReference() const;
    void removeReference() const;
};

extern hkRefObjDC82 DAT_011b7c00;

template <class T> class hkRefPtrDC82
{
  public:
    hkRefPtrDC82() : m_pRetainedObject(0)
    {}
    hkRefPtrDC82(T* e)
    {
        if (e)
            e->RetainReference();
        m_pRetainedObject = e;
    }
    ~hkRefPtrDC82()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    void operator=(const hkRefPtrDC82& rp)
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->RetainReference();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    void operator=(T* e)
    {
        if (e)
            e->RetainReference();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = e;
    }
    T* m_pRetainedObject;
};

struct hkHandleDC82
{
    hkHandleDC82()
    {
        DAT_011b7c00.RetainReference();
        m_pRetainedObject = &DAT_011b7c00;
    }
    void operator=(const hkRefPtrDC82<hkRefObjDC82>& rp)
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->RetainReference();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    hkRefObjDC82* m_pRetainedObject;
};

struct hkVariantDC82
{
    void* m_object;
    const void* m_class;
};

struct hkClassDC82
{
    const char* FUN_00d46d40() const;
    const hkClassDC82* FUN_00d46d50() const;
    int FUN_00d47120() const;
    int FUN_00d46f70() const;
    const hkVariantDC82* FUN_00d47260(const char* id) const;
    const struct hkClassMemberDC82& FUN_00d46f80(int i) const;
};

struct hkClassMemberDC82
{
    const char* m_name;
    const hkClassDC82* m_class;
    const void* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_iArraySize;
    unsigned short m_flags;
    unsigned short m_offset;
    const void* m_pCustomAttributes;

    int getType() const
    {
        return m_type;
    }
    int getSubtype() const
    {
        return m_eSubtype;
    }
    const hkClassDC82* FUN_00d86920() const;
    int FUN_00d86940() const;
    const hkVariantDC82* FUN_00d86960(const char* id) const;
};

struct hkMemberAccessorDC82
{
    void* m_pTargetObject;
    const void* m_kMemberDescriptor;
    hkMemberAccessorDC82(const hkVariantDC82* v, const char* member);
    const char** GetStringPointerAt(int i);
};

struct hkDataRefCountedDC82
{
    virtual ~hkDataRefCountedDC82();
    unsigned short m_usMemSizeAndFlags;
    unsigned short unk06;
    int m_uiItemCount;
    void RetainReference()
    {
        ++m_uiItemCount;
    }
    void removeReference()
    {
        if (--m_uiItemCount == 0)
            delete this;
    }
    static void* operator new(unsigned int n)
    {
        void* p = hkRouterNsDC82::FUN_00c85750().heap().AllocateMemoryBlock(n);
        static_cast<hkDataRefCountedDC82*>(p)->m_usMemSizeAndFlags = (unsigned short)n;
        return p;
    }
    static void operator delete(void* p);
};

struct hkDataWorldDC82;

struct hkDataClassDictDC82 : hkDataRefCountedDC82
{
    hkDataWorldDC82* m_pOwningWorld;
    const char* m_name;
    int m_version;
    hkRefPtrDC82<hkDataClassDictDC82> m_parent;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;

    hkDataClassDictDC82(hkDataWorldDC82* world, const char* name, int version) throw();
    void setParent(hkDataClassDictDC82* p)
    {
        m_parent = p;
    }
    __declspec(noalias) void FUN_00dc9f20(const char* name, int type, const struct hkHandleDC82& typeName, int count);
};

struct hkStringMapDC82
{
    void* GetValue(const char* key, void* def);
    void FUN_00d874d0(const char* key, const char* val);
};

extern "C" char* FUN_00cb1410(const char* s);
struct hkTrackerDC82
{
    hkStringMapDC82 m_kLookupMap;
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
    hkStringMapDC82 m_pStringFunctions;

    const char* InternString(const char* s)
    {
        if (s)
        {
            const char* r = (const char*)m_pStringFunctions.GetValue(s, 0);
            if (r == 0)
            {
                r = FUN_00cb1410(s);
                m_pStringFunctions.FUN_00d874d0(r, r);
            }
            return r;
        }
        return 0;
    }
    void RegisterObject(hkDataClassDictDC82* c);
    hkRefPtrDC82<hkRefObjDC82> FUN_00dc8d70(const char* name);
};

extern const char* DAT_011b7bfc;
extern "C" char* FUN_00cb1410(const char* s);
int GetShapeTypeFlags(int type, int subtype, const hkClassDC82* pClassInfo, int count);

struct hkDataWorldDC82
{
    void* vfptr;
    int unk04;
    hkTrackerDC82* m_pTracker;

    hkDataClassDictDC82* GetClassFromName(const char* name)
    {
        hkStringMapDC82& classes = m_pTracker->m_kLookupMap;
        return name ? (hkDataClassDictDC82*)classes.GetValue(name, 0) : 0;
    }
    const char* internString(const char* s)
    {
        hkTrackerDC82* tracker = m_pTracker;
        return tracker->InternString(s);
    }
    hkDataClassDictDC82* FUN_00dc8270(const hkClassDC82& pClassInfo);
};

// @fnv 0x00dc8270
hkDataClassDictDC82* hkDataWorldDC82::FUN_00dc8270(const hkClassDC82& pClassInfo)
{
    hkDataClassDictDC82* c = new hkDataClassDictDC82(this, pClassInfo.FUN_00d46d40(), pClassInfo.FUN_00d47120());
    if (pClassInfo.FUN_00d46d50())
    {
        const hkClassDC82* parent = pClassInfo.FUN_00d46d50();
        hkDataClassDictDC82* p = GetClassFromName(parent->FUN_00d46d40());
        if (p == 0)
        {
            p = FUN_00dc8270(*pClassInfo.FUN_00d46d50());
        }
        c->setParent(p);
    }
    c->RetainReference();
    m_pTracker->RegisterObject(c);
    for (int i = 0; i < pClassInfo.FUN_00d46f70(); ++i)
    {
        const hkClassMemberDC82& m = pClassInfo.FUN_00d46f80(i);
        int type = 0;
        hkHandleDC82 typeName;
        if ((m.m_flags & 0x400) != 0x400)
        {
            type = GetShapeTypeFlags(m.getType(), m.getSubtype(), m.FUN_00d86920(), m.FUN_00d86940());
            if (m.FUN_00d86920())
            {
                if (const hkVariantDC82* attr = m.FUN_00d86960(DAT_011b7bfc))
                {
                    hkMemberAccessorDC82 acc(attr, "typeName");
                    typeName = m_pTracker->FUN_00dc8d70(*acc.GetStringPointerAt(0));
                }
                else if (const hkVariantDC82* attr = m.FUN_00d86920()->FUN_00d47260(DAT_011b7bfc))
                {
                    hkMemberAccessorDC82 acc(attr, "typeName");
                    typeName = m_pTracker->FUN_00dc8d70(*acc.GetStringPointerAt(0));
                }
                else
                {
                    typeName = m_pTracker->FUN_00dc8d70(m.FUN_00d86920()->FUN_00d46d40());
                }
            }
        }
        const char* name = internString(m.m_name);
        hkRefObjDC82* typeObj = typeName.m_pRetainedObject;
        c->FUN_00dc9f20(name, type, typeName, m.FUN_00d86940());
        if (typeObj)
            typeObj->removeReference();
    }
    return c;
}
