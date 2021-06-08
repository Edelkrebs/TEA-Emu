#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeBEQInstruction(Addressing_mode mode, uint16_t value){
    if(status_register & Zero) program_counter += (int8_t)value;
}