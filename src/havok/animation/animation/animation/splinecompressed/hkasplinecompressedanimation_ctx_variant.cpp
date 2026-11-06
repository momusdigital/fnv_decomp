
// hkasplinecompressedanimation_ctx_variant.cpp: context variant of src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkaSplineCompressedAnimation.h"
struct FUN_00e33330_Class {
    void* __thiscall FUN_00e33330();
};
extern bool DAT_0126efb8;
void __cdecl FUN_00e63c60(bool *);
int __cdecl GetIndexedValueWithOffset(int offset, const int *values, int index, int count);
int __stdcall getNumDataChunks(int a1, int a2);
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
typedef void (__cdecl *SplineDecodeFn)(int, void*);
extern int DAT_010eb3b8[];
extern int DAT_010eb3d0[];
extern SplineDecodeFn DAT_011be4b8[];
void __cdecl DecodeSplineFrames(int* cursor,int type,int lastFrame,int firstFrame,int endFrame,void* output);
template <class T>
class hkArrayE333 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const { return m_iElementCount; }
    T* begin() const { return m_data; }
};
struct hkaAnimationDataChunkE333 {
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
class hkaSplineCompressedAnimationE333 {
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

    void GetBlockAndTime(unsigned int frame, float delta, int& blockOut, float& blockTimeOut, unsigned char& quantizedTimeOut) const throw();
    void GetDataChunks(unsigned int frame, float delta, hkaAnimationDataChunkE333* dataChunks, int numDataChunks) const throw();
};
typedef char fnv_check_e33350[(sizeof(hkaSplineCompressedAnimationE333) == 0x90) ? 1 : -1];
struct hkMathE334 {
    static int max2(int x, int y) { return x > y ? x : y; }
};
class FUN_00e33400_cls {
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
template <typename T>
inline T max2E347(T a, T b) { return a > b ? a : b; }
template <typename T>
inline T min2E347(T a, T b) { return a < b ? a : b; }
class hkaSplineCompressedAnimationE347 {
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

    void GetBlockAndTime(unsigned int frame, float delta, int& blockOut, float& blockTimeOut, unsigned char& quantizedTimeOut) const throw();
};
void __cdecl DecodeSplineFrame(const unsigned char*& dataInOut, int quantization, float frameDuration, float time, int numItems, void* out, int stride);
class hkaSplineAnimE33 {
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

    void ExtractFrame(float time, int quantization, int numItems, void* out, const unsigned char*& dataInOut, int stride);
};
struct hkVector4E34 {
    float x, y, z, w;
};
void __cdecl BlendVector4(unsigned char mask, const hkVector4E34& a, const hkVector4E34& b, hkVector4E34& out);
__declspec(noinline) int __cdecl FindKeyInterval(int n, int p, int u, const hkUint8* knots)
{
    hkUint8 value = (hkUint8)u;
    if (value >= knots[n + 1]) return n;
    if (value <= knots[0]) return p;
    int low = p;
    int high = n + 1;
    int mid = (low + high) / 2;
    while (value < knots[mid] || value >= knots[mid + 1]) {
        if (value < knots[mid]) high = mid;
        else low = mid;
        mid = (low + high) / 2;
    }
    return mid;
}
int __cdecl FUN_00e32f10(const hkUint8*& pDataInOut, int& iNOut, int& iPOut, int iU, hkReal fScale, hkReal* pfU);
#include <xmmintrin.h>
struct __declspec(align(16)) AlignedVector4 {float x,y,z,w;};
struct ResultArg { AlignedVector4* ptr; AlignedVector4* get() const {return ptr;} };
extern const AlignedVector4 DAT_01268700;
struct FUN_00e33e10_Class:hkaSplineCompressedAnimation{
 void EvaluateSpline(float time,int track,int enabled,int block,unsigned int*cursor,ResultArg result);
};
void __cdecl FUN_00e33a30(unsigned int*,int,float,float,int,int,const AlignedVector4*,AlignedVector4*);
struct SplineDataChunk {
    const char* m_data;
    int m_iElementCount;
    unsigned char m_offset;
};
struct SplineAnimSampler : public hkaSplineCompressedAnimation {
    void GetBlockAndTime(unsigned int frame, float delta, int& blockOut, float& blockTimeOut, unsigned char& quantizedTimeOut) const;
    void EvaluateSpline(float time, unsigned char quantizedTime, unsigned char mask, int quantization, const unsigned char** data, hkVector4* out) const;
    void ExtractFrame(float time, unsigned char quantizedTime, unsigned char mask, int quantization, const unsigned char** data, hkQuaternion* out) const;
    void FUN_00e33e90(float time, unsigned char quantizedTime, unsigned char mask, int quantization, const unsigned char** data, hkVector4* out) const;
    void FUN_00e33f10(float time, unsigned char quantizedTime, unsigned char mask, int quantization, const unsigned char** data, float* out) const;
};
void FUN_00e33f90(unsigned int frameIndex, float delta, unsigned int maxNumTransformTracks, hkQsTransform* transformsOut, unsigned int maxNumFloatTracks, float* floatsOut, const SplineDataChunk* dataChunks, int numDataChunks);
template <class T> inline T& hkArrayAtE344(hkArray<T>& a, int i) { return a.m_data[i]; }
template <class T> inline const T& hkArrayAtE344(const hkArray<T>& a, int i) { return a.m_data[i]; }
const hkUint8* __cdecl GetIndexedValueWithOffset(const hkUint8* base, const hkUint32* offsets, hkUint32 block, hkUint32 offset);
class hkaSplineCompressedAnimationE344 : public hkaSplineCompressedAnimation {
public:
    __declspec(noalias) void FUN_00e2f7c0(hkReal time, hkUint32& frameOut, hkReal& deltaOut) const;
    __declspec(noalias) void GetBlockAndTime(hkUint32 frame, hkReal delta, hkUint32& blockOut, hkReal& blockTimeOut, hkUint8& quantizedTimeOut) const;
    void FUN_00e33f10(hkReal blockTime, hkUint8 quantizedTime, hkUint8 mask, int quantization, const hkUint8*& dataInOut, hkReal& out) const;
    void sampleIndividualFloatTracks(hkReal time, const hkInt16* tracks, hkUint32 numTracks, hkReal* floatTracksOut) const;
};
extern void* __cdecl FUN_00c85750(void);
extern void __cdecl FUN_00dfb5a0(int value);
extern void __cdecl FUN_00c905b0(void);
extern int DAT_010de0ec;
extern int DAT_0102e388;
struct FUN_00e345a0_Track {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(unsigned int value, unsigned int size);
};
struct FUN_00e345a0_Manager {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct FUN_00dfb720 { virtual ~FUN_00dfb720(); };
class FUN_00e345a0_Obj : FUN_00dfb720 {
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
#include <xmmintrin.h>
struct FUN_00e32ec0_Class : public hkaSplineCompressedAnimation {
    int FUN_00e32ec0() const;
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern "C" void _ReadWriteBarrier(void);

struct S00e340e0_Cmd { const char* name; unsigned int ticks; unsigned int extra; };
struct S00e340e0_Mon {
    char* m_kRayStart;
    S00e340e0_Cmd* m_kRayEnd;
    char* m_pRayCursor;
    S00e340e0_Cmd* m_pCurrentCommand;
};

static __forceinline void S00e340e0_timer(const char* name)
{
    S00e340e0_Mon* mon = (S00e340e0_Mon*)TlsGetValue(DAT_0126835c);
    S00e340e0_Cmd* e = mon->m_kRayEnd;
    if (e < mon->m_pCurrentCommand)
    {
        e->name = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        e->ticks = ticks;
        mon->m_kRayEnd = e + 1;
    }
}

int __stdcall S00e340e0_vnum(const void* self);
int __stdcall S00e340e0_read(const unsigned char* p, float t, unsigned char qt, unsigned char q, int type, void* out);

struct S00e340e0_Anim {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iNumTransformTracks;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int m_iMaskAndQuantizationSize;
    float unk38;
    float unk3C;
    float unk40;
    int* m_kFirstUInt32Array;
    int unk48;
    int unk4C;
    int* m_kFloatBlockOffsets;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    unsigned char* m_data;

    __declspec(noinline) void FUN_00e2f7c0(float time, unsigned int& frame, float& delta) const;
    __declspec(noinline) void GetBlockAndTime(unsigned int frame, float delta, int& blockOut, float& blockTimeOut, unsigned char& quantizedTimeOut) const;
    __declspec(noinline) void EvaluateSpline(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, hkVector4& out) const;
    __declspec(noinline) void ExtractFrame(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, hkQuaternion& out) const;
    __declspec(noinline) void FUN_00e33e90(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, hkVector4& out) const;
    __declspec(noinline) void FUN_00e33f10(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, float& out) const;
    void sampleAtFrame(unsigned int frame, float delta, unsigned int maxNumTransformTracks, hkQsTransform* transformTracksOut, unsigned int maxNumFloatTracks, float* floatTracksOut) const;
    void samplePartialTracks(float time, unsigned int maxNumTransformTracks, hkQsTransform* transformTracksOut, unsigned int maxNumFloatTracks, float* floatTracksOut, void* cache) const;
};


typedef int (__thiscall S00e340e0_Anim::*S00e340e0_pv)() const;
void S00e340e0_Anim::FUN_00e2f7c0(float time, unsigned int& frameOut, float& deltaOut) const
{
    const unsigned int maxFrameIndex = S00e340e0_vnum(this) - 1;
    const float frameFloat = (time / *(const float*)&unk0C) * maxFrameIndex;
    frameOut = (unsigned int)frameFloat;
    if (frameOut > maxFrameIndex - 1) { frameOut = maxFrameIndex - 1; deltaOut = 1.0f; return; }
    deltaOut = frameFloat - frameOut;
}
void S00e340e0_Anim::GetBlockAndTime(unsigned int frame, float delta, int& blockOut, float& blockTimeOut, unsigned char& quantizedTimeOut) const
{
    blockOut = frame / (unk30 - 1);
    blockOut = blockOut > 0 ? blockOut : 0;
    blockOut = blockOut < unk2C - 1 ? blockOut : unk2C - 1;
    const unsigned int first = blockOut * (unk30 - 1);
    const float realFrame = (float)(frame - first) + delta;
    blockTimeOut = realFrame * unk40;
    quantizedTimeOut = (unsigned char)((blockTimeOut * unk3C) * (unk30 - 1));
}
void S00e340e0_Anim::EvaluateSpline(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, hkVector4& out) const
{ data += S00e340e0_read(data, t, qt, q, type, &out); }
void S00e340e0_Anim::ExtractFrame(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, hkQuaternion& out) const
{ data += S00e340e0_read(data, t, qt, q, type, &out); }
void S00e340e0_Anim::FUN_00e33e90(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, hkVector4& out) const
{ data += S00e340e0_read(data, t, qt, q, type, &out); }
void S00e340e0_Anim::FUN_00e33f10(float t, unsigned char qt, unsigned char q, int type, const unsigned char*& data, float& out) const
{ data += S00e340e0_read(data, t, qt, q, type, &out); }

// @fnv 0x00e340e0
void S00e340e0_Anim::samplePartialTracks(float time, unsigned int maxNumTransformTracks, hkQsTransform* transformTracksOut, unsigned int maxNumFloatTracks, float* floatTracksOut, void* cache) const
{
    S00e340e0_timer("TtSampleSpline");
    unsigned int frame;
    float delta;
    FUN_00e2f7c0(time, frame, delta);
    int block;
    float blockTime;
    unsigned char quantizedTime;
    GetBlockAndTime(frame, delta, block, blockTime, quantizedTime);
    const int* offsets = m_kFirstUInt32Array;
    int base = (int)m_data;
    const unsigned char* transformData = (const unsigned char*)GetIndexedValueWithOffset(base, offsets, block, m_iMaskAndQuantizationSize);
    const int* maskOffsets = m_kFirstUInt32Array;
    int maskBase = (int)m_data;
    const unsigned char* maskPtr = (const unsigned char*)GetIndexedValueWithOffset(maskBase, maskOffsets, block, 0x80000000);
    if (!transformData || !maskPtr) { S00e340e0_timer("Et"); return; }
    for (unsigned int i = 0; i < maxNumTransformTracks; i++)
    {
        unsigned char mask = *maskPtr++;
        EvaluateSpline(blockTime, quantizedTime, *maskPtr++, mask & 3, transformData, transformTracksOut[i].m_vTranslation);
        ExtractFrame(blockTime, quantizedTime, *maskPtr++, (mask >> 2) & 0xf, transformData, transformTracksOut[i].m_rotation);
        FUN_00e33e90(blockTime, quantizedTime, *maskPtr++, mask >> 6, transformData, transformTracksOut[i].m_vScale);
    }
    const unsigned char* floatData = m_data + m_kFloatBlockOffsets[block] + m_kFirstUInt32Array[block];
    const unsigned char* floatMask = m_data + m_iNumTransformTracks * 4 + m_kFirstUInt32Array[block];
    for (unsigned int j = 0; j < maxNumFloatTracks; j++)
    {
        unsigned char m = *floatMask++;
        FUN_00e33f10(blockTime, quantizedTime, m & 0xf9, (m >> 1) & 3, floatData, floatTracksOut[j]);
    }
    S00e340e0_timer("Et");
}
