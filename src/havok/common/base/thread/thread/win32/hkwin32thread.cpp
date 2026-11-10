// src/havok/common/base/thread/thread/win32/hkwin32thread.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/thread/thread/win32/hkwin32thread.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
class hkThread
{
  public:
    void hkThread_stopThread();

    HANDLE m_hHandle;
};

// @fnv 0x00d87920
// src: HAVOK_LIB 0x00d87920
void hkThread::hkThread_stopThread()
{
    if (m_hHandle != 0)
    {
        CloseHandle(m_hHandle);
        m_hHandle = 0;
    }
}
