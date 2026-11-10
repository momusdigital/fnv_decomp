// fallout/ai/alarmpackage_decls.h: declares SpellItem, TESLevSpell, FormChangeMask, BGSLoadGameBuffer, BGSLoadFormBuffer and more
#ifndef FNV_ALARMPACKAGE_DECLS_H
#define FNV_ALARMPACKAGE_DECLS_H


#include "BaseFormComponent.h"
#include "TESForm.h"

// Only the TESForm inheritance is needed for these RTTI casts.
class SpellItem : public TESForm
{
};
class TESLevSpell : public TESForm
{
};

class FormChangeMask
{
  public:
    unsigned int uiFlags;
    FormChangeMask(unsigned int flags);
    operator bool() const;
};

// Buffer API declarations; this unit does not access their storage.
class BGSLoadGameBuffer
{
  public:
    unsigned int ReadFormIdentifier();
};

class BGSLoadFormBuffer : public BGSLoadGameBuffer
{
  public:
    FormChangeMask GetChangeFlags(unsigned int mask);
    int LoadVariableSizedValue();
};

TESForm* __cdecl GetFormByID(unsigned int formID);

class TESSpellList : public BaseFormComponent
{
  public:
    BSSimpleList<SpellItem*> spellList;
    BSSimpleList<TESLevSpell*> leveledSpellList;
    void LoadGame(BGSLoadFormBuffer* buffer);
};

FNV_STATIC_ASSERT(sizeof(TESSpellList) == 0x14);
FNV_STATIC_ASSERT(offsetof(TESSpellList, spellList) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESSpellList, leveledSpellList) == 0xc);

#endif
