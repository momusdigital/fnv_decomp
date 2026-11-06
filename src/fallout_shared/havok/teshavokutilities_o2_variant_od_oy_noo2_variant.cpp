
// src/fallout_shared/havok/teshavokutilities_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout_shared/havok/teshavokutilities_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/havok/teshavokutilities_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/havok/teshavokutilities.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout_shared/havok/teshavokutilities.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/teshavokutilities.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
struct Point3
{
    float x, y, z;
    Point3* FUN_006815c0();
    Point3* FUN_00439e90(Point3* out, const Point3* other) const;
    Point3* FUN_00416870(float x, float y, float z);
};
struct Aabb
{
    __m128 minimum, maximum;
    Aabb* FUN_00437c10();
};
struct HavokTransform
{
    __m128 rotation0, rotation1, rotation2, translation;
    HavokTransform* FUN_0056ded0();
};
struct Transform
{
    float rotation[3][3];
    Point3 translation;
    float scale;
    Transform* FUN_00476a80();
    Transform* FUN_004b4880(Transform* out) const;
    Transform* FUN_0062c250(Transform* out, const Transform* other) const;
    Point3* FUN_00524c40(Point3* out, const Point3* point) const;
};
struct Node
{
    const Transform* FUN_00461130() const;
};
struct WorldObject
{
    void GetAabb(Aabb* bounds);
    void GetTransform(HavokTransform* transform);
};
struct CollisionObject
{
    WorldObject* FUN_006fa820();
    Node* FUN_0044ddc0();
};
struct RTTI;
extern RTTI g_012683c8;
extern Point3 DAT_011f426c;
CollisionObject* FUN_004b5260(Node*);
void FUN_00458620(Point3* out, const __m128* havokPoint);
Point3* FUN_004a3760(Point3* out, float scale, const Point3* point);
float FUN_00476b70(float minimum, float maximum);
bool FUN_0043b300(const RTTI*, WorldObject*);
Transform* FUN_00624ad0(Transform* out, const HavokTransform* havok);
// @fnv 0x0062bfb0
Point3* FUN_0062bfb0(Point3* out, Node* node)
{
    Point3 chosen = DAT_011f426c;
    CollisionObject* collision = FUN_004b5260(node);
    if (collision)
    {
        WorldObject* body = collision->FUN_006fa820();
        if (body)
        {
            Aabb bounds;
            bounds.FUN_00437c10();
            body->GetAabb(&bounds);
            Point3 minimum;
            minimum.FUN_006815c0();
            FUN_00458620(&minimum, &bounds.minimum);
            Point3 maximum;
            maximum.FUN_006815c0();
            FUN_00458620(&maximum, &bounds.maximum);
            Point3 lower, upper, minTermA, maxTermA, minTermB, maxTermB;
            FUN_004a3760(&maxTermA, .55f, &maximum)->FUN_00439e90(&upper, FUN_004a3760(&minTermA, .45f, &minimum));
            FUN_004a3760(&maxTermB, .45f, &maximum)->FUN_00439e90(&lower, FUN_004a3760(&minTermB, .55f, &minimum));
            Point3 random;
            chosen = *random.FUN_00416870(FUN_00476b70(lower.x, upper.x), FUN_00476b70(lower.y, upper.y),
                                          FUN_00476b70(lower.z, upper.z));
            if (FUN_0043b300(&g_012683c8, body) || collision->FUN_0044ddc0() != node)
            {
                HavokTransform bodyHavok;
                bodyHavok.FUN_0056ded0();
                body->GetTransform(&bodyHavok);
                Transform bodyWorld;
                bodyWorld.FUN_00476a80();
                FUN_00624ad0(&bodyWorld, &bodyHavok);
                bodyWorld.scale = 1.0f;
                Transform inverse;
                inverse.FUN_00476a80();
                node->FUN_00461130()->FUN_004b4880(&inverse);
                Transform composed;
                Point3 transformed;
                chosen = *inverse.FUN_0062c250(&composed, &bodyWorld)->FUN_00524c40(&transformed, &chosen);
            }
        }
    }
    *out = chosen;
    return out;
}
