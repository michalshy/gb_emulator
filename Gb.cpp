#include "Gb.h"

void Gb::LoadROM()
{
    std::ifstream test;
    test.open("tetris.gb", std::ios::binary);
    if (test)
    {
        u8 romByte;
        u32 i = 0;
        while (test.read((char*)&romByte, sizeof(u8)))
        {
            RAM[i] = romByte;
            i++;
        }
        test.close();
        mInit = true;
    }
}

void Gb::EnterLoop()
{
    ppu.Init();
    while (mInit)
    {
        ppu.Render();

        if (cpu.Fetch(RAM))
        {
            cpu.Decode();
            std::cin.get();
        }
    }
}

bool Gb::IsActive()
{
    return mInit;
}
