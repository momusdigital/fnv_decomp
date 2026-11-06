// gamebryo2.2/corelibs/nimain/niproperty.cpp: NiProperty (3 functions)

#include "niproperty_decls.h"

// @fnv 0x00a5d7f0
void NiProperty::LoadBinary(NiStream& stream)
{
    NiObjectNET::LoadBinary(stream);

    if (stream.m_uiNifVersion < 0x0a000102)
    {
        // Pre-10.0.1.2 files carry the block's property flags in the stream.
        unsigned short usPropertyFlags;
        stream.m_pUnderlyingStream->Read(usPropertyFlags);
        stream.m_usPropertyFlags = usPropertyFlags;
    }
}

struct NiUpdateData
{
    float fTime;
};
struct NiTimeController
{
    virtual ~NiTimeController()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void Update(NiUpdateData&)
    {}
    char _pad04[44];
    NiTimeController* m_spNextController;
};
struct PropHack00a5d7c0
{
    char _pad[12];
    NiTimeController* m_pControllers;
    void UpdateControllerChain(NiUpdateData& UpdateData);
};
// @fnv 0x00a5d7c0
void PropHack00a5d7c0::UpdateControllerChain(NiUpdateData& UpdateData)
{
    NiTimeController* pkControl = m_pControllers;
    while (pkControl)
    {
        pkControl->Update(UpdateData);
        pkControl = pkControl->m_spNextController;
    }
}

struct StrArr
{
    char _pad0[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    char _pad1[2];
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    unsigned short GetSize() const
    {
        return m_usSize;
    }
    unsigned short GetMaxSize() const
    {
        return m_usMaxSize;
    }
    unsigned short GetGrowBy() const
    {
        return m_usGrowBy;
    }
};
struct FUN_00a62a40_this
{
    void GetViewerStrings(StrArr*);
    void AppendString(StrArr*);
};
extern char const* const g_011f4408_arg1;
char* __cdecl _FUN_00a7d330(char const*);
// Appends the string returned by _FUN_00a7d330(g_011f4408_arg1) to pkStrings, growing the array if it is full.
// @fnv 0x00a5d850
void FUN_00a62a40_this::AppendString(StrArr* pkStrings)
{
    GetViewerStrings(pkStrings);
    char* pcStr = _FUN_00a7d330(g_011f4408_arg1);
    unsigned int uiSize = pkStrings->GetSize();
    if (uiSize >= pkStrings->GetMaxSize())
        pkStrings->SetSize(uiSize + pkStrings->GetGrowBy());
    pkStrings->SetAt(uiSize, pcStr);
}
