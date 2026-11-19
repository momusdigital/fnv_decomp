// NiRenderedTexture.cpp: NiRenderedTexture (6 functions)

#include "../include/Ni2DBuffer.h"
#include "../include/NiObject.h"
#include "../include/NiObjectNET.h"
#include "../include/NiRefObject.h"
#include "../include/NiRenderedTexture.h"
#include "../include/NiRenderer.h"
#include "NiRenderedTexture.h"

// @fnv 0x00a7fc00
// pdb: NiRenderedTexture::Create | NiRenderedTexture.obj | retail, upstream name already matches, high
// pdb params: kName, uiWidth, uiHeight, pkRenderer, eMSAAPref, apAliasTex, uiAliasOffset
NiRenderedTexture* NiRenderedTexture::Create(const NiFixedString& kName, unsigned int uiWidth, unsigned int uiHeight,
                                             NiRenderer* apkRenderer, NiTexture::TextureFormatPreferences& kPrefs,
                                             Ni2DBuffer::MultiSamplePreference eMSAAPref, NiRenderedTexture* apAliasTex,
                                             unsigned int uiAliasOffset)
{
    if (!apkRenderer)
        return 0;
    NiDX9Renderer* dxRenderer = static_cast<NiDX9Renderer*>(apkRenderer);
    bool dimensionsPowerOfTwo = false;
    if (uiWidth)
    {
        dimensionsPowerOfTwo = (uiWidth & (uiWidth - 1)) == 0;
        if (dimensionsPowerOfTwo)
        {
            if (uiHeight)
                dimensionsPowerOfTwo = (uiHeight & (uiHeight - 1)) == 0;
            else
                dimensionsPowerOfTwo = false;
        }
    }
    if (!dimensionsPowerOfTwo)
    {
        if (!(dxRenderer->GetFlags() & 8) && !(dxRenderer->GetFlags() & 4))
            return 0;
    }
    NiRenderedTexture* texture = new NiRenderedTexture;
    texture->m_kFormatPrefs = kPrefs;
    texture->pAliasTexture = apAliasTex;
    texture->uiAliasOffset = uiAliasOffset;
    Ni2DBuffer* buffer = Ni2DBuffer::Create(uiWidth, uiHeight);
    Ni2DBuffer* oldBuffer = texture->m_spRenderTargetBuffer.m_pObject;
    if (oldBuffer != buffer)
    {
        if (oldBuffer && InterlockedDecrement(reinterpret_cast<volatile long*>(&oldBuffer->m_uiRefCount)) == 0)
            oldBuffer->DeleteThis();
        texture->m_spRenderTargetBuffer.m_pObject = buffer;
        if (buffer)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&buffer->m_uiRefCount));
    }
    texture->bForceD3DFormat = ms_bUseDepthBuffer;
    texture->m_ePixelFormat = ms_eDepthStencilFormat;
    texture->bRenderedTexture = ms_bUseMipMaps;
    if (!dxRenderer->CreateRenderedTexture(texture, eMSAAPref))
    {
        delete texture;
        return 0;
    }
    texture->eMSAA = eMSAAPref;
    texture->pAliasTexture = 0;
    return texture;
}

void __fastcall DestroyFogProperty(void*);
void __fastcall NiTexture_RemoveTextureFromList(void*);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
extern int DAT_0109b944;

// Scalar deleting destructor of NiRenderedTexture: releases the render target buffer (this+0x30) and the renderer
// data (this+0x24), runs the base-class destructors, and frees the object when bit 0 of flags is set.
// @fnv 0x00a7fd30
// pdb: NiRenderedTexture::`scalar deleting destructor' | NiRenderedTexture.obj | retail, object-file run extension, low
// pdb note: debug build links it to NiGeometry::~NiGeometry
void* __fastcall DestroyRenderedTexture(NiRenderedTexture* self, int, unsigned char flags)
{
    void* p30 = *(void**)((char*)self + 0x30);
    if (p30)
    {
        // NiPointer<Ni2DBuffer> release: drop the reference, DeleteThis when it was the last one
        if (InterlockedDecrement((long*)((char*)p30 + 4)) == 0)
        {
            void** vtbl = *(void***)p30;
            ((void(__thiscall*)(void*))vtbl[1])(p30);
        }
    }

    void* p24 = *(void**)((char*)self + 0x24);
    *(void**)self = &DAT_0109b944;
    if (p24)
    {
        void** vtbl24 = *(void***)p24;
        ((void(__thiscall*)(void*, int))vtbl24[0])(p24, 1);
    }

    NiTexture_RemoveTextureFromList(self);
    DestroyFogProperty(self);

    if (flags & 1)
    {
        __Dummy_00b6fef0(self, 0x48);
    }

    return self;
}

extern char const* const g_012708e4_arg1[];

// @fnv 0x00a7fbd0
NiRTTI* NiRenderedTexture::GetType()
{
    return reinterpret_cast<NiRTTI*>(const_cast<char const**>(g_012708e4_arg1));
}

// @fnv 0x00a7fbe0
unsigned int NiTexture::GetRenderedWidth()
{
    Ni2DBuffer* buffer = static_cast<NiRenderedTexture*>(this)->m_spRenderTargetBuffer.m_pObject;
    if (buffer)
        return buffer->m_uiWidth;
    return 0;
}

// @fnv 0x00a7fbf0
unsigned int NiTexture::GetRenderedHeight()
{
    Ni2DBuffer* buffer = static_cast<NiRenderedTexture*>(this)->m_spRenderTargetBuffer.m_pObject;
    if (buffer)
        return buffer->m_uiHeight;
    return 0;
}

// @fnv 0x00be0b90
int NiRenderedTexture::vf41()
{
    return reinterpret_cast<int>(m_spRenderTargetBuffer.m_pObject);
}
