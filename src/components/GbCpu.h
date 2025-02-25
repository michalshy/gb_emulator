#ifndef __GBCPU_H__
#define __GBCPU_H__

#include "../GbStructs.h"
#include <cstdio>
#include <cstring>
#include "../help/Logger.h"
#include "GbMem.h"

class GbCpu {
	u8 opcode;
	Registers regs;
    GbMem& mem;
    bool mInit;
public:
    GbCpu(GbMem& _mem) : mem(_mem), opcode(0), regs(), mInit(false) {}

    bool Init();

	void SetFlag(u8);
	void ResetFlag(u8);

	bool Fetch();
	bool Decode();

	Registers DumpRegs() const { return regs; }

protected:

	void NOP(); // 0x00
    void DEC_B(); //0x05
    void LD_B_D8(); // 0x06
    void DEC_C(); // 0x0D
    void LD_C_D8(); // 0x0E
	void RRCA(); // 0x0F
    void JR_NZ_E8(); // 0x20
    void LD_HL_N16(); // 0x21
    void LD_HLadd_M_A(); // 0x32
	void LD_hl_n(); // 0x36
	void LD_A_D8(); // 0x3E
    void XOR_A_B(); // 0xA8
    void XOR_A_A(); // 0xAF
    void JP_A16(); // 0xC3
	void LD_n_A(); // 0xE0
    void LD_c_A(); // 0xE2
	void LD_nn_A(); // 0xEA
    void LDH_A_n(); //0XF0
    void DI(); // 0xF3
	void EI(); // 0xFB
	void CP_A_n8(); // 0xFE

    const CpuInstruction instructions[256] = {
        {"NOP", 1, &GbCpu::NOP}, // 0x00
        {"LD BC, d16", 3, NULL}, // 0x01
        {"LD (BC), A", 1, NULL}, // 0x02
        {"INC BC", 1, NULL}, // 0x03
        {"INC B", 1, NULL}, // 0x04
        {"DEC B", 1, &GbCpu::DEC_B}, // 0x05
        {"LD B, d8", 2, &GbCpu::LD_B_D8}, // 0x06
        {"RLCA", 1, NULL}, // 0x07
        {"LD (a16), SP", 3, NULL}, // 0x08
        {"ADD HL, BC", 1, NULL}, // 0x09
        {"LD A, (BC)", 1, NULL}, // 0x0A
        {"DEC BC", 1, NULL}, // 0x0B
        {"INC C", 1, NULL}, // 0x0C
        {"DEC C", 1, &GbCpu::DEC_C}, // 0x0D
        {"LD C, d8", 2, &GbCpu::LD_C_D8}, // 0x0E
        {"RRCA", 1, &GbCpu::RRCA}, // 0x0F
        {"STOP 0", 2, NULL}, // 0x10
        {"LD DE, d16", 3, NULL}, // 0x11
        {"LD (DE), A", 1, NULL}, // 0x12
        {"INC DE", 1, NULL}, // 0x13
        {"INC D", 1, NULL}, // 0x14
        {"DEC D", 1, NULL}, // 0x15
        {"LD D, d8", 2, NULL}, // 0x16
        {"RLA", 1, NULL}, // 0x17
        {"JR r8", 2, NULL}, // 0x18
        {"ADD HL, DE", 1, NULL}, // 0x19
        {"LD A, (DE)", 1, NULL}, // 0x1A
        {"DEC DE", 1, NULL}, // 0x1B
        {"INC E", 1, NULL}, // 0x1C
        {"DEC E", 1, NULL}, // 0x1D
        {"LD E, d8", 2, NULL}, // 0x1E
        {"RRA", 1, NULL}, // 0x1F
        {"JR NZ, e8", 2, &GbCpu::JR_NZ_E8}, // 0x20
        {"LD HL, d16", 3, &GbCpu::LD_HL_N16}, // 0x21
        {"LD (HL+), A", 1, NULL}, // 0x22
        {"INC HL", 1, NULL}, // 0x23
        {"INC H", 1, NULL}, // 0x24
        {"DEC H", 1, NULL}, // 0x25
        {"LD H, d8", 2, NULL}, // 0x26
        {"DAA", 1, NULL}, // 0x27
        {"JR Z, r8", 2, NULL}, // 0x28
        {"ADD HL, HL", 1, NULL}, // 0x29
        {"LD A, (HL+)", 1, NULL}, // 0x2A
        {"DEC HL", 1, NULL}, // 0x2B
        {"INC L", 1, NULL}, // 0x2C
        {"DEC L", 1, NULL}, // 0x2D
        {"LD L, d8", 2, NULL}, // 0x2E
        {"CPL", 1, NULL}, // 0x2F
        {"JR NC, r8", 2, NULL}, // 0x30
        {"LD SP, d16", 3, NULL}, // 0x31
        {"LD (HL-), A", 1, &GbCpu::LD_HLadd_M_A}, // 0x32
        {"INC SP", 1, NULL}, // 0x33
        {"INC (HL)", 1, NULL}, // 0x34
        {"DEC (HL)", 1, NULL}, // 0x35
        {"LD (HL), d8", 2, &GbCpu::LD_hl_n}, // 0x36
        {"SCF", 1, NULL}, // 0x37
        {"JR C, r8", 2, NULL}, // 0x38
        {"ADD HL, SP", 1, NULL}, // 0x39
        {"LD A, (HL-)", 1, NULL}, // 0x3A
        {"DEC SP", 1, NULL}, // 0x3B
        {"INC A", 1, NULL}, // 0x3C
        {"DEC A", 1, NULL}, // 0x3D
        {"LD A, d8", 2, &GbCpu::LD_A_D8}, // 0x3E
        {"CCF", 1, NULL}, // 0x3F
        {"LD B, B", 1, NULL}, // 0x40
        {"LD B, C", 1, NULL}, // 0x41
        {"LD B, D", 1, NULL}, // 0x42
        {"LD B, E", 1, NULL}, // 0x43
        {"LD B, H", 1, NULL}, // 0x44
        {"LD B, L", 1, NULL}, // 0x45
        {"LD B, (HL)", 1, NULL}, // 0x46
        {"LD B, A", 1, NULL}, // 0x47
        {"LD C, B", 1, NULL}, // 0x48
        {"LD C, C", 1, NULL}, // 0x49
        {"LD C, D", 1, NULL}, // 0x4A
        {"LD C, E", 1, NULL}, // 0x4B
        {"LD C, H", 1, NULL}, // 0x4C
        {"LD C, L", 1, NULL}, // 0x4D
        {"LD C, (HL)", 1, NULL}, // 0x4E
        {"LD C, A", 1, NULL}, // 0x4F
        {"LD D, B", 1, NULL}, // 0x50
        {"LD D, C", 1, NULL}, // 0x51
        {"LD D, D", 1, NULL}, // 0x52
        {"LD D, E", 1, NULL}, // 0x53
        {"LD D, H", 1, NULL}, // 0x54
        {"LD D, L", 1, NULL}, // 0x55
        {"LD D, (HL)", 1, NULL}, // 0x56
        {"LD D, A", 1, NULL}, // 0x57
        {"LD E, B", 1, NULL}, // 0x58
        {"LD E, C", 1, NULL}, // 0x59
        {"LD E, D", 1, NULL}, // 0x5A
        {"LD E, E", 1, NULL}, // 0x5B
        {"LD E, H", 1, NULL}, // 0x5C
        {"LD E, L", 1, NULL}, // 0x5D
        {"LD E, (HL)", 1, NULL}, // 0x5E
        {"LD E, A", 1, NULL}, // 0x5F
        {"LD H, B", 1, NULL}, // 0x60
        {"LD H, C", 1, NULL}, // 0x61
        {"LD H, D", 1, NULL}, // 0x62
        {"LD H, E", 1, NULL}, // 0x63
        {"LD H, H", 1, NULL}, // 0x64
        {"LD H, L", 1, NULL}, // 0x65
        {"LD H, (HL)", 1, NULL}, // 0x66
        {"LD H, A", 1, NULL}, // 0x67
        {"LD L, B", 1, NULL}, // 0x68
        {"LD L, C", 1, NULL}, // 0x69
        {"LD L, D", 1, NULL}, // 0x6A
        {"LD L, E", 1, NULL}, // 0x6B
        {"LD L, H", 1, NULL}, // 0x6C
        {"LD L, L", 1, NULL}, // 0x6D
        {"LD L, (HL)", 1, NULL}, // 0x6E
        {"LD L, A", 1, NULL}, // 0x6F
        {"LD (HL), B", 1, NULL}, // 0x70
        {"LD (HL), C", 1, NULL}, // 0x71
        {"LD (HL), D", 1, NULL}, // 0x72
        {"LD (HL), E", 1, NULL}, // 0x73
        {"LD (HL), H", 1, NULL}, // 0x74
        {"LD (HL), L", 1, NULL}, // 0x75
        {"HALT", 1, NULL}, // 0x76
        {"LD (HL), A", 1, NULL}, // 0x77
        {"LD A, B", 1, NULL}, // 0x78
        {"LD A, C", 1, NULL}, // 0x79
        {"LD A, D", 1, NULL}, // 0x7A
        {"LD A, E", 1, NULL}, // 0x7B
        {"LD A, H", 1, NULL}, // 0x7C
        {"LD A, L", 1, NULL}, // 0x7D
        {"LD A, (HL)", 1, NULL}, // 0x7E
        {"LD A, A", 1, NULL}, // 0x7F
        {"ADD A, B", 1, NULL}, // 0x80
        {"ADD A, C", 1, NULL}, // 0x81
        {"ADD A, D", 1, NULL}, // 0x82
        {"ADD A, E", 1, NULL}, // 0x83
        {"ADD A, H", 1, NULL}, // 0x84
        {"ADD A, L", 1, NULL}, // 0x85
        {"ADD A, (HL)", 1, NULL}, // 0x86
        {"ADD A, A", 1, NULL}, // 0x87
        {"ADC A, B", 1, NULL}, // 0x88
        {"ADC A, C", 1, NULL}, // 0x89
        {"ADC A, D", 1, NULL}, // 0x8A
        {"ADC A, E", 1, NULL}, // 0x8B
        {"ADC A, H", 1, NULL}, // 0x8C
        {"ADC A, L", 1, NULL}, // 0x8D
        {"ADC A, (HL)", 1, NULL}, // 0x8E
        {"ADC A, A", 1, NULL}, // 0x8F
        {"SUB B", 1, NULL}, // 0x90
        {"SUB C", 1, NULL}, // 0x91
        {"SUB D", 1, NULL}, // 0x92
        {"SUB E", 1, NULL}, // 0x93
        {"SUB H", 1, NULL}, // 0x94
        {"SUB L", 1, NULL}, // 0x95
        {"SUB (HL)", 1, NULL}, // 0x96
        {"SUB A", 1, NULL}, // 0x97
        {"SBC A, B", 1, NULL}, // 0x98
        {"SBC A, C", 1, NULL}, // 0x99
        {"SBC A, D", 1, NULL}, // 0x9A
        {"SBC A, E", 1, NULL}, // 0x9B
        {"SBC A, H", 1, NULL}, // 0x9C
        {"SBC A, L", 1, NULL}, // 0x9D
        {"SBC A, (HL)", 1, NULL}, // 0x9E
        {"SBC A, A", 1, NULL}, // 0x9F
        {"AND B", 1, NULL}, // 0xA0
        {"AND C", 1, NULL}, // 0xA1
        {"AND D", 1, NULL}, // 0xA2
        {"AND E", 1, NULL}, // 0xA3
        {"AND H", 1, NULL}, // 0xA4
        {"AND L", 1, NULL}, // 0xA5
        {"AND (HL)", 1, NULL}, // 0xA6
        {"AND A, B", 1, NULL}, // 0xA7
        {"XOR A, B", 1, &GbCpu::XOR_A_B }, // 0xA8
        {"XOR A, C", 1, NULL}, // 0xA9
        {"XOR A, D", 1, NULL}, // 0xAA
        {"XOR A, E", 1, NULL}, // 0xAB
        {"XOR A, H", 1, NULL}, // 0xAC
        {"XOR A, L", 1, NULL}, // 0xAD
        {"XOR A, (HL)", 1, NULL}, // 0xAE
        {"XOR A, A", 1, &GbCpu::XOR_A_B }, // 0xAF
        {"OR B", 1, NULL}, // 0xB0
        {"OR C", 1, NULL}, // 0xB1
        {"OR D", 1, NULL}, // 0xB2
        {"OR E", 1, NULL}, // 0xB3
        {"OR H", 1, NULL}, // 0xB4
        {"OR L", 1, NULL}, // 0xB5
        {"OR (HL)", 1, NULL}, // 0xB6
        {"OR A", 1, NULL}, // 0xB7
        {"CP B", 1, NULL}, // 0xB8
        {"CP C", 1, NULL}, // 0xB9
        {"CP D", 1, NULL}, // 0xBA
        {"CP E", 1, NULL}, // 0xBB
        {"CP H", 1, NULL}, // 0xBC
        {"CP L", 1, NULL}, // 0xBD
        {"CP (HL)", 1, NULL}, // 0xBE
        {"CP A", 1, NULL}, // 0xBF
        {"RET NZ", 1, NULL}, // 0xC0
        {"POP BC", 1, NULL}, // 0xC1
        {"JP NZ, a16", 3, NULL}, // 0xC2
        {"JP a16", 3, &GbCpu::JP_A16 }, // 0xC3
        {"CALL NZ, a16", 3, NULL}, // 0xC4
        {"PUSH BC", 1, NULL}, // 0xC5
        {"ADD A, d8", 2, NULL}, // 0xC6
        {"RST 00H", 1, NULL}, // 0xC7
        {"RET Z", 1, NULL}, // 0xC8
        {"RET", 1, NULL}, // 0xC9
        {"JP Z, a16", 3, NULL}, // 0xCA
        {"PREFIX", 1, NULL}, // 0xCB
        {"CALL Z, a16", 3, NULL}, // 0xCC
        {"CALL a16", 3, NULL}, // 0xCD
        {"ADC A, d8", 2, NULL}, // 0xCE
        {"RST 08H", 1, NULL}, // 0xCF
        {"RET NC", 1, NULL}, // 0xD0
        {"POP DE", 1, NULL}, // 0xD1
        {"JP NC, a16", 3, NULL}, // 0xD2
        {"NULL", 0, NULL}, // 0xD3
        {"CALL NC, a16", 3, NULL}, // 0xD4
        {"PUSH DE", 1, NULL}, // 0xD5
        {"SUB d8", 2, NULL}, // 0xD6
        {"RST 10H", 1, NULL}, // 0xD7
        {"RET C", 1, NULL}, // 0xD8
        {"RETI", 1, NULL}, // 0xD9
        { "JP C, a16", 3, NULL }, // 0xDA
        { "CALL C, a16", 3, NULL }, // 0xDB
        { "SBC A, d8", 2, NULL }, // 0xDC
        { "RST 18H", 1, NULL }, // 0xDD
        { "LD (a8), A", 2, NULL }, // 0xDE
        { "POP HL", 1, NULL }, // 0xDF
        { "LD (n), A", 1, &GbCpu::LD_n_A } , // 0xE0
        { "PUSH HL", 1, NULL }, // 0xE1
        { "AND d8", 2, NULL }, // 0xE2
        { "RST 20H", 1, NULL }, // 0xE3
        { "ADD SP, r8", 2, NULL }, // 0xE4
        { "JP (HL)", 1, NULL }, // 0xE5
        { "LD (a16), A", 3, NULL }, // 0xE6
        { "XOR d8", 2, NULL }, // 0xE7
        { "RST 28H", 1, NULL }, // 0xE8
        { "LD A, (a8)", 2, NULL }, // 0xE9
        { "LD (nn), A", 3, &GbCpu::LD_nn_A }, // 0xEA
        { "LD A, (C)", 1, NULL }, // 0xEB
        { "DI", 1, NULL }, // 0xEC
        { "PUSH AF", 1, NULL }, // 0xED
        { "PUSH AF", 1, NULL }, // 0xEE
        { "OR d8", 2, NULL }, // 0xEF
        { "LDH A, (a8)", 1, &GbCpu::LDH_A_n }, // 0xF0
        { "LD HL, SP+r8", 2, NULL }, // 0xF1
        { "LD SP, HL", 1, NULL }, // 0xF2
        { "DI", 3, &GbCpu::DI }, // 0xF3
        { "EI", 1, NULL}, // 0xF4
        { "CP d8", 2, NULL }, // 0xF5
        { "OR A, n8", 1, NULL }, // 0xF6
        { "RST $30", 1, NULL }, // 0xF7
        { "LD HL, SP + e8", 1, NULL }, // 0xF8
        { "LD SP, HL", 1, NULL }, // 0xF9
        { "LD A, [a16]", 1, NULL }, // 0xFA
        { "EI", 1, &GbCpu::EI }, // 0xFB
        { "-", 1, NULL }, // 0xFC
        { "-", 1, NULL }, // 0xFD
        { "CP A, n8", 1, &GbCpu::CP_A_n8 }, // 0xFE
        { "RST $38", 1, NULL }, // 0xFF
    };
};

#endif // !__GBCPU_H__
