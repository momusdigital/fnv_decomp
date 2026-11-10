#pragma once

#include "TESBoundObject.h"
#include "TESFullName.h"
#include "TESScriptableForm.h"
#include "TESEnchantableForm.h"
#include "TESValueForm.h"
#include "TESWeightForm.h"
#include "TESHealthForm.h"
#include "TESBipedModelForm.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSEquipType.h"
#include "BGSRepairItemList.h"
#include "BGSBipedModelList.h"
#include "BGSPickupPutdownSounds.h"
#include "ArmorData.h"

class SoundDescriptor;

template <class T> class BSSimpleList;

class TESObjectARMO : public TESBoundObject,
                      public TESFullName,
                      public TESScriptableForm,
                      public TESEnchantableForm,
                      public TESValueForm,
                      public TESWeightForm,
                      public TESHealthForm,
                      public TESBipedModelForm,
                      public BGSDestructibleObjectForm,
                      public BGSEquipType,
                      public BGSRepairItemList,
                      public BGSBipedModelList,
                      public BGSPickupPutdownSounds
{
public:
    TESObjectARMO();

    // Both overrides retain their inherited primary vtable slots (96 total).
    virtual ~TESObjectARMO();
    virtual void InitItem();

    void ResetFormData();
    bool Load(TESFile* file);
    unsigned char GetArmorWeight();
    float GetArmorRating();
    float GetDamageThreshold();
    bool TESObjectWEAP_GetIsPlayable();

    ArmorData data;       // 0x178
    unsigned int flags;   // 0x184
    union
    {
        BSSimpleList<SoundDescriptor*>* m_pPickupPutdownSoundList; // 0x188
        TESObjectARMO* m_pSoundSourceArmor;                        // 0x188
    };
    bool m_bUsesSoundList;                  // 0x18C
    unsigned char layoutPadding18D[3];      // 0x18D
};
