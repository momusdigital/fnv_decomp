// gamebryo2.2/corelibs/nimain/niskininstance.cpp: NiSkinInstance, SkinGraph, NiSkinInstanceStub, SkinInstanceW and more (8 functions)

#include "niskininstance_decls.h"
// @fnv 0x00a86340
void NiSkinInstance::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    stream.ResetStreamState();
    if (stream.m_uiNifVersion >= 0x0a010065)
        stream.ResetStreamState();
    stream.ResetStreamState();
    stream.ReadUnsignedInteger();
}
// @fnv 0x00a86380
void NiSkinInstance::LinkObject(NiStream& stream)
{
    NiObject::LinkObject(stream);
    m_pSkinData = stream.GetLoadedObject();
    if (stream.m_uiNifVersion >= 0x0a010065)
        m_pkSkinMeshPartition = stream.GetLoadedObject();
    m_pRootParent = stream.GetLoadedObject();
    unsigned int count = stream.GetLinkID();
    m_ppBones = (NiObject**)_NiMalloc(count * sizeof(NiObject*));
    for (unsigned int i = 0; i < count; ++i)
        m_ppBones[i] = stream.GetLoadedObject();
}

struct A46BB0Object
{
    bool IsEqual(A46BB0Object*);
};

struct FUN_00a864d0_Class
{
    char pad[8];
    void* m_pSkinData;            // +0x08
    void* m_pkSkinMeshPartition;  // +0x0c
    bool FUN_00a864d0(A46BB0Object* pkObject);
};

// @fnv 0x00a864d0
bool FUN_00a864d0_Class::FUN_00a864d0(A46BB0Object* pkObject)
{
    FUN_00a864d0_Class* pkSkinInstance = (FUN_00a864d0_Class*)pkObject;
    if (!((A46BB0Object*)this)->IsEqual(pkObject))
        return false;
    void* pData = *(void**)((char*)this + 8);
    void* pOtherData = *(void**)((char*)pkSkinInstance + 8);
    if (!((bool(__thiscall*)(void*, void*))((void**)*(void**)pData)[0x5c / 4])(pData, pOtherData))
        return false;
    void* pThisPart = *(void**)((char*)this + 0xc);
    if (pThisPart)
    {
        void* pOtherPart = *(void**)((char*)pkSkinInstance + 0xc);
        if (!((bool(__thiscall*)(void*, void*))((void**)*(void**)pThisPart)[0x5c / 4])(pThisPart, pOtherPart))
            return false;
    }
    if (*(void**)((char*)this + 0xc) == 0 && *(void**)((char*)pkSkinInstance + 0xc) != 0)
        return false;
    return true;
}

class NiStream;
struct SkinGraph
{
    void* vtable;
    unsigned int refCount;
    NiObject* skinData;
    NiObject* skinPartition;
    NiObject* rootParent;
    NiObject** bones;
    bool FUN_00a5d2f0(NiStream&);
    bool VisitSkinGraphLinks(NiStream& stream);
};
typedef void(__thiscall* VisitStreamable)(NiObject*, NiStream&);
__forceinline void VisitLinkedObject(NiObject* object, NiStream& stream)
{
    void** methods = *reinterpret_cast<void***>(object);
    reinterpret_cast<VisitStreamable>(methods[21])(object, stream);
}
// @fnv 0x00a86460
bool SkinGraph::VisitSkinGraphLinks(NiStream& stream)
{
    if (!FUN_00a5d2f0(stream))
        return false;
    VisitLinkedObject(skinData, stream);
    if (skinPartition)
        VisitLinkedObject(skinPartition, stream);
    VisitLinkedObject(rootParent, stream);
    unsigned int count = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(skinData) + 0x44);
    for (unsigned int index = 0; index < count; ++index)
    {
        VisitLinkedObject(bones[index], stream);
    }
    return true;
}

class NiSkinDataLink : public NiObject
{
  public:
    NiPointer<NiObject> m_spLink;
};

class NiPtrAssignHelper
{
  public:
    NiObject* p;
    void Assign(NiObject* value);
};

class FUN_00a86740_cls : public NiSkinInstance
{
  public:
    void ClearSkinDataLink(NiStream& stream);
};

// @fnv 0x00a86740
void FUN_00a86740_cls::ClearSkinDataLink(NiStream& stream)
{
    if (stream.m_uiNifVersion >= 0xa010065)
    {
        return;
    }
    if (m_pSkinData.p == 0)
    {
        return;
    }
    NiSkinDataLink* data = (NiSkinDataLink*)m_pSkinData.p;
    reinterpret_cast<NiPtrAssignHelper*>(&m_pkSkinMeshPartition)->Assign(data->m_spLink.p);
    NiPointer<NiObject>& rSkinLink = ((NiSkinDataLink*)m_pSkinData.p)->m_spLink;
    if (rSkinLink.p != 0)
    {
        rSkinLink = 0;
    }
}

void* NiMalloc(unsigned int uiSize);

struct NiAVObjectStub;

struct NiCloneMapStub
{
    bool GetAt(NiAVObjectStub* pkKey, NiAVObjectStub*& pkVal) const;
};

struct NiCloningProcessStub
{
    NiCloneMapStub* m_pCloneMap;
};

struct NiSkinDataStub
{
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
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
    unsigned int m_uiBoneCount;
};

struct NiObjectBaseStub
{
    NiObjectBaseStub() throw();
    virtual ~NiObjectBaseStub();
    unsigned int m_uiRefCount;
};

struct NiSkinInstanceStub : NiObjectBaseStub
{
    NiSkinInstanceStub()
        : m_pkSkinData(0), m_pkSkinPartition(0), m_pRootParent(0), m_ppBones(0), m_uiRendererFlags(0xffffffff),
          PopulateViewerStrings(0), unk20(0), unk24(0), unk28(0), unk30(0)
    {}
    virtual ~NiSkinInstanceStub();
    static void* operator new(unsigned int uiSize);

    NiSkinDataStub* m_pkSkinData;
    void* m_pkSkinPartition;
    NiAVObjectStub* m_pRootParent;
    NiAVObjectStub** m_ppBones;
    unsigned int m_uiRendererFlags;
    void* PopulateViewerStrings;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;

    bool IsCloneable(NiCloningProcessStub& kCloning);
    void CopyMemberData(NiSkinInstanceStub* pkDest, NiCloningProcessStub& kCloning);
    NiSkinInstanceStub* CreateClone(NiCloningProcessStub& kCloning);
};

// Clones the skin instance when cloneable, remapping the skin root and bone objects through the cloning map and copying the bone pointer array.
// @fnv 0x00a86830
NiSkinInstanceStub* NiSkinInstanceStub::CreateClone(NiCloningProcessStub& kCloning)
{
    if (!IsCloneable(kCloning))
        return this;

    NiSkinInstanceStub* pkClone = new NiSkinInstanceStub;
    CopyMemberData(pkClone, kCloning);

    NiAVObjectStub* pkClonedObject = 0;
    pkClone->m_pRootParent =
        kCloning.m_pCloneMap->GetAt(m_pRootParent, pkClonedObject) ? pkClonedObject : m_pRootParent;

    unsigned int uiBones = m_pkSkinData->m_uiBoneCount;
    pkClone->m_ppBones = (NiAVObjectStub**)NiMalloc(uiBones * sizeof(NiAVObjectStub*));
    for (unsigned int i = 0; i < uiBones; i++)
    {
        pkClone->m_ppBones[i] =
            kCloning.m_pCloneMap->GetAt(m_ppBones[i], pkClonedObject) ? pkClonedObject : m_ppBones[i];
    }
    return pkClone;
}

class NiBinaryStreamW
{
  public:
    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int (*m_pfnWrite)(NiBinaryStreamW*, const void*, unsigned int, unsigned int*, unsigned int);

    void Write(const void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiSize = uiBytes;
        BinaryWrite(pvBuffer, uiBytes, &uiSize, 1);
    }
    void BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                     unsigned int uiNumComponents)
    {
        unsigned int uiBytes = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytes;
    }
};

class NiStreamW
{
  public:
    virtual void Vf00();
    virtual void Vf04();
    virtual void Vf08();
    virtual void Vf0c();
    virtual void Vf10();
    virtual void Vf14();
    virtual void Vf18();
    virtual void Vf1c();
    virtual void Vf20();
    virtual void Vf24();
    virtual void Vf28();
    virtual void Vf2c();
    virtual void SaveLinkID(const NiObject* pkObject);
    char m_pad04[0x250 - 4];
    NiBinaryStreamW* m_pBackingStream;
};

inline void SerializeValue(NiStreamW& kStream, const unsigned int& uiValue)
{
    kStream.m_pBackingStream->Write(&uiValue, sizeof(unsigned int));
}

struct NiSkinDataW
{
    char m_pad00[0x44];
    unsigned int m_uiBoneCount;
};

class SkinInstanceW
{
  public:
    void FUN_00a89af0(NiStreamW& kStream);
    void SaveSkinInstance(NiStreamW& kStream);

    void* m_pvVtbl;
    unsigned int m_uiRefCount;
    NiSkinDataW* m_pSkinData;
    NiObject* m_pkSkinMeshPartition;
    NiObject* m_pRootParent;
    NiObject** m_ppBones;
};

// Writes the skin instance's link IDs, bone count and each bone's link ID to the stream.
// @fnv 0x00a867a0
void SkinInstanceW::SaveSkinInstance(NiStreamW& kStream)
{
    FUN_00a89af0(kStream);
    kStream.SaveLinkID((NiObject*)m_pSkinData);
    kStream.SaveLinkID(m_pkSkinMeshPartition);
    kStream.SaveLinkID(m_pRootParent);
    unsigned int uiBones = m_pSkinData->m_uiBoneCount;
    SerializeValue(kStream, uiBones);
    for (unsigned int i = 0; i < uiBones; i++)
        kStream.SaveLinkID(m_ppBones[i]);
}

#include <string.h>
#include <stdio.h>
struct Strings
{
    void* vtable;
    char** data;
    unsigned short capacity, size, count, grow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    void Add(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + grow);
        SetAt(index, value);
    }
    __forceinline void AddInline(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + grow);
        if (index >= size)
        {
            size = (unsigned short)(index + 1);
            if (value)
                ++count;
        }
        else if (value)
        {
            if (!data[index])
                ++count;
        }
        else
        {
            if (data[index])
                --count;
        }
        data[index] = value;
    }
};
struct Named
{
    void* vtable;
    unsigned int refs;
    char* name;
    char* GetName()
    {
        return name;
    }
};
struct Partition : Named
{
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    unsigned int bones;
};
struct Root
{
    unsigned int refs;
    char* name;
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void Describe(Strings*);
};
extern void __stdcall ClearStrings(Strings*);
extern char* globalName;
char* CopyName(char*);
char* Label(const char*, const char*);
char* FUN_00a7d510(const char*, unsigned int);
void* NiMalloc(unsigned int);
void NiFree(void*);
int FUN_00a86280(const void*, const void*);
extern "C" void __cdecl SortNames(void*, unsigned int, unsigned int, int(__cdecl*)(const void*, const void*));
void FUN_00a305b0(char*, unsigned int, const char*, ...);
struct BonePtr
{
    Named* p;
    operator Named*&()
    {
        return p;
    }
    Named*& operator->()
    {
        return p;
    }
};
struct Skin
{
    void* vtable;
    unsigned int refs;
    Partition* skin;
    Root* partition;
    Named* parent;
    BonePtr* bones;
    void GetViewerStrings(Strings*);
};
// Adds skin and parent labels, hardware partition and bone count values, sorted bone labels, then calls partition->Describe.
// @fnv 0x00a86920
void Skin::GetViewerStrings(Strings* apStrings)
{
    ClearStrings(apStrings);
    apStrings->Add(CopyName(globalName));
    if (parent)
        apStrings->Add(Label("Root Parent", parent->GetName()));
    Partition* pPartition = skin;
    if (pPartition)
    {
        unsigned int partitions = (unsigned int)partition;
        if (partitions)
            partitions = (unsigned int)partition->name;
        apStrings->Add(FUN_00a7d510("Hardware partitions", partitions));
        unsigned int uiBoneCount = pPartition->bones;
        apStrings->Add(FUN_00a7d510("Bone Count", uiBoneCount));
        char** ppBoneNames = (char**)NiMalloc(uiBoneCount * sizeof(char*));
        char szBoneName[1000];
        for (unsigned int index = 0; index < uiBoneCount; ++index)
        {
            sprintf(szBoneName, "%s (%08X)", bones[index]->GetName(), bones[index]);
            ppBoneNames[index] = (char*)NiMalloc(strlen(szBoneName) + 1);
            strcpy(ppBoneNames[index], szBoneName);
        }
        SortNames(ppBoneNames, uiBoneCount, 4, FUN_00a86280);
        for (unsigned int index = 0; index < uiBoneCount; ++index)
        {
            char szIndex[10];
            FUN_00a305b0(szIndex, 10, "  %3d", index);
            apStrings->AddInline(Label(szIndex, ppBoneNames[index] ? ppBoneNames[index] : "<noname>"));
        }
        for (unsigned int index = 0; index < uiBoneCount; ++index)
            NiFree(ppBoneNames[index]);
        NiFree(ppBoneNames);
        partition->Describe(apStrings);
    }
}
