#pragma once

#include "hkpHeightFieldShape.h"
#include "hkVector4.h"

class hkpPlaneShape : public hkpHeightFieldShape
{
public:
    virtual void SetMapName();

    hkVector4 m_kTriangleNormal;
    hkVector4 m_kAabbCenter;
    hkVector4 m_kAabbHalfExtents;
};
