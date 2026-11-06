
// fallout_shared/actionpoints.cpp
// ActionPoints::GetActionPoints (0x0066dda0).
//
// The restore-rate setting is a SettingT<GameSettingCollection> global whose
// vanilla reference accessors live on the shared Setting base class. The
// canonical generated Setting.h omits those vanilla accessors, so the needed
// declarations are authored locally for this TU.

#pragma pack(push, 4)
union SETTING_VALUE
{
  public:
    const char* str;  // +0x0
    int i;            // +0x0
    unsigned int u;   // +0x0
    float f;          // +0x0
    bool b;           // +0x0
    char c;           // +0x0
    unsigned char h;  // +0x0
};
#pragma pack(pop)

class GameSettingCollection
{
};

class SettingT_GameSettingCollection_
{
  public:
    SettingT_GameSettingCollection_();
    ~SettingT_GameSettingCollection_();
    SETTING_VALUE* Float();
};

extern SettingT_GameSettingCollection_ fActionPointsRestoreRate;

class ActionPoints
{
  public:
    static float GetActionPoints();
};

// @fnv 0x0066dda0
float ActionPoints::GetActionPoints()
{
    return fActionPointsRestoreRate.Float()->f;
}

// Returns true for action codes 0-8, 16, 17, 19, 20 and 21, and false for any other code.
// @fnv 0x0066dde0
bool IsAttackAction(int aeAction)
{
    switch (aeAction)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 16:
    case 17:
    case 19:
    case 20:
    case 21:
        return true;
    default:
        return false;
    }
}

// @fnv 0x0066dba0
int GetAttackAction(int aeWeaponType)
{
    int result = 22;
    if (aeWeaponType >= 0 && aeWeaponType < 14)
    {
        switch (aeWeaponType)
        {
        case 0:
            result = 0;
            break;
        case 1:
            result = 1;
            break;
        case 2:
            result = 2;
            break;
        case 3:
        case 4:
            result = 3;
            break;
        case 5:
        case 6:
        case 7:
            result = 4;
            break;
        case 8:
            result = 5;
            break;
        case 9:
            result = 6;
            break;
        case 10:
            result = 7;
            break;
        case 11:
            result = 8;
            break;
        case 13:
            result = 19;
            break;
        }
    }
    return result;
}

struct StartMenu
{
    char const* GetMenuTitle();
};

extern StartMenu* DAT_0119bb50[];

// @fnv 0x0066ddc0
char const* FUN_0066ddc0(int index)
{
    return DAT_0119bb50[index]->GetMenuTitle();
}
