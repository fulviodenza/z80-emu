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

    nop = 0x00,
    ld_bc_xx = 0x01,
    ld_bc_a = 0x02,
    inc_bc = 0x03,
    inc_b = 0x04,
    dec_b = 0x05,
    ld_b_x = 0x06,
    rlca = 0x07,
    ex_af_af1 = 0x08,
    add_hl_bc = 0x09,
    ld_a_bc = 0x0A,
    dec_bc = 0x0B,
    inc_c = 0x0C,
    dec_c = 0x0D,
    ld_c_x = 0x0E,
    rrca = 0x0F,
    djnz_x = 0x10,
    ld_de_xx = 0x11,
    ld_de_a = 0x12,
    inc_de = 0x13,
    add_a_b = 0x80
} op_code;

int fetch(z80_info_s *status, op_code opcode);