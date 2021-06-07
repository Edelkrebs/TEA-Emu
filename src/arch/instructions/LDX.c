#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeLDXInstruction(Addressing_mode mode, uint16_t value){
    x_register = value;

    if(x_register == 0){
        status_register |= Zero;
    }
    if(x_register >> 7){
        status_register |= Negative;
    }
}