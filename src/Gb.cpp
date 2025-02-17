#include "Gb.h"

bool Gb::Init()
{
    if (cpu.Init() && mem.Init() && ppu.Init())
    {
        mInit = true;
        return true;
    }
    return false;
}

void Gb::EnterLoop()
{
    bool running = true;
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
