#ifndef __GB_H__
#define __GB_H__

#include "components/GbCpu.h"
#include "components/GbPpu.h"
#include "components/GbMem.h"
#include <iostream>

class Gb {
	//Memory segment
	GbMem mem;
	// CPU segment
	GbCpu cpu;
	// PPU segment
	GbPpu ppu;
	//Internal variables
	bool mInit;
	
public:
	// CONSTRUCTORS
	Gb() : mInit(false), cpu(mem), ppu(mem) {}

	bool Init();

	// Components functions
	void EnterLoop();

	//Internal state functions
	bool IsActive();

protected:
};

#endif // !__GB_H__
