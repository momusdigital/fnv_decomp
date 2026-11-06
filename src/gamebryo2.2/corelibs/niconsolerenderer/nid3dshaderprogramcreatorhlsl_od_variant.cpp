
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct NiD3DPixelShader
{
    void* __thiscall DestroyPixelShader(unsigned int flags);
};
extern "C" void __cdecl FUN_00e89970();
extern void __cdecl __Dummy_00b6fef0(void* p, unsigned int flags);
struct COMUnknownInterface;
struct NiD3DVertexShader
{
    void SetVertexDeclaration(COMUnknownInterface* hDecl);
};
struct VTableObj
{
    int m_uiX;
    int m_uiY;
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void Call(int a, int b);
};
extern "C" void* __cdecl FUN_00c85750();
struct FUN_00c7b0f0_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    void FUN_00c7b0f0();
};
extern "C" void* g_0126fa40;
void* __cdecl FUN_00e95cc0();
extern const void* g_0126fa48;
const void* __cdecl FUN_00e95df0();
extern void(__cdecl* DAT_fdf3f0)();
void __cdecl D3DXGetVertexShaderProfile();
struct NiD3DShaderProgramCreator;
struct NiD3DShaderProgram
{
    void __thiscall FUN_00eea540(NiD3DShaderProgramCreator* pkCreator);
};

struct ID3DXConstantTable;
struct NiD3DHLSLPixelShader
{
    char m_auiShapeKeys[0x48];
    ID3DXConstantTable* m_pShaderConstantTable;
    ID3DXConstantTable* FUN_00b18300();
};

// @fnv 0x00b18300
ID3DXConstantTable* NiD3DHLSLPixelShader::FUN_00b18300()
{
    return m_pShaderConstantTable;
}
