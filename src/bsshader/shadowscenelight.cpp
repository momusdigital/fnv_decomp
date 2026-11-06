// bsshader/shadowscenelight.cpp: ShadowSceneLight, RemovalList, NiRefObject, LightView and more (22 functions)

#include "shadowscenelight_decls.h"

// If object has a node with a world bound and radius, dispatches it to one of two handlers; otherwise forwards tri-based geometry to AddGeometry.
// @fnv 0x00ba0110
void ShadowSceneLight::AddObject(NiAVObject* object)
{
    if (object)
    {
        NiNode* node = reinterpret_cast<ShadowObjectSlots*>(object)->GetNiNode();
        if (node && !(*reinterpret_cast<unsigned char*>(&object->m_uiObjectFlags) & 1) &&
            reinterpret_cast<NiAVObject*>(node)->m_kWorldBound &&
            reinterpret_cast<ShadowBoundRadiusView*>(reinterpret_cast<NiAVObject*>(node)->m_kWorldBound)
                ->m_fBoundRadius)
        {
            if (m_bSkipLightObject && object == m_pLightNode.m_pObject &&
                ((unsigned char)~(object->m_uiObjectFlags >> 23) & 1))
                goto AddDisplayGeometry;
            if (m_bSkipLightObject)
            {
                ProcessShadowObject(reinterpret_cast<NiAVObject*>(node));
                return;
            }
            else
            {
                AddShadowObject(reinterpret_cast<NiAVObject*>(node));
                return;
            }
        }
    AddDisplayGeometry:
        if (reinterpret_cast<ShadowObjectSlots*>(object)->GetTriBasedGeom())
            AddGeometry(reinterpret_cast<NiTriBasedGeom*>(object));
    }
}

// @fnv 0x00b9f6a0
void ShadowSceneLight::AddShadowObject(NiAVObject* object)
{
    unsigned int active = m_kFrustumPlanes.m_uiActivePlaneMask;
    if (!((unsigned char)(object->m_uiObjectFlags >> 11) & 1))
    {
        NiPoint3* bound = reinterpret_cast<NiPoint3*>(object->m_kWorldBound);
        NiLight* light = m_pMenuLight.m_pObject;
        if (!bound)
            bound = reinterpret_cast<NiPoint3*>(&DAT_011f4288);
        if (!FUN_00b9dae0(bound, light, 1.0f))
            goto done;
    }
    {
        NiNode* node = reinterpret_cast<ShadowObjectSlots*>(object)->GetNiNode();
        if (node)
        {
            ShadowNodeChildrenView* children = reinterpret_cast<ShadowNodeChildrenView*>(node);
            for (unsigned int i = 0; i < children->m_usElementCount; ++i)
            {
                NiAVObject* child = children->m_ppChildren[i];
                unsigned int flags;
                if (child &&
                    (((unsigned char)((flags = child->m_uiObjectFlags) >> 11) & 1) ||
                     (child->m_kWorldBound &&
                      reinterpret_cast<ShadowBoundRadiusView*>(child->m_kWorldBound)->m_fBoundRadius)) &&
                    !((unsigned char)flags & 1))
                    AddShadowObject(child);
            }
        }
        else if (reinterpret_cast<ShadowObjectSlots*>(object)->GetTriBasedGeom())
            AddGeometry(reinterpret_cast<ShadowObjectSlots*>(object)->GetTriBasedGeom());
    }
done:
    m_kFrustumPlanes.m_uiActivePlaneMask = active;
}
// @fnv 0x00b9f5b0
void ShadowSceneLight::ProcessShadowObject(NiAVObject* object)
{
    unsigned int active = m_kFrustumPlanes.m_uiActivePlaneMask;
    if (object == m_pLightNode.m_pObject || !((unsigned char)~(object->m_uiObjectFlags >> 23) & 1))
        goto done;
    if (active && !((unsigned char)(object->m_uiObjectFlags >> 11) & 1))
    {
        NiPoint3* bound = reinterpret_cast<NiPoint3*>(object->m_kWorldBound);
        if (!bound)
            bound = reinterpret_cast<NiPoint3*>(&DAT_011f4288);
        if (!TestSphereFrustum(bound))
            goto done;
    }
    {
        NiNode* node = reinterpret_cast<ShadowObjectSlots*>(object)->GetNiNode();
        if (node)
        {
            ShadowNodeChildrenView* children = reinterpret_cast<ShadowNodeChildrenView*>(node);
            for (unsigned int i = 0; i < children->m_usElementCount; ++i)
            {
                NiAVObject* child = children->m_ppChildren[i];
                unsigned int flags;
                if (child &&
                    (((unsigned char)((flags = child->m_uiObjectFlags) >> 11) & 1) ||
                     (child->m_kWorldBound &&
                      reinterpret_cast<ShadowBoundRadiusView*>(child->m_kWorldBound)->m_fBoundRadius)) &&
                    !((unsigned char)flags & 1))
                    ProcessShadowObject(child);
            }
        }
        else if (reinterpret_cast<ShadowObjectSlots*>(object)->GetTriBasedGeom())
            AddGeometry(reinterpret_cast<NiTriBasedGeom*>(object));
    }
done:
    m_kFrustumPlanes.m_uiActivePlaneMask = active;
}

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" const NiPoint3 NiPoint3_ZERO;
extern const float runtimeFloatSettingDefault100;
__forceinline void ShadowMatrixIdentity(D3DXMATRIX& m)
{
    m._12 = m._13 = m._14 = m._21 = m._23 = m._24 = m._31 = m._32 = m._34 = m._41 = m._42 = m._43 = 0.0f;
    m._11 = m._22 = m._33 = m._44 = 1.0f;
}
// @fnv 0x00b9fda0
ShadowSceneLight::ShadowSceneLight()
{
    m_fShadowParameter3 = 0.0f;
    m_fShadowParameter4 = 0.0f;
    m_bLightFlag1 = true;
    m_fShadowParameter5 = 0.0f;
    m_bSkipLightObject = false;
    m_bLightFlag0 = false;
    m_bLightFlag2 = false;
    m_bIsPipLight = false;
    m_kPipLightPosition = NiPoint3_ZERO;
    m_usEnabledState = 0;
    m_spShadowTexture = (NiTexture*)0;
    m_pMenuLight = (NiLight*)0;
    m_spSceneObject = (NiAVObject*)0;
    m_spLightRenderedTexture = (BSRenderedTexture*)0;
    ShadowMatrixIdentity(m_kShadowMatrix1);
    double spotlightDefault = runtimeFloatSettingDefault100;
    *reinterpret_cast<volatile bool*>(&m_bLightFlag1) = false;
    *reinterpret_cast<volatile float*>(&m_fSpotlightParameter) = spotlightDefault;
    m_bLightFlag3 = false;
    m_bLightFlag4 = false;
    m_kShadowLightData = 1.0f;
    m_pLightNode = (NiAVObject*)0;
    m_pShadowData = 0;
    m_spShadowGeometry = (NiTriBasedGeom*)0;
    m_pCamera = (NiCamera*)0;
    m_fShadowParameter1 = 0.0f;
    m_fShadowParameter2 = 1.0f;
    m_bShadowFrustumInitialized = false;
    fnv_zlib_memset(m_afShadowFrustumData, 0, sizeof(m_afShadowFrustumData));
}

struct Node_00b9e770
{
    Node_00b9e770* next;
    void* prev;
    char* data;
};

static __forceinline int IsShaderProp_00b9e770(char* prop)
{
    unsigned int t = *(unsigned int*)(prop + 0x1c);
    return t >= 1 && t <= 12;
}

// Walks the list at self+0x138, clears field +0x38 of each item's shader property, then nulls the list head.
// @fnv 0x00b9e770
void __fastcall ClearShaderPropRefs(char* self)
{
    Node_00b9e770* pNode = *(Node_00b9e770**)(self + 0x138);
    while (pNode)
    {
        char** ppData = &pNode->data;
        pNode = pNode->next;
        char* item = *ppData;
        if (item)
        {
            char* prop = *(char**)(item + 0xa8);
            if (prop)
            {
                char* pShaderProp = IsShaderProp_00b9e770(prop) ? prop : 0;
                if (pShaderProp)
                    *(void**)(pShaderProp + 0x38) = 0;
            }
        }
    }
    *(Node_00b9e770**)(self + 0x138) = 0;
}

extern "C" __declspec(dllimport) void __stdcall FreeBlockImp(void*);
struct FUN_00b9e8f0
{
    virtual ~FUN_00b9e8f0();
    void* data;
    int a;
    int b;
};
// Frees the owned data block via FreeBlockImp and clears data, b and a when data is non-null.
// @fnv 0x00b9e8f0
FUN_00b9e8f0::~FUN_00b9e8f0()
{
    if (data)
    {
        FreeBlockImp(data);
        data = 0;
        b = 0;
        a = 0;
    }
}

extern "C" __declspec(dllimport) void __stdcall FreeBlockImp(void*);
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct SsArr
{
    virtual ~SsArr()
    {
        if (data)
        {
            FreeBlockImp(data);
            data = 0;
            b = 0;
            a = 0;
        }
    }
    void* data;
    int a;
    int b;
};
// Destructs the SsArr object, frees its data block, and deallocates the object itself when flags has bit 0 set.
// @fnv 0x00b9e920
SsArr* __fastcall DestroySsArr(SsArr* p, int, unsigned int flags)
{
    p->SsArr::~SsArr();
    if (flags & 1)
        g_memoryManager.Deallocate(p);
    return p;
}

extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);

struct GlobalObjectO2_00b9fda0
{
    ~GlobalObjectO2_00b9fda0();
};

// @fnv 0x00ba00e0
GlobalObjectO2_00b9fda0* __fastcall FUN_00ba00e0(GlobalObjectO2_00b9fda0* this_ptr, int /*edx*/, int param2)
{
    this_ptr->~GlobalObjectO2_00b9fda0();
    if (param2 & 1)
        __Dummy_00b6fef0(this_ptr, 0x250);
    return this_ptr;
}

struct ListItem_b9e7c0
{
    ListItem_b9e7c0* m_pkNext;
    ListItem_b9e7c0* m_pkPrev;
    NiRefObject* m_element;
};

struct RefPtr_b9e7c0
{
    NiRefObject* m_pObject;
    RefPtr_b9e7c0(NiRefObject* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    RefPtr_b9e7c0(const RefPtr_b9e7c0& o) : m_pObject(o.m_pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~RefPtr_b9e7c0()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

struct FUN_00b9e7c0_list
{
    ListItem_b9e7c0* m_pkHead;
    ListItem_b9e7c0* m_pkTail;
    unsigned int m_uiCount;

    void ReleaseRefCountedNode(ListItem_b9e7c0* pkItem);
    RefPtr_b9e7c0 PopFront();
};

// @fnv 0x00b9e7c0
RefPtr_b9e7c0 FUN_00b9e7c0_list::PopFront()
{
    ListItem_b9e7c0* pkNode = m_pkHead;
    m_pkHead = m_pkHead->m_pkNext;
    if (m_pkHead)
        m_pkHead->m_pkPrev = 0;
    else
        m_pkTail = 0;
    RefPtr_b9e7c0 element = pkNode->m_element;
    ReleaseRefCountedNode(pkNode);
    m_uiCount--;
    return element;
}

struct RefPtr_b9fcc0
{
    NiRefObject* m_pObject;
    RefPtr_b9fcc0(NiRefObject* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    RefPtr_b9fcc0(const RefPtr_b9fcc0& o) : m_pObject(o.m_pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~RefPtr_b9fcc0()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    bool operator==(const RefPtr_b9fcc0& o) const
    {
        return m_pObject == o.m_pObject;
    }
};

struct ListItem_b9fcc0
{
    ListItem_b9fcc0* m_pkNext;
    ListItem_b9fcc0* m_pkPrev;
    RefPtr_b9fcc0 m_element;
};

struct List_b9fcc0
{
    ListItem_b9fcc0* m_pkHead;
    ListItem_b9fcc0* m_pkTail;
    unsigned int m_uiCount;

    void* GetHeadPos() const
    {
        return m_pkHead;
    }
    const RefPtr_b9fcc0& GetNext(void*& kPos) const
    {
        const RefPtr_b9fcc0& element = ((ListItem_b9fcc0*)kPos)->m_element;
        kPos = ((ListItem_b9fcc0*)kPos)->m_pkNext;
        return element;
    }
    void* FindPos(const RefPtr_b9fcc0& element, void* kStart = 0) const
    {
        if (kStart == 0)
            kStart = GetHeadPos();
        while (kStart)
        {
            void* kPos = kStart;
            if (element == GetNext(kStart))
                return kPos;
        }
        return 0;
    }
    RefPtr_b9fcc0 FUN_00b9efa0(void*& kPos);
    RefPtr_b9fcc0 FUN_00b9fcc0(const RefPtr_b9fcc0& element);
};

// @fnv 0x00b9fcc0
RefPtr_b9fcc0 List_b9fcc0::FUN_00b9fcc0(const RefPtr_b9fcc0& element)
{
    void* kPos = FindPos(element);
    return kPos ? FUN_00b9efa0(kPos) : element;
}

struct ListItem_b9e850
{
    ListItem_b9e850* m_pkNext;
    ListItem_b9e850* m_pkPrev;
    NiRefObject* m_element;
};

struct RefPtr_b9e850
{
    NiRefObject* m_pObject;
    RefPtr_b9e850(NiRefObject* p) : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    RefPtr_b9e850(const RefPtr_b9e850& o) : m_pObject(o.m_pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~RefPtr_b9e850()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

struct FUN_00b9e850_list
{
    ListItem_b9e850* m_pkHead;
    ListItem_b9e850* m_pkTail;
    unsigned int m_uiCount;

    void ReleaseRefCountedNode(ListItem_b9e850* pkItem);
    RefPtr_b9e850 PopBack();
};

// @fnv 0x00b9e850
RefPtr_b9e850 FUN_00b9e850_list::PopBack()
{
    ListItem_b9e850* pkNode = m_pkTail;
    m_pkTail = m_pkTail->m_pkPrev;
    if (m_pkTail)
        m_pkTail->m_pkNext = 0;
    else
        m_pkHead = 0;
    RefPtr_b9e850 element = pkNode->m_element;
    ReleaseRefCountedNode(pkNode);
    m_uiCount--;
    return element;
}

struct NiGlobalStringTable
{
    static char* __cdecl AddString(char const*);
};
extern char* _EmptyFS;
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
    static void __cdecl operator delete(void*);
    unsigned char pad[0xc4];
};
struct FUN_00a74480 : BSFadeNode
{
    FUN_00a74480(unsigned int);
};
class NiFixedString
{
  public:
    char* m_handle;
    NiFixedString(const char* s)
    {
        m_handle = NiGlobalStringTable::AddString(s);
    }
    ~NiFixedString()
    {
        if (m_handle != _EmptyFS)
            InterlockedDecrement(reinterpret_cast<volatile long*>(m_handle - 8));
    }
};
struct NiObjectNET
{
    void SetName(const NiFixedString&);
};
struct FencePtr
{
    NiAVObject* m_p;
    NiObjectNET* operator->() const
    {
        return reinterpret_cast<NiObjectNET*>(m_p);
    }
    FencePtr& operator=(NiAVObject* p)
    {
        if (m_p != p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = p;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
};
struct FUN_00c1b4a0_holder
{
    void FUN_00c1b4a0(FencePtr*);
};
struct FUN_00b9fba0_s
{
    void FUN_00b9fba0();
};
// @fnv 0x00b9fba0
void FUN_00b9fba0_s::FUN_00b9fba0()
{
    char* self = reinterpret_cast<char*>(this);
    FencePtr& fence = *reinterpret_cast<FencePtr*>(self + 0x13c);
    if (fence.m_p == 0)
    {
        fence = reinterpret_cast<NiAVObject*>(new FUN_00a74480(0));
        fence->SetName("fence");
    }
    reinterpret_cast<FUN_00c1b4a0_holder*>(self + 0xe0)->FUN_00c1b4a0(&fence);
    *reinterpret_cast<int*>(self + 0x138) = *reinterpret_cast<int*>(self + 0xe0);
}

extern "C" double __cdecl sqrt(double);
inline float __cdecl sqrt(float _X)
{
    return (float)sqrt((double)_X);
}

struct V3
{
    float x, y, z;
    V3 operator-(const V3& o) const
    {
        V3 r;
        r.x = x - o.x;
        r.y = y - o.y;
        r.z = z - o.z;
        return r;
    }
    float Length() const
    {
        return sqrt(x * x + y * y + z * z);
    }
};
struct C3
{
    float r, g, b;
    C3& operator*=(float s)
    {
        r *= s;
        g *= s;
        b *= s;
        return *this;
    }
};
struct LightV
{
    float GetDimmer() const
    {
        return *(float*)((char*)this + 0xc4);
    }
};
inline float MinF(float a, float b)
{
    return a < b ? a : b;
}
inline float Sqr(float a)
{
    return a * a;
}
inline float MaxF(float a, float b)
{
    return a > b ? a : b;
}
extern double _gModifierZero;

struct FUN_00b9bc50_t
{
    float ComputeLightAttenuation(V3 apPoint, NiLight* apIgnore);
};

// Computes a light's attenuation at apPoint from its dimmed color and distance/radius falloff, storing and returning the result at this+0xc.
// @fnv 0x00b9bc50
float FUN_00b9bc50_t::ComputeLightAttenuation(V3 apPoint, NiLight* apIgnore)
{
    char* pkLight = *(char**)((char*)this + 0xf8);
    if (pkLight == (char*)apIgnore || *((char*)this + 0xec) == 1)
        return 0.0f;
    V3 lightPos = *(V3*)(pkLight + 0x8c);
    C3 lightColor = *(C3*)(pkLight + 0xd4);
    lightColor *= ((LightV*)pkLight)->GetDimmer();
    float plightRadius = *(float*)(pkLight + 0xe0);
    *(float*)((char*)this + 0xc) = 1.0f;
    if (*((char*)this + 0xf4))
    {
        float fdistance = (apPoint - lightPos).Length() / plightRadius;
        fdistance = MinF(1.0f, fdistance < _gModifierZero ? 0.0f : fdistance);
        *(float*)((char*)this + 0xc) = 1.0f - fdistance * fdistance;
    }
    *(float*)((char*)this + 0xc) = MaxF(lightColor.r, MaxF(lightColor.g, lightColor.b)) * *(float*)((char*)this + 0xc);
    return *(float*)((char*)this + 0xc);
}

struct BSTextureManager;
extern BSTextureManager* DAT_011f91a8;
struct LightD
{
    void FUN_00b9ef30();
};
struct ShadowRendererView
{
    void FUN_00b6d4c0(BSRenderedTexture* pTexture);
};

struct ShadowSceneArrayView
{
    virtual ~ShadowSceneArrayView();
    virtual void Slot04();
    virtual void Free(void* p);
};

template <> inline ShadowSceneArray<BSMultiBoundNode*>::~ShadowSceneArray()
{
    if (pBuffer)
    {
        ((ShadowSceneArrayView*)this)->Free(pBuffer);
        pBuffer = 0;
        SimpleArrayStorage = 0;
        iSize = 0;
    }
}
template <> inline ShadowSceneArray<BSPortal*>::~ShadowSceneArray()
{
    if (pBuffer)
    {
        ((ShadowSceneArrayView*)this)->Free(pBuffer);
        pBuffer = 0;
        SimpleArrayStorage = 0;
        iSize = 0;
    }
}
template <> inline ShadowSceneArray<NiNode*>::~ShadowSceneArray()
{
    if (pBuffer)
    {
        ((ShadowSceneArrayView*)this)->Free(pBuffer);
        pBuffer = 0;
        SimpleArrayStorage = 0;
        iSize = 0;
    }
}

NiRefObject::~NiRefObject()
{
    InterlockedDecrement(&DAT_011f4400);
}

struct FUN_00b9f0c0_cls : public NiRefObject
{
    int m_iShadowLightState;
    float m_fShadowParameter3;
    D3DXMATRIX m_kShadowMatrix1;
    D3DXMATRIX m_kShadowMatrix2;
    D3DXMATRIX m_kShadowMatrix3;
    float m_fShadowParameter4;
    float m_fShadowParameter5;
    float m_fShadowParameter2;
    float m_fShadowParameter1;
    NiTPointerList_NiPointer_NiTriBasedGeom___ m_kLightStripList;
    bool m_bSkipLightObject;
    bool m_bLightFlag1;
    unsigned char layoutPaddingEE[2];
    ShadowScenePointer<NiTexture> m_spShadowTexture;
    bool m_bLightFlag0;
    bool m_bLightFlag2;
    unsigned char layoutPaddingF[2];
    ShadowScenePointer<NiLight> m_pMenuLight;
    bool m_bIsPipLight;
    unsigned char layoutPaddingFD[3];
    NiPoint3 m_kPipLightPosition;
    ShadowScenePointer<BSRenderedTexture> m_spLightRenderedTexture;
    unsigned short m_usEnabledState;
    unsigned char layoutPadding[2];
    ShadowScenePointer<NiAVObject> m_spSceneObject;
    bool m_bLightFlag3;
    unsigned char layoutPaddingCur[3];
    float m_fSpotlightParameter;
    float m_kShadowLightData;
    bool m_bLightFlag4;
    unsigned char layoutPaddingValue[3];
    ShadowScenePointer<NiAVObject> m_pLightNode;
    NiTPointerList_NiPointer_NiAVObject___ m_kSceneObjectList;
    void* m_pShadowData;
    ShadowScenePointer<NiTriBasedGeom> m_spShadowGeometry;
    ShadowScenePointer<NiCamera> m_pCamera;
    NiFrustumPlanes m_kFrustumPlanes;
    float m_afShadowFrustumData[24];
    bool m_bShadowFrustumInitialized;
    unsigned char lNewayoutPadding[3];
    ShadowScenePointer<BSShaderAccumulator> m_spShadowShaderAccumulator;
    ShadowSceneArray<BSMultiBoundNode*> m_kMultiBoundNodes;
    ShadowSceneArray<BSPortal*> m_kShadowLightData1;
    ShadowSceneArray<NiNode*> m_kShadowLightData2;
    BSPortalGraph* m_pPortalConnectivityGraphInfo;
    ~FUN_00b9f0c0_cls();
};

// @fnv 0x00b9f0c0
FUN_00b9f0c0_cls::~FUN_00b9f0c0_cls()
{
    ((LightD*)this)->FUN_00b9ef30();
    m_spShadowTexture = 0;
    m_pMenuLight = 0;
    if (m_spLightRenderedTexture.m_pObject)
    {
        reinterpret_cast<ShadowRendererView*>(DAT_011f91a8)->FUN_00b6d4c0(m_spLightRenderedTexture.m_pObject);
    }
    m_spLightRenderedTexture = 0;
    m_usEnabledState = 0;
    m_spSceneObject = 0;
    m_pCamera = 0;
    m_pLightNode = 0;
    m_spShadowShaderAccumulator = 0;
    m_pShadowData = 0;
    m_spShadowGeometry = 0;
    {
        ShadowSceneArray<BSMultiBoundNode*>& a = m_kMultiBoundNodes;
        if (a.pBuffer)
        {
            ((ShadowSceneArrayView*)&a)->Free(a.pBuffer);
            a.pBuffer = 0;
            a.SimpleArrayStorage = 0;
            a.iSize = 0;
        }
    }
    {
        ShadowSceneArray<BSPortal*>& a = m_kShadowLightData1;
        if (a.pBuffer)
        {
            ((ShadowSceneArrayView*)&a)->Free(a.pBuffer);
            a.pBuffer = 0;
            a.SimpleArrayStorage = 0;
            a.iSize = 0;
        }
    }
    {
        ShadowSceneArray<NiNode*>& a = m_kShadowLightData2;
        if (a.pBuffer)
        {
            ((ShadowSceneArrayView*)&a)->Free(a.pBuffer);
            a.pBuffer = 0;
            a.SimpleArrayStorage = 0;
            a.iSize = 0;
        }
    }
}

struct Color4
{
    float r, g, b, a;
    Color4(float R, float G, float B, float A) : r(R), g(G), b(B), a(A)
    {}
};
extern Color4 DAT_011a9bd0;
extern unsigned int DAT_011f91b8;
extern const float runtimeFloatSettingDefault408;
struct RendererView
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43(Color4*);
    virtual void slot44();
    virtual void slot45(Color4*);
};
extern RendererView* DAT_011f9508;
struct TextureView : NiRefObject
{
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
    NiPointer<NiRefObject> unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    NiPointer<NiRefObject> unk4C[6];
    void* FUN_00b6b260();
};
struct WaterView : NiRefObject
{
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
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    NiPointer<TextureView> unk10C;
    unsigned short unk110;
};
struct AccumulatorView : NiRefObject
{
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35(void*);
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
    bool unk84;
};
struct FUN_00a69400
{
    virtual void slot0();
    FUN_00a69400(void*);
    void FUN_00a694a0(void*);
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
    int unk8C;
};
struct BSCullingProcess : FUN_00a69400
{
    virtual void slot0();
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    AccumulatorView* unkC4;
    BSCullingProcess(void* v) : FUN_00a69400(v)
    {
        unk90 = 0;
        unkBC = 0;
        unkC0 = 0;
        unkC4 = 0;
    }
    ~BSCullingProcess();
};
struct UpdateView
{
    float unk00;
    bool unk04, unk05, unk06, unk07, unk08;
    UpdateView() : unk00(0), unk04(false), unk05(false), unk06(false), unk07(false), unk08(false)
    {}
};
struct LightView : NiRefObject
{
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
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    NiPointer<TextureView> unk130;
    WaterView* unk134;
    void* unk138;
    AccumulatorView* unk13C;
    void RenderFaces();
    void FUN_00bd7200(int);
    void CullScene(WaterView*);
    void FUN_00a59c60(UpdateView&);
};
void FUN_00b6b8d0(unsigned int, void*);
void FUN_00b6bee0(LightView*, void*, BSCullingProcess*);
void FUN_00b6c0d0(LightView*, AccumulatorView*, int);
void FUN_00b71360(unsigned int, WaterView*, float);
void FUN_00b6b790();
// @fnv 0x00bd77c0
void LightView::RenderFaces()
{
    Color4 old = DAT_011a9bd0;
    unsigned short uiFaceMask = 0;
    DAT_011f9508->slot45(&old);
    if (DAT_011f91b8 == 7)
    {
        uiFaceMask = unk134->unk110;
        Color4 clear(runtimeFloatSettingDefault408, runtimeFloatSettingDefault408, runtimeFloatSettingDefault408, 1.0f);
        DAT_011f9508->slot43(&clear);
    }
    for (int face = 0; face < 6; ++face)
    {
        FUN_00bd7200(face);
        NiRefObject* texture = (unk130 ? unk130->unk30 : NiPointer<NiRefObject>());
        TextureView* pTextureView = (TextureView*)texture;
        pTextureView->unk48 = face;
        pTextureView->unk30 = pTextureView->unk4C[face];
        FUN_00b6b8d0(7, unk130->FUN_00b6b260());
        int uiFaceBit = 0;
        switch (face)
        {
        case 1:
            uiFaceBit = 2;
            break;
        case 0:
            uiFaceBit = 1;
            break;
        case 3:
            uiFaceBit = 8;
            break;
        case 2:
            uiFaceBit = 4;
            break;
        case 5:
            uiFaceBit = 32;
            break;
        case 4:
            uiFaceBit = 16;
            break;
        }
        if (!(unsigned short)(uiFaceBit & uiFaceMask))
        {
            UpdateView updateView;
            FUN_00a59c60(updateView);
            if (DAT_011f91b8 != 7)
            {
                if (unk138)
                {
                    if (unk13C->m_uiRefCount == 1)
                        unk13C->IncRefCount();
                    unk13C->slot35(this);
                    unk13C->unk84 = true;
                    BSCullingProcess cullingProcess(0);
                    cullingProcess.unk0C = (int)this;
                    void* list = &unkDC;
                    cullingProcess.FUN_00a694a0(list);
                    AccumulatorView* pAccumulator = unk13C;
                    if (cullingProcess.unkC4 != pAccumulator)
                    {
                        if (cullingProcess.unkC4)
                            cullingProcess.unkC4->DecRefCount();
                        cullingProcess.unkC4 = pAccumulator;
                        if (pAccumulator)
                            pAccumulator->IncRefCount();
                    }
                    void* scene = unk138;
                    FUN_00b6bee0(this, scene, &cullingProcess);
                    AccumulatorView* pCurrentAccumulator = unk13C;
                    FUN_00b6c0d0(this, pCurrentAccumulator, 0);
                    if (cullingProcess.unkC4)
                    {
                        cullingProcess.unkC4->DecRefCount();
                        cullingProcess.unkC4 = 0;
                    }
                }
            }
            else if (unk134)
            {
                FUN_00b71360(0, unk134, 1.0f);
                unk130 = (TextureView*)unk134->unk10C;
                CullScene(unk134);
            }
        }
        FUN_00b6b790();
    }
    DAT_011f9508->slot43(&old);
}

struct BoundListItem
{
    BoundListItem* next;
    BoundListItem* previous;
    NiPointer<NiRefObject> element;
};
struct BoundAllocator
{
    unsigned int count;
    BoundListItem* FUN_0043a010();
};
struct RemovalList
{
    BoundListItem* m_pkHead;
    BoundListItem* m_pkTail;
    unsigned int m_uiCount;
    __declspec(noinline) NiPointer<NiRefObject> PopBack();
    void ReleaseRefCountedNode(BoundListItem* item);
};
struct ActiveList
{
    BoundListItem* head;
    BoundListItem* tail;
    BoundAllocator allocator;
    __declspec(noinline) void FUN_00a5a310(const NiPointer<NiRefObject>& item);
};
void ActiveList::FUN_00a5a310(const NiPointer<NiRefObject>& item)
{
    BoundListItem* entry = allocator.FUN_0043a010();
    entry->element = item;
    entry->next = 0;
    entry->previous = tail;
    if (tail)
        tail->next = entry;
    else
        head = entry;
    ++allocator.count;
    tail = entry;
}
NiPointer<NiRefObject> RemovalList::PopBack()
{
    BoundListItem* entry = m_pkTail;
    m_pkTail = entry->previous;
    if (m_pkTail)
        m_pkTail->next = 0;
    else
        m_pkHead = 0;
    NiPointer<NiRefObject> value = entry->element;
    ReleaseRefCountedNode(entry);
    --m_uiCount;
    return value;
}
class MultiBoundLists
{
  public:
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
    RemovalList pending;
    ActiveList active;
    NiRefObject* ActivatePending();
};
// If pending is nonempty, pops its last item, appends it to active, and returns the popped value.
// @fnv 0x00b6d3f0
NiRefObject* MultiBoundLists::ActivatePending()
{
    NiPointer<NiRefObject> result;
    if (pending.m_uiCount > 0)
    {
        result = pending.PopBack();
        active.FUN_00a5a310(result);
    }
    return result;
}

namespace fnv_00b9ef30 {
class LightD;

struct LightProp
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int m_iType;
    int IsLightingProperty()
    {
        return m_iType - 1 <= 11;
    }
    void AddWatcher(LightD* pkOwner);
};

struct LightGeom
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
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    LightProp* m_pkProp;
};

struct NodeB9E
{
    NodeB9E* m_pkNext;
    NodeB9E* m_pkPrev;
    LightGeom* m_element;
};

struct ShadowSceneLightList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> >
{
    NodeB9E* GetHeadPos() const
    {
        return (NodeB9E*)m_pkHead;
    }
    LightGeom* GetNext(NodeB9E*& pkPos) const
    {
        LightGeom*& element = pkPos->m_element;
        pkPos = pkPos->m_pkNext;
        return element;
    }
};

class LightD
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
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    ShadowSceneLightList m_kList1;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    ShadowSceneLightList m_kList2;

    void FUN_00b9ef30();
};

// Iterates m_kList1, calls AddWatcher on each lighting property, then removes all entries from m_kList1 and m_kList2.
// @fnv 0x00b9ef30
void LightD::FUN_00b9ef30()
{
    NodeB9E* pkPos = m_kList1.GetHeadPos();
    while (pkPos)
    {
        LightGeom* pkObj = m_kList1.GetNext(pkPos);
        if (pkObj)
        {
            LightProp* pkProp = pkObj->m_pkProp;
            if (pkProp)
            {
                int b = pkProp->IsLightingProperty();
                int* pbIsLighting = &b;
                LightProp* pkMatch = (*pbIsLighting) ? pkProp : 0;
                if (pkMatch)
                    pkMatch->AddWatcher(this);
            }
        }
    }
    m_kList1.RemoveAll();
    m_kList2.RemoveAll();
}
}  // namespace fnv_00b9ef30

namespace fnv_00b9efa0 {
struct RemovalList
{
    ListItem_b9fcc0* m_pkHead;
    ListItem_b9fcc0* m_pkTail;
    unsigned int m_uiCount;
    RefPtr_b9fcc0 RemoveHead();
    RefPtr_b9fcc0 RemoveTail();
    void FreeItem(ListItem_b9fcc0*);
    RefPtr_b9fcc0 FUN_00b9efa0(void*& position);
};

// Removes the ListItem_b9fcc0 at position, updating the position pointer to the next item, and returns the removed RefPtr_b9fcc0 element.
// @fnv 0x00b9efa0
RefPtr_b9fcc0 RemovalList::FUN_00b9efa0(void*& position)
{
    ListItem_b9fcc0* item = (ListItem_b9fcc0*)position;
    if (item == m_pkHead)
    {
        position = item->m_pkNext;
        return RemoveHead();
    }
    if (item == m_pkTail)
    {
        position = 0;
        return RemoveTail();
    }
    ListItem_b9fcc0* previous = item->m_pkPrev;
    ListItem_b9fcc0* next = item->m_pkNext;
    position = next;
    if (previous)
        previous->m_pkNext = next;
    if (next)
        next->m_pkPrev = previous;
    RefPtr_b9fcc0 element = item->m_element;
    FreeItem(item);
    --m_uiCount;
    return element;
}
}  // namespace fnv_00b9efa0

extern "C" void _ReadWriteBarrier(void);
#include <string.h>
namespace fnv_00b9dfc0 {
// Views extend the pack's intentionally abbreviated object declarations.
struct ShadowVector : NiPoint3
{

    static void Set(ShadowVector& v, float a, float b, float c)
    {
        v.x = a;
        v.y = b;
        v.z = c;
    }

    float Length() const;
    ShadowVector* ApplyScaled(ShadowVector*, float scalar) const;
    ShadowVector& operator+=(const ShadowVector& p)
    {
        x += p.x;
        y += p.y;
        z += p.z;
        return *this;
    }
    void FUN_004a0c10();
    ShadowVector* FUN_0053d1a0(ShadowVector*, const ShadowVector&) const;
    ShadowVector& FUN_0063c8a0(const ShadowVector&);
};
struct ShadowTransform
{
    ShadowVector rotationX, rotationY, rotationZ;
    ShadowVector translation;
    float scale;
};
struct ShadowExtraData
{
    void* vtable;
    unsigned int refCount;
    void* name;
    ShadowVector offset;
    ShadowVector extent;
};
struct ShadowUpdateData
{
    float time;
    bool updateControllers, multithreaded, updateGeomorphs, updateBounds, updateTransforms;
};
struct NiFrustum
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool orthographic;
    NiFrustum(bool);
    void Set(float l, float r)
    {
        left = l;
        bottom = l;
        right = r;
        top = r;
    }
};
struct ShadowViewport
{
    float left, right, top, bottom;
};
struct ShadowObject : NiAVObject
{
    ShadowTransform local, world;
    float GetScale() const
    {
        return world.scale;
    }
    float OrderedScale() const
    {
        _ReadWriteBarrier();
        return world.scale;
    }
    ShadowExtraData* FUN_00a5bdd0(const void*);
};
struct NiMemObjectAllocation
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct ShadowLight : ShadowObject
{
    unsigned int unk09c, unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4;
    unsigned int unk0b8, unk0bc, unk0c0, unk0c4, unk0c8, unk0cc, unk0d0;
    unsigned int unk0d4, unk0d8, unk0dc;
    float range;
};
struct FUN_00a712f0 : ShadowObject, NiMemObjectAllocation
{
    D3DXMATRIX worldToCamera;
    NiFrustum frustum;
    ShadowViewport viewport;
    float lodAdjust;
    unsigned int unk10c, unk110;
    FUN_00a712f0();
    void FUN_00a59c60(ShadowUpdateData&);
    void SetLookAt(const ShadowVector&, const ShadowVector&);
    void FUN_00a6faf0(const NiFrustum&);
    void SetViewPort(const ShadowViewport&);
    void FUN_00a70080(const NiBound&);
};
struct ShadowManager
{
    BSRenderedTexture* ActivatePending();
    void FUN_00b6d4c0(BSRenderedTexture*);
};
struct ShadowPointerCalls
{
    ShadowPointerCalls& FUN_0066b0d0(void*);
};
struct ShadowPlanes
{
    void SetFromFrustum(const NiFrustum&, const ShadowTransform&);
};
struct ShadowAccumulator : BSShaderAccumulator
{
    unsigned int unk008, unk00c, unk010, unk014;
    unsigned int unk018, unk01c, unk020, unk024;
    unsigned int unk028, unk02c, unk030, unk034;
    unsigned int unk038, unk03c, unk040, unk044;
    unsigned int unk048, unk04c, unk050, unk054;
    unsigned int unk058, unk05c, unk060, unk064;
    unsigned int unk068, unk06c, unk070, unk074;
    unsigned int unk078, unk07c, unk080, unk084;
    unsigned int unk088, unk08c, unk090, unk094;
    unsigned int unk098, unk09c, unk0a0, unk0a4;
    unsigned int unk0a8, unk0ac, unk0b0, unk0b4;
    unsigned int unk0b8, unk0bc, unk0c0, unk0c4;
    unsigned int unk0c8, unk0cc, unk0d0, unk0d4;
    unsigned int unk0d8, unk0dc, unk0e0, unk0e4;
    unsigned int unk0e8, unk0ec, unk0f0, unk0f4;
    unsigned int unk0f8, unk0fc, unk100, unk104;
    unsigned int unk108, unk10c, unk110, unk114;
    unsigned int unk118, unk11c, unk120, unk124;
    unsigned int unk128, unk12c, unk130, unk134;
    unsigned int unk138, unk13c, unk140, unk144;
    unsigned int unk148, unk14c, unk150, unk154;
    unsigned int unk158, unk15c, unk160, unk164;
    unsigned int unk168, unk16c, unk170, unk174;
    unsigned int unk178, unk17c, unk180, unk184;
    unsigned int unk188, unk18c, unk190, unk194;
    unsigned int unk198;
    unsigned int activePass;
    void SetPass(unsigned int pass)
    {
        activePass = pass;
    }
    void AssignRefCounted(ShadowSceneLight*);
};
struct ShadowEvents
{
    void FUN_00ba30f0(int, unsigned char*);
    void FUN_00ba3390(NiCamera*, int, NiAVObject*, int, int, BSShaderAccumulator*, int, unsigned char*, int);
};
extern ShadowManager* DAT_011f91a8;
extern int DAT_011f91c0, DAT_011f91b0;
extern int DAT_011f91d8;
extern double DAT_01082cb0, DAT_01031148, DAT_010b7ea0;
extern double DAT_01016ff0, DAT_0106c948, DAT_01020758;
extern double DAT_0106b178, DAT_01018a90;
extern float DAT_01032adc;
extern ShadowVector DAT_011a9484, DAT_011a946c, DAT_011f426c;
extern const void* DAT_012031e4;
extern ShadowEvents DAT_01200088;
inline float ShadowNegate(float f)
{
    return -f;
}
inline float ShadowRadius(const NiBound& b)
{
    return b.radius;
}
extern float __cdecl FUN_00404010(float, float);
extern float __cdecl FUN_0040ebd0(float, float);
extern bool __cdecl FUN_005bf7b0();
extern BSShaderAccumulator* __cdecl PopNextInt();
inline void ShadowEnabled(int& result)
{
    result = (DAT_011f91d8 & 0x10) > 0;
}
inline int ShadowEnabledValue()
{
    int result;
    ShadowEnabled(result);
    return result;
}
class ShadowSceneLightDecompile : public ShadowSceneLight
{
  public:
    NiLight* GetLight() const
    {
        return m_pMenuLight.m_pObject;
    }
    bool CastsShadow() const
    {
        return m_bSkipLightObject;
    }
    NiCamera* GetShadowCamera()
    {
        return m_pCamera.m_pObject;
    }
    void AssignRefObject(BSRenderedTexture*);
    void UpdateShadow(void*, unsigned char*);
};

// Updates the shadow camera frustum and viewport when conditions hold; otherwise releases an existing shadow texture.
// @fnv 0x00b9dfc0
void ShadowSceneLightDecompile::UpdateShadow(void* unused, unsigned char* renderFlags)
{
    bool updateShadow = true;
    if (!(CastsShadow() && DAT_011f91c0 >= 3 && (unsigned char)ShadowEnabledValue()) && !m_bLightFlag3)
        updateShadow = false;

    if (!m_spLightRenderedTexture.m_pObject)
    {
        BSRenderedTexture* texture = DAT_011f91a8->ActivatePending();
        if (!texture)
            reinterpret_cast<NiAVObject*>(m_pMenuLight.m_pObject)->m_uiObjectFlags |= 1;
        AssignRefObject(texture);
    }

    if (updateShadow && m_usEnabledState != 255 && m_fShadowParameter5 > DAT_01082cb0 &&
        m_spLightRenderedTexture.m_pObject)
    {
        ShadowTransform lightTransform = reinterpret_cast<ShadowObject*>(GetLight())->world;
        union
        {
            ShadowVector direction, sceneOrigin;
            ShadowUpdateData initialUpdate;
        } a;
        union
        {
            ShadowVector side, position;
        } b;
        union
        {
            ShadowVector temp, delta, offset;
        } c;
        union
        {
            ShadowVector extent;
            ShadowUpdateData finalUpdate;
        } d;
        union
        {
            ShadowVector axis, up;
        } e;
        ShadowVector::Set(
            a.direction,
            reinterpret_cast<ShadowObject*>(m_pLightNode.m_pObject)->world.translation.x - lightTransform.translation.x,
            reinterpret_cast<ShadowObject*>(m_pLightNode.m_pObject)->world.translation.y - lightTransform.translation.y,
            reinterpret_cast<ShadowObject*>(m_pLightNode.m_pObject)->world.translation.z -
                lightTransform.translation.z);
        a.direction.FUN_004a0c10();
        ShadowVector::Set(e.axis, -DAT_011a9484.x, -DAT_011a9484.y, -DAT_011a9484.z);
        a.direction.FUN_0053d1a0(&b.side, e.axis);
        if (b.side.x < DAT_01031148 && b.side.x > DAT_010b7ea0 && b.side.y < DAT_01031148 && b.side.y > DAT_010b7ea0 &&
            b.side.z < DAT_01031148 && b.side.z > DAT_010b7ea0)
        {
            e.axis = DAT_011a946c;
            const NiPoint3* __restrict cross = a.direction.FUN_0053d1a0(&c.temp, e.axis);
            static_cast<NiPoint3&>(b.side) = *cross;
        }
        memcpy(&e.up, a.direction.FUN_0053d1a0(&c.temp, b.side), sizeof(e.up));
        NiFrustum frustum(false);
        frustum.orthographic = true;
        ShadowExtraData* pExtraData =
            reinterpret_cast<ShadowObject*>(m_pLightNode.m_pObject)->FUN_00a5bdd0(DAT_012031e4);
        float radius;
        {
            ShadowObject* __restrict scene = reinterpret_cast<ShadowObject*>(m_pLightNode.m_pObject);
            {
                const NiPoint3* __restrict origin = &scene->world.translation;
                static_cast<NiPoint3&>(a.sceneOrigin) = *origin;
            }
            {
                const NiPoint3* __restrict extent =
                    pExtraData ? pExtraData->extent.ApplyScaled(&c.temp, scene->GetScale()) : &DAT_011f426c;
                static_cast<NiPoint3&>(d.extent) = *extent;
            }
            const NiBound* bound = static_cast<NiBound*>(scene->m_kWorldBound);
            if (!bound)
                bound = &DAT_011f4288;
            radius = FUN_0040ebd0(DAT_01032adc, FUN_00404010(float(d.extent.x * DAT_01016ff0),
                                                             FUN_00404010(float(d.extent.y * DAT_01016ff0),
                                                                          FUN_00404010(float(d.extent.z * DAT_01016ff0),
                                                                                       ShadowRadius(*bound)))));
        }
        ShadowObject* light = reinterpret_cast<ShadowObject*>(m_pMenuLight.m_pObject);
        float distance;
        ShadowVector::Set(c.delta, light->world.translation.x - a.sceneOrigin.x,
                          light->world.translation.y - a.sceneOrigin.y, light->world.translation.z - a.sceneOrigin.z);
        distance = c.delta.Length();
        m_fSpotlightParameter = float((radius / distance) * DAT_0106c948);
        frustum.Set(-radius, radius);
        frustum.nearPlane = 1.0f;
        frustum.farPlane = reinterpret_cast<ShadowLight*>(light)->range;
        __declspec(align(16)) ShadowViewport viewport;
        viewport.bottom = viewport.left = 0.0f;
        viewport.top = viewport.right = 1.0f;

        if (m_bSkipLightObject && FUN_005bf7b0())
        {
            reinterpret_cast<ShadowPointerCalls*>(&m_spShadowShaderAccumulator)->FUN_0066b0d0(PopNextInt());
            reinterpret_cast<ShadowAccumulator*>(m_spShadowShaderAccumulator.m_pObject)->SetPass(7);
            if (!GetShadowCamera())
            {
                FUN_00a712f0* camera = new FUN_00a712f0;
                reinterpret_cast<ShadowPointerCalls*>(&m_pCamera)->FUN_0066b0d0(camera);
            }
            memcpy(&reinterpret_cast<FUN_00a712f0*>(GetShadowCamera())->local.translation, &lightTransform.translation,
                   sizeof(lightTransform.translation));
            a.initialUpdate.time = 0.0f;
            a.initialUpdate.updateControllers = false;
            a.initialUpdate.multithreaded = false;
            a.initialUpdate.updateGeomorphs = false;
            a.initialUpdate.updateBounds = false;
            a.initialUpdate.updateTransforms = false;
            reinterpret_cast<FUN_00a712f0*>(GetShadowCamera())->FUN_00a59c60(a.initialUpdate);
            memcpy(&b.position, &reinterpret_cast<ShadowObject*>(m_pLightNode.m_pObject)->world.translation,
                   sizeof(b.position));
            pExtraData = reinterpret_cast<ShadowObject*>(m_pLightNode.m_pObject)->FUN_00a5bdd0(DAT_012031e4);
            ShadowVector tempOffset;
            ShadowObject* __restrict scaleSource = reinterpret_cast<ShadowObject*>(m_pLightNode.m_pObject);
            float scale = static_cast<const volatile float&>(scaleSource->world.scale);
            ShadowVector* __restrict output = &tempOffset;
            const ShadowVector* input = &pExtraData->offset;
            b.position.FUN_0063c8a0(*input->ApplyScaled(output, scale));
            pExtraData->extent.ApplyScaled(&c.offset,
                                           reinterpret_cast<ShadowObject*>(m_pLightNode.m_pObject)->OrderedScale());
            if (c.offset.z > c.offset.x + c.offset.y)
            {
                c.offset.x = float(DAT_011a9484.x * DAT_01020758);
                c.offset.y = float(DAT_011a9484.y * DAT_01020758);
                c.offset.z = float(DAT_011a9484.z * DAT_01020758);
                b.position.x = c.offset.x + b.position.x;
                b.position.y = c.offset.y + (*static_cast<const volatile float*>(&b.position.y));
                b.position.z = c.offset.z + (*static_cast<const volatile float*>(&b.position.z));
            }
            reinterpret_cast<FUN_00a712f0*>(GetShadowCamera())->SetLookAt(b.position, e.up);
            reinterpret_cast<FUN_00a712f0*>(GetShadowCamera())->FUN_00a6faf0(frustum);
            reinterpret_cast<FUN_00a712f0*>(GetShadowCamera())->SetViewPort(viewport);
            d.finalUpdate.time = 0.0f;
            d.finalUpdate.updateControllers = false;
            d.finalUpdate.multithreaded = false;
            d.finalUpdate.updateGeomorphs = false;
            d.finalUpdate.updateBounds = false;
            d.finalUpdate.updateTransforms = false;
            reinterpret_cast<FUN_00a712f0*>(GetShadowCamera())->FUN_00a59c60(d.finalUpdate);
            float nearPlane = frustum.nearPlane;
            float farPlane = frustum.farPlane;
            ShadowObject* __restrict boundSource = reinterpret_cast<ShadowObject*>(m_pLightNode.m_pObject);
            const NiBound* bound = static_cast<NiBound*>(boundSource->m_kWorldBound);
            if (!bound)
                bound = &DAT_011f4288;
            reinterpret_cast<FUN_00a712f0*>(GetShadowCamera())->FUN_00a70080(*bound);
            frustum = reinterpret_cast<FUN_00a712f0*>(GetShadowCamera())->frustum;
            frustum.farPlane = float(frustum.farPlane + DAT_0106b178);
            if (!DAT_011f91b0)
                frustum.nearPlane = float(frustum.farPlane * DAT_01018a90);
            reinterpret_cast<ShadowPlanes*>(&m_kFrustumPlanes)
                ->SetFromFrustum(frustum, reinterpret_cast<FUN_00a712f0*>(GetShadowCamera())->world);
            frustum.nearPlane = nearPlane;
            frustum.farPlane = farPlane;
            reinterpret_cast<FUN_00a712f0*>(GetShadowCamera())->FUN_00a6faf0(frustum);
            reinterpret_cast<ShadowAccumulator*>(m_spShadowShaderAccumulator.m_pObject)->AssignRefCounted(this);
            DAT_01200088.FUN_00ba3390(m_pCamera.m_pObject, 0, m_pLightNode.m_pObject, 0, 0,
                                      m_spShadowShaderAccumulator.m_pObject, 0, renderFlags + 0x11, 0);
        }
    }
    else if (m_spLightRenderedTexture.m_pObject)
    {
        DAT_011f91a8->FUN_00b6d4c0(m_spLightRenderedTexture.m_pObject);
        m_spLightRenderedTexture = 0;
        m_spShadowShaderAccumulator = 0;
    }
    DAT_01200088.FUN_00ba30f0(0, renderFlags + 0x11);
}
}  // namespace fnv_00b9dfc0

struct NiRTTI;
extern NiRTTI g_011fed88_arg1;
struct NiShader
{
    NiShader* DynamicCast(const NiRTTI*);
};
struct ShadowSceneLight_b9f480;
struct Fake_FUN_004a2020
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    int iType;
    bool GetFlag(unsigned int) const;
    void InsertOrMoveNode(ShadowSceneLight_b9f480*, NiBound*);
};
struct PropState_b9f480
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Fake_FUN_004a2020* pShaderProp;
    int GetShaderType() const
    {
        return pShaderProp ? pShaderProp->iType : -1;
    }
};
struct Geom_b9f480
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    NiBound* pBound;
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
    PropState_b9f480 kState;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    NiShader* pShader;
};
struct Node_b9f480
{
    Node_b9f480* pNext;
    Node_b9f480* pPrev;
    Geom_b9f480* pGeom;
};
struct GeomHolder_b9f480
{
    Geom_b9f480* p;
    GeomHolder_b9f480() : p(0)
    {}
    ~GeomHolder_b9f480();
};
struct List_b9f480
{
    Node_b9f480* pHead;
    Geom_b9f480*& GetNext(Node_b9f480*& rPos)
    {
        Geom_b9f480*& r = rPos->pGeom;
        rPos = rPos->pNext;
        return r;
    }
    void MoveNodeBefore(Node_b9f480*, Node_b9f480*);
    void FUN_00c1b4a0(GeomHolder_b9f480*);
};
struct ShadowSceneLight_b9f480
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
    List_b9f480 kGeomList;
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
    Node_b9f480* pIter;
    void AddGeometry(Geom_b9f480* pGeom);
};

// For qualifying shader properties, searches the geometry list; a match may move before pIter, otherwise the geometry is processed and passed to a list helper.
// @fnv 0x00b9f480
void ShadowSceneLight_b9f480::AddGeometry(Geom_b9f480* apGeom)
{
    static GeomHolder_b9f480 spGeom;
    if (apGeom->pShader && apGeom->pShader->DynamicCast(&g_011fed88_arg1))
    {
        PropState_b9f480* pState = &apGeom->kState;
        if (pState)
        {
            Fake_FUN_004a2020* pProp = apGeom->kState.pShaderProp;
            int iType = pProp ? pProp->iType : -1;
            if ((unsigned int)(iType - 1) <= 11)
            {
                Node_b9f480* pStart = pIter;
                Node_b9f480* pNode = pStart ? pStart : kGeomList.pHead;
                while (pNode)
                {
                    Node_b9f480* pCur = pNode;
                    if (kGeomList.GetNext(pNode) == apGeom)
                    {
                        if (pStart)
                            kGeomList.MoveNodeBefore(pCur, pStart);
                        pProp->InsertOrMoveNode(this, apGeom->pBound ? apGeom->pBound : &DAT_011f4288);
                        return;
                    }
                }
                if (!pProp->GetFlag(0xc) || iType == 4)
                {
                    spGeom.p = apGeom;
                    pProp->InsertOrMoveNode(this, apGeom->pBound ? apGeom->pBound : &DAT_011f4288);
                    kGeomList.FUN_00c1b4a0(&spGeom);
                    spGeom.p = 0;
                }
            }
        }
    }
}

namespace fnv_00b9f780 {
struct RenderPassSetup
{
    void FUN_00ba3130(int, int);
};
extern RenderPassSetup g_01200088;
struct RenderColor
{
    float r, g, b, a;
    RenderColor()
    {}
    RenderColor(float R, float G, float B, float A) : r(R), g(G), b(B), a(A)
    {}
};
extern RenderColor DAT_011a9bd0;
struct RenderState
{
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5C();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6C();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7C();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8C();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual void Slot9C();
    virtual void SlotA0();
    virtual void SlotA4();
    virtual void SlotA8();
    virtual void SetColor(RenderColor*);
    virtual void SlotB0();
    virtual void GetColor(RenderColor*);
};
extern RenderState* DAT_011f4748;
struct RenderTextureView
{
    void* GetGroup();
    void* FUN_004bc320(int);
};
void FUN_00b6b8d0(unsigned int, void*);
struct PassAccumulator : NiRefObject
{
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    NiPointer<NiRefObject> target;
};
struct PassContext
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    NiPointer<PassAccumulator> accum;
};
struct PassTransform
{
    float rotate[3][3];
    NiPoint3 translate;
    float scale;
};
struct PassCamera
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    PassTransform world;
};
struct PassRenderer
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    unsigned int unk4F0;
    unsigned int unk4F4;
    unsigned int unk4F8;
    unsigned int unk4FC;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54C;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55C;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56C;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57C;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58C;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59C;
    unsigned int unk5A0;
    unsigned int unk5A4;
    unsigned int unk5A8;
    unsigned int unk5AC;
    unsigned int unk5B0;
    unsigned int unk5B4;
    unsigned int unk5B8;
    unsigned int unk5BC;
    unsigned int unk5C0;
    unsigned int unk5C4;
    unsigned int unk5C8;
    unsigned int unk5CC;
    unsigned int unk5D0;
    unsigned int unk5D4;
    unsigned int unk5D8;
    unsigned int unk5DC;
    unsigned int unk5E0;
    unsigned int unk5E4;
    unsigned int unk5E8;
    unsigned int unk5EC;
    unsigned int unk5F0;
    unsigned int unk5F4;
    unsigned int unk5F8;
    unsigned int unk5FC;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60C;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61C;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62C;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63C;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64C;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65C;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66C;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67C;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68C;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69C;
    unsigned int unk6A0;
    unsigned int unk6A4;
    unsigned int unk6A8;
    unsigned int unk6AC;
    unsigned int unk6B0;
    unsigned int unk6B4;
    unsigned int unk6B8;
    unsigned int unk6BC;
    unsigned int unk6C0;
    unsigned int unk6C4;
    unsigned int unk6C8;
    unsigned int unk6CC;
    unsigned int unk6D0;
    unsigned int unk6D4;
    unsigned int unk6D8;
    unsigned int unk6DC;
    unsigned int unk6E0;
    unsigned int unk6E4;
    unsigned int unk6E8;
    unsigned int unk6EC;
    unsigned int unk6F0;
    unsigned int unk6F4;
    unsigned int unk6F8;
    unsigned int unk6FC;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70C;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71C;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72C;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73C;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74C;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75C;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76C;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77C;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78C;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79C;
    unsigned int unk7A0;
    unsigned int unk7A4;
    unsigned int unk7A8;
    unsigned int unk7AC;
    unsigned int unk7B0;
    unsigned int unk7B4;
    unsigned int unk7B8;
    unsigned int unk7BC;
    unsigned int unk7C0;
    unsigned int unk7C4;
    unsigned int unk7C8;
    unsigned int unk7CC;
    unsigned int unk7D0;
    unsigned int unk7D4;
    unsigned int unk7D8;
    unsigned int unk7DC;
    unsigned int unk7E0;
    unsigned int unk7E4;
    unsigned int unk7E8;
    unsigned int unk7EC;
    unsigned int unk7F0;
    unsigned int unk7F4;
    unsigned int unk7F8;
    unsigned int unk7FC;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80C;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81C;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82C;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83C;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84C;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85C;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86C;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87C;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88C;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89C;
    unsigned int unk8A0;
    unsigned int unk8A4;
    unsigned int unk8A8;
    unsigned int unk8AC;
    unsigned int unk8B0;
    unsigned int unk8B4;
    unsigned int unk8B8;
    unsigned int unk8BC;
    unsigned int unk8C0;
    unsigned int unk8C4;
    unsigned int unk8C8;
    unsigned int unk8CC;
    unsigned int unk8D0;
    unsigned int unk8D4;
    unsigned int unk8D8;
    unsigned int unk8DC;
    unsigned int unk8E0;
    unsigned int unk8E4;
    unsigned int unk8E8;
    unsigned int unk8EC;
    unsigned int unk8F0;
    unsigned int unk8F4;
    unsigned int unk8F8;
    unsigned int unk8FC;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90C;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int unk918;
    unsigned int unk91C;
    unsigned int unk920;
    unsigned int unk924;
    unsigned int unk928;
    unsigned int unk92C;
    unsigned int unk930;
    unsigned int unk934;
    unsigned int unk938;
    unsigned int unk93C;
    unsigned int unk940;
    unsigned int unk944;
    unsigned int unk948;
    unsigned int unk94C;
    unsigned int unk950;
    unsigned int unk954;
    unsigned int unk958;
    unsigned int unk95C;
    unsigned int unk960;
    unsigned int unk964;
    unsigned int unk968;
    unsigned int unk96C;
    unsigned int unk970;
    unsigned int unk974;
    unsigned int unk978;
    unsigned int unk97C;
    D3DXMATRIX view;
    D3DXMATRIX proj;
    void SetFromCamera(PassCamera*);
};
extern PassRenderer* DAT_011f9508;
void FUN_00b6c0d0(NiCamera*, PassAccumulator*, int);
void __stdcall FUN_00ee6de0(D3DXMATRIX*, D3DXMATRIX*, D3DXMATRIX*);
void FUN_00b6b790();
extern int DAT_011f91b0;
struct PassTextureManager
{
    BSRenderedTexture* ActivatePending();
    void FUN_00b6d4c0(BSRenderedTexture*);
};
extern PassTextureManager* DAT_011f91a8;
struct ImageSpaceTexture
{
    bool a, b, c;
    unsigned int unk04, unk08, unk0C;
    ImageSpaceTexture() : a(false), b(false), c(false), unk04(0), unk08(0), unk0C(0)
    {}
    void FUN_00ba37a0(BSRenderedTexture*);
    ~ImageSpaceTexture();
};
struct ImageSpaceEffectParam
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    ImageSpaceEffectParam();
    ~ImageSpaceEffectParam();
};
struct PassEffect
{
    void SetAccumulatorAt(int, ImageSpaceTexture*, int);
};
struct PassEffectList
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    PassEffect* effect;
};
struct PassImageManager
{
    unsigned int unk00, unk04;
    PassEffect** effects;
    void FUN_00b97550(int, PassRenderer*, BSRenderedTexture*, BSRenderedTexture*, ImageSpaceEffectParam*, int);
};
extern PassImageManager* DAT_011f91ac;
__forceinline PassImageManager* GetImageManager()
{
    return DAT_011f91ac;
}
extern float DAT_010162c0;
extern float DAT_012003c4;
struct PassDebug
{
    void AddTexture(void*);
};
PassDebug* __cdecl FUN_00b55560(int);
struct ShadowPass : ShadowSceneLight
{
    void FUN_00b9f780(PassContext*, int);
};
// Renders the shadow pass by setting up the shadow matrices from the light and camera, then applies the image space effect to the light rendered texture.
// @fnv 0x00b9f780
void ShadowPass::FUN_00b9f780(PassContext* context, int pass)
{
    g_01200088.FUN_00ba3130(1, pass + 17);
    RenderColor previous = DAT_011a9bd0;
    DAT_011f4748->GetColor(&previous);
    {
        RenderColor white(1.0f, 1.0f, 1.0f, 1.0f);
        DAT_011f4748->SetColor(&white);
    }
    FUN_00b6b8d0(7, reinterpret_cast<RenderTextureView*>(m_spLightRenderedTexture.m_pObject)->GetGroup());
    DAT_011f4748->SetColor(&previous);
    context->accum = reinterpret_cast<PassAccumulator*>(m_spShadowShaderAccumulator.m_pObject);
    PassAccumulator* renderAccum = reinterpret_cast<PassAccumulator*>(m_spShadowShaderAccumulator.m_pObject);
    NiCamera* renderCamera = m_pCamera.m_pObject;
    FUN_00b6c0d0(renderCamera, renderAccum, 0);
    {
        PassAccumulator* accum = reinterpret_cast<PassAccumulator*>(m_spShadowShaderAccumulator.m_pObject);
        if (accum->target.m_pObject)
        {
            accum->target.m_pObject->DecRefCount();
            accum->target.m_pObject = 0;
        }
    }
    if (context->accum.m_pObject)
    {
        context->accum.m_pObject->DecRefCount();
        context->accum.m_pObject = 0;
    }
    PassCamera* camera = reinterpret_cast<PassCamera*>(m_pCamera.m_pObject);
    NiPoint3 up;
    up.x = camera->world.rotate[0][2];
    up.y = camera->world.rotate[1][2];
    up.z = camera->world.rotate[2][2];
    NiPoint3 right;
    right.x = camera->world.rotate[0][1];
    right.y = camera->world.rotate[1][1];
    right.z = camera->world.rotate[2][1];
    NiPoint3 dir;
    dir.x = camera->world.rotate[0][0];
    dir.y = camera->world.rotate[1][0];
    dir.z = camera->world.rotate[2][0];
    PassRenderer* renderer = DAT_011f9508;
    renderer->SetFromCamera(camera);
    __declspec(align(16)) D3DXMATRIX view = renderer->view;
    PassCamera* light = reinterpret_cast<PassCamera*>(m_pMenuLight.m_pObject);
    D3DXMATRIX proj = renderer->proj;
    PassTransform transform = light->world;
    m_kShadowMatrix2 = view;
    m_kShadowMatrix2._41 = -transform.translate.Dot(up);
    m_kShadowMatrix2._42 = -transform.translate.Dot(right);
    m_kShadowMatrix2._43 = -transform.translate.Dot(dir);
    m_kShadowMatrix3 = proj;
    FUN_00ee6de0(&proj, &m_kShadowMatrix2, &m_kShadowMatrix3);
    m_kShadowMatrix1 = proj;
    FUN_00b6b790();
    if (!DAT_011f91b0)
    {
        BSRenderedTexture* texture = DAT_011f91a8->ActivatePending();
        ImageSpaceTexture input;
        input.FUN_00ba37a0(texture);
        ImageSpaceEffectParam param;
        DAT_012003c4 = DAT_010162c0;
        PassEffect* effect = GetImageManager()->effects[17];
        effect->SetAccumulatorAt(2, &input, 0);
        PassRenderer* renderer2 = DAT_011f9508;
        GetImageManager()->FUN_00b97550(17, renderer2, m_spLightRenderedTexture.m_pObject,
                                        m_spLightRenderedTexture.m_pObject, &param, 1);
        DAT_011f91a8->FUN_00b6d4c0(texture);
    }
    if (m_bLightFlag4)
    {
        void* texture = reinterpret_cast<RenderTextureView*>(m_spLightRenderedTexture.m_pObject)->FUN_004bc320(0);
        PassDebug* debug = FUN_00b55560(9);
        debug->AddTexture(texture);
    }
    m_bShadowFrustumInitialized = false;
}
}  // namespace fnv_00b9f780

extern "C" double __cdecl sqrt(double);
static inline float ShadowUpdateSqrt(float value)
{
    return static_cast<float>(sqrt(static_cast<double>(value)));
}
struct LightPositionView_b9e
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    NiPoint3 position;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    float radius;
};
struct CameraCullView_b9e
{
    int unk00, unk04, unk08;
    LightPositionView_b9e* camera;
    LightPositionView_b9e* GetCamera() const
    {
        return camera;
    }
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    struct Plane
    {
        NiPoint3 normal;
        float constant;
        float Distance(const NiPoint3& point) const
        {
            return normal.x * point.x + point.y * normal.y + point.z * normal.z - constant;
        }
    };
    struct Planes
    {
        Plane planes[6];
        unsigned mask;
    } frustum;
};
struct DistanceScaleView_b9e
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    float scale;
};
struct RenderContextView_b9e
{
    int unk00, unk04;
    DistanceScaleView_b9e* object;
};
namespace sb9e {
extern "C" RenderContextView_b9e* __cdecl FUN_00b4f5c0();
extern "C" int DAT_011f91c0;
extern "C" char DAT_011f91d8;
extern "C" float DAT_011f9444, DAT_011f9448, DAT_011f9410, DAT_011ad834;
extern "C" int DAT_011f944c, DAT_011f9450;
}
struct AlphaPropertyView_b9e
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    float alpha;
};
struct PropertyObjectView_b9e
{
    AlphaPropertyView_b9e* FUN_00a59d30(unsigned);
};
struct ShaderDirtyView_b9e
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    unsigned type;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    bool dirty;
    int IsLighting()
    {
        return type - 1 <= 11;
    }
};
inline bool ShadowFeatureEnabled_b9e()
{
    return (sb9e::DAT_011f91d8 & 16) > 0;
}
inline bool CanCube_b9e()
{
    return sb9e::DAT_011f91c0 >= 3 ? (sb9e::DAT_011f91d8 & 16) > 0 : false;
}
struct GeometryDirtyView_b9e
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    ShaderDirtyView_b9e* shader;
};
struct DirtyNodeView_b9e
{
    DirtyNodeView_b9e* next;
    void* prev;
    GeometryDirtyView_b9e* geometry;
    GeometryDirtyView_b9e*& Get()
    {
        return geometry;
    }
};
struct TextureManagerView_b9e
{
    void FUN_00b6d4c0(BSRenderedTexture*);
};
namespace sb9e {
extern "C" TextureManagerView_b9e* DAT_011f91a8;
}
struct ShadowUpdate_b9e : ShadowSceneLight
{
    __declspec(noalias) bool FUN_00b9c020(LightPositionView_b9e*, NiCamera*);
    bool FUN_00b9de90(NiBound, CameraCullView_b9e*, unsigned short);
    void FUN_00b9e970(CameraCullView_b9e*);
};
// Culls the shadow light against the camera frustum, computes distance-based fade factors, and marks lighting shaders dirty when state changes.
// @fnv 0x00b9e970
void ShadowUpdate_b9e::FUN_00b9e970(CameraCullView_b9e* camera)
{
    LightPositionView_b9e* light = (LightPositionView_b9e*)m_pMenuLight.m_pObject;
    unsigned uiCullMask = 0;
    NiBound bound;
    bound.center = light->position;
    bound.radius = light->radius;
    bool castShadow = m_bSkipLightObject;

    bool contained = true;
    if (castShadow && m_pCamera.m_pObject)
    {
        uiCullMask = FUN_00b9c020(camera->GetCamera(), m_pCamera.m_pObject) ? 0 : 255;
    }
    else
    {
        CameraCullView_b9e::Planes planes = camera->frustum;
        for (unsigned planeIndex = 0; planeIndex < 6; ++planeIndex)
        {
            if (planes.mask & (1 << planeIndex))
            {
                CameraCullView_b9e::Plane plane = planes.planes[planeIndex];
                float distance = float(plane.normal.x * bound.center.x + bound.center.y * plane.normal.y +
                                       bound.center.z * plane.normal.z) -
                                 plane.constant;
                if (distance <= -bound.radius)
                {
                    uiCullMask = 255;
                    goto cullDone;
                }
                const float& d = plane.Distance(bound.center);
                if (d < 0.0f)
                    contained = false;
            }
        }
        if (!contained && castShadow && CanCube_b9e() && m_bLightFlag1)
        {
            for (unsigned short face = 0; face < 6; ++face)
                if (!FUN_00b9de90(bound, camera, face))
                    uiCullMask |= 1 << face;
        }
    }
cullDone:
    float dimmer = m_fShadowParameter4;
    float shadow = m_fShadowParameter5;
    float blend;
    if ((unsigned short)uiCullMask != 255)
    {
        LightPositionView_b9e* cameraObject = camera->camera;
        NiPoint3 cameraPosition = cameraObject->position;
        NiPoint3 delta;
        delta.x = bound.center.x - cameraPosition.x;
        delta.y = bound.center.y - cameraPosition.y;
        delta.z = bound.center.z - cameraPosition.z;
        float distance = ShadowUpdateSqrt(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z) - bound.radius;
        if (sb9e::FUN_00b4f5c0()->object)
            distance *= sb9e::FUN_00b4f5c0()->object->scale;
        if (distance < sb9e::DAT_011f9444 || sb9e::DAT_011f9448 == 0.0f)
            dimmer = 1.0f;
        else if (sb9e::DAT_011f9448 < distance)
        {
            uiCullMask = 255;
            shadow = dimmer = 0.0f;
            goto propertyFade;
        }
        else
        {
            dimmer = 1.0f - (distance - sb9e::DAT_011f9444) / (sb9e::DAT_011f9448 - sb9e::DAT_011f9444);
            if (!(dimmer > 0.0f))
                goto propertyFade;
        }
        if (m_bSkipLightObject)
        {
            if (distance < reinterpret_cast<float&>(sb9e::DAT_011f944c) ||
                reinterpret_cast<float&>(sb9e::DAT_011f9450) == 0.0f)
                shadow = 1.0f;
            else if (distance > reinterpret_cast<float&>(sb9e::DAT_011f9450))
                shadow = 0.0f;
            else
                shadow = 1.0f - (distance - reinterpret_cast<float&>(sb9e::DAT_011f944c)) /
                                    (reinterpret_cast<float&>(sb9e::DAT_011f9450) -
                                     reinterpret_cast<float&>(sb9e::DAT_011f944c));
        }
    propertyFade:
        if (m_pLightNode.m_pObject)
        {
            AlphaPropertyView_b9e* pAlphaProperty = ((PropertyObjectView_b9e*)m_pLightNode.m_pObject)->FUN_00a59d30(2);
            if (pAlphaProperty)
                shadow *= pAlphaProperty->alpha;
        }
        m_fShadowParameter1 += sb9e::DAT_011f9410;
        float ratio = m_fShadowParameter1 / sb9e::DAT_011ad834;
        blend = (1.0f < ratio) ? 1.0f : ratio;
        if (m_fShadowParameter2 == 0.0f)
            shadow = (1.0f - blend) * shadow;
        else
            shadow = blend * shadow;
    }
    if ((m_usEnabledState == 255 && (unsigned short)uiCullMask != 255) ||
        (m_usEnabledState != 255 && (unsigned short)uiCullMask == 255) ||
        (m_fShadowParameter4 == 0.0f && dimmer > 0.0f) || (m_fShadowParameter4 > 0.0f && dimmer == 0.0f) ||
        (m_fShadowParameter5 == 0.0f && shadow > 0.0f) || (m_fShadowParameter5 > 0.0f && shadow == 0.0f))
    {
        DirtyNodeView_b9e* node = *(DirtyNodeView_b9e**)&m_kLightStripList;
        while (node)
        {
            GeometryDirtyView_b9e* const& geometry = node->geometry;
            node = node->next;
            if (geometry)
            {
                ShaderDirtyView_b9e* prop = geometry->shader;
                ShaderDirtyView_b9e* pLightingShader = (!prop ? 0 : prop->IsLighting()) ? prop : 0;
                if (pLightingShader)
                    pLightingShader->dirty = true;
            }
        }
        if (m_fShadowParameter5 == 0.0f && m_spLightRenderedTexture.m_pObject)
        {
            sb9e::DAT_011f91a8->FUN_00b6d4c0(m_spLightRenderedTexture.m_pObject);
            m_spLightRenderedTexture = 0;
        }
    }
    m_usEnabledState = (unsigned short)uiCullMask;
    m_fShadowParameter4 = dimmer;
    m_fShadowParameter5 = shadow;
}
