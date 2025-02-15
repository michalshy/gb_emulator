#ifndef __GBCPU_H__
#define __GBCPU_H__

#include "GbStructs.h"
#include <cstdio>
#include <cstring>

class GbCpu {
	u8 opcode;
	Registers regs;
public:
	GbCpu();

	void SetFlag(u8);
	void ResetFlag(u8);

	bool Fetch(u8(&memory)[KiB32]);
	void Decode(u8(&ram)[KiB8], u8(&rom)[KiB32]);

	Registers DumpRegs() const { return regs; }

protected:

	void NOP();

	const CpuInstruction instructions[256] = {
		{"NULL", 0, &GbCpu::NOP},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
		{"NULL", 0, NULL},
	};
};

#endif // !__GBCPU_H__
