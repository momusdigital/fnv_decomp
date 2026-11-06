
// to their real unit once identified.

//
// Compile form of nid3dpixelshader.inl: MSVC 2008 cl does not accept the
// .inl extension as a source file, so this identical unit is compiled as .cpp
// by the matcher. Content is the authored body of the .inl source of record.
// The standalone build carries the shader base chain with the real member
// names and offsets of the MSVC 2008 build: NiD3DPixelShader is 48 bytes
// and its D3D pixel shader handle lives at offset 44.
// Direct3D9 pixel shader object; referenced by pointer only.
class GeometryRelatedType;
// Forward declarations of the renderer types named by the base chain.
class NiD3DShaderProgramCreator;
class Direct3DDeviceInterface;
class GraphicsRenderer;
class ShaderPassRenderer;
typedef unsigned int NiUInt32;
// Base of the engine allocation tracking; empty in this build.
class NiMemObject
{
};
// Reference counted engine object.
class NiRefObject : public NiMemObject
{
  public:
    NiRefObject() : m_uiRefCount(0)
    {}

    virtual ~NiRefObject()
    {}

    virtual void DeleteThis()
    {
        delete this;
    }

  protected:
    NiUInt32 m_uiRefCount;
};
// GPU program base of the Nivid3D shader programs.
class NiGPUProgram : public NiRefObject
{
  public:
    enum ProgramType
    {
        PROGRAMTYPE_INVALID,
        PROGRAMTYPE_VERTEX,
        PROGRAMTYPE_PIXEL
    };

    ProgramType GetProgramType()
    {
        return m_iProgramType;
    }

  protected:
    ProgramType m_iProgramType;
};
// Nivid3D shader program with its compiled D3D program state.
class NiD3DShaderProgram : public NiGPUProgram
{
  protected:
    char* m_pcProgramName;
    char* m_pcProfile;
    NiUInt32 m_uiProgramCodeSize;
    void* m_pProgramCode;
    NiD3DShaderProgramCreator* m_pCreator;
    Direct3DDeviceInterface* m_pD3DDevice;
    GraphicsRenderer* m_pShaderObject;
    ShaderPassRenderer* m_pRenderState;
};
// Nivid3D pixel shader program.
class NiD3DPixelShader : public NiD3DShaderProgram
{
  public:
    void SetD3DPixelShader(GeometryRelatedType* pixelShader);

  protected:
    GeometryRelatedType* m_pD3DPixelShader;
};
struct NiD3DPixelShader;
void __cdecl FUN_00e92f30(NiD3DPixelShader*);
struct FUN_00e898d0_shell : NiD3DPixelShader
{
    void FUN_00e898d0();
};
// ---- stand-ins for identities not defined in this unit ----
struct FakeShader;
struct FakeRenderer
{
    void PurgeShader(FakeShader* shader);
};
struct FUN_00e898c0_shell : NiD3DPixelShader
{
    void DestroyRendererData();
};

extern "C" unsigned int DAT_011f5fc4[];

struct S_00e89a40_Data
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    void* unk18;
    void* unk1c;
};

typedef void(__stdcall* S_00e89a40_Callback)(void* object, void* source, void* destination, unsigned int stride);

struct S_00e89a40_Shell : NiD3DPixelShader
{
    bool FUN_00e89a40(S_00e89a40_Data* data, void* destination, unsigned int count, unsigned int stride,
                      const unsigned short* indices);
};

// @fnv 0x00e89a40
bool __thiscall S_00e89a40_Shell::FUN_00e89a40(S_00e89a40_Data* data, void* destination, unsigned int count,
                                               unsigned int stride, const unsigned short* indices)
{
    unsigned int type = DAT_011f5fc4[data->unk14 & 0xff];

    if (type != 8 && type != 9)
        return false;

    void* source = data->unk1c;

    for (unsigned int index = 0; index < count; ++index)
    {
        void* renderer = m_pRenderState;
        void* object = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(renderer) + 0x10f8);
        void** vtable = *reinterpret_cast<void***>(object);

        S_00e89a40_Callback callback = reinterpret_cast<S_00e89a40_Callback>(vtable[0x1b4 / sizeof(void*)]);

        unsigned int item = static_cast<unsigned int>(indices[index]);
        item *= stride;
        item <<= 4;

        void* target = reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(destination) + item);

        callback(object, source, target, stride);
        source = reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(source) + stride);
    }

    return true;
}

namespace fnv_00e899a0 {
struct ScriptAttributeTypes
{
    enum AttributeType
    {
        ATTRIB_TYPE_BOOL = 1,
        ATTRIB_TYPE_INT = 3
    };
};

extern int DAT_011f5fc4[];

struct NiShaderConstantMapEntry
{
    unsigned int unk00[5];
    unsigned int m_uiValue1;
    unsigned int unk18;
    unsigned int m_uiValue3;
    unsigned int m_uiValue4;
    unsigned int unk24;
    unsigned int m_uiValue5;
    unsigned int unk2c;
    void* m_pConstantData;

    ScriptAttributeTypes::AttributeType GetAttributeType() const
    {
        return static_cast<ScriptAttributeTypes::AttributeType>(DAT_011f5fc4[m_uiValue1 & 0xff]);
    }
};

template <int N> struct ShaderDeviceSlots : ShaderDeviceSlots<N - 1>
{
    virtual void Reserved(ShaderDeviceSlots<N>*);
};

template <> struct ShaderDeviceSlots<0>
{
    virtual void Reserved(ShaderDeviceSlots<0>*);
};

struct ShaderConstantDevice : ShaderDeviceSlots<108>
{
    virtual long __stdcall SetPixelShaderConstantF(unsigned int, const float*, unsigned int) = 0;
    virtual long __stdcall GetPixelShaderConstantF(unsigned int, float*, unsigned int) = 0;
    virtual long __stdcall SetPixelShaderConstantI(unsigned int, const int*, unsigned int) = 0;
    virtual long __stdcall GetPixelShaderConstantI(unsigned int, int*, unsigned int) = 0;
    virtual long __stdcall SetPixelShaderConstantB(unsigned int, const int*, unsigned int) = 0;
};

struct ShaderConstantRenderState
{
    char unk0000[0x10f8];
    ShaderConstantDevice* device;

    __forceinline bool SetPixelShaderConstantB(unsigned int reg, const int* data, unsigned int count)
    {
        return device->SetPixelShaderConstantB(reg, data, count) >= 0;
    }

    __forceinline bool SetPixelShaderConstantI(unsigned int reg, const int* data, unsigned int count)
    {
        return device->SetPixelShaderConstantI(reg, data, count) >= 0;
    }

    __forceinline bool SetPixelShaderConstantF(unsigned int reg, const float* data, unsigned int count)
    {
        return device->SetPixelShaderConstantF(reg, data, count) >= 0;
    }
};

struct FUN_00e899a0_shell : NiD3DPixelShader
{
    bool SetShaderConstant(NiShaderConstantMapEntry* pkEntry, const void* pvDataSource, unsigned int uiRegisterCount);
};

// @fnv 0x00e899a0
bool FUN_00e899a0_shell::SetShaderConstant(NiShaderConstantMapEntry* pkEntry, const void* pvDataSource,
                                      unsigned int uiRegisterCount)
{
    if (!pvDataSource)
        pvDataSource = pkEntry->m_pConstantData;

    if (!uiRegisterCount)
    {
        uiRegisterCount = pkEntry->m_uiValue4;
        if (!uiRegisterCount)
            uiRegisterCount = 1;
    }

    ScriptAttributeTypes::AttributeType eAttributeType = pkEntry->GetAttributeType();

    if (eAttributeType == ScriptAttributeTypes::ATTRIB_TYPE_BOOL)
    {
        return reinterpret_cast<ShaderConstantRenderState*>(m_pRenderState)
            ->SetPixelShaderConstantB(pkEntry->m_uiValue3, static_cast<const int*>(pvDataSource), uiRegisterCount);
    }
    else if (eAttributeType == ScriptAttributeTypes::ATTRIB_TYPE_INT)
    {
        return reinterpret_cast<ShaderConstantRenderState*>(m_pRenderState)
            ->SetPixelShaderConstantI(pkEntry->m_uiValue3, static_cast<const int*>(pvDataSource), uiRegisterCount);
    }
    else
    {
        return reinterpret_cast<ShaderConstantRenderState*>(m_pRenderState)
            ->SetPixelShaderConstantF(pkEntry->m_uiValue3, static_cast<const float*>(pvDataSource), uiRegisterCount);
    }
}
}  // namespace fnv_00e899a0
