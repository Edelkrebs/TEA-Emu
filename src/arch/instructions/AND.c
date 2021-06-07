#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeANDInstruction(Addressing_mode mode, uint16_t value){
    accumulator &= value;
}