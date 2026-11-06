
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

class NiPoint3_S
{
  public:
    float x, y, z;
    NiPoint3_S()
    {}
    NiPoint3_S(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}
    NiPoint3_S operator-(const NiPoint3_S& pt) const
    {
        return NiPoint3_S(x - pt.x, y - pt.y, z - pt.z);
    }
    NiPoint3_S& operator+=(const NiPoint3_S& pt)
    {
        x += pt.x;
        y += pt.y;
        z += pt.z;
        return *this;
    }
    NiPoint3_S Cross(const NiPoint3_S& pt) const
    {
        return NiPoint3_S(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
    }
};

__declspec(noalias) void UnitizeVector(NiPoint3_S& kPt);
void NormalizePoints(NiPoint3_S* pkV, unsigned int uiElementCount, unsigned int uiStride);

class S_00a8ab40_NiTriStripsData
{
  public:
    void* vtbl;  // 0x00
    int unk04;
    unsigned short m_usVertices;  // 0x08
    unsigned short unk0A;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    NiPoint3_S* m_pkVertex;  // 0x20
    NiPoint3_S* m_pkNormal;  // 0x24
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    unsigned short m_usStrips;  // 0x44
    unsigned short unk46;
    unsigned short* m_pusStripLengths;  // 0x48
    unsigned short* m_pusStripLists;    // 0x4c

    void EnsureNormals(int aiNumVertices);
    void FUN_00a67090(int aiNumVertices);
    void GenerateNormals();
};

// @fnv 0x00a8ab40
void S_00a8ab40_NiTriStripsData::GenerateNormals()
{
    EnsureNormals(1);

    unsigned short* pusStripList = m_pusStripLists;
    for (unsigned short usStrip = 0; usStrip < m_usStrips; usStrip++)
    {
        for (unsigned short usIndex = 2; usIndex < m_pusStripLengths[usStrip]; usIndex++)
        {
            unsigned short usIndex0, usIndex1, usIndex2;
            if (usIndex % 2 == 0)
            {
                usIndex0 = pusStripList[usIndex - 2];
                usIndex1 = pusStripList[usIndex - 1];
                usIndex2 = pusStripList[usIndex];
            }
            else
            {
                usIndex0 = pusStripList[usIndex - 2];
                usIndex1 = pusStripList[usIndex];
                usIndex2 = pusStripList[usIndex - 1];
            }

            if (usIndex0 == usIndex1 || usIndex1 == usIndex2 || usIndex2 == usIndex0)
                continue;

            const NiPoint3_S& kVertex0 = m_pkVertex[usIndex0];
            const NiPoint3_S& kVertex1 = m_pkVertex[usIndex1];
            const NiPoint3_S& kVertex2 = m_pkVertex[usIndex2];
            NiPoint3_S kEdge1 = kVertex1 - kVertex0;
            NiPoint3_S kEdge2 = kVertex2 - kVertex1;
            NiPoint3_S kNormal = kEdge1.Cross(kEdge2);
            UnitizeVector(kNormal);

            m_pkNormal[usIndex0] += kNormal;
            m_pkNormal[usIndex1] += kNormal;
            m_pkNormal[usIndex2] += kNormal;
        }
        pusStripList += m_pusStripLengths[usStrip];
    }

    NormalizePoints(m_pkNormal, m_usVertices, sizeof(NiPoint3_S));
    FUN_00a67090(2);
}
