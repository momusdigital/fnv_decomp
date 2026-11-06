
// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkaSplineCompressedAnimation.h"

struct FUN_00e33330_Class
{
    void* __thiscall FUN_00e33330();
};

// @fnv 0x00e33330
void* FUN_00e33330_Class::FUN_00e33330()
{
    return (void**)(*(int**)((char*)this + 0x78) + *(int*)((char*)this + 0x6c) + *(int*)((char*)this + 0x60) +
                    *(int*)((char*)this + 0x48)) +
           0x21;
}

extern bool DAT_0126efb8;
void __cdecl FUN_00e63c60(bool*);

// @fnv 0x00e52fa0
int __cdecl GetIndexedValueWithOffset(int offset, const int* values, int index, int count)
{
    if (!DAT_0126efb8)
    {
        FUN_00e63c60(&DAT_0126efb8);
        if (!DAT_0126efb8)
            return 0;
    }

    return offset + (count & 0x7fffffff) + values[index];
}

// @fnv 0x00e32ed0
int __stdcall getNumDataChunks(int a1, int a2)
{
    return 3;
}

struct FnvAnimation
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual int slot10(float time, int blockOffset, int parameterA, int blockEnd, int parameterB, int parameterC);

    int unk04;
    int unk08;
    int unk0C;
    int blockOffset;
    int blockEnd;

    int FUN_00e32ee0(float time, int parameterA, int parameterB, int parameterC);
};

// Forwards the time, blockOffset, blockEnd and the three parameters to slot10 and returns its result.
// @fnv 0x00e32ee0
int FnvAnimation::FUN_00e32ee0(float time, int parameterA, int parameterB, int parameterC)
{
    return slot10(time, blockOffset, parameterA, blockEnd, parameterB, parameterC);
}

typedef void(__cdecl* SplineDecodeFn)(int, void*);
extern int DAT_010eb3b8[];
extern int DAT_010eb3d0[];
extern SplineDecodeFn DAT_011be4b8[];
// @fnv 0x00e33030
void __cdecl DecodeSplineFrames(int* cursor, int type, int lastFrame, int firstFrame, int endFrame, void* output)
{
    int alignment = DAT_010eb3b8[type];
    *cursor = (*cursor + alignment - 1) & ~(alignment - 1);
    int stride = DAT_010eb3d0[type];
    if (firstFrame >= 0)
    {
        int byteOffset = (endFrame - firstFrame) * stride;
        SplineDecodeFn* volatile decodeSlot = &DAT_011be4b8[type];
        int remaining = firstFrame + 1;
        char* destination = static_cast<char*>(output);
        do
        {
            (*decodeSlot)(*cursor + byteOffset, destination);
            byteOffset += stride;
            destination += 16;
        } while (--remaining != 0);
    }
    *cursor += (lastFrame + 1) * stride;
}

template <class T> class hkArrayE333
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T* begin() const
    {
        return m_data;
    }
};

struct hkaAnimationDataChunkE333
{
    const char* m_data;
    int m_iElementCount;
    unsigned char m_offset;

    void set(const void* p, int iSize)
    {
        unsigned char offset = static_cast<unsigned char>(reinterpret_cast<unsigned long>(p) & 15);
        m_data = reinterpret_cast<const char*>(reinterpret_cast<unsigned long>(p) & ~15);
        m_offset = offset;
        m_iElementCount = (offset + iSize + 15) & ~15;
    }
};

class hkaSplineCompressedAnimationE333
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
    int m_iBlockCount;
    int m_iMaxFramesPerBlock;
    int unk34;
    float unk38;
    float m_fBlockInverseDuration;
    float m_fPerFrameDuration;
    hkArrayE333<unsigned int> m_kFirstUInt32Array;
    hkArrayE333<unsigned int> m_kFloatBlockOffsets;
    hkArrayE333<unsigned int> unk5C;
    hkArrayE333<unsigned int> unk68;
    hkArrayE333<unsigned char> m_data;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;

    void GetBlockAndTime(unsigned int frame, float delta, int& blockOut, float& blockTimeOut,
                         unsigned char& quantizedTimeOut) const throw();
    void GetDataChunks(unsigned int frame, float delta, hkaAnimationDataChunkE333* dataChunks, int numDataChunks) const
        throw();
};

typedef char fnv_check_e33350[(sizeof(hkaSplineCompressedAnimationE333) == 0x90) ? 1 : -1];

// @fnv 0x00e33350
void hkaSplineCompressedAnimationE333::GetDataChunks(unsigned int frame, float delta,
                                                     hkaAnimationDataChunkE333* dataChunks, int numDataChunks) const
    throw()
{
    dataChunks[0].m_data = reinterpret_cast<const char*>(this);
    dataChunks[0].m_iElementCount = sizeof(hkaSplineCompressedAnimationE333);

    int block;
    float blockTime;
    unsigned char quantizedTime;
    GetBlockAndTime(frame, delta, block, blockTime, quantizedTime);

    const int blockEnd = (block == m_iBlockCount - 1) ? m_data.GetLogicalSize() : m_kFirstUInt32Array.m_data[block + 1];
    const int blockSize = (blockEnd - m_kFirstUInt32Array.m_data[block] + 15) & ~15;

    dataChunks[1].set(m_data.begin() + m_kFirstUInt32Array.m_data[block], blockSize);
    {
        const void* p = m_kFloatBlockOffsets.begin() + block;
        unsigned char offset = static_cast<unsigned char>(reinterpret_cast<unsigned long>(p) & 15);
        dataChunks[2].m_offset = offset;
        dataChunks[2].m_data = reinterpret_cast<const char*>(reinterpret_cast<unsigned long>(p) & ~15);
        dataChunks[2].m_iElementCount = (offset + sizeof(unsigned int) + 15) & ~15;
    }
}

struct hkMathE334
{
    static int max2(int x, int y)
    {
        return x > y ? x : y;
    }
};

class FUN_00e33400_cls
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
    int* m_offsets;
    int m_numOffsets;
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
    int m_kRayEnd;

    int getMaxSizeOfCombinedDataChunks() const;
};

// @fnv 0x00e33400
int FUN_00e33400_cls::getMaxSizeOfCombinedDataChunks() const
{
    int iMaxGap = 0;
    int iPrev = m_kRayEnd;
    for (int i = m_numOffsets - 1; i >= 0; i--)
    {
        int iCurOffset = m_offsets[i];
        iMaxGap = hkMathE334::max2(iMaxGap, iPrev - iCurOffset);
        iPrev = iCurOffset;
    }
    return ((iMaxGap + 15) & ~15) + 0xa0;
}

template <typename T> inline T max2E347(T a, T b)
{
    return a > b ? a : b;
}
template <typename T> inline T min2E347(T a, T b)
{
    return a < b ? a : b;
}

class hkaSplineCompressedAnimationE347
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
    int m_iBlockCount;
    int m_iMaxFramesPerBlock;
    int unk34;
    float unk38;
    float m_fBlockInverseDuration;
    float m_fPerFrameDuration;

    void GetBlockAndTime(unsigned int frame, float delta, int& blockOut, float& blockTimeOut,
                         unsigned char& quantizedTimeOut) const throw();
};

// Computes the block index for a frame, clamps it, and outputs the block-local time and its quantized value.
// @fnv 0x00e34720
void hkaSplineCompressedAnimationE347::GetBlockAndTime(unsigned int frame, float delta, int& blockOut,
                                                       float& blockTimeOut, unsigned char& quantizedTimeOut) const
    throw()
{
    blockOut = frame / (m_iMaxFramesPerBlock - 1);
    blockOut = max2E347(blockOut, 0);
    blockOut = min2E347(blockOut, m_iBlockCount - 1);
    const unsigned int firstFrameOfBlock = blockOut * (m_iMaxFramesPerBlock - 1);
    const float fLocalFrame = (frame - firstFrameOfBlock) + delta;
    blockTimeOut = fLocalFrame * m_fPerFrameDuration;
    quantizedTimeOut =
        static_cast<unsigned char>((blockTimeOut * m_fBlockInverseDuration) * (m_iMaxFramesPerBlock - 1));
}

void __cdecl DecodeSplineFrame(const unsigned char*& dataInOut, int quantization, float frameDuration, float time,
                               int numItems, void* out, int stride);

class hkaSplineAnimE33
{
  public:
    virtual ~hkaSplineAnimE33();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_type;
    float m_fAnimationDuration;
    int m_iNumTransformTracks;
    int m_iNumberOfFloatTracks;
    void* m_pExtractedMotion;
    void* m_kAnnotationTracks;
    int m_numAnnotationTracks;
    int m_annotationTracksCapacity;
    int m_iFrameCount;
    int m_iBlockCount;
    int m_iMaxFramesPerBlock;
    int m_iMaskAndQuantizationSize;
    float m_fBlockDuration;
    float m_fBlockInverseDuration;
    float m_fPerFrameDuration;

    void ExtractFrame(float time, int quantization, int numItems, void* out, const unsigned char*& dataInOut,
                      int stride);
};

// Passes the inputs to DecodeSplineFrame, then aligns dataInOut to a 4-byte boundary.
// @fnv 0x00e33dc0
void hkaSplineAnimE33::ExtractFrame(float time, int quantization, int numItems, void* out,
                                    const unsigned char*& dataInOut, int stride)
{
    DecodeSplineFrame(dataInOut, quantization, m_fPerFrameDuration, time, numItems, out, stride);
    dataInOut = (const unsigned char*)(((unsigned long)dataInOut + 3) & ~3);
}

struct hkVector4E34
{
    float x, y, z, w;
};

// Per-component selects each output component from a or b based on the low and high nibbles of mask.
// @fnv 0x00e346a0
void __cdecl BlendVector4(unsigned char mask, const hkVector4E34& a, const hkVector4E34& b, hkVector4E34& out)
{
    int maskA = mask & 0xf;
    int maskB = (~mask >> 4) & ~mask & 0xf;
    if (maskA & 1)
        out.x = a.x;
    else if (maskB & 1)
        out.x = b.x;
    if (maskA & 2)
        out.y = a.y;
    else if (maskB & 2)
        out.y = b.y;
    if (maskA & 4)
        out.z = a.z;
    else if (maskB & 4)
        out.z = b.z;
    if (maskA & 8)
        out.w = a.w;
    else if (maskB & 8)
        out.w = b.w;
}

__declspec(noinline) int __cdecl FindKeyInterval(int n, int p, int u, const hkUint8* knots)
{
    hkUint8 value = (hkUint8)u;
    if (value >= knots[n + 1])
        return n;
    if (value <= knots[0])
        return p;
    int low = p;
    int high = n + 1;
    int mid = (low + high) / 2;
    while (value < knots[mid] || value >= knots[mid + 1])
    {
        if (value < knots[mid])
            high = mid;
        else
            low = mid;
        mid = (low + high) / 2;
    }
    return mid;
}

// Reads n and p, scales 2*p knots around the selected span into pfU, advances pDataInOut, and returns the span index.
// @fnv 0x00e32f10
int __cdecl FUN_00e32f10(const hkUint8*& pDataInOut, int& iNOut, int& iPOut, int iU, hkReal fScale, hkReal* pfU)
{
    hkUint16 iN16 = *reinterpret_cast<const hkUint16*>(pDataInOut);
    pDataInOut += sizeof(hkUint16);
    int iN = iN16;
    hkUint8 iP8 = *pDataInOut;
    pDataInOut += sizeof(hkUint8);
    int iP = iP8;
    const hkUint8* pKnots = pDataInOut;
    int iNumKnots = iN + iP + 1;
    int iSpan = FindKeyInterval(iN, iP, iU, pKnots);
    for (int i = 0; i < 2 * iP; i++)
    {
        hkReal fKnot = pDataInOut[iSpan - iP + 1 + i];
        pfU[i] = fKnot * fScale;
    }
    pDataInOut = pKnots + iNumKnots + 1;
    iNOut = iN;
    iPOut = iP;
    return iSpan;
}

#include <xmmintrin.h>
struct __declspec(align(16)) AlignedVector4
{
    float x, y, z, w;
};
struct ResultArg
{
    AlignedVector4* ptr;
    AlignedVector4* get() const
    {
        return ptr;
    }
};
extern const AlignedVector4 DAT_01268700;
struct FUN_00e33e10_Class : hkaSplineCompressedAnimation
{
    void EvaluateSpline(float time, int track, int enabled, int block, unsigned int* cursor, ResultArg result);
};
void __cdecl FUN_00e33a30(unsigned int*, int, float, float, int, int, const AlignedVector4*, AlignedVector4*);
// Writes a constant vector when enabled is zero; otherwise calls FUN_00e33a30, then aligns cursor to a 4-byte boundary.
// @fnv 0x00e33e10
void FUN_00e33e10_Class::EvaluateSpline(float time, int track, int enabled, int block, unsigned int* cursor,
                                        ResultArg result)
{
    __m128 constant = _mm_load_ps(&DAT_01268700.x);
    if ((unsigned char)enabled == 0)
    {
        _mm_store_ps(&result.get()->x, constant);
        *cursor = (*cursor + 3) & ~3u;
        return;
    }
    AlignedVector4 vDefaults;
    _mm_store_ps(&vDefaults.x, constant);
    FUN_00e33a30(cursor, track, m_fPerFrameDuration, time, enabled, block, &vDefaults, result.get());
    *cursor = (*cursor + 3) & ~3u;
}

namespace fnv_00e33e90 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct hkVector4E33E
{
    __m128 m_vComponents;
    hkVector4E33E()
    {}
    hkVector4E33E(const hkVector4E33E& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4E33E& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

extern hkVector4E33E DAT_01268720;

void __cdecl FUN_00e33a30(const hkUint8*& dataInOut, hkUint8 quantizedTime, hkReal frameDuration, hkReal u,
                          hkUint8 mask, int quantization, const hkVector4E33E& I, hkVector4E33E& out);

class hkaSplineCompressedAnimationE33E : public hkaSplineCompressedAnimation
{
  public:
    void FUN_00e33e90(hkReal blockTime, hkUint8 quantizedTime, hkUint8 mask, int quantization,
                      const hkUint8*& dataInOut, hkVector4E33E& out) const;
};

// Calls FUN_00e33a30 when mask is nonzero; otherwise assigns DAT_01268720 to out, then aligns dataInOut to a 4-byte boundary.
// @fnv 0x00e33e90
void hkaSplineCompressedAnimationE33E::FUN_00e33e90(hkReal blockTime, hkUint8 quantizedTime, hkUint8 mask,
                                                    int quantization, const hkUint8*& dataInOut,
                                                    hkVector4E33E& out) const
{
    if (!mask)
    {
        out = DAT_01268720;
    }
    else
    {
        FUN_00e33a30(dataInOut, quantizedTime, m_fPerFrameDuration, blockTime, mask, quantization,
                     hkVector4E33E(DAT_01268720), out);
    }
    dataInOut = reinterpret_cast<const hkUint8*>((reinterpret_cast<hkUlong>(dataInOut) + 3) & ~3);
}
}  // namespace fnv_00e33e90

struct SplineDataChunk
{
    const char* m_data;
    int m_iElementCount;
    unsigned char m_offset;
};
struct SplineAnimSampler : public hkaSplineCompressedAnimation
{
    void GetBlockAndTime(unsigned int frame, float delta, int& blockOut, float& blockTimeOut,
                         unsigned char& quantizedTimeOut) const;
    void EvaluateSpline(float time, unsigned char quantizedTime, unsigned char mask, int quantization,
                        const unsigned char** data, hkVector4* out) const;
    void ExtractFrame(float time, unsigned char quantizedTime, unsigned char mask, int quantization,
                      const unsigned char** data, hkQuaternion* out) const;
    void FUN_00e33e90(float time, unsigned char quantizedTime, unsigned char mask, int quantization,
                      const unsigned char** data, hkVector4* out) const;
    void FUN_00e33f10(float time, unsigned char quantizedTime, unsigned char mask, int quantization,
                      const unsigned char** data, float* out) const;
};
// Samples transform and float tracks from a spline animation at the given frame and delta, writing results to the output arrays.
// @fnv 0x00e33f90
void FUN_00e33f90(unsigned int frameIndex, float delta, unsigned int maxNumTransformTracks,
                  hkQsTransform* transformsOut, unsigned int maxNumFloatTracks, float* floatsOut,
                  const SplineDataChunk* dataChunks, int numDataChunks)
{
    const SplineAnimSampler* anim = reinterpret_cast<const SplineAnimSampler*>(dataChunks[0].m_data);
    float blockTime;
    unsigned char quantizedTime;
    {
        int block;
        anim->GetBlockAndTime(frameIndex, delta, block, blockTime, quantizedTime);
    }
    {
        const unsigned char* mask =
            reinterpret_cast<const unsigned char*>(dataChunks[1].m_data) + dataChunks[1].m_offset;
        const unsigned char* dataPtr = mask + anim->m_iMaskAndQuantizationSize;
        for (unsigned int i = 0; i < maxNumTransformTracks; i++)
        {
            unsigned char quantizationTypes = *mask++;
            anim->EvaluateSpline(blockTime, quantizedTime, *mask++, quantizationTypes & 3, &dataPtr,
                                 &transformsOut[i].m_vTranslation);
            anim->ExtractFrame(blockTime, quantizedTime, *mask++, (quantizationTypes >> 2) & 15, &dataPtr,
                               &transformsOut[i].m_rotation);
            anim->FUN_00e33e90(blockTime, quantizedTime, *mask++, quantizationTypes >> 6, &dataPtr,
                               &transformsOut[i].m_vScale);
        }
    }
    {
        unsigned int floatOffset =
            *reinterpret_cast<const unsigned int*>(dataChunks[2].m_data + dataChunks[2].m_offset);
        const unsigned char* floatData =
            reinterpret_cast<const unsigned char*>(dataChunks[1].m_data) + dataChunks[1].m_offset + floatOffset;
        const unsigned char* floatMask = reinterpret_cast<const unsigned char*>(dataChunks[1].m_data) +
                                         dataChunks[1].m_offset + anim->m_iNumTransformTracks * 4;
        for (unsigned int uiFloatIndex = 0; uiFloatIndex < maxNumFloatTracks; uiFloatIndex++)
        {
            unsigned char ucFloatMask = *floatMask++;
            anim->FUN_00e33f10(blockTime, quantizedTime, ucFloatMask & 0xf9, (ucFloatMask >> 1) & 3, &floatData,
                               &floatsOut[uiFloatIndex]);
        }
    }
}

namespace fnv_00e34310 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps(void);

template <class T> inline T& hkArrayAtE343(hkArray<T>& a, int i)
{
    return a.m_data[i];
}
template <class T> inline const T& hkArrayAtE343(const hkArray<T>& a, int i)
{
    return a.m_data[i];
}

inline void hkSetZero4E343(hkVector4& v)
{
    *(__m128*)&v = _mm_setzero_ps();
}

const hkUint8* __cdecl GetIndexedValueWithOffset(const hkUint8* base, const hkUint32* offsets, hkUint32 block,
                                                 hkUint32 offset);

class hkaSplineCompressedAnimationE343 : public hkaSplineCompressedAnimation
{
  public:
    __declspec(noalias) void FUN_00e2f7c0(hkReal time, hkUint32& frameOut, hkReal& deltaOut) const;
    __declspec(noalias) void GetBlockAndTime(hkUint32 frame, hkReal delta, hkUint32& blockOut, hkReal& blockTimeOut,
                                             hkUint8& quantizedTimeOut) const;
    void EvaluateSpline(hkReal blockTime, hkUint8 quantizedTime, hkUint8 mask, int quantization,
                        const hkUint8*& dataInOut, hkVector4& out) const;
    void ExtractFrame(hkReal blockTime, hkUint8 quantizedTime, hkUint8 mask, int quantization,
                      const hkUint8*& dataInOut, hkQuaternion& out) const;
    void FUN_00e33e90(hkReal blockTime, hkUint8 quantizedTime, hkUint8 mask, int quantization,
                      const hkUint8*& dataInOut, hkVector4& out) const;
    void sampleIndividualTransformTracks(hkReal time, const hkInt16* tracks, hkUint32 numTracks, hkQsTransform* transformTracksOut) const;
};

// Evaluates spline-compressed transform tracks at the given time, writing translation, rotation, and scale into transformTracksOut for each valid track index.
// @fnv 0x00e34310
void hkaSplineCompressedAnimationE343::sampleIndividualTransformTracks(hkReal time, const hkInt16* tracks, hkUint32 numTracks,
                                                    hkQsTransform* transformTracksOut) const
{
    hkUint32 frame;
    hkReal delta;
    FUN_00e2f7c0(time, frame, delta);

    hkUint32 block;
    hkReal blockTime;
    hkUint8 quantizedTime;
    GetBlockAndTime(frame, delta, block, blockTime, quantizedTime);

    for (hkUint32 i = 0; i < numTracks; i++)
    {
        const hkInt16 track = tracks[i];
        if (track >= 0 && track < m_iNumTransformTracks)
        {
            const hkUint8* dataStream =
                GetIndexedValueWithOffset(&hkArrayAtE343(m_data, 0), &hkArrayAtE343(m_kFirstUInt32Array, 0), block,
                                          hkArrayAtE343(m_kTransformOffsets, block * m_iNumTransformTracks + track));
            const hkUint8* mask = GetIndexedValueWithOffset(&hkArrayAtE343(m_data, 0),
                                                            &hkArrayAtE343(m_kFirstUInt32Array, 0), block, 4 * track);
            const hkUint8 quantizationTypes = mask[0];
            EvaluateSpline(blockTime, quantizedTime, mask[1], quantizationTypes & 3, dataStream,
                           transformTracksOut[i].m_vTranslation);
            ExtractFrame(blockTime, quantizedTime, mask[2], (quantizationTypes >> 2) & 0xf, dataStream,
                         transformTracksOut[i].m_rotation);
            FUN_00e33e90(blockTime, quantizedTime, mask[3], quantizationTypes >> 6, dataStream,
                         transformTracksOut[i].m_vScale);
        }
        else
        {
            hkSetZero4E343(transformTracksOut[i].m_vTranslation);
            hkSetZero4E343(transformTracksOut[i].m_rotation.m_vec);
            hkSetZero4E343(transformTracksOut[i].m_vScale);
        }
    }
}
}  // namespace fnv_00e34310

template <class T> inline T& hkArrayAtE344(hkArray<T>& a, int i)
{
    return a.m_data[i];
}
template <class T> inline const T& hkArrayAtE344(const hkArray<T>& a, int i)
{
    return a.m_data[i];
}

const hkUint8* __cdecl GetIndexedValueWithOffset(const hkUint8* base, const hkUint32* offsets, hkUint32 block,
                                                 hkUint32 offset);

class hkaSplineCompressedAnimationE344 : public hkaSplineCompressedAnimation
{
  public:
    __declspec(noalias) void FUN_00e2f7c0(hkReal time, hkUint32& frameOut, hkReal& deltaOut) const;
    __declspec(noalias) void GetBlockAndTime(hkUint32 frame, hkReal delta, hkUint32& blockOut, hkReal& blockTimeOut,
                                             hkUint8& quantizedTimeOut) const;
    void FUN_00e33f10(hkReal blockTime, hkUint8 quantizedTime, hkUint8 mask, int quantization,
                      const hkUint8*& dataInOut, hkReal& out) const;
    void sampleIndividualFloatTracks(hkReal time, const hkInt16* tracks, hkUint32 numTracks, hkReal* floatTracksOut) const;
};

// @fnv 0x00e34490
void hkaSplineCompressedAnimationE344::sampleIndividualFloatTracks(hkReal time, const hkInt16* tracks, hkUint32 numTracks,
                                                    hkReal* floatTracksOut) const
{
    hkUint32 frame;
    hkReal delta;
    FUN_00e2f7c0(time, frame, delta);

    hkUint32 block;
    hkReal blockTime;
    hkUint8 quantizedTime;
    GetBlockAndTime(frame, delta, block, blockTime, quantizedTime);

    for (hkUint32 i = 0; i < numTracks; i++, floatTracksOut++)
    {
        const hkInt16 track = tracks[i];
        if (track >= 0 && track < m_iNumberOfFloatTracks)
        {
            const hkUint8* dataStream =
                GetIndexedValueWithOffset(&hkArrayAtE344(m_data, 0), &hkArrayAtE344(m_kFirstUInt32Array, 0), block,
                                          hkArrayAtE344(m_kFloatOffsets, block * m_iNumberOfFloatTracks + track));
            const hkUint8 mask =
                *GetIndexedValueWithOffset(&hkArrayAtE344(m_data, 0), &hkArrayAtE344(m_kFirstUInt32Array, 0), block,
                                           4 * m_iNumTransformTracks + track);
            FUN_00e33f10(blockTime, quantizedTime, mask & 0xf9, (mask >> 1) & 3, dataStream, *floatTracksOut);
        }
        else
        {
            *floatTracksOut = 0.0f;
        }
    }
}

extern void* __cdecl FUN_00c85750(void);
extern void __cdecl FUN_00dfb5a0(int value);
extern void __cdecl FUN_00c905b0(void);

extern int DAT_010de0ec;
extern int DAT_0102e388;

struct FUN_00e345a0_Track
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(unsigned int value, unsigned int size);
};

struct FUN_00e345a0_Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct FUN_00dfb720
{
    virtual ~FUN_00dfb720();
};

class FUN_00e345a0_Obj : FUN_00dfb720
{
  public:
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

    void __thiscall FUN_00e345a0();
};

// @fnv 0x00e345a0
void __thiscall FUN_00e345a0_Obj::FUN_00e345a0()
{
    int zero = 0;
    int flag = 0x80000000;

    *reinterpret_cast<int**>(this) = &DAT_010de0ec;

    {
        FUN_00e345a0_Manager* manager = static_cast<FUN_00e345a0_Manager*>(FUN_00c85750());
        FUN_00e345a0_Track* track = reinterpret_cast<FUN_00e345a0_Track*>(manager->unk10);

        int val = unk7C;
        unk78 = zero;
        if ((val & flag) == 0)
        {
            track->vf10(unk74, val & 0x3FFFFFFF);
        }
        unk74 = zero;
        unk7C = flag;
    }

    {
        FUN_00e345a0_Manager* manager = static_cast<FUN_00e345a0_Manager*>(FUN_00c85750());
        FUN_00e345a0_Track* track = reinterpret_cast<FUN_00e345a0_Track*>(manager->unk10);

        int val = unk70;
        unk6C = zero;
        if ((val & flag) == 0)
        {
            track->vf10(unk68, (val & 0x3FFFFFFF) * 4);
        }
        unk68 = zero;
        unk70 = flag;
    }

    {
        FUN_00e345a0_Manager* manager = static_cast<FUN_00e345a0_Manager*>(FUN_00c85750());
        FUN_00e345a0_Track* track = reinterpret_cast<FUN_00e345a0_Track*>(manager->unk10);

        int val = unk64;
        unk60 = zero;
        if ((val & flag) == 0)
        {
            track->vf10(unk5C, (val & 0x3FFFFFFF) * 4);
        }
        unk5C = zero;
        unk64 = flag;
    }

    {
        FUN_00e345a0_Manager* manager = static_cast<FUN_00e345a0_Manager*>(FUN_00c85750());
        FUN_00e345a0_Track* track = reinterpret_cast<FUN_00e345a0_Track*>(manager->unk10);

        int val = unk58;
        unk54 = zero;
        if ((val & flag) == 0)
        {
            track->vf10(unk50, (val & 0x3FFFFFFF) * 4);
        }
        unk50 = zero;
        unk58 = flag;
    }

    {
        FUN_00e345a0_Manager* manager = static_cast<FUN_00e345a0_Manager*>(FUN_00c85750());
        FUN_00e345a0_Track* track = reinterpret_cast<FUN_00e345a0_Track*>(manager->unk10);

        int val = unk4C;
        unk48 = zero;
        if ((val & flag) == 0)
        {
            track->vf10(unk44, (val & 0x3FFFFFFF) * 4);
        }
        unk44 = zero;
        unk4C = flag;
    }

    FUN_00dfb720::~FUN_00dfb720();
}

#include <xmmintrin.h>
namespace fnv_00e33960 {
extern const unsigned int DAT_010eb3b8[];
extern const unsigned int DAT_010eb3d0[];

typedef void (*UnpackFunc)(const void*, hkVector4*);
extern const UnpackFunc DAT_011be4b8[];

typedef void (*SplineEvalFunc)(float, int, const void*, const void*, hkVector4*);
extern const SplineEvalFunc DAT_011be4d0[];

extern const __m128 DAT_010c71b0;

int __cdecl FUN_00e32f10(const unsigned char** data, int* b, int* a, int a2, float a3, void* knots);
void __cdecl DecodeSplineFrames(const unsigned char** data, int type, int b, int a, int result,
                                hkVector4* controlPoints);

struct SplineKnots
{
    float k0, k1, k2, k3, k4, k5;
};

// Uses mask bits to spline-evaluate, type-specifically unpack, or load a constant vector.
// @fnv 0x00e33960
void __cdecl DecodeSplineFrame(const unsigned char** data, int a2, float a3, float a4, unsigned char mask, int type,
                               hkVector4* out)
{
    if (mask & 0xF0)
    {
        int a;
        int b;
        SplineKnots knots;
        __declspec(align(16)) hkVector4 controlPoints[4];

        int result = FUN_00e32f10(data, &b, &a, a2, a3, &knots);
        int a_val = a;
        DecodeSplineFrames(data, type, b, a_val, result, controlPoints);
        DAT_011be4d0[a_val](a4, a_val, &knots, controlPoints, out);
        return;
    }

    if (mask & 0x0F)
    {
        unsigned int align = DAT_010eb3b8[type];
        const unsigned char* cur = *data;
        const unsigned char* ptr = (const unsigned char*)(((uintptr_t)cur + align - 1) & ~(align - 1));
        *data = ptr;
        DAT_011be4b8[type](ptr, out);
        *data += DAT_010eb3d0[type];
        return;
    }

    *(__m128*)out = DAT_010c71b0;
}
}  // namespace fnv_00e33960

struct FUN_00e32ec0_Class : public hkaSplineCompressedAnimation
{
    int FUN_00e32ec0() const;
};

// @fnv 0x00e32ec0
int FUN_00e32ec0_Class::FUN_00e32ec0() const
{
    return m_iFrameCount;
}
