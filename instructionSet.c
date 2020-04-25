#include <stdio.h>
#include <stdlib.h>

#include "instructionSet.h"
#include "z80.h"

int decode(z80_info_s *status, OpCode opcode) {

    status->m_pc += 4;

    switch(opcode)
    {
        case opcode.nop:
        break;
        case opcode.add_a_b:
        
        uint16_t temp;
        temp=A+B;
        if(temp > 127 || temp < -128)
        {
            status->flags.pv = 1;
        }
        A = temp;
    }
}