#ifndef __INSTRUCTION_H
#define __INSTRUCTION_H

#include <stdint.h>

typedef enum{
    ACCUMULATOR = 1,
    ABSOLUTE = 3,
    ABSOLUTE_X = 3,
    ABSOLUTE_Y = 3,
    IMMEDIATE = 2,
    IMPLIED = 1,
    INDIRECT = 3,
    X_INDEXED = 2,
    Y_INDEXED = 2,
    RELATIVE = 2,
    ZEROPAGE = 2,
    ZEROPAGE_X = 2,
    ZEROPAGE_Y = 2    
} Addressing_mode;

typedef struct{
    const char* name;
    void (*execute_instruction)(Addressing_mode);
    Addressing_mode mode;
    uint8_t opcode; 
} Instruction;

extern Instruction instruction_set[];

void setup_instructions();

#endif