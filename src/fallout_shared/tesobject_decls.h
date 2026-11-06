// fallout_shared/tesobject_decls.h: declares BGSDehydrationStage, TESResponse, TESObjectREFR, TESFile, TESBoundPoint and more

class TESObject;
class TESFormList;
class SpellItem;
class TESIdleForm;
class BGSPerkEntry;
class BGSDehydrationStage
{
  public:
    void FUN_0050f9a0(SpellItem*);
};
class TESResponse
{
  public:
    void SetSpeakerIdle(TESIdleForm*);
};
class TESBoundObject;
class BipedAnim;
class TESObjectREFR
{
  public:
    virtual void refrSlot0();
    virtual void refrSlot1();
    virtual void refrSlot2();
    virtual void refrSlot3();
    virtual void refrSlot4();
    virtual void refrSlot5();
    virtual void refrSlot6();
    virtual void refrSlot7();
    virtual void refrSlot8();
    virtual void refrSlot9();
    virtual void refrSlot10();
    virtual void refrSlot11();
    virtual void refrSlot12();
    virtual void refrSlot13();
    virtual void refrSlot14();
    virtual void refrSlot15();
    virtual void refrSlot16();
    virtual void refrSlot17();
    virtual void refrSlot18();
    virtual void refrSlot19();
    virtual void refrSlot20();
    virtual void refrSlot21();
    virtual void refrSlot22();
    virtual void refrSlot23();
    virtual void refrSlot24();
    virtual void refrSlot25();
    virtual void refrSlot26();
    virtual void refrSlot27();
    virtual void refrSlot28();
    virtual void refrSlot29();
    virtual void refrSlot30();
    virtual void refrSlot31();
    virtual void refrSlot32();
    virtual void refrSlot33();
    virtual void refrSlot34();
    virtual void refrSlot35();
    virtual void refrSlot36();
    virtual void refrSlot37();
    virtual void refrSlot38();
    virtual void refrSlot39();
    virtual void refrSlot40();
    virtual void refrSlot41();
    virtual void refrSlot42();
    virtual void refrSlot43();
    virtual void refrSlot44();
    virtual void refrSlot45();
    virtual void refrSlot46();
    virtual void refrSlot47();
    virtual void refrSlot48();
    virtual void refrSlot49();
    virtual void refrSlot50();
    virtual void refrSlot51();
    virtual void refrSlot52();
    virtual void refrSlot53();
    virtual void refrSlot54();
    virtual void refrSlot55();
    virtual void refrSlot56();
    virtual void refrSlot57();
    virtual void refrSlot58();
    virtual void refrSlot59();
    virtual void refrSlot60();
    virtual void refrSlot61();
    virtual void refrSlot62();
    virtual void refrSlot63();
    virtual void refrSlot64();
    virtual void refrSlot65();
    virtual void refrSlot66();
    virtual void refrSlot67();
    virtual void refrSlot68();
    virtual void refrSlot69();
    virtual void refrSlot70();
    virtual void refrSlot71();
    virtual void refrSlot72();
    virtual void refrSlot73();
    virtual void refrSlot74();
    virtual void refrSlot75();
    virtual void refrSlot76();
    virtual void refrSlot77();
    virtual void refrSlot78();
    virtual void refrSlot79();
    virtual void refrSlot80();
    virtual void refrSlot81();
    virtual void refrSlot82();
    virtual void refrSlot83();
    virtual void refrSlot84();
    virtual void refrSlot85();
    virtual void refrSlot86();
    virtual void refrSlot87();
    virtual void refrSlot88();
    virtual void refrSlot89();
    virtual void refrSlot90();
    virtual void refrSlot91();
    virtual void refrSlot92();
    virtual void refrSlot93();
    virtual void refrSlot94();
    virtual void refrSlot95();
    virtual void refrSlot96();
    virtual void refrSlot97();
    virtual void refrSlot98();
    virtual void refrSlot99();
    virtual void refrSlot100();
    virtual void refrSlot101();
    virtual void refrSlot102();
    virtual void refrSlot103();
    virtual void refrSlot104();
    virtual void refrSlot105();
    virtual void refrSlot106();
    virtual void refrSlot107();
    virtual void refrSlot108();
    virtual void refrSlot109();
    virtual void refrSlot110();
    virtual void refrSlot111();
    virtual void refrSlot112();
    virtual void refrSlot113();
    virtual void refrSlot114();
    virtual void refrSlot115();
    virtual void refrSlot116();
    virtual void refrSlot117();
    virtual void refrSlot118();
    virtual void refrSlot119();
    virtual void refrSlot120();
    virtual void refrSlot121();
    virtual BipedAnim* GetBipedAnim();
    virtual void refrSlot123();
    virtual void SetBipedAnim(BipedAnim*);
    TESBoundObject* GetObjectReference();
    bool HasLeveledCreatureCalced();
    bool FUN_00477ba0();
    void FUN_00693ef0(bool);
};
class TESFile
{
  public:
    unsigned int GetChunkID();
    bool GetChunkData(void*, unsigned int);
    bool IsEndianConversionRequired();
};
class TESBoundPoint
{
  public:
    short a[3];
    void FUN_0050e8b0(const TESBoundPoint&);
};
const TESBoundPoint& GetActorValueShortVector();
class TESObjectBound
{
  public:
    TESBoundPoint min, max;
    void FUN_0050e9c0();
    void Endian();
};
class TESObjectREFR;
class NiAVObject;
class NiNode;

class TESObject
{
  public:
    TESObject();
    int GetFormType() const;
    bool HasLoaded3D();
    ~TESObject();
    virtual void Slot00()
    {}
    virtual void Slot01()
    {}
    virtual void Slot02()
    {}
    virtual void Slot03()
    {}
    virtual void Slot04()
    {}
    virtual void Slot05()
    {}
    virtual void Slot06()
    {}
    virtual void Slot07()
    {}
    virtual void Slot08()
    {}
    virtual void Slot09()
    {}
    virtual void Slot10()
    {}
    virtual void Slot11()
    {}
    virtual void Slot12()
    {}
    virtual void Slot13()
    {}
    virtual void Slot14()
    {}
    virtual void Slot15()
    {}
    virtual void Slot16()
    {}
    virtual void Slot17()
    {}
    virtual void Slot18()
    {}
    virtual void Slot19()
    {}
    virtual void Slot20()
    {}
    virtual void Slot21()
    {}
    virtual void Slot22()
    {}
    virtual void Slot23()
    {}
    virtual void Slot24()
    {}
    virtual void Slot25()
    {}
    virtual void Slot26()
    {}
    virtual void Slot27()
    {}
    virtual void Slot28()
    {}
    virtual void Slot29()
    {}
    virtual void Slot30()
    {}
    virtual void Slot31()
    {}
    virtual void Slot32()
    {}
    virtual void Slot33()
    {}
    virtual void Slot34()
    {}
    virtual void Slot35()
    {}
    virtual void Slot36()
    {}
    virtual void Slot37()
    {}
    virtual void Slot38()
    {}
    virtual void Slot39()
    {}
    virtual void Slot40()
    {}
    virtual void Slot41()
    {}
    virtual void Slot42()
    {}
    virtual void Slot43()
    {}
    virtual void Slot44()
    {}
    virtual void Slot45()
    {}
    virtual void Slot46()
    {}
    virtual void Slot47()
    {}
    virtual void Slot48()
    {}
    virtual void Slot49()
    {}
    virtual void Slot50()
    {}
    virtual void Slot51()
    {}
    virtual void Slot52()
    {}
    virtual void Slot53()
    {}
    virtual void Slot54()
    {}
    virtual void Slot55()
    {}
    virtual void Slot56()
    {}
    virtual void Slot57()
    {}
    virtual void Slot58()
    {}
    virtual void Slot59()
    {}
    virtual void Slot60()
    {}
    virtual void Slot61()
    {}
    virtual void Slot62()
    {}
    virtual void Slot63()
    {}
    virtual void Slot64()
    {}
    virtual void Slot65()
    {}
    virtual void Slot66()
    {}
    virtual void Slot67()
    {}
    virtual void Slot68()
    {}
    virtual void Slot69()
    {}
    virtual void Slot70()
    {}
    virtual void Slot71()
    {}
    virtual void Slot72()
    {}
    virtual void Slot73()
    {}
    virtual void Slot74()
    {}
    virtual void Slot75()
    {}
    virtual const char* GetEditorID();
    virtual void Slot77()
    {}
    virtual void Slot78()
    {}
    virtual void Slot79()
    {}
    virtual void Slot80()
    {}
    virtual void Slot81()
    {}
    virtual void Slot82()
    {}
    virtual NiNode* _CreateNiNode(TESObjectREFR* reference, bool arg1);
    virtual void objectSlot84();
    virtual void objectSlot85();
    virtual void objectSlot86();
    virtual void objectSlot87();
    virtual void objectSlot88();
    virtual void objectSlot89();
    virtual void objectSlot90();
    virtual void objectSlot91();
    virtual void objectSlot92();
    virtual NiNode* CreateNiNode(TESObjectREFR*);
};

class TESBoundObject : public TESObject
{
  public:
    TESBoundObject();
    char objectData[32];
    TESObjectBound bounds;
    void LoadBoundData(TESFile*);
    NiAVObject* Get3DObject(TESObjectREFR* reference);
    virtual NiNode* Create3DModel(TESObjectREFR* reference);
    NiNode* Get3DObject(TESObjectREFR*, bool);
};

class TESBoundAnimObject : public TESBoundObject
{
  public:
    TESBoundAnimObject();
};

class TESBoundTreeObject : public TESBoundObject
{
  public:
    TESBoundTreeObject();
};

class TESFormList
{
  public:
    unsigned int m_uiObjectCount;
    TESObject* m_pFirstObject;
    TESObject* m_pSecondObject;
    void* pOwner;
    TESObject* FUN_00510360(TESObject*);
    TESObject* GetTerrainMinLevel(TESObject*);
    TESObject* AddToObjectList(TESObject* object);
    TESObject* InsertObjectAfter(TESObject* object, TESObject* after);
};

class InterfaceManager
{
  public:
    void FUN_00984f60(unsigned int);
};
template <class T> class BSSimpleList
{
  public:
    BSSimpleList<T>* GetNext();
};
extern BSSimpleList<BGSPerkEntry*>* g_dataHandler;

class TESForm
{
  public:
    unsigned int GetFormID();
};
class TESObjectSTAT;
class TESObjectDOOR;
class TESModel
{
  public:
    static unsigned int GetModelLength(TESObject*);
    static const char* GetModelFilePath(TESObject*);
    unsigned int GetModelLength() const;
};
int FUN_00404dc0(const char*, const char*);
extern TESObjectDOOR* DAT_011ca258;
extern TESObjectSTAT* DAT_011ca220;
extern TESObjectSTAT* DAT_011ca250;
extern TESObjectSTAT* DAT_011ca25c;
extern TESObjectSTAT* DAT_011ca260;
extern TESObjectSTAT* DAT_011ca254;
extern TESObjectSTAT* DAT_011ca224;
extern TESObjectSTAT* DAT_011ca26c;
extern TESBoundObject* DAT_011ca244;
extern TESBoundObject* DAT_011ca248;
extern TESObjectSTAT* DAT_011ca24c;
extern TESObjectSTAT* DAT_011ca230;
extern TESObjectSTAT* DAT_011ca264;
extern TESObjectSTAT* DAT_011ca228;
extern TESObjectSTAT* DAT_011ca22c;

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class NiUpdateData
{
  public:
    float time;
    bool a, b;
    unsigned int flags;
    NiUpdateData(float, bool, bool);
};
class NiFixedString;
class NiTimeController;
class NiRTTI;
class NiExtraData;
class CloningProcess;
class NiAVObject
{
  public:
    virtual void avSlot0();
    virtual void avSlot1();
    virtual void avSlot2();
    virtual void avSlot3();
    virtual NiNode* GetAsNiNode();
    void SetName(const NiFixedString&);
    NiAVObject* CloneObject(CloningProcess&);
    NiTimeController* GetController(const NiRTTI*);
    NiExtraData* GetExtraData(const NiFixedString&);
    bool AddExtraData(const NiFixedString&, NiExtraData*);
    void UpdateSceneObject();
    void Update(NiUpdateData&);
};
class NiNode : public NiAVObject
{
};
class SceneObjectLookup
{
  public:
    static NiAVObject* GetObjectByName(NiAVObject*, const char*);
};
class BipedAnim
{
  public:
    char data[0x2b4];
    BipedAnim(TESObjectREFR*, NiNode*);
    void InitBoneSlots(NiNode*);
};
class TESActorBaseData
{
  public:
    bool GetUsesLeveledTemplate();
    void SetTemplateReference(TESObjectREFR*);
};
class TESCreature : public TESBoundObject
{
  public:
    TESActorBaseData actorData;
    NiNode* Create3DModel(TESObjectREFR*);
};

class NiObjectNET
{
  public:
    void ReplaceControllers(NiTimeController*);
};
class NiTimeController
{
};
class NiRTTI
{
};
class GlobalObject_00a7b610
{
};
extern GlobalObject_00a7b610 g_011dfeac;
class NiFixedString
{
  public:
    unsigned int handle;
    NiFixedString(const char*);
    ~NiFixedString();
};
const NiFixedString& FUN_00448a80();
class TESSound
{
  public:
    const char* FUN_00511840();
};
class TESChallenge
{
  public:
    TESForm* GetFormTwo();
};
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    bool FUN_005bb4d0();
    void Precache(const char*, unsigned int, void*);
};
union SETTING_VALUE
{
    float f;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
class GameSettingCollection;
template <class T> class SettingT
{
  public:
    char data[12];
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting35;
class BGSAcousticSpace
{
  public:
    void SetNoonSound(TESSound*);
};
class TESObjectDoorController : public NiTimeController
{
  public:
    char data[0x38];
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    TESObjectDoorController();
    void FUN_00929240(float);
    virtual void doorCtrlSlot0();
    virtual void doorCtrlSlot1();
    virtual void doorCtrlSlot2();
    virtual void doorCtrlSlot3();
    virtual void doorCtrlSlot4();
    virtual void doorCtrlSlot5();
    virtual void doorCtrlSlot6();
    virtual void doorCtrlSlot7();
    virtual void doorCtrlSlot8();
    virtual void doorCtrlSlot9();
    virtual void doorCtrlSlot10();
    virtual void doorCtrlSlot11();
    virtual void doorCtrlSlot12();
    virtual void doorCtrlSlot13();
    virtual void doorCtrlSlot14();
    virtual void doorCtrlSlot15();
    virtual void doorCtrlSlot16();
    virtual void doorCtrlSlot17();
    virtual void doorCtrlSlot18();
    virtual void doorCtrlSlot19();
    virtual void doorCtrlSlot20();
    virtual void doorCtrlSlot21();
    virtual void doorCtrlSlot22();
    virtual void doorCtrlSlot23();
    virtual void doorCtrlSlot24();
    virtual void doorCtrlSlot25();
    virtual void doorCtrlSlot26();
    virtual void doorCtrlSlot27();
    virtual void doorCtrlSlot28();
    virtual void doorCtrlSlot29();
    virtual void doorCtrlSlot30();
    virtual void doorCtrlSlot31();
    virtual void doorCtrlSlot32();
    virtual void doorCtrlSlot33();
    virtual void doorCtrlSlot34();
    virtual void doorCtrlSlot35();
    virtual void doorCtrlSlot36();
    virtual void doorCtrlSlot37();

    virtual void SetTarget(NiAVObject*);
};
class NiExtraData
{
  public:
    char data[0x10];
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    NiExtraData();
    void FUN_00519230(bool, bool);
};
class TESObjectDOOR : public TESBoundObject
{
  public:
    NiNode* Create3DModel(TESObjectREFR*);
    bool FUN_00517fa0();
    static void UpdateDoorNode(NiAVObject*);
};

extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)
template <class T> class NiPointer
{
  public:
    T* pointer;
    NiPointer(NiAVObject*);
    ~NiPointer();
    T* operator->() const;
};
class NiTexture;
class BGSCameraPath
{
  public:
    int HasNameForWarning();
};
class PlayerCharacter
{
  public:
    bool FUN_0050d4a0();
    float GetScale();
};
class CloningProcess
{
  public:
    unsigned int a, b, c, d, e, f, g;
    CloningProcess(float);
    ~CloningProcess();
};
class BSFadeNode : public NiNode
{
  public:
    char data[0xe0];
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    BSFadeNode();
};
class NiLight;
class TESObjectLIGH : public TESBoundObject
{
  public:
    char lightData[12];
    TESModel model;
    NiNode* Create3DModel(TESObjectREFR*);
    NiLight* CreateLight(TESObjectREFR*, NiAVObject*, bool);
};
