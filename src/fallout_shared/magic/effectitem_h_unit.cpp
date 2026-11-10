#include "../../../include/EffectItem.h"


// src: COMMUNITY 0x00403ea0
int EffectItem::GetActorValueIndex()
{
    return IsActorValueUsed() ? m_eAssociatedActorValue : -1;
}
