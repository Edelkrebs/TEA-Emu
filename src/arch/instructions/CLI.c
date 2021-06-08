#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeCLIInstruction(Addressing_mode mode, uint16_t value){
    status_register &= ~(Interrupt);
}