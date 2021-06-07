#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>

void executeBRKInstruction(Addressing_mode mode, uint16_t value){
    status_register |= Break;
    while(1);
}