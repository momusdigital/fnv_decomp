
// src/havok/unplaced/pathingrequestcover.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequestcover.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_006e4320_Class
{
    void FUN_006e4320(float value);
};

// @fnv 0x006e4320
void FUN_006e4320_Class::FUN_006e4320(float value)
{
    *(float*)((char*)this + 0xbc) = value;
}

struct FUN_006e4340_Class
{
    void FUN_006e4340(float value);
};

// @fnv 0x006e4340
void FUN_006e4340_Class::FUN_006e4340(float value)
{
    *(float*)((char*)this + 0xc4) = value;
}

struct FUN_006e4360_class
{
    void SetByteAtOffsetCD(char v);
};
// @fnv 0x006e4360
void FUN_006e4360_class::SetByteAtOffsetCD(char acValue)
{
    ((char*)this)[0xcd] = acValue;
}

struct FUN_006e4380_Class
{
    void __thiscall SetFlagCE(bool value);
};

// @fnv 0x006e4380
void __thiscall FUN_006e4380_Class::SetFlagCE(bool value)
{
    *(char*)((char*)this + 0xce) = (char)value;
}

struct FUN_006e43a0_class
{
    void FUN_006e43a0(int b);
};

// @fnv 0x006e43a0
void FUN_006e43a0_class::FUN_006e43a0(int b)
{
    *(char*)((char*)this + 0xcf) = (char)b;
}

struct FUN_006e43c0_class
{
    void __thiscall SetByteAtOffsetD0(char param);
};

// @fnv 0x006e43c0
void __thiscall FUN_006e43c0_class::SetByteAtOffsetD0(char acValue)
{
    *(char*)((char*)this + 0xd0) = acValue;
}

struct FUN_006e43e0_class
{
    void SetFlag(bool value);
};

// @fnv 0x006e43e0
void FUN_006e43e0_class::SetFlag(bool value)
{
    ((char*)this)[0xd1] = value;
}

struct NiPoint3
{
    float x, y, z;
};

struct PathingRequestCover
{
    unsigned int mPadding[0xd4 / 4];
    NiPoint3 mCover;
    void SetCover(const NiPoint3& point);
};

// Stores the given point into the mCover field of this PathingRequestCover.
// @fnv 0x006e4400
void PathingRequestCover::SetCover(const NiPoint3& point)
{
    mCover = point;
}

// @fnv 0x006e4630
unsigned char* FUN_006e4630(int aiBase, unsigned short ausIndex, unsigned char aucOffset)
{
    return (unsigned char*)((aiBase << 0x10) + ausIndex * 4 + aucOffset);
}

struct FUN_006e4820_class
{
    bool FUN_006e4820();
};

// @fnv 0x006e4820
bool FUN_006e4820_class::FUN_006e4820()
{
    return *(const unsigned char*)((const char*)this + 0x4c) == 2;
}

struct FUN_006e4500_class
{
    void FUN_006e4500(unsigned short a, unsigned short b, unsigned short c, char e, char f, char g);
};

// @fnv 0x006e4500
void FUN_006e4500_class::FUN_006e4500(unsigned short ausValue, unsigned short b, unsigned short c, char e, char f,
                                      char g)
{
    ((char*)this)[0x4c] = (char)ausValue;
    ((char*)this)[0x4d] = (char)(ausValue >= b ? 1 : 0);
    ((char*)this)[0x4e] = (char)(ausValue > c ? 1 : 0);
    ((char*)this)[0x4f] = e;
    ((char*)this)[0x50] = f;
    ((char*)this)[0x51] = g;
    ((char*)this)[0x52] = 0;
}

struct PathingLocation
{
    PathingLocation& operator=(const PathingLocation&);
    char pad[0x28];
};
struct FUN_006e4430_class : public PathingLocation
{
    NiPoint3 a, b, c;
    unsigned char f04c, f04d, f04e, f04f, f050, f051, f052;
    FUN_006e4430_class& operator=(const FUN_006e4430_class& src);
};
// Copies the base PathingLocation, three NiPoint3 values and seven bytes from src into this object and returns *this.
// @fnv 0x006e4430
FUN_006e4430_class& FUN_006e4430_class::operator=(const FUN_006e4430_class& src)
{
    PathingLocation::operator=(src);
    a = src.a;
    b = src.b;
    c = src.c;
    f04c = src.f04c;
    f04d = src.f04d;
    f04e = src.f04e;
    f04f = src.f04f;
    f050 = src.f050;
    f051 = src.f051;
    f052 = src.f052;
    return *this;
}

struct BGSSaveFormBuffer
{
    void SaveData(void* data, int size, int);
};
struct FUN_006def40_Class
{
    void FUN_006def40(BGSSaveFormBuffer* buffer);
};
struct PathingCoverLocation
{
    void SaveToBuffer(BGSSaveFormBuffer* buffer);
};
// Calls the base save routine, then writes three 12-byte blocks and seven single bytes from offsets 0x28 through 0x52 into the buffer.
// @fnv 0x006e48a0
void PathingCoverLocation::SaveToBuffer(BGSSaveFormBuffer* buffer)
{
    ((FUN_006def40_Class*)this)->FUN_006def40(buffer);
    buffer->SaveData((char*)this + 0x28, 12, 0);
    buffer->SaveData((char*)this + 0x34, 12, 0);
    buffer->SaveData((char*)this + 0x40, 12, 0);
    buffer->SaveData((char*)this + 0x4c, 1, 0);
    buffer->SaveData((char*)this + 0x4d, 1, 0);
    buffer->SaveData((char*)this + 0x4e, 1, 0);
    buffer->SaveData((char*)this + 0x4f, 1, 0);
    buffer->SaveData((char*)this + 0x50, 1, 0);
    buffer->SaveData((char*)this + 0x51, 1, 0);
    buffer->SaveData((char*)this + 0x52, 1, 0);
}

namespace fnv_006e4980 {
struct BGSLoadGameBuffer
{
    void ReadTypedData(void*, unsigned int);
};
struct PathingLocation
{
    void Load(BGSLoadGameBuffer*);
};
struct PathingCoverLocation
{
    PathingLocation base;
    void Load(BGSLoadGameBuffer* buffer);
};
// @fnv 0x006e4980
void PathingCoverLocation::Load(BGSLoadGameBuffer* buffer)
{
    base.Load(buffer);
    buffer->ReadTypedData((char*)this + 0x28, 0xc);
    buffer->ReadTypedData((char*)this + 0x34, 0xc);
    buffer->ReadTypedData((char*)this + 0x40, 0xc);
    buffer->ReadTypedData((char*)this + 0x4c, 1);
    buffer->ReadTypedData((char*)this + 0x4d, 1);
    buffer->ReadTypedData((char*)this + 0x4e, 1);
    buffer->ReadTypedData((char*)this + 0x4f, 1);
    buffer->ReadTypedData((char*)this + 0x50, 1);
    buffer->ReadTypedData((char*)this + 0x51, 1);
    buffer->ReadTypedData((char*)this + 0x52, 1);
}
}  // namespace fnv_006e4980

struct CoverPoint3
{
    float x;
    float y;
    float z;
};

struct CoverPathingRequest
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
    int unkA8;
    int unkAC;

    void CopyTo(CoverPathingRequest* apRequest);
};

struct CoverPathingRequestCover : CoverPathingRequest
{
    CoverPoint3 m_kCoverPoint;
    float m_fUnkBC;
    float m_fUnkC0;
    float m_fUnkC4;
    void* m_pUnkC8;
    unsigned char unkCC;
    unsigned char m_cUnkCD;
    bool m_bUnkCE;
    unsigned char m_ucUnkCF;
    unsigned char m_cUnkD0;
    bool m_bUnkD1;
    unsigned char unkD2;
    unsigned char unkD3;
    CoverPoint3 m_kThreatPoint;

    void SetCoverPoint(const CoverPoint3& arPoint);
    void SetUnkC0(float afValue);
    void SetUnkBC(float afValue);
    void SetUnkC4(float afValue);
    void SetUnkC8(void* apValue);
    void SetUnkCD(char acValue);
    void SetUnkCE(bool abValue);
    void SetUnkCF(int aiValue);
    void SetUnkD0(char acValue);
    void SetUnkD1(bool abValue);
    void SetThreatPoint(const CoverPoint3& arPoint);

    void CopyToCover(CoverPathingRequest* apRequest);
};

// Copies the base request into apRequest and then sets its cover point, unkBC/C0/C4/C8/CD/CE/CF/D0/D1 values and threat point from this object.
// @fnv 0x006e4220
void CoverPathingRequestCover::CopyToCover(CoverPathingRequest* apRequest)
{
    CoverPathingRequestCover* pCover = (CoverPathingRequestCover*)apRequest;
    CoverPathingRequest::CopyTo(pCover);
    pCover->SetCoverPoint(m_kCoverPoint);
    pCover->SetUnkC0(m_fUnkC0);
    pCover->SetUnkBC(m_fUnkBC);
    pCover->SetUnkC4(m_fUnkC4);
    pCover->SetUnkC8(m_pUnkC8);
    pCover->SetUnkCD(m_cUnkCD);
    pCover->SetUnkCE(m_bUnkCE);
    pCover->SetUnkCF(m_ucUnkCF);
    pCover->SetUnkD0(m_cUnkD0);
    pCover->SetUnkD1(m_bUnkD1);
    pCover->SetThreatPoint(m_kThreatPoint);
}

class NavMesh
{
  public:
    bool GetObstacleForTriangle(unsigned short a);
};

class NavMeshPtr
{
  public:
    NavMesh* m_p;
    NavMeshPtr();
    ~NavMeshPtr();
    NavMesh* operator->() const;
};

class PathingSolution
{
  public:
    char pad[0x70];
    int unk70;
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* p);
    ~NiPointer();
    T* operator->() const;
};

struct FUN_006e4650_class
{
    bool FUN_006dd610(NavMeshPtr& nm);
    unsigned short GetShortValueAtOffset24(NiPointer<PathingSolution>& sol);
    bool CheckDynamicCoverValid(int arg);
};

// @fnv 0x006e4650
bool FUN_006e4650_class::CheckDynamicCoverValid(int aiValue)
{
    NavMeshPtr nm;
    if (FUN_006dd610(nm))
    {
        NiPointer<PathingSolution> sol(0);
        if (nm->GetObstacleForTriangle(GetShortValueAtOffset24(sol)) && sol->unk70 == aiValue)
            return true;
    }
    return false;
}

struct S_006e4570_NavMesh : NavMesh
{
    int FUN_0084e3a0();
};

struct S_006e4570
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
    unsigned char unk50;
    unsigned char unk51;

    bool FUN_006dd640(NavMeshPtr& navMesh, unsigned short& triangleIndex);
    unsigned char* FUN_006e4570();
};

// Looks up a navmesh triangle via FUN_006dd640 and returns FUN_006e4630's result for that triangle and unk51, or null if lookup fails.
// @fnv 0x006e4570
unsigned char* S_006e4570::FUN_006e4570()
{
    NavMeshPtr navMesh;
    unsigned short triangleIndexA = 0;
    if (FUN_006dd640(navMesh, triangleIndexA))
    {
        return FUN_006e4630(((S_006e4570_NavMesh*)navMesh.operator->())->FUN_0084e3a0(), triangleIndexA, unk51);
    }
    return 0;
}

struct S_006e4740
{
    bool FUN_006dd610(NavMeshPtr& nm);
    unsigned short GetShortValueAtOffset24(NiPointer<PathingSolution>& sol);
    int FUN_006e4740();
};
// @fnv 0x006e4740
int S_006e4740::FUN_006e4740()
{
    NavMeshPtr nm;
    if (FUN_006dd610(nm))
    {
        NiPointer<PathingSolution> sol(0);
        if (nm->GetObstacleForTriangle(GetShortValueAtOffset24(sol)))
        {
            return sol->unk70;
        }
    }
    return -1;
}

struct PointCalc : NiPoint3
{
    PointCalc FUN_00439ef0(const NiPoint3& other) const;
    double FUN_004a7290() const;
};
struct DistanceCheck
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    PointCalc firstPoint;
    PointCalc secondPoint;
    bool FUN_006e4840(const NiPoint3& point);
};
// @fnv 0x006e4840
bool DistanceCheck::FUN_006e4840(const NiPoint3& point)
{
    PointCalc vecA = firstPoint.FUN_00439ef0(point);
    PointCalc vecB = secondPoint.FUN_00439ef0(point);
    if (vecA.FUN_004a7290() < vecB.FUN_004a7290())
        return true;
    return false;
}

typedef unsigned int E41E0size_t;

struct FUN_006e41e0
{
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
    int unkE0;
    int unkE4;
    int unkE8;

    FUN_006e41e0();
    virtual ~FUN_006e41e0();

    static void operator delete(void* pvMem, E41E0size_t uiSize);
};

// @fnv 0x006e41e0
FUN_006e41e0::FUN_006e41e0()
{}
