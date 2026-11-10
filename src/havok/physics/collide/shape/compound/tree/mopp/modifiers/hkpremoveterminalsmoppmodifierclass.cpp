
// src/havok/physics/collide/shape/compound/tree/mopp/modifiers/hkpremoveterminalsmoppmodifierclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/tree/mopp/modifiers/hkpremoveterminalsmoppmodifierclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkpMoppModifier
{
    virtual ~hkpMoppModifier()
    {}

    hkpMoppModifier* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Destroys the object, calling the destructor and freeing memory when acFlags has bit 0 set.
// @fnv 0x00e00910
// src: EXE 0x00e00910
hkpMoppModifier* hkpMoppModifier::Destroy(unsigned char acFlags)
{
    this->hkpMoppModifier::~hkpMoppModifier();
    if (acFlags & 1)
    {
        operator delete(this);
    }
    return this;
}
