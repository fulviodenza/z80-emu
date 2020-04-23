#include "z80.h"

#define A z80.m_regs[0].r1
#define F z80.m_regs[0].r2
#define AF z80.m_regs[0].rr
#define B z80.m_regs[1].r1
#define C z80.m_regs[1].r2
#define BC z80.m_regs[1].rr
#define D z80.m_regs[2].r1
#define E z80.m_regs[2].r2
#define DE z80.m_regs[2].rr
#define H z80.m_regs[3].r1
#define L z80.m_regs[3].r2
#define HL z80.m_regs[3].rr
#define A1 z80.m_regs[4].r1
#define F1 z80.m_regs[4].r2
#define AF1 z80.m_regs[4].rr
#define B1 z80.m_regs[5].r1
#define C1 z80.m_regs[5].r2
#define BC1 z80.m_regs[5].rr
#define D1 z80.m_regs[6].r1
#define E1 z80.m_regs[6].r2
#define DE1 z80.m_regs[6].rr
#define H1 z80.m_regs[7].r1
#define L1 z80.m_regs[7].r2
#define HL1 z80.m_regs[7].rr