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
        /**
         * nop does absoluterly nothing
        */
        //status->elapsed_cycles+=4;
        break;
        case ld_bc_xx:
        /**
         * ld_bc_xx stores xx 
         * (16 bit register) into BC
        */
        temp = memory[status->m_pc++];
        temp<<=8;
        temp = temp | memory[status->m_pc++];
        BC = temp;
        status->elapsed_cycles+=10;
        case ld_bc_a:
        /**
         * ld_bc_a stores a into the memory 
         * location pointed to by BC
        */
        *(&BC) = A;
        status->elapsed_cycles += 7;
        case inc_bc:
        /**
         * Adds one to BC
        */
        BC++;
        status->elapsed_cycles += 6;
        case inc_b:
        /**
         * Adds one to B
        */
        if(B > SCHAR_MAX)
        {
            status->flags.pv = 1;
        }
        B++;        
        status->elapsed_cycles += 4;
        case dec_b:
        /**
         * Subtract one to B
        */
        if(B < SCHAR_MIN)
        {
            status->flags.pv = 1;
        }
        B--;
        status->elapsed_cycles += 4;
        case ld_b_x:
        temp = memory[status->m_pc++];
        B = temp;
        status->elapsed_cycles += 7;
    }
}

int emulation (int opcode) 
{
    status.m_pc = 0;
    status.elapsed_cycles = 0;
    status.m_sp = 32767;
    
    //while(1)
    fetch(&status, opcode);
}

int main(){

    memory[0] = 0x01;
    memory[1] = 0xFF;
    memory[2] = 0xFE;

    emulation(memory[0]);
}

