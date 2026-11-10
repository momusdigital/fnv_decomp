#pragma once

#include "TESObjectACTI.h"
#include "NiPoint3.h"

class TESFurniture : public TESObjectACTI
{
public:
    TESFurniture();
    virtual ~TESFurniture();

    virtual void InitializeComponent();
    virtual bool LoadForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual void InitItem(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void ResetFormData();
    bool Load(TESFile* file);
    bool CanSitOn();
    void SetCanSitOn(bool bSit);
    bool CanSleepOn();
    void SetCanSleepOn(bool bSleep);
    bool GetMarkerEnabled(unsigned int aiMarker);
    void SetMarkerEnabled(unsigned int aiMarker, bool bEnabled);
    void UpdateSitSleepFlags(NiAVObject* apMarker);
    static unsigned int GetMarkerCount(NiAVObject* apMarker);
    static unsigned int GetMarkerNumber(NiAVObject* apMarker, unsigned int auMarker);
    static bool __cdecl IsSitMarker(unsigned int auMarker);
    static bool __cdecl IsSleepMarker(unsigned int auMarker);
    void VerifyMarkers();
    NiPoint3 GetMarkerTargetOffset(unsigned int auMarker, float afScale);
    float GetMarkerRotation(unsigned int auMarker);
    NiPoint3 FUN_00509920(unsigned int auMarker, float afScale);
    float TESFurniture_GetMarkerHeadingOffset(unsigned int auMarker);
    int _FNV_GetFormType();

    int m_iMarkerCount;
};

typedef char TESFurniture_size_check[(sizeof(TESFurniture) == 0x94) ? 1 : -1];
typedef char TESFurniture_marker_count_offset_check[(offsetof(TESFurniture, m_iMarkerCount) == 0x90) ? 1 : -1];
