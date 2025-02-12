#ifndef __GB_H__
#define __GB_H__

#include <fstream>
#include "GbCpu.h"
#include "GbPpu.h"

class Gb {

	// Memory segment
	u8 VRAM[KiB16];
	u8 RAM[KiB32];
	
	// CPU segment
	GbCpu cpu;

	// PPU segment
	GbPpu ppu;

	//Internal variables
	bool mInit;
	
public:
	// CONSTRUCTORS
	Gb() = default;

	// Components functions
	void LoadROM();
	void EnterLoop();

	//Internal state functions
	bool IsActive();

protected:
};

#endif // !__GB_H__
