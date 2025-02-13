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

	void SetFlag(u8);
	void ResetFlag(u8);

	bool Fetch(u8(&memory)[KiB32]);
	
	/* LOAD INSTRUCTIONS */

	/* 8-BIT ARITHMETIC INSTRUCTIONS */
	void ADC(u8&);
	void ADD(u8&);
	void ADD(u16& from, u16& to);
	void ADD(s8 from, u16& to);
	void CP(u8&);
	void DEC(u8&);
	void INC(u8&);
	void SBC(u8&);
	void SUB(u8&);

	/* 16-BIT ARITHMETIC INSTRUCTIONS */

	/* BITWISE INSTRUCTIONS */

	/* BIT FLAG INSTRUCTIONS */

	/* BIT SHIFT INSTRUCTIONS */

	/* JUMPS AND SUBROUTINES INSTRUCTIONS */

	/* CARRY FLAG INSTRUCTIONS */

	/* STACK MANIPULATION INSTRUCTIONS */

	/* INTERRUPT RELATED INSTRUCTIONS */

	/* MISCELLANEOUS INSTRUCTIONS */
	void Decode(u8(&ram)[KiB8], u8(&rom)[KiB32]);

	Registers DumpRegs() const { return regs; }

protected:
	void CheckCarries(u8, u8);
	void CheckCarries(u16, u16);
};

#endif // !__GBCPU_H__
