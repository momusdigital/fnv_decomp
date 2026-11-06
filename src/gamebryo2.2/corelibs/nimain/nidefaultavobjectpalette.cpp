// gamebryo2.2/corelibs/nimain/nidefaultavobjectpalette.cpp: NiDefaultAVObjectPalette, Map, PaletteOwner, PaletteShell and more (18 functions)

#include "nidefaultavobjectpalette_types_NiDefaultAVObjectPalette.h"
#include "nidefaultavobjectpalette_types_NiAVObject.h"
#include "nidefaultavobjectpalette_types_NiStream.h"
#include "nidefaultavobjectpalette_types_NiInterpolator.h"
#include "nidefaultavobjectpalette_types_NiGlobalStringTable.h"
#include "nidefaultavobjectpalette_decls.h"

void AddObjectToPalette(NiAVObject*, NiDefaultAVObjectPalette*);

struct NiDefaultPaletteNodeChildren
{
    unsigned char m_data[0xA0];
    NiAVObject** m_children;
    unsigned short m_usMaxSize;
    unsigned short m_usArraySize;
};

// @fnv 0x00a6e870
void AddObjectToPalette(NiAVObject* object, NiDefaultAVObjectPalette* palette)
{
    if (!object)
        return;
    if (!palette)
        return;

    if (object->m_kName.m_kHandle)
        palette->AddNamedAVObject(object->m_kName, object);

    NiNode* node = object->GetNiNode();
    if (node)
    {
        NiDefaultPaletteNodeChildren* children = (NiDefaultPaletteNodeChildren*)node;
        for (unsigned int i = 0; i < children->m_usArraySize; ++i)
            AddObjectToPalette(children->m_children[i], palette);
    }
}

// @fnv 0x00a6e960
void NiDefaultAVObjectPalette::BuildPalette()
{
    if (m_pkScene)
    {
        m_kObjectMap.RemoveAll();
        AddObjectToPalette(m_pkScene, this);
    }
}

// Loads the scene object and a count-prefixed list of name/object pairs from the stream, registering each pair in the palette.
// @fnv 0x00a6ea40
void NiDefaultAVObjectPalette::LoadBinary(NiStream& stream)
{
    ((NiInterpolator*)this)->NiInterpolator::LoadBinary(stream);
    m_pkScene = (NiAVObject*)stream.DeserializeObject();

    unsigned int count = 0;
    ReadBinaryValue(stream, count);

    if (count > 0)
    {
        do
        {
            --count;
            char* string = 0;
            stream.ReadStreamString(string);
            NiAVObject* object = (NiAVObject*)stream.DeserializeObject();
            if (string && object)
            {
                NiFixedString name;
                name.m_kHandle = NiGlobalStringTable::AddString(string);
                AddNamedAVObject(name, object);
                if (name.m_kHandle != EmptyFS.m_kHandle)
                {
                    InterlockedDecrement((volatile long*)(name.m_kHandle - 8));
                }
            }
            NiFree(string);
        } while (count > 0);
    }
}

struct FUN_00a6e960_shell : public NiDefaultAVObjectPalette
{
    void FUN_00a6e960();
};

// @fnv 0x00a6e960
void FUN_00a6e960_shell::FUN_00a6e960()
{
    if (m_pkScene)
    {
        m_kObjectMap.RemoveAll();
        AddObjectToPalette(m_pkScene, this);
    }
}

struct P03MM
{
    void* __thiscall Allocate(unsigned int);
};
extern P03MM g_memoryManager;

// @fnv 0x00a6ef50
void* __cdecl FUN_00a6ef50()
{
    void* p = g_memoryManager.Allocate(0xC);
    if (!p)
        p = 0;
    ((int*)p)[1] = 0;
    return p;
}

// Assigns the pointer from p2 into p1's slot with reference counting, and stores p3 alongside it.
// @fnv 0x00a6e550
void __stdcall AssignSharedPtr(void* apTarget, void* apSource, void* apValue)
{
    void* v = *(void**)apSource;
    if (*(void**)((char*)apTarget + 4) != v)
    {
        if (v != *(void**)&EmptyFS)
            InterlockedIncrement((long*)((char*)v - 8));
        void* old = *(void**)((char*)apTarget + 4);
        if (old != *(void**)&EmptyFS)
            InterlockedDecrement((long*)((char*)old - 8));
        *(void**)((char*)apTarget + 4) = v;
        *(void**)((char*)apTarget + 8) = apValue;
        return;
    }
    *(void**)((char*)apTarget + 8) = apValue;
}

struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern int DAT_0109ca08;
extern int DAT_0109ca18;
struct FUN_00a6eb20_Holder
{
    void* __thiscall DestroyHolder(unsigned int);
};
// Resets the two embedded maps, frees the pointer at offset 8, and optionally deallocates the object when flag bit 0 is set.
// @fnv 0x00a6eb20
void* __thiscall FUN_00a6eb20_Holder::DestroyHolder(unsigned int auiFlags)
{
    NiTFixedStringMap_NiAVObject___* p = (NiTFixedStringMap_NiAVObject___*)this;
    *(void**)this = (void*)&DAT_0109ca18;
    p->RemoveAll();
    *(void**)this = (void*)&DAT_0109ca08;
    p->RemoveAll();
    NiFree(*(void**)((char*)this + 8));
    if (auiFlags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}

struct NodeChildrenView_cls
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
    NiAVObject** m_children;
    unsigned short m_usMaxSize;
    unsigned short m_usArraySize;
};

// @fnv 0x00a6e870
void __cdecl AddObjectToPaletteRecursive(NiAVObject* apObject, NiDefaultAVObjectPalette* apPalette)
{
    if (apObject == 0)
        return;
    if (apPalette == 0)
        return;
    if (apObject->m_kName.m_kHandle != 0)
        apPalette->AddNamedAVObject(apObject->m_kName, apObject);
    NodeChildrenView_cls* node = (NodeChildrenView_cls*)apObject->GetNiNode();
    if (node == 0)
        return;
    unsigned int i = 0;
    if ((unsigned short)i < node->m_usArraySize)
    {
        do
        {
            AddObjectToPaletteRecursive(node->m_children[i], apPalette);
            i++;
        } while (i < node->m_usArraySize);
    }
}

struct S_00a6e8e0_Object
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual NiDefaultPaletteNodeChildren* vf03();
    int unk04;
    int m_08;
};

struct S_00a6e8e0_Palette
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
    virtual void vf36(int* name, int flag);
};

// @fnv 0x00a6e8e0
void __cdecl FUN_00a6e8e0(S_00a6e8e0_Object* object, S_00a6e8e0_Palette* palette)
{
    if (object == 0)
        return;
    if (palette == 0)
        return;
    if (object->m_08 != 0)
        palette->vf36(&object->m_08, 0);
    NiDefaultPaletteNodeChildren* children = object->vf03();
    if (children == 0)
        return;
    for (unsigned int i = 0; i < children->m_usArraySize; ++i)
        FUN_00a6e8e0((S_00a6e8e0_Object*)children->m_children[i], palette);
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
extern "C" void* __cdecl FUN_00aa1070(unsigned int size);
extern "C" void* __cdecl FUN_00ec61c0(void* buffer, int value, unsigned int size);
extern "C" unsigned char DAT_01096284;
extern "C" unsigned char DAT_01096114;
extern "C" unsigned char DAT_0109618c;
struct PaletteBase
{
    void* vtable;
    unsigned int unknown;
    void __thiscall FUN_00a5d3a0();
    __forceinline PaletteBase() throw()
    {
        FUN_00a5d3a0();
        vtable = &DAT_01096284;
    }
};
struct PaletteHash
{
    void* vtable;
    unsigned int capacity;
    void* buckets;
    unsigned int count;
    __forceinline PaletteHash() throw()
    {
        vtable = &DAT_01096114;
        capacity = 37;
        count = 0;
        buckets = FUN_00aa1070(148);
        FUN_00ec61c0(buckets, 0, capacity * 4);
        vtable = &DAT_0109618c;
    }
};
struct PaletteObject : PaletteBase
{
    PaletteHash hash;
    void* scene;
    static __forceinline void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
    __forceinline PaletteObject() throw() : PaletteBase(), hash(), scene(0)
    {}
};
struct PaletteOwner
{
    void __thiscall FUN_00aa1000(PaletteObject* palette, void* argument);
    PaletteObject* __thiscall CreatePalette(void* argument);
};
// Allocates a PaletteObject, initializes it via FUN_00aa1000 with argument, and returns it.
// @fnv 0x00a6ef70
PaletteObject* PaletteOwner::CreatePalette(void* argument)
{
    PaletteObject* palette = new PaletteObject;
    FUN_00aa1000(palette, argument);
    return palette;
}

struct BC1F550Point3
{
    float x;
    float y;
    float z;
};

extern const BC1F550Point3 g_kC1F550Zero;

class BC1F550Geometry;

template <class T> class BC1F550GeometryPointer
{
  public:
    T* m_pObject;
};

template <class T> class BC1F550NewInterface
{
  public:
    static T* Allocate(unsigned int auiCount);
};

template <class T> class BC1F550MallocInterface
{
  public:
    static T* Allocate(unsigned int auiCount);
};

template <class T, class TAlloc> class BC1F550Array
{
  public:
    BC1F550Array(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) throw()
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = TAlloc::Allocate(m_usMaxSize);
        else
            m_pBase = 0;
    }
    virtual ~BC1F550Array();

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

template <class T> class BC1F550ObjectArray : public BC1F550Array<T, BC1F550NewInterface<T> >
{
  public:
    BC1F550ObjectArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) throw()
        : BC1F550Array<T, BC1F550NewInterface<T> >(uiMaxSize, uiGrowBy)
    {}
    virtual ~BC1F550ObjectArray();
};

template <class T> class BC1F550PrimitiveArray : public BC1F550Array<T, BC1F550MallocInterface<T> >
{
  public:
    BC1F550PrimitiveArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) throw()
        : BC1F550Array<T, BC1F550MallocInterface<T> >(uiMaxSize, uiGrowBy)
    {}
    virtual ~BC1F550PrimitiveArray();
};

class BC1F550Emitter
{
  public:
    BC1F550Emitter() throw();
    virtual ~BC1F550Emitter();

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
};

class FUN_00c1f550_cls : public BC1F550Emitter
{
  public:
    FUN_00c1f550_cls() throw();
    virtual ~FUN_00c1f550_cls();

    BC1F550ObjectArray<BC1F550GeometryPointer<BC1F550Geometry> > m_kGeometryEmitters;
    BC1F550PrimitiveArray<unsigned int> m_kEmitterTypes;
    int m_eInitVelocityType;
    int m_eEmissionType;
    BC1F550Point3 m_kEmitterPoint;
};

// @fnv 0x00c1f550
FUN_00c1f550_cls::FUN_00c1f550_cls() throw()
    : m_kGeometryEmitters(1, 2), m_kEmitterTypes(0, 1), m_eInitVelocityType(0), m_eEmissionType(0),
      m_kEmitterPoint(g_kC1F550Zero)
{}

template <class Alloc, class K, class V> class NiTMapBase
{
  public:
    bool GetAt(const K key, V& val) const;
};

class CloningProcess
{
  public:
    NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, NiObject*>* m_pCloneMap;
};

struct NiObjectCloneBase
{
    void ProcessClone(CloningProcess& kCloning);
};

inline void* FirstPos(const NiTFixedStringMap_NiAVObject___& m)
{
    for (unsigned int i = 0; i < m.m_uiHashSize; i++)
    {
        if (m.m_ppkHashTable[i])
            return m.m_ppkHashTable[i];
    }
    return 0;
}

struct PaletteShell : public NiDefaultAVObjectPalette
{
    void FUN_00a6e5b0(CloningProcess& kCloning);
};

// @fnv 0x00a6e5b0
void PaletteShell::FUN_00a6e5b0(CloningProcess& kCloning)
{
    ((NiObjectCloneBase*)this)->ProcessClone(kCloning);

    NiFixedString kName;
    NiObject*& pkClone = reinterpret_cast<NiObject*&>(kName.m_kHandle);
    pkClone = 0;
    kCloning.m_pCloneMap->GetAt(this, pkClone);
    PaletteShell* pkDest = (PaletteShell*)pkClone;

    if (m_pkScene)
    {
        kCloning.m_pCloneMap->GetAt(m_pkScene, pkClone);
        pkDest->m_pkScene = (NiAVObject*)pkClone;
    }

    if (m_kObjectMap.m_kItemCount.m_uiCount)
    {
        void* pos = FirstPos(m_kObjectMap);
        while (pos)
        {
            kName.m_kHandle = EmptyFS.m_kHandle;
            NiAVObject* pkObj;
            m_kObjectMap.GetNext(pos, kName, pkObj);
            if (kName.m_kHandle && pkObj)
            {
                NiObject* pkObjClone;
                if (kCloning.m_pCloneMap->GetAt(pkObj, pkObjClone))
                    pkDest->AddNamedAVObject(kName, (NiAVObject*)pkObjClone);
            }
            if (kName.m_kHandle != EmptyFS.m_kHandle)
                InterlockedDecrement((volatile long*)(kName.m_kHandle - 8));
        }
    }
}

bool __stdcall FUN_00a84c70(void*);

// @fnv 0x00a6e540
bool __stdcall FUN_00a6e540(void* p)
{
    return FUN_00a84c70(p);
}

extern char* DAT_0109b220;
extern "C" void(__stdcall* DAT_00fdf1c4)(void*);

struct PaletteMap
{
    void* unk00;
    int unk04;
    void* unk08;
    unsigned int m_uiItemCount;
    void* FUN_00ee8ac0();
    void FUN_00a8f770(void** iterator, char** key, void** object);
};
class FUN_00a6e7b0_class
{
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
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
    virtual int vf35(char** key);
    int unk04;
    PaletteMap m_map;
    bool FUN_00a88a50(FUN_00a6e7b0_class* other);
    bool IsEqual(FUN_00a6e7b0_class* other);
};
// @fnv 0x00a6e7b0
bool FUN_00a6e7b0_class::IsEqual(FUN_00a6e7b0_class* other)
{
    if (!FUN_00a88a50(other))
        return false;
    unsigned int num = m_map.m_uiItemCount;
    if (other->m_map.m_uiItemCount != num)
        return false;
    if (num)
    {
        void* iterator = m_map.FUN_00ee8ac0();
        if (iterator)
        {
            void(__stdcall * deallocate)(void*) = DAT_00fdf1c4;
            do
            {
                char* key = DAT_0109b220;
                void* object;
                m_map.FUN_00a8f770(&iterator, &key, &object);
                if (!other->vf35(&key))
                {
                    if (key != DAT_0109b220)
                        deallocate(key - 8);
                    return false;
                }
                if (key != DAT_0109b220)
                    deallocate(key - 8);
            } while (iterator != 0);
        }
    }
    return true;
}

struct MapNoAlias : NiTFixedStringMap_NiAVObject___
{
    __declspec(noalias) void GetNext(void*&, NiFixedString&, NiAVObject*&) const;
};
struct StreamSaveShell : public NiStream
{
    void FUN_00a64160(const char* pcString);
};

struct PaletteSaveShell : public NiDefaultAVObjectPalette
{
    void SaveBinary(NiStream& kStream);
    void FUN_00a724d0(NiStream& kStream);
};

typedef void(__thiscall* NiStreamLinkObject)(NiStream*, NiAVObject*);

template <class T> void WriteBinaryArray(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumValues)
{
    unsigned int uiComponentSize = sizeof(T);
    kOstr.m_uiStreamFlags += kOstr.m_pfnWrite(&kOstr, pValue, sizeof(T) * uiNumValues, &uiComponentSize, 1);
}

// @fnv 0x00a6e6c0
void PaletteSaveShell::SaveBinary(NiStream& kStream)
{
    FUN_00a724d0(kStream);

    ((NiStreamLinkObject)kStream.m_ppVirtualMethodTable[12])(&kStream, m_pkScene);

    unsigned int uiObjectCount = m_kObjectMap.m_kItemCount.m_uiCount;
    NiBinaryStream* pkOstr = kStream.m_pBackingStream;
    WriteBinaryArray(*pkOstr, &uiObjectCount, 1);

    if (m_kObjectMap.m_kItemCount.m_uiCount != 0)
    {
        void* pvPos = FirstPos(m_kObjectMap);
        while (pvPos)
        {
            NiFixedString kKey;
            const char* pcKey;
            kKey.m_kHandle = EmptyFS.m_kHandle;
            NiAVObject* pkObject;
            ((MapNoAlias&)m_kObjectMap).GetNext(pvPos, kKey, pkObject);
            pcKey = kKey.m_kHandle;
            ((StreamSaveShell&)kStream).FUN_00a64160(pcKey);
            ((NiStreamLinkObject)kStream.m_ppVirtualMethodTable[12])(&kStream, pkObject);
            if (pcKey != EmptyFS.m_kHandle)
                InterlockedDecrement((volatile long*)(pcKey - 8));
        }
    }
}

void __cdecl CreateVertexBufferSet();
// @fnv 0x00aa1000
void __cdecl FUN_00aa1000()
{
    CreateVertexBufferSet();
}

// Adapted from another contributor's unverified best attempt; prior model was not supplied.

struct ViewerMemoryManager
{
    void* Allocate(unsigned int uiSize) throw();
};
extern ViewerMemoryManager g_viewerMemoryManager;
extern "C" int __cdecl sprintf(char*, const char*, ...);
char* FUN_00a7d330(const char* pcName);
extern const char* g_011f4a04;
extern char* g_nullFixedStringHandle;
struct ViewerStrings
{
    void** m_ppVirtualMethodTable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize) throw();
    void SetAt(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element)
                m_usESize++;
        }
        else
        {
            if (element)
            {
                if (!m_pBase[uiIndex])
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex])
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int Add(char*& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
};
struct PaletteBaseViewer
{
    void GetViewerStrings(ViewerStrings* pkStrings);
};
struct ViewerFixedString
{
    char* m_kHandle;
    ViewerFixedString() : m_kHandle(g_nullFixedStringHandle)
    {}
};
struct PaletteHashViewer
{
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    void* GetFirstPos()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    __declspec(noalias) void GetNext(void*& pos, ViewerFixedString& kName, NiAVObject*& pkObj) const throw();
};
struct NiDefaultAVObjectPaletteViewer : public NiDefaultAVObjectPalette
{
    void FUN_00a6ed90(ViewerStrings* pkStrings);
};
// Adds a formatted scene-name line and object-map keys to pkStrings, decrementing non-sentinel key handles.
// @fnv 0x00a6ed90
void NiDefaultAVObjectPaletteViewer::FUN_00a6ed90(ViewerStrings* pkStrings)
{
    ((PaletteBaseViewer*)this)->GetViewerStrings(pkStrings);
    char* pcRTTI = FUN_00a7d330(g_011f4a04);
    pkStrings->Add(pcRTTI);
    char* pcScene = (char*)g_viewerMemoryManager.Allocate(0x60);
    sprintf(pcScene, "m_pkScene = %s", m_pkScene->m_kName.m_kHandle ? m_pkScene->m_kName.m_kHandle : "UNKNOWN");
    pkStrings->Add(pcScene);
    if (m_kObjectMap.m_kItemCount.m_uiCount)
    {
        PaletteHashViewer* pkHash = (PaletteHashViewer*)&m_kObjectMap;
        void* pos = pkHash->GetFirstPos();
        while (pos)
        {
            ViewerFixedString kName;
            NiAVObject* pkObj;
            pkHash->GetNext(pos, kName, pkObj);
            char* pcName = (char*)g_viewerMemoryManager.Allocate(0x60);
            char* pcKey = kName.m_kHandle;
            sprintf(pcName, "%s", pcKey);
            pkStrings->Add(pcName);
            if (pcKey != g_nullFixedStringHandle)
                InterlockedDecrement((long*)(pcKey - 8));
        }
    }
}

#include <string.h>
extern int DAT_0109ca08;
extern int DAT_0109ca18;
extern NiFixedString EmptyFS;

void* __cdecl NiMalloc(unsigned int);
void __cdecl FUN_00aa10f0(void*);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
struct Key
{
    const char* text;
    __forceinline Key()
    {}
    __forceinline Key(const char* value);
    __forceinline void Release()
    {
        if (text != EmptyFS.m_kHandle)
            DAT_00fdf1c4((long*)text - 2);
    }
};
struct StringPool
{
    static char* __cdecl AddString(const char*);
};
__forceinline Key::Key(const char* value)
{
    text = StringPool::AddString(value);
}
struct Obj
{
    int vptr;
    int refs;
    const char* name;
};
struct Item
{
    Item* next;
    const char* key;
    Obj* value;
};
struct Map
{
    void* vtable;
    unsigned int size;
    Item** buckets;
    unsigned int count;
    __forceinline Map()
    {
        vtable = &DAT_0109ca08;
        size = 37;
        count = 0;
        buckets = (Item**)NiMalloc(148);
        fnv_zlib_memset(buckets, 0, size * 4);
        vtable = &DAT_0109ca18;
    }
    void __thiscall FUN_00aa01f0();
    __forceinline void Destroy()
    {
        vtable = &DAT_0109ca18;
        FUN_00aa01f0();
        vtable = &DAT_0109ca08;
        FUN_00aa01f0();
        FUN_00aa10f0(buckets);
    }
    __forceinline void* First() const
    {
        for (unsigned int index = 0; index < size; ++index)
            if (buckets[index])
                return buckets[index];
        return 0;
    }
    void __thiscall FUN_00a8f770(void*&, Key&, Obj*&);
    void __thiscall FUN_00a6e980(const Key&, const void*);
    void __thiscall RemoveKey(const Key&);
    __forceinline bool GetAt(const Key& key, Obj*& value)
    {
        Item* item = buckets[(unsigned int)key.text % size];
        while (item)
        {
            if (key.text == item->key)
            {
                value = item->value;
                return true;
            }
            item = item->next;
        }
        return false;
    }
};

extern "C" void(__stdcall* DAT_00fdf1c0)(void*);
struct MapDispatch
{
    void* destroy;
    Item*(__thiscall* allocate)(Map*);
    void(__thiscall* release)(Map*, Item*);
};
__declspec(noinline) void __stdcall AssignEntry(Item* item, const Key& key, const void* value)
{
    const char* fresh = key.text;
    if (item->key != fresh)
    {
        if (fresh != EmptyFS.m_kHandle)
            DAT_00fdf1c0((long*)fresh - 2);
        if (item->key != EmptyFS.m_kHandle)
            DAT_00fdf1c4((long*)item->key - 2);
        item->key = fresh;
    }
    item->value = (Obj*)value;
}
__declspec(noinline) void Map::FUN_00a6e980(const Key& key, const void* value)
{
    unsigned int hash = (unsigned int)key.text % size;
    Item* cursor = buckets[hash];
    while (cursor)
    {
        if (cursor->key == key.text)
        {
            AssignEntry(cursor, key, value);
            return;
        }
        cursor = cursor->next;
    }
    Item* added = ((MapDispatch*)vtable)->allocate(this);
    AssignEntry(added, key, value);
    added->next = buckets[hash];
    buckets[hash] = added;
    ++count;
}

__declspec(noinline) void Map::RemoveKey(const Key& key)
{
    unsigned int hash = (unsigned int)key.text % size;
    Item** link = buckets + hash;
    while (*link)
    {
        Item* item = *link;
        if (item->key == key.text)
        {
            *link = item->next;
            ((MapDispatch*)vtable)->release(this, item);
            --count;
            return;
        }
        link = &item->next;
    }
}

struct Palette
{
    int vptr;
    int refs;
    Map map;
    void __thiscall CloneBase(void*);
    void __thiscall LinkObject(void*);
};
// Clones the base object, then renames palette entries whose key differs from the object name by moving them in the map under the new key.
// @fnv 0x00a6eb60
void Palette::LinkObject(void* apDest)
{
    CloneBase(apDest);
    Map changes;
    apDest = map.First();
    while (apDest)
    {
        Key key;
        key.text = EmptyFS.m_kHandle;
        Obj* object;
        map.FUN_00a8f770(apDest, key, object);
        const char* pcKey;
        const char* name;
        if (key.text && object && (pcKey = key.text, (name = object->name) != 0) && strcmp(pcKey, name))
        {
            changes.FUN_00a6e980(key, name);
            if (pcKey != EmptyFS.m_kHandle)
                DAT_00fdf1c4((long*)pcKey - 2);
        }
        else if (key.text != EmptyFS.m_kHandle)
            DAT_00fdf1c4((long*)key.text - 2);
    }
    apDest = changes.First();
    while (apDest)
    {
        Key key;
        key.text = EmptyFS.m_kHandle;
        Obj* name;
        Obj* object = 0;
        changes.FUN_00a8f770(apDest, key, name);
        if (key.text && name)
        {
            const char* pcKey = key.text;
            Key keyNew((const char*)name);
            Key keyOld;
            keyOld.text = pcKey;
            map.GetAt(keyOld, object);
            const char* pcNewKey = keyNew.text;
            map.FUN_00a6e980(keyNew, object);
            map.RemoveKey(key);
            if (pcNewKey != EmptyFS.m_kHandle)
                DAT_00fdf1c4((long*)pcNewKey - 2);
            if (pcKey != EmptyFS.m_kHandle)
                DAT_00fdf1c4((long*)pcKey - 2);
        }
        else if (key.text != EmptyFS.m_kHandle)
            DAT_00fdf1c4((long*)key.text - 2);
    }
    changes.Destroy();
}
