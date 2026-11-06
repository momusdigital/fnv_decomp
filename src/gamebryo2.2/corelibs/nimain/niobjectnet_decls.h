// gamebryo2.2/corelibs/nimain/niobjectnet_decls.h: declares NiAVObject, NiObject, NiInterpolator, NiMorphData, MorphTarget and more
#ifndef NIOBJECTNET_PRIVATE_DECLS_H
#define NIOBJECTNET_PRIVATE_DECLS_H

#include "niobjectnet_bhk_decls.h"
#include "NiRefObject.h"
#include "NiFixedString.h"

class NiStream;
class CloningProcess;
class NiExtraData;
class NiTimeController;
class NiInterpolator;
class TESObjectREFR;
class NiAVObject
{
  public:
    NiExtraData* GetExtraData(const NiFixedString&);
};

class NiObject : public NiRefObject
{
  public:
    virtual void Slot02()
    {}
    virtual void Slot03()
    {}
    virtual void Slot04()
    {}
    virtual void Slot05()
    {}
    virtual void Slot06()
    {}
    virtual void Slot07()
    {}
    virtual void Slot08()
    {}
    virtual void Slot09()
    {}
    virtual void Slot10()
    {}
    virtual void Slot11()
    {}
    virtual void Slot12()
    {}
    virtual void Slot13()
    {}
    virtual void Slot14()
    {}
    virtual void Slot15()
    {}
    virtual void Slot16()
    {}
    virtual void Slot17()
    {}
    virtual void Slot18()
    {}
    virtual void Slot19()
    {}
    virtual void Slot20()
    {}
    virtual void Slot21()
    {}
    virtual void Slot22()
    {}
    virtual void Slot23()
    {}
    virtual void Slot24()
    {}
    virtual void Slot25()
    {}
    virtual void ProcessClone(CloningProcess&);
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
};

class NiInterpolator : public NiObject
{
};

class NiMorphData
{
  public:
    class MorphTarget : public NiObject
    {
      public:
        char m_kPad008[4];
        NiInterpolator* m_spTargetInterpolator;
        void SetTargetInterpolator(NiInterpolator*);
    };
};

class NiExtraData : public NiObject
{
  public:
    NiFixedString m_kName;
};

class NiTimeController : public NiObject
{
  public:
    char pad008[0x28];
    NiTimeController* m_spNextController;
};

class NiObjectNET : public NiObject
{
  public:
    NiFixedString m_kName;
    NiTimeController* m_pControllers;
    NiExtraData** m_ppExtraData;
    unsigned short m_usExtraDataCount;
    unsigned short m_usMaxSize;
    char m_kPad018[0x84];
    NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> > m_kArray;

    virtual void LoadBinary(NiStream&);
    virtual void ProcessClone(CloningProcess&);
    void SetFlags(unsigned short);
    void FUN_00439360(unsigned short, unsigned int, unsigned int);
    void AddController(NiTimeController*);
    void GetNumChildren();
    bool ResizeExtraData(unsigned short);
    void ClearAnimationControllers();
    void RefreshExtraData();
    bool AddExtraData(NiExtraData*);
    virtual void LinkObject(NiStream&);
};

extern char g_NiObjectNETExtraDataLock;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
void* __cdecl _NiMalloc(unsigned int);
void __cdecl NiFree(void*);
extern "C" void* __cdecl fnv_zlib_memcpy(void*, const void*, unsigned int);

class NiStream
{
  public:
    char m_kPad000[0xD8];
    unsigned int m_uiNifVersion;
    void ReadFixedString(NiFixedString&);
    void ReadStringTableEntry(NiFixedString&);
    void ResetStreamState();
    unsigned int ReadUnsignedInteger();
    NiObject* GetLoadedObject();
    unsigned int GetLinkID();
};

#endif
