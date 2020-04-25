#include <stdio.h>
#include <stdlib.h>

#include "instructionSet.h"
#include "z80.h"

z80_info_s status;

uint8_t memory[32768];

int emulation (int opcode) 
{

    int pc = status.m_pc;

    while(true)
    {
        fetch   
        decode 
        execute
    }
}
