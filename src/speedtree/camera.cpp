
// src/speedtree/camera.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/camera.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Vector3D
{
    float x, y, z;
};
struct CIdvCamera
{
    int m_auiShapeKeys;
    Vector3D m_kTranslation;
    CIdvCamera& CopyCameraTranslation(const CIdvCamera& other);
};
// @fnv 0x00b3f0c0
CIdvCamera& CIdvCamera::CopyCameraTranslation(const CIdvCamera& other)
{
    if (&other != this)
    {
        m_kTranslation = other.m_kTranslation;
    }
    return *this;
}
