
// src/havok/common/visualize/shape/hkdisplaycapsule.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaycapsule.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct StaticHelper
{
    static void HandleObjectEvent(void* a, void* b, float c, void* d, void* e, void* f, void* g);
};

struct hkDisplayCapsule
{
    void buildGeometry();
};

// @fnv 0x00d22d70
void hkDisplayCapsule::buildGeometry()
{
    StaticHelper::HandleObjectEvent(this + 0x60, this + 0x70, *(float*)((char*)this + 0x80),
                                    *(void**)((char*)this + 0x88), *(void**)((char*)this + 0x84), this + 0x10,
                                    this + 0x8);
}

// @fnv 0x00d22db0
void __stdcall FUN_00d22db0(int, int)
{}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_load_ss(const float*);
    void _mm_store_ss(float*, __m128);
    double sqrt(double);
    void _ReadWriteBarrier();
}
extern float DAT_0104da4c;
extern double DAT_01016978;
struct Vector
{
    union
    {
        __m128 quad;
        struct
        {
            float x, y, z, w;
        };
    };
    Vector()
    {}
    Vector(const Vector& v)
    {
        quad = v.quad;
    }
    void operator=(const Vector& v)
    {
        quad = v.quad;
    }
};
struct Matrix
{
    Vector c0, c1, c2, c3;
};
struct Other
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    Matrix* transform;
};
struct Limit
{
    Vector axis, origin;
    float slope, positive, negative, scale;
};
static __forceinline __m128 dot3(const Vector& a, const Vector& b)
{
    __m128 p = _mm_mul_ps(a.quad, b.quad);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
}
static __forceinline __m128 broadcast(__m128 a)
{
    return _mm_shuffle_ps(a, a, 0);
}
static __forceinline __m128 scalar(float a)
{
    return broadcast(_mm_load_ss(&a));
}
static __forceinline float value(__m128 a)
{
    float r;
    _mm_store_ss(&r, a);
    return r;
}
static __forceinline void crossProduct(Vector& result, const Vector& a, const Vector& b)
{
    __m128 p = _mm_mul_ps(_mm_shuffle_ps(a.quad, a.quad, 0xc9), _mm_shuffle_ps(b.quad, b.quad, 0xd2));
    __m128 q = _mm_mul_ps(_mm_shuffle_ps(a.quad, a.quad, 0xd2), _mm_shuffle_ps(b.quad, b.quad, 0xc9));
    result.quad = _mm_sub_ps(p, q);
}
// Projects a point onto a Limit cone defined by axis, origin, slope, and positive/negative limits, applying scale and transform constraints.
// @fnv 0x00d234e0
static __declspec(noinline) void FUN_00d234e0(Limit* apLimit, const Vector* point, Vector* out, Other* other)
{
    float slope = apLimit->slope;
    float scale = apLimit->scale;
    Vector offset;
    offset.quad = _mm_sub_ps(point->quad, apLimit->origin.quad);
    Vector origin = apLimit->origin;
    Vector axis = apLimit->axis;
    __m128 axial = dot3(axis, offset);
    float distance2;
    _mm_store_ss(&distance2, dot3(offset, offset));
    offset.quad = _mm_sub_ps(offset.quad, _mm_mul_ps(broadcast(axial), axis.quad));
    float axial2;
    _mm_store_ss(&axial2, _mm_mul_ss(axial, axial));
    Matrix* transform = other->transform;
    float facing;
    _mm_store_ss(&facing, dot3(transform->c3, offset));
    float limit = facing > 0.0f ? apLimit->positive : apLimit->negative;
    if (limit > 0.0f)
    {
        float side = 0.0f;
        Vector cross;
        crossProduct(cross, transform->c3, axis);
        float cross2;
        _mm_store_ss(&cross2, dot3(cross, cross));
        if (DAT_0104da4c < cross2)
        {
            float len = (float)sqrt(cross2);
            float inv = 1.0f / len;
            cross.quad = _mm_mul_ps(scalar(inv), cross.quad);
            side = value(dot3(cross, offset));
            float slope2 = slope * slope;
            float side2 = side * side;
            if (slope2 * axial2 >= side2)
            {
                offset.quad = _mm_sub_ps(offset.quad, _mm_mul_ps(scalar(side), cross.quad));
                side = 0.0f;
            }
        }
        float cone2 = (limit + slope) * (limit + slope);
        float residual2 = distance2 - side * side - axial2;
        if (cone2 * axial2 >= residual2)
        {
            if (side == 0.0f)
            {
                out->quad = origin.quad;
                return;
            }
            offset.quad = _mm_mul_ps(scalar(side), cross.quad);
        }
    }
    else
    {
        float slope2 = slope * slope;
        if ((slope2 + 1.0) * axial2 >= distance2)
        {
            out->quad = origin.quad;
            return;
        }
    }
    if (scale < 1.0f)
    {
        float projected2;
        _mm_store_ss(&projected2, dot3(offset, offset));
        if (DAT_0104da4c <= projected2 && distance2 * DAT_01016978 < projected2)
        {
            float ratio = distance2 / projected2;
            float root = (float)sqrt(ratio);
            float factor = scale + (1.0f - scale) * root;
            offset.quad = _mm_mul_ps(scalar(factor), offset.quad);
            __m128 component = dot3(axis, offset);
            offset.quad = _mm_sub_ps(offset.quad, _mm_mul_ps(broadcast(component), axis.quad));
        }
    }
    origin.quad = _mm_add_ps(origin.quad, offset.quad);
    out->quad = origin.quad;
}
Limit* volatile inputLimit;
const Vector* volatile inputPoint;
Vector* volatile outputPoint;
Other* volatile inputOther;
void invokeProjection()
{
    FUN_00d234e0(inputLimit, inputPoint, outputPoint, inputOther);
}

extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
    double fabs(double);
}
static __forceinline float root(float f)
{
    return (float)sqrt(f);
}
static __forceinline float absoluteValue(float f)
{
    return (float)fabs(f);
}
extern float DAT_0104da4c;
extern const __m128 DAT_01017d10;
extern const float DAT_01011d78;

static __forceinline __m128 scalarParam(float f)
{
    return _mm_load_ss(&f);
}
static __forceinline float scalar(__m128 q)
{
    float f;
    _mm_store_ss(&f, q);
    return f;
}

struct Basis
{
    Vector first, second, third;
};
struct Record : Limit
{
    int priority, unk34, unk38, unk3c;
};
struct State
{
    int unk00, unk04, unk08;
    int state;
};
struct Shape : Matrix
{
    int unk40, unk44;
    Record* records;
};
struct Working
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    State* states;
};
struct Context
{
    Other base;
    Working* working;
};
struct ContextArg
{
    Context* p;
};
struct VecArg
{
    Vector* p;
    VecArg(Vector* v) : p(v)
    {}
};

static __forceinline __m128 prefixColumns(Context* context, Record* a, Record* b, const Vector& raw, const Vector& unit,
                                          const Basis& basis, float inv, Vector& base, __m128& first, __m128& second)
{
    float bDot = scalar(dot3(b->origin, b->axis));
    float aDot = scalar(dot3(a->origin, a->axis));
    Vector centerSum;
    centerSum.quad = _mm_add_ps(a->origin.quad, b->origin.quad);
    float midpointDot = scalar(dot3(centerSum, unit)) * 0.5;
    __m128 weights = _mm_setr_ps(midpointDot, aDot, bDot, DAT_01011d78);
    first = _mm_mul_ps(_mm_shuffle_ps(weights, weights, 0), basis.first.quad);
    second = _mm_mul_ps(_mm_shuffle_ps(weights, weights, 0x55), basis.second.quad);
    __m128 third = _mm_mul_ps(_mm_shuffle_ps(weights, weights, 0xaa), basis.third.quad);
    return third;
}
// Uses the cross product of a and b's axes to compute a point written to out; if that is degenerate or out of bounds, calls FUN_00d234e0 on both records.
// @fnv 0x00d23850
static __declspec(noinline) void FUN_00d23850(Context* context, Record* a, Record* b, VecArg point, Vector* out)
{
    float threshold = DAT_0104da4c;
    Vector raw;
    crossProduct(raw, a->axis, b->axis);
    float fLengthSq = scalar(dot3(raw, raw));
    if (threshold >= fLengthSq)
        goto fallback;
    {
        float inv = 1.0f / root(fLengthSq);
        __m128 scale = scalarParam(inv);
        Vector unit;
        unit.quad = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), raw.quad);
        Basis basis;
        basis.first.quad = raw.quad;
        crossProduct(basis.second, b->axis, unit);
        crossProduct(basis.third, unit, a->axis);
        Vector base;
        __m128 first;
        __m128 second;
        __m128 third = prefixColumns(context, a, b, raw, unit, basis, inv, base, first, second);
        base.quad = _mm_mul_ps(_mm_add_ps(_mm_add_ps(first, second), third),
                               _mm_shuffle_ps(scalarParam(inv), scalarParam(inv), 0));
        __m128 absolute = _mm_and_ps(base.quad, DAT_01017d10);
        if (_mm_movemask_ps(_mm_cmplt_ps(context->base.transform->c2.quad, absolute)) & 7)
            goto fallback;

        Vector delta;
        delta.quad = _mm_sub_ps(point.p->quad, base.quad);
        float distance2 = scalar(dot3(delta, delta));
        float preferred = scalar(dot3(context->base.transform->c3, unit));
        float axial = scalar(dot3(delta, unit));
        float displacement = axial;
        float radius = a->slope + b->slope;
        if (axial * preferred > 0.0)
            radius += preferred * (a->positive + b->positive);
        else
            radius += preferred * (a->negative + b->negative);
        radius = radius * 0.5;
        float blend = (a->scale + b->scale) * 0.5;
        float axial2 = axial * axial;
        if ((distance2 - axial2) * float(radius * radius) >= axial2)
        {
            out->quad = base.quad;
            return;
        }
        if (blend < 1.0f && distance2 * DAT_01016978 < axial * axial)
        {
            float invAxial = 1.0f / axial;
            invAxial = absoluteValue(invAxial);
            float ratio = root(distance2);
            ratio = ratio * invAxial;
            ratio = blend + (1.0f - blend) * ratio;
            displacement = ratio * axial;
        }
        out->quad =
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&displacement), _mm_load_ss(&displacement), 0), unit.quad),
                       base.quad);
        return;
    }
fallback:
    context->working->states[a - static_cast<Shape*>(context->base.transform)->records].state = 2;
    context->working->states[b - static_cast<Shape*>(context->base.transform)->records].state = 2;
    ContextArg ca = {context};
    Vector* dst = out;
    Vector* src = point.p;
    if (a->priority > b->priority)
    {
        FUN_00d234e0(b, src, dst, &ca.p->base);
        FUN_00d234e0(a, dst, dst, &ca.p->base);
    }
    else
    {
        FUN_00d234e0(a, src, dst, &ca.p->base);
        FUN_00d234e0(b, dst, dst, &ca.p->base);
    }
}

extern Context* volatile testContext;
extern Record* volatile testLeft;
extern Record* volatile testRight;
extern Vector* volatile testPoint;
extern Vector* volatile testOut;
void invokeGeometry()
{
    VecArg p(testPoint);
    FUN_00d23850(testContext, testLeft, testRight, p, testOut);
}

struct V
{
    union
    {
        __m128 v;
        float f[4];
    };
    V()
    {}
    V(const V& r)
    {
        v = r.v;
    }
    void operator=(const V& r)
    {
        v = r.v;
    }
    void cross(const V& a, const V& b);
};
struct CrossBasis
{
    V bc;
    V ca;
    V ab;
    CrossBasis()
    {}
    V& column(int n)
    {
        return (&bc)[n];
    }
    const V& column(int n) const
    {
        return (&bc)[n];
    }
};
struct PlaneMeta
{
    int priority, unk34, unk38, unk3c;
};
struct PlaneRecord
{

    V normal;

    V point;

    __m128 auxiliary;

    PlaneMeta metadata;
};

struct PlaneStatus
{
    int unk00;
    int unk04;
    int unk08;
    int marked;
};

struct PlaneGeometry
{

    __m128 unk00;

    __m128 unk10;

    __m128 bounds;

    __m128 unk30;

    int unk40;

    int unk44;

    PlaneRecord* planes;
};

struct PlaneStatusStore
{

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

    int unk14;
    int unk18;
    int unk1c;
    int unk20;

    PlaneStatus* entries;
};

struct IntersectionContext
{

    int unk00;

    PlaneRecord* first;

    int unk08;
    int unk0c;

    PlaneRecord* second;

    int unk14;
    int unk18;

    PlaneRecord* third;

    int unk20;
    int unk24;
    int unk28;
    int unk2c;

    int count;

    int unk34;

    PlaneGeometry* geometry;

    PlaneStatusStore* status;
};

extern void __cdecl FUN_00d23380(IntersectionContext* context);

inline void V::cross(const V& a, const V& b)
{

    __m128 lhs = _mm_mul_ps(_mm_shuffle_ps(a.v, a.v, 0xc9), _mm_shuffle_ps(b.v, b.v, 0xd2));

    __m128 rhs = _mm_mul_ps(_mm_shuffle_ps(a.v, a.v, 0xd2), _mm_shuffle_ps(b.v, b.v, 0xc9));

    v = _mm_sub_ps(lhs, rhs);
}

inline float dot(const __m128& a, const __m128& b)
{

    __m128 p = _mm_mul_ps(a, b);

    __m128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);

    __m128 total = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);

    float result;
    _mm_store_ss(&result, total);
    return result;
}

inline __m128 distances3(float a, float b, float c)
{
    return _mm_setr_ps(a, b, c, DAT_01011d78);
}

extern void __cdecl FUN_00d234e0(IntersectionContext*, PlaneRecord*, const __m128*);

extern const double DAT_01011588 = 0.5;

struct PairPlane
{
    PlaneRecord* p;
};

struct PairRead
{
    const __m128* p;
};

struct PairWrite
{
    __m128* p;
};

static __declspec(noinline) void FUN_00d23850(IntersectionContext* ctx, PairPlane aw, PairPlane bw, PairRead fw,
                                              PairWrite rw)

{

    PlaneRecord* a = aw.p;
    PlaneRecord* b = bw.p;

    const V& na = a->normal;
    const V& nb = b->normal;

    V direction;
    direction.cross(na, nb);

    float squaredLength = dot(direction.v, direction.v);

    if (!(squaredLength < DAT_0104da4c))
    {

        float inverse = 1.0f / root(squaredLength);

        direction.v = _mm_mul_ps(direction.v, scalar(inverse));

        V right, left;
        right.cross(nb, direction);
        left.cross(direction, na);

        float db = dot(b->point.v, nb.v);

        float da = dot(a->point.v, na.v);

        float average = (float)(dot(_mm_add_ps(a->point.v, b->point.v), direction.v) * DAT_01011588);

        __m128 distances = distances3(average, db, da);

        __m128 sum = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0),
                       _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(nb.v, nb.v, 0xd2), _mm_shuffle_ps(na.v, na.v, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(nb.v, nb.v, 0xc9), _mm_shuffle_ps(na.v, na.v, 0xd2)))),
            _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0x55), left.v));

        sum = _mm_add_ps(sum, _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0xaa), right.v));

        __m128 position = _mm_mul_ps(sum, scalar(inverse));

        if (!(_mm_movemask_ps(_mm_cmplt_ps(ctx->geometry->bounds, _mm_and_ps(position, DAT_01017d10))) & 7))
        {

            __m128 difference = _mm_sub_ps(*fw.p, position);

            float squared = dot(difference, difference);

            float radius = dot(ctx->geometry->unk30, direction.v);

            float projection = dot(difference, direction.v);

            float threshold = (float)((a->auxiliary.m128_f32[0] + b->auxiliary.m128_f32[0] +
                                       radius * ((projection * radius > 0.0f)
                                                     ? a->auxiliary.m128_f32[1] + b->auxiliary.m128_f32[1]
                                                     : a->auxiliary.m128_f32[2] + b->auxiliary.m128_f32[2])) *
                                      DAT_01011588);

            float blend = (float)((a->auxiliary.m128_f32[3] + b->auxiliary.m128_f32[3]) * DAT_01011588);

            if ((squared - projection * projection) * threshold * threshold >= projection * projection)
            {
                *rw.p = position;
                return;
            }

            float adjustment = projection;

            if (blend < 1.0f && !(0.001f * squared < projection * projection))

                adjustment = projection * (blend + root(squared) * absoluteValue(1.0f / projection) * (1.0f - blend));

            *rw.p = _mm_add_ps(position, _mm_mul_ps(scalar(adjustment), direction.v));

            return;
        }
    }

    ctx->status->entries[a - ctx->geometry->planes].marked = 2;

    ctx->status->entries[b - ctx->geometry->planes].marked = 2;

    if (a->metadata.priority > b->metadata.priority)
    {

        FUN_00d234e0(ctx, b, fw.p);
        FUN_00d234e0(ctx, a, rw.p);
    }
    else
    {
        FUN_00d234e0(ctx, a, fw.p);
        FUN_00d234e0(ctx, b, rw.p);
    }
}

struct Wrap_b
{
    PlaneRecord* p;
};

struct Wrap_c
{
    PlaneRecord* p;
};

struct Wrap_reorder
{
    int p;
};

struct Wrap_fallback
{
    const __m128* p;
};

struct Wrap_result
{
    __m128* p;
};

// Computes the intersection point of three planes using a cross-product basis, falling back to sequential pairwise intersection if the determinant is near zero.
// @fnv 0x00d23ca0
static __declspec(noinline) void FUN_00d23ca0(IntersectionContext* ctx, PlaneRecord* apPlaneA, PlaneRecord* apPlaneB,
                                              PlaneRecord* apPlaneC, Wrap_reorder reorder, Wrap_fallback fallback,
                                              Wrap_result result)
{
    V point;
    CrossBasis basis;
    V& bc = basis.column(0);
    V& ca = basis.column(1);
    V& ab = basis.column(2);
    bc.cross(apPlaneB->normal, apPlaneC->normal);
    ca.cross(apPlaneC->normal, apPlaneA->normal);
    ab.cross(apPlaneA->normal, apPlaneB->normal);
    float determinant = dot(bc.v, apPlaneA->normal.v);
    if (absoluteValue(determinant) < 0.00000011920928955078125f)
        goto sequential;
    {
        V weights;
        float dc = dot(apPlaneC->normal.v, apPlaneC->point.v);
        float db = dot(apPlaneB->normal.v, apPlaneB->point.v);
        weights.v = distances3(dot(apPlaneA->normal.v, apPlaneA->point.v), db, dc);
        __m128 wx = _mm_shuffle_ps(weights.v, weights.v, 0);
        __m128 first = _mm_mul_ps(basis.column(0).v, wx);
        __m128 wy = _mm_shuffle_ps(weights.v, weights.v, 0x55);
        __m128 second = _mm_mul_ps(basis.column(1).v, wy);
        __m128 wz = _mm_shuffle_ps(weights.v, weights.v, 0xaa);
        __m128 third = _mm_mul_ps(basis.column(2).v, wz);
        point.v = _mm_add_ps(_mm_add_ps(first, second), third);
        float inverse = 1.0f / determinant;
        point.v = _mm_mul_ps(point.v, _mm_shuffle_ps(_mm_load_ss(&inverse), _mm_load_ss(&inverse), 0));
        V absolute;
        absolute.v = _mm_and_ps(point.v, DAT_01017d10);
        if (_mm_movemask_ps(_mm_cmplt_ps(ctx->geometry->bounds, absolute.v)) & 7)
            goto sequential;
        *result.p = point.v;
        return;
    }
sequential:
    if (reorder.p)
    {
        FUN_00d23380(ctx);
        apPlaneA = ctx->first;
        apPlaneB = ctx->second;
        apPlaneC = ctx->third;
    }
    ctx->status->entries[apPlaneA - ctx->geometry->planes].marked = 1;
    ctx->status->entries[apPlaneB - ctx->geometry->planes].marked = 1;
    ctx->status->entries[apPlaneC - ctx->geometry->planes].marked = 1;
    int oldCount = ctx->count;
    {
        PairPlane pa = {apPlaneA}, pb = {apPlaneB};
        PairRead pf = {fallback.p};
        PairWrite pr = {result.p};
        FUN_00d23850(ctx, pa, pb, pf, pr);
    }
    if (oldCount == ctx->count)
    {
        PairPlane pa = {apPlaneA}, pc = {apPlaneC};
        PairRead pf = {result.p};
        PairWrite pr = {result.p};
        FUN_00d23850(ctx, pa, pc, pf, pr);
    }
    if (oldCount == ctx->count)
    {
        PairPlane pb = {apPlaneB}, pc = {apPlaneC};
        PairRead pf = {result.p};
        PairWrite pr = {result.p};
        FUN_00d23850(ctx, pb, pc, pf, pr);
    }
}

extern PlaneRecord* volatile feed_a;

extern IntersectionContext* volatile feed_ctx;

extern PlaneRecord* volatile feed_b;

extern PlaneRecord* volatile feed_c;

extern int volatile feed_reorder;

extern const __m128* volatile feed_fallback;

extern __m128* volatile feed_result;

void emit_intersection()
{
    Wrap_b w_b = {feed_b};

    Wrap_c w_c = {feed_c};

    Wrap_reorder w_reorder = {feed_reorder};

    Wrap_fallback w_fallback = {feed_fallback};

    Wrap_result w_result = {feed_result};

    FUN_00d23ca0(feed_ctx, feed_a, w_b.p, w_c.p, w_reorder, w_fallback, w_result);
}

extern float runtimeFloatSettingDefault166;

struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b) : m_cBooleanValue(b ? 1 : 0)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct Vec4
{
    union
    {
        __m128 m_vComponents;
        struct
        {
            float x, y, z, w;
        };
    };
    void operator=(const Vec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct ActivePlane
{
    int m_uiEdgeIndex;
    PlaneRecord* m_pHavokConstraint;
    PlaneStatus* m_pPlaneStatus;
};

struct SimplexInput
{
    Vec4 m_vContactPosition;
    Vec4 m_fVelocity;
    Vec4 m_vThirdInputVector;
    Vec4 m_vFourthInputVector;
    float m_fTimeStep;
    float m_fConstraintParameter;
    PlaneRecord* m_ppConstraints;
    int m_iConstraintCount;
};

struct SimplexOutput
{
    Vec4 m_vContactPosition;
    Vec4 m_fVelocity;
    float m_fTimeStep;
    PlaneStatus* m_pPlaneStatuses;
};

struct SimplexInfo
{
    ActivePlane m_kActivePlanes[4];
    int m_iActivePlaneCount;
    float m_fElapsedSimulationTime;
    const SimplexInput* m_pRayCastInput;
    SimplexOutput* m_pRayCastOutput;
};

static __declspec(noinline) void FUN_00d234e0(const SimplexInfo& other_, const PlaneRecord& self_, const Vec4& point_,
                                              Vec4& out_)
{
    const Limit* self = (const Limit*)&self_;
    const Vector* point = (const Vector*)&point_;
    Vector* out = (Vector*)&out_;
    const Other* other = (const Other*)&other_;
    float slope = self->slope;
    float scale = self->scale;
    Vector offset;
    offset.quad = _mm_sub_ps(point->quad, self->origin.quad);
    Vector origin = self->origin;
    Vector axis = self->axis;
    __m128 axial = dot3(axis, offset);
    float distance2;
    _mm_store_ss(&distance2, dot3(offset, offset));
    offset.quad = _mm_sub_ps(offset.quad, _mm_mul_ps(broadcast(axial), axis.quad));
    float axial2;
    _mm_store_ss(&axial2, _mm_mul_ss(axial, axial));
    Matrix* transform = other->transform;
    float facing;
    _mm_store_ss(&facing, dot3(transform->c3, offset));
    float limit = facing > 0.0f ? self->positive : self->negative;
    if (limit > 0.0f)
    {
        float side = 0.0f;
        Vector cross;
        crossProduct(cross, transform->c3, axis);
        float cross2;
        _mm_store_ss(&cross2, dot3(cross, cross));
        if (DAT_0104da4c < cross2)
        {
            float len = (float)sqrt(cross2);
            float inv = 1.0f / len;
            cross.quad = _mm_mul_ps(scalar(inv), cross.quad);
            side = value(dot3(cross, offset));
            float slope2 = slope * slope;
            float side2 = side * side;
            if (slope2 * axial2 >= side2)
            {
                offset.quad = _mm_sub_ps(offset.quad, _mm_mul_ps(scalar(side), cross.quad));
                side = 0.0f;
            }
        }
        float cone2 = (limit + slope) * (limit + slope);
        float residual2 = distance2 - side * side - axial2;
        if (cone2 * axial2 >= residual2)
        {
            if (side == 0.0f)
            {
                out->quad = origin.quad;
                return;
            }
            offset.quad = _mm_mul_ps(scalar(side), cross.quad);
        }
    }
    else
    {
        float slope2 = slope * slope;
        if ((slope2 + 1.0) * axial2 >= distance2)
        {
            out->quad = origin.quad;
            return;
        }
    }
    if (scale < 1.0f)
    {
        float projected2;
        _mm_store_ss(&projected2, dot3(offset, offset));
        if (DAT_0104da4c <= projected2 && distance2 * DAT_01016978 < projected2)
        {
            float ratio = distance2 / projected2;
            float root = (float)sqrt(ratio);
            float factor = scale + (1.0f - scale) * root;
            offset.quad = _mm_mul_ps(scalar(factor), offset.quad);
            __m128 component = dot3(axis, offset);
            offset.quad = _mm_sub_ps(offset.quad, _mm_mul_ps(broadcast(component), axis.quad));
        }
    }
    origin.quad = _mm_add_ps(origin.quad, offset.quad);
    out->quad = origin.quad;
}

static __declspec(noinline) hkBool FUN_00d23480(const PlaneRecord& sci, const Vec4& velocityIn)
{
    V relativeVelocity;
    relativeVelocity.v = _mm_sub_ps(velocityIn.m_vComponents, sci.point.v);
    float planeVel = dot(relativeVelocity.v, sci.normal.v);
    if (planeVel < runtimeFloatSettingDefault166)
    {
        return false;
    }
    return true;
}

static __declspec(noinline) void FUN_00d23850(SimplexInfo& ctx_, const PlaneRecord* a_, const PlaneRecord* b_,
                                              const Vec4* fw_, Vec4* rw_)
{
    IntersectionContext* ctx = (IntersectionContext*)&ctx_;
    const PlaneRecord* a = *(const PlaneRecord* const volatile*)&a_;
    const PlaneRecord* b = *(const PlaneRecord* const volatile*)&b_;
    const Vec4& fw = **(const Vec4* const volatile*)&fw_;
    Vec4& rw = **(Vec4* const volatile*)&rw_;
    const V& na = a->normal;
    const V& nb = b->normal;
    V direction;
    direction.cross(na, nb);
    float squaredLength = dot(direction.v, direction.v);
    if (!(squaredLength < DAT_0104da4c))
    {
        float inverse = 1.0f / root(squaredLength);
        direction.v = _mm_mul_ps(direction.v, scalar(inverse));
        V right, left;
        right.cross(nb, direction);
        left.cross(direction, na);
        float db = dot(b->point.v, nb.v);
        float da = dot(a->point.v, na.v);
        float average = (float)(dot(_mm_add_ps(a->point.v, b->point.v), direction.v) * DAT_01011588);
        __m128 distances = distances3(average, db, da);
        __m128 sum = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0),
                       _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(nb.v, nb.v, 0xd2), _mm_shuffle_ps(na.v, na.v, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(nb.v, nb.v, 0xc9), _mm_shuffle_ps(na.v, na.v, 0xd2)))),
            _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0x55), left.v));
        sum = _mm_add_ps(sum, _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0xaa), right.v));
        __m128 position = _mm_mul_ps(sum, scalar(inverse));
        if (!(_mm_movemask_ps(_mm_cmplt_ps(ctx->geometry->bounds, _mm_and_ps(position, DAT_01017d10))) & 7))
        {
            __m128 difference = _mm_sub_ps(fw.m_vComponents, position);
            float squared = dot(difference, difference);
            float radius = dot(ctx->geometry->unk30, direction.v);
            float projection = dot(difference, direction.v);
            float threshold = (float)((a->auxiliary.m128_f32[0] + b->auxiliary.m128_f32[0] +
                                       radius * ((projection * radius > 0.0f)
                                                     ? a->auxiliary.m128_f32[1] + b->auxiliary.m128_f32[1]
                                                     : a->auxiliary.m128_f32[2] + b->auxiliary.m128_f32[2])) *
                                      DAT_01011588);
            float blend = (float)((a->auxiliary.m128_f32[3] + b->auxiliary.m128_f32[3]) * DAT_01011588);
            if ((squared - projection * projection) * threshold * threshold >= projection * projection)
            {
                rw.m_vComponents = position;
                return;
            }
            float adjustment = projection;
            if (blend < 1.0f && !(0.001f * squared < projection * projection))
            {
                adjustment = projection * (blend + root(squared) * absoluteValue(1.0f / projection) * (1.0f - blend));
            }
            rw.m_vComponents = _mm_add_ps(position, _mm_mul_ps(scalar(adjustment), direction.v));
            return;
        }
    }
    ctx->status->entries[a - ctx->geometry->planes].marked = 2;
    ctx->status->entries[b - ctx->geometry->planes].marked = 2;
    *(const PlaneRecord* const volatile*)&b_;
    if (a->metadata.priority > b->metadata.priority)
    {
        FUN_00d234e0(ctx_, *b, fw, rw);
        FUN_00d234e0(ctx_, *a, rw, rw);
    }
    else
    {
        FUN_00d234e0(ctx_, *a, fw, rw);
        FUN_00d234e0(ctx_, *b, rw, rw);
    }
}

static __declspec(noinline) void FUN_00d23ca0(SimplexInfo& ctx_, const PlaneRecord* a, const PlaneRecord* b,
                                              const PlaneRecord* c, int allowResort, const Vec4& fallback, Vec4& result)
{
    IntersectionContext* ctx = (IntersectionContext*)&ctx_;
    CrossBasis m;
    V& r0 = m.column(0);
    V& r1 = m.column(1);
    V& r2 = m.column(2);
    r0.cross(b->normal, c->normal);
    r1.cross(c->normal, a->normal);
    r2.cross(a->normal, b->normal);
    float det = dot(r0.v, a->normal.v);
    if (!(absoluteValue(det) < DAT_0104da4c))
    {
        float dc = dot(c->point.v, c->normal.v);
        float db = dot(b->point.v, b->normal.v);
        float da = dot(a->point.v, a->normal.v);
        __m128 t = distances3(da, db, dc);
        float invDet = 1.0f / det;
        __m128 sVel = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(t, t, 0), r0.v), _mm_mul_ps(_mm_shuffle_ps(t, t, 0x55), r1.v)),
            _mm_mul_ps(_mm_shuffle_ps(t, t, 0xaa), r2.v));
        sVel = _mm_mul_ps(sVel, scalar(invDet));
        if (!(_mm_movemask_ps(_mm_cmplt_ps(ctx->geometry->bounds, _mm_and_ps(sVel, DAT_01017d10))) & 7))
        {
            result.m_vComponents = sVel;
            return;
        }
    }
    if (allowResort)
    {
        FUN_00d23380(ctx);
        a = ctx->first;
        b = ctx->second;
        c = ctx->third;
    }
    ctx->status->entries[a - ctx->geometry->planes].marked = 1;
    ctx->status->entries[b - ctx->geometry->planes].marked = 1;
    ctx->status->entries[c - ctx->geometry->planes].marked = 1;
    int oldNum = ctx->count;
    FUN_00d23850(ctx_, a, b, &fallback, &result);
    if (ctx->count == oldNum)
    {
        FUN_00d23850(ctx_, a, c, &result, &result);
    }
    if (ctx->count == oldNum)
    {
        FUN_00d23850(ctx_, b, c, &result, &result);
    }
}

template <typename T> static __forceinline T hkMax2(T a, T b)
{
    return a > b ? a : b;
}

// Iteratively reduces the active plane set by testing velocity against planes and resolving intersections until a stable result is written to the ray-cast output.
// @fnv 0x00d23f50
static __declspec(noinline) void FUN_00d23f50(SimplexInfo& info)
{
    while (true)
    {
        switch (info.m_iActivePlaneCount)
        {
        case 1: {
            PlaneRecord* sci = info.m_kActivePlanes[0].m_pHavokConstraint;
            FUN_00d234e0(info, *sci, info.m_pRayCastInput->m_fVelocity, info.m_pRayCastOutput->m_fVelocity);
            return;
        }
        case 2: {
            Vec4 velocity;
            FUN_00d234e0(info, *info.m_kActivePlanes[1].m_pHavokConstraint, info.m_pRayCastInput->m_fVelocity,
                         velocity);
            hkBool plane0Used = FUN_00d23480(*info.m_kActivePlanes[0].m_pHavokConstraint, velocity);
            if (!plane0Used)
            {
                info.m_pRayCastOutput->m_fVelocity = velocity;
                info.m_kActivePlanes[0] = info.m_kActivePlanes[1];
                info.m_iActivePlaneCount = 1;
                return;
            }
            FUN_00d23850(info, info.m_kActivePlanes[0].m_pHavokConstraint, info.m_kActivePlanes[1].m_pHavokConstraint,
                         &info.m_pRayCastInput->m_fVelocity, &info.m_pRayCastOutput->m_fVelocity);
            return;
        }
        case 3: {
            {
                Vec4 velocity;
                FUN_00d234e0(info, *info.m_kActivePlanes[2].m_pHavokConstraint, info.m_pRayCastInput->m_fVelocity,
                             velocity);
                hkBool plane0Used = FUN_00d23480(*info.m_kActivePlanes[0].m_pHavokConstraint, velocity);
                if (!plane0Used)
                {
                    hkBool plane1Used = FUN_00d23480(*info.m_kActivePlanes[1].m_pHavokConstraint, velocity);
                    if (!plane1Used)
                    {
                        info.m_pRayCastOutput->m_fVelocity = velocity;
                        info.m_kActivePlanes[0] = info.m_kActivePlanes[2];
                        info.m_iActivePlaneCount = 1;
                        break;
                    }
                }
            }
            {
                bool dropped_a_plane = false;
                for (int testPlane = 0; testPlane < 2; testPlane++)
                {
                    Vec4 velocity;
                    FUN_00d23850(info, info.m_kActivePlanes[testPlane].m_pHavokConstraint,
                                 info.m_kActivePlanes[2].m_pHavokConstraint, &info.m_pRayCastInput->m_fVelocity,
                                 &velocity);
                    bool planeUsed = FUN_00d23480(*info.m_kActivePlanes[1 - testPlane].m_pHavokConstraint, velocity);
                    if (!planeUsed)
                    {
                        info.m_kActivePlanes[0] = info.m_kActivePlanes[testPlane];
                        info.m_kActivePlanes[1] = info.m_kActivePlanes[2];
                        info.m_iActivePlaneCount--;
                        dropped_a_plane = true;
                        break;
                    }
                }
                if (dropped_a_plane)
                {
                    break;
                }
            }
            FUN_00d23ca0(info, info.m_kActivePlanes[0].m_pHavokConstraint, info.m_kActivePlanes[1].m_pHavokConstraint,
                         info.m_kActivePlanes[2].m_pHavokConstraint, true, info.m_pRayCastInput->m_fVelocity,
                         info.m_pRayCastOutput->m_fVelocity);
            return;
        }
        case 4: {
            FUN_00d23380((IntersectionContext*)&info);
            bool dropped_a_plane = false;
            for (int i = 0; i < 3; i++)
            {
                Vec4 velocity;
                FUN_00d23ca0(info, info.m_kActivePlanes[(i + 1) % 3].m_pHavokConstraint,
                             info.m_kActivePlanes[(i + 2) % 3].m_pHavokConstraint,
                             info.m_kActivePlanes[3].m_pHavokConstraint, false, info.m_pRayCastInput->m_fVelocity,
                             velocity);
                hkBool planeUsed = FUN_00d23480(*info.m_kActivePlanes[i].m_pHavokConstraint, velocity);
                if (!planeUsed)
                {
                    info.m_kActivePlanes[i] = info.m_kActivePlanes[2];
                    info.m_kActivePlanes[2] = info.m_kActivePlanes[3];
                    info.m_iActivePlaneCount = 3;
                    dropped_a_plane = true;
                    break;
                }
            }
            if (dropped_a_plane)
            {
                break;
            }
            {
                Vec4 velocity = info.m_pRayCastInput->m_fVelocity;
                PlaneRecord* sci0 = info.m_kActivePlanes[0].m_pHavokConstraint;
                PlaneRecord* sci1 = info.m_kActivePlanes[1].m_pHavokConstraint;
                PlaneRecord* sci2 = info.m_kActivePlanes[2].m_pHavokConstraint;
                PlaneRecord* sci3 = info.m_kActivePlanes[3].m_pHavokConstraint;
                int oldNum = info.m_iActivePlaneCount;
                FUN_00d23ca0(info, sci0, sci1, sci2, false, velocity, velocity);
                if (oldNum == info.m_iActivePlaneCount)
                {
                    FUN_00d23ca0(info, sci0, sci1, sci3, false, velocity, velocity);
                }
                try
                {
                    if (oldNum != info.m_iActivePlaneCount)
                        goto skip2;
                }
                catch (...)
                {
                    throw;
                }
                FUN_00d23ca0(info, sci0, sci2, sci3, false, velocity, velocity);
            skip2:
                try
                {
                    if (oldNum != info.m_iActivePlaneCount)
                        goto skip3;
                }
                catch (...)
                {
                    throw;
                }
                FUN_00d23ca0(info, sci1, sci2, sci3, false, velocity, velocity);
            skip3:
                info.m_pRayCastOutput->m_fVelocity = velocity;
            }
            {
                int maxStatus = 0;
                for (int j = 0; j < 4; j++)
                {
                    maxStatus = hkMax2(maxStatus, info.m_kActivePlanes[j].m_pPlaneStatus->marked);
                }
                for (int k = 0; k < 4; k++)
                {
                    if (maxStatus == info.m_kActivePlanes[k].m_pPlaneStatus->marked)
                    {
                        info.m_kActivePlanes[k] = info.m_kActivePlanes[3];
                        break;
                    }
                }
                info.m_iActivePlaneCount--;
                for (int l = 0; l < 3; l++)
                {
                    info.m_kActivePlanes[l].m_pPlaneStatus->marked = 0;
                }
            }
            break;
        }
        default:
            return;
        }
    }
}

SimplexInfo* volatile g_simplexInfo;
void invokeExamineActivePlanes()
{
    FUN_00d23f50(*g_simplexInfo);
}
