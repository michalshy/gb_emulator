#ifndef __GBCPUSTRUCTS_H__
#define __GBCPUSTRUCTS_H__

#include "TypeDef.h"
#include <string>


// CONSTANTS
constexpr u8 MASK_RESET = 0b11111111;
constexpr u8 MASK_SET = 0b00000000;
constexpr u8 MASK_LOWER = 0b00001111;
constexpr u16 MASK_LOWER12 = 0b0000111111111111;
constexpr u8 MASK_BIT4 = 0b00001000;
constexpr u8 CARRY_MASK = 0b00010000;
constexpr u8 LEFT_BIT = 0b10000000;
constexpr u8 RIGHT_BIT = 0b00000001;

// PPU CONSTANTS
constexpr size_t RES_MULT = 4;
constexpr size_t WIDTH = 160;
constexpr size_t HEIGHT = 144;
constexpr size_t WIDTH_RES = WIDTH * RES_MULT;
constexpr size_t HEIGHT_RES = HEIGHT * RES_MULT;

// MEMORY OFFSETS
constexpr u16 ROM_START = 0x000;
constexpr u16 ROM_END = 0x7FFF;
constexpr u16 VRAM_START = 0x8000;
constexpr u16 VRAM_END = 0x9FFF;
constexpr u16 RAM_START = 0xA000;
constexpr u16 RAM_END = 0xBFFF;
constexpr u16 WRAM_START = 0xC000;
constexpr u16 WRAM_END = 0xDFFF;
constexpr u16 OAM_START = 0xFE00;
constexpr u16 OAM_END = 0xFE9F;
constexpr u16 IO_START = 0xFF00;
constexpr u16 IO_END = 0xFF7F;
constexpr u16 INTERRUPT_ENABLE = 0xFFFF;

// MEMORY SEGMENTS
constexpr size_t KiB8 = 8 * 1024;
constexpr size_t KiB16 = 16 * 1024;
constexpr size_t KiB32 = 32 * 1024;
constexpr size_t BYTE160 = 160;
constexpr size_t BYTE128 = 128;

// CPU INSTRUCTIONS
struct CpuInstruction
{
	std::string name;
	u8 size;
	CpuFunc func;
};

// CPU REGISTERS
struct Registers {
	union {
		struct {
			u8 a;
			u8 f;
		};
		u16 af; // AC and flags
	};
	union {
		struct {
			u8 b;
			u8 c;
		};
		u16 bc;
	};
	union {
		struct {
			u8 d;
			u8 e;
		};
		u16 de;
	};
	union {
		struct {
			u8 h;
			u8 l;
		};
		u16 hl;
	};
	u16 sp; //Stack pointer
	u16 pc; //Program Counter
};
#endif // !__GBCPUSTRUCTS_H__

