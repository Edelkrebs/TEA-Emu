#ifndef __CPU_H
#define __CPU_H

#include <stdint.h>

typedef enum{
    Carry = (1 << 0),
    Zero = (1 << 1),
    Interrupt = (1 << 2),
    Decimal = (1 << 3),
    Break = (1 << 4),
    Overflow = (1 << 6),
    Negative = (1 << 7)
} status_flags;

#define PAGE_SIZE 0xFF

#define STACK_BOTTOM 0x100
#define STACK_TOP 0x1FF

extern uint32_t cycles;

extern uint8_t accumulator;
extern uint8_t x_register;
extern uint8_t y_register;
extern uint8_t status_register;
extern uint8_t stack_pointer;
extern uint16_t program_counter;

void process_instruction(); 
void start_execution(uint16_t addr);

#endif