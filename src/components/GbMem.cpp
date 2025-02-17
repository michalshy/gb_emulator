#include "GbMem.h"

bool GbMem::Init()
{
	std::ifstream test;
	test.open("tetris.gb", std::ios::binary);
	if (test)
	{
		u8 romByte;
		u32 i = 0;
		while (test.read((char*)&romByte, sizeof(u8)))
		{
			ROM[i] = romByte;
			i++;
		}
		test.close();
		mInit = true;
		return true;
	}
	return false;
}

void GbMem::WriteByte(u16 addr, u8 val)
{
	if (!mInit)
	{
		return;
	}

	if (addr >= VRAM_START && addr <= VRAM_END)
	{
		VRAM[addr - VRAM_START] = val;
	}
	else if (addr >= RAM_START && addr <= RAM_END)
	{
		RAM[addr - RAM_START] = val;
	}
	else if (addr >= WRAM_START && addr <= WRAM_END)
	{
		WRAM[addr - WRAM_START] = val;
	}
	else if (addr >= OAM_START && addr <= OAM_END)
	{
		OAM[addr - OAM_START] = val;
	}
	else if (addr >= IO_START && addr <= IO_END)
	{
		IO[addr - IO_START] = val;
	}
	else if (addr == INTERRUPT_ENABLE)
	{
		INTERRUPT = val;
	}
}

u8 GbMem::ReadByte(u16 addr) const
{
	if (mInit)
	{
		if (addr >= ROM_START && addr <= ROM_END) 
		{
			return ROM[addr];
		} 
		else if (addr >= VRAM_START && addr <= VRAM_END) 
		{
			return VRAM[addr - VRAM_START];
		}
		else if (addr >= RAM_START && addr <= RAM_END) 
		{
			return RAM[addr - RAM_START];
		}
		else if (addr >= WRAM_START && addr <= WRAM_END) 
		{
			return WRAM[addr - WRAM_START];
		}
		else if (addr >= OAM_START && addr <= OAM_END) 
		{
			return OAM[addr - OAM_START];
		}
		else if (addr >= IO_START && addr <= IO_END) 
		{
			return IO[addr - IO_START];
		}
		else if (addr == INTERRUPT_ENABLE)
		{
			return INTERRUPT;
		}
	}
}
