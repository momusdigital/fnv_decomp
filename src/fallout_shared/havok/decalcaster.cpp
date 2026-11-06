
// src/fallout_shared/havok/decalcaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/decalcaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct RootContactPoint
{
    char _pad[0x48];
    const char* name;
};
struct NiAVObject
{
    int _d;
};
struct bhkNiCollisionObject
{
    int _d;
};
struct hkpWorldObject
{
    int _d;
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct NiShader
{
    static NiAVObject* __cdecl DynamicCast(NiAVObject*);
};
const void* __fastcall getOwner(const char*);
struct DecalCaster
{
    const RootContactPoint* FUN_006232f0(unsigned int);
    unsigned int GetCollisionFlags(unsigned int);
};
// Looks up the entry at aiIndex, resolves its name to a collision object, casts it to NiAVObject and returns its flags, or 0 if absent.
// @fnv 0x00623290
unsigned int DecalCaster::GetCollisionFlags(unsigned int aiIndex)
{
    unsigned int uiFlags;
    uiFlags = 0;
    {
        const RootContactPoint* pEntry;
        pEntry = FUN_006232f0(aiIndex);
        if (pEntry->name)
        {
            {
                bhkNiCollisionObject* pCollisionObject;
                pCollisionObject = (bhkNiCollisionObject*)getOwner(pEntry->name);
                {
                    NiAVObject* pObject;
                    pObject = NiShader::DynamicCast((NiAVObject*)pCollisionObject);
                    if (pObject)
                        uiFlags = ((ArrSI*)pObject)->GetFlags();
                }
            }
        }
    }
    return uiFlags;
}
