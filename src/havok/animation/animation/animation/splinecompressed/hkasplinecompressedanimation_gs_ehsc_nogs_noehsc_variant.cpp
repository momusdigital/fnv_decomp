
// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkaSplineCompressedAnimation.h"
struct FUN_00e33330_Class
{
    void* __thiscall FUN_00e33330();
};
extern bool DAT_0126efb8;
void __cdecl FUN_00e63c60(bool*);
int __cdecl GetIndexedValueWithOffset(int offset, const int* values, int index, int count);
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
typedef void(__cdecl* SplineDecodeFn)(int, void*);
extern int DAT_010eb3b8[];
extern int DAT_010eb3d0[];
extern SplineDecodeFn DAT_011be4b8[];
void __cdecl DecodeSplineFrames(int* cursor, int type, int lastFrame, int firstFrame, int endFrame, void* output);
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
struct hkVector4E34
{
    float x, y, z, w;
};
void __cdecl BlendVector4(unsigned char mask, const hkVector4E34& a, const hkVector4E34& b, hkVector4E34& out);
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
int __cdecl FUN_00e32f10(const hkUint8*& pDataInOut, int& iNOut, int& iPOut, int iU, hkReal fScale, hkReal* pfU);
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
void FUN_00e33f90(unsigned int frameIndex, float delta, unsigned int maxNumTransformTracks,
                  hkQsTransform* transformsOut, unsigned int maxNumFloatTracks, float* floatsOut,
                  const SplineDataChunk* dataChunks, int numDataChunks);
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
#include <xmmintrin.h>

class hkBoolE330
{
  public:
    char m_cBooleanValue;
    hkBoolE330()
    {}
    hkBoolE330(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class hkOstream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;
    hkOstream(char* buf, int bufSize);     // FUN_00cb1600
    ~hkOstream();                          // FUN_00cc00e0
    hkOstream& operator<<(const char* s);  // FUN_00cc01c0
};

class hkError
{
  public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual int message(int type, int id, const char* description, const char* file, int line);
};
extern hkError* DAT_01268360;

enum QuantizationType
{
    BITS8 = 0,
    BITS16 = 1
};
enum RotationQuantizationType
{
    POLAR32 = 0,
    THREECOMP40 = 1,
    THREECOMP48 = 2,
    THREECOMP24 = 3,
    STRAIGHT16 = 4,
    UNCOMPRESSED = 5
};

__declspec(noinline) hkBoolE330 StoreBoolFlag(QuantizationType type)
{
    return type == BITS8 || type == BITS16;
}

__declspec(noinline) hkBoolE330 IsValidMode(RotationQuantizationType type)
{
    return type == POLAR32 || type == THREECOMP40 || type == THREECOMP48 || type == THREECOMP24 || type == STRAIGHT16 ||
           type == UNCOMPRESSED;
}

__declspec(noinline) hkReal FUN_00e32ea0(QuantizationType type)
{
    switch (type)
    {
    case BITS8:
        return 0.0078125f;
    case BITS16:
        return 3.0517578125e-05f;
    }
    return 0.0f;
}

double FUN_00e32e50(RotationQuantizationType type);

struct TrackCompressionParams
{
    hkReal m_fRotationTolerance;
    hkReal m_fTranslationTolerance;
    hkReal m_fScaleTolerance;
    hkReal m_fFloatingTolerance;
    int m_iRotationDegree;
    int m_iTranslationDegree;
    hkUint8 m_eRotationQuantizationType;
    hkUint8 m_eTranslationQuantizationType;
    hkUint8 m_eScaleQuantizationType;
    hkUint8 m_eFloatQuantizationType;

    hkBoolE330 FUN_00e330b0() const;
};

// @fnv 0x00e330b0
hkBoolE330 TrackCompressionParams::FUN_00e330b0() const
{
    hkBoolE330 ok = StoreBoolFlag((QuantizationType)m_eTranslationQuantizationType) &&
                    IsValidMode((RotationQuantizationType)m_eRotationQuantizationType) &&
                    StoreBoolFlag((QuantizationType)m_eScaleQuantizationType) &&
                    StoreBoolFlag((QuantizationType)m_eFloatQuantizationType);

    hkBoolE330 tolerancesOk = m_fTranslationTolerance >= 0.0f && m_fRotationTolerance >= 0.0f &&
                              m_fScaleTolerance >= 0.0f && m_fFloatingTolerance >= 0.0f;

    if (m_fTranslationTolerance < FUN_00e32ea0((QuantizationType)m_eTranslationQuantizationType))
    {
        char assertBuf[512];
        hkOstream ostr(assertBuf, sizeof(assertBuf));
        ostr
            << "Quantization may be limiting translation quality.  If artifacts are visible, try increasing the number of translation quantization bits.";
        DAT_01268360->message(1, 0xabba5a61, assertBuf,
                              ".\\Animation\\SplineCompressed\\hkaSplineCompressedAnimation.cpp", 79);
    }

    if (m_fScaleTolerance < FUN_00e32ea0((QuantizationType)m_eScaleQuantizationType))
    {
        char assertBuf[512];
        hkOstream ostr(assertBuf, sizeof(assertBuf));
        ostr
            << "Quantization may be limiting scale quality.  If artifacts are visible, try increasing the number of scale quantization bits.";
        DAT_01268360->message(1, 0xabba5a61, assertBuf,
                              ".\\Animation\\SplineCompressed\\hkaSplineCompressedAnimation.cpp", 84);
    }

    if (m_fFloatingTolerance < FUN_00e32ea0((QuantizationType)m_eFloatQuantizationType))
    {
        char assertBuf[512];
        hkOstream ostr(assertBuf, sizeof(assertBuf));
        ostr
            << "Quantization may be limiting float quality.  If artifacts are visible, try increasing the number of float quantization bits.";
        DAT_01268360->message(1, 0xabba5a61, assertBuf,
                              ".\\Animation\\SplineCompressed\\hkaSplineCompressedAnimation.cpp", 89);
    }

    RotationQuantizationType rq = (RotationQuantizationType)m_eRotationQuantizationType;
    if (m_fRotationTolerance < FUN_00e32e50(rq) * 0.16260161995887756)
    {
        char assertBuf[512];
        hkOstream ostr(assertBuf, sizeof(assertBuf));
        ostr
            << "Quantization may be limiting rotation quality.  If artifacts are visible, try increasing the number of rotation quantization bits.";
        DAT_01268360->message(1, 0xabba5a61, assertBuf,
                              ".\\Animation\\SplineCompressed\\hkaSplineCompressedAnimation.cpp", 100);
    }

    return ok && tolerancesOk;
}
