#include "GbCpu.h"

GbCpu::GbCpu()
{
    opcode = 0;
    regs.sp = 0;
    regs.pc = 0;
    regs.af = 0;
    regs.bc = 0;
    regs.de = 0;
    regs.hl = 0;
}

/* 0 0 0 0 c(carry) h(half carrt) n(substraction) z(zero) */
void GbCpu::SetFlag(u8 bit)
{
    u8 toSet = (RIGHT_BIT << bit);
    regs.f |= toSet;
}

/* 0 0 0 0 c(carry) h(half carrt) n(substraction) z(zero) */
void GbCpu::ResetFlag(u8 bit)
{
    u8 toReset = (RIGHT_BIT << bit);
    regs.f &= ~toReset;
}

bool GbCpu::Fetch(u8 (&memory)[KiB32])
{
    if (regs.pc < KiB32)
    {
        opcode = memory[regs.pc];
        regs.pc++;
    }
    else
    {
        return true;
    }
}

void GbCpu::Decode(u8(&ram)[KiB8], u8(&rom)[KiB32])
{
    this->instructions[opcode];
}

void GbCpu::NOP()
{
}
