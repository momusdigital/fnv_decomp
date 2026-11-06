// fallout_shared/extradatacell.cpp: ExtraNorthRotation, ExtraCell3D, ExtraHavok, ExtraCellImpactSwap and more (28 functions)

#include "extradatacell_decls.h"
// Constructs an ExtraNorthRotation, setting its vtable and initializing its float value to 0.0f.
// @fnv 0x0040f680
ExtraNorthRotation::ExtraNorthRotation() : BSExtraData(0x43)
{
    m_ppVirtualMethodTable = ExtraNorthRotation_vtable;
    m_fNorthRotation = 0.0f;
}

struct BE
{
    void* pVftable;
    BE(unsigned char);
};

struct FUN_0040ef00_shell : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040ef00_shell(void* aField);
};

extern void* DAT_01014228;

// Sets the vftable pointer to DAT_01014228 and stores aField in pField.
// @fnv 0x0040ef00
FUN_0040ef00_shell::FUN_0040ef00_shell(void* aField) : BE(4)
{
    *reinterpret_cast<void**>(this) = &DAT_01014228;
    pField = aField;
}

extern void* DAT_01014240;

struct FUN_0040efd0_shell : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040efd0_shell(void* aField);
};

// @fnv 0x0040efd0
FUN_0040efd0_shell::FUN_0040efd0_shell(void* aField) : BE(0x81)
{
    *reinterpret_cast<void**>(this) = &DAT_01014240;
    pField = aField;
}

extern void* DAT_0101424c;

struct FUN_0040f070_shell : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040f070_shell(void* aField);
};

// @fnv 0x0040f070
FUN_0040f070_shell::FUN_0040f070_shell(void* aField) : BE(8)
{
    pVftable = &DAT_0101424c;
    pField = aField;
}

struct FUN_0040f4d0_shell : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040f4d0_shell(void* aField);
    void* FUN_0040f4d0(unsigned int flags);
    void FUN_0040f500();
};

extern void* _Deallocate(void*);

// Calls FUN_0040f500, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0040f4d0
void* FUN_0040f4d0_shell::FUN_0040f4d0(unsigned int flags)
{
    FUN_0040f500();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern void* DAT_01014294;

struct FUN_0040f590_shell : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040f590_shell();
};

// Initialises the object with base value 5, sets its vftable pointer to DAT_01014294 and clears pField.
// @fnv 0x0040f590
FUN_0040f590_shell::FUN_0040f590_shell() : BE(5)
{
    pVftable = &DAT_01014294;
    pField = 0;
}

struct ExtraCell3D
{
    void FUN_0040ed30();
    void* FUN_0040ed00(unsigned int);
};
// Calls FUN_0040ed30 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0040ed00
void* ExtraCell3D::FUN_0040ed00(unsigned int flags)
{
    this->FUN_0040ed30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct ExtraHavok
{
    void FUN_0040ee70();
    void* FUN_0040ee40(unsigned int);
};
// Calls FUN_0040ee70, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0040ee40
void* ExtraHavok::FUN_0040ee40(unsigned int flags)
{
    FUN_0040ee70();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct BGSMusicType;

extern int DAT_01014234;
struct FUN_0040ef30 : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040ef30(BGSMusicType* aMusic);
};
// @fnv 0x0040ef30
FUN_0040ef30::FUN_0040ef30(BGSMusicType* aMusic) : BE(7)
{
    pVftable = &DAT_01014234;
    pField = aMusic;
}

struct ExtraCellImpactSwap
{
    void FUN_0040f210();
    void* FUN_0040f1e0(unsigned int flags);
};
// @fnv 0x0040f1e0
void* ExtraCellImpactSwap::FUN_0040f1e0(unsigned int flags)
{
    FUN_0040f210();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern int DAT_01014270;
struct FUN_0040f370 : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040f370();
};
// @fnv 0x0040f370
FUN_0040f370::FUN_0040f370() : BE(3)
{
    pVftable = (void*)&DAT_01014270;
    pField = 0;
}

extern int DAT_0101427c;
struct FUN_0040f410 : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040f410();
};
// @fnv 0x0040f410
FUN_0040f410::FUN_0040f410() : BE(9)
{
    BE::pVftable = (void*)&DAT_0101427c;
    pField = 0;
}

extern int DAT_01014258;

struct FUN_0040f110_shell : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040f110_shell(void* aField);
};

// Initialises the object with vtable DAT_01014258 and stores aField in pField.
// @fnv 0x0040f110
FUN_0040f110_shell::FUN_0040f110_shell(void* aField) : BE(0x59)
{
    *(void**)this = &DAT_01014258;
    pField = aField;
}

struct FUN_0040f1b0_shell : BE
{
    void* pad1;
    void* pad2;
    void* pField;
    FUN_0040f1b0_shell();
};

extern void* DAT_01014264;

// @fnv 0x0040f1b0
FUN_0040f1b0_shell::FUN_0040f1b0_shell() : BE(0x8c)
{
    *(void**)this = &DAT_01014264;
    pField = 0;
}

// Destructor: drop the held pathing reference before the member and base destructors run.

class ED30PathingRef
{
  public:
    ~ED30PathingRef();
    void Reset(void* pvObject);
    void* m_pvObject;
};

class ED30Base
{
  public:
    virtual ~ED30Base();
    int unk04;
    int unk08;
};

class FUN_0040ed30 : public ED30Base
{
  public:
    virtual ~FUN_0040ed30();
    ED30PathingRef m_kSolution;
};

// Destructor that resets the pathing solution reference by calling Reset with a null object pointer.
// @fnv 0x0040ed30
FUN_0040ed30::~FUN_0040ed30()
{
    m_kSolution.Reset(0);
}

extern void* DAT_0101421c;

struct CleanupBase
{
    ~CleanupBase();
};

struct FUN_00633c90
{
    FUN_00633c90(unsigned int value);
    ~FUN_00633c90();
    void FUN_0066b0d0(void* value);
    void* value;
};

struct FUN_0040eda0 : BSExtraData, CleanupBase
{
    FUN_00633c90 first;
    FUN_00633c90 second;
    FUN_0040eda0(void* value);
};

// Constructs a BSExtraData with two value holders, storing the given value in the first and null in the second.
// @fnv 0x0040eda0
FUN_0040eda0::FUN_0040eda0(void* value) : BSExtraData(1), first((m_ppVirtualMethodTable = (void**)&DAT_0101421c, 0)), second(0)
{
    first.FUN_0066b0d0(value);
    second.FUN_0066b0d0(0);
}

struct FUN_0040ecb0
{
    virtual ~FUN_0040ecb0();
    unsigned char m_ucExtraDataType;
    unsigned char pad05;
    unsigned char pad06;
    unsigned char pad07;
    FUN_0040ecb0* pNext;
};
struct FUN_0045cec0
{
    void* pObject;
    void FUN_0066b0d0(unsigned int);
    ~FUN_0045cec0();
};
struct FUN_0040ee70 : FUN_0040ecb0
{
    FUN_0045cec0 first;
    FUN_0045cec0 second;
    virtual ~FUN_0040ee70();
};
// @fnv 0x0040ee70
FUN_0040ee70::~FUN_0040ee70()
{
    second.FUN_0066b0d0(0);
    first.FUN_0066b0d0(0);
}

class B0F210Data
{
  public:
    ~B0F210Data();
};

class B0F210ExtraData
{
  public:
    virtual ~B0F210ExtraData();

    unsigned char m_ucType;
    void* m_pkNext;
};

class FUN_0040f210 : public B0F210ExtraData
{
  public:
    virtual ~FUN_0040f210();

    B0F210Data* m_pUserData;
};

// @fnv 0x0040f210
FUN_0040f210::~FUN_0040f210()
{
    delete m_pUserData;
}

struct FUN_0040f3a0_node
{
    void* m_ppVirtualMethodTable;
    void* unk04;
    void* unk08;
    int m_0c;
};

extern int DAT_01183c38;
extern int DAT_01183b2c;
void* FUN_00ec43fb(void* a, int b, void* c, void* d, int e);

struct FUN_0040f3a0_cls
{
    void* m_ppVirtualMethodTable;
    void* unk04;
    void* unk08;
    int m_0c;

    bool IsDifferentFrom(void* a1);
    bool Differs(void* a1);
};

// Looks up a node via FUN_00ec43fb and returns true if it is null, IsDifferentFrom succeeds, or the node's m_0c differs from this object's m_0c.
// @fnv 0x0040f3a0
bool FUN_0040f3a0_cls::Differs(void* a1)
{
    FUN_0040f3a0_node* p = (FUN_0040f3a0_node*)FUN_00ec43fb(a1, 0, &DAT_01183b2c, &DAT_01183c38, 0);
    if (p == 0)
    {
        return true;
    }
    if (IsDifferentFrom(a1))
    {
        return true;
    }
    if (p->m_0c != m_0c)
    {
        return true;
    }
    return false;
}

struct FUN_0040f500_base
{
    virtual ~FUN_0040f500_base();
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_0040f500_sub
{
    unsigned int unk00;
    unsigned int unk04;
    void Init(unsigned char flags);
    ~FUN_0040f500_sub();
};

struct FUN_0040f500_cls : FUN_0040f500_base
{
    unsigned int unk0c;
    FUN_0040f500_sub m_10;
    unsigned int unk18;

    virtual ~FUN_0040f500_cls();
};

// Clears unk0c and unk18 and reinitialises m_10 with flags 0.
// @fnv 0x0040f500
FUN_0040f500_cls::~FUN_0040f500_cls()
{
    unk0c = 0;
    m_10.Init(0);
    unk18 = 0;
}

struct Field_40f
{
    virtual ~Field_40f();
};

struct Base_40f
{
    virtual void v00();
    ~Base_40f();
};

struct FUN_0040f5f0 : Base_40f
{
    void* pad1;
    void* pad2;
    Field_40f* m_pField;
    virtual void v00();
    ~FUN_0040f5f0();
};

// Destructor that deletes the owned m_pField object.
// @fnv 0x0040f5f0
FUN_0040f5f0::~FUN_0040f5f0()
{
    delete m_pField;
}

class ExtraData40F
{
  public:
    ExtraData40F(unsigned char ucType);
    virtual ~ExtraData40F();

    unsigned char m_ucType;
    ExtraData40F* m_pkNext;
};

class Handle40F
{
  public:
    Handle40F(int iValue);
    ~Handle40F();
    void Reset(void* pvObject);

    void* m_pvObject;
    int unk04;
};

class FUN_0040f440 : public ExtraData40F
{
  public:
    FUN_0040f440(int iValue, void* pvObject);
    virtual ~FUN_0040f440();

    int m_iValue;
    Handle40F m_kHandle;
    int m_iArrayLength;
};

// Initializes an ExtraData40F of type 0xa, storing iValue, resetting m_kHandle to pvObject, and zeroing the trailing field.
// @fnv 0x0040f440
FUN_0040f440::FUN_0040f440(int iValue, void* pvObject) : ExtraData40F(0xa), m_kHandle(0)
{
    m_iValue = iValue;
    m_kHandle.Reset(pvObject);
    m_iArrayLength = 0;
}

struct FUN_0040f5c0
{
    virtual ~FUN_0040f5c0();
};
// @fnv 0x0040f5c0
FUN_0040f5c0::~FUN_0040f5c0()
{}

extern int DAT_01183b84;

struct ExtraMusicTypeShell : BSExtraData
{
    BGSMusicType* pType;
    bool Differs(BSExtraData* extra);
};

// Returns true if the cast fails, IsDifferentFrom(extra) is true, or the two pType pointers differ; otherwise false.
// @fnv 0x0040ef60
bool ExtraMusicTypeShell::Differs(BSExtraData* apOther)
{
    ExtraMusicTypeShell* pOther =
        static_cast<ExtraMusicTypeShell*>(FUN_00ec43fb(apOther, 0, &DAT_01183b2c, &DAT_01183b84, 0));
    if (!pOther)
        return true;
    if (reinterpret_cast<FUN_0040f3a0_cls*>(this)->IsDifferentFrom(apOther))
        return true;
    if (pOther->pType != pType)
        return true;
    return false;
}

struct BGSAcousticSpace;
extern int DAT_01183ba8;
struct ExtraCellAcousticSpace : BSExtraData
{
    BGSAcousticSpace* m_pPathingCell;
    bool Differs(BSExtraData* apCompare);
};
// Compares this ExtraCellAcousticSpace against apCompare, returning true if the cast target is null, the base differs, or the acoustic space pointer differs.
// @fnv 0x0040f000
bool ExtraCellAcousticSpace::Differs(BSExtraData* apCompare)
{
    ExtraCellAcousticSpace* pComp =
        static_cast<ExtraCellAcousticSpace*>(FUN_00ec43fb(apCompare, 0, &DAT_01183b2c, &DAT_01183ba8, 0));
    if (!pComp)
        return true;
    if (reinterpret_cast<FUN_0040f3a0_cls*>(this)->IsDifferentFrom(apCompare))
        return true;
    if (pComp->m_pPathingCell != m_pPathingCell)
        return true;
    return false;
}

extern int DAT_01183bd0;
struct FUN_0040f0a0_shell : BSExtraData
{
    void* pField;
    bool IsDifferentFrom(BSExtraData*);
    bool Differs(BSExtraData* extra);
};
// Returns true if the cast fails, IsDifferentFrom(extra) returns true, or the pField pointers differ; otherwise false.
// @fnv 0x0040f0a0
bool FUN_0040f0a0_shell::Differs(BSExtraData* apOther)
{
    FUN_0040f0a0_shell* cast = (FUN_0040f0a0_shell*)FUN_00ec43fb(apOther, 0, &DAT_01183b2c, &DAT_01183bd0, 0);
    if (!cast)
        return true;
    if (IsDifferentFrom(apOther))
        return true;
    if (cast->pField != pField)
        return true;
    return false;
}

extern int DAT_01183c14;

struct CellImpactSwapValue
{
    bool IsImpactSwapDifferent(CellImpactSwapValue*);
};

struct CellImpactCompare : BSExtraData
{
    CellImpactSwapValue* m_pCellImpactSwapValue;

    bool Differs(BSExtraData* apCompare);
};

// Returns true if the cast fails, IsDifferentFrom(apCompare) is true, or the payload comparison returns true.
// @fnv 0x0040f2d0
bool CellImpactCompare::Differs(BSExtraData* apCompare)
{
    CellImpactCompare* pComp;

    pComp = static_cast<CellImpactCompare*>(FUN_00ec43fb(apCompare, 0, &DAT_01183b2c, &DAT_01183c14, 0));

    if (!pComp)
        return true;

    if (reinterpret_cast<FUN_0040f3a0_cls*>(this)->IsDifferentFrom(apCompare))
        return true;

    if (pComp->m_pCellImpactSwapValue && this->m_pCellImpactSwapValue)
    {
        if (pComp->m_pCellImpactSwapValue->IsImpactSwapDifferent(this->m_pCellImpactSwapValue))
            return true;
    }
    else if (pComp->m_pCellImpactSwapValue || this->m_pCellImpactSwapValue)
    {
        return true;
    }

    return false;
}

extern int DAT_01183bf0;
struct ExtraCellImageSpace : BSExtraData
{
    void* m_pImageSpace;
    bool Differs(BSExtraData* extra);
    bool IsDifferentFrom(BSExtraData* extra);
};

// Returns true if the cast fails, FUN_0040f700(extra) returns true, or the image-space pointers differ; otherwise false.
// @fnv 0x0040f140
bool ExtraCellImageSpace::Differs(BSExtraData* extra)
{
    ExtraCellImageSpace* cast =
        static_cast<ExtraCellImageSpace*>(FUN_00ec43fb(extra, 0, &DAT_01183b2c, &DAT_01183bf0, 0));
    if (!cast)
        return true;
    if (IsDifferentFrom(extra))
        return true;
    if (cast->m_pImageSpace != m_pImageSpace)
        return true;
    return false;
}
