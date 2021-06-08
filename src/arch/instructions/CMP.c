#include <arch/instruction.h>
#include <arch/cpu.h>
#include <stdio.h>
#include <arch/bus.h>

void executeCMPInstruction(Addressing_mode mode, uint16_t value){
    status_register &= ~(Carry | Zero | Negative);

    if(accumulator == value){
        status_register |= Zero;
    }
    if(accumulator >= value){
        status_register |= Carry;
    }
}