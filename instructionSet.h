#include <string.h>

#include "z80.h"
/*
    The z80 Processor includes following instructions:
    Add; Subtract; Logical AND; Logical OR; Logical Exclusive OR;
    Compare; Left or Right Shifts or Rotates (Arithmetic and Logical);
    Increment; Decrement; Set Bit; Reset Bit; Test bit; Load and Exchange;
    Block Transfer and Search; Jump; Call; Return; Input/Output; Basic CPU Control
*/

enum OpCode {

    nop = 0x00,
    ld = 0x01,
    

}