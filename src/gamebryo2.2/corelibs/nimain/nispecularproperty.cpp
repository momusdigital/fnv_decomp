
// src/gamebryo2.2/corelibs/nimain/nispecularproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nispecularproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_010a02e4;
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct NiObject : BSFadeNode
{
};
struct CloningProcess
{
};
struct NiProperty : NiObject
{
    int _v;
    char _d[20];
    NiProperty() throw();
};
struct NiCullingProperty
{
    void FUN_00a5d7a0(void*, CloningProcess&);
};
struct NiSpecularProperty : NiProperty
{
    unsigned short m_uiObjectFlags;
    NiSpecularProperty() throw()
    {
        *(void**)this = (void*)&DAT_010a02e4;
        m_uiObjectFlags = 0;
    }
    NiObject* CreateClone(CloningProcess&);
};
// @fnv 0x00a95110
NiObject* NiSpecularProperty::CreateClone(CloningProcess& kCloning)
{
    NiSpecularProperty* pkObject = new NiSpecularProperty;
    ((NiCullingProperty*)this)->FUN_00a5d7a0(pkObject, kCloning);
    pkObject->m_uiObjectFlags = m_uiObjectFlags;
    return pkObject;
}

extern unsigned int DAT_011f5ecc;

unsigned int __cdecl FUN_00a7d330(unsigned int key);
unsigned int __cdecl FUN_00a7d370(const char* name, unsigned int value);

struct FUN_00a951f0_list
{
    int unk00;
    int unk04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short unk0c;
    unsigned short m_0e;
    void FUN_0096ad30(unsigned int newCapacity);
    void FUN_0096ae90(unsigned int index, void* item);
};

struct FUN_00a951f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char m_18;
    void AppendString(FUN_00a951f0_list* list);
    void GetViewerStrings(FUN_00a951f0_list* list);
};

// @fnv 0x00a951f0
void FUN_00a951f0_cls::GetViewerStrings(FUN_00a951f0_list* list)
{
    AppendString(list);
    unsigned int item = FUN_00a7d330(DAT_011f5ecc);
    unsigned int count = list->m_0a;
    if (count >= list->m_08)
        list->FUN_0096ad30(count + list->m_0e);
    list->FUN_0096ae90(count, &item);

    unsigned char ucSpecFlag = m_18;
    ucSpecFlag &= 1;
    *(volatile unsigned char*)&item = ucSpecFlag;
    unsigned int result = FUN_00a7d370("m_bSpec", *(volatile unsigned int*)&item);
    *(volatile unsigned int*)&item = result;

    count = list->m_0a;
    if (count >= list->m_08)
        list->FUN_0096ad30(count + list->m_0e);
    list->FUN_0096ae90(count, &item);
}
