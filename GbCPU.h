#ifndef __GBCPU_H__
#define __GBCPU_H__

#include "GbStructs.h"
#include <cstdio>

class GbCpu{
	Registers regs;

public:
	GbCpu();
	void ProceedInstruction(u16);
};

#endif // !__GBCPU_H__
