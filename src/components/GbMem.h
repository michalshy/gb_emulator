#ifndef __GBMEM_H__
#define __GBMEM_H__

#include "../GbStructs.h"
#include <fstream>

class GbMem
{
	u8 ROM[KiB32];
	u8 VRAM[KiB8];
	u8 RAM[KiB8];
	u8 WRAM[KiB8];
	u8 OAM[BYTE160];
	u8 IO[BYTE128];
	u8 INTERRUPT;
	bool mInit;
public:
	GbMem() = default;
	bool Init(); // LOADING ROM HERE
	void WriteByte(u16 addr, u8 val);
	u8 ReadByte(u16 addr) const;
};

#endif

