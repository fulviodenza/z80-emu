#pragma once
/*
    This is main header of the z80 emulator. This file contains
    most of data structures used in this project
*/

/*
    The instruction cycle is composed by an Opcode Fetch,
    a Memory read and a Memory Write.
    At the beginning of M1 machine cycle the PC is placed on the address bus
*/

typedef union
{
    uint8_t r1;
    uint8_t r2;
    uint16_t rr;
} z80_register;

typedef struct z80_info_s 
{
    z80_register m_regs[8];
    uint16_t m_pc;
    uint16_t m_sp;
    uint8_t m_index[2];
    int elapsed_cycles;

    struct {
        int c:1;
        int n:1;
        int pv:1;
        int h:1;
        int z:1;
        int s:1;
        int unused1:1;
        int unused2:1;
    } flags;
    
} z80_info_s;

z80_info_s z80;

#define A z80.m_regs[0].r1
#define F z80.m_regs[0].r2
#define AF z80.m_regs[0].rr
#define B z80.m_regs[1].r1
#define C z80.m_regs[1].r2
#define BC z80.m_regs[1].rr
#define D z80.m_regs[2].r1
#define E z80.m_regs[2].r2
#define DE z80.m_regs[2].rr
#define H z80.m_regs[3].r1
#define L z80.m_regs[3].r2
#define HL z80.m_regs[3].rr
#define A1 z80.m_regs[4].r1
#define F1 z80.m_regs[4].r2
#define AF1 z80.m_regs[4].rr
#define B1 z80.m_regs[5].r1
#define C1 z80.m_regs[5].r2
#define BC1 z80.m_regs[5].rr
#define D1 z80.m_regs[6].r1
#define E1 z80.m_regs[6].r2
#define DE1 z80.m_regs[6].rr
#define H1 z80.m_regs[7].r1
#define L1 z80.m_regs[7].r2
#define HL1 z80.m_regs[7].rr

#define PC z80.m_pc
#define SP z80.m_sp
#define IX z80.m_index[0]
#define IY z80.m_index[1]

uint8_t memory[32768];
