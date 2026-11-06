// src/havok/physics/collide/query/collector/bodypaircollector/hkpflagcdbodypaircollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/bodypaircollector/hkpflagcdbodypaircollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct DAFc80
{
    int unk00;
    unsigned char unk04;
    void addCdBodyPair(int a, int b);
};
// @fnv 0x00dafc80
void DAFc80::addCdBodyPair(int a, int b)
{
    unk04 = 1;
}

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750();

struct FUN_00d34900
{
    int m_i04;

    FUN_00d34900();

// @fnv 0x00d34900
    virtual ~FUN_00d34900()
    {}

    static void operator delete(void* apMemory)
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(apMemory, sizeof(FUN_00d34900));
    }
};

FUN_00d34900::FUN_00d34900()
{
    m_i04 = 0;
}
