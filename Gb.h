#ifndef __GB_H__
#define __GB_H__

#include <fstream>
#include "GbCpu.h"

class Gb {
	GbCpu cpu;
	u8 VRAM[KiB16];
	u8 RAM[KiB32];
public:
	Gb() = default;
	void LoadROM();
};

#endif // !__GB_H__
