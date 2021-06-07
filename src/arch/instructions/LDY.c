#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeLDYInstruction(Addressing_mode mode, uint16_t value){
    y_register = value;

    if(y_register == 0){
        status_register |= Zero;
    }
    if(y_register >> 7){
        status_register |= Negative;
    }
}