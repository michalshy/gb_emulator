#ifndef __GB_H__
#define __GB_H__

#include "GbCpu.h"
#include "GbPpu.h"
#include <fstream>
#include <iostream>

class Gb {

	u8 ROM[KiB32];

	// Memory segment
	u8 VRAM[KiB8];
	u8 RAM[KiB8];
	
	// CPU segment
	GbCpu cpu;

	// PPU segment
	GbPpu ppu;

	//Internal variables
	bool mInit;
	
public:
	// CONSTRUCTORS
	Gb() : mInit(false), cpu(ROM, RAM, VRAM) 
	{
		for (auto& el : VRAM)
		{
			el = 0;
		}
		for (auto& el : ROM)
		{
			el = 0;
		}
		for (auto& el : RAM)
		{
			el = 0;
		}
	}

	// Components functions
	void LoadROM();
	void EnterLoop();

	//Internal state functions
	bool IsActive();

protected:
};

#endif // !__GB_H__
