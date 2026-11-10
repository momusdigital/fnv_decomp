#ifndef FNV_RESPONSELISTWRAPPER_H
#define FNV_RESPONSELISTWRAPPER_H

#include "testopicinfo_topicinfo_layout_support.h"
class TESResponseList
{
  public:
    TESResponse* pHead;  // +0x0
    void ClearResponses();
    TESResponse* QResponseList();
    void ResponseListWrapper_CopyResponseList(TESResponse* head);
    void AddTail(TESResponse* response);
};
FNV_STATIC_ASSERT(sizeof(TESResponseList) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESResponseList, pHead) == 0x0);
#endif
