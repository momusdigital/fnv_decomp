// Authored unit header for fallout_shared/formcomponentcollection.cpp.
//
// The FormComponentArray body below is copied verbatim (with its layout
// class is not canonical. The only authored addition is ClearDataAllComponents:
// the helper that zeroes the component array, bound to 0x0047c540 by the unit
#ifndef FNV_FORMCOMPONENTCOLLECTION_H
#define FNV_FORMCOMPONENTCOLLECTION_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class FormComponentArray;
class TESForm;
class FormComponentArray
{
  public:
    BaseFormComponent* m_pComponents[38];  // +0x0, 152 bytes
    FormComponentArray();
    void FormComponentCollection_InitFormComponentArray(TESForm* form);
    // void __cdecl FormComponentArray::*()
    // void __cdecl FormComponentArray::*()
    // void __cdecl FormComponentArray::*(TESForm*)
    // void __cdecl FormComponentArray::*()
    // void __cdecl FormComponentArray::*()
    // void __cdecl FormComponentArray::*()
    // void __cdecl FormComponentArray::*(FormComponentArray*)
    // bool __cdecl FormComponentArray::*(FormComponentArray*)
    // void* __cdecl FormComponentArray::*(unsigned int)
    void ClearDataAllComponents();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FormComponentArray) == 152);
FNV_STATIC_ASSERT(offsetof(FormComponentArray, m_pComponents) == 0);
#endif
