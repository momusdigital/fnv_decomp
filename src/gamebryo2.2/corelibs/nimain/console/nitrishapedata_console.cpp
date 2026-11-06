
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3 operator-(const NiPoint3& pt) const
    {
        return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
    }
    NiPoint3& operator+=(const NiPoint3& pt)
    {
        x += pt.x;
        y += pt.y;
        z += pt.z;
        return *this;
    }
    NiPoint3 Cross(const NiPoint3& pt) const
    {
        return NiPoint3(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
    }
    __declspec(noalias) static void __cdecl UnitizeVector(NiPoint3& kPt);
    static void __cdecl NormalizePoints(NiPoint3* pkPts, unsigned int uiElementCount, unsigned int uiStride);
};

struct NiSharedNormal
{
    unsigned short m_usNormalCount;
    unsigned short* m_pusNormalIndices;
};

class NiTriShapeDataStandIn
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual unsigned short GetActiveVertexQuantity();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual unsigned short GetNumberOfVertices();

    int unk04;
    unsigned short m_usVertices;
    unsigned short unk0a;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    NiPoint3* m_pkVertex;
    NiPoint3* m_pkNormal;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    unsigned short* m_pusTriList;
    NiSharedNormal* m_pkSharedNormalArray;
    unsigned short m_usSharedNormalCount;

    void EnsureNormals(bool bInitialize);
    void FUN_00a67090(unsigned int uiMask);
    void RecalculateNormals();
};

// @fnv 0x00a8ed40
void NiTriShapeDataStandIn::RecalculateNormals()
{
    EnsureNormals(true);
    unsigned short* pusTriList = m_pusTriList;
    unsigned short usTriangleCount = GetNumberOfVertices();
    for (unsigned short i = 0; i < usTriangleCount; i++)
    {
        unsigned short usIndex0 = *pusTriList++;
        unsigned short usIndex1 = *pusTriList++;
        unsigned short usIndex2 = *pusTriList++;
        NiPoint3 kEdge1 = m_pkVertex[usIndex1] - m_pkVertex[usIndex0];
        NiPoint3 kEdge2 = m_pkVertex[usIndex2] - m_pkVertex[usIndex1];
        NiPoint3 kFaceNormal = kEdge1.Cross(kEdge2);
        NiPoint3::UnitizeVector(kFaceNormal);
        m_pkNormal[usIndex0] += kFaceNormal;
        m_pkNormal[usIndex1] += kFaceNormal;
        m_pkNormal[usIndex2] += kFaceNormal;
        if (m_pkSharedNormalArray && m_usSharedNormalCount == m_usVertices)
        {
            unsigned short* pusSharedIndices = m_pkSharedNormalArray[usIndex0].m_pusNormalIndices;
            unsigned short usSharedCount = m_pkSharedNormalArray[usIndex0].m_usNormalCount;
            while (usSharedCount)
            {
                usSharedCount--;
                m_pkNormal[pusSharedIndices[usSharedCount]] += kFaceNormal;
            }
            pusSharedIndices = m_pkSharedNormalArray[usIndex1].m_pusNormalIndices;
            usSharedCount = m_pkSharedNormalArray[usIndex1].m_usNormalCount;
            while (usSharedCount)
            {
                usSharedCount--;
                m_pkNormal[pusSharedIndices[usSharedCount]] += kFaceNormal;
            }
            pusSharedIndices = m_pkSharedNormalArray[usIndex2].m_pusNormalIndices;
            usSharedCount = m_pkSharedNormalArray[usIndex2].m_usNormalCount;
            while (usSharedCount)
            {
                usSharedCount--;
                m_pkNormal[pusSharedIndices[usSharedCount]] += kFaceNormal;
            }
        }
    }
    NiPoint3::NormalizePoints(m_pkNormal, GetActiveVertexQuantity(), sizeof(NiPoint3));
    FUN_00a67090(2);
}
