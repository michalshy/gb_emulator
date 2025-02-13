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
    u8 toSet = (RIGHT_BIT << (bit - 1));
    regs.f |= toSet;
}

/* 0 0 0 0 c(carry) h(half carrt) n(substraction) z(zero) */
void GbCpu::ResetFlag(u8 bit)
{
    u8 toReset = (RIGHT_BIT << (bit - 1));
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

void GbCpu::ADC(u8& reg)
{
    u8 toAdd = reg + (regs.f & 0b00001000);
    ADD(toAdd);
}

void GbCpu::ADD(u8& reg)
{
    regs.a += reg;
    if (regs.a == 0)
    {

    }
}
void GbCpu::ADD(u16& from, u16& to)
{
    to += from;
}
void GbCpu::ADD(s8 from, u16& to)
{
    to += from;
}

void GbCpu::CP(u8&)
{
}

void GbCpu::DEC(u8&)
{
}

void GbCpu::INC(u8&)
{
}

void GbCpu::SBC(u8&)
{
}

void GbCpu::SUB(u8&)
{
}

void GbCpu::Decode(u8(&ram)[KiB8], u8(&rom)[KiB32])
{
    printf("Process opcode :0x%02x\n", opcode);
    switch (opcode) {
    case 0x00:
        // Handle opcode 0x00
        break;
    case 0x01:
        // Handle opcode 0x01
        break;
    case 0x02:
        // Handle opcode 0x02
        break;
    case 0x03:
        // Handle opcode 0x03
        break;
    case 0x04:
        // Handle opcode 0x04
        break;
    case 0x05:
        // Handle opcode 0x05
        break;
    case 0x06:
        // Handle opcode 0x06
        break;
    case 0x07:
        // Handle opcode 0x07
        break;
    case 0x08:
        // Handle opcode 0x08
        break;
    case 0x09:
        ADD(regs.bc, regs.hl);
        break;
    case 0x0A:
        // Handle opcode 0x0A
        break;
    case 0x0B:
        // Handle opcode 0x0B
        break;
    case 0x0C:
        // Handle opcode 0x0C
        break;
    case 0x0D:
        // Handle opcode 0x0D
        break;
    case 0x0E:
        // Handle opcode 0x0E
        break;
    case 0x0F:
        // Handle opcode 0x0F
        break;
    case 0x10:
        // Handle opcode 0x10
        break;
    case 0x11:
        // Handle opcode 0x11
        break;
    case 0x12:
        // Handle opcode 0x12
        break;
    case 0x13:
        // Handle opcode 0x13
        break;
    case 0x14:
        // Handle opcode 0x14
        break;
    case 0x15:
        // Handle opcode 0x15
        break;
    case 0x16:
        // Handle opcode 0x16
        break;
    case 0x17:
        // Handle opcode 0x17
        break;
    case 0x18:
        // Handle opcode 0x18
        break;
    case 0x19:
        ADD(regs.de, regs.hl);
        break;
    case 0x1A:
        // Handle opcode 0x1A
        break;
    case 0x1B:
        // Handle opcode 0x1B
        break;
    case 0x1C:
        // Handle opcode 0x1C
        break;
    case 0x1D:
        // Handle opcode 0x1D
        break;
    case 0x1E:
        // Handle opcode 0x1E
        break;
    case 0x1F:
        // Handle opcode 0x1F
        break;
    case 0x20:
        // Handle opcode 0x20
        break;
    case 0x21:
        // Handle opcode 0x21
        break;
    case 0x22:
        // Handle opcode 0x22
        break;
    case 0x23:
        // Handle opcode 0x23
        break;
    case 0x24:
        // Handle opcode 0x24
        break;
    case 0x25:
        // Handle opcode 0x25
        break;
    case 0x26:
        // Handle opcode 0x26
        break;
    case 0x27:
        // Handle opcode 0x27
        break;
    case 0x28:
        // Handle opcode 0x28
        break;
    case 0x29:
        ADD(regs.hl, regs.hl);
        break;
    case 0x2A:
        // Handle opcode 0x2A
        break;
    case 0x2B:
        // Handle opcode 0x2B
        break;
    case 0x2C:
        // Handle opcode 0x2C
        break;
    case 0x2D:
        // Handle opcode 0x2D
        break;
    case 0x2E:
        // Handle opcode 0x2E
        break;
    case 0x2F:
        // Handle opcode 0x2F
        break;
    case 0x30:
        // Handle opcode 0x30
        break;
    case 0x31:
        // Handle opcode 0x31
        break;
    case 0x32:
        // Handle opcode 0x32
        break;
    case 0x33:
        // Handle opcode 0x33
        break;
    case 0x34:
        // Handle opcode 0x34
        break;
    case 0x35:
        // Handle opcode 0x35
        break;
    case 0x36:
        // Handle opcode 0x36
        break;
    case 0x37:
        // Handle opcode 0x37
        break;
    case 0x38:
        // Handle opcode 0x38
        break;
    case 0x39:
        ADD(regs.sp, regs.hl);
        break;
    case 0x3A:
        // Handle opcode 0x3A
        break;
    case 0x3B:
        // Handle opcode 0x3B
        break;
    case 0x3C:
        // Handle opcode 0x3C
        break;
    case 0x3D:
        // Handle opcode 0x3D
        break;
    case 0x3E:
        // Handle opcode 0x3E
        break;
    case 0x3F:
        // Handle opcode 0x3F
        break;
    case 0x40:
        // Handle opcode 0x40
        break;
    case 0x41:
        // Handle opcode 0x41
        break;
    case 0x42:
        // Handle opcode 0x42
        break;
    case 0x43:
        // Handle opcode 0x43
        break;
    case 0x44:
        // Handle opcode 0x44
        break;
    case 0x45:
        // Handle opcode 0x45
        break;
    case 0x46:
        // Handle opcode 0x46
        break;
    case 0x47:
        // Handle opcode 0x47
        break;
    case 0x48:
        // Handle opcode 0x48
        break;
    case 0x49:
        // Handle opcode 0x49
        break;
    case 0x4A:
        // Handle opcode 0x4A
        break;
    case 0x4B:
        // Handle opcode 0x4B
        break;
    case 0x4C:
        // Handle opcode 0x4C
        break;
    case 0x4D:
        // Handle opcode 0x4D
        break;
    case 0x4E:
        // Handle opcode 0x4E
        break;
    case 0x4F:
        // Handle opcode 0x4F
        break;
    case 0x50:
        // Handle opcode 0x50
        break;
    case 0x51:
        // Handle opcode 0x51
        break;
    case 0x52:
        // Handle opcode 0x52
        break;
    case 0x53:
        // Handle opcode 0x53
        break;
    case 0x54:
        // Handle opcode 0x54
        break;
    case 0x55:
        // Handle opcode 0x55
        break;
    case 0x56:
        // Handle opcode 0x56
        break;
    case 0x57:
        // Handle opcode 0x57
        break;
    case 0x58:
        // Handle opcode 0x58
        break;
    case 0x59:
        // Handle opcode 0x59
        break;
    case 0x5A:
        // Handle opcode 0x5A
        break;
    case 0x5B:
        // Handle opcode 0x5B
        break;
    case 0x5C:
        // Handle opcode 0x5C
        break;
    case 0x5D:
        // Handle opcode 0x5D
        break;
    case 0x5E:
        // Handle opcode 0x5E
        break;
    case 0x5F:
        // Handle opcode 0x5F
        break;
    case 0x60:
        // Handle opcode 0x60
        break;
    case 0x61:
        // Handle opcode 0x61
        break;
    case 0x62:
        // Handle opcode 0x62
        break;
    case 0x63:
        // Handle opcode 0x63
        break;
    case 0x64:
        // Handle opcode 0x64
        break;
    case 0x65:
        // Handle opcode 0x65
        break;
    case 0x66:
        // Handle opcode 0x66
        break;
    case 0x67:
        // Handle opcode 0x67
        break;
    case 0x68:
        // Handle opcode 0x68
        break;
    case 0x69:
        // Handle opcode 0x69
        break;
    case 0x6A:
        // Handle opcode 0x6A
        break;
    case 0x6B:
        // Handle opcode 0x6B
        break;
    case 0x6C:
        // Handle opcode 0x6C
        break;
    case 0x6D:
        // Handle opcode 0x6D
        break;
    case 0x6E:
        // Handle opcode 0x6E
        break;
    case 0x6F:
        // Handle opcode 0x6F
        break;
    case 0x70:
        // Handle opcode 0x70
        break;
    case 0x71:
        // Handle opcode 0x71
        break;
    case 0x72:
        // Handle opcode 0x72
        break;
    case 0x73:
        // Handle opcode 0x73
        break;
    case 0x74:
        // Handle opcode 0x74
        break;
    case 0x75:
        // Handle opcode 0x75
        break;
    case 0x76:
        // Handle opcode 0x76
        break;
    case 0x77:
        // Handle opcode 0x77
        break;
    case 0x78:
        // Handle opcode 0x78
        break;
    case 0x79:
        // Handle opcode 0x79
        break;
    case 0x7A:
        // Handle opcode 0x7A
        break;
    case 0x7B:
        // Handle opcode 0x7B
        break;
    case 0x7C:
        // Handle opcode 0x7C
        break;
    case 0x7D:
        // Handle opcode 0x7D
        break;
    case 0x7E:
        // Handle opcode 0x7E
        break;
    case 0x7F:
        // Handle opcode 0x7F
        break;
    case 0x80:
        ADD(regs.b);
        break;
    case 0x81:
        ADD(regs.c);
        break;
    case 0x82:
        ADD(regs.d);
        break;
    case 0x83:
        ADD(regs.e);
        break;
    case 0x84:
        ADD(regs.h);
        break;
    case 0x85:
        ADD(regs.l);
        break;
    case 0x86:
        ADD(ram[regs.hl]);
        break;
    case 0x87:
        ADD(regs.a);
        break;
    case 0x88:
        ADC(regs.b);
        break;
    case 0x89:
        ADC(regs.c);
        break;
    case 0x8A:
        ADC(regs.d);
        break;
    case 0x8B:
        ADC(regs.e);
        break;
    case 0x8C:
        ADC(regs.h);
        break;
    case 0x8D:
        ADC(regs.l);
        break;
    case 0x8E:
        ADC(ram[regs.hl]);
        break;
    case 0x8F:
        ADC(regs.a);
        break;
    case 0x90:
        // Handle opcode 0x90
        break;
    case 0x91:
        // Handle opcode 0x91
        break;
    case 0x92:
        // Handle opcode 0x92
        break;
    case 0x93:
        // Handle opcode 0x93
        break;
    case 0x94:
        // Handle opcode 0x94
        break;
    case 0x95:
        // Handle opcode 0x95
        break;
    case 0x96:
        // Handle opcode 0x96
        break;
    case 0x97:
        // Handle opcode 0x97
        break;
    case 0x98:
        // Handle opcode 0x98
        break;
    case 0x99:
        // Handle opcode 0x99
        break;
    case 0x9A:
        // Handle opcode 0x9A
        break;
    case 0x9B:
        // Handle opcode 0x9B
        break;
    case 0x9C:
        // Handle opcode 0x9C
        break;
    case 0x9D:
        // Handle opcode 0x9D
        break;
    case 0x9E:
        // Handle opcode 0x9E
        break;
    case 0x9F:
        // Handle opcode 0x9F
        break;
    case 0xA0:
        // Handle opcode 0xA0
        break;
    case 0xA1:
        // Handle opcode 0xA1
        break;
    case 0xA2:
        // Handle opcode 0xA2
        break;
    case 0xA3:
        // Handle opcode 0xA3
        break;
    case 0xA4:
        // Handle opcode 0xA4
        break;
    case 0xA5:
        // Handle opcode 0xA5
        break;
    case 0xA6:
        // Handle opcode 0xA6
        break;
    case 0xA7:
        // Handle opcode 0xA7
        break;
    case 0xA8:
        // Handle opcode 0xA8
        break;
    case 0xA9:
        // Handle opcode 0xA9
        break;
    case 0xAA:
        // Handle opcode 0xAA
        break;
    case 0xAB:
        // Handle opcode 0xAB
        break;
    case 0xAC:
        // Handle opcode 0xAC
        break;
    case 0xAD:
        // Handle opcode 0xAD
        break;
    case 0xAE:
        // Handle opcode 0xAE
        break;
    case 0xAF:
        // Handle opcode 0xAF
        break;
    case 0xB0:
        // Handle opcode 0xB0
        break;
    case 0xB1:
        // Handle opcode 0xB1
        break;
    case 0xB2:
        // Handle opcode 0xB2
        break;
    case 0xB3:
        // Handle opcode 0xB3
        break;
    case 0xB4:
        // Handle opcode 0xB4
        break;
    case 0xB5:
        // Handle opcode 0xB5
        break;
    case 0xB6:
        // Handle opcode 0xB6
        break;
    case 0xB7:
        // Handle opcode 0xB7
        break;
    case 0xB8:
        break;
    case 0xB9:
        break;
    case 0xBA:
        break;
    case 0xBB:
        break;
    case 0xBC:
        break;
    case 0xBD:
        break;
    case 0xBE:
        break;
    case 0xBF:
        break;
    case 0xC0:
        break;
    case 0xC1:
        break;
    case 0xC2:
        break;
    case 0xC3:
        break;
    case 0xC4:
        break;
    case 0xC5:
        break;
    case 0xC6:
        ADD(rom[regs.pc]);
        regs.pc++;
        break;
    case 0xC7:
        break;
    case 0xC8:
        break;
    case 0xC9:
        break;
    case 0xCA:
        break;
    case 0xCB:
        break;
    case 0xCC:
        break;
    case 0xCD:
        break;
    case 0xCE:
        ADC(rom[regs.pc]);
        regs.pc++;
        break;
    case 0xCF:
        break;
    case 0xD0:
        break;
    case 0xD1:
        break;
    case 0xD2:
        break;
    case 0xD3:
        break;
    case 0xD4:
        break;
    case 0xD5:
        break;
    case 0xD6:
        break;
    case 0xD7:
        break;
    case 0xD8:
        break;
    case 0xD9:
        break;
    case 0xDA:
        break;
    case 0xDB:
        break;
    case 0xDC:
        break;
    case 0xDD:
        break;
    case 0xDE:
        break;
    case 0xDF:
        break;
    case 0xE0:
        break;
    case 0xE1:
        break;
    case 0xE2:
        break;
    case 0xE3:
        break;
    case 0xE4:
        break;
    case 0xE5:
        break;
    case 0xE6:
        break;
    case 0xE7:
        break;
    case 0xE8:
        ADD(static_cast<s8>(rom[regs.pc]), regs.sp);
        regs.pc++;
        break;
    case 0xE9:
        break;
    case 0xEA:
        break;
    case 0xEB:
        break;
    case 0xEC:
        break;
    case 0xED:
        break;
    case 0xEE:
        break;
    case 0xEF:
        break;
    case 0xF0:
        break;
    case 0xF1:
        break;
    case 0xF2:
        break;
    case 0xF3:
        break;
    case 0xF4:
        break;
    case 0xF5:
        break;
    case 0xF6:
        break;
    case 0xF7:
        break;
    case 0xF8:
        break;
    case 0xF9:
        break;
    case 0xFA:
        break;
    case 0xFB:
        break;
    case 0xFC:
        break;
    case 0xFD:
        break;
    case 0xFE:
        break;
    case 0xFF:
        break;
    default:
        printf("Invalid opcode! :0x%08x\n", opcode);
        break;
    }
}

