#include "GbCpu.h"

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

bool GbCpu::Fetch()
{
    if (regs.pc < KiB32)
    {
        opcode = ROM[regs.pc];
        regs.pc++;
        return true;
    }
    return false;
}

bool GbCpu::Decode()
{
   auto instruction = this->instructions[opcode];
   //Logger::Debug(regs);
   if (instruction.func != NULL)
   {
       //Logger::Debug(instruction);
       (this->*(instruction.func))();
       return true;
   }
   else
   {
       //Logger::Error(instruction);
       return false;
   }
}

void GbCpu::NOP()
{
   /*
   Do nothing
   */
}

void GbCpu::DEC_B()
{
    u8 res = regs.b - 1;
    if (res == 0) SetFlag(7);
    SetFlag(6);
    if ((regs.b & MASK_LOWER) - 1 > (regs.b & MASK_LOWER)) {
        SetFlag(5);
    }
}

void GbCpu::LD_B_D8()
{
    u8 load = ROM[regs.pc++];
    regs.b = load;
}

void GbCpu::LD_C_D8()
{
    u8 load = ROM[regs.pc++];
    regs.c = load;
}

void GbCpu::JR_NZ_E8()
{
    s8 e = static_cast<s8>(ROM[regs.pc++]);
    if (regs.f >= 128)
    {
        regs.pc = static_cast<u16>(regs.pc + e);
    }
}

void GbCpu::LD_HL_N16()
{
    u16 lsb = ROM[regs.pc++];
    u16 msb = ROM[regs.pc++];
    regs.hl = (msb << 8) | lsb;
}

void GbCpu::LD_HLadd_M_A()
{
    //RAM[regs.hl] = regs.a; TODO: FIX crash?
    regs.hl -= 1;
}

void GbCpu::XOR_A_B()
{
    u8 res = regs.a ^ regs.b;
    regs.a = res;
    if (res == 0)
        regs.f = 128;
    else
        regs.f = 0;
}

void GbCpu::XOR_A_A()
{
    u8 res = regs.a ^ regs.a;
    regs.a = res;
    if (res == 0)
        regs.f = 128;
    else
        regs.f = 0;
}

void GbCpu::JP_A16()
{
    u16 lsb = ROM[regs.pc++];
    u16 msb = ROM[regs.pc++];
    regs.pc = (msb << 8) | lsb;
}
