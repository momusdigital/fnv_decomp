
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiPoint3
{
    float x, y, z;
};

struct BSAudioListener
{
    int m_unk00;
    NiPoint3 m_vContactPosition;
    NiPoint3& FUN_00aeaad0();
};

// @fnv 0x00aeaad0
NiPoint3& BSAudioListener::FUN_00aeaad0()
{
    return m_vContactPosition;
}

namespace fnv_00aeaaf0 {
struct NiPoint3
{
};

struct BSAudioListener
{
    NiPoint3* GetFrontOrientation();
};

// @fnv 0x00aeaaf0
NiPoint3* BSAudioListener::GetFrontOrientation()
{
    return reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x10);
}
}  // namespace fnv_00aeaaf0

namespace fnv_00aeab10 {
struct NiPoint3
{
    float x, y, z;
};

struct BSAudioListener
{
    NiPoint3& GetTopOrientation();
};

// @fnv 0x00aeab10
NiPoint3& BSAudioListener::GetTopOrientation()
{
    return *(NiPoint3*)((char*)this + 0x1c);
}
}  // namespace fnv_00aeab10

namespace fnv_00aeab30 {
struct BSAudioListener
{
    char pad[0x40];
    float m_fDistanceScale;
    void SetGain(float afGain);
};

// @fnv 0x00aeab30
void BSAudioListener::SetGain(float afGain)
{
    m_fDistanceScale = afGain;
}
}  // namespace fnv_00aeab30

namespace fnv_00aeab90 {
struct BSAudioListener
{
    float m_fDopplerScale;
    void SetRolloffFactor(float afRolloffFactor);
};

// @fnv 0x00aeab90
void BSAudioListener::SetRolloffFactor(float afRolloffFactor)
{
    *(float*)((char*)this + 0x3c) = afRolloffFactor;
}
}  // namespace fnv_00aeab90

struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern int DAT_010a3bb4;
struct BSAudioListenerShell
{
    char _pad[0x44];
    unsigned int _m44;
    void* Destroy(unsigned int);
};
// Sets the vtable pointer, clears _m44, and deallocates this when a1 has bit 0 set; returns this.
// @fnv 0x00aeabb0
void* BSAudioListenerShell::Destroy(unsigned int auiFlags)
{
    *(int*)this = (int)&DAT_010a3bb4;
    _m44 = 0;
    if (auiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
