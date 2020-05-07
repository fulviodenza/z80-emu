#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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
        status->elapsed_cycles+=4;
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
        break;
        
        case ld_bc_a:
        /**
         * ld_bc_a stores a into the memory 
         * location pointed to by BC
        */
        *(&BC) = A;
        status->elapsed_cycles += 7;
        break;

        case inc_bc:
        /**
         * Adds one to BC
        */
        BC++;
        status->elapsed_cycles += 6;
        break;

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
        break;

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
        break;

        case ld_b_x:
        /**
         * Loads x into b.
        */
        temp = memory[status->m_pc++];
        B = temp;
        status->elapsed_cycles += 7;
        break;

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
        break;

        case ex_af_af1:
        /**
         * Exchanges the 16-bit
         * contents of af and af'
        */
        temp = AF;
        AF = AF1;
        AF1 = temp;
        status->elapsed_cycles += 4;
        break;
        
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
        break;

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
        break;

        case dec_bc:
        /**
         * Substracts one from BC
        */
        BC--;
        status->elapsed_cycles += 6;
        break;

        case inc_c:
        /**
         * Adds one to C
        */
        C++;
        status->elapsed_cycles += 4;
        break;

        case dec_c:
        /**
         * Subtracts one to C
        */
        C--;
        status->elapsed_cycles += 4;
        break;

        case ld_c_x:
        /**
         * Loads x to C
        */
        C = memory[status->m_pc++];
        status->elapsed_cycles += 7;
        break;

        case rrca:
        /**
         * The contents of A are rotated right one
         * bit position. The contents of bit 0 are copied
         * to the carry flag and bit 7
        */
        shifted = A >> 1;
        //Flags affections
        status->flags.c = A << 7;
        status->flags.h = 0;
        status->flags.n = 0;
        //rotation
        A = shifted | status->flags.c;
        status->elapsed_cycles += 4;
        break;
        
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

int main(int argc, char *argv[]){

    /*
    memory[0] = 0x0E;
    memory[1] = 0xFF;
    memory[2] = 0xFE;
    C = 5;
    printf("%d\n",C);
    emulation(memory[0]);
    printf("%d\n",C);
    */

    if(argc == 1) {

        fprintf(stderr, "usage: ./a.out file\n");
        exit(EXIT_FAILURE);
    }

    char *file_name = argv[1];
    FILE *fd; 
    long filelen;

    fd = fopen(file_name, "rb"); //read mode
    fseek(fd, 0, SEEK_END);
    filelen = ftell(fd);
    rewind(fd);

    fread(memory, 1, filelen, fd);
    fclose(fd);
}