#pragma once
#include <string.h>
#include <limits.h>

#include "z80.h"
/*
    The z80 Processor includes following instructions:
    Add; Subtract; Logical AND; Logical OR; Logical Exclusive OR;
    Compare; Left or Right Shifts or Rotates (Arithmetic and Logical);
    Increment; Decrement; Set Bit; Reset Bit; Test bit; Load and Exchange;
    Block Transfer and Search; Jump; Call; Return; Input/Output; Basic CPU Control
*/

typedef enum op_code{

    nop = 0x00, //done
    ld_bc_xx = 0x01, //done
    ld_bc_a = 0x02, //done
    inc_bc = 0x03, //done
    inc_b = 0x04, //done
    dec_b = 0x05, //done
    ld_b_x = 0x06, //done
    rlca = 0x07, //done
    ex_af_af1 = 0x08, //done
    add_hl_bc = 0x09, //done
    ld_a_bc = 0x0A, //done
    dec_bc = 0x0B, //done
    inc_c = 0x0C, //done
    dec_c = 0x0D, //done
    ld_c_x = 0x0E, //done
    rrca = 0x0F, //done
    djnz_x = 0x10,
    ld_de_xx = 0x11,
    ld_de_a = 0x12,
    inc_de = 0x13,
    add_a_b = 0x80
} op_code;

int fetch(z80_info_s *status, op_code opcode);