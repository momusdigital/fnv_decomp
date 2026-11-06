
// src/fallout/interface/animatingtext.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/animatingtext.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Str6a70
{
    Str6a70& operator=(const char*);
};
struct FUN_00759f20_shell
{
    FUN_00759f20_shell* AssignString(const char* s);
    void FUN_006ffda0();
};
// Assigns the string s to this object, calls FUN_006ffda0, and returns this.
// @fnv 0x00759f20
FUN_00759f20_shell* FUN_00759f20_shell::AssignString(const char* apString)
{
    *(Str6a70*)this = apString;
    FUN_006ffda0();
    return this;
}

struct TwTile
{
    char pad00[8];
    float m_fAlpha;
    void FUN_00a0a270(float fValue, int iPropagate);
    void SetString(const char* pcText, int iPropagate);
};
unsigned int __cdecl FUN_00457fe0();
int __cdecl FUN_0044a670(const char* pcStr);
void __cdecl FUN_00401460(char* pcDest, const char* pcSrc, unsigned int uiCountZ);

struct TwTypewriter
{
    char pad00[8];
    TwTile* m_pkText;
    TwTile* m_pkCursor;
    unsigned int m_uiInterval;
    unsigned int m_uiBlinkOn;
    unsigned int m_uiBlinkOff;
    unsigned int m_uiNextTime;
    unsigned int m_uiNextBlink;
    char* m_pString;
    char pad28;
    bool m_bDone;

    bool FUN_007000b0();
    bool FUN_007000d0();
    const char* FUN_00559450();
    unsigned int FUN_004048e0();
    bool FUN_00700270(const char* pcText);
    void FUN_006ffea0();
};

// Advances the typewriter text and cursor blink when the interval elapses, copying characters into the buffer and marking the effect done at the end.
// @fnv 0x006ffea0
void TwTypewriter::FUN_006ffea0()
{
    if (FUN_007000b0() && FUN_00457fe0() >= m_uiNextTime && !m_bDone)
    {
        if (m_pkCursor && !FUN_007000d0())
            m_pkCursor->FUN_00a0a270(1.0f, 1);
        if (m_pkCursor && m_pkText && !FUN_00559450())
            m_pkCursor->FUN_00a0a270(0.0f, 1);
        if (m_pkText && m_pString && FUN_00700270(m_pString))
        {
            int iStartTmp = FUN_0044a670(m_pString);
            unsigned int uiCountZ = m_uiNextTime ? (FUN_00457fe0() - m_uiNextTime) / m_uiInterval + 1 : 1;
            if (uiCountZ > FUN_004048e0() - iStartTmp)
            {
                uiCountZ = FUN_004048e0() - iStartTmp;
                m_bDone = true;
            }
            FUN_00401460(m_pString + iStartTmp, FUN_00559450() + iStartTmp, uiCountZ);
            m_pkText->SetString(m_pString, 1);
        }
        else
        {
            m_bDone = true;
        }
        m_uiNextTime = FUN_00457fe0() + m_uiInterval;
    }
    if (FUN_007000d0() && FUN_00457fe0() >= m_uiNextBlink)
    {
        if (m_pkCursor->m_fAlpha == 1.0)
        {
            m_pkCursor->FUN_00a0a270(0.0f, 1);
            m_uiNextBlink = FUN_00457fe0() + m_uiBlinkOff;
        }
        else
        {
            m_pkCursor->FUN_00a0a270(1.0f, 1);
            m_uiNextBlink = FUN_00457fe0() + m_uiBlinkOn;
        }
    }
}

// ForceFinish: thiscall, /Od /GS, guarded float-state updates on member m_0c.
struct ObjC
{
    void FUN_00a0a270(float v, int flag);
};
struct ObjD
{
    void SetString(int a, int b);
};

extern "C" int __cdecl FUN_0044a670(int v);
extern "C" int __cdecl FUN_00401460(int a, int b, int c);

struct FUN_00700110_cls
{
    int unk00;
    int unk04;
    ObjD* m_08;
    ObjC* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_24;
    unsigned char unk28;
    unsigned char m_29;

    bool FUN_007000b0();
    bool FUN_007000d0();
    int FUN_00559450();
    void ForceFinish();
};

// @fnv 0x00700110
void FUN_00700110_cls::ForceFinish()
{
    if (FUN_007000b0())
    {
        if (m_29 == 0)
        {
            if (m_0c != 0)
            {
                if (!FUN_007000d0())
                {
                    m_0c->FUN_00a0a270(1.0f, 1);
                }
            }
            if (m_0c != 0 && m_08 != 0 && FUN_00559450() == 0)
            {
                m_0c->FUN_00a0a270(0.0f, 1);
            }
            if (m_08 != 0 && m_24 != 0)
            {
                FUN_00401460(m_24, FUN_00559450(), FUN_0044a670(FUN_00559450()));
                m_08->SetString(m_24, 1);
                m_29 = 1;
            }
        }
    }
}
