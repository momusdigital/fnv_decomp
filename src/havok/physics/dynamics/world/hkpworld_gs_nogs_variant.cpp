
// src/havok/physics/dynamics/world/hkpworld_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/dynamics/world/hkpworld.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/world/hkpworld.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/hkpworld.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpWorld.h"
struct FUN_00cf7c10
{
    void __thiscall PerformThisObjectOperation();
};
struct FUN_00c91120
{
    void __thiscall ExecutePendingOperations();
};
struct FUN_00c91180_Class
{
    void EnterTlsGuard();
    void IncrementCounter();
};
struct FUN_00c91250_Class
{
    void* m_p;
    void FUN_00c91250();
};
struct FUN_00cf6d20_Class
{
    void __thiscall FUN_00cf6d20();
};
struct FUN_00cf6d30_Class
{
    void __thiscall ResetThreadCheck();
};
struct FUN_00c91280_Class
{
    void __thiscall FUN_00c91280(int);
};
struct NiBinaryStream
{
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream* pThis, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytes = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytes;
        return uiBytes;
    }
};
struct Ctx_00caa840
{
    unsigned int unk00;
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
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    NiBinaryStream* m_pBackingStream;
};
struct Blk40
{
    float f[16];
};
template <class T>
inline unsigned int WriteBinaryArray(NiBinaryStream& binstream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    return binstream.BinaryWrite(pValue, uiNumEls * sizeof(T), &uiSize, uiNumEls);
}
template <class T> inline void SerializeValue(Ctx_00caa840& kStream, const T& tValue)
{
    WriteBinaryArray(*kStream.m_pBackingStream, &tValue, 1);
}
struct Data_00caa840
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    Blk40 m_20;
    Blk40 m_60;
    unsigned char unkA0;
    unsigned char unkA1;
    char m_a2;
    unsigned char unkA3;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    int m_b0;
    unsigned int unkB4;
    unsigned int unkB8;
    int m_bc;
    unsigned int unkC0;
    int m_c4;
    int m_c8;
};
struct FUN_00caa840_shell
{
    void* m_iWordAt00;
    Data_00caa840* m_data;
    void FUN_00c8a280(Ctx_00caa840* ctx);
    void SaveShape(int n, Ctx_00caa840* ctx);
    void WriteToStream(Ctx_00caa840* ctx);
};
void __stdcall FUN_00c90e40(void* self, int arg);
struct FUN_00cf86e0_class
{
    void FUN_00cf86e0(float);
};
void __fastcall FUN_00c91040(void* p, int edx, float f);
struct RefObj
{
    void FUN_00c90510();
};
struct DDCC60World
{
    void removeReference();
};
struct FUN_00c910d0_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    void* m_40;
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    void* m_60;
    void* m_64;
    void* m_68;
    void* m_6c;
    void* m_70;
    void* m_74;
    void* m_78;
    void* m_7c;
    void* m_80;
    void* m_84;
    void* m_88;
    void* m_8c;
    void* m_90;
    void* m_94;
    void* m_98;
    void* m_9c;
    void* m_a0;
    void* m_a4;
    void* m_a8;
    void* m_ac;
    void* m_b0;
    void* m_b4;
    void* m_b8;
    void* m_bc;
    void* m_c0;
    void* m_c4;
    void* m_c8;
    void* m_cc;
    void* m_d0;
    void* m_d4;
    void* m_d8;
    void* m_dc;
    void* m_e0;
    void* m_e4;
    void* m_e8;
    void* m_ec;
    void* m_f0;
    void* m_f4;
    void* m_f8;
    void* m_fc;
    void* m_100;
    void* m_104;
    void* m_108;
    void* m_10c;
    void* m_110;
    void* m_114;
    void* m_118;
    void* m_11c;
    void* m_120;
    void* m_124;
    void* m_128;
    void* m_12c;
    void* m_130;
    void* m_134;
    void* m_138;
    void* m_13c;
    void* m_140;
    void* m_144;
    void* m_148;
    void* m_14c;
    void* m_150;
    void* m_154;
    void* m_158;
    void* m_15c;
    void* m_160;
    void* m_164;
    void* m_168;
    void* m_16c;
    void* m_170;
    void* m_174;
    void* m_178;
    void* m_17c;
    void* m_180;
    void* m_184;
    void* m_188;
    void* m_18c;
    void* m_190;
    void* m_194;
    void* m_198;
    void* m_19c;
    void* m_1a0;
    void* m_1a4;
    void* m_1a8;
    void* m_1ac;
    void* m_1b0;
    void* m_1b4;
    void* m_1b8;
    void* m_1bc;
    void SetRefObject(void*);
};
struct FUN_00cf7ae0_Class
{
    void FUN_00cf7ae0();
};
struct FUN_00c91140_Class
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3C;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4C;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5C;
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6C;
    unsigned int m_70;
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7C;
    unsigned int m_80;
    unsigned int m_84;
    unsigned int m_88;
    unsigned int m_8C;
    int m_90;
    void FUN_00c91140();
};
struct S_00cf7540_Ref
{
    void* m_p;
};
struct S_00cf7540
{
    void __thiscall AddEntry(S_00cf7540_Ref*, S_00cf7540_Ref*, int, int);
};
struct FUN_00c91170_Class
{
    void FUN_00c91170(S_00cf7540_Ref*, S_00cf7540_Ref*, int, int);
};
void __cdecl FUN_00c904e0();
struct FUN_00c91190_Class
{
    void __thiscall FUN_00c91190();
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
struct FUN_00c911d0_Class
{
    void __thiscall EnterLock(void*);
};
extern void(__stdcall* DAT_00fdf05c)(void*);
struct FUN_00c911f0_Class
{
    void FUN_00c911f0(void*);
};
struct hkpAction;
struct hkpPhysicsSystem
{
    void __thiscall FUN_00d06590(hkpAction* action);
};
struct FUN_00c928c0_ActionList
{
    hkpAction** m_ppActions;
    int m_uiItemCount;
};
struct FUN_00c928c0_ActionOwner
{
    unsigned char m_auiShapeKeys[0x38];
    FUN_00c928c0_ActionList m_actionList;
};
struct FUN_00c928c0_Context
{
    unsigned char m_pad00[0x28];
    FUN_00c928c0_ActionOwner** m_owners1;
    unsigned int m_ownerCount1;
    unsigned char m_pad30[0x04];
    FUN_00c928c0_ActionOwner** m_owners2;
    unsigned int m_ownerCount2;
};
void FUN_00c928c0(FUN_00c928c0_Context* context, hkpPhysicsSystem* physicsSystem);
struct hkpWorld_MemUsageOut
{
    int m_maxSize;
    int m_totalSize;
    void* m_maxObject;
};
struct FUN_00c92b50_Class
{
    char pad[0x28];
    void* m_data;  // +0x28
    int m_iElementCount;    // +0x2c
    void __thiscall ComputeMemoryUsage(hkpWorld_MemUsageOut* out);
};
struct CA8B80Command
{
    unsigned char m_bType;
    void* m_p;
};
struct CA8B80Queue
{
    void __thiscall Push(CA8B80Command*);
};
struct FUN_00c97510
{
    void __thiscall ProcessPointer(void*);
};
struct FUN_00c97f50_Class
{
    void DispatchOrQueue(void* p);
};
extern int DAT_010c3bb8;
struct FUN_00c98350_Class
{
    void* m_p;
    void* __thiscall InitAndMaybeFree(int);
};
void __cdecl _Deallocate(void*);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct FUN_00c983e0_Class
{
    void ForEachCall(int a, int b, int c, int d, int e);
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct FUN_00c984a0_Class
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    void FUN_00c984a0(int a1, int a2, int a3);
};
struct FUN_00c98540_Class
{
    void CallAllWithArgs(int a, int b, int c);
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpCriticalSection);
struct FUN_00c98600_Class
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_ppData;     // +0x08
    int m_uiItemCount;  // +0x0C
    unsigned int unk10;
    void* m_cs;  // +0x14
    void CallVirtualOnAll(int a, int b, int c, int d, int e, int f, int g, int h);
};
struct FUN_00c990b0_Class
{
    void FUN_00c990b0(int a, int b, int c, int d);
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf05c(void*);
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf100(void*);
struct FUN_00c995f0_Class
{
    void FUN_00c995f0();
};
struct FUN_00c90f30_Class
{
    int unk00;
    void* __thiscall FUN_00c90f30();
};
struct CpuScalar
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    float value;
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    CpuScalar* value;
    float FUN_00c91020();
};
struct FUN_00cf86f0_Class
{
    void __thiscall IsFieldEqual();
};
struct FUN_00c91060_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    FUN_00cf86f0_Class* m_8;
    void __thiscall FUN_00c91060();
};
struct Inner
{
    void Tail();
};
struct FUN_00c91070_cls
{
    int unk00;
    int unk04;
    Inner* m_08;
    void FUN_00c91070();
};
struct FnvCpu_FUN_00c91090_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00c91090_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    FnvCpu_FUN_00c91090_CpuInterface* target;
    void FUN_00c91090(int arg0);
};
struct PendingOperations
{
    void __thiscall FUN_00cf7690();
};
struct WorldWithPending : hkpWorld
{
    void __thiscall FUN_00c91160();
};
struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void Forward(int a);
};
struct FUN_00c91270_cls
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
    Target* m_5C;
    void FUN_00c91270(int a);
};
struct FUN_00c98250_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* __thiscall createContactMgr(int, int, int);
};
void __stdcall FUN_00c982a0(char* pFlag, int a2, int a3, int a4, int a5, int a6);
void __stdcall FUN_00c982b0(unsigned char* flag, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
extern __declspec(thread) int g_tlsMemContext;
extern unsigned int DAT_011afe7c;
struct ScopedMemContext
{
    int m_saved;
    ScopedMemContext(int ctx)
    {
        m_saved = g_tlsMemContext;
        g_tlsMemContext = ctx;
    }
    ~ScopedMemContext()
    {
        g_tlsMemContext = m_saved;
    }
};
struct C67Owner
{
    int unk00;
    int unk04;
    int unk08;
    struct C67Flags* unk0C;
};
struct C67Flags
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int unk10;
    void clearFlag20()
    {
        unk10 &= ~0x20;
    }
};
struct C67Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char m_type;
    C67Owner* getOwner()
    {
        return (C67Owner*)((char*)this + m_iOwnerOffset);
    }
};
struct C67Entry
{
    void removeReference();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C67Collidable m_kCollidable;
};
inline C67Owner* getEntityOwner(C67Collidable* coll)
{
    if (coll->m_type == 1)
        return coll->getOwner();
    return 0;
}
struct C67Sink
{
    void RemoveEntities(C67Entry** entries, unsigned int count);
};
class FUN_00c67aa0_Class
{
  public:
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
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual C67Sink* getSink();
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
    C67Entry** m_entries;
    unsigned int m_iNumberOfEntries;
    void FlushEntries();
};
struct WorldExt : public hkpWorld
{
    float FUN_00c91020() throw();
    void FUN_00c91040(float f) throw();
    void FUN_00c91bd0() throw();
    bool FUN_00c91060() throw();
    float FUN_00c91030() throw();
    void FUN_00c91b10(float f) throw();
    void FUN_00c93ae0(int a, int b, float f) throw();
    void FUN_00c91120() throw();
    void FUN_00c91140() throw();
};
struct Class_012677d0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    void EnsureObjectsCreated(unsigned char val) throw();
};
extern float DAT_012677c4;
extern char DAT_012677a0;
extern int DAT_012677c8;
extern unsigned char DAT_012677a2;
extern unsigned int DAT_011afe80;
extern float DAT_011afe68;
extern unsigned char DAT_01267b2c;
extern Class_012677d0* DAT_012677d0;
extern float DAT_01267b38;
extern float DAT_011ac3a0;
extern float DAT_012677ac;
extern float DAT_011afe64;
extern char DAT_012677cd;
struct bhkWorld
{
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
    virtual void v17() throw();
    virtual void v18() throw();
    virtual void v19() throw();
    virtual void v20() throw();
    virtual void v21() throw();
    virtual void v22() throw();
    virtual void v23() throw();
    virtual void v24() throw();
    virtual void v25() throw();
    virtual void v26() throw();
    virtual void v27() throw();
    virtual void v28() throw();
    virtual void v29() throw();
    virtual void v30() throw();
    virtual void v31() throw();
    virtual void v32() throw();
    virtual void v33() throw();
    virtual void v34() throw();
    virtual void v35() throw();
    virtual void v36() throw();
    virtual WorldExt* GetHkpWorld() throw();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void** unk2C;
    unsigned int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    unsigned int unk50;

    void FUN_00c674d0(void* p, unsigned int count) throw();
    void ProcessConstraints() throw();
    void FUN_00c6aac0() throw();
    void FUN_00c6a540(float f) throw();
    void FUN_00c66a00() throw();
    void FUN_00c66e20(float f) throw();
    void FUN_00c68de0() throw();
    void FlushEntries() throw();
    void SetProcessEnabled(int arg) throw();

    bool StepSimulation();
};
void __stdcall FUN_00c910a0(int);
void FUN_00c911a0();
extern void(__stdcall* DAT_00fdf100)(void*);
struct FUN_00c91230_World : hkpWorld
{
    void __thiscall FUN_00c91230(void* param);
};
struct FUN_00c912c0_Class : hkpWorld
{
    unsigned int FUN_00c912c0();
};
struct Comparator
{
    virtual void unused_00();
    virtual void unused_01();
    virtual void unused_02();
    virtual void unused_03();
    virtual void unused_04();
    virtual void unused_05();
    virtual void unused_06();
    virtual void unused_07();
    virtual void unused_08();
    virtual void unused_09();
    virtual void unused_0a();
    virtual void unused_0b();
    virtual void unused_0c();
    virtual void unused_0d();
    virtual void unused_0e();
    virtual void unused_0f();
    virtual void unused_10();
    virtual void unused_11();
    virtual void unused_12();
    virtual bool accepts(const void* left, const void* right);
};
struct FilterCore
{
    virtual void reserved();
    virtual unsigned char* evaluate(unsigned char* answer, const void* left, const void* right);
};
struct FilterOwner
{
    void* unknown_00;
    void* unknown_04;
    FilterCore core;
};
struct Pair
{
    const void* left;
    const void* right;
};
struct OpPacket
{
    unsigned char opcode;
    const void* left;
    const void* right;
};
struct EventSink
{
    void FUN_00cf7080(const Pair* p, int action, FilterCore* core);
};
int __cdecl FindEntryValue(const void*, const void*);
struct FUN_00c913b0_Class
{
    void* unknown_00;
    void* unknown_04;
    void* unknown_08;
    void* unknown_0c;
    void* unknown_10;
    void* unknown_14;
    void* unknown_18;
    void* unknown_1c;
    void* unknown_20;
    void* unknown_24;
    void* unknown_28;
    void* unknown_2c;
    void* unknown_30;
    void* unknown_34;
    void* unknown_38;
    void* unknown_3c;
    void* unknown_40;
    void* unknown_44;
    void* unknown_48;
    void* unknown_4c;
    void* unknown_50;
    void* unknown_54;
    Comparator* m_comparator;
    void* unknown_5c;
    void* unknown_60;
    EventSink* m_callback;
    void* unknown_68;
    void* unknown_6c;
    void* unknown_70;
    void* unknown_74;
    void* unknown_78;
    FilterOwner* m_iFilter;
    void* unknown_80;
    void* unknown_84;
    void* unknown_88;
    void* unknown_8c;
    void* unknown_90;
    void* m_pDataAtOffset94;
    void FUN_00c91160(const OpPacket* packet);
    void ProcessPair(const void* left, const void* right);
};
struct Sh00c91160
{
    void FUN_00c91160(void* rec);
};
struct QueuedOp
{
    unsigned char m_ucOperationType;  // +0x0
    int m_p;                          // +0x4
    short m_kPointA;                        // +0x8
    unsigned char m_kPointB;                // +0xa
};
struct SimVtbl
{
    void* slot[12];
    void(__thiscall* invoke)(void*, int, int, void*, int);  // +0x30
};
struct Sim
{
    SimVtbl* m_vtbl;
};
struct WorldQ
{
    char pad0[8];
    Sim* m_pSimulation;  // +0x08
    char pad_c[0x94 - 0xc];
    int m_iCriticalOperationsLockCount;  // +0x94

    void __thiscall DispatchOp(int a0, int a1, int a2);
};
class hkpWorldC914;
class hkpMotionC914;
void __cdecl FUN_00cf1480(float fA, float fB, int* piOut) throw();
struct hkpCollidableQualityC914
{
    void SetFlagBits(unsigned char ucA, unsigned char ucB, unsigned char ucC) throw();
};
class hkpEntityC914
{
  public:
    virtual void V00() throw();
    virtual void V01() throw();
    virtual void V02() throw();
    virtual void V03() throw();
    virtual hkpMotionC914* getMotion() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkpWorldC914* m_pOwningWorld;
    int m_ulUserData;
    const void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    hkpMotionC914* m_pMotionState;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_uiUniqueId;
    int m_d8;
    int m_dc;
    hkpCollidableQualityC914 m_e0;
    int m_e4;
    short m_e8;
    unsigned short m_ea;
    unsigned short m_ec;
    short m_ee;
    int m_f0;

    void UpdateBoundingVolume(hkpWorldC914* pkWorld, const void* pvShape) throw();
    void FUN_00c90510() throw();
};
struct hkWorldOperationBaseC914
{
    unsigned char m_type;
};
struct hkWorldOperationAddEntityC914 : public hkWorldOperationBaseC914
{
    hkpEntityC914* m_pEntity;
    int m_iActivationState;

    hkWorldOperationAddEntityC914()
    {
        m_type = 1;
    }
};
class hkpWorldC914
{
  public:
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
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_98;
    bool m_bBlockExecutingPendingOperations;
    bool m_bBlockExecutingPendingOperationQueues;
    char m_9e;
    char m_9f;
    int m_a0;
    int m_iPendingOperationQueueCount;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    int m_uiLastEntityUid;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    int m_16c;
    int m_170;
    int m_174;
    int m_178;
    int m_17c;
    int m_180;
    int m_184;
    int m_188;
    int m_18c;
    int m_190;
    int m_194;
    int m_198;
    int m_19c;
    int m_1a0;
    int m_1a4;
    int m_1a8;
    int m_1ac;
    int m_1b0;
    int m_1b4;
    int m_1b8;
    int m_1bc;
    int m_1c0;
    int m_1c4;
    int m_1c8;
    int m_1cc;
    int m_1d0;
    int m_1d4;
    int m_1d8;
    int m_1dc;
    int m_1e0;
    int m_1e4;
    int m_1e8;
    int m_1ec;
    int m_1f0;
    int m_1f4;
    int m_1f8;
    int m_1fc;
    int m_200;
    int m_204;
    int m_208;
    int m_20c;
    int m_210;
    int m_214;
    int m_218;
    int m_21c;
    int m_220;
    int m_224;
    int m_228;
    int m_22c;
    int m_230;
    int m_234;
    int m_238;
    int m_23c;
    int m_240;
    int m_244;
    int m_248;
    int m_24c;
    int m_250;
    int m_254;
    int m_258;
    int m_25c;
    int m_260;
    int m_264;
    int m_268;
    int m_26c;
    int m_270;
    int m_274;
    int m_278;
    int m_27c;
    int m_280;
    int m_284;
    int m_288;
    int m_28c;
    int m_290;
    int m_294;
    int m_298;
    int m_29c;
    int m_2a0;
    int m_2a4;
    int m_2a8;
    int m_2ac;
    int m_2b0;
    int m_2b4;
    int m_2b8;
    int m_2bc;
    int m_2c0;
    int m_2c4;
    int m_2c8;
    int m_2cc;
    int m_2d0;
    int m_2d4;
    int m_2d8;
    int m_2dc;
    int m_2e0;
    int m_2e4;
    int m_2e8;
    int m_2ec;
    int m_2f0;
    int m_2f4;
    int m_2f8;
    int m_2fc;
    int m_300;
    char m_304;
    unsigned char m_305;
    unsigned char m_306;
    unsigned char m_307;

    bool areCriticalOperationsLocked() const
    {
        return m_iCriticalOperationsLockCount != 0;
    }
    void lockCriticalOperations()
    {
        m_iCriticalOperationsLockCount++;
    }
    void unlockAndAttemptToExecutePendingOperations()
    {
        m_iCriticalOperationsLockCount--;
        if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations)
        {
            if (m_iPendingOperationCount)
                FUN_00c91120();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
                FUN_00c91140();
        }
    }

    void FUN_00c91120() throw();
    void FUN_00c91140() throw();
    void FUN_00c91160(const hkWorldOperationBaseC914& kOperation) throw();

    hkpEntityC914* FUN_00c914d0(hkpEntityC914* pkEntity, int iInitialActivationState) throw();
};
void __cdecl FUN_00cb4640(hkpWorldC914* pkWorld, hkpEntityC914* pkEntity, int iInitialActivationState) throw();
void __cdecl FUN_00cb59f0(hkpWorldC914* pkWorld, hkpEntityC914* pkEntity) throw();
void __cdecl NotifyEntityAdded(hkpWorldC914* pkWorld, hkpEntityC914* pkEntity) throw();
void __cdecl FUN_00cffa00(hkpEntityC914* pkEntity) throw();
struct PointerArray
{
    void** elements;
    int size;
    __forceinline int Find(void* target) const
    {
        for (int index = 0; index < size; ++index)
        {
            if (elements[index] == target)
                return index;
        }
        return -1;
    }
};
struct ObjectTable
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    PointerArray pointers;
    void RemovePointer(void* value);
};
struct SearchArray
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    int* items;
    int count;
    void ClearValue(int value);
    int find(int value) const
    {
        for (int i = 0; i < count; ++i)
        {
            if (items[i] == value)
                return i;
        }
        return -1;
    }
};
struct EntryListNode
{
    int* volatile entries;
    int count;
    int findIndex(int value) const
    {
        int total = count;
        int index = 0;
        if (total > 0)
        {
            int* cursor = entries;
            do
            {
                if (*cursor == value)
                    return index;
                ++index;
                ++cursor;
            } while (index < total);
        }
        return -1;
    }
};
struct FUN_00c919d0_Class
{
    void FUN_00c919d0(int value);
};
struct CD22Registry
{
    void __thiscall IncrementCounter();
    void __thiscall FUN_00c91190();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
    int FUN_00c91ba0();
};
struct hkShapeC927
{
    unsigned short m_type;
    unsigned short unk02;
    int unk04[4];
    hkShapeC927* m_pChildAtom;
};
struct hkRecordC927
{
    void* m_object;
    int unk04[2];
    hkShapeC927* m_pCollisionShape;
    int unk10[8];
};
struct hkRecordListC927
{
    hkRecordC927* m_data;
    unsigned short m_iElementCount;
};
struct hkEntityC927
{
    char unk00[0xac];
    hkRecordListC927 m_records;
};
struct hkWorldC927
{
    int unk00[0x12];
    hkEntityC927** m_kActorEntries;
    int m_iActorEntryCount;
};
class hkSetC927
{
  public:
    void FUN_00d06540(void* object);
};
void __cdecl FUN_00c927f0(hkWorldC927* world, hkSetC927* set);
struct hkArrayRaw
{
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct PendingOps
{
    void* m_vtbl;
    void* m_04;
    void* m_08;
    void* m_0c;
    hkArrayRaw m_10;
    hkArrayRaw m_1c;
};
struct HandlerRegistration
{
    void* data;
    void* other;
    HandlerRegistration* next;
};
struct WorldSave
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pSimulation;
    unsigned int m_unknown0c;
    hkVector4 m_kGravity;
    void* m_pFixedIsland;
    void* m_pFixedRigidBody;
    hkArrayRaw m_kActiveSimulationIslands;
    hkArrayRaw m_kInactiveSimulationIslands;
    hkArrayRaw m_kDirtySimulationIslands;
    void* m_pMaintenanceManager;
    void* m_pMemoryWatchDog;
    unsigned char m_bAssertOnRunningOutOfSolverMemory;
    void* m_pJobSemaphore;
    void* m_pKdTreeManager;
    unsigned char m_bUseKdTree;
    void* m_pBroadPhaseDispatcher;
    void* m_pPhantomBroadPhaseListener;
    void* m_pEntityEntityBroadPhaseListener;
    void* m_pBroadPhaseBorderListener;
    void* m_pMultithreadedSimulationJobData;
    void* m_pCollisionInput;
    void* m_pCollisionFilter;
    void* m_pDispatcher;
    void* m_pConvexListCollisionFilter;
    PendingOps* m_pPendingOperations;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_iCriticalOperationsLockCountForPhantoms;
    unsigned char m_bBlockExecutingPendingOperations;
    unsigned char m_bBlockExecutingPendingOperationQueues;
    HandlerRegistration* m_pPendingOperationQueues;
    int m_iPendingOperationQueueCount;
    hkMultiThreadCheck m_kMultiThreadCheck;
    unsigned char m_bProcessActionsInSingleThread;
    unsigned char m_bAllowUnconstrainedIslandJob;
    unsigned int m_uiMinDesiredIslandSize;
    void* m_pModifyConstraintCriticalSection;
    int m_iIsLocked;
    void* m_pIslandDirtyListCriticalSection;
    void* m_pPropertyMasterLock;
    unsigned char m_bWantSimulationIslands;
    float m_fSnapCollisionToConvexEdgeThreshold;
    float m_fSnapCollisionToConcaveEdgeThreshold;
    unsigned char m_bEnableToiWeldRejection;
    unsigned char m_bWantDeactivation;
    unsigned char m_bActivateOnBodyTransformChange;
    float m_fDeactivationReferenceDistance;
    float m_fToiCollisionResponseRotateNormal;
    int m_iMaxSectorsPerMidphaseTask;
    unsigned char m_bProcessToisMultithreaded;
    int m_iMaxSectorsPerNarrowphaseTask;
    int m_iMaxEntriesPerMidphaseToiTask;
    int m_iMaxEntriesPerNarrowphaseToiTask;
    float m_fSimplifiedToiPenetrationThreshold;
    float m_fToiPenetrationThreshold;
    float m_fHigherToiPenetrationThreshold;
    float m_fForcedToiPenetrationThreshold;
    unsigned int m_uiLastEntityUid;
    unsigned int m_uiLastIslandUid;
    unsigned int m_uiLastConstraintUid;
    hkArrayRaw m_kPhantoms;
    hkArrayRaw m_kActionListeners;
    hkArrayRaw m_kEntityListenerArray;
    hkArrayRaw m_kPhantomListeners;
    hkArrayRaw m_kConstraintListeners;
    hkArrayRaw m_kWorldDeletionListeners;
    hkArrayRaw m_kIslandActivationListeners;
    hkArrayRaw m_kWorldPostSimulationListeners;
    hkArrayRaw m_kWorldPostIntegrateListeners;
    hkArrayRaw m_kWorldPostCollideListeners;
    hkArrayRaw m_kIslandPostIntegrateListeners;
    hkArrayRaw m_kIslandPostCollideListeners;
    hkArrayRaw m_kContactListeners;
    hkArrayRaw m_kContactImpulseLimitBreachedListeners;
    void* m_pViolatedConstraintArray;
    void* m_pBroadPhaseBorder;
    void FUN_00c92db0(struct ObjectWriter* writer, void* unused);
};
struct ObjectWriter
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void WriteValue(char* name, void* value, int flags);
    virtual void slot10();
    virtual void WriteArray(int kind, char* name, void* array, int length, void* bounded);
    virtual void OpenBlock(char* name);
    virtual void CloseBlock();
    int m_unknown04;
    void* m_reference08;
    int m_unknown0c;
    unsigned char m_writeAll10;
    void DispatchWithMode(char* name, void* value, unsigned int length, int flags);
};
void* __cdecl FUN_00d06f80(void* array, unsigned int bytes);
extern char str_010c6700;
extern char str_0109c938;
extern char str_010c66f0;
extern char str_010c66e4;
extern char str_010c6084;
extern char str_010c66d8;
extern char str_010c41a4;
extern char str_010c66b8;
extern char str_010c6698;
extern char str_010c6684;
extern char str_010c6664;
extern char str_010c664c;
extern char str_010c6630;
extern char str_010c6624;
extern char str_010c6618;
extern char str_010c660c;
extern char str_010c6600;
extern char str_010c65f8;
extern char str_010c65e8;
extern char str_010c65d8;
extern char str_010c65c4;
extern char str_010c65bc;
extern char str_010c65b0;
extern char str_010c65a4;
extern char str_010c6598;
extern char str_010c6580;
extern char str_010c6578;
extern char str_010c6564;
extern char str_010c6558;
extern char str_010c654c;
extern char str_010c6540;
extern char str_010c6534;
extern char str_010c6524;
extern char str_010c6514;
extern char str_010c6504;
extern char str_010c64f4;
extern char str_010c64e4;
extern char str_010c64d4;
extern char str_010c64c8;
static __forceinline void SaveArray(ObjectWriter* writer, hkArrayRaw& array, char* name, unsigned int stride)
{
    if ((array.m_iCapacityState & 0x80000000u) == 0 || writer->m_writeAll10)
    {
        void* ptr = array.m_data;
        unsigned int capacity = (array.m_iCapacityState & 0x3fffffff);
        void* bounded = FUN_00d06f80(ptr, capacity * stride);
        writer->WriteArray(3, name, array.m_data, array.m_iElementCount * stride, bounded);
    }
}
static __forceinline void SaveBlob(ObjectWriter* writer, char* name, void* address, unsigned int length)
{
    writer->DispatchWithMode(name, address, length, 0);
}
struct WorldWatchDogHolder : hkpWorld
{
    void* __thiscall FUN_00c93570();
};
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
inline void __cdecl operator delete(void*, void*)
{}
struct hkpPhantom;
struct ThreadMemHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_alloc;
};
void* FUN_00c85750();
void ResizeAudioStream(void* alloc, void* array, int elemSize);
void QueryEntityIntoBuffer(hkpWorld* world, hkpPhantom* phantom);
void NotifyPhantomAdded(hkpWorld* world, hkpPhantom* phantom);
struct PendingOperation
{
    unsigned char m_type;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    hkpPhantom* m_pPhantom;
};
struct hkpPhantom : hkReferencedObject
{
    hkpWorld* m_pOwningWorld;
    int unk0C;
    int unk10;
    int unk14;
    void* unk18;

    virtual ~hkpPhantom();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void* vfunc10();
    void FUN_00d07b90();
};
struct FUN_00c936a0_World : hkpWorld
{
    void FUN_00c91160(PendingOperation* op);
    void FUN_00c91120();
    void FUN_00c91140();

    hkpPhantom* FUN_00c936a0(hkpPhantom* phantom);
};
struct FUN_00c93ae0_Vt
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c(void* p, int n);
    virtual void slot10();
};
struct FUN_00c93ae0_Dtm
{
    void FUN_00d051b0();
};
struct FUN_00c93ae0_Cb
{
    int FUN_00c92d70(void* p, float f);
};
struct FUN_00c93ae0_Pair
{
    void FUN_00c91c00(void* a, void* b);
};
struct FUN_00c93ae0_class
{
    void FUN_00c93ae0(void* p1, void* p2, float f);
};
template <class T> struct hkArrayC93D
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayC93D() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct hkMultiThreadCheckC93D
{
    hkUint32 m_uiThreadId;
    hkUint16 m_usMarkedForWrite;
    hkUint16 m_usMarkCount;

    hkMultiThreadCheckC93D() throw() : m_uiThreadId(0xfffffff1), m_usMarkedForWrite(0x8000)
    {}
};
class hkReferencedObjectC93D
{
  public:
    virtual void CalcContentStatistics() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    hkReferencedObjectC93D() throw() : m_sReferenceCount(1)
    {}
};
class FUN_00c93d10 : public hkReferencedObjectC93D
{
  public:
    void* m_pSimulation;
    char m_padC[0x4];
    hkVector4 m_kGravity;
    void* m_pFixedIsland;
    void* m_pFixedRigidBody;
    hkArrayC93D<void*> m_kActiveSimulationIslands;
    hkArrayC93D<void*> m_kInactiveSimulationIslands;
    hkArrayC93D<void*> m_kDirtySimulationIslands;
    void* m_pMaintenanceManager;
    void* m_pMemoryWatchDog;
    char m_pad54[0x54];
    hkMultiThreadCheckC93D m_kMultiThreadCheck;
    char m_padB0[0x6c];
    hkArrayC93D<void*> m_kPhantoms;
    hkArrayC93D<void*> m_kActionListeners;
    hkArrayC93D<void*> m_kEntityListenerArray;
    hkArrayC93D<void*> m_kPhantomListeners;
    hkArrayC93D<void*> m_kConstraintListeners;
    hkArrayC93D<void*> m_kWorldDeletionListeners;
    hkArrayC93D<void*> m_kIslandActivationListeners;
    hkArrayC93D<void*> m_kWorldPostSimulationListeners;
    hkArrayC93D<void*> m_kWorldPostIntegrateListeners;
    hkArrayC93D<void*> m_kWorldPostCollideListeners;
    hkArrayC93D<void*> m_kIslandPostIntegrateListeners;
    hkArrayC93D<void*> m_kIslandPostCollideListeners;
    hkArrayC93D<void*> m_kContactListeners;

    FUN_00c93d10(int iUnused) throw();
    virtual void CalcContentStatistics() throw();
};
struct SystemObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    void* owner;
    void* attachment;
};
struct ActiveFlag
{
    char value;
    operator bool() const
    {
        return value != 0;
    }
};
struct PhysicsSystem
{
    unsigned int unk00;
    unsigned int unk04;
    hkArray<void*> entities;
    hkArray<SystemObject*> constraints;
    hkArray<void*> actions;
    hkArray<void*> phantoms;
    unsigned int unk38;
    unsigned int unk3c;
    ActiveFlag active;
    ActiveFlag isActive() const
    {
        return active;
    }
};
inline int findNull(const hkArray<void*>& values)
{
    for (int i = 0; i < values.m_iElementCount; ++i)
    {
        if (values.m_data[i] == 0)
            return i;
    }
    return -1;
}
struct SystemWorld : hkpWorld
{
    void FUN_00c94bd0(void**, int, int);
    void FUN_00c914d0(void*, int);
    void FUN_00c954e0(void**, int);
    void FUN_00c936a0(void*);
    void FUN_00c97370(void*);
    void FUN_00c97d30(SystemObject*);
    void FUN_00c97f80(PhysicsSystem* system);
};
class hkpConstraintInstanceC980;
class hkpActionC980;
class hkpRigidBodyC980;
class hkpEntityC980;
class hkpPhantomC980;
template <class T> struct hkArrayC980
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    const T* begin() const
    {
        return m_data;
    }
    int indexOf(const T& t, int startIdx = 0, int endIdx = -1) const
    {
        if (endIdx < 0)
            endIdx = m_iElementCount;
        for (int i = startIdx; i < endIdx; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};
struct hkBoolRetC980
{
    char m_cBooleanValue;
    hkBoolRetC980() throw()
    {}
};
class hkpPhysicsSystemC980
{
  public:
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    hkArrayC980<hkpRigidBodyC980*> m_ppRigidBodies;
    hkArrayC980<hkpConstraintInstanceC980*> m_ppConstraints;
    hkArrayC980<hkpActionC980*> m_ppActions;
    hkArrayC980<hkpPhantomC980*> m_kPhantoms;

    const hkArrayC980<hkpRigidBodyC980*>& getRigidBodies() const
    {
        return m_ppRigidBodies;
    }
    const hkArrayC980<hkpConstraintInstanceC980*>& getConstraints() const
    {
        return m_ppConstraints;
    }
    const hkArrayC980<hkpActionC980*>& getActions() const
    {
        return m_ppActions;
    }
    const hkArrayC980<hkpPhantomC980*>& getPhantomArray() const
    {
        return m_kPhantoms;
    }
};
class hkpWorldC980
{
  public:
    hkBoolRetC980 FUN_00c97e80(hkpConstraintInstanceC980* pkConstraint) throw();
    void DispatchOrQueue(hkpActionC980* pkAction) throw();
    void RemoveEntities(hkpEntityC980* const* ppkEntityBatch, int iNumEntities) throw();
    hkBoolRetC980 ProcessTarget(hkpEntityC980* pkEntity) throw();
    void FUN_00c95800(hkpPhantomC980* const* ppkPhantomBatch, int iNumPhantoms) throw();
    void FUN_00c92c70(hkpPhantomC980* pkPhantom) throw();

    void FUN_00c980d0(const hkpPhysicsSystemC980* pkSys) throw();
};
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
class hkListenerC984
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void onEvent(int a, int b, int c, int d, int e);
};
class hkDispatcherC984
{
  public:
    int unk00;
    int unk04;
    hkListenerC984** m_kListeners;
    int m_numListeners;
    int unk10;
    void* m_kCriticalSection;

    void DispatchEvent(int a, int b, int c, int d, int e);
};
extern void(__stdcall* DAT_00fdf05c)(void* pvSection);
extern void(__stdcall* DAT_00fdf100)(void* pvSection);
class hkCriticalSectionC985
{
  public:
    int m_kCriticalSection[6];
    void enter()
    {
        DAT_00fdf05c(this);
    }
    void leave()
    {
        DAT_00fdf100(this);
    }
};
struct hkVector3C985
{
    float x;
    float y;
    float z;
};
class hkListenerC985
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void notify(void* a, void* b, void* c, float x, float y, float z, void* d);
};
class hkDispatcherC985
{
  public:
    int unk00;
    int unk04;
    hkListenerC985** m_kListeners;
    int m_numListeners;
    int unk10;
    hkCriticalSectionC985* m_lock;

    void FUN_00c98590(void* a, void* b, void* c, float x, float y, float z, void* d);
};
class hkpListenerC986
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void notify(int a, int b, int c, int d) throw();
};
class hkpListenerListC986
{
  public:
    int unk00;
    int unk04;
    hkpListenerC986** m_data;
    int m_iElementCount;
    int unk10;
    void* m_pWorldLock;

    void FUN_00c98670(int a, int b, int c, int d);
};
class hkpListenerC98B
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void V8() throw();
    virtual void notify(int a, int b, int c, int d, int e) throw();
};
class hkpListenerListC98B
{
  public:
    int unk00;
    int unk04;
    hkpListenerC98B** m_data;
    int m_iElementCount;
    int unk10;
    void* m_pWorldLock;

    void FUN_00c986c0(int a, int b, int c, int d, int e);
};
// 0x00c98720  unit_74447a602ec8.cpp  /MT /O2 /GS /EHsc /Gy
// thiscall, 6 stack args (ret 0x18): lock pointer at this+0x14, walk the array at
// this+8 for this->count0c elements, call vtable slot 0x28 with the six args, unlock.
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct Listener00c98720
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28(int, int, int, int, int, int);
};
struct C00c98720
{
    char pad00[0x8];
    Listener00c98720** arr08;
    int count0c;
    char pad10[0x4];
    void* pCS14;

    void FUN_00c98720(int a, int b, int c, int d, int e, int f);
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C" __m128 __cdecl _mm_setzero_ps(void);
extern "C" __m128 __cdecl _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 __cdecl _mm_sub_ps(__m128 a, __m128 b);
struct FUN_00c986c0_Obj
{
    void FUN_00c986c0(__m128* a, __m128* b, int c, int d, int e);
};
struct FUN_00c98b60_Class
{
    void FUN_00c98b60(__m128* v, float f, int c, int d, int e);
};
struct IListener
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c(void* a1, void* a2, void* a3, void* a4, void* a5);
};
struct ListenerManager
{
    int unk00;
    int unk04;
    IListener** m_kListeners;
    int m_uiItemCount;
    int unk10;
    void* m_cs;

    void FUN_00c99100(void* a1, void* a2, void* a3, void* a4, void* a5);
};
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf05c(void*);
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf100(void*);
struct FUN_00c99160_Dispatch
{
    virtual void fn00();
    virtual void fn04();
    virtual void fn08();
    virtual void fn0c();
    virtual void fn10();
    virtual void fn14();
    virtual void fn18();
    virtual void fn1c();
    virtual void fn20();
    virtual void fn24();
    virtual void fn28();
    virtual void fn2c();
    virtual void fn30();
    virtual void fn34();
    virtual void fn38();
    virtual void fn3c(int a, int b, int c, int d, int e);
};
struct FUN_00c99160_Owner
{
    int unk00;
    int unk04;
    FUN_00c99160_Dispatch** listeners;
    int listenerCount;
    int unk10;
    void* mutex;
    void DispatchToListeners(int a, int b, int c, int d, int e);
};
struct FUN_00c991c0_Interface
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void __thiscall slot38(int, int, int, int);
};
struct FUN_00c991c0_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    FUN_00c991c0_Interface** m_8;
    int m_iThirdValue;
    void* m_10;
    void* m_14;

    void __thiscall DispatchToSlots(int, int, int, int);
};
extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);
struct HavokHelper
{
    void DrawAxes(const hkRotation& rot, float a2, int a3, int a4);
    void FUN_00c99870(const hkQuaternion& a1, float a2, int a3, int a4);
};
struct __declspec(align(16)) AlignedRotation : hkRotation
{
    void FUN_00ce52e0(const hkQuaternion& a1);
};
struct FUN_00ca8420_Local
{
    unsigned char unk00;
    unsigned int unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
};
struct FUN_00ca8420_Target
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
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
    int unk90;
    int unk94;

    void __thiscall FUN_00c91160(FUN_00ca8420_Local* local);
};
struct FUN_00ca8420_Class
{
    void* unk00;
    void* unk04;
    FUN_00ca8420_Target* unk08;

    void __thiscall FUN_00ca8420(int param2, int param3, int param4);
};
void __cdecl FUN_00cb6f70(void* param1, int param2, int param3, int param4);
void __cdecl NotifyEntitySetMotionType(void* param1, void* param2);
void __cdecl InvokeMotionTypeCallbacks(void* param1);
struct hkVector3CA8A
{
    float x;
    float y;
    float z;
};
struct hkWorldOperationBaseCA8A
{
    unsigned char m_type;
};
class hkpEntityCA8A;
struct hkSetVelocityOpCA8A : public hkWorldOperationBaseCA8A
{
    hkpEntityCA8A* m_pEntity;
    float m_fVelocity[3];

    hkSetVelocityOpCA8A()
    {
        m_type = 0x1b;
    }
};
class hkpWorldCA8A
{
  public:
    int unk00[0x25];
    int m_iCriticalOperationsLockCount;

    bool areCriticalOperationsLocked() const
    {
        return m_iCriticalOperationsLockCount != 0;
    }
    void FUN_00c91160(const hkWorldOperationBaseCA8A& kOperation) throw();
};
struct UnkCall
{
    void FUN_00c9c1d0();
};
class hkpMotionCA8A
{
  public:
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
    virtual void v44();
    virtual void v48();
    virtual void SetTranslationalVelocity(const hkVector3CA8A& v);
};
class hkpEntityCA8A
{
  public:
    int unk00;
    int unk04;
    hkpWorldCA8A* m_pOwningWorld;
    int unk0C[0x35];
    hkpMotionCA8A m_pMotionState;

    void FUN_00ca8a80(const hkVector3CA8A& v);
};
struct FUN_00ca94c0_Ctx
{
    void* self;
    unsigned int arg;
    unsigned int result;
};
struct FUN_00ca94c0_Elem
{
    virtual void Visit(FUN_00ca94c0_Ctx* ctx);
};
struct FUN_00ca94c0_Class
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
    FUN_00ca94c0_Elem** m_pElements;
    int m_uiItemCount;
    int FUN_00ca94c0(unsigned int arg);
};
struct Allocator9
{
    void* __thiscall FUN_00aa3e40(unsigned int size);
};
extern Allocator9 DAT_011f6238;
extern "C" int DAT_010c5dc0;
extern __declspec(thread) unsigned char threadContext9;
struct Guard9
{
    int previous;
    Guard9()
    {
        int* flag = (int*)((char*)&threadContext9 + 0x2b4);
        previous = *flag;
        *flag = 16;
    }
    ~Guard9()
    {
        int* flag = (int*)((char*)&threadContext9 + 0x2b4);
        *flag = previous;
    }
};
struct Node9
{
    void* vtable;
    int value;
    int references;
    int previous;
    int next;
};
struct Class9
{
    void* unk00;
    void* unk04;
    int callbackFlag;
    int* data;
    void __thiscall CopyFromSource(Node9* node);
    int* __thiscall GetOrCreateData(unsigned char* wasEmpty);
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
typedef unsigned int(__cdecl* ReadFn)(NiBinaryStream* pThis, void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);
inline unsigned int BinaryRead(NiBinaryStream* stream, void* pvBuffer, unsigned int uiTotalBytes,
                               unsigned int* puiComponentSizes = 0, unsigned int uiNumComponents = 0)
{
    unsigned int uiBytes =
        ((ReadFn)stream->m_pfnRead)(stream, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    stream->m_uiStreamFlags += uiBytes;
    return uiBytes;
}
struct NiStream
{
    void* m_vtbl;
    unsigned int m_uiFormatVersion;
    unsigned int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    unsigned int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    unsigned int unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    unsigned int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84;
    unsigned int unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4;
    unsigned int unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    unsigned int unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4;
    unsigned int unkE8, unkEC, unkF0, unkF4, unkF8, unkFC, unk100, unk104;
    unsigned int unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124;
    unsigned int unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144;
    unsigned int unk148, unk14C, unk150, unk154, unk158, unk15C, unk160, unk164;
    unsigned int unk168, unk16C, unk170, unk174, unk178, unk17C, unk180, unk184;
    unsigned int unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4;
    unsigned int unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4;
    unsigned int unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC, unk1E0;
    unsigned char unk1E4;
    unsigned char m_bEndianSwap;
    unsigned char unk1E6;
    unsigned char unk1E7;
    unsigned int unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    unsigned int unk200, unk204, unk208, unk20C, unk210, unk214, unk218, unk21C;
    unsigned int unk220, unk224, unk228, unk22C, unk230, unk234, unk238, unk23C;
    unsigned int unk240, unk244, unk248;
    NiBinaryStream* m_pUnderlyingStream;
};
template <class T>
inline unsigned int NiBinaryStreamLoad(NiBinaryStream* binstream, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    return BinaryRead(binstream, pValue, uiNumEls * sizeof(T), &uiSize, uiNumEls);
}
template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    NiBinaryStreamLoad(stream.m_pUnderlyingStream, &value, 1);
}
extern "C" void __cdecl SwapEndianBlocks(void* p);
inline void SwapDword(unsigned long& val)
{
    val = _byteswap_ulong(val);
}
inline void ByteSwapBlk(Blk40& blk)
{
    unsigned long* u = (unsigned long*)&blk;
    SwapDword(u[12]);
    SwapDword(u[13]);
    SwapDword(u[14]);
    SwapDword(u[15]);
    SwapEndianBlocks(&blk);
}
struct FUN_00d1df70
{
    void removeReference();
};
struct Data_caa6a0 : Data_00caa840
{
    void SetReferencedObject(hkReferencedObject* obj);
};
struct FUN_00d53200_class
{
    void* m_unk00;
    Data_caa6a0* m_data;

    void FUN_00c8a230(NiStream& stream);
    hkReferencedObject* FUN_00c8a330(NiStream& stream);

    void ReadFromStream(NiStream& stream);
};
struct AudioTlsState
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
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
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
};
__declspec(thread) AudioTlsState threadData;
struct MemoryScope
{
    int previous;
    MemoryScope()
    {
        previous = threadData.unk2B4;
        threadData.unk2B4 = 16;
    }
    ~MemoryScope()
    {
        threadData.unk2B4 = previous;
    }
};
struct Point3
{
    float x, y, z;
    char* FUN_00a59af0(const char*);
};
Point3& FUN_004a3970(Point3&, const hkVector4&);
char* FUN_00a7d550(const char*, float);
char* FUN_00a7d5e0(const char*, const char*);
struct Strings
{
    void* unk00;
    char** unk04;
    unsigned short unk08, unk0A, unk0C, unk0E;
    void FUN_0096ad30(unsigned);
    void FUN_0096ae90(unsigned, char*&);
    void Append(char* text)
    {
        unsigned n = unk0A;
        if (n >= unk08)
            FUN_0096ad30(n + unk0E);
        FUN_0096ae90(n, text);
    }
};
struct Constraint
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
    hkVector4 unk30;
    hkVector4 unk40;
    hkVector4 unk50;
    hkVector4 unk60;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    hkVector4 unk90;
    unsigned short unkA0;
    unsigned char unkA2, unkA3;
    int unkA4;
    int unkA8;
    float unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    float unkBC;
    int unkC0;
    float unkC4;
    float unkC8;
};
struct Owner
{
    int unk00;
    Constraint* unk04;
    void FUN_00c8a560(Strings*);
    void AppendConstraintToStrings(Strings*);
};
class hkRefObjCBFB
{
  public:
    virtual ~hkRefObjCBFB() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjCBFB()
    {
        m_sReferenceCount = 1;
    }
};
class hkListenerACBFB
{
  public:
    virtual void a0() = 0;
};
class hkListenerBCBFB
{
  public:
    virtual void b0() = 0;
};
class hkListenerCCBFB
{
  public:
    virtual void c0() = 0;
};
class hkListenerDCBFB
{
  public:
    virtual void d0() = 0;
};
class FUN_00cbfba0 : public hkRefObjCBFB,
                     public hkListenerACBFB,
                     public hkListenerBCBFB,
                     public hkListenerCCBFB,
                     public hkListenerDCBFB
{
  public:
    int unk18;
    int unk1C;
    int m_20;

    FUN_00cbfba0() throw();
    virtual ~FUN_00cbfba0() throw();
    virtual void a0();
    virtual void b0();
    virtual void c0();
    virtual void d0();
};
// Reconstructed ClearIndexedValues (FNV 1.4.0.525, /MT /O2 /GS /EHsc /Gy).
// Stand-in declarations; unknown fields are named by their byte offset.
// External callees keep the pack's FUN_ names and bind through relocations.
struct Tls676
{
    char m_pad0000[0x2b4];
    int m_2b4;
};
__declspec(thread) Tls676 g_tls676;
struct Elem676;
struct Sub676
{
    char m_pad0000[0x14];
    unsigned char m_14;
};
struct Elem676
{
    char m_pad0000[0xc];
    Sub676* m_iThirdValue;
    void removeReference();
};
struct Q676
{
    void FUN_00c954e0(Elem676** arr, int count);
    void FUN_00c92c70(Elem676* e);
};
struct GC676
{
    void* m_p;
    int m_unused;
};
struct Tmp676
{
    float m_f;
    unsigned char b0, b1, b2, b3, b4;
};
struct GCObj676
{
    virtual void* g00(void*);
    virtual void* g01(void*);
    virtual void* g02(void*);
    virtual void* g03(void*);
    virtual void* g04(void*);
    virtual void* g05(void*);
    virtual void* g06(void*);
    virtual void* g07(void*);
    virtual void* g08(void*);
    virtual void* g09(void*);
    virtual void* g10(void*);
    virtual void* g11(void*);
    virtual void* g12(void*);
    virtual void* g13(void*);
    virtual void* g14(void*);
    virtual void* g15(void*);
    virtual void* g16(void*);
    virtual void* g17(void*);
    virtual void* g18(void*);
    virtual void* g19(void*);
    virtual void* g20(void*);
    virtual void* g21(void*);
    virtual void* g22(void*);
    virtual void* g23(void*);
    virtual void* g24(void*);
    virtual void* g25(void*);
    virtual void* g26(void*);
    virtual void* g27(void*);
    virtual void* g28(void*);
    virtual void* g29(void*);
    virtual void* g30(void*);
    virtual void* g31(void*);
    virtual void* g32(void*);
    virtual void* g33(void*);
    virtual void* g34(void*);
    virtual void* g35(void*);
    virtual void g36(void*);
};
struct This676
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void* v37();
    char m_pad0004[0x30];
    Elem676** m_aiIndexedValues;  // +0x34
    unsigned int m_uiItemCount;   // +0x38
    void ClearIndexedValues();
};
// Scoped override of the thread-local context field (0x10 during the operation).
struct Guard676
{
    int m_saved;
    Guard676()
    {
        m_saved = g_tls676.m_2b4;
        g_tls676.m_2b4 = 0x10;
    }
    ~Guard676()
    {
        g_tls676.m_2b4 = m_saved;
    }
};
extern GC676* FUN_00c85ef0(GC676* out, Elem676* obj, void* rtti);
extern void* FUN_00ec61c0(void* dst, int value, unsigned int size);
extern unsigned char DAT_01267b70;
struct BoolC68BF0
{
    char m_cBooleanValue;
};
struct HkEntityC68BF0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m_uiValue1;
};
struct EntityC68BF0;
struct HkWorldC68BF0
{
    BoolC68BF0 ProcessTarget(EntityC68BF0* pkEntity);
};
struct EntityC68BF0
{
    void FUN_00c90510();
    int unk00;
    int unk04;
    int unk08;
    HkEntityC68BF0* m_pkHkEntity;
};
struct WorldC68BF0
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
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual HkWorldC68BF0* GetHavokWorld();
    void ProcessPendingItems();
    void ReleaseBodies();
    void ClearReferences();
    void FlushEntries();
    bool FUN_00c68bf0(EntityC68BF0* pkEntity);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_uiBatchDepth;
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
    EntityC68BF0** m_ppkPendingAdds;
    unsigned int m_uiNumPendingAdds;
};
struct FUN_00c91000_Class
{
    __m128 m_iWordAt00;
    __m128 m_10;

    void __thiscall FUN_00c91000(const __m128* value);
};
struct FUN_00c91620_Target;
struct FUN_00c91620_Args
{
    unsigned char type;
    FUN_00c91620_Target* target;
};
struct FUN_00c91620_Aux
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void FreeStorage();
};
struct FUN_00c91620_Target
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();

    unsigned short m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    FUN_00c91620_Aux m_30;
    int m_54;

    void FUN_00c905b0();
};
struct FUN_00c91620_Class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    void* m_40;
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    void* m_60;
    void* m_64;
    void* m_68;
    void* m_6c;
    void* m_70;
    void* m_74;
    void* m_78;
    void* m_7c;
    void* m_80;
    void* m_84;
    void* m_88;
    void* m_8c;
    void* m_90;
    int m_94;
    void* m_98;
    unsigned char m_9c;
    unsigned char m_9d;
    void* m_a0;
    int m_a4;
    void FUN_00c91160(FUN_00c91620_Args* args);
    void FUN_00c91120();
    void FUN_00c91140();
    unsigned char* ProcessTarget(unsigned char* result, FUN_00c91620_Target* target);
};
void __cdecl FUN_00cb5c10(FUN_00c91620_Class* self, FUN_00c91620_Target* target);
void __cdecl FUN_00d005a0(FUN_00c91620_Class* self, FUN_00c91620_Target* target);
void __cdecl FUN_00cffab0(FUN_00c91620_Target* target);
void __cdecl FUN_00cb4740(FUN_00c91620_Class* self, FUN_00c91620_Target* target);
template <class T> class hkArrayXc91700
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};
class hkWorldXc91700
{
  public:
    int unk000[71];
    hkArrayXc91700<void*> m_entries;

    void FUN_00c91700(void* entry);
};
template <class T> class hkArrayC9175
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};
class hkWorldC9175
{
  public:
    int unk000[80];
    hkArrayC9175<void*> m_entries;

    void FUN_00c91750(void* entry);
};
template <class T> class hkArrayC917
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};
class hkWorldC917
{
  public:
    int unk000[74];
    hkArrayC917<void*> m_entries;

    void FUN_00c917a0(void* entry);
};
template <class T> class hkArrayC91F
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};
class hkWorldC91F
{
  public:
    int unk000[77];
    hkArrayC91F<void*> m_entries;

    void FUN_00c917f0(void* entry);
};
template <class T> class hkArrayC918
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};
class hkWorldC918
{
  public:
    int unk000[95];
    hkArrayC918<void*> m_entries;

    void FUN_00c91890(void* entry);
};
template <class T> class hkArrayXc91930
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};
class hkWorldXc91930
{
  public:
    int unk000[92];
    hkArrayXc91930<void*> m_entries;

    void FUN_00c91930(void* entry);
};
template <class T> class hkArrayXc91980
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};
class hkWorldXc91980
{
  public:
    int unk000[101];
    hkArrayXc91980<void*> m_entries;

    void FUN_00c91980(void* entry);
};
template <class T> class hkArrayXc91a20
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};
class hkWorldXc91a20
{
  public:
    int unk000[104];
    hkArrayXc91a20<void*> m_entries;

    void FUN_00c91a20(void* entry);
};
template <class T> class hkArrayXc91a70
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};
class hkWorldXc91a70
{
  public:
    int unk000[83];
    hkArrayXc91a70<void*> m_entries;

    void FUN_00c91a70(void* entry);
};
template <class T> class hkArrayXc91ac0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
};
class hkWorldXc91ac0
{
  public:
    int unk000[107];
    hkArrayXc91ac0<void*> m_entries;

    void FUN_00c91ac0(void* entry);
};
struct Allocator
{
    virtual void v00();
    virtual void* Allocate(int size);
    virtual void Deallocate(void* p, int size);
};
struct ThreadStorage
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Allocator* m_pThreadAllocator;
};
void* FUN_00c85750();
int __fastcall FUN_00d04380(void*);
struct JobHeader
{
    unsigned char m_eJobType;
    unsigned char m_ucSubType;
    unsigned char m_executionFlags;
    unsigned char unk03;
    unsigned short m_jobSize;
    short m_iAffinity;

    JobHeader(unsigned char type, unsigned char subType, unsigned short size, short affinity = -1)
        : m_eJobType(type), m_ucSubType(subType), m_jobSize(size), m_iAffinity(affinity)
    {}
};
struct RayCastCommand
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    int m_uiFilterInfo;
    int m_ulUserData;
    void* m_pResultBuffer;
    int m_iResultCount;
    int m_iResultCapacity;
    int unk34;
    int unk38;
    int unk3C;
};
struct JobDoneHeader
{
    int m_iJobId;
    int unk04;
    int unk08;
    int unk0C;
};
struct JobBase
{
    JobHeader m_kHeader;
    int unk08;
    int unk0C;
    void* m_pCompletionSemaphore;
    JobDoneHeader* m_pJobDoneHeader;
    int unk18;

    __forceinline JobBase(unsigned char subType, unsigned short size) : m_kHeader(1, subType, size)
    {
        unk18 = 0;
        m_kHeader.m_executionFlags = 1;
    }
};
__declspec(align(16)) struct Job : JobBase
{
    void* m_pCollisionInput;
    int m_iFirstIndex;
    RayCastCommand* m_pCommands;
    int m_iCommandCount;
    int unk2C;
    int unk30;
    void* m_pJobSemaphore;
    int unk38;
    void* m_kdTreeUnk0C;
    void* m_kdTreeUnk10;
    int unk44;
    int unk48;
    int unk4C;

    __forceinline Job(void* input, JobDoneHeader* jobHeader, RayCastCommand* commandArray, int numCommands,
                      void* broadphase, void* semaphore)
        : JobBase(3, sizeof(Job))
    {
        m_pJobDoneHeader = jobHeader;
        m_pCollisionInput = input;
        m_pCompletionSemaphore = semaphore;
        m_iFirstIndex = sizeof(RayCastCommand);
        m_pCommands = commandArray;
        m_iCommandCount = numCommands;
        m_pJobSemaphore = broadphase;
        m_pJobDoneHeader->m_iJobId = (numCommands == 0) ? 1 : (numCommands - 1) / 64 + 1;
        unk38 = 0;
        m_kdTreeUnk0C = 0;
        m_kdTreeUnk10 = 0;
        unk2C = 0;
        unk30 = 0;
    }
};
struct JobQueue
{
    void AddObjectCopy(const Job& job, int priority);
};
struct ThreadPool
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void processWork(JobQueue* queue, int type);
    virtual void RunWorkerThread();
};
struct KdTreeManager
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual bool isTreeActive();
    int unk04;
    int unk08;
    void* m_treeData0C;
    void* m_treeData10;
};
struct hkpWorldHelper : hkpWorld
{
    void ExecuteRayCastJobs(RayCastCommand* commandArray, int numCommands, JobQueue* jobQueue, ThreadPool* threadPool,
                            void* semaphore, int numCommandsPerJob);
};
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern unsigned int DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int);
extern const char str_010c64b8[];
extern const char str_010c41f8[];
extern void* DAT_010c6488;
extern float DAT_0104da4c;
struct TimerEntry
{
    const char* name;
    unsigned int ticks;
    unsigned int unk08;
};
struct TimerBuffer
{
    unsigned int unk00;
    TimerEntry* current;
    unsigned int unk08;
    TimerEntry* end;
};
struct __declspec(align(16)) LinearCaster
{
    void* unk00;
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
    float unk80;
    void FUN_00cfaed0(void*, void*, void*, void*, void*, int, int, void*, void*);
};
struct QueryTree
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual bool enabled();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void cast(void*, void*, void*, void*, int, void*, void*);
};
struct CollisionInput
{
    unsigned int unk00;
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
    int unk70;
};
struct WorldQuery : hkpWorld
{
    void FUN_00c92430(void*, void*, void*, void*);
};
extern "C" void __cdecl FUN_00c927f0(void* object, void* value);
struct zzVal_c92860
{
    void* v;
};
static void InvokeOnAllOwners(FUN_00c928c0_Context* ctx, zzVal_c92860 value);
FUN_00c928c0_Context* volatile zz_ctx_c92860 = 0;
void* volatile zz_val_c92860 = 0;
void zz_call_c92860(void);
void __cdecl FUN_00d06cb0(void* apvArray, int iSizeElem);
class EntityC92B;
class IslandC92B
{
  public:
    void RemoveEntry(EntityC92B* pkEntity);
    void AddItem(EntityC92B* pkEntity);
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned short m_usStorageIndex;
    unsigned short unk22;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int** m_pEntities;
};
class EntityC92B
{
  public:
    int unk00, unk04, unk08;
    IslandC92B* m_pSimulationIsland;
};
template <class T> struct hkSmallArrayC92B
{
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fff;
    }
    void AddBack(const T& e)
    {
        if (m_iElementCount == getCapacity())
            FUN_00d06cb0(this, sizeof(T));
        m_data[m_iElementCount++] = e;
    }
};
class WorldC92B
{
  public:
    int unk00[0xcc / 4];
    IslandC92B* m_pFixedIsland;
    int unkD0[(0xe8 - 0xd0) / 4];
    unsigned char m_iMaxEntriesPerNarrowphaseToiTask;
    unsigned char unkE9[0x208 - 0xe9];
    hkSmallArrayC92B<EntityC92B*> m_kActorEntries;
};
class ListenerC92B
{
  public:
    void FUN_00c92bd0(EntityC92B* pkEntity, WorldC92B* pkWorld);
};
void __cdecl FUN_00cb5570(ListenerC92B* pkThis, WorldC92B* pkWorld, int* pkCurrentObject);
class FUN_00c905b0_s
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void FUN_00c905b0();
};
class ActionC92C : public FUN_00c905b0_s
{
  public:
    void* m_pOwningWorld;

    void FUN_00d07b50();
};
template <class T> class hkArrayC92C
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t, int iStart = 0, int iEnd = -1) const
    {
        if (iEnd < 0)
            iEnd = m_iElementCount;
        for (int i = iStart; i < iEnd; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int iIndex)
    {
        m_iElementCount--;
        if (m_iElementCount != iIndex)
            m_data[iIndex] = m_data[m_iElementCount];
    }
};
class WorldC92C;
void __cdecl FUN_00d00820(WorldC92C* pkWorld, ActionC92C* pkAction);
void __cdecl FUN_00cb5d00(WorldC92C* pkWorld, ActionC92C* pkAction);
struct RemoveActionOpC92C
{
    unsigned char m_type;
    ActionC92C* m_pAction;
};
class WorldC92C
{
  public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_iCriticalOperationsLockCountForPhantoms;
    bool m_bBlockExecutingPendingOperations;
    char unk09D[3];
    int unkA0;
    int m_iPendingOperationQueueCount;
    int unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC, unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4;
    int unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104;
    int unk108, unk10C;
    hkArrayC92C<ActionC92C*> m_ppActions;

    bool areCriticalOperationsLocked() const
    {
        return m_iCriticalOperationsLockCount + m_iCriticalOperationsLockCountForPhantoms != 0;
    }
    void lockCriticalOperations()
    {
        m_iCriticalOperationsLockCount++;
    }
    void unlockCriticalOperations()
    {
        if (--m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations)
        {
            if (m_iPendingOperationCount)
                FUN_00c91120();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
                FUN_00c91140();
        }
    }
    void FUN_00c91120();
    void FUN_00c91140();
    void FUN_00c91160(const RemoveActionOpC92C& kOp);
    void FUN_00c92c70(ActionC92C* pkAction);
};
template <int SIZE> __forceinline void memCpyOneAlignedXc937a0(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}
struct hkMemoryRouterXc937a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};
namespace hkRouterXc937a0 {
extern "C" hkMemoryRouterXc937a0& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);
template <class T> class hkArrayXc937a0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXc937a0& router = hkRouterXc937a0::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXc937a0<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};
class hkOwnerXc937a0
{
  public:
    int unk00[71];
    hkArrayXc937a0<void*> m_kNode;

    void FUN_00c937a0(void* item);
};
class hkMemoryAllocatorC93
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterC93
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocatorC93* m_pStreamAllocator;
    hkMemoryAllocatorC93& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterC93& __cdecl GetMemoryRouterC93() throw();
template <typename T> struct hkArrayC93
{
    __forceinline ~hkArrayC93() throw()
    {
        hkMemoryAllocatorC93& kAlloc = GetMemoryRouterC93().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class hkBaseObjectC93
{
  public:
    virtual ~hkBaseObjectC93() throw()
    {}
};
class hkReferencedObjectC93 : public hkBaseObjectC93
{
  public:
    void RetainReference() const throw();
    void removeReference() const throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
template <typename T> struct hkRefPtrC93
{
    __forceinline ~hkRefPtrC93() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    __forceinline void operator=(T* e) throw()
    {
        if (e)
            e->RetainReference();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = e;
    }
    T* m_pRetainedObject;
};
class WorldDeletableC93
{
  public:
    virtual ~WorldDeletableC93() throw();
};
struct ChunkBufferC93
{
    __forceinline ~ChunkBufferC93() throw()
    {
        if (m_pBuffer)
            GetMemoryRouterC93().heap().ReleaseBlock(m_pBuffer, 0x200);
    }
    void* m_pBuffer;
};
struct MtSimulationJobDataC93
{
    __forceinline void operator delete(void* p) throw()
    {
        if (p)
            GetMemoryRouterC93().heap().ReleaseBlock(p, sizeof(MtSimulationJobDataC93));
    }
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
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    ChunkBufferC93 m_kBuffer;
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
};
struct CollisionAgentConfigC93
{
    __forceinline void operator delete(void* p) throw()
    {
        if (p)
            GetMemoryRouterC93().heap().ReleaseBlock(p, sizeof(CollisionAgentConfigC93));
    }
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
struct ProcessCollisionInputC93
{
    __forceinline void operator delete(void* p) throw()
    {
        if (p)
            GetMemoryRouterC93().heap().ReleaseBlock(p, sizeof(ProcessCollisionInputC93));
    }
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
    ChunkBufferC93 m_kBuffer;
    unsigned int unk68;
    unsigned int unk6c;
    CollisionAgentConfigC93* m_pConfiguration;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
};
struct CriticalSectionDataC93
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CriticalSectionDataC93* pkSection);
struct CriticalSectionC93
{
    __forceinline void operator delete(void* p) throw()
    {
        if (p)
            GetMemoryRouterC93().heap().ReleaseBlock(p, sizeof(CriticalSectionC93));
    }
    __forceinline ~CriticalSectionC93() throw()
    {
        DeleteCriticalSection(&m_kCriticalSection);
    }
    CriticalSectionDataC93 m_kCriticalSection;
};
struct BroadPhaseDispatcherC93
{
    __forceinline void operator delete(void* p) throw()
    {
        if (p)
            GetMemoryRouterC93().heap().ReleaseBlock(p, sizeof(BroadPhaseDispatcherC93));
    }
    ~BroadPhaseDispatcherC93() throw();
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
    unsigned int unkd8;
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
};
struct WorldOperationQueueC93
{
    __forceinline void operator delete(void* p) throw()
    {
        if (p)
            GetMemoryRouterC93().heap().ReleaseBlock(p, sizeof(WorldOperationQueueC93));
    }
    ~WorldOperationQueueC93() throw();
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
};
struct ViolatedConstraintArrayC93
{
    __forceinline void operator delete(void* p) throw()
    {
        if (p)
            GetMemoryRouterC93().heap().ReleaseBlock(p, sizeof(ViolatedConstraintArrayC93));
    }
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
    unsigned int unkd8;
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
};
class hkBoolC93
{
  public:
    hkBoolC93(bool b) throw() : m_cBooleanValue(b)
    {}
    char m_cBooleanValue;
};
class FUN_00c93e50 : public hkReferencedObjectC93
{
  public:
    virtual ~FUN_00c93e50() throw();
    void FUN_00c93580() throw();
    hkBoolC93 IsEntityAdded(void* pkEntity) throw();

    hkReferencedObjectC93* m_pSimulation;
    unsigned int unk0c;
    float m_gravityX;
    float m_gravityY;
    float m_gravityZ;
    float m_gravityW;
    WorldDeletableC93* m_pFixedIsland;
    void* m_pFixedRigidBody;
    hkArrayC93<void*> m_kActiveSimulationIslands;
    hkArrayC93<void*> m_kInactiveSimulationIslands;
    hkArrayC93<void*> m_kDirtySimulationIslands;
    hkReferencedObjectC93* m_pMaintenanceManager;
    hkRefPtrC93<hkReferencedObjectC93> m_pMemoryWatchDog;
    bool m_bAssertOnRunningOutOfSolverMemory;
    hkReferencedObjectC93* m_pJobSemaphore;
    hkReferencedObjectC93* m_pKdTreeManager;
    bool m_bUseKdTree;
    BroadPhaseDispatcherC93* m_pBroadPhaseDispatcher;
    WorldDeletableC93* m_pPhantomBroadPhaseListener;
    WorldDeletableC93* m_pEntityEntityBroadPhaseListener;
    WorldDeletableC93* m_pBroadPhaseBorderListener;
    MtSimulationJobDataC93* m_pMultithreadedSimulationJobData;
    ProcessCollisionInputC93* m_pCollisionInput;
    hkReferencedObjectC93* m_pCollisionFilter;
    hkReferencedObjectC93* m_pDispatcher;
    hkReferencedObjectC93* m_pConvexListCollisionFilter;
    WorldOperationQueueC93* m_pPendingOperations;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_iCriticalOperationsLockCountForPhantoms;
    bool m_bBlockExecutingPendingOperations;
    bool m_bBlockExecutingPendingOperationQueues;
    void* m_pPendingOperationQueues;
    int m_iPendingOperationQueueCount;
    unsigned int m_multiThreadCheckThreadId;
    unsigned int m_multiThreadCheckMarks;
    bool m_bProcessActionsInSingleThread;
    bool m_bAllowUnconstrainedIslandJob;
    unsigned int m_uiMinDesiredIslandSize;
    CriticalSectionC93* m_pModifyConstraintCriticalSection;
    int m_iIsLocked;
    CriticalSectionC93* m_pIslandDirtyListCriticalSection;
    CriticalSectionC93* m_pPropertyMasterLock;
    bool m_bWantSimulationIslands;
    float m_fSnapCollisionToConvexEdgeThreshold;
    float m_fSnapCollisionToConcaveEdgeThreshold;
    bool m_bEnableToiWeldRejection;
    bool m_bWantDeactivation;
    bool m_bActivateOnBodyTransformChange;
    float m_fDeactivationReferenceDistance;
    float m_fToiCollisionResponseRotateNormal;
    int m_iMaxSectorsPerMidphaseTask;
    bool m_bProcessToisMultithreaded;
    int m_iMaxSectorsPerNarrowphaseTask;
    int m_iMaxEntriesPerMidphaseToiTask;
    int m_iMaxEntriesPerNarrowphaseToiTask;
    float m_fSimplifiedToiPenetrationThreshold;
    float m_fToiPenetrationThreshold;
    float m_fHigherToiPenetrationThreshold;
    float m_fForcedToiPenetrationThreshold;
    unsigned int m_uiLastEntityUid;
    unsigned int m_uiLastIslandUid;
    unsigned int m_uiLastConstraintUid;
    hkArrayC93<void*> m_kPhantoms;
    hkArrayC93<void*> m_kActionListeners;
    hkArrayC93<void*> m_kEntityListenerArray;
    hkArrayC93<void*> m_kPhantomListeners;
    hkArrayC93<void*> m_kConstraintListeners;
    hkArrayC93<void*> m_kWorldDeletionListeners;
    hkArrayC93<void*> m_kIslandActivationListeners;
    hkArrayC93<void*> m_kWorldPostSimulationListeners;
    hkArrayC93<void*> m_kWorldPostIntegrateListeners;
    hkArrayC93<void*> m_kWorldPostCollideListeners;
    hkArrayC93<void*> m_kIslandPostIntegrateListeners;
    hkArrayC93<void*> m_kIslandPostCollideListeners;
    hkArrayC93<void*> m_kContactListeners;
    hkArrayC93<void*> m_kContactImpulseLimitBreachedListeners;
    ViolatedConstraintArrayC93* m_pViolatedConstraintArray;
    hkReferencedObjectC93* m_pBroadPhaseBorder;
};
void __cdecl ClearSlotReference(FUN_00c93e50* pkWorld, WorldDeletableC93* pkIsland) throw();
void __cdecl FUN_00d00e80(FUN_00c93e50* pkWorld) throw();
class hkMemoryAllocatorC97
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterC97
{
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorC97* m_pTemp;
    hkMemoryAllocatorC97* m_pStreamAllocator;
    hkMemoryAllocatorC97& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterC97& __cdecl GetMemoryRouterC97() throw();
template <typename T> struct hkArrayC97
{
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <typename T, int N> struct hkInplaceArrayC97 : public hkArrayC97<T>
{
    hkInplaceArrayC97() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
    __forceinline ~hkInplaceArrayC97() throw()
    {
        hkMemoryAllocatorC97& kAlloc = GetMemoryRouterC97().heap();
        this->m_iElementCount = 0;
        if ((this->m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
    T m_kStorage[N];
};
struct hkSmallArrayUtilC97
{
    static void __cdecl GrowArray(void* apvArray, int iSizeElem) throw();
};
template <typename T> struct hkSmallArrayC97
{
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fff;
    }
    void AddBack(const T& t) throw()
    {
        if (m_iElementCount == getCapacity())
            hkSmallArrayUtilC97::GrowArray(this, sizeof(T));
        m_data[m_iElementCount++] = t;
    }
    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
};
class hkpActionC97;
class hkpWorldC97;
class hkpSimulationIslandC97
{
  public:
    bool isFixed() const
    {
        return m_usStorageIndex == 0xffff;
    }
    void RegisterAction(hkpActionC97* pkAction) throw();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned short m_usStorageIndex;
};
class hkpEntityC97
{
  public:
    hkpSimulationIslandC97* GetSimulationIsland() const
    {
        return m_pSimulationIsland;
    }
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
    hkpSimulationIslandC97* m_pSimulationIsland;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
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
    hkSmallArrayC97<hkpActionC97*> m_ppActions;
};
class hkpActionC97
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void GetEntities(hkArrayC97<hkpEntityC97*>& kEntitiesOut) throw();
    void RetainReference() const throw();
    void setWorld(hkpWorldC97* pkWorld)
    {
        m_pOwningWorld = pkWorld;
    }
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkpWorldC97* m_pOwningWorld;
};
struct hkWorldOperationC97
{
    enum Type
    {
        ADD_ACTION = 0xa
    };
    struct TypeTag
    {
        TypeTag(Type eType) : m_type(static_cast<unsigned char>(eType))
        {}
        unsigned char m_type;
    };
    struct AddActionCommand : public TypeTag
    {
        AddActionCommand() : TypeTag(ADD_ACTION)
        {}
        hkpActionC97* m_pAction;
    };
};
struct hkpWorldOperationUtilC97
{
    static void __cdecl ReenableCollisionBetweenEntityPair(hkpWorldC97* pkWorld, hkpEntityC97* pkEntityA,
                                                           hkpEntityC97* pkEntityB) throw();
};
struct hkpWorldCallbackUtilC97
{
    static void __cdecl FireActionAdded(hkpWorldC97* pkWorld, hkpActionC97* pkAction) throw();
};
class hkpWorldC97
{
  public:
    bool areCriticalOperationsLocked() const
    {
        return m_iCriticalOperationsLockCount != 0;
    }
    void lockCriticalOperations()
    {
        m_iCriticalOperationsLockCount++;
    }
    void unlockCriticalOperations()
    {
        m_iCriticalOperationsLockCount--;
    }
    __forceinline void attemptToExecutePendingOperations()
    {
        if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations)
        {
            if (m_iPendingOperationCount)
                ExecutePendingOperations();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
                ExecutePendingOperationQueues();
        }
    }
    __forceinline void unlockAndAttemptToExecutePendingOperations()
    {
        unlockCriticalOperations();
        attemptToExecutePendingOperations();
    }
    void AddWorldOperation(const hkWorldOperationC97::TypeTag& kOperation) throw();
    void ExecutePendingOperations() throw();
    void ExecutePendingOperationQueues() throw();
    hkpActionC97* FUN_00c97370(hkpActionC97* pkAction) throw();

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
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_iCriticalOperationsLockCountForPhantoms;
    bool m_bBlockExecutingPendingOperations;
    bool m_bBlockExecutingPendingOperationQueues;
    void* m_pPendingOperationQueues;
    int m_iPendingOperationQueueCount;
};
class hkMemoryAllocatorC97E
{
  public:
    virtual ~hkMemoryAllocatorC97E() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterC97E
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorC97E* m_pStreamAllocator;

    hkMemoryAllocatorC97E& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterC97E {
extern "C" hkMemoryRouterC97E& __cdecl FUN_00c85750() throw();
}

class hkRefObjC97E
{
  public:
    virtual ~hkRefObjC97E();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    static void* operator new(unsigned int nbytes)
    {
        hkRefObjC97E* b = static_cast<hkRefObjC97E*>(hkRouterC97E::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};
struct InfoC97E
{
    int unk00;
    int unk04;
    int m_08;
};
class FUN_00cf3ea0 : public hkRefObjC97E
{
  public:
    int unk08[9];
    int m_2c;
    int unk30[2];

    FUN_00cf3ea0(void* a1, void* a2, InfoC97E* a3, bool a4) throw();
};
class FUN_00c97e30_C
{
  public:
    void FUN_00c97d30(FUN_00cf3ea0* p);
    FUN_00cf3ea0* Create(void* a1, void* a2, InfoC97E* a3);
};
struct C97E80PendingOperation
{
    unsigned char m_type;
    void* m_pAction;
};
struct C97E80Action
{
    virtual void function00();
    virtual void function04();
    virtual void function08();
    virtual void function0C();
    virtual void function10();
    virtual void function14();
    virtual int getReferenceCount();
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    void* m_owner44;
};
struct C97E80Owner
{
    int unk00, unk04;
    hkpWorld* m_pOwningWorld;
};
struct C97E80PendingShell
{
    void __thiscall FUN_00c91160(C97E80PendingOperation* operation);
};
struct C97E80RemoveShell
{
    void __thiscall FUN_00c97510(void* owner);
};
struct C97E80ActionChangeShell
{
    void __thiscall RemoveReferenceFromSlots(hkpWorld* world);
};
struct C97E80ReleaseShell
{
    void __thiscall FUN_00c905b0();
};
struct C97E80CleanupShell
{
    void __thiscall FUN_00c91120();
    void __thiscall FUN_00c91140();
};
void __cdecl FUN_00cb3dd0(hkpWorld* world, C97E80Action* action, int flags);
struct C97E80Return
{
    bool m_iResultCode;
};
struct C97E80World : hkpWorld
{
    C97E80Return __thiscall FUN_00c97e80(C97E80Action* action);
};
float __cdecl FUN_00c98210(float fA, float fB);
struct __declspec(align(16)) FUN_00c987e0_Pose
{
    hkVector4 translation;
    hkQuaternion rotation;
    hkVector4 scale;
    void FUN_00ce52e0(int a1);
};
struct FUN_00c98780_Obj
{
    void FUN_00c98780(FUN_00c987e0_Pose* pose, int a2, int a3, int a4, int a5, int a6);
};
struct FUN_00c987e0_Cls
{
    void FUN_00c987e0(int a1, int a2, int a3, int a4, int a5, int a6);
};
struct __declspec(align(16)) EC98BE0Vector
{
    float x;
    float y;
    float z;
    float w;
    void __thiscall FUN_00c7f7a0(int a, int b);
};
struct EC98BE0Owner
{
    void __thiscall FUN_00c98b60(EC98BE0Vector* position, float scalar, int a, int b, int c);
    void __thiscall FUN_00c98be0(int x, int y, float scalar, int a, int b, int c);
};
struct __declspec(align(16)) FUN_00c7f640_Class
{
    void FUN_00c7f640(const void* m, const void* p);
};
struct FUN_00c98c30_Class
{
    void FUN_00c98b60(const void* p, float c, int d, int e, int f);
    void FUN_00c98c30(const void* a, const void* b, float c, int d, int e, int f);
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
template <class T> class hkArrayC995
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
            {
                return i;
            }
        }
        return -1;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
        {
            m_data[index] = m_data[m_iElementCount];
        }
    }
};
class hkListenerListC995
{
  public:
    int unk00;
    int unk04;
    hkArrayC995<void*> m_kListeners;
    void* m_pWorldLock;

    void RemoveListener(void* listener);
};
class Ce52e0Helper
{
  public:
    void SetFromInput(int*, int);
    void FUN_00ce52e0(int a);
};
class hkpWorldD0AD;
class hkMemberD0AD
{
  public:
    void FUN_00d9e280(hkpWorldD0AD* pkWorld);
};
class hkListenerAD0AD
{
  public:
    virtual void onA();
};
class hkListenerBD0AD
{
  public:
    virtual void onB();
};
class hkReferencedObjectD0AD
{
  public:
    virtual ~hkReferencedObjectD0AD();
    int m_memSizeAndRefCount;
    void FUN_00c905b0();
};
class hkSharedD0AD : public hkReferencedObjectD0AD, public hkListenerAD0AD, public hkListenerBD0AD
{
  public:
    int m_useCount;
    hkMemberD0AD m_kMemberDescriptor;
};
class hkpWorldD0AD
{
  public:
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC;
    int unk1B0, unk1B4, unk1B8, unk1BC;
    hkSharedD0AD* m_pSharedObject;

    void FUN_00c91750(hkListenerAD0AD* pkListener);
    void FUN_00c91a70(hkListenerBD0AD* pkListener);
};
void __cdecl ReleaseSharedObject(hkpWorldD0AD* pkWorld);

struct FUN_00c98820_ArrayObject
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24(void* first, void* second, void* third, void* fourth, void* fifth);
};

struct FUN_00c98820_Class
{
    int m_00;
    int m_04;
    FUN_00c98820_ArrayObject** m_08;
    int m_0c;

    void __thiscall FUN_00c98820(void* first, void* second, void* third, void* fourth, void* fifth);
};

// @fnv 0x00c98820
void __thiscall FUN_00c98820_Class::FUN_00c98820(void* first, void* second, void* third, void* fourth, void* fifth)
{
    __m128 sum = _mm_add_ps(*(__m128*)second, *(__m128*)first);

    for (int index = 0; index < m_0c; ++index)
    {
        FUN_00c98820_ArrayObject* object = m_08[index];
        object->vf24(first, &sum, third, fourth, fifth);
    }
}
