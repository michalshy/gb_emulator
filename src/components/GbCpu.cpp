#include "GbCpu.h"

bool GbCpu::Init()
{
    mInit = true;
    //ENTRY POINT
    regs.pc = 0x100;
    return true;
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

bool GbCpu::Fetch()
{
    if (regs.pc < KiB32)
    {
        opcode = mem.ReadByte(regs.pc);
        regs.pc++;
        return true;
    }
    return false;
}

bool GbCpu::Decode()
{
   auto instruction = this->instructions[opcode];
   if (instruction.func != NULL)
   {
       Logger::Debug(instruction);
       (this->*(instruction.func))();
       return true;
   }
   else
   {
       Logger::Error(instruction);
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
    if (res == 0)
        SetFlag(7);
    else
		ResetFlag(7);
    SetFlag(6);
    if ((regs.b & MASK_LOWER) - 1 > (regs.b & MASK_LOWER)) {
        SetFlag(5);
    }
    else
    {
		ResetFlag(5);
    }
    regs.b--;
}

void GbCpu::LD_B_D8()
{
    u8 load = mem.ReadByte(regs.pc);
    regs.pc++;
    regs.b = load;
}

void GbCpu::DEC_C()
{
    u8 res = regs.c - 1;
    if (res == 0)
        SetFlag(7);
    else
        ResetFlag(7);
    SetFlag(6);
    if ((regs.c & MASK_LOWER) - 1 > (regs.c & MASK_LOWER)) {
        SetFlag(5);
    }
    else
    {
        ResetFlag(5);
    }
    regs.c--;
}

void GbCpu::LD_C_D8()
{
    u8 load = mem.ReadByte(regs.pc);
    regs.pc++;
    regs.c = load;
}

void GbCpu::RRCA()
{
	u8 carry = regs.a & 1;
	regs.a = (regs.a >> 1) | (carry << 7);
	if (carry == 1)
		SetFlag(4);
	else
		ResetFlag(4);
	ResetFlag(5);
	ResetFlag(6);
	ResetFlag(7);
}

void GbCpu::JR_NZ_E8()
{
    s8 e = static_cast<s8>(mem.ReadByte(regs.pc));
    regs.pc++;
    if (regs.f >= 128)
    {
        regs.pc = static_cast<u16>(regs.pc + e);
    }
}

void GbCpu::LD_HL_N16()
{
    u16 lsb = mem.ReadByte(regs.pc);
    regs.pc++;
    u16 msb = mem.ReadByte(regs.pc);
    regs.pc++;
    regs.hl = (msb << 8) | lsb;
}

void GbCpu::LD_HLadd_M_A()
{
    mem.WriteByte(regs.hl, regs.a);
    regs.hl -= 1;
}

void GbCpu::LD_hl_n()
{
	u8 load = mem.ReadByte(regs.pc);
	regs.pc++;
	mem.WriteByte(regs.hl, load);
}

void GbCpu::LD_A_D8()
{
	u8 load = mem.ReadByte(regs.pc);
	regs.pc++;
	regs.a = load;
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
    u16 lsb = mem.ReadByte(regs.pc);
    regs.pc++;
    u16 msb = mem.ReadByte(regs.pc);
    regs.pc++;
    regs.pc = (msb << 8) | lsb;
}

void GbCpu::LD_n_A()
{
	u8 addr = mem.ReadByte(regs.pc);
	regs.pc++;
	mem.WriteByte(0xff00 + addr, regs.a);
}

void GbCpu::LD_c_A()
{
    mem.WriteByte(0xff00 + regs.c, regs.a);
}

void GbCpu::LD_nn_A()
{
	u16 addr = mem.ReadByte(regs.pc);
	regs.pc++;
	addr |= mem.ReadByte(regs.pc) << 8;
	regs.pc++;
	mem.WriteByte(addr, regs.a);
}

void GbCpu::LDH_A_n()
{
	u8 addr = mem.ReadByte(regs.pc);
	regs.pc++;
	regs.a = mem.ReadByte(0xff00 + addr);
}

void GbCpu::DI()
{
	mem.WriteByte(0xFFFF, 0);
}

void GbCpu::EI()
{
	mem.WriteByte(0xFFFF, 1);
}

void GbCpu::CP_A_n8()
{
    u8 n = mem.ReadByte(regs.pc);
	regs.pc++;
	u8 res = regs.a - n;
	if (res == 0)
		SetFlag(7);
	else
		ResetFlag(7);
	SetFlag(6);
	if ((regs.a & MASK_LOWER) - n > (regs.a & MASK_LOWER)) {
		SetFlag(5);
	}
	else
	{
		ResetFlag(5);
	}
	if (n > regs.a)
		SetFlag(4);
	else
		ResetFlag(4);
}
