#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeBNEInstruction(Addressing_mode mode, uint16_t value){
    if(status_register & Zero) program_counter += (int8_t)value;
}