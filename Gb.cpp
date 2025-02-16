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
    bool running = true;
    ppu.Init();
    if (!mInit)
    {
        return;
    }
    while (running)
    {
        ppu.Render();

        if (cpu.Fetch())
        {
            if ( cpu.Decode() ) {
                /*
                    Correct
                */
            }
            else
            {
                Logger::FalseBreakpoint();
                running = false;
            }
        }
        else
        {
            running = false;
        }
    }
}

bool Gb::IsActive()
{
    return mInit;
}
