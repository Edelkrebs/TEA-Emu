#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>

void executeBRKInstruction(Addressing_mode mode){
    status_register |= Break;
    while(1);
}