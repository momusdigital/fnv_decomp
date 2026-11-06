// src/fallout_shared/bgstextureset_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/bgstextureset.cpp that match byte for byte only
// with VC9 SP1 and /MT /Od /Oy- /GS /EHsc /Gy /GF (unit lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton.


// Fallout: New Vegas decompilation: fallout_shared/bgstextureset.cpp.
#include "bgstextureset_packet.h"
void ResetNullTextureSet();
BGSTextureSet* __cdecl FUN_00593220();
void __cdecl _Deallocate(void*);
struct S591140
{
    void FUN_00591170();
    void* FUN_00591140(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
struct Holder
{
    void FUN_005923c0();
    void* FUN_00592380(unsigned int flags);
};
struct FullNameEx
{
    int _m0;
    int _m1;
    int _m2;
    void SetFullName(char const*);
};
struct Holder00592cc0
{
    char _pad[56];
    FullNameEx _arr[6];
    void SetFullNameByType(int, char const*);
};
struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct FUN_0048e370_obj
{
    void FUN_0048e370(unsigned int);
};
struct FUN_00593320_shell
{
    void FUN_00593320(void*);
};
void __cdecl FUN_00485950(unsigned int, unsigned int);
extern unsigned int DAT_0118c574[6];
struct FUN_00592810_shell
{
    void FUN_00592810();
};
struct FUN_005e79a0_t : public TESForm
{
    bool FUN_00485270(TESForm*);
};
struct FUN_005932e0_shell
{
    bool Compare(void*);
};
struct FUN_005926f0_entry
{
    virtual void FUN_0() = 0;
    virtual void FUN_1() = 0;
    virtual void FUN_2() = 0;
    virtual bool Compare(void*) = 0;
};
struct FUN_005926f0_texture
{
    char _pad[0x80];
    FUN_005932e0_shell* _compareObject;
    unsigned short _flags;
};
struct FUN_005926f0_shell
{
    char _pad[0x80];
    FUN_005932e0_shell* _compareObject;
    unsigned short _flags;

    bool CompareTextureSet(TESForm* apCompare);
};
struct DecalDataOwned : public DecalData
{
    ~DecalDataOwned();
};
struct BoundObjectCopier
{
    void CopyBoundObject(TESForm* apForm);
};
struct BGSTextureSetCopy : public BGSTextureSet
{
    void CopyFromTextureSet(TESForm* apForm);
};
struct DecalDataCopier
{
    void Copy(DecalData* apSrc);
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* object = 0);
    ~NiPointer();
    NiPointer<T>& operator=(const NiPointer<T>& other);
};
class NiTexture
{
  public:
    void IncRefCount();
    void DecRefCount();
};
class BSShaderManager
{
  public:
    static void GetTexture(const char* apPath, bool abFlag, NiPointer<NiTexture>& arspTexture, bool abFlag2,
                           bool abFlag3);
};
int FUN_00406d30(char*, unsigned int, const char*);
struct TexSetIface
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
    virtual const char* GetTextureFilePath(int aeTextureType);
    virtual void GetTextureByType(int aeTextureType, NiPointer<NiTexture>& arspTexture);
};
struct FormBase9
{
    virtual void f00();
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
};
struct TexSetB : FormBase9, TexSetIface
{
    virtual void GetTextureByType(int aeTextureType, NiPointer<NiTexture>& arspTexture);
};
namespace s593030 {

struct ValueList
{
    int unk00;
    int unk04;
    int unk08;

    void FUN_00489100(int iValue);
};

struct Owner
{
    int unk00;
    int unk04;
    ValueList m_kList0;
    ValueList m_kList1;
    ValueList m_kList5;
    ValueList m_kList2;
    ValueList m_kList3;
    ValueList m_kList4;

    void FUN_00593030(unsigned int uiType, int iValue);
};

// @fnv 0x00593030
void Owner::FUN_00593030(unsigned int uiType, int iValue)
{
    switch (uiType)
    {
    case 0:
        m_kList0.FUN_00489100(iValue);
        break;
    case 1:
        m_kList1.FUN_00489100(iValue);
        break;
    case 2:
        m_kList2.FUN_00489100(iValue);
        break;
    case 3:
        m_kList3.FUN_00489100(iValue);
        break;
    case 4:
        m_kList4.FUN_00489100(iValue);
        break;
    case 5:
        m_kList5.FUN_00489100(iValue);
        break;
    }
}

}

struct S_005923c0_Base0
{
    virtual ~S_005923c0_Base0();
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
};

struct S_005923c0_Sec
{
    virtual void unk00();
    int unk04;
    ~S_005923c0_Sec();
};

struct S_005923c0_Elem
{
    int unk00;
    int unk04;
    int unk08;
    ~S_005923c0_Elem();
};

struct FUN_005923c0 : S_005923c0_Base0, S_005923c0_Sec
{
    S_005923c0_Elem m_38[6];
    virtual ~FUN_005923c0();
    virtual void ClearData();
};

// @fnv 0x005923c0
FUN_005923c0::~FUN_005923c0()
{
    ClearData();
}
