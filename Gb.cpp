
#include "Gb.h"

void Gb::LoadROM()
{
    u8 romByte;
    std::ifstream test;
    test.open("tetris.gb", std::ios::binary);
    if (test)
    {
        u32 i = 0;
        while (test.good() && !test.eof())
        {
            test.read((char*)&romByte, sizeof(u8));
            RAM[i] = romByte;
            i++;
        }
        test.close();
    }
    test.close();
}