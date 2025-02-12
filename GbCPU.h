#ifndef __GBCPU_H__
#define __GBCPU_H__

#include "GbStructs.h"
#include <cstdio>
#include <cstring>

class GbCpu{
	u8 opcode;
	Registers regs;
public:
	GbCpu();
	bool Fetch(u8(&memory)[KiB32]);
	void Decode();
};

#endif // !__GBCPU_H__
