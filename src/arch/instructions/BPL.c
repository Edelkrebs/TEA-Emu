#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeBPLInstruction(Addressing_mode mode, uint16_t value){
    if(!(status_register & Negative)) program_counter += (int8_t)value;
}