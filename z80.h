/*
    This is main header of the z80 emulator. This file contains
    most of data structures used in this project
*/

/*
    The instruction cycle is composed by an Opcode Fetch,
    a Memory read and a Memory Write.
    At the beginning of M1 machine cycle the PC is placed on the address bus
*/

typedef struct z80_info_s 
{
    register m_regs[8];
    uint16_t m_pc;
    uint16_t m_sp;
    uint8_t m_index[2];
} cpu_info;

typedef union
{
    uint8_t r1;
    uint8_t r2;
    uint16_t rr;
} register;