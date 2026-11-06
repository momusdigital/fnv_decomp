// fallout_shared/globalfunc.cpp: BipedNodeNames, NiAVObject, ActorMover, PathingGraphNode and more (110 functions)

#include "globalfunc_decls.h"

// @fnv 0x004b7920
void BipedNodeNames::InitializeMultiBounds()
{
    DAT_011c61a4 = new NiFixedString("Bip01");
    DAT_011c61a8 = new NiFixedString("Bip");
    DAT_011c61ac = new NiFixedString("Bip01 Head");
    DAT_011c61b0 = new NiFixedString("Bip01 Neck");
    DAT_011c61b4 = new NiFixedString("Bip01 Spine");
    DAT_011c61b8 = new NiFixedString("Bip01 Spine1");
    DAT_011c61bc = new NiFixedString("magicNode");
    DAT_011c61c0 = new NiFixedString("SpecialIdle_Cast");
    DAT_011c61c4 = new NiFixedString("SpecialIdle_AreaEffect");
    DAT_011c61c8 = new NiFixedString("AttachSound");
    DAT_011c61cc = new NiFixedString("Sound Marker");
    DAT_011c61d0 = new NiFixedString("Skinned Decal Node");
    DAT_011c61d4 = new NiFixedString("Decal Node");
    DAT_011c61d8 = new NiFixedString("ModelSwapNode");
    DAT_011c61dc = new NiFixedString("Open");
    DAT_011c61e0 = new NiFixedString("Close");
    DAT_011c61e4 = new NiFixedString("DVPG");
    DAT_011c61e8 = new NiFixedString("Prn");
    DAT_011c61ec = new NiFixedString("Weapon");
    DAT_011c61f0 = new NiFixedString("EditorMarker");
    DAT_011c61f4 = new NiFixedString("EditorMarker:0");
    DAT_011c61f8 = new NiFixedString("EditorMarker:1");
    DAT_011c61fc = new NiFixedString("EditorMarker:2");
    DAT_011c6200 = new NiFixedString("ArrowQuiver");
    DAT_011c6204 = new NiFixedString("MarkerSource");
    DAT_011c6208 = new NiFixedString("MarkerTarget");
    DAT_011c620c = new NiFixedString("AttachLight");
    DAT_011c6210 = new NiFixedString("skin");
    DAT_011c6214 = new NiFixedString("FaceGenEars");
    DAT_011c6218 = new NiFixedString("Unequip");
    DAT_011c621c = new NiFixedString("LaserSight");
    DAT_011c6220 = new NiFixedString("AimSight");
    DAT_011c6224 = new NiFixedString("Grass");
    DAT_011c6228 = new NiFixedString("Decal");
    DAT_011c622c = new NiFixedString("Permanent Decal");
    DAT_011c6230 = new NiFixedString("grabLeft");
    DAT_011c6234 = new NiFixedString("grabRight");
    DAT_011c6238 = new NiFixedString("Arrow:0");
    DAT_011c623c = new NiFixedString("ArrowBone");
    DAT_011c6240 = new NiFixedString("BSFaceGenNiNodeBiped");
    DAT_011c6244 = new NiFixedString("BSFaceGenNiNodeSkinned");
    DAT_011c6248 = new NiFixedString("HeadAnims:0");
    DAT_011c624c = new NiFixedString("EntryPoint");
    DAT_011c6250 = new NiFixedString("Bip01 L UpperArm");
    DAT_011c6254 = new NiFixedString("Bip01 L Forearm");
    DAT_011c6258 = new NiFixedString("Bip01 R UpperArm");
    DAT_011c625c = new NiFixedString("Bip01 Yaw");
    DAT_011c6260 = new NiFixedString("Bip01 Pitch");
    DAT_011c6264 = new NiFixedString("Bip01 Looking");
    DAT_011c6268 = new NiFixedString("Talking");
    DAT_011c626c = new NiFixedString("Camera1st");
    DAT_011c6270 = new NiFixedString("Camera3rd");
    DAT_011c6274 = new NiFixedString("HeadMeshForExport_FaceGenAndMorphs:0");
    DAT_011c6278 = new NiFixedString("PinnedLimb");
}

// @fnv 0x004b7240
bool ConvertLocalizedString(const char* input, char* output, unsigned int capacity)
{
    if (!input || !output || !capacity)
        return false;
    const char* current;
    bool changed = false;
    output[0] = 0;
    unsigned int written = 0;
    int targetPlatform = FUN_004b71a0();
    LANGUAGE language = GetConfiguredLanguage();
    current = input;
    for (int i = 0; i < 4; ++i)
    {
        char separator = 0;
        const char* found = LocateString(current, DAT_01189038[i]);
        while (found)
        {
            unsigned int tagLength = BSStringLength(DAT_01189038[i]);
            if (found[tagLength] == '\\' || found[tagLength] == '/')
            {
                separator = found[tagLength];
                break;
            }
            else
                found = LocateString(found + tagLength, DAT_01189038[i]);
        }
        if (found)
        {
            unsigned int prefix = found - current;
            if (prefix)
            {
                memcpy_s(output + written, capacity - written, current, prefix);
                written += prefix;
                output[written] = 0;
            }
            strcat_s(output, capacity, DAT_01189038[targetPlatform]);
            written += strlen(DAT_01189038[targetPlatform]);
            output[written] = separator;
            ++written;
            output[written] = 0;
            found += strlen(DAT_01189038[i]);
            ++found;
            current = found;
            changed = true;
            break;
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        char separator = 0;
        const char* found = LocateString(current, DAT_01188f84[i]);
        while (found)
        {
            unsigned int tagLength = BSStringLength(DAT_01188f84[i]);
            if (found[tagLength] == '\\' || found[tagLength] == '/')
            {
                separator = found[tagLength];
                break;
            }
            else
                found = LocateString(found + tagLength, DAT_01188f84[i]);
        }
        if (found)
        {
            unsigned int prefix = found - current;
            if (prefix)
            {
                memcpy_s(output + written, capacity - written, current, prefix);
                written += prefix;
                output[written] = 0;
            }
            strcat_s(output, capacity, DAT_01188f84[language]);
            written += strlen(DAT_01188f84[language]);
            output[written] = separator;
            ++written;
            output[written] = 0;
            found += strlen(DAT_01188f84[i]);
            ++found;
            current = found;
            changed = true;
            break;
        }
    }
    strcat_s(output, capacity, current);
    return changed;
}

// @fnv 0x004b7660
bool UpdateObjectVisibility(NiAVObject* object)
{
    bool changed = false;
    if (object)
    {
        NiProperty* property = object->GetProperty(3);
        NiProperty* textures = (property == 0 ? 0
                                              : (reinterpret_cast<NiTimeController*>(property)->FUN_00441110() >= 8 &&
                                                 reinterpret_cast<NiTimeController*>(property)->FUN_00441110() <= 12))
                                   ? property
                                   : 0;
        if (textures)
        {
            unsigned int count = textures->GetTextureCount();
            for (unsigned int i = 0; i < count; ++i)
            {
                for (int type = 0; type < 6; ++type)
                {
                    NiTexture* texture = textures->GetTexture(type, i);
                    if (texture && FUN_0043b300(&DAT_011f444c, reinterpret_cast<NiAVObject*>(texture)))
                    {
                        bool swapped;
                        NiTexture* source = texture;
                        NiFixedString path(source->GetPath());
                        {
                            char replacement[260];
                            replacement[0] = 0;
                            swapped = ConvertLocalizedString(
                                reinterpret_cast<const char*>(reinterpret_cast<BSFadeNode*>(&path)->FUN_0043b1b0()),
                                replacement, 260);
                            if (swapped && replacement[0])
                            {
                                NiPointer<NiTexture> newTexture(0);
                                g_TES->CreateTextureImage(replacement,
                                                          reinterpret_cast<NiPointer<NiSourceTexture>&>(newTexture),
                                                          false, false);
                                if (newTexture)
                                {
                                    textures->SetTexture(type, i, static_cast<NiTexture*>(newTexture));
                                    changed = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        NiNode* node = object->GetAsNiNode();
        if (node)
        {
            unsigned int count = node->FUN_0043b480();
            for (unsigned int i = 0; i < count; ++i)
                if (UpdateObjectVisibility(node->GetAt(i)))
                    changed = true;
        }
    }
    return changed;
}

// @fnv 0x004b5d10
bool RemoveInvalidChildNodes(NiNode* apNode)
{
    bool removed = false;
    if (!apNode)
        return removed;
    if (!DAT_011c6328)
    {
        NiExtraData* pExtraData = apNode->GetExtraData(FUN_00448a80());
        if (pExtraData)
        {
            NiExtraData* flags = pExtraData;
            if (flags->FUN_004b5fa0())
            {
                DAT_011c6328 = apNode;
                NiTimeController* controller = apNode->GetController(&DAT_011f36ac);
                {
                    NiControllerManager* controllerManager = reinterpret_cast<NiControllerManager*>(controller);
                    if (controllerManager)
                        DAT_011c6324 = controllerManager->GetStringAtOffset();
                }
            }
        }
    }
    if (!DAT_011c6328)
        return removed;
    if (reinterpret_cast<const char*>(
            reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(apNode)->GetLinkToList())
                ->FUN_0043b1b0()) &&
        !FUN_00404dc0(reinterpret_cast<const char*>(
                          reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(apNode)->GetLinkToList())
                              ->FUN_0043b1b0()),
                      "EditorMarker"))
    {
        if (DAT_011c6324)
        {
            DAT_011c6324->vfn_90(FUN_004b5f60(), 0);
            DAT_011c6324->vfn_90(FUN_004b5f70(), 0);
            DAT_011c6324->vfn_90(FUN_004b5f80(), 0);
            DAT_011c6324->vfn_90(FUN_004b5f90(), 0);
        }
        if (apNode->GetParent())
            apNode->GetParent()->RemoveObject(apNode);
        if (DAT_011c6328 == apNode)
        {
            DAT_011c6328 = 0;
            DAT_011c6324 = 0;
        }
        return true;
    }
    for (unsigned int i = 0; i < apNode->FUN_0043b480(); ++i)
    {
        NiAVObject* child = apNode->GetAt(i);
        if (child)
        {
            NiNode* node = child->GetAsNiNode();
            if (node)
            {
                removed = RemoveInvalidChildNodes(node);
                if (removed)
                {
                    if (DAT_011c6328 == apNode)
                    {
                        DAT_011c6328 = 0;
                        DAT_011c6324 = 0;
                    }
                    return removed;
                }
            }
        }
    }
    if (DAT_011c6328 == apNode)
    {
        DAT_011c6328 = 0;
        DAT_011c6324 = 0;
    }
    return removed;
}

// @fnv 0x004b5b20
bool HandleUnparentedObjectNode(NiNode* object)
{
    if (!object)
        return false;
    for (unsigned int i = 0; i < object->FUN_0043b480(); ++i)
    {
        NiAVObject* child = object->GetAt(i);
        if (child)
        {
            const char* name = reinterpret_cast<const char*>(
                reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(child)->GetLinkToList())
                    ->FUN_0043b1b0());
            if (name)
            {
                if (!FUN_00404dc0(name, "Scb"))
                {
                    object->RemoveNthObject(i);
                    return true;
                }
                else if (!_strnicmp(name, "FadeNode ", 9))
                    return HandleUnparentedObjectNode(child->GetAsNiNode());
            }
        }
    }
    return false;
}

// @fnv 0x004b6dc0
void SetObjectFormID(NiAVObject* object, unsigned int referenceID)
{
    if (!object)
        return;
    if (object->GetAsNiGeometry())
    {
        NiProperty* property = object->GetProperty(3);
        NiProperty* lighting = FUN_004a2c20(property) ? property : 0;
        if (lighting)
            reinterpret_cast<EffectSetting*>(lighting)->SetLight(reinterpret_cast<TESObjectLIGH*>(referenceID));
    }
    else
    {
        NiNode* node = object->GetAsNiNode();
        if (node)
            for (unsigned int i = 0; i < node->FUN_0043b480(); ++i)
                SetObjectFormID(node->GetAt(i), referenceID);
    }
}

// @fnv 0x004b5c80
bool IsObjectNetValid(NiObjectNET* object)
{
    if (!object)
        return false;
    if (FUN_0043b300(&DAT_012024e0, reinterpret_cast<NiAVObject*>(object)))
        return true;
    NiNode* node = object->GetAsNiNode();
    if (node)
        for (unsigned int i = 0; i < node->FUN_0043b480(); ++i)
        {
            NiAVObject* child = node->GetAt(i);
            if (IsObjectNetValid(child))
                return true;
        }
    return false;
}

// Computes an angle from vector.x and vector.y using logf of their ratio, adding pi when y is negative and using pi/2 or 3pi/2 when y is zero.
// @fnv 0x004b1550
float GetAngleFromVector(const NiPoint3& vector)
{
    float angle = 0.0f;
    if (vector.y != 0.0)
    {
        float ratio = vector.x / vector.y;
        angle = logf(ratio);
        if (vector.y < 0.0)
            angle += 3.1415927410125732;
    }
    else
    {
        if (vector.x > 0.0)
            angle = 1.5707963705062866f;
        else
            angle = 4.71238899230957f;
    }
    return angle;
}

// Traverses the NiAVObject tree with filter flags set from the skip arguments and returns the accumulated collision object count.
// @fnv 0x004b66d0
int CountCollisionObjects(NiAVObject* object, bool skipPhantoms, bool skipBlendObjects, bool skipUnknown)
{
    CollisionObjectCountContext context;
    context.uiTraversalFlags = 0x12;
    context.bRecurse = true;
    context.iCount = 0;
    context.uiFilterFlags = 0;
    if (skipPhantoms)
        context.uiFilterFlags |= 1;
    if (skipBlendObjects)
        context.uiFilterFlags |= 2;
    if (skipUnknown)
        context.uiFilterFlags |= 4;
    FUN_00c68900(object, &context, FUN_004b6740);
    return context.iCount;
}

// Returns true when m_spWorldBound is set and its FUN_0084d030 result is non-zero.
// @fnv 0x004b2960
int NiAVObject::IsVisualObject()
{
    return m_spWorldBound && m_spWorldBound->FUN_0084d030() != 0.0;
}

// If a look-at target exists, copies the stored look-at point into point and returns true; otherwise returns false.
// @fnv 0x009de270
bool ActorMover::GetLookAtTargetPosition(NiPoint3& point)
{
    if (HasLookAtTarget())
    {
        point = m_kLookAtTargetPosition;
        return true;
    }
    return false;
}

// @fnv 0x006ca0c0
bool PathingGraphNode::IsTransitionNode()
{
    return (iFlags & 4) == 4;
}

// @fnv 0x004b7220
LANGUAGE GetConfiguredLanguage()
{
    LANGUAGE language = static_cast<LANGUAGE>(BSSysInfoSystemUtility::GetRandomGenerator());
    return language;
}

// @fnv 0x00430830
RecipeCraftingInfo* TESRecipe::GetData()
{
    return &data;
}

// @fnv 0x00605d20
bool IsSettingEnabled()
{
    return DAT_011d5a30.Bool()->b;
}

// @fnv 0x00888960
bool bhkWorld::QPickCountOverride()
{
    return DAT_012677a3;
}

double __cdecl FUN_00ec9010(double);

// @fnv 0x004b1460
float FUN_004b1460(float _X)
{
    return static_cast<float>(FUN_00ec9010(_X));
}

double __cdecl FUN_00ec9130(double, double);

// @fnv 0x004b1520
float __cdecl FUN_004b1520(float _X, float _Y)
{
    return (float)FUN_00ec9130((double)_X, (double)_Y);
}

class NiPick
{
  public:
    bool PerformPick(const NiPoint3&, const NiPoint3&, bool);
};

class FOPipboyManager
{
  public:
    void FUN_00705fc0(NiNode*);
};

extern const NiPoint3 NiPoint3_ZERO;
bool __cdecl PickObjectsInRadius(NiPick*, int, int, float, int);

// @fnv 0x004b2780
bool __cdecl FUN_004b2780(NiPick* pPicker, int p2, int p3, float p4, int p5, bool p6)
{
    bool bResult = false;
    if (pPicker != 0 && p5 != 0 && p4 != 0.0)
    {
        if (p6)
        {
            ((FOPipboyManager*)pPicker)->FUN_00705fc0(0);
            pPicker->PerformPick(NiPoint3_ZERO, NiPoint3_ZERO, false);
        }
        bResult = PickObjectsInRadius(pPicker, p2, p3, p4, p5);
    }
    return bResult;
}

// Maps value from the range [y1,y2] onto [x1,x2] by linear interpolation and returns the result.
// @fnv 0x004b3ab0
float LinearInterpolate(float x1, float x2, float y1, float y2, float value)
{
    return x1 + (value - y1) / (y2 - y1) * (x2 - x1);
}

struct FourByFourMatrix
{
    float _11;
    float _12;
    float _13;
    float _14;
    float _21;
    float _22;
    float _23;
    float _24;
    float _31;
    float _32;
    float _33;
    float _34;
    float _41;
    float _42;
    float _43;
    float _44;
};
typedef char _sizecheck__XMMATRIX[sizeof(FourByFourMatrix) == 64 ? 1 : -1];
struct SwizzledMatrix : public FourByFourMatrix
{
    void SetUnswizzled(float*, float*, float);
    void SetUnswizzled(float*);
    void SwizzleFrom(void*);
    void SwizzleFrom4X3(void*);
    void SwizzleTo(SwizzledMatrix*);
    void SwizzleTo4X3(SwizzledMatrix*);
    void SwizzleTo4X4(SwizzledMatrix*);
    void TransposeTo(SwizzledMatrix*);
    void Set(void*);
};
typedef char _sizecheck_BSMatrix[sizeof(SwizzledMatrix) == 64 ? 1 : -1];
struct FourComponentNumericValue
{
    char u[16];
};
typedef char _sizecheck___vector4[sizeof(FourComponentNumericValue) == 16 ? 1 : -1];
struct FUN_004b4500_shell : public SwizzledMatrix
{
    void FUN_004b4500(SwizzledMatrix*);
};

struct NiPoint3b : public NiPoint3
{
    NiPoint3b(float, float, float);
};
struct M_004b4500 : public SwizzledMatrix
{
    NiPoint3b FUN_004b4500(const NiPoint3* v);
};
// Multiplies the 3x3 part of this matrix by vector v and returns the resulting NiPoint3.
// @fnv 0x004b4500
NiPoint3b M_004b4500::FUN_004b4500(const NiPoint3* apVector)
{
    return NiPoint3b(reinterpret_cast<float*>(this)[0] * reinterpret_cast<const float*>(apVector)[0] +
                         reinterpret_cast<float*>(this)[1] * reinterpret_cast<const float*>(apVector)[1] +
                         reinterpret_cast<float*>(this)[2] * reinterpret_cast<const float*>(apVector)[2],
                     reinterpret_cast<float*>(this)[3] * reinterpret_cast<const float*>(apVector)[0] +
                         reinterpret_cast<float*>(this)[4] * reinterpret_cast<const float*>(apVector)[1] +
                         reinterpret_cast<float*>(this)[5] * reinterpret_cast<const float*>(apVector)[2],
                     reinterpret_cast<float*>(this)[6] * reinterpret_cast<const float*>(apVector)[0] +
                         reinterpret_cast<float*>(this)[7] * reinterpret_cast<const float*>(apVector)[1] +
                         reinterpret_cast<float*>(this)[8] * reinterpret_cast<const float*>(apVector)[2]);
}

struct NiFrustumPlanes
{
    void Set(void*, void*);
    void Set(void*);
    void* GetPlane(unsigned int);
    void SetWaterColorParameter(unsigned int, void*);
    bool IsPlaneActive(unsigned int);
    bool IsAnyPlaneActive();
    bool AreAllPlanesActive();
    void EnablePlane(unsigned int);
    void DisablePlane(unsigned int);
    void EnableAllPlanes();
    void DisableAllPlanes();
    unsigned int GetActivePlaneState();
    void SetActivePlaneState(unsigned int);
    char m_akPlanes[96];
    unsigned int m_uiActivePlaneMask;
};
typedef char _sizecheck_NiFrustumPlanes[sizeof(NiFrustumPlanes) == 100 ? 1 : -1];
struct FUN_004b4cf0_shell : public NiFrustumPlanes
{
    void* FUN_004b4cf0(unsigned int);
};

// @fnv 0x004b4cf0
void* FUN_004b4cf0_shell::FUN_004b4cf0(unsigned int ePlane)
{
    return reinterpret_cast<char*>(this) + (ePlane * 16);
}

struct hkQuaternion;
struct hkVector4;
struct FourDimensionalVector
{
    hkQuaternion* ToHK(hkQuaternion*);
    hkVector4* ToHK(hkVector4*);
    void set(float, float, float, float);
    void setZero4();
    void setAll3(float);
    void mul4(float);
    FourDimensionalVector* NI2HKNS(void*);
    FourDimensionalVector* FromHK(void*);
    float fX;
    float fY;
    float fZ;
    float fW;
};
typedef char _sizecheck_bhkVector4[sizeof(FourDimensionalVector) == 16 ? 1 : -1];
struct FUN_004b4e50_shell : public FourDimensionalVector
{
    FourDimensionalVector* SetFromScaledVector3(void*);
};

extern float runtimeInitializationFloat2127;

// @fnv 0x004b4e50
FourDimensionalVector* FUN_004b4e50_shell::SetFromScaledVector3(void* arSrc)
{
    fX = runtimeInitializationFloat2127 * ((const float*)arSrc)[0];
    fY = runtimeInitializationFloat2127 * ((const float*)arSrc)[1];
    fZ = runtimeInitializationFloat2127 * ((const float*)arSrc)[2];
    fW = 0.0f;
    return this;
}

template <class T> class BSSimpleList;
class BGSRagdoll;

class TESDataHandler
{
  public:
    BSSimpleList<BGSRagdoll*>* GetBGSRagdollList();
};

int __fastcall FUN_004b4f20(void* pThis);

// @fnv 0x004b4f00
int __fastcall FUN_004b4f00(TESDataHandler* apDataHandler)
{
    return FUN_004b4f20(apDataHandler->GetBGSRagdollList());
}

namespace fnv_004b4ff0 {
struct hkQuaternion;
struct hkVector4;
struct FourDimensionalVector
{
    hkQuaternion* ToHK(hkQuaternion*);
    hkVector4* ToHK(hkVector4*);
    void set(float, float, float, float);
    void setZero4();
    void setAll3(float);
    void mul4(float);
    FourDimensionalVector* NI2HKNS(void*);
    FourDimensionalVector* FromHK(void*);
    float fX;
    float fY;
    float fZ;
    float fW;
};
typedef char _sizecheck_bhkVector4[sizeof(FourDimensionalVector) == 16 ? 1 : -1];
struct FUN_004b4ff0_shell : public FourDimensionalVector
{
    void FUN_004b4ff0(float, float, float, float);
};

// @fnv 0x004b4ff0
void FUN_004b4ff0_shell::FUN_004b4ff0(float afX, float afY, float afZ, float afW)
{
    fX = afX;
    fY = afY;
    fZ = afZ;
    fW = afW;
}
}  // namespace fnv_004b4ff0

struct PhysicsSimulationContext;
struct hkMatrix3;
struct hkMotionState;
struct hkMultiThreadCheck;
struct hkReferencedObject;
struct hkStatisticsCollector;
struct hkTransform;
struct hkVector4;
struct hkaiObjectData;
struct hkdBreakableBody;
struct hkpAction;
struct hkpBreakableBody;
struct hkpCollidable;
struct hkpConstraintInstance;
struct hkpContactListener;
struct hkpDynamicsContactMgr;
struct hkpEntity;
struct hkpEntityActivationListener;
struct hkpEntityListener;
struct hkpLinkedCollidable;
struct hkpMaterial;
struct hkpMaxSizeMotion;
struct hkpMotion;
struct hkpRigidBody;
struct WorldPhysicsSettings;
struct hkpSimulationIsland;
struct hkpWorld;
struct blob1
{
    char b[1];
};
struct blob8
{
    char b[8];
};

hkpRigidBody* __fastcall FUN_004ae750(void*);
float __fastcall getMass(hkpRigidBody*);

// @fnv 0x004b5400
float __fastcall GetMass(void* pThis)
{
    hkpRigidBody* pb = FUN_004ae750(pThis);
    return pb ? getMass(pb) : 0.0f;
}

bool __cdecl FUN_004b5470(const NiPoint3& aPt, float afCompLength);

struct NiPoint3_sub : public NiPoint3
{
    NiPoint3 operator-(const NiPoint3& pt) const;
};

// @fnv 0x004b5440
bool __cdecl FUN_004b5440(const NiPoint3& aPt1, const NiPoint3& aPt2, float afCompLength)
{
    return FUN_004b5470(((const NiPoint3_sub&)aPt1) - aPt2, afCompLength);
}

float __cdecl FUN_004b5530(float);

// @fnv 0x004b5510
float __cdecl FUN_004b5510(float _X)
{
    return FUN_004b5530(_X);
}

double __cdecl FUN_00ec9610(double);

// @fnv 0x004b5530
float FUN_004b5530(float value)
{
    return static_cast<float>(FUN_00ec9610(value));
}

float __cdecl FUN_004b5590(float, float);

// @fnv 0x004b5570
float __cdecl FUN_004b5570(float _Y, float _X)
{
    return FUN_004b5590(_Y, _X);
}

int __fastcall FUN_004b5980(const void* collidable);
void* __cdecl FUN_004b59c0(const void* collidable);

// Returns the result of FUN_004b59c0 when FUN_004b5980 reports 2 for collidable, otherwise returns 0.
// @fnv 0x004b5950
void* __cdecl FUN_004b5950(const void* collidable)
{
    if (FUN_004b5980(collidable) == 2)
    {
        return FUN_004b59c0(collidable);
    }
    return 0;
}

// @fnv 0x004b59d0
const void* __fastcall getOwner(const char* apBase)
{
    return apBase + apBase[0x10];
}

int __fastcall FUN_004b5980(const void* collidable);
void* __cdecl FUN_004b59c0(const void* collidable);

// Returns the result of FUN_004b59c0 when FUN_004b5980 reports 1 for collidable, otherwise returns 0.
// @fnv 0x004b59f0
void* __cdecl FUN_004b59f0(const void* collidable)
{
    if (FUN_004b5980(collidable) == 1)
    {
        return FUN_004b59c0(collidable);
    }
    return 0;
}

class NiShader
{
  public:
    static NiAVObject* __cdecl DynamicCast(NiAVObject*);
};

extern char const* const g_012683d0_arg1;
void* __cdecl DynamicCastByRTTI(const void*, NiAVObject*);

// @fnv 0x004b5ad0
void* __cdecl FUN_004b5ad0(NiAVObject* apPhantom)
{
    NiAVObject* pc = NiShader::DynamicCast(apPhantom);
    return DynamicCastByRTTI(&g_012683d0_arg1, pc);
}

class BSXFlags
{
  public:
    unsigned int GetFlags(unsigned int) const;
};

// @fnv 0x004b5fa0
bool __fastcall FUN_004b5fa0(const BSXFlags* pThis)
{
    return pThis->GetFlags(0x20) != 0;
}

struct NiPlane_004b6100
{
    float Distance(void*);
};
struct B_004b6100
{
    float cx, cy, cz, radius;
    int ClassifySphereAgainstPlane(NiPlane_004b6100* m_kFogPlane);
};
// Computes the plane distance to this sphere and returns 2 if fully behind, 1 if fully in front, or 0 if straddling.
// @fnv 0x004b6100
int B_004b6100::ClassifySphereAgainstPlane(NiPlane_004b6100* m_kFogPlane)
{
    float fDistance = m_kFogPlane->Distance(this);
    if (fDistance <= -radius)
        return 2;
    else if (fDistance >= radius)
        return 1;
    else
        return 0;
}

struct NiPoint3_ext : NiPoint3
{
    float Dot(const NiPoint3& pt) const;
};

struct FUN_004b6160_class
{
    NiPoint3_ext normal;
    float d;
    float EvaluatePlane(const NiPoint3& pt) const;
};

// @fnv 0x004b6160
float FUN_004b6160_class::EvaluatePlane(const NiPoint3& aPoint) const
{
    return normal.Dot(aPoint) - d;
}

struct FUN_004b6190_shell : public NiPoint3
{
    float DotProduct(void*);
};

// Returns the dot product of this NiPoint3 with the NiPoint3 pointed to by pt.
// @fnv 0x004b6190
float FUN_004b6190_shell::DotProduct(void* apPoint)
{
    return x * static_cast<const NiPoint3*>(apPoint)->x + y * static_cast<const NiPoint3*>(apPoint)->y +
           z * static_cast<const NiPoint3*>(apPoint)->z;
}

int __cdecl FUN_00408b20(const char*, const char*);
extern NiRTTI DAT_011f9140;
extern NiRTTI g_0126817c;

class TESObjectREFR
{
  public:
    unsigned int GetFlags();
};

// Skips incrementing the counter at data+0xc when the object matches the RTTI checks or is an Arrow; otherwise increments it.
// @fnv 0x004b6740
void __cdecl FUN_004b6740(NiAVObject* apObject, char* data)
{
    if ((*(unsigned int*)(data + 0x18) & 1) && FUN_0043b300(&g_0126817c, apObject))
        return;
    if ((*(unsigned int*)(data + 0x18) & 2) &&
        FUN_0043b300(&DAT_011f9140, (NiAVObject*)((TESObjectREFR*)apObject)->GetFlags()))
        return;
    if ((*(unsigned int*)(data + 0x18) & 2) && ((TESObjectREFR*)apObject)->GetFlags() &&
        ((BSFadeNode*)((TESTopicInfoData*)((TESObjectREFR*)apObject)->GetFlags())->GetLinkToList())
            ->FUN_0043b1b0() &&
        !FUN_00408b20(
            (const char*)((BSFadeNode*)((TESTopicInfoData*)((TESObjectREFR*)apObject)->GetFlags())->GetLinkToList())
                ->FUN_0043b1b0(),
            "Arrow"))
        return;
    *(int*)(data + 0xc) += 1;
}

template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

// @fnv 0x004b6e70
const char* __fastcall GetStringAtOffset13C(const char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0x13c);
}

bool __cdecl FUN_004b71d0(void);

// Returns 1 if FUN_004b71d0() returns true, otherwise returns 0.
// @fnv 0x004b71a0
int FUN_004b71a0()
{
    int result = 0;
    if (FUN_004b71d0())
        result = 1;
    return result;
}

class MobileObject
{
  public:
    bool GetCharControllerFlag() const;
};

extern bool DAT_011d8a84;
extern MobileObject g_011d8c4c;
void* __cdecl FUN_004b7210(void);

// Returns true when DAT_011d8a84 is set and, after calling FUN_004b7210, g_011d8c4c reports its char controller flag.
// @fnv 0x004b71d0
bool __cdecl FUN_004b71d0()
{
    return DAT_011d8a84 && (FUN_004b7210(), g_011d8c4c.GetCharControllerFlag());
}

struct FUN_0063f790_shell : public NiBound
{
    void FUN_0063f790(float);
};

// @fnv 0x0063f790
void FUN_0063f790_shell::FUN_0063f790(float afRadius)
{
    *(float*)((char*)this + 0xc) = afRadius;
}

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};
typedef char _sizecheck_tagRECT[sizeof(tagRECT) == 16 ? 1 : -1];

struct NiPoint3Ex : public NiPoint3
{
    NiPoint3Ex(float fX, float fY, float fZ);
    NiPoint3Ex operator+(const NiPoint3Ex& pt) const;
    NiPoint3Ex operator-(const NiPoint3& pt) const;
    float Length() const;
    void ComputeMagnitude();
};

// @fnv 0x004b1e80
bool FUN_004b1e80(const tagRECT* aTestRect, const NiPoint3* aStartPt, const NiPoint3* aEndPt,
                  NiPoint3* aOutputIntersectPt)
{
    bool bIntersect = false;

    if (aTestRect->left >= aTestRect->right)
        return false;
    if (aTestRect->bottom >= aTestRect->top)
        return false;
    if (aStartPt->x < aTestRect->left && aEndPt->x < aTestRect->left)
        return false;
    if (aStartPt->y < aTestRect->bottom && aEndPt->y < aTestRect->bottom)
        return false;
    if (aStartPt->x > aTestRect->right && aEndPt->x > aTestRect->right)
        return false;
    if (aStartPt->y > aTestRect->top && aEndPt->y > aTestRect->top)
        return false;
    if (aStartPt->x > aTestRect->left && aStartPt->x < aTestRect->right && aStartPt->y > aTestRect->bottom &&
        aStartPt->y < aTestRect->top && aEndPt->x > aTestRect->left && aEndPt->x < aTestRect->right &&
        aEndPt->y > aTestRect->bottom && aEndPt->y < aTestRect->top)
        return false;

    if (aEndPt->x == aStartPt->x || aEndPt->y == aStartPt->y)
    {
        if (aEndPt->x == aStartPt->x && aEndPt->y == aStartPt->y)
        {
            if (aStartPt->x <= aTestRect->right && aStartPt->x >= aTestRect->left && aStartPt->y <= aTestRect->top &&
                aStartPt->y >= aTestRect->bottom)
            {
                bIntersect = true;
                *aOutputIntersectPt = *aStartPt;
            }
        }
        else if (aEndPt->x == aStartPt->x)
        {
            if (aStartPt->x <= aTestRect->right && aStartPt->x >= aTestRect->left)
            {
                bIntersect = true;
                if (aStartPt->y > aEndPt->y)
                    *aOutputIntersectPt = NiPoint3Ex(aStartPt->x, aTestRect->top, 0.0f);
                else
                    *aOutputIntersectPt = NiPoint3Ex(aStartPt->x, aTestRect->bottom, 0.0f);
            }
        }
        else if (aEndPt->y == aStartPt->y)
        {
            if (aStartPt->y <= aTestRect->top && aStartPt->y >= aTestRect->bottom)
            {
                bIntersect = true;
                if (aStartPt->x > aEndPt->x)
                    *aOutputIntersectPt = NiPoint3Ex(aTestRect->right, aStartPt->y, 0.0f);
                else
                    *aOutputIntersectPt = NiPoint3Ex(aTestRect->left, aStartPt->y, 0.0f);
            }
        }
    }
    else
    {
        int intersectsFound = 0;
        NiPoint3Ex intersect1(3.402823466e+38F, 3.402823466e+38F, 3.402823466e+38F);
        NiPoint3Ex intersect2(3.402823466e+38F, 3.402823466e+38F, 3.402823466e+38F);
        float slope = (aEndPt->y - aStartPt->y) / (aEndPt->x - aStartPt->x);
        float intercept = aEndPt->y - aEndPt->x * slope;

        if (intersectsFound < 2)
        {
            float YatBorder = aTestRect->left * slope + intercept;
            if (YatBorder <= aTestRect->top && YatBorder >= aTestRect->bottom)
            {
                if (intersectsFound == 0)
                    intersect1 = NiPoint3Ex(aTestRect->left, YatBorder, 0.0f);
                else
                    intersect2 = NiPoint3Ex(aTestRect->left, YatBorder, 0.0f);
                intersectsFound++;
            }
        }
        if (intersectsFound < 2)
        {
            float XatBorder = (aTestRect->top - intercept) / slope;
            if (XatBorder <= aTestRect->right && XatBorder >= aTestRect->left)
            {
                if (intersectsFound == 0)
                    intersect1 = NiPoint3Ex(XatBorder, aTestRect->top, 0.0f);
                else
                    intersect2 = NiPoint3Ex(XatBorder, aTestRect->top, 0.0f);
                intersectsFound++;
            }
        }
        if (intersectsFound < 2)
        {
            float YatBorder = aTestRect->right * slope + intercept;
            if (YatBorder <= aTestRect->top && YatBorder >= aTestRect->bottom)
            {
                if (intersectsFound == 0)
                    intersect1 = NiPoint3Ex(aTestRect->right, YatBorder, 0.0f);
                else
                    intersect2 = NiPoint3Ex(aTestRect->right, YatBorder, 0.0f);
                intersectsFound++;
            }
        }
        if (intersectsFound < 2)
        {
            float XatBorder = (aTestRect->bottom - intercept) / slope;
            if (XatBorder <= aTestRect->right && XatBorder >= aTestRect->left)
            {
                if (intersectsFound == 0)
                    intersect1 = NiPoint3Ex(XatBorder, aTestRect->bottom, 0.0f);
                else
                    intersect2 = NiPoint3Ex(XatBorder, aTestRect->bottom, 0.0f);
                intersectsFound++;
            }
        }

        if (intersectsFound)
        {
            bIntersect = true;
            if (intersectsFound == 2)
            {
                if (aStartPt->x > aTestRect->left && aStartPt->x < aTestRect->right &&
                    aStartPt->y > aTestRect->bottom && aStartPt->y < aTestRect->top)
                {
                    NiPoint3Ex linevect = (const NiPoint3Ex&)*aEndPt - *aStartPt;
                    NiPoint3Ex intersect1vect = intersect1 - *aStartPt;
                    linevect.z = 0.0f;
                    intersect1vect.z = 0.0f;
                    linevect.ComputeMagnitude();
                    intersect1vect.ComputeMagnitude();
                    if ((linevect + intersect1vect).Length() > 1.0)
                        *aOutputIntersectPt = intersect1;
                    else
                        *aOutputIntersectPt = intersect2;
                }
                else if ((intersect1 - *aStartPt).Length() < (intersect2 - *aStartPt).Length())
                {
                    *aOutputIntersectPt = intersect1;
                }
                else
                {
                    *aOutputIntersectPt = intersect2;
                }
            }
            else
            {
                *aOutputIntersectPt = intersect1;
            }
        }
    }
    return bIntersect;
}

struct bhkRefObject
{
    bhkRefObject* Initialize();
};

extern unsigned char DAT_0102023c;

struct FUN_004b5120 : bhkRefObject
{
    void* vtbl;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
    int m_pad3;
    FUN_004b5120();
};

// Calls Initialize, installs the vtable pointer at offset 0 and zeroes the int at offset 0xc.
// @fnv 0x004b5120
FUN_004b5120::FUN_004b5120()
{
    Initialize();
    *reinterpret_cast<void**>(this) = &DAT_0102023c;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xc) = 0;
}

struct FUN_004b51a0_shell
{
    void* FUN_004b51a0(unsigned int flags);
};

struct FUN_00c87970_shell
{
    void __thiscall FUN_00c87970();
};

void __cdecl __Dummy_00b6fef0(void* obj, unsigned int size);

// @fnv 0x004b51a0
void* FUN_004b51a0_shell::FUN_004b51a0(unsigned int flags)
{
    ((FUN_00c87970_shell*)this)->FUN_00c87970();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x10);
    return this;
}

extern const char* const g_0126812c_arg1;

struct FUN_004b51d0_shell
{
    const char* const* __thiscall GetRTTI();
};

// @fnv 0x004b51d0
const char* const* __thiscall FUN_004b51d0_shell::GetRTTI()
{
    return &g_0126812c_arg1;
}

extern const NiRTTI g_0126812c;

struct FUN_004b5210_shell
{
    const NiRTTI* GetRTTI() const;
};

// @fnv 0x004b5210
const NiRTTI* FUN_004b5210_shell::GetRTTI() const
{
    return &g_0126812c;
}

// @fnv 0x004b59a0
int __fastcall GetCharAtOffset4(int param_1)
{
    return (int)*(char*)(param_1 + 4);
}

// @fnv 0x004b5f60
const NiFixedString& FUN_004b5f60()
{
    return *DAT_011c61f0;
}

// @fnv 0x004b5f70
const NiFixedString& FUN_004b5f70()
{
    return *DAT_011c61f4;
}

// @fnv 0x004b5f80
const NiFixedString& FUN_004b5f80()
{
    return *DAT_011c61f8;
}

// @fnv 0x004b5f90
const NiFixedString& FUN_004b5f90()
{
    return *DAT_011c61fc;
}

struct bhkWorldObject;
struct bhkCollisionObject
{
    bhkWorldObject* FUN_006fa820();
};
int __fastcall GetReferenceFlags(void*);

// Gets the collision object's world object and, if it exists and GetReferenceFlags returns nonzero, increments the fourth int of arg.
// @fnv 0x004b6b20
void __cdecl FUN_004b6b20(bhkCollisionObject* apCollisionObject, void* apData)
{
    bhkWorldObject* result = apCollisionObject->FUN_006fa820();
    if (result && GetReferenceFlags(result))
        ((int*)apData)[3]++;
}

namespace fnv_004b6bc0 {
struct bhkWorldObject;
struct bhkCollisionObject
{
    bhkWorldObject* FUN_006fa820(void);
};

int __fastcall GetReferenceFlags(bhkWorldObject*);

// @fnv 0x004b6bc0
void FUN_004b6bc0(bhkCollisionObject* apCollisionObject, void* dest)
{
    bhkWorldObject* w = apCollisionObject->FUN_006fa820();
    if (w)
    {
        int r = GetReferenceFlags(w);
        if (r)
        {
            if (r == ((int*)dest)[4])
            {
                ((int*)dest)[5] = ((int*)dest)[3];
            }
            ((int*)dest)[3] = ((int*)dest)[3] + 1;
        }
    }
}
}  // namespace fnv_004b6bc0

namespace fnv_004b6c70 {
struct bhkCollisionObject
{
    int* FUN_006fa820();
};

int __fastcall GetReferenceFlags(int* obj);

// @fnv 0x004b6c70
void __cdecl FUN_004b6c70(bhkCollisionObject* apCollisionObject, int* arg2)
{
    int* obj = apCollisionObject->FUN_006fa820();
    if (obj)
    {
        int result = GetReferenceFlags(obj);
        if (result)
        {
            if (arg2[3] == arg2[5])
            {
                arg2[4] = result;
            }
            arg2[3] = arg2[3] + 1;
        }
    }
    arg2[3] = arg2[3] + 1;
}
}  // namespace fnv_004b6c70

namespace fnv_004b7210 {
struct UIRoot;
extern UIRoot* DAT_011d8a80;

// @fnv 0x004b7210
UIRoot* FUN_004b7210()
{
    return DAT_011d8a80;
}
}  // namespace fnv_004b7210

namespace fnv_004b50f0 {
struct FUN_004b5120
{
    FUN_004b5120();
};

extern int DAT_0102016c;
extern int DAT_01268154;

struct FUN_004b50f0 : FUN_004b5120
{
    int* m_p;
    FUN_004b50f0();
};

FUN_004b5120::FUN_004b5120()
{}

// Sets m_p to the address of DAT_0102016c and increments DAT_01268154.
// @fnv 0x004b50f0
FUN_004b50f0::FUN_004b50f0()
{
    m_p = &DAT_0102016c;
    ++DAT_01268154;
}
}  // namespace fnv_004b50f0

extern char const* const g_01268100_arg1;

struct FUN_004b5150_shell
{
    char const* const* __thiscall FUN_004b5150();
};

// @fnv 0x004b5150
char const* const* __thiscall FUN_004b5150_shell::FUN_004b5150()
{
    return &g_01268100_arg1;
}

struct bhkSerializable
{
    void Destroy();
    void* FUN_004b5160(unsigned int flags);
};

extern void _delete(void* ptr, unsigned int size);

// Calls Destroy on this, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x004b5160
void* bhkSerializable::FUN_004b5160(unsigned int flags)
{
    this->Destroy();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

extern const char* const g_0126811c_arg1;

struct FUN_004b5190_shell
{
    const char* const* FUN_004b5190();
};

// @fnv 0x004b5190
const char* const* FUN_004b5190_shell::FUN_004b5190()
{
    return &g_0126811c_arg1;
}

struct bhkUnaryAction
{
    void __thiscall FUN_00c86720();
};
extern void __cdecl _delete(void* ptr, unsigned int size);

struct FUN_004b51e0_shell : bhkUnaryAction
{
    void* __thiscall FUN_004b51e0(unsigned int flags);
};

// @fnv 0x004b51e0
void* __thiscall FUN_004b51e0_shell::FUN_004b51e0(unsigned int flags)
{
    this->FUN_00c86720();
    if (flags & 1)
        _delete(this, 16);
    return this;
}

int __fastcall GetCharAtOffset4(int);

// @fnv 0x004b5980
int __fastcall FUN_004b5980(int param_1)
{
    return GetCharAtOffset4(param_1 + 0x14);
}

void const* __fastcall getOwner(char const*);

// @fnv 0x004b59c0
void const* __cdecl FUN_004b59c0(char const* arg)
{
    return getOwner(arg);
}

namespace fnv_004b4d10 {
struct bhkUnaryAction
{
    void Set(float, float, float, float);
};
struct UnaryActionSettings
{
    float f00;
    float f04;
    float f08;
    float f0C;
    bhkUnaryAction* ApplyToAction(bhkUnaryAction*);
};
// Calls Set on the given bhkUnaryAction with this object's four floats and returns the action.
// @fnv 0x004b4d10
bhkUnaryAction* UnaryActionSettings::ApplyToAction(bhkUnaryAction* apAction)
{
    apAction->Set(f00, f04, f08, f0C);
    return apAction;
}
}  // namespace fnv_004b4d10

namespace fnv_004b4ec0 {
struct BSSimpleList_Ragdoll;
struct FUN_004b4ee0_shell
{
    void FUN_004b4ee0();
};
struct TESDataHandler
{
    BSSimpleList_Ragdoll* GetBGSRagdollList();
};
struct FUN_004b4ec0_shell
{
    void FUN_004b4ec0();
};
// @fnv 0x004b4ec0
void FUN_004b4ec0_shell::FUN_004b4ec0()
{
    ((FUN_004b4ee0_shell*)((TESDataHandler*)this)->GetBGSRagdollList())->FUN_004b4ee0();
}
}  // namespace fnv_004b4ec0

extern "C" void __cdecl _ref_006815c0();
struct FUN_004b4f20_shell
{
    void __thiscall FUN_004b4f20();
};
// @fnv 0x004b4f20
void __thiscall FUN_004b4f20_shell::FUN_004b4f20()
{
    ((void(__thiscall*)(void*))_ref_006815c0)((char*)this + 0x10);
}

extern float DAT_0101b2d0;
extern float const g_011cc6cc_arg1;
struct Base537
{
    char _d[0x10];
    void FUN_00537bb0();
};
struct Mem4fa0
{
    char _d[0x10];
    void FUN_004b4fa0();
};
struct FUN_004b4f40 : Base537
{
    Mem4fa0 m10;
    Mem4fa0 m20;
    float f30;
    float f34;
    float f38;
    float f3c;
    FUN_004b4f40();
};
// Calls base and member initializers, then sets f30 to 0.5, f34 to 0.3, f38 to DAT_0101b2d0 and f3c to g_011cc6cc_arg1.
// @fnv 0x004b4f40
FUN_004b4f40::FUN_004b4f40()
{
    FUN_00537bb0();
    m10.FUN_004b4fa0();
    m20.FUN_004b4fa0();
    f30 = 0.5f;
    f34 = 0.3f;
    f38 = DAT_0101b2d0;
    f3c = g_011cc6cc_arg1;
}

struct FUN_004b4fa0_shell
{
    void* __fastcall FUN_004b4fa0();
};

void* __fastcall FUN_004b4fc0(void*);

// @fnv 0x004b4fa0
void* __fastcall FUN_004b4fa0_shell::FUN_004b4fa0()
{
    FUN_004b4fc0(this);
    return this;
}

struct S_004b4fc0
{
    void FUN_004b4ff0(float, float, float, float);
    void FUN_004b4fc0();
};
// Calls FUN_004b4ff0 with four zero float arguments.
// @fnv 0x004b4fc0
void S_004b4fc0::FUN_004b4fc0()
{
    FUN_004b4ff0(0.0f, 0.0f, 0.0f, 0.0f);
}

extern int DAT_0102009c;
extern int DAT_01268118;
struct Fake004b50c0
{
    void FUN_004b50f0();
    Fake004b50c0* FUN_004b50c0();
};
// @fnv 0x004b50c0
Fake004b50c0* Fake004b50c0::FUN_004b50c0()
{
    FUN_004b50f0();
    *(int*)this = (int)&DAT_0102009c;
    DAT_01268118++;
    return this;
}

struct bhkMouseSpringAction
{
    void __thiscall FUN_00c86cb0();
    void* __thiscall FUN_004b5230(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Calls FUN_00c86cb0, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x004b5230
void* __thiscall bhkMouseSpringAction::FUN_004b5230(unsigned int flags)
{
    this->FUN_00c86cb0();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

namespace fnv_004b5260 {
struct bhkCollisionObject
{
    static NiAVObject* GetFromNiAVObject(NiAVObject*);
};
// @fnv 0x004b5260
NiAVObject* FUN_004b5260(NiAVObject* object)
{
    NiAVObject* result = 0;
    if (object)
    {
        result = bhkCollisionObject::GetFromNiAVObject(object);
        if (!result)
        {
            NiNode* node = object->GetAsNiNode();
            if (node)
            {
                unsigned int count = node->FUN_0043b480();
                for (unsigned int i = 0; i < count; ++i)
                {
                    result = FUN_004b5260(node->GetAt(i));
                    if (result)
                        break;
                }
            }
        }
    }
    return result;
}
}  // namespace fnv_004b5260

struct TESCombatStyle
{
    float UpdateCombatStyle();
};
// @fnv 0x004b5470
int FUN_004b5470(TESCombatStyle* apCombatStyle, float afValue)
{
    float f1;
    float f2;
    f1 = apCombatStyle->UpdateCombatStyle();
    f2 = afValue * afValue;
    if (f1 < f2)
        return -1;
    else
    {
        if (f1 > f2)
            return 1;
    }
    return 0;
}

extern float runtimeInitializationFloat825;
float __cdecl FUN_004b5510(float);
// @fnv 0x004b54c0
float __cdecl FUN_004b54c0(float afValue)
{
    if (afValue > -1.0)
    {
        if (afValue < 1.0)
        {
            return FUN_004b5510(afValue);
        }
        else
        {
            return runtimeInitializationFloat825;
        }
    }
    else
    {
        return -runtimeInitializationFloat825;
    }
}

struct GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_011f3728;
// Returns true if object or any descendant NiNode child has a controller matching g_011f3728; recurses through children.
// @fnv 0x004b5bf0
bool FUN_004b5bf0(NiAVObject* object)
{
    if (!object)
        return false;
    if (object->GetController(reinterpret_cast<const NiRTTI*>(&g_011f3728)))
        return true;
    NiNode* node = object->GetAsNiNode();
    if (node)
    {
        for (unsigned int i = 0; i < node->FUN_0043b480(); ++i)
        {
            NiAVObject* child = node->GetAt(i);
            if (FUN_004b5bf0(child))
                return true;
        }
    }
    return false;
}

class NiCamera;
struct FUN_0043d450_Owner
{
    NiBound* FUN_0043d450();
};
bool __cdecl IsBoundVisible(NiBound*, NiCamera*);
// Returns false if apObject is null, otherwise tests the object's bound against apCamera via IsBoundVisible.
// @fnv 0x004b5fc0
bool __cdecl FUN_004b5fc0(NiAVObject* apObject, NiCamera* apCamera)
{
    if (apObject)
    {
        return IsBoundVisible(((FUN_0043d450_Owner*)apObject)->FUN_0043d450(), apCamera);
        goto done;
    }
    return false;
done:;
}

namespace CollisionObjectCount {
struct IntegerAndByteRecord
{
    int _00;
    unsigned char _04;
    int _08;
    int _0C;
    int _10;
    int _14;
    int _18;
};
}
void __cdecl FUN_004b6b20(NiCollisionObject*, CollisionObjectCountContext*);
// @fnv 0x004b6ae0
int FUN_004b6ae0(NiAVObject* apRoot)
{
    CollisionObjectCount::IntegerAndByteRecord recData;
    recData._08 = 18;
    recData._04 = 1;
    recData._0C = 0;
    FUN_00c68900(apRoot, reinterpret_cast<CollisionObjectCountContext*>(&recData), FUN_004b6b20);
    return recData._0C;
}

namespace fnv_004b6c20 {
struct hkpWorldObject;
namespace CollisionObjectCount {
struct IntegerAndByteRecord
{
    int _0;
    bool _4;
    char _5;
    char _6;
    char _7;
    int _8;
    int _12;
    hkpWorldObject* _16;
    int _20;
    int _24;
};
}
void __cdecl FUN_004b6c70(NiCollisionObject*, CollisionObjectCountContext*);
// @fnv 0x004b6c20
hkpWorldObject* FindCollisionObjectByIndex(NiAVObject* apRoot, int aiIndex)
{
    CollisionObjectCount::IntegerAndByteRecord recData;
    recData._8 = 0x12;
    recData._4 = 1;
    recData._12 = 0;
    recData._16 = 0;
    recData._20 = aiIndex;
    FUN_00c68900(apRoot, (CollisionObjectCountContext*)&recData, FUN_004b6c70);
    return recData._16;
}
}  // namespace fnv_004b6c20

struct S004e88d0
{
    float m0;
    float m4;
    S004e88d0& Add(S004e88d0*);
};
// Adds the two floats of p into this object's m0 and m4 and returns *this.
// @fnv 0x004e88d0
S004e88d0& S004e88d0::Add(S004e88d0* apOther)
{
    m0 += apOther->m0;
    m4 += apOther->m4;
    return *this;
}

struct Flt
{
    operator unsigned int() const;
};

struct FUN_004b70d0_shell
{
    char pad[0x3c];
    Flt m_flt;
    unsigned int FUN_004b70d0();
};

// @fnv 0x004b70d0
unsigned int FUN_004b70d0_shell::FUN_004b70d0()
{
    return m_flt.operator unsigned int();
}

struct Sub004B
{
    char pad[16];
    void FUN_004b4fa0();
    void FUN_004b4ff0(float, float, float, float);
};
struct Sub0056
{
    char pad[16];
    void FUN_0056e8d0();
};
struct Owner0066d650
{
    Sub0056 f0;
    Sub004B f10;
    Sub004B f20;
    Owner0066d650* Reset();
};
// @fnv 0x0066d650
Owner0066d650* Owner0066d650::Reset()
{
    f0.FUN_0056e8d0();
    f10.FUN_004b4fa0();
    f20.FUN_004b4fa0();
    f20.FUN_004b4ff0(1.0f, 0.0f, 0.0f, 0.0f);
    return this;
}

namespace fnv_004b2800 {
struct NiPick
{
    void FUN_00705fc0(void*);
    bool PerformPick(const NiPoint3&, const NiPoint3&, bool);
};
struct FUN_00456630_helper
{
    bool FUN_00456610();
};
struct FUN_0043d450_Owner
{
    NiBound* FUN_0043d450();
};
struct Pt
{
    float x, y, z;
    float Length() const;
};
struct NiPoint3Ex
{
    float x, y, z;
    NiPoint3Ex operator-(const NiPoint3&) const;
};
struct FUN_004b2800_Bound
{
    float x, y, z, r;
};
bool __fastcall GetByteAtOffset17(const char*);
NiPoint3Ex* __fastcall _ref_006815c0(FUN_004b2800_Bound*);

// @fnv 0x004b2800
bool PickObjectsInRadius(NiPick* pick, const NiPoint3& origin, const NiPoint3& dir, float radius, NiAVObject* object)
{
    bool result = false;
    if (pick && object && (!GetByteAtOffset17((const char*)pick) || !((FUN_00456630_helper*)object)->FUN_00456610()))
    {
        if (!object->IsVisualObject())
            return false;
        FUN_004b2800_Bound kBound = *(FUN_004b2800_Bound*)((FUN_0043d450_Owner*)object)->FUN_0043d450();
        NiPoint3Ex kDiff = *_ref_006815c0(&kBound) - origin;
        if (((Pt*)&kDiff)->Length() < ((NiBound*)&kBound)->FUN_0084d030() + radius)
        {
            NiNode* node = object->GetAsNiNode();
            if (node)
            {
                int count = node->FUN_0043b480();
                for (int i = 0; i < count; i++)
                {
                    NiAVObject* child = node->GetAt(i);
                    if (PickObjectsInRadius(pick, origin, dir, radius, child))
                        result = true;
                }
            }
            else
            {
                pick->FUN_00705fc0(object);
                if (pick->PerformPick(origin, dir, true))
                    result = true;
            }
        }
    }
    return result;
}
}  // namespace fnv_004b2800

struct BSShaderAccumulator;
struct BSShaderTextureSet;
struct BSTextureSet;
struct NiAdditionalGeometryData;
struct CloningProcess;
struct NiGeometry;
struct NiObject;
struct NiStream;
struct NiTriBasedGeom;
struct ShadowSceneLight;
struct blob16
{
    char b[16];
};
struct NiShadeProperty : public NiProperty
{
    virtual void __vslot_0();
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(NiShadeProperty*, CloningProcess*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    virtual void GetViewerStrings(void*);
    void SetField(unsigned short, unsigned short, unsigned short);
    unsigned short GetField(unsigned short, unsigned short);
    void SetBit(bool, unsigned short);
    bool GetBit(unsigned short);
    void SetSmooth(bool);
    bool GetSmooth();
    bool IsEqualFast(void*);
    virtual int Type();
    static int GetType();
    static NiShadeProperty* GetDefault();
    static void InitializePoint3();
    static void ShutdownPoint3();
    int GetShaderPropertyType();
    void __local_vftable_ctor_closure();
    char _pad_4[20];
    unsigned short m_uiObjectFlags;
    char _pad_1a[2];
    int m_iShaderType;
};
typedef char _sizecheck_NiShadeProperty[sizeof(NiShadeProperty) == 32 ? 1 : -1];
struct BSShaderProperty : public NiShadeProperty
{
    virtual void __vslot_0();
    virtual void CopyTo(BSShaderProperty*);
    virtual void CopyToMembers(BSShaderProperty*);
    virtual bool SetupGeometry(NiGeometry*);
    virtual void* CreateRenderPasses(NiGeometry*, int, unsigned short*, unsigned int, BSShaderAccumulator*, bool);
    virtual unsigned short GetNumberofPasses(NiGeometry*);
    virtual void* GetSIBlockRenderPasses();
    virtual void* GetRenderDepthPass(NiGeometry*);
    virtual BSShaderProperty* ClarifyShader(NiGeometry*, bool, bool);
    virtual NiTexture* GetBaseTexture();
    virtual void* GetWaterFogPassList(NiGeometry*);
    virtual void GetTextureUse(int*, void*);
    virtual void PrecacheTextures();
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSShaderProperty*, CloningProcess*);
    virtual void GetViewerStrings(void*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    virtual void PostLinkObject(NiStream*);
    void* QRenderPasses();
    void CheckCreateRenderPassArray(int);
    void CheckCreateDepthMapRenderPassArray(int);
    void CheckCreateLocalMapRenderPassArray(int);
    void CheckCreateSIBlockRenderPassArray(int);
    void CheckCreateConstAlphaRenderPassArray(int);
    void CheckCreateWaterFogRenderPassArray(int);
    void CheckSilhouetteRenderPassArray(int);
    void SetLastRenderPassState(int);
    bool CompareFlags(BSShaderProperty*);
    bool GetFlag(unsigned int);
    void SetFlag(unsigned int, bool);
    void SetAlpha(float);
    float GetAlpha();
    float GetFadeAlpha();
    void SetFadeAlpha(float);
    void FreeRenderPasses();
    void ClearRenderPasses();
    void SetObjectType(unsigned int);
    unsigned int GetObjectType();
    int QShader();
    void SetShader(int);
    float QEnvmapScale();
    void SetEnvmapScale(float);
    static void ToggleMotionBlurRecurse(NiAVObject*);
    static void SetMotionBlurRecurse(NiAVObject*, bool);
    static void SetFlagRecurse(NiAVObject*, int, bool);
    bool Get1stPerson();
    void Set1stPerson(bool);
    float GetDepthBias();
    void SetDepthBias(float);
    static void ResetDebugStats();
    static void GetDebugStats(unsigned int*);
    void SetMotionBlurred(bool);
    float GetCameraDistance();
    static void ClearRenderPassGarbage();
    void __local_vftable_ctor_closure();
    char ulFlags[8];
    float fAlpha;
    float fFadeAlpha;
    float m_fAmbientReflectionScale;
    float m_fSpecularExponent;
    int iLastRenderPassState;
    void* pRenderPassList;
    void* m_pRenderPassArray1;
    void* m_pRenderPassArray2;
    void* m_pRenderPassArray3;
    void* m_pRenderPassArray4;
    void* m_pRenderPassArray5;
    void* m_pRenderPassArray6;
    int m_iRenderPassCount;
    float fDepthBias;
    float m_fValueAfterDepthBias;
    float m_fEnvironmentMapScale;
};
typedef char _sizecheck_BSShaderProperty[sizeof(BSShaderProperty) == 104 ? 1 : -1];
struct BSShaderLightingProperty : public BSShaderProperty
{
    virtual void __vslot_0();
    virtual void CopyTo(BSShaderLightingProperty*);
    virtual void CopyToMembers(BSShaderLightingProperty*);
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSShaderLightingProperty*, CloningProcess*);
    virtual void GetViewerStrings(void*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    bool CopyLightingDataTo(ShadowSceneLight*, NiBound*, void**);
    void ResortLights(NiBound*);
    bool AreLightsSorted(NiBound*);
    ShadowSceneLight* GetFirstAttachedLight(void**);
    ShadowSceneLight* GetFirstActiveLight(void**);
    ShadowSceneLight* GetFirstActiveNonShadowLight(void**);
    ShadowSceneLight* GetNextLight(void**);
    ShadowSceneLight* GetNextAttachedLight(void**);
    ShadowSceneLight* GetNextVisibleNonShadowLight(void**);
    void AttachLight(ShadowSceneLight*, NiBound*);
    void RemoveLight(ShadowSceneLight*);
    unsigned short GetNumberofLights();
    unsigned short GetNumberOfActiveLights();
    unsigned short GetNumberofActiveNonShadowLights();
    static void SetShaderConstant(int, struct blob16);
    static void SetLight(unsigned int, ShadowSceneLight*, float);
    static void SetLight1x2x(unsigned int, ShadowSceneLight*, float);
    static void SetPointLight3x(unsigned int, ShadowSceneLight*, float);
    static void SetSpotLight3x(unsigned int, ShadowSceneLight*, float);
    static void ResetLights(int);
    void SetForcedDarkness(float);
    float GetForcedDarkness();
    void SetReferenceID(unsigned int);
    unsigned int GetReferenceID();
    void FenceAllLights();
    void ClearLights(NiTriBasedGeom*);
    void SetLightListChanged(bool);
    void __local_vftable_ctor_closure();
    char m_kShadowSceneLights[12];
    float m_fForcedDarkness;
    unsigned int m_uiLightCount;
    bool m_bHasForcedDarkness;
    char _pad_7d[3];
    void* m_pLightData;
};
typedef char _sizecheck_BSShaderLightingProperty[sizeof(BSShaderLightingProperty) == 132 ? 1 : -1];
struct BSShaderPPLightingProperty : public BSShaderLightingProperty
{
    virtual void __vslot_0();
    virtual void CopyTo(BSShaderPPLightingProperty*);
    virtual void CopyToMembers(BSShaderPPLightingProperty*);
    virtual NiAdditionalGeometryData* CreateRendererSpecificProperty(NiGeometry*);
    virtual int GetClampD3D();
    virtual void SetClampD3D(int);
    virtual int GetClampNI();
    virtual void SetClampNI(int);
    virtual unsigned short GetTextureCount();
    virtual unsigned short QLandscapeTextureCount();
    virtual void SetTexture(int, unsigned int, NiTexture*);
    virtual NiTexture* GetTexture(int, unsigned int);
    virtual void SetRectangleBounds(BSShaderTextureSet*);
    virtual void SetDiffuseTexture(unsigned int, NiTexture*);
    virtual void SetNormalTexture(unsigned int, NiTexture*);
    virtual void SetSpecularTexture(unsigned int, NiTexture*);
    virtual void SetGlowTexture(unsigned int, NiTexture*);
    virtual void SetFlagsFromTextures();
    virtual float GetSpecularLODFade();
    virtual float GetEnvMapLODFade();
    virtual void GetRenderPasses_1x(NiGeometry*, int, unsigned short*, unsigned int, BSShaderAccumulator*, bool);
    virtual void GetRenderPasses_2x(NiGeometry*, int, unsigned short*, unsigned int, BSShaderAccumulator*, bool);
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSShaderPPLightingProperty*, CloningProcess*);
    virtual void GetViewerStrings(void*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    virtual void PostLinkObject(NiStream*);
    virtual bool SetupGeometry(NiGeometry*);
    virtual void* CreateRenderPasses(NiGeometry*, int, unsigned short*, unsigned int, BSShaderAccumulator*, bool);
    virtual unsigned short GetNumberofPasses(NiGeometry*);
    virtual void* GetRenderDepthPass(NiGeometry*);
    virtual NiTexture* GetBaseTexture();
    NiTexture* GetDiffuseTextureIndex(unsigned int);
    NiTexture* GetNormalMapTexture(unsigned int);
    NiTexture* GetSpecularTexture(unsigned int);
    NiTexture* GetGlowTexture(unsigned int);
    void* GetExtraDataPointers();
    NiPoint3* GetTangentExtraData();
    NiPoint3* GetBinormalExtraData();
    void StoreExtraDataPointers(void*);
    void StoreTextureSplatVertexDataPointers(float*);
    static bool GetForceNoProjectedShadowTexture();
    static void SetForceNoProjectedShadowTexture(bool);
    void SetLandscapeSpecularExponents(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char,
                                       unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
    void SetForLandscapeTextures();
    void SetLandscapeTextureSet(unsigned int, BSTextureSet*);
    NiTexture* GetLandscapeTexture(unsigned short);
    bool GetTextureSpecular(int);
    float GetTextureSpecularExponent(int);
    void SetTextureEffectData(void*);
    void* GetTextureEffectData();
    static void UpdateRefractionRecurse(NiAVObject*, bool, float, bool, float, bool);
    static bool HasRefractionRecurse(NiAVObject*);
    float GetRefractionPower();
    void SetRefractionPower(float);
    int GetRefractionFirePeriod();
    void SetRefractionFirePeriod(int);
    float GetParallaxOccMaxPasses();
    void SetParallaxOccMaxPasses(float);
    float GetParallaxOccScale();
    void SetParallaxOccScale(float);
    bool QRemappableTextures();
    void SetTextureSet(BSTextureSet*);
    void CopyTextureSet(BSTextureSet*);
    void LoadTextureSet(char*, BSTextureSet*);
    void EnsureNormalMap();
    virtual BSShaderProperty* ClarifyShader(NiGeometry*, bool, bool);
    virtual void* GetWaterFogPassList(NiGeometry*);
    virtual void GetTextureUse(int*, void*);
    float GetTerrainTexOffsetX();
    float GetTerrainTexOffsetY();
    float GetTerrainTexFade();
    float GetTerrainDetailTexScale();
    void SetTerrainTexParams(float, float, float);
    void SetTerrainDetailTexScale(float);
    virtual void PrecacheTextures();
    void* AddZOnlyPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool, bool);
    void* AddZOnlyTextureEffectPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void AddConstAlphaPass_1x(NiGeometry*, bool, bool);
    void* AddAmbientPass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool);
    void* AddAmbDiffTexPass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool,
                               bool, bool, bool);
    void* AddAmbDiffDirAndPtPass_1x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*,
                                    bool, bool);
    void* AddDiffusePass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool);
    void* AddAmbientDiffuseTexturePass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool,
                                          bool, bool, bool, bool);
    void* AddSpecularPass_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool, bool,
                             bool);
    void* AddEnvmapPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool, bool);
    void* AddFogPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool, bool, bool);
    void AddLandscapePasses_1x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool);
    void* AddTextureEffectPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void* AddTextureEffectPass_2x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void* AddRenderNormalsPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool, bool);
    void* AddRenderNormalsClearPass_1x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void* AddVelocityPass_2x(NiGeometry*, unsigned short*, bool, bool*, bool);
    void* AddSelfIllumAlphaPass(NiGeometry*, unsigned short*, bool, bool, bool);
    void* AddSelfIllumAlphaBlockPass(NiGeometry*, unsigned short*, bool, bool);
    void* AddAmbDiff2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool,
                             bool, bool, bool, bool, bool, bool);
    void* AddAmbDiff3Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*,
                             bool, bool*, bool, bool, bool, bool, bool, bool, bool);
    void* AddAmbDiffTexPass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool,
                               bool, bool, bool, bool, bool, bool, bool);
    void* AddAmbDiffTex2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool,
                                bool, bool, bool, bool, bool, bool, bool);
    void* AddAmbDiffTexSpecularPass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool,
                                       bool, bool, bool, bool, bool);
    void* AddAmbDiffTexSpecular2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*,
                                        bool, bool, bool, bool, bool, bool, bool, bool);
    void* AddAmbDiffTexSpecular10Pass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool,
                                         bool, bool);
    void* AddDiffusePt2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool,
                               bool, bool, bool, bool);
    void* AddDiffusePt3Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*,
                               bool, bool*, bool, bool, bool, bool, bool);
    void* AddTexturePass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool, bool,
                            bool, bool, bool);
    void* AddSpecularPass_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool, bool,
                             bool);
    void* AddSpecularPt2Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool,
                                bool, bool, bool);
    void* AddSpecularPt3Pass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*,
                                bool, bool*, bool, bool, bool, bool);
    void* AddEnvmapPass_2x(NiGeometry*, ShadowSceneLight*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool,
                           bool);
    void AddLandscapePasses_2x(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool);
    void AddDepthMapPass_2x(NiGeometry*, bool, bool, BSShaderAccumulator*);
    void AddLocalMapPass_2x(NiGeometry*, bool, bool);
    void AddSilhouettePass_2x(NiGeometry*, bool);
    void __local_vftable_ctor_closure();
    float m_fEmissiveMultiple;
    float m_fSpecularScale;
    char m_kEmissiveColor[16];
    char m_kSpecularColor[16];
    char m_spTextureSet[4];
    unsigned short m_usTextureFlags;
    char _pad_b2[2];
    char m_ppTextureSlots[28];
    unsigned char* m_pTextureFlags;
    unsigned short m_usTextureIndex;
    char _pad_d6[2];
    bool* m_pbTextureHasAlpha;
    char m_spTangentSpaceData[4];
    float* m_pfTextureSpecularExponents;
    int m_eClampMode;
    char spTexEffectData[4];
    float m_fValueBeforeTextureCount;
    int m_iTextureCount;
    float m_fFirstFloatAfterTextureCount;
    float m_fSecondFloatAfterTextureCount;
    float m_fThirdFloatAfterTextureCount;
    float m_fFourthFloatAfterTextureCount;
    float m_fFifthFloatAfterTextureCount;
    float m_fSixthFloatAfterTextureCount;
    void* m_pRenderPassEntry;
};
typedef char _sizecheck_BSShaderPPLightingProperty[sizeof(BSShaderPPLightingProperty) == 272 ? 1 : -1];

struct NiNode_00558310
{
    NiAVObject* FUN_0045bc00(unsigned int);
};
struct VObj_004b5710
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual NiNode* IsSceneNode();
};
int __cdecl FUN_00438220();
BSShaderPPLightingProperty* __cdecl FindAcceptedForm(NiNode*);
// Scans the node's children in reverse for a BSShaderPPLightingProperty, returning it if found, otherwise falling back to FindAcceptedForm.
// @fnv 0x004b5710
BSShaderPPLightingProperty* __cdecl FindPPLightingProperty(NiNode* apNode)
{
    if (!apNode->FUN_0043b480())
        return 0;
    unsigned int n = apNode->FUN_0043b480() - 1;
    while (true)
    {
        NiAVObject* pobj = apNode->GetAt(n);
        if (pobj)
        {
            NiNode* pnode = ((VObj_004b5710*)pobj)->IsSceneNode();
            if (pnode)
            {
                NiAVObject* pchild = ((NiNode_00558310*)pnode)->FUN_0045bc00(0);
                if (pchild)
                {
                    NiShadeProperty* pproperty = (NiShadeProperty*)pchild->GetProperty(FUN_00438220());
                    if (pproperty)
                    {
                        BSShaderPPLightingProperty* plightingProperty =
                            (BSShaderPPLightingProperty*)((pproperty == 0
                                                               ? 0
                                                               : (((NiTimeController*)pproperty)->FUN_00441110() >= 8 &&
                                                                  ((NiTimeController*)pproperty)->FUN_00441110() <= 12))
                                                              ? pproperty
                                                              : 0);
                        if (plightingProperty)
                            return plightingProperty;
                    }
                }
            }
        }
        if (n == 0)
            break;
        n--;
    }
    return FindAcceptedForm(apNode);
}

extern double _gModifierZero;
extern double DAT_0101ff58;

// @fnv 0x004b15e0
float __cdecl FUN_004b15e0(float startAngle, float targetAngle, float* pfOutDir)
{
    float angleDelta = targetAngle - startAngle;
    *pfOutDir = 0.0f;
    if (angleDelta != _gModifierZero)
    {
        *pfOutDir = 1.0f;
        if (angleDelta < _gModifierZero)
        {
            if (angleDelta > DAT_0101ff58)
                *pfOutDir = -1.0f;
            else
                angleDelta += 6.2831855f;
        }
        else if (angleDelta > (double)3.1415927f)
        {
            *pfOutDir = -1.0f;
            angleDelta = 6.2831855f - angleDelta;
        }
    }
    return angleDelta;
}

struct Model
{
    NiNode* GetObject3D();
};
struct CtlV
{
    CtlV* GetNext();
};
struct FUN_00621b20_Class
{
    void FUN_00621b20(float);
    CtlV* GetNext();
};
extern const NiRTTI DAT_011f4428;
// @fnv 0x004b70f0
void FUN_004b70f0(NiNode* apNode, float afPhase)
{
    if (!apNode)
        return;
    NiTimeController* pcont = (NiTimeController*)((Model*)apNode)->GetObject3D();
    while (pcont)
    {
        ((FUN_00621b20_Class*)pcont)->FUN_00621b20(afPhase);
        pcont = (NiTimeController*)((FUN_00621b20_Class*)pcont)->GetNext();
    }
    unsigned int n = 0;
    for (; n < apNode->FUN_0043b480(); ++n)
    {
        NiAVObject* pobj = apNode->GetAt(n);
        if (pobj && FUN_0043b300(&DAT_011f4428, pobj))
            FUN_004b70f0((NiNode*)pobj, afPhase);
    }
}

struct NiCamera;
struct NiBoundStandIn
{
    float m_afRadius;
    float m_acCenter[3];
    NiBoundStandIn();
};
bool IsBoundVisible(NiBoundStandIn*, NiCamera*);
struct FUN_0098ddd0_shell
{
    void FUN_0098ddd0(NiPoint3&);
};
struct PackageTargetRecord
{
    void SetTargAcquireRadius(float);
};
// @fnv 0x004b61d0
bool FUN_004b61d0(NiPoint3 location, NiCamera* camera, float radius)
{
    if (!camera)
        return false;
    NiBoundStandIn sphere;
    ((FUN_0098ddd0_shell*)&sphere)->FUN_0098ddd0(location);
    ((PackageTargetRecord*)&sphere)->SetTargAcquireRadius(radius);
    return IsBoundVisible(&sphere, camera);
}

extern const char* const g_0120043c_arg1;
struct _UseSaveGameBlocks;
_UseSaveGameBlocks* _UseSaveGameBlocks(const char* const*, void*);
struct PropHelper
{
    void AssignRefObj(unsigned int);
};
void FUN_004b6630(NiAVObject*);
// @fnv 0x004b6630
void FUN_004b6630(NiAVObject* object)
{
    PropHelper* result = (PropHelper*)_UseSaveGameBlocks(&g_0120043c_arg1, object->GetProperty(3));
    if (result)
        result->AssignRefObj(0);
    NiNode* node = object->GetAsNiNode();
    if (node)
    {
        unsigned int i = 0;
        for (; i < node->FUN_0043b480(); ++i)
        {
            if (node->GetAt(i))
                FUN_004b6630(node->GetAt(i));
        }
    }
}

namespace fnv_004b4ea0 {
struct hkpMotion
{
    float GetMassValue(void);
};

typedef hkpMotion BSSimpleList_Ragdoll;

class TESDataHandler
{
  public:
    BSSimpleList_Ragdoll* GetBGSRagdollList(void);
    float getMass();
};

// @fnv 0x004b4ea0
float TESDataHandler::getMass()
{
    return GetBGSRagdollList()->GetMassValue();
}
}  // namespace fnv_004b4ea0

struct FUN_004b5020_shell
{
    int vftable;
    void _ref_006815c0();
    FUN_004b5020_shell* FUN_004b5020();
};

// @fnv 0x004b5020
FUN_004b5020_shell* FUN_004b5020_shell::FUN_004b5020()
{
    _ref_006815c0();
    vftable = 0;
    return this;
}

namespace fnv_004b68a0 {
int __cdecl FUN_00408b20(char const*, char const*);

extern void const* const DAT_011f9140;
extern NiRTTI g_0126817c;

struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_004b68a0_data
{
    void* field_00;
    void* field_04;
    void* field_08;
    int field_0c;
    ArrSI* field_10;
    int field_14;
    unsigned int field_18;
};

// Checks RTTI and fade-node conditions on object, resets field_14 when object matches field_10, then increments field_0c.
// @fnv 0x004b68a0
void FUN_004b68a0(ArrSI* object, FUN_004b68a0_data* data)
{
    if ((data->field_18 & 1) && FUN_0043b300(&g_0126817c, reinterpret_cast<NiAVObject*>(object)))
        return;

    if ((data->field_18 & 2) &&
        FUN_0043b300(reinterpret_cast<const NiRTTI*>(&DAT_011f9140), reinterpret_cast<NiAVObject*>(object->GetFlags())))
        return;

    if ((data->field_18 & 2) && object->GetFlags() &&
        reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(object->GetFlags())->GetLinkToList())
            ->FUN_0043b1b0())
    {
        if (!FUN_00408b20(reinterpret_cast<char const*>(
                              reinterpret_cast<BSFadeNode*>(
                                  reinterpret_cast<TESTopicInfoData*>(object->GetFlags())->GetLinkToList())
                                  ->FUN_0043b1b0()),
                          "Arrow"))
            return;
    }

    if (object == data->field_10)
        data->field_14 = data->field_0c;

    data->field_0c++;
}
}  // namespace fnv_004b68a0

struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_004b6a00_data
{
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
    NiAVObject* field_10;
    int field_14;
    unsigned int field_18;
};

extern NiRTTI DAT_011f9140;
extern NiRTTI g_0126817c;
extern const char $SG20273[];

int __cdecl FUN_00408b20(char const*, char const*);

// Checks object against data flags and RTTI, stores it in field_10 when field_0c equals field_14, then increments field_0c.
// @fnv 0x004b6a00
void __cdecl ProcessObjectMatch(NiAVObject* object, FUN_004b6a00_data* data)
{
    if (data->field_18 & 1)
    {
        if (FUN_0043b300(&g_0126817c, object))
            return;
    }

    if (data->field_18 & 2)
    {
        if (FUN_0043b300(&DAT_011f9140, reinterpret_cast<NiAVObject*>(reinterpret_cast<ArrSI*>(object)->GetFlags())))
            return;
    }

    if (data->field_18 & 2)
    {
        if (reinterpret_cast<ArrSI*>(object)->GetFlags())
        {
            if (reinterpret_cast<BSFadeNode*>(
                    reinterpret_cast<TESTopicInfoData*>(reinterpret_cast<ArrSI*>(object)->GetFlags())
                        ->GetLinkToList())
                    ->FUN_0043b1b0())
            {
                if (!FUN_00408b20(static_cast<char const*>(
                                      reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(
                                                                        reinterpret_cast<ArrSI*>(object)->GetFlags())
                                                                        ->GetLinkToList())
                                          ->FUN_0043b1b0()),
                                  $SG20273))
                    return;
            }
        }
    }

    if (data->field_0c == data->field_14)
        data->field_10 = object;

    data->field_0c++;
}

namespace fnv_004b6e90 {
class NiObject
{
};

struct A51BF0Base : NiObject
{
    static void* __cdecl operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
};

struct BSShaderLightingProperty : A51BF0Base
{
    unsigned char m_data[128];
    BSShaderLightingProperty();
};

struct NiAVObject_Attach
{
    void AttachProperty(NiObject* property);
};

void AttachLightingPropertyRecursive(NiAVObject* object);

// Recursively attaches a new BSShaderLightingProperty to geometry objects lacking property 3, descending through NiNode children.
// @fnv 0x004b6e90
void AttachLightingPropertyRecursive(NiAVObject* object)
{
    if (object->GetAsNiGeometry() && !object->GetProperty(3))
    {
        BSShaderLightingProperty* lightingProperty = new BSShaderLightingProperty();
        ((NiAVObject_Attach*)object)->AttachProperty(lightingProperty);
    }

    NiNode* node = object->GetAsNiNode();
    if (node)
    {
        for (unsigned int index = 0; index < node->FUN_0043b480(); ++index)
        {
            NiAVObject* child = node->GetAt(index);
            if (child)
                AttachLightingPropertyRecursive(child);
        }
    }
}
}  // namespace fnv_004b6e90

struct NiAVObject_004b5b00
{
    char unk00[0x34];
    void* m_pExtraDataArray;

    void* GetExtraDataAt(unsigned short index);
};

// @fnv 0x004b5b00
void* NiAVObject_004b5b00::GetExtraDataAt(unsigned short index)
{
    return reinterpret_cast<char*>(m_pExtraDataArray) + index * 0x30;
}

class NiRTTI;
extern NiRTTI DAT_011f36ac;

struct FixedStr6220
{
    char* m_kHandle;
    operator const char*() const;
};

class NiObj6220;
class NiObj6220
{
  public:
    NiObj6220* GetControllers() const;
};
NiObj6220* NiDynamicCast(const NiRTTI*, NiObj6220*);

struct AnimEntry6220
{
    int unk00;
    int unk04;
    FixedStr6220* GetName();
    float GetValue();
};
struct AnimData6220
{
    AnimEntry6220* GetEntries(unsigned int* count);
};
struct Seq6220
{
    AnimData6220* GetData();
};
struct Mgr6220
{
    Seq6220* GetControllerSequence(const NiFixedString& name);
};

template <class T> unsigned int BSStringLength(const T*);
extern "C" int _strnicmp(const char*, const char*, unsigned int);

// Looks up the named sequence on obj's controller manager and returns the value of the first entry whose name starts with prefix, else 0.
// @fnv 0x004b6220
float GetAnimValueByPrefix(NiObj6220* obj, const char* name, const char* prefix)
{
    if (!obj)
        return 0.0f;
    Mgr6220* mgr = (Mgr6220*)NiDynamicCast(&DAT_011f36ac, obj->GetControllers());
    if (mgr)
    {
        Seq6220* seq3 = mgr->GetControllerSequence(NiFixedString(name));
        if (seq3)
        {
            AnimData6220* data8 = seq3->GetData();
            unsigned int aCount;
            AnimEntry6220* entries3 = data8->GetEntries(&aCount);
            unsigned int len = BSStringLength(prefix);
            if (len > 0)
            {
                for (unsigned int i4 = 0; i4 < aCount; i4++)
                {
                    const char* s4 = *entries3[i4].GetName();
                    if (s4 && !_strnicmp(s4, prefix, len))
                        return entries3[i4].GetValue();
                }
            }
        }
    }
    return 0.0f;
}

struct S_004b6810_Filter
{
    int m_00;
    bool m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
};

typedef int(__cdecl* PFN_004b68a0)(S_004b6810_Filter*);
int __cdecl FUN_004b68a0(S_004b6810_Filter*);
int __cdecl FUN_00c68900(void*, S_004b6810_Filter*, PFN_004b68a0);

// Builds a filter struct from the flags and a2, runs FUN_00c68900 over a1, and returns the filter's m_14 result or -1.
// @fnv 0x004b6810
int __cdecl FilterByFlags(void* a1, int iValue, bool abSkipPhantoms, bool abSkipBlend, bool abSkipUnknown)
{
    S_004b6810_Filter kFilter;
    kFilter.m_08 = 0x12;
    kFilter.m_04 = true;
    kFilter.m_0c = 0;
    kFilter.m_10 = iValue;
    kFilter.m_14 = -1;
    kFilter.m_18 = 0;
    if (abSkipPhantoms)
        kFilter.m_18 |= 1;
    if (abSkipBlend)
        kFilter.m_18 |= 2;
    if (abSkipUnknown)
        kFilter.m_18 |= 4;
    FUN_00c68900(a1, &kFilter, FUN_004b68a0);
    return (kFilter.m_14 != -1) ? kFilter.m_14 : -1;
}

void __cdecl ProcessObjectMatch(NiCollisionObject*, CollisionObjectCountContext*);

struct FUN_004b6980_Context
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    void* pUserData;
    int iCount;
    void* pAuxiliaryData;
    unsigned int uiFilterFlags;
};

// Builds a traversal context from the three flags, runs FUN_00c68900 over object with ProcessObjectMatch, and returns the accumulated count.
// @fnv 0x004b6980
int __cdecl FUN_004b6980(NiAVObject* object, void* auxiliaryData, bool flag1, bool flag2, bool flag3)
{
    FUN_004b6980_Context context;

    context.uiTraversalFlags = 0x12;
    context.bRecurse = true;
    context.pUserData = 0;
    context.iCount = 0;
    context.pAuxiliaryData = auxiliaryData;
    context.uiFilterFlags = 0;

    if (flag1)
    {
        context.uiFilterFlags |= 1;
    }
    if (flag2)
    {
        context.uiFilterFlags |= 2;
    }
    if (flag3)
    {
        context.uiFilterFlags |= 4;
    }

    FUN_00c68900(object, reinterpret_cast<CollisionObjectCountContext*>(&context), ProcessObjectMatch);

    return context.iCount;
}

void FUN_004b6bc0(NiCollisionObject* pkObject, CollisionObjectCountContext* pkContext);

// Traverses pkRoot with a context that counts collision objects and returns the auxiliary result, or -1 when it is unset.
// @fnv 0x004b6b60
int FUN_004b6b60(NiAVObject* pkRoot, void* pvUserData)
{
    CollisionObjectCountContext kContext;
    kContext.uiTraversalFlags = 0x12;
    kContext.bRecurse = true;
    kContext.iCount = 0;
    kContext.pUserData = pvUserData;
    kContext.pAuxiliaryData = reinterpret_cast<void*>(-1);
    FUN_00c68900(pkRoot, &kContext, FUN_004b6bc0);
    return reinterpret_cast<int>(kContext.pAuxiliaryData) != -1 ? reinterpret_cast<int>(kContext.pAuxiliaryData) : -1;
}

class FUN_004b6ce0_cls
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual FUN_004b6ce0_cls* vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void* vfn_1c();
    FUN_004b6ce0_cls* FUN_00a59d30(int);
    int FUN_00441110();
    unsigned int FUN_0043b480();
    FUN_004b6ce0_cls* FUN_0043b4a0(unsigned int);
};

class FUN_004b6ce0_gl
{
  public:
    void FUN_004534f0(void*);
};
extern FUN_004b6ce0_gl DAT_011e0e80;
int FUN_004a2c20(void*);

// @fnv 0x004b6ce0
void FUN_004b6ce0(FUN_004b6ce0_cls* p)
{
    FUN_004b6ce0_cls* RunFourthVirtual;
    FUN_004b6ce0_cls* x8;
    void* y;
    bool flag4;
    FUN_004b6ce0_cls* c;
    unsigned int i2;

    if (p == 0)
        return;
    if (p->vfn_1c() != 0)
    {
        x8 = p;
        RunFourthVirtual = x8->FUN_00a59d30(3);
        if (RunFourthVirtual != 0)
        {
            y = FUN_004a2c20(RunFourthVirtual) ? RunFourthVirtual : 0;
            if (y != 0)
            {
                flag4 = false;
                if (RunFourthVirtual->FUN_00441110() == 3)
                    flag4 = true;
                DAT_011e0e80.FUN_004534f0(y);
                if (flag4)
                    return;
            }
        }
    }
    else
    {
        c = p->vfn_c();
        if (c != 0)
        {
            for (i2 = 0; i2 < c->FUN_0043b480(); i2++)
                FUN_004b6ce0(c->FUN_0043b4a0(i2));
        }
    }
}

struct LightingProp80
{
    LightingProp80();
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void SetShaderFlag(unsigned int, bool);
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
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
};

struct AVObjectEx : public NiAVObject
{
    void AttachProperty(void*);
    void UpdatePropertyState();
};

void __cdecl FUN_00b57e30(NiAVObject*, int, int);

// Adds a LightingProp80 with shader flag 0x30 to a geometry lacking property 3, or recurses into a visual node's children.
// @fnv 0x004b6f90
void __cdecl EnsureLightingProperty(AVObjectEx* apObject)
{
    if (apObject->GetAsNiGeometry() && !apObject->GetProperty(3))
    {
        LightingProp80* pProp = new LightingProp80;
        pProp->SetShaderFlag(0x30, true);
        apObject->AttachProperty(pProp);
        apObject->UpdatePropertyState();
        FUN_00b57e30(apObject, 0, 0);
    }
    else
    {
        NiNode* pNode = apObject->GetAsNiNode();
        if (pNode && pNode->IsVisualObject())
        {
            for (unsigned int i = 0; i < pNode->FUN_0043b480(); i++)
            {
                NiAVObject* pChild = pNode->GetAt(i);
                if (pChild)
                    EnsureLightingProperty((AVObjectEx*)pChild);
            }
        }
    }
}

// Deletes each of the global objects pointed to by DAT_011c61a4 through DAT_011c6278.
// @fnv 0x004b8cf0
void __cdecl FUN_004b8cf0()
{
    delete DAT_011c61a4;
    delete DAT_011c61a8;
    delete DAT_011c61ac;
    delete DAT_011c61b0;
    delete DAT_011c61bc;
    delete DAT_011c61c0;
    delete DAT_011c61c4;
    delete DAT_011c61c8;
    delete DAT_011c61cc;
    delete DAT_011c61d0;
    delete DAT_011c61d4;
    delete DAT_011c61d8;
    delete DAT_011c61dc;
    delete DAT_011c61e0;
    delete DAT_011c61e4;
    delete DAT_011c61e8;
    delete DAT_011c61ec;
    delete DAT_011c61f0;
    delete DAT_011c61f4;
    delete DAT_011c61f8;
    delete DAT_011c61fc;
    delete DAT_011c6200;
    delete DAT_011c6204;
    delete DAT_011c6208;
    delete DAT_011c620c;
    delete DAT_011c6210;
    delete DAT_011c6214;
    delete DAT_011c6218;
    delete DAT_011c621c;
    delete DAT_011c6220;
    delete DAT_011c6224;
    delete DAT_011c6228;
    delete DAT_011c622c;
    delete DAT_011c6230;
    delete DAT_011c6234;
    delete DAT_011c6238;
    delete DAT_011c623c;
    delete DAT_011c6240;
    delete DAT_011c6244;
    delete DAT_011c6248;
    delete DAT_011c624c;
    delete DAT_011c6250;
    delete DAT_011c6254;
    delete DAT_011c6258;
    delete DAT_011c625c;
    delete DAT_011c6260;
    delete DAT_011c6264;
    delete DAT_011c6268;
    delete DAT_011c626c;
    delete DAT_011c6270;
    delete DAT_011c6274;
    delete DAT_011c6278;
}

// Maps an input byte to a fixed index via a switch, returning -1 for unmapped values.
// @fnv 0x004b1680
int MapByteToIndex(unsigned char a)
{
    switch (a)
    {
    case 21:
        return 0;
    case 24:
        return 1;
    case 25:
        return 2;
    case 27:
        return 3;
    case 28:
        return 4;
    case 29:
        return 5;
    case 30:
        return 6;
    case 31:
        return 7;
    case 50:
        return 66;
    case 46:
        return 20;
    case 32:
        return 8;
    case 33:
        return 72;
    case 34:
        return 43;
    case 35:
        return 45;
    case 36:
        return 9;
    case 37:
        return 10;
    case 40:
        return 11;
    case 41:
        return 21;
    case 42:
        return 12;
    case 43:
        return 13;
    case 44:
        return 14;
    case 45:
        return 15;
    case 20:
        return 16;
    case 19:
        return 17;
    case 47:
        return 18;
    case 52:
        return 19;
    case 18:
        return 25;
    case 91:
        return 46;
    case 13:
        return 24;
    case 39:
        return 23;
    case 38:
        return 22;
    case 74:
        return 26;
    case 75:
        return 27;
    case 76:
        return 28;
    case 77:
        return 29;
    case 78:
        return 30;
    case 48:
        return 31;
    case 79:
        return 32;
    case 51:
        return 33;
    case 81:
        return 35;
    case 22:
        return 34;
    case 23:
        return 44;
    case 4:
        return 36;
    case 82:
        return 37;
    case 5:
        return 38;
    case 85:
        return 39;
    case 86:
        return 40;
    case 87:
        return 41;
    case 97:
        return 64;
    case 88:
        return 42;
    case 94:
        return 47;
    case 95:
        return 48;
    case 71:
        return 49;
    case 73:
        return 50;
    case 93:
        return 51;
    case 7:
        return 52;
    case 12:
        return 53;
    case 11:
        return 54;
    case 9:
        return 55;
    case 8:
        return 56;
    case 49:
        return 57;
    case 53:
        return 58;
    case 54:
        return 59;
    case 14:
        return 67;
    case 102:
        return 71;
    case 16:
        return 70;
    case 103:
        return 73;
    case 104:
        return 74;
    case 106:
        return 75;
    case 107:
        return 76;
    case 114:
        return 83;
    case 108:
        return 77;
    case 109:
        return 78;
    case 110:
        return 79;
    case 111:
        return 80;
    case 112:
        return 81;
    case 113:
        return 82;
    case 115:
        return 84;
    case 116:
        return 85;
    case 117:
        return 86;
    default:
        return -1;
    }
}

struct FormName
{
    const char* name;
    int unk04;
    int unk08;
};
extern FormName FNV_FormTypeNames[];
extern const char* typeNames[];
int __cdecl LookupType(unsigned char);
void __cdecl Warn(const char*, ...);
extern const char* DAT_01188f98;
extern const char* DAT_01188f9c;
extern const char* DAT_01188fa0;
extern const char* DAT_01188fa4;
extern const char* DAT_01188fa8;
extern const char* DAT_01188fac;
extern const char* DAT_01188fb0;
extern const char* DAT_01188fb4;
extern const char* DAT_01188fb8;
extern const char* DAT_01188fbc;
extern const char* DAT_01188fc0;
extern const char* DAT_01188fc4;
extern const char* DAT_01188fc8;
extern const char* DAT_01188fcc;
extern const char* DAT_01188fd0;
extern const char* DAT_01188fd4;
extern const char* DAT_01188fd8;
extern const char* DAT_01188fdc;
extern const char* DAT_01188fe0;
extern const char* DAT_01188fe4;
extern const char* DAT_01188fe8;
extern const char* DAT_01188fec;
extern const char* DAT_01188ff0;
extern const char* DAT_01188ff4;
extern const char* DAT_01188ff8;
extern const char* DAT_01188ffc;
extern const char* DAT_01189000;
extern const char* DAT_01189004;
extern const char* DAT_01189008;
extern const char* DAT_0118900c;
extern const char* DAT_01189010;
extern const char* DAT_01189014;
extern const char* DAT_01189018;
extern const char* DAT_0118901c;
extern const char* DAT_01189020;
extern const char* DAT_01189024;
extern const char* DAT_01189028;
extern const char* DAT_0118902c;
extern const char* DAT_01189030;
extern const char* DAT_01189034;

// Returns the type name string for a form type code, looking it up in typeNames, then a switch table, then FNV_FormTypeNames, warning on invalid codes.
// @fnv 0x004b1b60
const char* __cdecl GetFormTypeName(unsigned char type)
{
    int index = LookupType(type);
    if (index >= 0)
        return typeNames[index];
    switch (type)
    {
    case 12:
        return DAT_01188f98;
    case 7:
        return DAT_01188f9c;
    case 17:
        return DAT_01188fa0;
    case 69:
        return DAT_01188fa4;
    case 57:
        return DAT_01188fa8;
    case 8:
        return DAT_01188fac;
    case 13:
        return DAT_01188fb0;
    case 6:
        return DAT_01188fb4;
    case 55:
        return DAT_01188fb8;
    case 3:
        return DAT_01188fbc;
    case 16:
        return DAT_01188fc0;
    case 65:
        return DAT_01188fc4;
    case 54:
        return DAT_01188fc8;
    case 53:
        return DAT_01188fcc;
    case 15:
        return DAT_01188fd0;
    case 71:
        return DAT_01188fd4;
    case 9:
        return DAT_01188fd8;
    case 10:
        return DAT_01188fdc;
    case 11:
        return DAT_01188fe0;
    case 58:
        return DAT_01188fe4;
    case 72:
        return DAT_01188fe8;
    case 73:
        return DAT_01188fec;
    case 49:
        return DAT_01188ff0;
    case 83:
        return DAT_01188ff4;
    case 84:
        return DAT_01188ff8;
    case 14:
        return DAT_01188ffc;
    case 102:
        return DAT_01189000;
    case 104:
        return DAT_01189004;
    case 106:
        return DAT_01189008;
    case 107:
        return DAT_0118900c;
    case 108:
        return DAT_01189010;
    case 109:
        return DAT_01189014;
    case 110:
        return DAT_01189018;
    case 111:
        return DAT_0118901c;
    case 112:
        return DAT_01189020;
    case 113:
        return DAT_01189024;
    case 114:
        return DAT_01189028;
    case 115:
        return DAT_0118902c;
    case 116:
        return DAT_01189030;
    case 117:
        return DAT_01189034;
    default:
        if (type >= 121)
        {
            Warn("FORMS: Invalid FormID sent to FormIDToString().\r\n", FNV_FormTypeNames[type].name);
            type = 0;
        }
        return FNV_FormTypeNames[type].name;
    }
}

namespace stand {
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
};
}
struct RgbaColor
{
    float r, g, b, a;
    RgbaColor();
};
struct NiLines : NiAVObject
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    NiLines(unsigned short, stand::NiPoint3*, RgbaColor*, void*, void*, void*, bool*);
    void AttachProperty(LightingProp80*);
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
};
// Builds a 4-vertex square NiLines from four corner points at +/-extent, fills all vertex colors with color, and optionally attaches a LightingProp80.
// @fnv 0x004b3b90
NiLines* __cdecl CreateSquareLines(float extent, const RgbaColor& color, bool addLighting)
{
    stand::NiPoint3* pVertices = new stand::NiPoint3[4];
    RgbaColor* pColors = new RgbaColor[4];
    bool* pEnabled = new bool[4];
    pVertices[0] = stand::NiPoint3(-extent, -extent, 0.0f);
    pVertices[1] = stand::NiPoint3(-extent, extent, 0.0f);
    pVertices[2] = stand::NiPoint3(extent, extent, 0.0f);
    pVertices[3] = stand::NiPoint3(extent, -extent, 0.0f);
    for (int i = 0; i < 4; ++i)
    {
        pColors[i] = color;
        pEnabled[i] = true;
    }
    NiLines* lines = new NiLines(4, pVertices, pColors, 0, 0, 0, pEnabled);
    if (addLighting)
    {
        LightingProp80* property = new LightingProp80;
        lines->AttachProperty(property);
        FUN_00b57e30((NiAVObject*)lines, 0, 0);
    }
    return lines;
}

struct AuxPoint
{
    float x, y;
    AuxPoint();
};
struct Point
{
    float x, y, z;
    Point();
    Point operator-(const Point&) const;
    float Length() const;
    void FUN_004a0c10();
    Point& operator+=(const Point&);
};
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Matrix();
    Matrix FUN_004b45b0() const;
    Matrix operator*(const Matrix&) const;
    Point FUN_004b4500(const Point*);
};
struct Transform : Matrix
{
    Point translation;
    float scale;
    Transform();
    Transform& Relative(Transform&, const Transform&);
    void FUN_004b4880(Transform&);
};
struct GeometryData
{
    void FUN_00a67090(unsigned int);
};
struct Geometry
{
    Point* FUN_0049ec60();
    Point* FUN_004a8030();
    unsigned short FUN_00456650();
    Transform& FUN_00461130();
    GeometryData* FUN_005495f0();
};
struct Entry
{
    unsigned int first, second;
    float bestDistance10;
};
struct PairMap
{
    int unk00, unk04, unk08, unk0c;
    PairMap(int);
    ~PairMap();
    bool FUN_004b9b20(unsigned int, Entry&);
    void SetOrInsert(unsigned int, Entry);
    void* FUN_004b9ba0();
    void GetNextEntry(void*&, unsigned int&, Entry&);
};
Point* CreateElementArray(Geometry*);
bool FUN_0040eb10(float, float, float);
Point FUN_004a3760(float, const Point&);
extern Geometry* DAT_011c6320;
void __cdecl operator delete(void*);
// @fnv 0x004b3e60
bool __cdecl MatchGeometryVertices(Geometry* source, Geometry* target, float threshold, float unused, bool adjust)
{
    PairMap map30(37);
    Matrix rotation4;
    Transform aTransform;
    AuxPoint point12;
    bool bChangedB = false;
    if (!source || !target || source == target)
        return false;
    Point* sourceVertices7 = source->FUN_0049ec60();
    Point* sourceNormals2 = source->FUN_004a8030();
    unsigned int uiCountX = source->FUN_00456650();
    if (!sourceVertices7 || !sourceNormals2 || !uiCountX)
        return false;
    Point* targetVertices5 = target->FUN_0049ec60();
    Point* targetNormals2 = target->FUN_004a8030();
    unsigned int uiCountVal = target->FUN_00456650();
    if (!targetVertices5 || !targetNormals2 || !uiCountVal)
        return false;
    Point* sourcePositions = CreateElementArray(source);
    if (!sourcePositions)
        return false;
    Point* targetVertices = CreateElementArray(target);
    if (!targetVertices)
    {
        delete sourcePositions;
        return false;
    }
    target->FUN_00461130().FUN_004b4880(aTransform);
    rotation4 = target->FUN_00461130().FUN_004b45b0() * source->FUN_00461130();
    unsigned int best4;
    float bestDist3;
    float bestDistance10;
    float minimumVal = 3.402823466e+38F;
    for (unsigned int outer = 0; outer < uiCountVal; outer++)
    {
        best4 = uiCountX;
        bestDist3 = threshold >= 0.0 ? threshold : 3.402823466e+38F;
        for (unsigned int inner = 0; inner < uiCountX; inner++)
        {
            bestDistance10 = (targetVertices[outer] - sourcePositions[inner]).Length();
            if (bestDistance10 < bestDist3)
            {
                best4 = inner;
                bestDist3 = bestDistance10;
            }
            if (bestDistance10 < minimumVal)
                minimumVal = bestDistance10;
        }
        if (best4 < uiCountX)
        {
            Entry entry20;
            entry20.first = outer;
            entry20.second = uiCountVal;
            entry20.bestDistance10 = bestDist3;
            Entry existing;
            if (map30.FUN_004b9b20(best4, existing))
            {
                if (FUN_0040eb10(entry20.bestDistance10, existing.bestDistance10, 0.001F))
                {
                    entry20.second = existing.first;
                    map30.SetOrInsert(best4, entry20);
                }
                else if (entry20.bestDistance10 < existing.bestDistance10)
                    map30.SetOrInsert(best4, entry20);
            }
            else
                map30.SetOrInsert(best4, entry20);
        }
    }
    {
        void* position = map30.FUN_004b9ba0();
        unsigned int iCount = 0;
        unsigned int aHKey;
        Entry existing;
        while (position)
        {
            iCount++;
            map30.GetNextEntry(position, aHKey, existing);
            targetNormals2[existing.first] = rotation4.FUN_004b4500(&sourceNormals2[aHKey]);
            targetNormals2[existing.first].FUN_004a0c10();
            if (existing.second < uiCountVal)
            {
                targetNormals2[existing.second] = targetNormals2[existing.first];
                iCount++;
            }
            if (adjust)
            {
                if (DAT_011c6320 != source)
                    sourceVertices7[aHKey] += FUN_004a3760(10.0F, sourceNormals2[aHKey]);
                targetVertices5[existing.first] += FUN_004a3760(10.0F, targetNormals2[existing.first]);
                if (existing.second < uiCountVal)
                    targetVertices5[existing.second] = targetVertices5[existing.first];
            }
            bChangedB = true;
        }
    }
    if (bChangedB)
    {
        if (adjust)
            source->FUN_005495f0()->FUN_00a67090(3);
        target->FUN_005495f0()->FUN_00a67090(3);
    }
    if (sourcePositions)
        delete sourcePositions;
    if (targetVertices)
        delete targetVertices;
    DAT_011c6320 = source;
    return bChangedB;
}

struct FUN_004b4ee0_sub
{
    void* __thiscall FUN_006815c0();
    void __thiscall FUN_00436aa0();
};

struct FUN_004b4ee0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_004b4ee0_sub unk10;
    void FUN_004b4ee0();
};

// @fnv 0x004b4ee0
void FUN_004b4ee0_cls::FUN_004b4ee0()
{
    ((FUN_004b4ee0_sub*)unk10.FUN_006815c0())->FUN_00436aa0();
}

struct S4b52f0_List
{
    unsigned int FUN_0043b480();
    void* FUN_0043b4a0(unsigned int index);
};
struct S4b52f0_Obj
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual S4b52f0_List* vfn_0c();
};
struct S4b52f0_Ref
{
    void* FUN_006fa820();
};
S4b52f0_Ref* __cdecl FUN_0043b610(void* obj);

// Recursively picks, among an object's list children and its ref target, the one with the greatest GetMass value; returns 0 for a null object.
// @fnv 0x004b52f0
void* __cdecl FUN_004b52f0(void* object)
{
    void* bestX;
    S4b52f0_List* list6;
    S4b52f0_Ref* ref;
    void* other;
    unsigned int count7;
    unsigned int i4;
    void* child2;
    if (object != 0)
    {
        bestX = 0;
        list6 = ((S4b52f0_Obj*)object)->vfn_0c();
        if (list6 != 0)
        {
            count7 = list6->FUN_0043b480();
            for (i4 = 0; i4 < count7; i4++)
            {
                child2 = FUN_004b52f0(list6->FUN_0043b4a0(i4));
                if (child2 != 0)
                {
                    if (bestX == 0 || GetMass(bestX) < GetMass(child2))
                        bestX = child2;
                }
            }
        }
        ref = FUN_0043b610(object);
        other = ref ? ref->FUN_006fa820() : 0;
        if (bestX != 0 && (other == 0 || GetMass(other) < GetMass(bestX)))
        {
            return bestX;
        }
        else
        {
            return other;
        }
    }
    else
    {
        return 0;
    }
}

class NiCamera;

struct NiPlaneS
{
    float m_kNormalX;
    float m_kNormalY;
    float m_kNormalZ;
    float m_fPlaneConstant;
};

struct NiBoundS
{
    float m_fCenterX;
    float m_fCenterY;
    float m_fCenterZ;
    float m_fBoundRadius;
    int WhichSide(NiPlaneS* m_kFogPlane);
};

struct NiFrustumPlanesS : public NiFrustumPlanes
{
    NiFrustumPlanesS();
    void SetFromCamera(NiCamera* pkCamera);
    NiPlaneS* GetPlaneS(unsigned int uiPlane);
};

struct TimeGlobalS
{
    unsigned int GetFrameCount();
};

extern TimeGlobalS g_timeGlobal;

static NiCamera* s_pkLastCamera;
static unsigned int s_uiLastFrame;

// @fnv 0x004b5ff0
bool __cdecl IsBoundVisible(NiBound* pkBound, NiCamera* pkCamera)
{
    if (!pkCamera)
        return false;

    static NiFrustumPlanesS g_kFrustumPlanes;

    if (s_pkLastCamera != pkCamera || s_uiLastFrame != g_timeGlobal.GetFrameCount())
    {
        g_kFrustumPlanes.SetFromCamera(pkCamera);
        s_uiLastFrame = g_timeGlobal.GetFrameCount();
        s_pkLastCamera = pkCamera;
    }

    for (unsigned int i = 0; i < 6; i++)
    {
        NiPlaneS m_kFogPlane = *g_kFrustumPlanes.GetPlaneS(i);
        if (((NiBoundS*)pkBound)->WhichSide(&m_kFogPlane) == 2)
            return false;
    }
    return true;
}

struct ImageSpaceEffectParam
{
    float x, y, z, w;
    ImageSpaceEffectParam(float, float, float, float);
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class FUN_00b668b0 : public NiMemObject
{
  public:
    FUN_00b668b0();
    unsigned int vtable;
    unsigned int referenceCount;
    unsigned int flags;
    ImageSpaceEffectParam color0;
    ImageSpaceEffectParam color1;
    ImageSpaceEffectParam color2;
    ImageSpaceEffectParam color3;
    ImageSpaceEffectParam color4;
    unsigned int mode0, mode1, mode2, mode3, mode4, mode5;
};
template <> class NiPointer<FUN_00b668b0>
{
  public:
    FUN_00b668b0* m_pObject;
    NiPointer(FUN_00b668b0*);
    ~NiPointer();
    NiPointer& operator=(FUN_00b668b0*);
    operator FUN_00b668b0*() const;
};
struct Property6360
{
    void AssignRefObj(FUN_00b668b0*);
};
Property6360* FUN_00653270(const NiRTTI*, NiProperty*);
extern const NiRTTI DAT_011fa010;
// @fnv 0x004b6360
void FUN_004b6360(NiAVObject* object, const NiPoint3* color, FUN_00b668b0* property)
{
    NiPointer<FUN_00b668b0> shared(property);
    if (!property)
    {
        shared = new FUN_00b668b0;
        property = shared;
        ((FUN_00b668b0*)shared)->color2 = ImageSpaceEffectParam(color->x, color->y, color->z, 0.5f);
        ((FUN_00b668b0*)shared)->color3 = ImageSpaceEffectParam(color->x, color->y, color->z, 0.5f);
        ((FUN_00b668b0*)shared)->color0 = ImageSpaceEffectParam(color->x, color->y, color->z, 0.5f);
        ((FUN_00b668b0*)shared)->color1 = ImageSpaceEffectParam(color->x, color->y, color->z, 0.5f);
        ((FUN_00b668b0*)shared)->mode0 = 9;
        ((FUN_00b668b0*)shared)->mode1 = 10;
        ((FUN_00b668b0*)shared)->mode2 = 1;
        ((FUN_00b668b0*)shared)->mode3 = 4;
    }
    Property6360* material = FUN_00653270(&DAT_011fa010, object->GetProperty(3));
    if (material)
        material->AssignRefObj(shared);
    NiNode* node = object->GetAsNiNode();
    if (node)
    {
        for (unsigned int i = 0; i < node->FUN_0043b480(); ++i)
        {
            if (node->GetAt(i))
                FUN_004b6360(node->GetAt(i), color, property);
        }
    }
}

class FUN_004b50c0
{
  public:
    FUN_004b50c0();
    virtual ~FUN_004b50c0();
    void FUN_00c87260(unsigned int value);
};

class FUN_004b5040 : public FUN_004b50c0
{
  public:
    FUN_004b5040(unsigned int value);
    virtual ~FUN_004b5040();
};

extern int DAT_01268124;

// Calls FUN_00c87260 with value and increments the global counter DAT_01268124.
// @fnv 0x004b5040
FUN_004b5040::FUN_004b5040(unsigned int value)
{
    FUN_00c87260(value);
    ++DAT_01268124;
}
