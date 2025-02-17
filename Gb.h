#ifndef __GB_H__
#define __GB_H__

#include "GbCpu.h"
#include "GbPpu.h"
#include "GbMem.h"
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
	Gb() : mInit(false), cpu(mem) {}

	bool Init();

	// Components functions
	void EnterLoop();

	//Internal state functions
	bool IsActive();

protected:
};

#endif // !__GB_H__
