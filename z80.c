#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "z80.h"
#include "instructionSet.h"

z80_info_s status;

int fetch(z80_info_s *status, op_code opcode) 
{

    uint16_t temp;

    switch(memory[status->m_pc++]) { //switch memory[m_pc]

        case nop:
        break;
        case ld_bc_xx:
        temp = memory[status->m_pc++];
        temp<<=8;
        temp = temp | memory[status->m_pc++];
        BC = temp;
    }
}

int emulation (int opcode) 
{
    int pc = status.m_pc;
    status.m_pc = 0;
    status.m_sp = 32767;
    
    //while(1)
    fetch(&status, opcode);
    printf("%d\n", BC);
        //execute
}   



int main(){

    memory[0] = 0x01;
    memory[1] = 0xFF;
    memory[2] = 0xFE;

    emulation(memory[0]);
}

