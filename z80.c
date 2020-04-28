#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "z80.h"
#include "instructionSet.h"

z80_info_s status;

int fetch(z80_info_s *status, op_code opcode) 
{

    uint16_t temp;
    uint16_t shifted;

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
        /**
         * Loads x into b.
        */
        temp = memory[status->m_pc++];
        B = temp;
        status->elapsed_cycles += 7;

        case rlca:
        /**
         * the contents of A are rotated left one bit position.
         * The contents of bit 7 are copied to the carry flag and
         * bit 0.
        */
        shifted = A << 1;
        //Flags affections
        status->flags.c = A >> 7;
        status->flags.h = 0;
        status->flags.n = 0;
        //rotation
        A = shifted | status->flags.c;
        status->elapsed_cycles += 4;

        case ex_af_af1:
        /**
         * Exchanges the 16-bit
         * contents of af and af'
        */
        temp = AF;
        AF = AF1;
        AF1 = temp;
        status->elapsed_cycles += 4;
        
        case add_hl_bc:
        /**
         * The value of BC is added to HL
        */
        if(HL > 0 && BC >0 || HL < 0 && BC < 0){
            status->flags.c = 1;
        }
        if(HL > 0 && BC < 0 || HL < 0 && BC > 0){
            status->flags.n = 1;
        }
        //HALF CARRY TO IMPLEMENT
        HL += BC;
        status->elapsed_cycles += 11;

        case ld_a_bc:
        /**
         * The contents of the memory
         * location specified by the 
         * contents of the BC register
         * pair are loaded to the
         * Accumulator
        */
        A = *(&BC);
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

