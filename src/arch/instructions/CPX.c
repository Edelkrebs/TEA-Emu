#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeCPXInstruction(Addressing_mode mode, uint16_t value){
    status_register &= ~(Carry | Zero | Negative);

    if(x_register == value){
        status_register |= Zero;
    }
    if(x_register >= value){
        status_register |= Carry;
    }
}