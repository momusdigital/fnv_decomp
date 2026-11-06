
// src/fallout_shared/exteriorcellloader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/exteriorcellloader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct IOManager
{
    void SubmitTask();
};

struct ExteriorCellLoaderTask : IOManager
{
    void FUN_00527ce0();
};

// @fnv 0x00527ce0
void __thiscall ExteriorCellLoaderTask::FUN_00527ce0()
{
    SubmitTask();
}

struct IntPoint2D
{
    int iX;
    int iY;
};

struct IOTask
{
};

struct FUN_00527df0_shell
{
    IOTask m_IOTask;
    IntPoint2D* m_pGridCoordinates;
    bool GetDescription(char* apDescription, unsigned int aiBufferSize);
};

extern "C" char* __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

// Formats the cell coordinates of the task's cell into apDescription using _sprintf_s and returns true.
// @fnv 0x00527df0
bool FUN_00527df0_shell::GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    _sprintf_s(apDescription, aiBufferSize, "ExteriorCellLoaderTask for cell ( %i, %i )",
               ((IntPoint2D*)*(int*)((char*)this + 0x1c))->iX, ((IntPoint2D*)*(int*)((char*)this + 0x1c))->iY);
    return true;
}

struct FUN_00528790_shell
{
    char bUnk96;
    char GetUnk60Byte();
};

// @fnv 0x00528790
char FUN_00528790_shell::GetUnk60Byte()
{
    return *reinterpret_cast<char*>(this + 0x60);
}

struct FUN_005287e0_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    bool FUN_005287e0();
};

// @fnv 0x005287e0
bool FUN_005287e0_shell::FUN_005287e0()
{
    return m_0c == 5;
}

extern int DAT_0102d078;

struct FUN_00528800_shell
{
    int m_val;
    void FUN_00528800();
};

// @fnv 0x00528800
void FUN_00528800_shell::FUN_00528800()
{
    m_val = (int)&DAT_0102d078;
}

struct FUN_00528820_shell
{
    void ClearField();
};

// @fnv 0x00528820
void FUN_00528820_shell::ClearField()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 8) = 0;
}

extern "C" void __cdecl _Deallocate(void*);

struct FUN_00440640_shell
{
    void FUN_00440640();
};

struct FUN_00527c70_shell
{
    char* m_00;
    char* m_1c;
    void FUN_00527c70();
};

// Sets m_00 to "@|R", deallocates the pointer at offset 0x1c, then calls FUN_00440640 on this.
// @fnv 0x00527c70
void FUN_00527c70_shell::FUN_00527c70()
{
    m_00 = "@|R";
    char* p = *(char**)((char*)this + 0x1c);
    _Deallocate(p);
    ((FUN_00440640_shell*)this)->FUN_00440640();
}

struct NiNode
{
};
struct TESObjectCELL
{
    NiNode* FUN_00545cb0();
};
extern int g_TES;

struct FUN_00454b90_shell
{
    int m_00;
    void AddCellToBuffer(TESObjectCELL* apCell);
};

struct FUN_005287b0_shell
{
    void FUN_005287b0(TESObjectCELL* apCell);
};

// If apCell is non-null and its FUN_00545cb0() node is non-null, calls AddCellToBuffer on the global g_TES object with apCell.
// @fnv 0x005287b0
void FUN_005287b0_shell::FUN_005287b0(TESObjectCELL* apCell)
{
    if (apCell)
    {
        if (apCell->FUN_00545cb0())
        {
            ((FUN_00454b90_shell*)(g_TES))->AddCellToBuffer(apCell);
        }
    }
}

struct TES
{
    bool IsCellBuffered(TESObjectCELL* apCell, bool abUnload);
};
struct DH
{
    void DeleteObject(TESObjectCELL* apCell);
};
extern DH* g_dataHandler;
struct TESWorldSpace
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int GetCellAtGridCoord(int aiX, int aiY);
};
struct FUN_00527d80_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    TESWorldSpace* m_1c;
    void FUN_00527d80(int, int);
};
// @fnv 0x00527d80
void FUN_00527d80_shell::FUN_00527d80(int, int)
{
    if (m_1c->m_0c && ((TES*)g_TES)->IsCellBuffered((TESObjectCELL*)m_1c->m_0c, false))
        g_dataHandler->DeleteObject((TESObjectCELL*)m_1c->m_0c);
    ((TESWorldSpace*)m_18)->GetCellAtGridCoord(m_1c->m_00, m_1c->m_04);
}

struct FUN_00528840_shell : public FUN_00528800_shell
{
    void* FUN_00528840(unsigned int flags);
};

// Calls FUN_00528800, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00528840
void* FUN_00528840_shell::FUN_00528840(unsigned int flags)
{
    FUN_00528800();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct LoaderDummy
{
    void FUN_00528620(IntPoint2D* p);
};
struct CellRefDummy
{
    void QueueReferences(int i);
};
struct MyCellEx
{
    char _pad[0xC];
    CellRefDummy* pObj;
};
struct FUN_00527cb0_shell
{
    char _pad[0x18];
    LoaderDummy* pLoader;
    IntPoint2D* m_pGridCoordinates;
    void FUN_00527cb0();
};
// @fnv 0x00527cb0
void FUN_00527cb0_shell::FUN_00527cb0()
{
    pLoader->FUN_00528620(m_pGridCoordinates);
    ((MyCellEx*)m_pGridCoordinates)->pObj->QueueReferences(1);
}

bool __fastcall FUN_00449130(int*);

struct FUN_00527d00_shell
{
    char _pad[0x18];
    FUN_005287b0_shell* pLoader;
    char* m_pGridCoordinates;
    void PostProcess();
};

// @fnv 0x00527d00
void FUN_00527d00_shell::PostProcess()
{
    if (!FUN_00449130((int*)this))
    {
        if (*(int*)(m_pGridCoordinates + 0xc) != 0)
        {
            if (*(unsigned char*)(m_pGridCoordinates + 0x10) != 0)
            {
                pLoader->FUN_005287b0((TESObjectCELL*)*(int*)(m_pGridCoordinates + 0xc));
            }
        }
    }
    *(char*)(m_pGridCoordinates + 0x10) = 0;
    ((TESWorldSpace*)pLoader)->GetCellAtGridCoord(*(int*)(m_pGridCoordinates), *(int*)(m_pGridCoordinates + 4));
}

struct CellEffects;
struct NiPoint2
{
    float x;
    float y;
};
struct WorldSpaceAccess : TESWorldSpace
{
    CellEffects* __thiscall LoadCell(int x, int y);
};
struct NodeEffects : NiNode
{
    void __thiscall LoadVertices(bool value);
    void __thiscall DrawLandBorder(unsigned char value);
    void __thiscall FUN_0053f440();
};
struct CellEffects : TESObjectCELL
{
    void __thiscall GetOrCreateWidget();
    NodeEffects* __thiscall FUN_00546fb0();
    NodeEffects* __thiscall FUN_00546fb0(NiPoint2* outPosition);
    bool __thiscall FUN_00451cd0();
    float __thiscall FUN_005471e0();
    void __thiscall SetFlag2(bool value);
    bool __thiscall FUN_004518e0();
    void __thiscall SetByteAt54(bool value);
};
struct GameWorld : TES
{
    CellEffects* __thiscall NewCell(int mode, int x, int y, WorldSpaceAccess* worldSpace);
};
extern GameWorld* DAT_011c3f2c;
extern FUN_00528790_shell* DAT_011dea10;
struct GlobalSettings
{
    unsigned char* __thiscall FUN_00408d60();
};
extern GlobalSettings DAT_011c7adc;
void __cdecl FUN_0049c860(CellEffects* cell);
struct CellLoadData : IntPoint2D
{
    WorldSpaceAccess* worldSpace;
    CellEffects* cell;
    bool loaded;
};
struct CellLoader
{
    void __thiscall FUN_00528620(CellLoadData* data);
};
// @fnv 0x00528620
void CellLoader::FUN_00528620(CellLoadData* pLoadData)
{
    if (pLoadData != 0)
    {
        if (pLoadData->cell == 0)
            pLoadData->cell = pLoadData->worldSpace->LoadCell(pLoadData->iX, pLoadData->iY);
        if (pLoadData->cell == 0)
            pLoadData->cell = DAT_011c3f2c->NewCell(0, pLoadData->iX, pLoadData->iY, pLoadData->worldSpace);
        pLoadData->cell->GetOrCreateWidget();
        NodeEffects* pNode = pLoadData->cell->FUN_00546fb0();
        if (pNode != 0)
        {
            pNode->LoadVertices(true);
            pNode->DrawLandBorder(DAT_011dea10->GetUnk60Byte());
        }
        if (!pLoadData->cell->FUN_00451cd0())
        {
            NiPoint2 position;
            pLoadData->cell->FUN_00546fb0(&position)->FUN_0053f440();
            pLoadData->cell->SetFlag2(position.x < pLoadData->cell->FUN_005471e0());
            if (*DAT_011c7adc.FUN_00408d60() && pLoadData->cell->FUN_004518e0() && !pLoadData->cell->FUN_00451cd0())
            {
                FUN_0049c860(pLoadData->cell);
            }
            pLoadData->cell->SetByteAt54(true);
        }
        pLoadData->loaded = true;
    }
}

void FUN_0040fca0(unsigned long ulMilliseconds);
struct QueuedTask
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Run(int eState, void* pArg);
    int m_04;
    int m_08;
    int m_eAnimationState;
    bool SetState(int eExpected, int eNew);
    void FUN_0092c870();
    void FUN_0044dd60();
};
struct FUN_00528870_shell
{
    void FUN_0044e050(QueuedTask* pTask);
    bool RunQueuedTask(QueuedTask* pTask, void* pArg);
};

// @fnv 0x00528870
bool FUN_00528870_shell::RunQueuedTask(QueuedTask* pTask, void* pArg)
{
    while (true)
    {
        int eState = pTask->m_eAnimationState;
        switch (eState)
        {
        case 0:
            if (pTask->SetState(eState, 6))
            {
                pTask->Run(eState, pArg);
                return true;
            }
            break;
        case 1:
            if (pTask->SetState(eState, 6))
            {
                pTask->FUN_0092c870();
                FUN_0044e050(pTask);
                pTask->Run(eState, pArg);
                pTask->FUN_0044dd60();
                return true;
            }
            break;
        case 2:
            while (pTask->m_eAnimationState == 3)
                FUN_0040fca0(0);
            break;
        case 3:
        case 4:
            return false;
        case 5:
            if (pTask->SetState(eState, 6))
            {
                pTask->Run(eState, pArg);
                return true;
            }
            break;
        case 6:
            return true;
        default:
            return true;
        }
    }
    return true;
}

struct CellLoaderDeletingTask : FUN_00527c70_shell
{
    void* __thiscall FUN_00527c40(unsigned int aiFlags);
};

// Calls FUN_00527c70, deallocates this when aiFlags bit 0 is set, and returns this.
// @fnv 0x00527c40
void* __thiscall CellLoaderDeletingTask::FUN_00527c40(unsigned int aiFlags)
{
    FUN_00527c70();
    if (aiFlags & 1)
        _Deallocate(this);
    return this;
}
