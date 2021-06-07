#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeLDAInstruction(Addressing_mode mode, uint16_t value){
    accumulator = value;

    if(accumulator == 0){
        status_register |= Zero;
    }
    if(accumulator >> 7){
        status_register |= Negative;
    }
}