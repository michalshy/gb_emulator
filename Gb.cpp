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
            ROM[i] = romByte;
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

        if (cpu.Fetch(ROM))
        {
            cpu.Decode(RAM, ROM);
            //std::cin.get();
        }
    }
}

bool Gb::IsActive()
{
    return mInit;
}
