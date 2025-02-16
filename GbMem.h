#ifndef __GBMEM_H__
#define __GBMEM_H__

#include "GbStructs.h"

class GbMem
{
public:
	void WriteByte(u16 addr, u8 val);
	u8 ReadByte(u16 addr);
};

#endif

