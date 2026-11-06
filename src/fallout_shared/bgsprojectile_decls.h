// fallout_shared/bgsprojectile_decls.h: declares TESBoundObject, TESDataHandler, BGSProjectileFloatNode, TESModel, BGSPreloadable and more
#ifndef FNV_BGSPROJECTILE_DECLS_H
#define FNV_BGSPROJECTILE_DECLS_H


#include "BaseFormComponent.h"
#include "bgsprojectile_form.h"
#include "TESFullName.h"
#include <malloc.h>

class TESBoundObject : public TESForm
{
    unsigned char layoutPadding018[24];

  public:
    TESBoundObject();
};

class TESRace;
template <class T> class BSSimpleList;
class TESDataHandler
{
  public:
    BSSimpleList<TESRace*>* GetTESRaceList();
};
class BGSProjectile;
void* operator new(unsigned int size);

class BGSProjectileFloatNode
{
  public:
    float value;
    BGSProjectileFloatNode* next;
    BGSProjectileFloatNode(const BGSProjectileFloatNode& other);
    void AddHead(const float& value);
};

class TESModel : public BaseFormComponent
{
    unsigned char layoutPadding004[20];

  public:
    TESModel();
    ~TESModel();
    static void LoadModelData(TESModel* model, TESFile* file);
    static void LoadTextureSwapData(TESModel* model, TESFile* file);
};

class BGSPreloadable : public BaseFormComponent
{
  public:
    BGSPreloadable();
};

class BGSDestructibleObjectForm : public BaseFormComponent
{
    void* pData;

  public:
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();
    static void LoadDestructibleData(BGSDestructibleObjectForm* form, TESFile* file);
    void InitItem(TESForm*);
};

class ProjectileProperties
{
    unsigned char data[84];

  public:
    void Endian();
    void InitializeDefaults();
};

class FUN_004fcc00 : public ProjectileProperties
{
  public:
    FUN_004fcc00();
};

class BGSImpactData
{
  public:
    void ReadTypedData(TESFile* file, void* data, unsigned short size);
    char _pdbpad_1[47];
    char Data_db_pad2f_pad2f_pad2f[24];
    void* m_pDecalTextureSet;
    void* m_pPrimaryImpactSound;
    void* m_pSecondaryImpactSound;
    char ImpactDecalInfo[36];
};

class BGSProjectileVTable
{
  public:
#define FNV_VTABLE_SLOT(n) virtual void Slot##n() = 0
    FNV_VTABLE_SLOT(0);
    FNV_VTABLE_SLOT(1);
    FNV_VTABLE_SLOT(2);
    FNV_VTABLE_SLOT(3);
    FNV_VTABLE_SLOT(4);
    FNV_VTABLE_SLOT(5);
    FNV_VTABLE_SLOT(6);
    FNV_VTABLE_SLOT(7);
    FNV_VTABLE_SLOT(8);
    FNV_VTABLE_SLOT(9);
    FNV_VTABLE_SLOT(10);
    FNV_VTABLE_SLOT(11);
    FNV_VTABLE_SLOT(12);
    FNV_VTABLE_SLOT(13);
    FNV_VTABLE_SLOT(14);
    FNV_VTABLE_SLOT(15);
    FNV_VTABLE_SLOT(16);
    FNV_VTABLE_SLOT(17);
    FNV_VTABLE_SLOT(18);
    FNV_VTABLE_SLOT(19);
    FNV_VTABLE_SLOT(20);
    FNV_VTABLE_SLOT(21);
    FNV_VTABLE_SLOT(22);
    FNV_VTABLE_SLOT(23);
    FNV_VTABLE_SLOT(24);
    FNV_VTABLE_SLOT(25);
    FNV_VTABLE_SLOT(26);
    FNV_VTABLE_SLOT(27);
    FNV_VTABLE_SLOT(28);
    FNV_VTABLE_SLOT(29);
    FNV_VTABLE_SLOT(30);
    FNV_VTABLE_SLOT(31);
    FNV_VTABLE_SLOT(32);
    FNV_VTABLE_SLOT(33);
    FNV_VTABLE_SLOT(34);
    FNV_VTABLE_SLOT(35);
    FNV_VTABLE_SLOT(36);
    FNV_VTABLE_SLOT(37);
    FNV_VTABLE_SLOT(38);
    FNV_VTABLE_SLOT(39);
    FNV_VTABLE_SLOT(40);
    FNV_VTABLE_SLOT(41);
    FNV_VTABLE_SLOT(42);
    FNV_VTABLE_SLOT(43);
    FNV_VTABLE_SLOT(44);
    FNV_VTABLE_SLOT(45);
    FNV_VTABLE_SLOT(46);
    FNV_VTABLE_SLOT(47);
    FNV_VTABLE_SLOT(48);
    FNV_VTABLE_SLOT(49);
    FNV_VTABLE_SLOT(50);
    FNV_VTABLE_SLOT(51);
    FNV_VTABLE_SLOT(52);
    FNV_VTABLE_SLOT(53);
    FNV_VTABLE_SLOT(54);
    FNV_VTABLE_SLOT(55);
#undef FNV_VTABLE_SLOT
    virtual void LoadBoundChunk(TESFile* file) = 0;
#define FNV_VTABLE_SLOT(n) virtual void Slot##n() = 0
    FNV_VTABLE_SLOT(57);
    FNV_VTABLE_SLOT(58);
    FNV_VTABLE_SLOT(59);
    FNV_VTABLE_SLOT(60);
    FNV_VTABLE_SLOT(61);
    FNV_VTABLE_SLOT(62);
    FNV_VTABLE_SLOT(63);
    FNV_VTABLE_SLOT(64);
    FNV_VTABLE_SLOT(65);
    FNV_VTABLE_SLOT(66);
    FNV_VTABLE_SLOT(67);
    FNV_VTABLE_SLOT(68);
    FNV_VTABLE_SLOT(69);
    FNV_VTABLE_SLOT(70);
    FNV_VTABLE_SLOT(71);
    FNV_VTABLE_SLOT(72);
    FNV_VTABLE_SLOT(73);
    FNV_VTABLE_SLOT(74);
    FNV_VTABLE_SLOT(75);
    FNV_VTABLE_SLOT(76);
#undef FNV_VTABLE_SLOT
    virtual bool SetEditorID(const char* editorID) = 0;
};

class TESModelVTable
{
  public:
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void Slot4() = 0;
    virtual void Slot5() = 0;
    virtual void LoadRawChunk(void* buffer) = 0;
};

class BGSProjectile : public TESBoundObject,
                      public TESFullName,
                      public TESModel,
                      public BGSPreloadable,
                      public BGSDestructibleObjectForm
{
  public:
    FUN_004fcc00 Data;
    TESModel m_kProjectileModel;
    int m_eSoundLevel;
    BGSProjectile();
    void ClearData();
    void ResetFormData();
    void InitItem();
    bool GetHasExplosion();
    bool Load(TESFile* file);
};

FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(sizeof(BGSPreloadable) == 4);
FNV_STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 8);
FNV_STATIC_ASSERT(sizeof(ProjectileProperties) == 84);
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 0x30);
FNV_STATIC_ASSERT(sizeof(FUN_004fcc00) == 84);
FNV_STATIC_ASSERT(sizeof(TESBoundObject) + sizeof(TESFullName) + sizeof(TESModel) + sizeof(BGSPreloadable) +
                      sizeof(BGSDestructibleObjectForm) ==
                  0x60);
FNV_STATIC_ASSERT(offsetof(BGSProjectile, Data) == 0x60);
FNV_STATIC_ASSERT(offsetof(BGSProjectile, m_kProjectileModel) == 0xB4);
FNV_STATIC_ASSERT(offsetof(BGSProjectile, m_eSoundLevel) == 0xCC);
FNV_STATIC_ASSERT(sizeof(BGSProjectile) == 0xD0);

class TESObjectLIGH : public TESForm
{
};
class TESSound : public TESForm
{
};
class BGSExplosion : public TESForm
{
};
class TESObjectWEAP : public TESForm
{
};
class Tile;
class EffectSetting
{
  public:
    TESObjectLIGH* GetLight();
    TESSound* GetBoltSound();
    TESSound* GetHitSound();
    int GetArchetype();
    void SetLight(TESObjectLIGH*);
    void SetBoltSound(TESSound*);
    void SetHitSound(TESSound*);
    void SetEffectID(int);
    void SetAssociatedActorValue(int);
};
class TESChallenge
{
  public:
    TESForm* GetFormOne();
};
class TESObjectACTI
{
  public:
    void SetLoopingSound(TESSound*);
};
class InterfaceManager
{
  public:
    Tile* FUN_00586150();
    Tile* FUN_004fd400();
    void FUN_00500a20(Tile*);
};
#endif
