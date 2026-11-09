extern unsigned char DAT_0109a914;
extern unsigned int vftable_NiBoolInterpolator;
extern unsigned int DAT_011f404c;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

inline void* operator new(unsigned int, NiBoolInterpController& p)
{
    return &p;
}
