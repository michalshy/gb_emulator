#ifndef __GBCPU_H__
#define __GBCPU_H__

#include "GbCpuStructs.h"
#include <fstream>

class GbCpu{
	Registers regs;
	u8 VRAM[KiB16];
	u8 RAM[KiB32];
public:
	GbCpu();
	void LoadROM();
	void ProceedInstruction(u16);
};

#endif // !__GBCPU_H__
