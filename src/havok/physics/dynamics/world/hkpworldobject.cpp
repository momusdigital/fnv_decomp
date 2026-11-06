
// src/havok/physics/dynamics/world/hkpworldobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/hkpworldobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpWorldObject.h"

// @fnv 0x00cd2930
int __stdcall setShape(int a1)
{
    return 1;
}

class hkMemoryAllocatorCD2B;

struct hkMemoryRouterCD2B
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCD2B* m_pStreamAllocator;
    hkMemoryAllocatorCD2B& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterCD2B {
extern "C" hkMemoryRouterCD2B& __cdecl FUN_00c85750() throw();
}

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

struct hkEntryCD2B
{
    void* m_key;
    int unk04;
    struct Value
    {
        int m_kPointA;
        int m_kPointB;
    };
    Value m_uiFilterValue;
};

template <class T> class hkArrayCD2B
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& AllocatePair()
    {
        hkMemoryAllocatorCD2B& kAlloc = hkRouterCD2B::FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        return m_data[m_iElementCount++];
    }
};

class hkOwnerCD2B
{
  public:
    int unk00[0x1e];
    hkArrayCD2B<hkEntryCD2B> m_entries;

    void AddEntry(void* key, hkEntryCD2B::Value v);
};

// Scans m_entries for an entry with the given key and returns if found; otherwise appends a new entry storing the key and value.
// @fnv 0x00cd2be0
void hkOwnerCD2B::AddEntry(void* key, hkEntryCD2B::Value v)
{
    for (int i = 0; i < m_entries.m_iElementCount; i++)
    {
        if (m_entries.m_data[i].m_key == key)
            return;
    }
    hkEntryCD2B& e = m_entries.AllocatePair();
    e.m_uiFilterValue = v;
    e.m_key = key;
}

extern char DAT_0105c390;
extern char DAT_010cb2d8;
extern char DAT_01020e44;
extern char DAT_010cb2c8;
void* __cdecl FUN_00d06f80(void* data, int bytes);

struct hkStreamWriter
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void WriteField(const void* field, const void* data, int flags);
    virtual void v10();
    virtual void WriteArray(int kind, const void* field, const void* data, int bytes, void* allocation);

    int unk04;
    int unk08;
    int unk0C;
    unsigned char m_includeOwned;

    void DispatchWithMode(const void* field, const void* data, int bytes, int flags);
};

struct FNVWorldObject : hkpWorldObject
{
    void WriteToStream(hkStreamWriter* writer, int unused);
};

// Writes collision shape, collision entries, properties, and bounding volume child shape data to the stream writer.
// @fnv 0x00cd2b00
void FNVWorldObject::WriteToStream(hkStreamWriter* writer, int unused)
{
    writer->WriteField(&DAT_0105c390, m_kCollidable.m_pCollisionShape, 0);

    hkArray<char>& collisionEntries = m_kCollidable.m_kCollisionEntries;
    int entryCap = collisionEntries.m_iCapacityState;
    if ((entryCap & 0x80000000) == 0 || writer->m_includeOwned)
    {
        void* entryData = collisionEntries.m_data;
        void* copy = FUN_00d06f80(entryData, (entryCap & 0x3fffffff) * 8);
        writer->WriteArray(3, &DAT_010cb2d8, collisionEntries.m_data, collisionEntries.m_iElementCount * 8, copy);
    }

    int propCap = m_kProperties.m_iCapacityState;
    if ((propCap & 0x80000000) == 0 || writer->m_includeOwned)
    {
        void* propData = m_kProperties.m_data;
        void* copy = FUN_00d06f80(propData, (propCap & 0x3fffffff) * 16);
        writer->WriteArray(3, &DAT_01020e44, m_kProperties.m_data, m_kProperties.m_iElementCount * 16, copy);
    }

    hkpCollidableBoundingVolumeData& bounds = m_kCollidable.m_kBoundingVolumeData;
    void* firstChild = bounds.m_pChildShapeAabbs;
    if (firstChild)
    {
        writer->DispatchWithMode(&DAT_010cb2c8, firstChild, (unsigned int)bounds.m_uiCapacityChildShapeAabbs * 32, 0);
        writer->DispatchWithMode(&DAT_010cb2c8, bounds.m_pChildShapeKeys,
                                 (unsigned int)bounds.m_uiCapacityChildShapeAabbs * 4, 0);
    }
}

struct hkFinishLoadedObjectFlagCD2C
{
    int m_bFinishing;
};

namespace FUN_00cb0a70 {
class hkStringPtr
{
  public:
    hkStringPtr(hkFinishLoadedObjectFlagCD2C flag) throw();
    const char* m_pcText;
};
}

namespace hkCD2C {
class hkReferencedObject
{
  public:
    hkReferencedObject(hkFinishLoadedObjectFlagCD2C)
    {}
    virtual void unkVirtual00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

template <class T> class hkArray
{
  public:
    hkArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    hkArray(hkFinishLoadedObjectFlagCD2C)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkpCdBody
{
  public:
    hkpCdBody(hkFinishLoadedObjectFlagCD2C)
    {}
    void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    void* m_pMotionState;
    hkpCdBody* m_parent;
};

class hkpTypedBroadPhaseHandle
{
  public:
    hkpTypedBroadPhaseHandle(hkFinishLoadedObjectFlagCD2C)
    {}
    void SetOwnerPointer(void* pvOwner)
    {
        m_iOwnerOffset = (signed char)((char*)pvOwner - (char*)this);
    }
    unsigned int m_iOwnerObjectOffset;
    signed char m_type;
    signed char m_iOwnerOffset;
    signed char m_ucObjectQualityType;
    unsigned char unk07;
    unsigned int m_uiCollisionFilterData;
};

class hkpCollidableBoundingVolumeData
{
  public:
    hkpCollidableBoundingVolumeData(hkFinishLoadedObjectFlagCD2C flag)
    {
        if (flag.m_bFinishing)
        {
            m_uiNumChildShapeAabbs = 0;
            m_uiCapacityChildShapeAabbs = 0;
            m_pChildShapeAabbs = 0;
            m_pChildShapeKeys = 0;
            invalidate();
        }
    }
    void invalidate()
    {
        m_kMinimumCorner[0] = 1;
        m_kMaximumCorner[0] = 0;
    }
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_ucUnknownByte;
    unsigned short m_uiNumChildShapeAabbs;
    unsigned short m_uiCapacityChildShapeAabbs;
    void* m_pChildShapeAabbs;
    void* m_pChildShapeKeys;
};

class hkpCollidable : public hkpCdBody
{
  public:
    hkpCollidable(hkFinishLoadedObjectFlagCD2C flag)
        : hkpCdBody(flag), m_kBroadPhaseHandle(flag), m_kBoundingVolumeData(flag)
    {
        if (flag.m_bFinishing)
            m_kBroadPhaseHandle.SetOwnerPointer(this);
    }
    void SetOwnerPointer(void* pvOwner)
    {
        m_iOwnerOffset = (signed char)((char*)pvOwner - (char*)this);
    }
    signed char m_iOwnerOffset;
    unsigned char m_uiForceCollideOntoPpu;
    unsigned short m_uiShapeSizeOnSpu;
    hkpTypedBroadPhaseHandle m_kBroadPhaseHandle;
    hkpCollidableBoundingVolumeData m_kBoundingVolumeData;
    float m_fAllowedPenetrationDepth;
};

class hkpLinkedCollidable : public hkpCollidable
{
  public:
    hkpLinkedCollidable(hkFinishLoadedObjectFlagCD2C flag) : hkpCollidable(flag)
    {}
    hkArray<char> m_kCollisionEntries;
};

class hkMultiThreadCheck
{
  public:
    hkMultiThreadCheck(hkFinishLoadedObjectFlagCD2C)
    {
        m_uiThreadId = 0xfffffff1;
        m_usMarkedForWrite = 0x8000;
    }
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;
};
}

namespace FUN_00cd2c50 {
class hkpWorldObject : public hkCD2C::hkReferencedObject
{
  public:
    hkpWorldObject(hkFinishLoadedObjectFlagCD2C flag);
    virtual void unkVirtual00();

    void* m_pOwningWorld;
    unsigned long m_ulUserData;
    hkCD2C::hkpLinkedCollidable m_kCollidable;
    hkCD2C::hkMultiThreadCheck m_kMultiThreadCheck;
    FUN_00cb0a70::hkStringPtr m_name;
    hkCD2C::hkArray<int> m_kProperties;
};

// Constructs hkpWorldObject and, when finishing a load, sets the collidable's owner pointer to this object.
// @fnv 0x00cd2c50
hkpWorldObject::hkpWorldObject(hkFinishLoadedObjectFlagCD2C flag)
    : hkCD2C::hkReferencedObject(flag), m_kCollidable(flag), m_kMultiThreadCheck(flag), m_name(flag),
      m_kProperties(flag)
{
    if (flag.m_bFinishing)
        m_kCollidable.SetOwnerPointer(this);
}
}

namespace FUN_00cb0a60 {
class hkStringPtr
{
  public:
    hkStringPtr() throw();
    const char* m_pcText;
};
}

struct FUN_00c90510_s
{
    void FUN_00c90510() throw();
};

namespace hkCD2E {
class hkReferencedObject
{
  public:
    hkReferencedObject()
    {
        m_sReferenceCount = 1;
    }
    virtual void unkVirtual00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

template <class T> class hkArray
{
  public:
    hkArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkpTypedBroadPhaseHandle
{
  public:
    unsigned int m_iOwnerObjectOffset;
    signed char m_type;
    signed char m_iOwnerOffset;
    signed char m_ucObjectQualityType;
    unsigned char unk07;
    unsigned int m_uiCollisionFilterData;
};

class hkpCollidableBoundingVolumeData
{
  public:
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_ucUnknownByte;
    unsigned short m_uiNumChildShapeAabbs;
    unsigned short m_uiCapacityChildShapeAabbs;
    void* m_pChildShapeAabbs;
    void* m_pChildShapeKeys;
};
}

namespace FUN_00cd2d80 {
class hkpCollidable
{
  public:
    hkpCollidable(const void* shape, const void* motionState, int type) throw();
    void SetOwnerPointer(void* pvOwner)
    {
        m_iOwnerOffset = (signed char)((char*)pvOwner - (char*)this);
    }
    void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    void* m_parent;
    signed char m_iOwnerOffset;
    unsigned char m_uiForceCollideOntoPpu;
    unsigned short m_uiShapeSizeOnSpu;
    hkCD2E::hkpTypedBroadPhaseHandle m_kBroadPhaseHandle;
    hkCD2E::hkpCollidableBoundingVolumeData m_kBoundingVolumeData;
    float m_fAllowedPenetrationDepth;
};
}

namespace hkCD2E {
class hkpLinkedCollidable : public FUN_00cd2d80::hkpCollidable
{
  public:
    hkpLinkedCollidable(const void* shape, const void* motionState, int type)
        : FUN_00cd2d80::hkpCollidable(shape, motionState, type)
    {}
    hkArray<char> m_kCollisionEntries;
};

class hkMultiThreadCheck
{
  public:
    hkMultiThreadCheck()
    {
        m_uiThreadId = 0xfffffff1;
        m_usMarkedForWrite = 0x8000;
    }
    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;
};
}

namespace FUN_00cd2ce0 {
class hkpWorldObject : public hkCD2E::hkReferencedObject
{
  public:
    hkpWorldObject(const void* shape, int type);
    virtual void unkVirtual00();

    void* m_pOwningWorld;
    unsigned long m_ulUserData;
    hkCD2E::hkpLinkedCollidable m_kCollidable;
    hkCD2E::hkMultiThreadCheck m_kMultiThreadCheck;
    FUN_00cb0a60::hkStringPtr m_name;
    hkCD2E::hkArray<int> m_kProperties;
    void* m_kNextStreamField;
    int m_pWorldObjectOwner;
};

// Initializes members, sets the collidable's owner pointer, and calls FUN_00c90510 on shape when it is non-null.
// @fnv 0x00cd2ce0
hkpWorldObject::hkpWorldObject(const void* shape, int type)
    : m_pOwningWorld(0), m_ulUserData(0), m_kCollidable(shape, 0, type), m_kNextStreamField(0), m_pWorldObjectOwner(-1)
{
    m_kCollidable.SetOwnerPointer(this);
    if (shape)
        ((FUN_00c90510_s*)shape)->FUN_00c90510();
}
}
